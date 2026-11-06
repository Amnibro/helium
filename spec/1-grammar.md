# Chapter 1: Lexical structure and grammar

Status: derived from `hc/lex.he` and `hc/parse.he` (hc at `build/hc`, built from this worktree), checked by compiling 170+ probe programs. Test programs live in `spec/probes/ch1/` beside this file. Each rule carries a status:

- CONFIRMED: an hc run agrees with the rule as written.
- UNCONFIRMED: source read only, or the probe was not run, or the result was ambiguous. The reason is given.
- KNOWN GAP: hc accepts something the guide or TODO.md says is invalid, or the diagnostic is wrong.

Compiler wins over `HELIUM.md`. Disagreements are listed in section 10.

Line numbers refer to the files at the time of writing.

## 1. Source files and the two surface syntaxes

### 1.1 Extension selects the surface syntax

| Extension | Syntax | Layout | Notes |
|---|---|---|---|
| `.amni` | brace form | none; `{ }` delimit blocks, `;` ends statements | `//` comments; `lut fn` is desugared by a pre-pass (`lex.he:155`) |
| `.he` | layout form | indentation plus braces; `;` optional | `#` and `@` line comments; `//` is floor division; text pre-pass (`lex.he:91-103`) |

- Rule LEX-FILE-1. The lexer picks the syntax from the file extension (`lex.he:150-160`, `FILES[].he`). Both extensions set the `amni` flag, so keyword and identifier rules are shared (the flag is set at `lex.he:161`; the keyword check is at `lex.he:221-222`, corrected by the skeptic pass). CONFIRMED (every `.amni` and `.he` probe).
- Rule LEX-FILE-2. A `.he` file is pre-processed before lexing (`he_pre`, `lex.he:91`): `f"..."` format strings become `str(...)` calls (`fstr`, `lex.he:104`), and single-quoted strings longer than one character become double-quoted strings. `.amni` files get neither. CONFIRMED: `F01_fstring_he.he` prints `x=5 y=010`, `F02_fstring_amni.amni` is rejected, `H24_he_single_quote_multi.he` prints `abc`. Edge (skeptic pass): `''` (no character) also becomes `""` in `.he` (`lex.he:99-103`, the branch that is not one character or an escape), so `print('', ...)` prints an empty string (`spec/probes/ch1-review/X14_he_empty_char.he`). `.amni` rejects `''` (`spec/probes/ch1-review/X07_char_empty.amni`).
- Rule LEX-FILE-3 (gotcha). A `.he` file is treated as Python when any line that starts in column 0 matches `pyline` (`lex.he:79-88`): a prefix such as `def `, `from `, `class `, `import `, `print(`, `for `, `while `, `if `, or `@`; or an identifier followed by ` = `. A file in Python mode is parsed by the Python front end, not by the Helium grammar. CONFIRMED: `H13_at_top_col0.he` (a column-0 `@` comment) and `H19_py_at_col0_mix.he` (a column-0 `x = 1`) are both rejected with errors from the wrong grammar. Indented `@` comments are safe (`H12_at_comment.he`). The check reads the raw file, so a column-0 line inside a triple-quoted string also switches the file to Python mode. Silent miscompile (skeptic pass): `spec/probes/ch1-review/Y13_ml_col0_trap.he` (string content `if hello` at column 0) builds with exit 0, runs with exit 0, prints nothing, and the `print("after")` line after the string is lost. See G8.
- Rule LEX-FILE-4. A UTF-8 byte-order mark is skipped (`lex.he:159`). CONFIRMED (skeptic pass): `spec/probes/ch1-review/Z03_bom.amni` (BOM then `fn main`) builds and prints `4`.
- Rule LEX-FILE-5. `lut fn` desugaring runs only for `.amni` files (`lex.he:155`). CONFIRMED result: `S31_lut_he.he` (`lut fn` in `.he`) compiles and prints the correct value as a plain function. UNCONFIRMED: memoization is absent in `.he` (matches `hc/TODO.md` section 1).

### 1.2 The `.he` layout form relates to the brace form

The lexer turns layout into ordinary tokens, so one grammar (section 8) serves both forms. The mapping (`lex.he:175-188`, helpers `lay` and `ins` at `lex.he:168-169`):

| Layout event | Token stream |
|---|---|
| `:` at end of a line, followed by a deeper-indented line | `:` becomes `{` (`T_LC`), and the block closes with a synthetic `}` (`T_RC`) |
| a line that starts at a shallower indentation | one synthetic `}` per closed level |
| a new line at the same level | synthetic `;` (`T_SEMI`) unless the previous token was already `;`, `{`, or a `lay` `else` |
| `x := e` | `let x = e` (`K_LET`, `T_ASSIGN`) |
| `x ~= e` | `var x = e` (`K_VAR`, `T_ASSIGN`) |
| `:` followed by text on the same line | `{` opened inline; closed at the end of the line or at an `else`/`elif` that belongs to an outer `if` |

Layout is suspended inside `(`, `[`, and `{` (the `dep` counter, `lex.he:163` and `lex.he:279`). Explicit braces in `.he` therefore work and switch layout off inside them.

## 2. Character set, whitespace, comments

- Rule LEX-WS. Spaces, tabs, carriage returns and newlines separate tokens (`lex.he:171`). Tabs work as indentation in `.he`. CONFIRMED: `C15_he_tab_indent.he`. The skip loop is at `lex.he:172`.
- Rule LEX-CMT-LINE. In `.amni`, `//` starts a line comment that runs to the newline (`lex.he:173`). CONFIRMED: `L13_block_comments.amni`.
- Rule LEX-CMT-BLOCK. `/* ... */` comments nest (`lex.he:189-195`). An unterminated block comment is an error ("unterminated /* comment"). CONFIRMED: `L13_block_comments.amni` (`/* outer /* inner */ still comment */` is one comment), `L14_unterminated_comment.amni` (rejected).
- Rule LEX-CMT-HE. In `.he`, `#` and `@` start a line comment (`lex.he:174`). CONFIRMED: `H11_hash_comment.he`, `H12_at_comment.he`, `K18_he_at_inline.he`. A `#` inside a string is not a comment (`C13_he_string_hash.he`, prints `a # not comment`).
- Rule LEX-CMT-HE-SLASH. In `.he`, `//` is the floor-division operator, not a comment (`lex.he:322`). CONFIRMED: `K13_he_comment_slash.he` is rejected ("expression expected, found '/'"), and `K17_he_floor_div.he` prints `-4 3` for `-7 // 2` and `7 // 2`.
- Rule LEX-ILLEGAL. Any other byte outside tokens and literals is an error ("illegal character"), for example `$` (`lex.he:355`). CONFIRMED: `L15_illegal_char.amni`. `#` in `.amni` is also illegal (`L18_hash_in_amni.amni`).

## 3. Identifiers and keywords

- Rule LEX-IDENT. An identifier is a maximal run of ASCII letters, digits and `_`, not starting with a digit (`idc`, `lex.he:55`; digits are tested first at `lex.he:196`). Non-ASCII letters are illegal. CONFIRMED: `L20_unicode_ident.amni` ("illegal character" on `é`). `_` alone is a legal identifier (`K05_underscore_name.amni`, prints 2).
- Rule LEX-KW. The 49 reserved words in `KWS` (`lex.he:12`, `NKW := 49` at `lex.he:18`) are keywords:

  `import namespace struct enum type fn thread_fn export simd recursive let var extern const pad reusable if else while for in loop block guard match return break continue as true false null self bool varint i8 i16 i32 i64 u8 u16 u32 u64 f32 f64 int uint byte real`

  A keyword cannot be a name. CONFIRMED: `L16_keyword_as_name.amni` (`let loop`), `K04_self_name.amni` (`self`), `K08_amni_keyword_bool_name.amni` (`int`), `K07_he_keyword_name.he` (`let`).
- Rule LEX-KW-PY. Python-only words `and`, `or`, `not`, `elif`, `True`, `False`, `pass` are keywords only in Python mode or, for the first four, in `.he` (`lex.he:224`). CONFIRMED: `H05_word_ops.he`, `H07_inline_block.he` (`elif`).
- Rule LEX-CTX. These words are contextual, not reserved: `inline`, `checkfree`, `upto`, `lut`, `from`, `fields`, `types`, `variants`, `use` (`use` is a keyword only as the first word of a top-level `.he` line, `lex.he:226`). CONFIRMED: `K03_inline_as_name.amni` (`inline`, `checkfree`, `upto` as variable names), `S34_he_use_import.he`.

## 4. Literals

### 4.1 Integers

- Rule LIT-INT-DEC. A decimal integer is one or more digits. Leading zeros are allowed and do not make it octal. Type is adapted by context. With no context the default is `int`, except a decimal literal above 2^63-1 (up to 2^64-1), which is `uint` (`lex.he:207`, `lex.he:216`: the `uns` flag is set for decimal too). CONFIRMED (corrected by skeptic pass; the old "default `int`" claim is refuted for values above 2^63-1): `spec/probes/ch1-review/Q05_big_dec_noctx.amni` prints 9223372036854775808, and `spec/probes/ch1-review/Q11_type_of_big.amni` shows the value is unsigned (`x / 2` = 4611686018427387904, `x > 0` is true). Probes: `L25_leading_zero.amni` (`007` prints 7), `L01b_ints.amni`.
- Rule LIT-INT-HEX. `0x` or `0X` followed by up to 16 hex digits (`lex.he:198-207`). Values above 2^63-1 are unsigned (`uns` flag, `lex.he:207`). Zero digits are accepted: a bare `0x` is the integer 0 (`spec/probes/ch1-review/X02_hex_empty.amni`). The rule as written ("up to 16") allows it, but it is probably unintended, so it is recorded as KNOWN GAP G11. CONFIRMED: `L01b_ints.amni` (`0xFF` = 255, `0x7FFFFFFFFFFFFFFF`), `L02_int_hex_big.amni` (`uint` `0xFFFFFFFFFFFFFFFF` prints 18446744073709551615), `L04_hex_too_big.amni` ("hex literal too large for 64 bits").
- Rule LIT-INT-RANGE. A decimal literal above 18446744073709551615 is an error (`lex.he:216`). CONFIRMED: `L03_int_too_big.amni`. An unsigned value that does not fit a signed `int` needs a `uint` context: `L33_uint_literal_neg.amni` (`let u uint = -1` is rejected, "constant -1 does not fit u64"). `L32_neg_literal_min.amni` (`-9223372036854775808`) is accepted.
- Rule LIT-NO-SEP. There are no digit separators. CONFIRMED: `0x1_0` lexes as `0x1` followed by identifier `_0` and is rejected ("expected ')' in call arguments"). Decimal `1_000` is also rejected (CONFIRMED, skeptic pass: `spec/probes/ch1-review/X05_dec_sep.amni`, `expected ')' in call arguments, found '_000'`).
- Rule LIT-NO-BIN-OCT. `0b` and `0o` prefixes do not exist. CONFIRMED: `L21_binlit.amni` and `L22_octlit.amni` are rejected (the `0` lexes, then `b101` or `o17` is an identifier).

### 4.2 Reals

