import sys, numpy as np
from PIL import ImageFont
f = ImageFont.truetype(sys.argv[1], 96)
for cp in range(33, 127):
    m = f.getmask(chr(cp), mode='L'); print(cp, int(np.asarray(m, dtype=np.int64).sum()))