- Rule LIT-FLT. A real literal is digits, `.`, digits, with an optional exponent `e`/`E`, optional sign, digits (`lex.he:208-215`). The fraction is required after the dot: `1.` lexes as the integer `1` followed by a field access. CONFIRMED: `L05_reals.amni` (`1.5`, `1e3`, `2.5e-2`, `1E+2` print 1.5, 1000.0, 0.025, 100.0), `L06_real_no_digit_after_dot.amni` (rejected), `L23_dot_five.amni` (`.5` rejected, "expression expected").
- Rule LIT-FLT-EXP. An exponent needs a digit, optionally after a sign. CONFIRMED: `L24_exp_no_digits.amni` (`1e` is `1` followed by identifier `e`, rejected).
- Rule LIT-FLT-HEX. A hex real is `0x`, hex digits, then a `.` with a hex fraction, or a `p` binary exponent, or both (`lex.he:198-204`: the `.` branch sets the real flag even when no `p` follows). The earlier "mandatory `p`" is REFUTED by the skeptic pass: `spec/probes/ch1-review/X01_hex_real_nop.amni` (`let x = 0x1.8; print(x)`) prints 1.5. CONFIRMED (corrected): `L05_reals.amni` (`0x1.8p1` = 3.0, `0x10p-1` = 8.0), `L31_hex_float_nodot.amni` (`0x1p4` = 16.0), `X09_hex_p_nofrac.amni` (`0x1.8p1` = 3.0), `X10_hex_dotonly.amni` (`0x.8p1` = 1.0).
- Rule LIT-F32. There is no f32 suffix. An untyped real literal converts to `f32` by context. CONFIRMED: `L19_f32_lit.amni` (`let x f32 = 1.5; x + 2` prints 3.5).
- Rule LIT-REAL-INT. A real literal does not implicitly become an integer. CONFIRMED: `L30_real_exp_int.amni` (`let x int = 1e3;` rejected, "a float converts to an integer only with an explicit `as`").

### 4.3 Characters

- Rule LIT-CHAR. `'c'` is an integer literal of type `int`. An escape is allowed; the value must be exactly one character (`lex.he:230-233`). CONFIRMED: `L07_char_lits.amni` (`'a'` = 97, `'\n' == 10` true, `'\x41'` = 65, `'\\'` = 92, `'\''` = 39, `'\0'` = 0), `L17_byte_is_int.amni` (`let b byte = 'a'`), `L09_char_multi.amni` (`'ab'` rejected, "expected closing ' of character literal").

### 4.4 Escapes

- Rule LIT-ESC. Escapes are `\n` (10), `\t` (9), `\r` (13), `\0` (0), `\\`, `\"`, `\'`, and `\xHH` with exactly two hex digits (`esc`, `lex.he:68-76`). Anything else is "unknown escape sequence". There is no `\u{...}` form. CONFIRMED: `L10_str_escapes.amni` (`"a\tb\x41\"q\\\n"` prints `a<TAB>bA"q\` then a newline), `L08_bad_escape.amni` (`'\q'` rejected), `L29_unicode_escape.amni` (`\u{41}` rejected).

### 4.5 Strings

- Rule LIT-STR. `"..."` is a single-line string. A newline or end of file before the closing quote is an error (`lex.he:235-273`). CONFIRMED: `L10_str_escapes.amni`, `L11_str_unterminated.amni` ("unterminated string literal").
- Rule LIT-STR-ML. `"""` starts a multi-line string (`lex.he:238-271`). If the opening `"""` is followed by a newline, the text starts on the next line. The closing `"""` must sit on its own line, preceded only by spaces or tabs; that prefix is removed from every content line, and every content line must start with it (otherwise: "a line of a multi-line string must start with the indentation of its closing"). Content lines are joined with `\n`, and there is no newline after the last content line. Refined by the skeptic pass: the indentation check does not fire on a blank or whitespace-only line that is shorter than the closing indentation. Such a line is accepted and contributes an empty line (`spec/probes/ch1-review/T11_blank_mid.amni` prints `a`, an empty line, `b`; `X03_ml_blank_line.amni`). A non-blank line whose prefix differs is an error (`X04_ml_blank_short.amni`, `T10_close_text.amni` for text before the closing `"""`). A one-line `"""abc"""` is also accepted (`X06_ml_oneline.amni`, prints `abc`). CONFIRMED. CONFIRMED: `L12_triple_str.amni` (prints `one` / `  two`), `H17_multiline_str.he` (prints `hello` / `world`), `L34_ml_len.amni` (`"""`, `ab`, `cd`, `"""` has length 5, that is `ab\ncd`).
- Rule LIT-STR-OTHER. A string literal is a `const byte[:]` view; `"a" + "b"` concatenation is a `.he` feature (section 7, EXP-STR-PLUS).

## 5. Operators and punctuation

Tokens (`lex.he:3-11`), with the surface spellings:

| Group | Tokens |
|---|---|
| delimiters | `( ) [ ] { } , ; :` and `::` (`T_CC`), `?` |
| member access | `.` `..` (range/slice) `.=` (bind reference) `.==` `.!=` (address equality) |
| arithmetic | `+ - * / %`, `**` (`.he` only), `//` (`.he` only, floor division) |
| compound | `+= -= *= /= %= &= \|= ^= <<= >>=` and `//=` (`.he`) |
| step | `++ --` (postfix, statement form only) |
| compare | `== != < > <= >=` |
| shift | `<< >>` |
| bitwise | `& \| ^ ~` |
| logical | `&& \|\| !`; `and or not` in `.he` |
| arrows | `->` (return type, function type), `=>` (match arm, lambda) |
| `in` | keyword in `for`; the membership operator `in` / `not in` in `.he` |

- Rule LEX-OP-LONGEST. Operators take the longest match among the listed spellings (for example `<<=` before `<<` before `<=` before `<`, `lex.he:290-350`). CONFIRMED: `P02_shift_vs_add.amni` (`1 << 2 + 1` = 8, `16 >> 1 + 1` = 4).
- Rule LEX-OP-POW-AMNI. `**` is two `*` tokens in `.amni`, so `2 ** 3` is a syntax error. CONFIRMED: `P07_pow_amni.amni` ("expression expected, found '*'").
- Rule LEX-OP-DIV-ASSIGN. `/=` in `.amni` is compound division; `//=` in `.he` is floor-division assignment. CONFIRMED: `K15_amni_floor_div.amni` (`x /= 2` gives 4), `K14_he_division_eq.he` (`x //= 2` gives 4).

## 6. Layout rules in `.he`

- Rule LAY-BLOCK. A line that ends with `:` opens a block. The next line must be indented deeper than the opener (`lex.he:175-186`). CONFIRMED: `H06_colon_block.he` (prints `30 1`), `H10_expected_indent.he` (rejected, "expected an indented block after ':'").
- Rule LAY-SEMI. A newline that does not follow `;`, `{`, or a block opener inserts a statement separator (`lex.he:186`). CONFIRMED: `H01_basic.he` (no semicolons), and the reverse effect: a comma at a line end inserts a separator, so a multi-line struct or enum body with commas at the line ends is rejected (`M01_he_multiline_struct.he`, `M02_he_multiline_enum.he`: "found ';'"). Keep struct and enum bodies on one line, or use braces.
- Rule LAY-DEDENT. A line may only return to an indentation level already on the stack (`lex.he:181-184`). CONFIRMED: `C14_he_dedent_mismatch.he` ("this line's indentation matches no enclosing block"), `H09_bad_indent.he` ("unexpected indentation").
- Rule LAY-INLINE. `: a; b` puts a block on one line; the `;` separates statements (`lex.he:278`). CONFIRMED: `H08_inline_semicolons.he` (prints 5), `H07_inline_block.he`.
- Rule LAY-ELSE. `else:`, `elif`, and `else if` continue an `if` at the same indentation (`lex.he:224-225`, `lay_else`, `lex.he:77`). An inline `else` closes an inline block it follows. CONFIRMED: `H07_inline_block.he` (`elif`), `C11_he_else_if_chain.he` (prints `1-10`).
- Rule LAY-DEPTH. Layout is off inside `(`, `[`, `{`. CONFIRMED: `C06_he_multiline_call.he` (a call split across three lines, prints 6), `C07_he_multiline_list.he`.
- Rule LAY-BRACE-SWITCH. Braces inside `.he` code switch layout off for their contents. CONFIRMED: `C16_he_mixed_brace_block.he` (`for x in xs { print(x) }` in a layout body), `H18_brace_inside_he.he`, `C03_he_struct_brace.he`.
- Rule LAY-FN-OPT. In `.he`, the keyword `fn` is optional before a function name, provided the declaration is followed by `(` or `<` (`he_decl`, `parse.he:89-99`). CONFIRMED: `M04_he_fn_no_keyword.he` (`add(a int, b int) int:` and `main():`). `thread_fn` still needs its keyword.
- Rule LAY-SEMI-OPT. A `;` is optional at a line end in `.he` and an optional trailing `;` is accepted (`semi`, `parse.he:88`). CONFIRMED: `K06_he_semicolon_end.he`.
- Rule LAY-DECL-ASSIGN. `x := e` declares an immutable binding and `x ~= e` a mutable one (`lex.he:277`). CONFIRMED: `H01_basic.he`, `H16_walrus_let.he`, `C19_he_fn_result_list.he` (`q, ok := dm(9, 3)`).
- Rule LAY-FOR. `for i xs:` and `for x int in xs:` are accepted in `.he` (type after the binding, the `in` optional) (`pfor`, `parse.he:225-251`). CONFIRMED: `H15_for_forms.he`.
- Rule LAY-NO-TERNARY. `.he` has no `x if c else y` expression. CONFIRMED: `H14_ternary_he.he` (rejected). The conditional expression exists only in Python mode (`parse.he:185`, `pexpr`).
- Rule LAY-INLINE-STRUCT. A `struct` or `enum` may open with `:` and put its fields on the same line, comma separated. CONFIRMED: `C02_he_struct_inline.he` (`struct P: x real, y real`), `C04_he_enum_inline.he` (`enum Shape { Circle { r real }, Dot }` in a `.he` file, via braces).
- Rule LAY-MATCH. A `match` in `.he` may use a layout block, one arm per line with `=>` (`pmatch`, `parse.he:297`). CONFIRMED: `M03_he_match_layout.he` (prints 2), `M05_he_var_block_match_int.he`.
- Rule LAY-NO-CONT (new, skeptic pass). In `.he`, outside brackets, a line break after a binary operator or a `.` does not continue the expression. The newline inserts `;` (`lex.he:187`), and the deeper-indented next line is rejected. Inside `(`, `[` or `{` layout is off, so line breaks are fine (`C06_he_multiline_call.he`). CONFIRMED: `spec/probes/ch1-review/Z01_he_cont_plus.he` (`y := 1 +` then an indented `2`: `unexpected indentation`), `Z02_he_cont_dot.he` (`xs` then an indented `.len`: same error).

## 7. Operators, precedence and associativity

### 7.1 Table (tightest first)

| Level | Operators | Assoc | Parser location | Notes |
|---|---|---|---|---|
| 1 | postfix: call `f(...)`, index `a[i]`, field `.x`, method, `as T`, `as! T`, trailing `{...}` block | left | `ppost` (`parse.he:392-409`), `pcall` (410), `pindex` (425) | `as` binds tighter than any unary or binary operator |
| 2 | `**` power | right | `pun` (`parse.he:379-391`) | `.he` only; right operand is a unary expression |
| 3 | unary `-`, `!`, `~`, `&` (prefix) | right | `pun` (`parse.he:379-391`) | operand is a unary; `-2 ** 2` is `-(2 ** 2)`. `not` (`.he`) is not at this level, see EXP-NOT |
| 4 | `*`, `/`, `%`, `//` (`.he`) | left | `binprec` 10 (`parse.he:348-357`) | `/` truncates, `%` is Euclidean, `//` floors |
| 5 | `+`, `-` | left | `binprec` 9 | `+` on strings in `.he` concatenates |
| 6 | `<<`, `>>` | left | `binprec` 8 | |
| 7 | `&` (binary) | left | `binprec` 7 | tighter than `==` (unlike C) |
| 8 | `^` | left | `binprec` 6 | |
| 9 | `\|` | left | `binprec` 5 | |
| 10 | `<`, `>`, `<=`, `>=`, `in`, `not in` (`.he`) | left, chaining in `.he` | `binprec` 4; `pbin` (358-378) | see 7.3 |
| 11 | `==`, `!=`, `.==`, `.!=` | left | `binprec` 3 | |
| 11a | `not` (`.he` only, prefix) | operand is `pbin(3)` | `pun` (`parse.he:379-383`) | operand takes every binary operator of level 4 to 11; stops before `&&`, `\|\|`. See EXP-NOT |
| 12 | `&&` | left | `binprec` 2 | operands must be `bool` |
| 13 | `\|\|` | left | `binprec` 1 | operands must be `bool` |

Assignment, `.=`, `+=` and the rest are statements, not expressions (`pstmt`, `parse.he:618`). `.he` `and`/`or` map to `&&`/`||` at level 12/13. `not` (`.he`) is not a level-3 unary operator (skeptic pass, refuted): it sits between level 11 and level 12, see EXP-NOT.

Evidence for the table: `P01_mul_add.amni` (`1 + 2 * 3` = 7, `10 - 3 - 2` = 5, `2 * 3 % 4` = 2, `100 / 10 / 5` = 2), `P02_shift_vs_add.amni` (`1 << 2 + 1` = 8, `1 | 2 & 3` = 3, `6 ^ 3 & 5` = 7, `1 & 3 == 1` true), `P03_bit_vs_eq.amni` (`a & 1 == 1` accepted and true, so `&` groups first), `P05_unary.amni` (`-x * 2` = -6, `-x + 5` = 2, `~0 & 7` = 7), `P06_as_binds_tight.amni` (`1 + x as int` = 301, `-x as int` = -300), `P10_assoc_mixed.amni` (`20 - 4 * 2 + 1` = 13, `7 % 4 * 2` = 6, `2 * 3 << 1` = 12), `H02_pow_assoc.he` (`2 ** 3 ** 2` = 512, `-2 ** 2` = -4, `(2 ** 3) * 2` = 16).

### 7.2 Rules

- Rule EXP-PREC. Operator grouping follows section 7.1 (CONFIRMED, above).
- Rule EXP-LEFT. Binary operators at one level are left-associative: `pbin` parses the right operand with minimum precedence `pr + 1` (`parse.he:358-378`). CONFIRMED: `P01_mul_add.amni`, `P15_div_mod_neg.amni`.
- Rule EXP-POW-RIGHT. `**` is right-associative and binds tighter than prefix operators (`pun`, `parse.he:379-391`). CONFIRMED: `H02_pow_assoc.he` (`2 ** 3 ** 2` = 512; `2 ** -1` parses, value 1 for `int` operands; `2.0 ** -1` = 0.5, `H03b_chain_cmp.he`).
- Rule EXP-UNARY. Prefix operators apply to a unary operand, so `-x * 2` is `(-x) * 2` and `!a && b` is `(!a) && b`. CONFIRMED: `P05_unary.amni`, `H05_word_ops.he`. The exception is `not` (`.he`), see EXP-NOT.
- Rule EXP-AS. `e as T` is postfix and binds tighter than prefix and binary operators (`ppost`, `parse.he:392-409`, `K_AS`). In release builds both forms wrap for narrowing integers: `300 as u8` is 44 and `200 as i8` is -56 (`spec/probes/ch1-review/Q07_cast_i8.amni`). Float to int truncates toward zero (`-3.7 as int` is -3, `Q06_cast.amni`). `as!` is the always-wrapping form (`fl = 1`, `parse.he:408`; `T02_as_bang.amni`). CONFIRMED: `P06_as_binds_tight.amni`. Under `hc build --debug` (skeptic pass, `spec/probes/ch1-review/AS1.amni`, `AS2.amni`, `AS3.amni`): `as` traps on an out-of-range value (`helium runtime error: as conversion out of range (debug): 300 as u8`, run exit 1), while `as!` still wraps (44). The section 12 item is resolved.
- Rule EXP-BITS-FIRST. In `.amni` and `.he`, bitwise `& ^ |` and shifts bind tighter than comparisons and equality, unlike C. CONFIRMED: `P03_bit_vs_eq.amni`, `P02_shift_vs_add.amni`.
- Rule EXP-BOOL. `&&`, `||`, `!` require `bool` operands; integers are rejected. CONFIRMED: `P04_cmp_eq.amni` (`0 || 1 && 0` rejected, "expected a value of type bool, got i64"), `P04b_cmp_bool.amni` (`1 < 2 == true` and `1 == 1 && 0 == 1 || 1 == 1` accepted, `&&` above `||`).
- Rule EXP-DIV. `/` on integers truncates toward zero, `%` is Euclidean (never negative), `//` in `.he` floors. CONFIRMED: `P15_div_mod_neg.amni` (`-7 / 2` = -3, `-7 % 3` = 2, `7 % -3` = 1, `7 / -2` = -3), `K17_he_floor_div.he` (`-7 // 2` = -4).
- Rule EXP-POSTFIX-STEP. `x++` and `x--` are statements only; prefix `++x` and the expression forms are syntax errors. CONFIRMED: `P13_incr_postfix.amni` (accepted), `P12_incr_prefix.amni` (rejected, "expression expected, found '++'"), `P14_incr_expr.amni` (`let y = x++;` rejected).

### 7.3 Comparison chaining (`.he` only)

- Rule EXP-CHAIN-HE. In `.he`, `a < b < c` (and any mix of `< > <= >=`) parses as `a < b && b < c` when the middle operand is a plain name or literal (`pbin`, `rc` and `lc` at `parse.he:358-378`: the middle node kind is at most `N_ID`). Chaining does not apply to a field, call, or other compound middle operand, which then reads as `(a < b) < c` and fails typing. CONFIRMED: `H03b_chain_cmp.he` (`1 < a < 3` true, `1 < a < 2` false, `a = 2`), `H21_chain_mixed_and.he`, `H22_chain_field_middle.he` (`1 < xs.len < 3`, rejected, "expected a value of type bool, got i64"), `H23_chain_call_middle.he` (`1 < g() < 3`, rejected the same way). Refined (skeptic pass): the test is applied to the right operand of each comparison in the chain (`rc` at `parse.he:375`), and it accepts any node of kind 1 to 8 (`N_INT`, `N_FLT`, `N_STR`, `N_TRUE`, `N_FALSE`, `N_NULL`, `N_SELF`, `N_ID`, `parse.he:2`), not only names and integers. So `"a" < "b" < "c"` is true (`spec/probes/ch1-review/Y11_chain_str_mid.he`), `1 < 2 < 3 < 4` is true (`X13_chain_str_mid.he`), and `0 < -1 < 3` is rejected because a unary operand is not an atom (`Y04_chain_mid_neg.he`). The last operand must also be an atom: `1 < a < 2 + 1` is rejected (`X11_chain_compound_last.he`). CONFIRMED.
- Rule EXP-CHAIN-AMNI. `.amni` does not chain. CONFIRMED: `P08_chain_cmp_amni.amni` (`1 < 2 < 3` rejected, "expected a value of type bool, got i64").

### 7.4 Membership and word operators (`.he` only)

- Rule EXP-IN. `x in xs` is `contains(xs, x)`, at level 10 (`pbin`, `K_IN && he()`), and `x not in xs` is its negation (`ni` flag). CONFIRMED: `H04_in_op.he` (prints `true false true`). In `.amni`, `in` is rejected outside `for` (`L26_in_amni.amni`).
- Rule EXP-WORDS. `and` and `or` are synonyms for `&&` and `||` in `.he`. CONFIRMED: `H05_word_ops.he`, `spec/probes/ch1-review/Y03_not_and.he` (`not a and b` is `(not a) && b`). The original claim that `not` is a synonym for unary `!` is REFUTED; see EXP-NOT.
- Rule EXP-NOT (new, skeptic pass; corrects EXP-WORDS and the level table). In `.he`, `not e` parses its operand with `pbin(3)` (`pun`, `parse.he:379-383`: `a := pyc(pbin(3))`). The operand therefore takes every binary operator of precedence 3 or higher: `==`, `!=`, `<`, `>`, `<=`, `>=`, `in`, `&`, `^`, `|`, shifts, `+`, `-`, `*`, `/`, `%`, `//`. It stops before `&&` and `||`. Evidence: `spec/probes/ch1-review/Y01_not_prec.he` (with `x := 1`, `not x == 2` is accepted and prints `true`, so it is `not (x == 2)`; `not x == 1` prints `false`), `spec/probes/ch1-review/Y14_not_arith.he` (`not x + 1 == 2` prints `false`, so it is `not ((x + 1) == 2)`), `Y03_not_and.he`. `!` is still a unary operator: `spec/probes/ch1-review/Y02_bang_prec.he` (`!x == 2` with an int `x` is rejected, `expected a value of type bool, got i64`). CONFIRMED.

### 7.5 String concatenation

- Rule EXP-STR-PLUS. In `.he`, `+` with a string operand builds a call `str(l, r)` (`parse.he:372`). CONFIRMED: `L27_he_str_concat.he` (`"a" + "b"` gives `ab`, and `'c' + 1` is integer addition giving 100). In `.amni`, `"ab" + "cd"` is rejected with an internal backend message (`native backend: slice from expression kind 9 resolved 0`), which is a diagnostic gap (KNOWN GAP G1, section 9).

## 8. Grammar (EBNF)

Notation: `"x"` is a keyword or token; `[ ]` optional; `{ }` repetition; `|` alternation; `( )` grouping. Productions marked `(.he)` exist only in `.he`; `(.amni)` only in `.amni`. The same productions read the token stream of section 1.2, where `{`/`}` may come from layout.

### 8.1 Program and top-level items

```ebnf
program        = { top_item } ;
top_item       = import | namespace | type_alias | struct_decl | enum_decl
               | extern_block | fn_decl | global_decl | ";" (.he) ;
import         = ( "import" | "use" (.he) ) path [ "from" string ] ";"? ;
path           = ident { "." ident } ;
namespace      = "namespace" ident ";" ;
type_alias     = "type" ident "=" type ";" ;
extern_block   = "extern" string "{" { fn_head ";" } "}" ;
global_decl    = ( "let" | "var" | "const" ) ident-list [ ":" ] [ type ]
                 [ "=" expr-list ] ";" ;
```

- `use` is recognized only at the top of a `.he` file with a space after it (`lex.he:226`). CONFIRMED: `S34_he_use_import.he`.
- `extern "lib" { ... }` binds a library. CONFIRMED: `S40_extern_amni.amni` (prints 1.0). A bare `extern fn` (no block) is parsed but cannot bind natively (see G6).
- Global `let` and `const` need an initializer (`pvdecl`, `parse.he:679-704`). CONFIRMED: `D06_let_global_const.amni` (`let SIZE = 4;`, `var counter int = 0;`, `const NAMES int[SIZE] = [1, 2, 3, 4];`). Skeptic pass: `reusable` is local only. `reusable K = 4;` at file scope is rejected with `let, var or const expected` (`spec/probes/ch1-review/G10_reusable_global.amni`), so the grammar line above was wrong and is corrected. A file-scope `var` may omit its initializer (`Q01_global_var_noinit.amni` prints 0). `let X int;` and `const C real;` at file scope are rejected (`Q02_global_let_noinit.amni`, `Q03_global_const_noinit.amni`).

### 8.2 Type declarations

```ebnf
struct_decl    = "struct" ident [ generics ] ( "{" field-list "}" | ":" field-line-list ) ;
field-list     = [ field { "," field } [ "," ] ] ;
field          = "pad" [ int ]
               | [ "let" | "const" ] ident [ ":" ] type [ "=" expr ] ;
enum_decl      = "enum" ident [ generics ] "{" variant { "," variant } [ "," ] "}" ;
variant        = ident [ "{" field-list "}" ] ;
generics       = "<" generic { "," generic } [ "," ] ">" ;
generic        = ident [ ":" type | type (.he) ] ;
```

- Fields: `name type` with an optional colon and optional default. CONFIRMED: `S16_struct_lits.amni` (`hp i32 = 100`), `D01_colon_types.amni` (`x: real` accepted), `D02_no_colon_types.amni` (`let y real`, `const z real`), `S41_pad_field.amni` (`pad 3`).
- A trailing comma in a field list is accepted by the loop (`pfields`, `parse.he:719-735`). CONFIRMED (skeptic pass): `spec/probes/ch1-review/X24_struct_trailing_comma.amni` (multi-line struct with `y real,` last).
- Enum variants: `Name` or `Name { fields }` (`penum`, `parse.he:745-759`). CONFIRMED: `S01_match_forms.amni`, `C04_he_enum_inline.he`.
- Generic declarations `<T>` on `fn`, `struct` (CONFIRMED: `D07_generics.amni`, `struct Pair<T> { a T, b T }`). On `enum`: CONFIRMED to parse and type-check (skeptic pass: `spec/probes/ch1-review/Y08_enum_generic_nomatch.amni`, `enum E<T> { A { v T }, B }` with `E<int>.A { v: 3 }`, prints 1). Matching on a generic enum is rejected by the native backend (`X23_enum_generic.amni`, `native backend: matching on this type natively`), which is a backend limit. Trailing commas in generic lists are accepted (`G02_generic_trail.amni`), and so are trailing commas in enum bodies (`G01_enum_trail.amni`). Generic bounds `<T: int>` parse and run (`G03_generic_bound.amni`).
- `type X = T;` aliases. CONFIRMED: `S37_type_alias.amni`.

### 8.3 Functions

```ebnf
fn_decl        = [ "lut" ] [ "checkfree" ] [ "export" [ string ] ] [ "extern" [ string ] ]
                 [ "checkfree" ] [ "simd" ] [ "inline" ] [ "recursive" ]
                 ( "fn" | "thread_fn" ) ident [ generics ]
                 "(" [ param { "," param } [ "," ] ] ")" [ return ]
                 ( block | "=" string ";" | ";" ) ;
param          = [ "var" ] ident [ ":" ] [ type ] [ "=" expr ] ;
return         = [ "->" ] type { "," type } ;
```

- `fn` may be omitted in `.he` (LAY-FN-OPT). `fn_mod` order is fixed by `pfn`, not free (see FN-MOD-ORDER in section 9). The `= "symbol"` rename is accepted only on extern declarations (skeptic pass). CONFIRMED: `extern "libm.so.6" { fn cosx(x real) real = "cos"; }` (`spec/probes/ch1-review/V07_extern_rename_so6.amni`, prints 1.0). Rejected: a plain `fn cosx(x real) real = "cos";` (`V02_extern_rename.amni`, `expected '{' in function body`), and a bare `extern fn ... = "cos";` in `.amni` (`V05_extern_rename_amni.amni`, native backend, see G6). `extern "m"` loads the linker script `libm.so` and fails at startup (G12).
- Untyped parameters make the function generic. CONFIRMED: `T04_untyped_param.amni` (`fn larger(a, b)`, prints 9).
- Default parameter values: CONFIRMED: `D08_default_params.amni` (`f(a, b = 10, c = 100)`: `f(1)` = 111, `f(1, 2)` = 103, `f(1, 2, 3)` = 6).
- `var` parameters: CONFIRMED: `D09_param_var.amni` (`fn inc(var n int)`).
- Return lists: CONFIRMED: `D04_fn_return_list.amni` (`fn divide(a int, b int) int, bool`). Arrow form `-> int`: CONFIRMED accepted (`D05_return_arrow.amni`), but `HELIUM.md` says no arrow (section 10, D-b).
- Export: CONFIRMED `S38_export_fn.amni` (`export fn he_add`), `S39_export_c.amni` (`export "my_add" fn add`).
- `thread_fn`: CONFIRMED in `.he`: `C09_thread_noarg.he` (prints 7 on a worker thread, joined). With a parameter, `S33_he_thread.he` is rejected ("no thread_fn worker matches these arguments"). Refined (skeptic pass): a `thread_fn` with parameters is fine when called directly (`spec/probes/ch1-review/X26_thread_arg.he`: `thread_fn work(n int)` called as `work(4)` prints 4). It cannot be passed to `thread_spawn`, which takes only zero-parameter workers, so `S33_he_thread.he` is rejected. The arity question in section 12 is resolved this way. CONFIRMED.

### 8.4 Blocks and statements

```ebnf
block          = "{" { stmt } [ expr ] "}" ;
stmt           = ";" (.he, or after a layout line) | fn_decl
               | ( "let" | "var" | "const" | "reusable" ) var-list ";"
               | "const" "for" const_for
               | guard
               | expr-stmt ;
var-list       = ident-list [ ":" ] [ type ] ( "=" expr-list | ".=" expr ) ;
guard          = "guard" expr ( "else" block [ ";" ] | ";" ) ;
expr-stmt      = expr [ assign ] ";"   (or the tail of a block)
               | expr "," lhs-list "=" expr-list ";"   (multi-target)
               | expr "++" ";" | expr "--" ";" ;
assign         = "=" | ".=" | "+=" | "-=" | "*=" | "/=" | "%=" | "&=" | "|=" | "^="
               | "<<=" | ">>=" | "//=" (.he) ;
```

- A block ends in an expression (no `;`) that becomes its value (`pstmt`, `pbody`: `ND[b].a`, `parse.he:606-648`). CONFIRMED: `D14_fn_nested_decl.amni`, `S08_block_expr.amni`.
- A statement-position `if`, `match`, `while`, `loop`, `for`, `block`, or a bare `{}` block needs no `;` (`K09b_amni_if_stmt.amni`, `K10b_amni_block_stmt.amni`). Without the trailing `;`, a non-block statement inside such blocks fails: `K09_amni_if_stmt_no_semi.amni` ("expected ';' ... found '}'") shows the required `;` before `}`.
- A missing `;` between two statements is rejected: `D03_missing_semi.amni`.
- A stray `;` in `.amni` is rejected: `K02_empty_stmt_amni.amni`. A `;` after a top-level function is rejected in `.amni`: `K20_amni_semicolon_after_fn.amni` (`top-level declaration expected, found ';'`). In `.he`, `;` is accepted at top level and in blocks (`parse.he:618-621`, `ptop` line 1049).
- `guard` continues the rest of the block when its condition holds (`pguard`, `parse.he:670`). CONFIRMED: `S09_guard_stmt.amni`, `S08_block_expr.amni` (`guard ... else { break -1; }` inside `block`).
- Assignments: CONFIRMED `S14_ref_binding.amni` (`var r .= xs[0]; r = 11; r .= xs[2];` and `r .== xs[2]`), `S13_for_ref.amni`, `S06_loops.amni` (`n += 7`, `n /= 2`).
- Multi-target assignment: a call's results (`a, b = two();`) is accepted (`S20_assign_list_multi.amni`). A swap `a, b = b, a;` is rejected in `.amni`, "expected ';' in assignment statement, found ','" (`S19_assign_list.amni`). In `.he` the right-hand side may be a list (`ptup`, `parse.he:662`): `S19b_swap.he` (prints `21`), `S24_he_tuple_assign.he` (prints 12). The `.amni` error message suggests `return`-based code; both forms are documented in `HELIUM.md` section 7.1.
- Multi-binding declaration: `let q, ok = divide(7, 2);` CONFIRMED: `D04_fn_return_list.amni`.
- `x++` and `x--` (EXP-POSTFIX-STEP).
- A nested function declaration in a block: CONFIRMED `D14_fn_nested_decl.amni`, `C18_he_nested_fn.he` (reads and writes the enclosing local, prints 4).

### 8.5 Control flow expressions

```ebnf
if_expr        = "if" scrut block [ "else" ( if_expr | block ) ] ;
match_expr     = "match" scrut "{" arm-list "}" ;
arm-list       = arm { ( "," | ";" (.he, layout) ) arm } [ "," ] ;
arm            = "_" "=>" expr
               | pattern-list "=>" expr
               | ident [ "&" ] ident "=>" expr ;      (one payload binding)
pattern-list   = pitem { "," pitem } ;
pitem          = pbound [ ".." pbound ] ;
pbound         = [ "-" ] ( int | qname ) ;
while_expr     = "while" scrut block ;
loop_expr      = "loop" block ;
for_stmt       = "for" [ "&" ] ident [ ":" ] [ type ] [ "," ident [ ":" ] [ type ] ]
                 "in" expr [ ".." expr ] block ;
block_expr     = "block" block ;
scrut          = expr   (struct literals and trailing blocks off here) ;
```

- `if` as a value needs `else` (`S10_if_no_else_value.amni`, rejected; wording "this expression has no value (the call returns nothing)" is misleading, see G10). `if` expressions chain with `else if` (`K19_amni_if_value_block.amni`, prints 2).
- `match`: CONFIRMED `S01_match_forms.amni` (literals, `1..10`, lists `10, 20, 30`, `_`, variant bindings `Circle c`, list `Rect, Dot`).
- Arms: a list may not contain `_` (`S03_match_underscore_list.amni`, "_ cannot be listed with other patterns").
- Arm separator: a block-valued arm needs `,` before the next arm (`T06_arm_block_no_comma.amni`, rejected, "expected '}' in match expression"); `T03b_pattern_ref_bind.amni` with commas is accepted.
- Negative literal patterns: CONFIRMED `S04_match_neg_pattern.amni` (`-1 => 10`).
- Ranges in patterns are half-open: CONFIRMED `S05_match_range_bound.amni` (`1..10` does not match 10, prints `b`).
- Payload binding by reference: `Circle &c =>` CONFIRMED `T03b_pattern_ref_bind.amni` (the binding is accepted and mutates the payload).
- `while` and `loop`: CONFIRMED `S06_loops.amni`. `loop` yields a value through `break value` (`let k = loop { ... break n; }` gives 35).
- `for` forms: CONFIRMED `S06_loops.amni` (`for x, i in [10, 20, 30]`, `for i in 2..5`, `for i in 3`), `S13_for_ref.amni` (`for &x in xs`), `F03_for_typed_amni.amni` (`for x: int in xs`), `H15_for_forms.he` (`for i xs`, `for x int in xs`, `for x, i in xs`).
- `break value` is valid only in `loop` and `block`, not `for` or `while`: `S07_break_value_for.amni` ("break with a value exits loop/block only").
- `continue` applies to the innermost loop; labels do not exist (`S06_loops.amni`).
- `return`: `return e, e2;` with the list form (`D04_fn_return_list.amni`). `S18_return_in_block.amni` (`let x = { return 9; };`) is rejected with the misleading message in G10; the cause (a block used as a value that returns) is a typing question for a later chapter.

### 8.6 Expressions

```ebnf
expr           = binary ;
binary         = unary { binop unary } ;      (precedence per 7.1)
binop          = "||" | "&&" | "==" | "!=" | ".==" | ".!=" | "<" | ">" | "<=" | ">="
               | "in" (.he) | "not" "in" (.he) | "|" | "^" | "&" | "<<" | ">>"
               | "+" | "-" | "*" | "/" | "%" | "//" (.he) ;
unary          = ( "-" | "!" | "~" | "&" ) unary | "not" (.he) binary-from-level-3 | power ;   (* EXP-NOT *)
power          = postfix [ "**" unary ] (.he) ;
postfix        = primary { call | index | "." ident | "as" [ "!" ] type } ;
call           = "(" [ expr { "," expr } [ "," ] ] ")" [ "{" block-body "}" ] ;
index          = "[" ( expr | [ "^" ] expr ".." [ "^" ] [ expr ] | ".." [ "^" ] expr ) "]" ;
primary        = int | real | string | "true" | "false" | "null" | "self"
               | qname [ type-args ] [ "{" field-init-list "}" ]
               | "(" expr ")" | array | if_expr | match_expr | while_expr | loop_expr
               | for_stmt | block_expr | block | "return" [ expr-list ] [ "from" qname ]
               | "break" [ expr ] | "continue"
               | ( "int" | "real" ) "(" expr ")" (.he) ;
array          = "[" [ expr { "," expr } [ "," ] | expr ";" expr | ".." expr ] "]" ;
field-init     = [ ident ":" ] expr | "pad" .. ".." ;     (named or positional, not mixed)
```

- `.` method call `x.f(a)` means `f(x, a)` (CONFIRMED: `S11_trailing_block.amni`, `xs.filter() { ... }`).
- A trailing block `{ it ... }` or `{ a, b => ... }` belongs to the last call and only when the `{` is not on a new layout line (`pcall`, `parse.he:410-424`, `!NOSL && !TK[P].lay`). CONFIRMED: `S11_trailing_block.amni` (`xs.filter() { ... }`, `xs.map() { ... }`, `fold(xs, 0) { acc, x => acc + x }`), `C10_he_lambda.he` (prints `[2, 4, 6]`).
- `..` in a struct literal fills the remaining fields with defaults: CONFIRMED `S16_struct_lits.amni` (`Unit { kind: 3, .. }`, `c.hp` = 100).
- Struct literals: named or positional, never mixed: CONFIRMED `S16` (named and positional both accepted), `S17_struct_mixed.amni` (rejected, "struct literal mixes named and positional initializers").
- Generic type arguments on a call or literal: `scale<real>(1.5)` and `Pair<int> { 1, 2 }` (`try_tyargs`, `parse.he:479-503`). CONFIRMED: `D07_generics.amni`.
- Array literals: `[a, b, c]`, `[v; n]`, `[]`, `[..n]` (capacity form, `parray`). CONFIRMED: `S15_list_literals.amni` (`[0; 4]`, `[]`, `[1, 2, 3][1]` = 2). `[..n]` CONFIRMED (skeptic pass): `spec/probes/ch1-review/X21_arr_cap_amni.amni` (`var xs int[>..] = [..4]; xs.push(3)` gives `xs.len` 1).
- Indexing and slicing: CONFIRMED `S12_slices.amni` (`xs[1..3]` = `[2, 3]`, `xs[..2]`, `xs[^2..]` = last two, `xs[2..]`, `xs[1..^1]` = `[2, 3, 4]`), `S23_index_neg.amni` (`xs[-1]` is a runtime bounds error, not a parse error).
- `&` prefix (reference) in expressions parses: `let r = &x;` (`T05_ref_unary.amni`, prints 1). Its typing is outside this chapter. UNCONFIRMED for the full reference semantics.
- `int(x)` and `real(x)` conversions in `.he` (`pprim`, `parse.he:449-478`): CONFIRMED (skeptic pass): `spec/probes/ch1-review/X16_he_intcall.he` (`int(3.7)` prints 3, `real(2)` prints 2.0).
- Postfix `.Variant` on a type name (`Shape.Circle { r: 2.0 }`) is a variant literal: CONFIRMED `S01_match_forms.amni`, `C04`.
- `if`, `match`, `while`, `loop`, `for`, `block` are expressions (`pexpr`, `parse.he:178-216`). `match` and `if` can be used in an argument list.

### 8.7 Types

```ebnf
type           = [ "const" ] type_base { type_suffix } ;
type_base      = prim [ ( "in" | "upto" ) qname ]
               | qname [ "<" type { "," type } ">" ]
               | "fn" [ "(" [ type { "," type } ] ")" [ "->" ( type | "(" type-list ")" ) ] ]
               | "(" type ")" ;
prim           = "bool" | "varint" | "i8" | "i16" | "i32" | "i64" | "u8" | "u16" | "u32" | "u64"
               | "f32" | "f64" | "int" | "uint" | "byte" | "real" ;
type_suffix    = "[" "]"                              (* growable-by-construction array, A_VAR *)
               | "[" ":" "]"                          (* slice *)
               | "[" ".." [ expr ] "]"                (* inline capacity; A_LIM *)
               | "[" ">" ".." [ "<" ] "]"             (* resizable; A_GROW or A_GS *)
               | "[" lenstore "]"                     (* length type: u8 u16 u32 u64 uint byte varint *)
               | "[" expr "]"                         (* fixed length *)
               | "&" [ "<" lenstore [ "in" qname ] ">" ]   (* reference / relative link *)
               | "?"                                  (* optional *)
               | ".." | "." ident ;                   (* variable mode / variant *)
```

- Primitive names: `int`, `uint`, `byte` (= u8), `real` (= f64), and the rest of the list (`lex.he:12`). CONFIRMED: `D11_unsigned_types.amni`, `L19_f32_lit.amni`, `D12_type_names_bad.amni` (`f16` rejected, "unknown type f16").
- Array suffixes: `int[>..]` CONFIRMED `S12`/`S13` (resizable), `int[..4]` CONFIRMED `D10_type_forms.amni` (capacity), `int[varint]` CONFIRMED `D10` (length type), `int[3]` CONFIRMED `D10`, `int[:]` CONFIRMED `D10` (slice param), `int[>..<]` and `int[..]` CONFIRMED `T01_type_forms2.amni`, `byte[..16]` CONFIRMED `D10`.
- Optional: `Node?`, `int?`, CONFIRMED `D10_type_forms.amni`, `S01`.
- Reference parameter `int&`: CONFIRMED `P09_ref_amp_unary.amni` (`fn bump(n int&)`).
- Variable-mode ADT `Shape..`: CONFIRMED `T01_type_forms2.amni` (`struct Holder { s Shape.. }`).
- Variant type `Shape.Circle` in a parameter: CONFIRMED by the `HELIUM.md` example `fn area(s Shape.Circle)`, and by the skeptic pass (`spec/probes/ch1-review/V08_variant_type_param.amni`, prints 12.0).
- `const T` marks a read-only type: CONFIRMED `S01` (`const byte[:]` return), `D06` (`const int[SIZE]`).
- Index types `int in Name`, `int upto Name`: CONFIRMED by the skeptic pass (`spec/probes/ch1-review/V03_index_type.amni`, `V04_upto_type.amni`: both parse as parameter types and run).
- Function type: `fn(int) -> int` parses (`D13b_fn_type_arrow.amni`), and a parameter of this type cannot be called ("this call's callee is not supported yet"). `fn(int) int` without the arrow is rejected (`D13_fn_type.amni`). Function values are compile-time only (`HELIUM.md`).
- Type annotation after `:` in declarations and parameters: CONFIRMED `D01_colon_types.amni`. See section 10 (D-a).

### 8.8 Patterns

Patterns appear only in `match` arms and `for` bindings. The grammar is in 8.5. Summary:

- `_` matches anything and must stand alone (`ppattern`, `parse.he:315-339`).
- An integer or negative integer constant, or a name (a variant or a constant).
- A range `a..b` with exclusive upper bound.
- A variant name with an optional single payload binding `c` or `&c`.

### 8.9 Compile-time forms

```ebnf
const_for      = "<" names ">" "in" ( "[" expr-list "]" | ( "fields" | "variants" | "types" ) "<" type-list ">" ) ( block | "{" arms "}" | "{" field-inits "}" ) ;
```

- `const for <k> in [1, 2, 3] { ... }` CONFIRMED `S22b_const_for_list.amni` (prints 6).
- `const for <N, A> in fields<P> { ... }` CONFIRMED `C01_const_for_fields_two.amni` (prints 2).
- `const for <f> in fields<P>` (one name) is rejected: "fields<T> and variants<E> bind two names" (`S21c_const_for_fields.amni`). The `const for f in fields<P>` form (no `<`) is rejected (`S21b_const_for.amni`).
- `const for` in `.he` CONFIRMED `S25_he_const_for.he` (prints 6).

## 9. Rule catalogue

Each row: ID, the rule, the source location that enforces it, evidence (probe program, observed result), status. Probe names are files under `spec/probes/ch1/`.

| ID | Rule | Source | Evidence | Status |
|---|---|---|---|---|
| LEX-FILE-1 | extension selects syntax | `lex.he:150-160` | every probe | CONFIRMED |
| LEX-FILE-2 | `.he` pre-pass: f-strings, multi-char `'...'` | `lex.he:91-104` | `F01_fstring_he.he`, `F02_fstring_amni.amni`, `H24_he_single_quote_multi.he` | CONFIRMED |
| LEX-FILE-3 | `.he` Python-mode detection (gotcha) | `lex.he:79-88` | `H13_at_top_col0.he`, `H19_py_at_col0_mix.he` | CONFIRMED |
| LEX-FILE-4 | BOM skipped | `lex.he:159` | `Z03_bom.amni` (skeptic pass) | CONFIRMED |
| LEX-FILE-5 | `lut fn` desugar only in `.amni` | `lex.he:155` | `S31_lut_he.he` (correct value), `S32_lut_amni.amni` | CONFIRMED (result), memo UNCONFIRMED |
| LEX-WS | whitespace, tabs | `lex.he:171` | `C15_he_tab_indent.he` | CONFIRMED |
| LEX-CMT-LINE | `//` line comment in `.amni` | `lex.he:173` | `L13_block_comments.amni` | CONFIRMED |
| LEX-CMT-BLOCK | nested `/* */`, unterminated error | `lex.he:189-195` | `L13`, `L14_unterminated_comment.amni` | CONFIRMED |
| LEX-CMT-HE | `#` and `@` line comments in `.he` | `lex.he:174` | `H11`, `H12`, `K18_he_at_inline.he`, `C13_he_string_hash.he` | CONFIRMED |
| LEX-CMT-HE-SLASH | `//` is floor division in `.he`, not comment | `lex.he:322` | `K13_he_comment_slash.he`, `K17_he_floor_div.he` | CONFIRMED |
| LEX-ILLEGAL | illegal character error | `lex.he` operator chain tail | `L15_illegal_char.amni`, `L18_hash_in_amni.amni`, `L20_unicode_ident.amni` | CONFIRMED |
| LEX-IDENT | ASCII identifiers, `_` legal | `lex.he:55`, `196` | `L20`, `K05_underscore_name.amni` | CONFIRMED |
| LEX-KW | 49 reserved keywords | `lex.he:12`, `18` | `L16`, `K04`, `K07`, `K08` | CONFIRMED |
| LEX-KW-PY | `and or not elif` keywords in `.he` | `lex.he:224` | `H05_word_ops.he`, `H07_inline_block.he` | CONFIRMED |
| LEX-CTX | contextual words (`inline checkfree upto lut from fields types variants use`) | `lex.he:226`, `parse.he:1048` | `K03_inline_as_name.amni`, `S34_he_use_import.he` | CONFIRMED |
| LIT-INT-DEC | decimal integers, leading zeros; `int` default, `uint` above 2^63-1 with no context | `lex.he:196-217` | `L25_leading_zero.amni`, `L01b_ints.amni`, `Q05_big_dec_noctx.amni`, `Q11_type_of_big.amni` | CONFIRMED (corrected) |
| LIT-INT-HEX | hex integers, up to 16 digits, `uns` above i64 | `lex.he:198-207` | `L01b`, `L02_int_hex_big.amni`, `L04` | CONFIRMED |
| LIT-INT-RANGE | 64-bit range error | `lex.he:216` | `L03_int_too_big.amni`, `L33`, `L32` | CONFIRMED |
| LIT-NO-SEP | no digit separators | `lex.he:55` (idc) | `L01_ints.amni` (error), `X05_dec_sep.amni` (decimal, error) | CONFIRMED |
| LIT-NO-BIN-OCT | no `0b` / `0o` literals | `lex.he:198` | `L21_binlit.amni`, `L22_octlit.amni` | CONFIRMED |
| LIT-FLT | real literal forms; `1.` is not real | `lex.he:208-215` | `L05_reals.amni`, `L06`, `L23` | CONFIRMED |
| LIT-FLT-EXP | exponent needs digits | `lex.he:212` | `L24_exp_no_digits.amni` | CONFIRMED |
| LIT-FLT-HEX | hex real: fraction, `p` exponent, or both | `lex.he:198-204` | `L05`, `L31_hex_float_nodot.amni`, `X01_hex_real_nop.amni` (no `p`, prints 1.5) | CONFIRMED (corrected) |
| LIT-F32 | no f32 suffix; context typed | (typing) | `L19_f32_lit.amni` | CONFIRMED |
| LIT-REAL-INT | real does not convert to int implicitly | (typing) | `L30_real_exp_int.amni` | CONFIRMED |
| LIT-CHAR | char literal is int | `lex.he:230-233` | `L07_char_lits.amni`, `L17_byte_is_int.amni`, `L09` | CONFIRMED |
| LIT-ESC | escape set; no `\u` | `lex.he:68-76` | `L07`, `L08_bad_escape.amni`, `L10_str_escapes.amni`, `L29` | CONFIRMED |
| LIT-STR | single-line strings | `lex.he:235-273` | `L10`, `L11_str_unterminated.amni` | CONFIRMED |
| LIT-STR-ML | triple-quote strings, indentation rules | `lex.he:238-271` | `L12_triple_str.amni`, `H17_multiline_str.he` | CONFIRMED |
| LEX-OP-LONGEST | longest-match operators | `lex.he:294-322` | `P02_shift_vs_add.amni` | CONFIRMED |
| LEX-OP-POW-AMNI | `**` only in `.he` | `lex.he:320` | `P07_pow_amni.amni` | CONFIRMED |
| LEX-OP-DIV-ASSIGN | `/=` vs `//=` | `lex.he:322` | `K15`, `K14_he_division_eq.he` | CONFIRMED |
| LAY-BLOCK | `:` opens an indented block | `lex.he:175-186`, `277-279` | `H06_colon_block.he`, `H10_expected_indent.he` | CONFIRMED |
| LAY-SEMI | newline inserts `;`; comma at line end too | `lex.he:175-186` | `H01_basic.he`, `M01_he_multiline_struct.he`, `M02_he_multiline_enum.he` | CONFIRMED |
| LAY-DEDENT | dedent must match an open level | `lex.he:181-184` | `C14_he_dedent_mismatch.he`, `H09_bad_indent.he` | CONFIRMED |
| LAY-INLINE | `: a; b` one-line block | `lex.he:278` | `H07`, `H08_inline_semicolons.he` | CONFIRMED |
| LAY-ELSE | `else:`, `elif`, `else if` | `lex.he:224-225`, `lay_else` (77) | `H07`, `C11_he_else_if_chain.he` | CONFIRMED |
| LAY-DEPTH | layout off in brackets | `lex.he:279` | `C06_he_multiline_call.he`, `C07_he_multiline_list.he` | CONFIRMED |
| LAY-BRACE-SWITCH | braces switch layout off | `lex.he:279` | `C16_he_mixed_brace_block.he`, `H18`, `C03` | CONFIRMED |
| LAY-FN-OPT | `fn` optional in `.he` | `parse.he:89-99`, `pfn` 760 | `M04_he_fn_no_keyword.he` | CONFIRMED |
| LAY-SEMI-OPT | optional `;` in `.he` | `parse.he:88` | `K06_he_semicolon_end.he` | CONFIRMED |
| LAY-DECL-ASSIGN | `:=` let, `~=` var | `lex.he:277` | `H01`, `H16_walrus_let.he`, `C19_he_fn_result_list.he` | CONFIRMED |
| LAY-FOR | `for i xs`, `for x T in xs` | `parse.he:225-251` | `H15_for_forms.he` | CONFIRMED |
| LAY-NO-TERNARY | no `x if c else y` in `.he` | `parse.he:185` (Python only) | `H14_ternary_he.he` | CONFIRMED |
| LAY-INLINE-STRUCT | `struct P: x real, y real` | `parse.he:719-736` | `C02_he_struct_inline.he` | CONFIRMED |
| LAY-MATCH | layout `match` arms | `parse.he:297-305` | `M03_he_match_layout.he`, `M05_he_var_block_match_int.he` | CONFIRMED |
| LAY-NO-CONT | no line continuation after a binary operator or `.` outside brackets | `lex.he:187` | `Z01_he_cont_plus.he`, `Z02_he_cont_dot.he` | CONFIRMED |
| EXP-PREC | precedence table 7.1 | `parse.he:348-409` | `P01`, `P02`, `P03`, `P05`, `P06`, `P10`, `H02_pow_assoc.he` | CONFIRMED |
| EXP-LEFT | binary left-assoc | `parse.he:358-378` | `P01`, `P15_div_mod_neg.amni` | CONFIRMED |
| EXP-POW-RIGHT | `**` right-assoc, above prefix ops | `parse.he:379-391` | `H02`, `H03b_chain_cmp.he` | CONFIRMED |
| EXP-UNARY | prefix binds to unary operand | `parse.he:379-391` | `P05`, `H05` | CONFIRMED |
| EXP-AS | `as` postfix, tighter than binary | `parse.he:392-409`, `fl` at `parse.he:408` | `P06_as_binds_tight.amni`, `T02_as_bang.amni`, `Q06_cast.amni`, `Q07_cast_i8.amni`, `AS1.amni` / `AS2.amni` / `AS3.amni` (`--debug`) | CONFIRMED (release: both wrap; `--debug`: `as` traps, `as!` wraps) |
| EXP-BITS-FIRST | `& ^ \|` and shifts bind tighter than compare | `parse.he:348-357` | `P03`, `P02` | CONFIRMED |
| EXP-BOOL | `&& \|\| !` need bool | (typing) | `P04_cmp_eq.amni` (error), `P04b_cmp_bool.amni` | CONFIRMED |
| EXP-DIV | `/` truncates, `%` Euclidean, `//` floors | `parse.he:358-378` (`v == 3`) | `P15`, `K17_he_floor_div.he` | CONFIRMED |
| EXP-POSTFIX-STEP | `++ --` statement only | `parse.he:618-648` | `P12`, `P13`, `P14` | CONFIRMED |
| EXP-CHAIN-HE | chained comparisons; every right operand in the chain must be an atom (kind 1 to 8) | `parse.he:375-378` (`rc`, `lc`) | `H03b`, `H21_chain_mixed_and.he`, `H22`, `H23`, `Y11_chain_str_mid.he`, `Y04_chain_mid_neg.he`, `X11_chain_compound_last.he` | CONFIRMED (refined) |
| EXP-CHAIN-AMNI | no chaining in `.amni` | `parse.he:358-378` (`he()` guard) | `P08_chain_cmp_amni.amni` | CONFIRMED |
| EXP-IN | `in` / `not in` membership, `.he` | `parse.he:348-378` (`K_IN && he()`) | `H04_in_op.he`, `L26_in_amni.amni` | CONFIRMED |
| EXP-WORDS | `and or` in `.he` (`not` moved, see EXP-NOT) | `lex.he:224` | `H05_word_ops.he`, `Y03_not_and.he` | CONFIRMED |
| EXP-NOT | `not` (`.he`) operand is `pbin(3)`: binds looser than `==`, `<`, bitwise, shifts, arithmetic; tighter than `&&` | `parse.he:379-383` | `Y01_not_prec.he`, `Y14_not_arith.he`, `Y03_not_and.he`, `Y02_bang_prec.he` | CONFIRMED (skeptic pass; level-3 claim REFUTED) |
| EXP-STR-PLUS | `+` concatenates strings in `.he`; `.amni` rejected | `parse.he:372` | `L27_he_str_concat.he`, `P11_plus_string_amni.amni` | CONFIRMED (`.he`); `.amni` KNOWN GAP G1 |
| EXP-TRAIL-BLOCK | trailing block on last call | `parse.he:410-424` | `S11_trailing_block.amni`, `C10_he_lambda.he` | CONFIRMED |
| EXP-TYARGS | generic call and literal | `parse.he:479-503` | `D07_generics.amni` | CONFIRMED |
| EXP-STRUCT-LIT | named or positional, not mixed, `..` | `parse.he:553-577` | `S16`, `S17_struct_mixed.amni` | CONFIRMED |
| EXP-ARRAY | `[a, b]`, `[v; n]`, `[]`, `[..n]` | `parse.he:504-520` | `S15_list_literals.amni`, `X21_arr_cap_amni.amni` | CONFIRMED |
| EXP-INDEX | index and slice forms incl. `^k` | `parse.he:425-448` | `S12_slices.amni`, `S23_index_neg.amni` | CONFIRMED |
| EXP-REF-BIND | `.=`, `.==`, `.!=` | `parse.he:618-648` (`T_DOTASSIGN`), `lex.he:278` | `S14_ref_binding.amni` | CONFIRMED |
| EXP-BLOCK | `block {}` and `{}` values; `if` needs `else` | `parse.he:178-216` | `S08_block_expr.amni`, `K19`, `S10_if_no_else_value.amni` | CONFIRMED |
| EXP-LOOP-BREAK | `break value` only in `loop` or `block` | `parse.he:186-193` | `S06`, `S07_break_value_for.amni` | CONFIRMED |
| EXP-METHOD | `x.f(a)` is `f(x, a)` | `parse.he:392-409` | `S11` | CONFIRMED |
| EXP-REF-PREFIX | prefix `&` parses | `parse.he:379-391` | `T05_ref_unary.amni` | CONFIRMED (parse); semantics UNCONFIRMED |
| EXP-INT-CONV | `int(x)` / `real(x)` in `.he` | `parse.he:449-478` | `X16_he_intcall.he` | CONFIRMED |
| EXP-CALL-NOARGS | trailing `,` in call arguments and parameter lists | `parse.he:410-424`, `pfn` 760 | `X28_amni_fn_trailing_comma.amni`, `X29_call_trailing_comma.amni`, `X30_he_call_trailing_comma.he`, `X27_he_fn_trailing_comma.he` | CONFIRMED |
| STM-TERM | `;` required except block-ended statements | `parse.he:618-648`, `semi` 88 | `D03_missing_semi.amni`, `K09b`, `K10b`, `K02`, `K20` | CONFIRMED |
| STM-GUARD | `guard c else { ... }` | `parse.he:670-678` | `S09_guard_stmt.amni`, `S08` | CONFIRMED |
| STM-ASSIGN | `=` and compound assignment | `parse.he:618-648` | `S06`, `S13`, `S14` | CONFIRMED |
| STM-MULTI-AMNI | `a, b = f()` only; swap rejected in `.amni` | `parse.he:649-661` | `S19_assign_list.amni`, `S20_assign_list_multi.amni` | CONFIRMED |
| STM-MULTI-HE | `a, b = b, a` in `.he` | `parse.he:662-669` | `S19b_swap.he`, `S24_he_tuple_assign.he` | CONFIRMED |
| STM-DECL-LIST | `let a, b = f()` | `parse.he:679-704` | `D04` | CONFIRMED |
| STM-FN-NESTED | nested `fn` in a block | `pstmt` 618-625 | `D14`, `C18_he_nested_fn.he` | CONFIRMED |
| STM-BLOCK-TAIL | block tail expression is the value | `parse.he:606-617` | `D14`, `S08`, `C17_he_block_semicolon_tail.he` | CONFIRMED |
| STM-EMPTY | bare `;` rejected in `.amni` | `parse.he:618-621` | `K02_empty_stmt_amni.amni` | CONFIRMED |
| PAT-WILD | `_` alone | `parse.he:315-339` | `S01`, `S03` | CONFIRMED |
| PAT-LIST | `A, B =>` | `parse.he:315-339` | `S01` | CONFIRMED |
| PAT-NEG | negative literal pattern | `parse.he:340-347` | `S04_match_neg_pattern.amni` | CONFIRMED |
| PAT-RANGE | half-open range pattern | `parse.he:315-339` | `S05_match_range_bound.amni` | CONFIRMED |
| PAT-BIND | payload binding `c`, `&c` | `parse.he:315-339` | `S01`, `T03b_pattern_ref_bind.amni` | CONFIRMED |
| PAT-ARM-SEP | block arm needs `,` | `parse.he:306-314` | `T06_arm_block_no_comma.amni` | CONFIRMED |
| PAT-VARIANT-QUAL | payload pattern with a type-qualified name, `Shape.Circle c =>` | `parse.he:315-339` | `V01_qual_payload_pat.amni` (rejected, `expected '=>' in match arm`) | CONFIRMED (rejected) |
| PAT-QUAL-DOT | qualified variant pattern `C.Red =>` | `parse.he:315-339` | `G14_arm_qname.amni` (rejected, parse error at `.`); `G23_qname_colons.amni` (`C::Red` parses, then `no variant C::Red in C`) | CONFIRMED (rejected) |
| PAT-INT-WILD | int match needs `_` | `parse.he:297-305` | `S02_match_no_wild_int.amni` (accepted) | KNOWN GAP G2 |
| LOOP-FOR | `for` forms | `parse.he:225-251` | `S06`, `S13`, `F03_for_typed_amni.amni`, `H15` | CONFIRMED |
| LOOP-WHILE-LOOP | `while`, `loop` | `parse.he:186-193` | `S06` | CONFIRMED |
| CTRL-IF | `if` / `else if` | `parse.he:217-224` | `K19`, `C11` | CONFIRMED |
| CTRL-MATCH | `match` expression | `parse.he:297-305` | `S01` | CONFIRMED |
| DEC-VAR | `let`, `var`, `const`, `reusable` locals | `parse.he:679-704` | `S42_reusable_let.amni`, `D04`, `S14` | CONFIRMED |
| DEC-COLON | colon before type optional | `parse.he:679-704`, `719-735` | `D01_colon_types.amni`, `D02_no_colon_types.amni` | CONFIRMED (disagrees with HELIUM.md, D-a) |
| DEC-GLOBAL | global `let SIZE = 4;` | `parse.he:679-704`, `ptop` 1048 | `D06_let_global_const.amni`, `Q01_global_var_noinit.amni`, `Q02_global_let_noinit.amni` | CONFIRMED |
| DEC-GLOBAL-REUSABLE | `reusable` is not a file-scope declaration | `parse.he:679-704`, `ptop` 1048 | `G10_reusable_global.amni` (rejected, `let, var or const expected`) | CONFIRMED (grammar line corrected) |
| DEC-STRUCT | struct fields, defaults, `let`/`const`, `pad` | `parse.he:719-736` | `S16`, `D02`, `S41` | CONFIRMED |
| DEC-ENUM | enum variants, payload braces | `parse.he:745-759` | `S01`, `C04` | CONFIRMED |
| DEC-GENERICS | generics on fn, struct and enum (parse and type-check; enum match is a backend limit) | `parse.he:705-718` | `D07_generics.amni`, `Y08_enum_generic_nomatch.amni`, `X23_enum_generic.amni`, `G02_generic_trail.amni`, `G03_generic_bound.amni` | CONFIRMED |
| DEC-ALIAS | `type X = T;` | `parse.he:1048-1060` | `S37_type_alias.amni` | CONFIRMED |
| DEC-IMPORT | `import m;` then unqualified names | `parse.he:1048-1093` | `K01_import_fn.amni` (`sqrt`), `S34_he_use_import.he` | CONFIRMED |
| DEC-IMPORT-QUAL | `math::sqrt`, `math.sqrt` | `parse.he:1048-1093` | `S35_import_dot.amni`, `C08_math_dot.amni` (rejected) | CONFIRMED (rejected; see section 10) |
| DEC-NAMESPACE | `namespace` in root hides `main` | `parse.he:1048-1060` | `S36_namespace.amni` | KNOWN GAP G5 (disagrees with HELIUM.md D-e; the cross-reference D-g was a typo) |
| DEC-EXTERN-BLOCK | `extern "lib" { fn ...; }` | `parse.he:1048-1093` | `S40_extern_amni.amni` | CONFIRMED |
| DEC-EXTERN-BARE | `extern fn` without block in `.he` | `pfn` 760 | `C05_he_extern_fn.he` (rejected) | KNOWN GAP G6 |
| DEC-EXPORT | `export fn`, `export "sym" fn` | `pfn` 760 | `S38`, `S39` | CONFIRMED |
| DEC-LUT | `lut fn` | `lex.he:155` | `S32_lut_amni.amni` | CONFIRMED |
| DEC-THREAD | `thread_fn` | `pfn` 760 | `C09_thread_noarg.he`, `X26_thread_arg.he` (direct call with arg works), `S33_he_thread.he` (spawn with arg rejected) | CONFIRMED (refined) |
| DEC-FN-PARAM-DEFAULT | parameter defaults | `pfn` 760 | `D08_default_params.amni` | CONFIRMED |
| DEC-FN-PARAM-VAR | `var` parameter | `pfn` 760 | `D09_param_var.amni` | CONFIRMED |
| DEC-FN-PARAM-UNTYPED | untyped parameters are generic | `pfn` 760 | `T04_untyped_param.amni` | CONFIRMED |
| DEC-FN-RET | return list; arrow form | `pfn` 760 | `D04`, `D05_return_arrow.amni`, `G22_ret_list_arrow.amni` | CONFIRMED (arrow disagrees with HELIUM.md, D-b) |
| FN-MOD-ORDER | `fn_mod` order is fixed: `lut`, `checkfree`, `export`, `extern`, `checkfree`, `simd`, `inline`, `recursive`, then `fn` (the EBNF `{ fn_mod }` was wrong) | `pfn` 760-775 | `G04_fnmods.amni` (rejected: `recursive inline`), `G16_inline_rec.amni` (accepted: `inline recursive`), `G20_export_inline.amni` (rejected: `inline export`), `O03.amni` (accepted: `export inline`), `O04.amni` (rejected: `inline checkfree`), `O05.amni` (accepted: `checkfree inline`), `O06.amni` (rejected: `recursive simd`), `O07.amni` (accepted: `simd recursive`), `O01.amni` (`export simd`), `O02.amni` (`simd inline`), `G18_simd_fn.amni`, `G19_checkfree_fn.amni` | CONFIRMED (corrected) |
| EXT-RENAME | `= "sym"` symbol rename, only on extern declarations | `pfn` 800-808 | `V07_extern_rename_so6.amni` (accepted), `V02_extern_rename.amni` (plain fn rejected), `V05_extern_rename_amni.amni` (bare extern, native backend) | CONFIRMED (refined) |
| DEC-RECURSIVE | `recursive` marker required | `pfn` 760 | `D15_recursive_marker.amni`, `D16_recursive_missing.amni` (accepted) | KNOWN GAP G3 |
| DEC-CONST-FOR | `const for <N> in [..]`, `<N, A> in fields<T>` | `parse.he:521-552` | `S22b`, `C01`, `S21b`, `S21c` | CONFIRMED |
| DEC-TYPE-ARRAY | array type forms, including `int in Name` and `int upto Name` | `parse.he:119-151` | `D10_type_forms.amni`, `T01_type_forms2.amni`, `V03_index_type.amni`, `V04_upto_type.amni` | CONFIRMED |
| DEC-TYPE-OPT | `T?` | `parse.he:119-151` | `D10` | CONFIRMED |
| DEC-TYPE-REF | `T&` | `parse.he:119-151` | `P09_ref_amp_unary.amni` | CONFIRMED |
| DEC-TYPE-VARMODE | `T..` on ADT | `parse.he:119-151` | `T01_type_forms2.amni` | CONFIRMED |
| DEC-TYPE-FN | `fn(T) -> R` type | `parse.he:152-177` | `D13b_fn_type_arrow.amni` (parses; call rejected), `D13_fn_type.amni` (rejected without arrow) | CONFIRMED |
| DEC-TYPE-PRIM | primitive names | `lex.he:12` | `D11_unsigned_types.amni`, `D12_type_names_bad.amni` | CONFIRMED |
| DEC-TYPE-CONST | `const T` | `parse.he:119-151` | `S01`, `D06` | CONFIRMED |
| LIT-ESC-TYPE-BYTE | `byte` is `u8` | `lex.he:12` | `L17_byte_is_int.amni` | CONFIRMED |
| DIAG-1 | `if` value without `else` message | `pstmt`/typing | `S10_if_no_else_value.amni` | KNOWN GAP G10 |
| DIAG-2 | `native backend:` message leaks for `+` on strings in `.amni` | `parse.he:372`, backend | `P11_plus_string_amni.amni` | KNOWN GAP G1 |
| DIAG-3 | `S18_return_in_block.amni` wording | typing | `S18_return_in_block.amni` | UNCONFIRMED (message is misleading; cause not isolated) |

Counts for this table are in section 14.

## 10. Disagreements between `HELIUM.md` and the compiler

Compiler behavior wins for the spec. Each item is either a `HELIUM.md` statement that hc does not enforce, or a form hc accepts that the guide forbids.

- D-a. `HELIUM.md` says no colon before a type in declarations (`fn f(a int, b real) int, bool`). hc accepts `var n: int = 4`, `fn add(a: int, b: int) int`, and `struct P { x: real }` (`D01_colon_types.amni`). Both forms are valid.
- D-b. `HELIUM.md` says no `->` before results. hc accepts `fn f(a int) -> int` (`D05_return_arrow.amni`) and `fn(int) -> int` in types (`D13b_fn_type_arrow.amni`). Both forms are valid.
- D-c. `HELIUM.md` says `match` on integers needs `_`. hc accepts `match n { 0 => 1, 1 => 2 }` with no wildcard (`S02_match_no_wild_int.amni`). The spec records this as KNOWN GAP G2.
- D-d. `HELIUM.md` says recursion must be marked `recursive fn`. hc accepts unmarked recursion (`D16_recursive_missing.amni`, prints 120). KNOWN GAP G3.
- D-e. `HELIUM.md` says `namespace geo;` scopes a file and `fn main()` in the root is the entry. In the root file, a `namespace` before `main` moves `main` into that namespace, and the program fails with "program needs exactly one global fn main()" (`S36_namespace.amni`). KNOWN GAP G5.
- D-f. `HELIUM.md` shows `math` functions after `import math;`. That works (`K01_import_fn.amni`). The qualified form `math::sqrt` and `math.sqrt` is rejected (`S35`, `C08`). The spec records the unqualified form only.
- D-g. `HELIUM.md` describes `.he` as "the same language with layout". Python-mode detection (LEX-FILE-3) can replace the whole file's grammar. This is a gotcha, not a language rule.
- D-h. `HELIUM.md` says `lut fn` works in `.amni` only. Consistent with `hc/TODO.md` section 1; `.he` runs it as a plain function.

## 11. Known gaps (summary)

| ID | Gap | Evidence |
|---|---|---|
| G1 | `+` on strings in `.amni` rejected with an internal backend message, not a parse diagnostic | `P11_plus_string_amni.amni` |
| G2 | integer `match` without `_` accepted; non-exhaustive match is not diagnosed | `S02_match_no_wild_int.amni` |
| G3 | unmarked recursion accepted; `recursive` marker not enforced | `D16_recursive_missing.amni` |
| G5 | `namespace` in the root file hides `main` | `S36_namespace.amni` |
| G6 | bare `extern fn` in `.he` (no library block) is not available natively | `C05_he_extern_fn.he` |
| G7 | `.he` `lut fn` is a plain function, not memoized (per `hc/TODO.md` section 1) | `S31_lut_he.he` |
| G8 | a column-0 `@` comment or `name = value` line in `.he` switches the file to Python mode (LEX-FILE-3). Worse (skeptic pass): a column-0 line inside a triple-quoted string does the same, and the file then compiles and runs with no output and exit 0 | `H13_at_top_col0.he`, `H19_py_at_col0_mix.he`, `Y13_ml_col0_trap.he` |
| G9 | a comma at a `.he` line end inserts `;`, so multi-line struct and enum bodies fail | `M01_he_multiline_struct.he`, `M02_he_multiline_enum.he` |
| G10 | diagnostics for `if` used as a value without `else` and for a `block {}` that returns a value say "this expression has no value (the call returns nothing)", which is misleading | `S10_if_no_else_value.amni`, `S18_return_in_block.amni` |
| G11 | `0x` with no digits is accepted as the integer 0 (the rule says "up to 16" digits) | `X02_hex_empty.amni` |
| G12 | `extern "m" { ... }` loads `/usr/lib/libm.so`, a linker script, so the program builds and then fails at startup with `invalid ELF header`; `extern "libm.so.6"` works | `V06_extern_block_rename.amni`, `V07_extern_rename_so6.amni` |

G7 matches `hc/TODO.md` section 1. Gap IDs are not contiguous (G4 was merged into G2 and removed); the IDs used in the text all appear in this table.

Note on G11 and G12 (skeptic pass): G11 is a zero-digit literal accepted without a diagnostic. G12 is a run-time failure, not a build failure: the build succeeds, and the program fails at startup with `invalid ELF header` because `libm.so` on glibc systems is a text linker script. Library names must be loadable objects such as `libm.so.6`.

Note on G8 and G9: they are language-level hazards of the `.he` layout rules, not bugs in one construct. Both are in scope for the grammar chapter because a `.he` program can fail for these reasons without any error in the code the author intended.

## 12. Probes not run

These rules are read from source only. Each needs a probe before the status changes.

All ten items on the original list were probed in the skeptic pass (see the Review section): BOM, decimal `1_000`, enum generics, `int in`/`upto` index types, `int(x)`/`real(x)`, `[..n]`, the type-qualified payload pattern (rejected), the `thread_fn` arity, the `=` extern rename, and `as!` under `--debug`. Still not probed: `lut fn` memoization in `.he` (LEX-FILE-5). Also not a grammar question: `int[]` growable arrays with `push` are rejected by the native backend (`spec/probes/ch1-review/G08_growable.amni`, `native backend: push, append, pop, resize ...`).

## 13. Probe index

Probe programs were compiled with `HC_LIB=hc/lib build/hc build <file> -o <bin>` and run. Files are in `spec/probes/ch1/`: 198 Helium source files, including repeats after corrections (for example `L01` and `L01b`, `P04` and `P04b`, `H03` and `H03b`, `S19` and `S19b`, `T03` and `T03b`, `K09` and `K09b`, `K10` and `K10b`, `S21`/`S21b`/`S21c`, `S22`/`S22b`, `D13`/`D13b`, `C01`). Several probes are deliberate rejections, which is the expected result for them.

Method note. Probes were run from inline shell loops, not from script files. The compiled binaries and `.err` files are still in `spec/probes/ch1/`. One cleanup step was blocked by the sandbox (a removal through a variable path), so those files need to be deleted by the owner or by a literal-path cleanup.

## 14. Count summary

- Rule rows in section 9 (after the skeptic pass): 131. CONFIRMED 124 (EXP-STR-PLUS carries a `.amni` KNOWN GAP G1 part in its cell), UNCONFIRMED 1 (DIAG-3), KNOWN GAP 6 (PAT-INT-WILD, DEC-NAMESPACE, DEC-EXTERN-BARE, DEC-RECURSIVE, DIAG-1, DIAG-2). Rows marked CONFIRMED with a partial qualifier (for example EXP-AS, DEC-IMPORT-QUAL) keep that qualifier in their cell. Rows added by the skeptic pass: EXP-NOT, LAY-NO-CONT, PAT-VARIANT-QUAL, PAT-QUAL-DOT, DEC-GLOBAL-REUSABLE, FN-MOD-ORDER, EXT-RENAME.
- Known gaps listed in section 11: 11 (G1, G2, G3, G5, G6, G7, G8, G9, G10, G11, G12).
- Disagreements with `HELIUM.md` in section 10: 5 true disagreements (D-a, D-b, D-c, D-d, D-e). D-f, D-g and D-h are notes, not contradictions.
- Probes not run (section 12): 1 item (LEX-FILE-5 memoization); the other nine were probed in the skeptic pass.
- Probe programs: 198 (original, `spec/probes/ch1/`) and 121 (skeptic pass, `spec/probes/ch1-review/`).

## Review (skeptic pass)

Reviewer: skeptic pass over sections 1 to 14. Method: re-ran all 198 original probes from `spec/probes/ch1/` (outcomes in `spec/probes/ch1-review/results_ch1.txt`); every recorded accept or reject matched. Wrote 121 new probes in `spec/probes/ch1-review/`, all Helium, compiled with `HC_LIB=hc/lib build/hc build`. Checked the cited lines in `lex.he` and `parse.he`; the citations that were wrong are fixed (see the list below).

Refuted and corrected in place (the rule text changed; the new rule is CONFIRMED with its program):
1. LIT-FLT-HEX: the "mandatory `p`" claim is false. `0x1.8` is a real, 1.5 (`X01_hex_real_nop.amni`).
2. LIT-INT-DEC: the default type is not always `int`. A decimal literal above 2^63-1 with no context is `uint` (`Q05_big_dec_noctx.amni`, `Q11_type_of_big.amni`).
3. LIT-STR-ML: blank or whitespace-only lines shorter than the closing indent are accepted and become empty lines (`T11_blank_mid.amni`, `X03_ml_blank_line.amni`). One-line `"""abc"""` is accepted (`X06_ml_oneline.amni`).
4. EXP-WORDS, EXP-UNARY, precedence row 3: `not` in `.he` is not a level-3 unary operator. Its operand is `pbin(3)`, so it takes comparisons, bitwise, shifts and arithmetic, and stops before `&&` (`Y01_not_prec.he`, `Y14_not_arith.he`, `Y03_not_and.he`). New rule EXP-NOT.
5. Grammar `global_decl`: `reusable` is not allowed at file scope (`G10_reusable_global.amni`). The grammar line is corrected.
6. Grammar `fn_decl` / `fn_mod`: `{ fn_mod }` in any order is wrong. The order is fixed by `pfn` (`G04_fnmods.amni`, `G16_inline_rec.amni`, `G20_export_inline.amni`, `O03`-`O07`). The EBNF is replaced.
7. `= "symbol"` rename (section 8.3): accepted only on extern declarations (`V07_extern_rename_so6.amni` works; `V02_extern_rename.amni` plain `fn` is rejected). Now CONFIRMED with that scope.
8. EXP-AS: "`as!` is the wrapping form" was incomplete. Release builds wrap for both forms. Under `--debug`, `as` traps and `as!` wraps (`AS1.amni`, `AS2.amni`, `AS3.amni`). The section 12 item is resolved.
9. EXP-CHAIN-HE: the chain test applies to every right operand, and accepts kinds 1 to 8 (strings, reals and bools included). A unary or compound operand breaks the chain (`Y04_chain_mid_neg.he`, `X11_chain_compound_last.he`, `Y11_chain_str_mid.he`).
10. DEC-THREAD: a `thread_fn` with parameters works when called directly (`X26_thread_arg.he`). Only `thread_spawn` needs a zero-parameter worker (`S33_he_thread.he`).
11. LEX-FILE-2: `''` in `.he` becomes an empty string, not an error (`X14_he_empty_char.he`).
12. LEX-FILE-3 / G8: a column-0 line inside a triple-quoted string also switches `.he` to Python mode, and the file then runs with no output and exit 0 (`Y13_ml_col0_trap.he`). G8 is extended.
13. Citation fixes: DEC-NAMESPACE cross-reference D-g changed to D-e; `as!` `fl` at `parse.he:408` (not 403); the amni flag is set at `lex.he:161`; the semicolon insert is `lex.he:187`; idc is `lex.he:55`; `rc` is `parse.he:375`.

Previously UNCONFIRMED or not probed, now CONFIRMED by my runs: LEX-FILE-4 BOM (`Z03_bom.amni`); decimal `1_000` rejected (`X05_dec_sep.amni`); struct trailing comma (`X24_struct_trailing_comma.amni`); `int(x)` / `real(x)` (`X16_he_intcall.he`); `[..n]` (`X21_arr_cap_amni.amni`); trailing commas in calls and parameters (`X28`-`X30`, `X27`); enum generics, parse and type-check (`Y08_enum_generic_nomatch.amni`); `int in` / `int upto` (`V03`, `V04`); qualified payload pattern rejected (`V01_qual_payload_pat.amni`); extern rename on a library block (`V07`).

New rules added: EXP-NOT, LAY-NO-CONT (`Z01_he_cont_plus.he`, `Z02_he_cont_dot.he`: no line continuation after a binary operator or `.` outside brackets), PAT-VARIANT-QUAL, PAT-QUAL-DOT, DEC-GLOBAL-REUSABLE, FN-MOD-ORDER, EXT-RENAME.

New known gaps: G11 (a bare `0x` is accepted as 0, `X02_hex_empty.amni`); G12 (`extern "m"` loads the linker script `libm.so` and fails at startup; `V06_extern_block_rename.amni`).

Still open: DIAG-3 remains UNCONFIRMED (the misleading `S18` message has a cause not yet isolated). LEX-FILE-5 memoization of `lut fn` in `.he` is not probed. Two findings are backend limits, not grammar: matching a generic enum (`X23_enum_generic.amni`) and `push` on `int[]` (`G08_growable.amni`).
