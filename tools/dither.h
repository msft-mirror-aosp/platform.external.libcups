/* Simple ordered dither threshold matrix */
const unsigned char threshold[64][64] =
{
  {   0, 235, 138,  22,  45,  98, 217,   2,  45,  98,   7, 185,  45,  97,   6, 192, 110,  37, 110,  37,  97,  45,  18, 148, 109,  37,  97,  45,   7, 185,  45,  97,   6, 192, 109,  37,  57,  82, 165,  12,  26, 130, 190,   6, 119,  31,  97,  45, 179,   8, 109,  37,  97,  45, 140,  22, 109,  37,  57,  82,   9, 177,  24, 135 },
  { 109,  37,  57,  82,  20, 143,  57,  82, 146,  19,  57,  82,  15, 158,  87,  53,  20, 144,  13, 162, 138,  22,  53,  87, 162,  13, 138,  22,  57,  82,  22, 140,  57,  82, 153,  16, 119,  31, 109,  37, 109,  37,  57,  81,  19, 147, 213,   2,  53,  87,  21, 142,  13, 164,  53,  87, 187,   6, 152,  17, 119,  32, 110,  37 },
  {  24, 135,  12, 167,  97,  45,  17, 151,  45,  97,  32, 119,  26, 130, 119,  32,  81,  58,  30, 121,  81,  58, 181,   8, 119,  32,  97,  45,  17, 151,  45,  97, 161,  14,  45,  97, 213,   2, 135,  24,   7, 183, 138,  22, 109,  37,  58,  81, 121,  30, 109,  37,  58,  81,  30, 121,  58,  81, 127,  27,  58,  81, 165,  12 },
  {  58,  81,  31, 119,   5, 197,  58,  81,   9, 175, 206,   3,  58,  81,  10, 174, 222,   1,  45,  97, 206,   3, 124,  29,  58,  81,   4, 200,  58,  81,   2, 217,  58,  81,  27, 127, 108,  37,  58,  81,  30, 121,  58,  81, 167,  12,  25, 132,  15, 158,   5, 197, 135,  24, 206,   3, 142,  21,  45,  97, 203,   3, 119,  32 },
  {   6, 190, 108,  38,  97,  45, 143,  20, 108,  38,  97,  45, 148,  18, 108,  38,  58,  81, 148,  18, 119,  32,  97,  45,  16, 153,  97,  45, 143,  20,  46,  97,  32, 119,   6, 187,  25, 132,  13, 164,  46,  97,   1, 222, 119,  32, 108,  38, 108,  38, 108,  38, 108,  38, 108,  38,  58,  81,   8, 179, 123,  29,  97,  46 },
  {  58,  81, 161,  14, 147,  19,  53,  87,  22, 138,  14, 159,  87,  53,  22, 138,  14, 159, 108,  38,  87,  53, 177,   9,  53,  87,  14, 161,  58,  81,  22, 137,  12, 167, 108,  38, 108,  38,  81,  58, 153,  16, 123,  29,  53,  87, 187,   6, 162,  13, 132,  25,  11, 168,  25, 132,  12, 165, 119,  32,  81,  58,  14, 161 },
  { 140,  22, 108,  38,  81,  58,   8, 181, 108,  38,  97,  46,   8, 181,  58,  81,  31, 119,   7, 185, 147,  19,  58,  81, 127,  27,  97,  46,   8, 179, 108,  38,  58,  81,  21, 142,  13, 162,   5, 194, 108,  38,  58,  81,  15, 156,  87,  53,  30, 121, 108,  38, 108,  38,  58,  81, 127,  27,  97,  46,  16, 153,  97,  46 },
  {  58,  81,   2, 217, 123,  29,  36, 111,   1, 227, 138,  22,  97,  46,   4, 203, 108,  38, 108,  38,  97,  46,  23, 137, 222,   1, 112,  36,  58,  81,   6, 192, 137,  23,  53,  87,  30, 121,  58,  80,  23, 137, 183,   7,  36, 111,  26, 130,  59,  80,   0, 235, 130,  26, 192,   6,  46,  97, 222,   1,  53,  87, 194,   5 },
  {  17, 151,  46,  97, 172,  10,  59,  80,  27, 127,  59,  80,  18, 148,  59,  80, 172,  10,  24, 135,   4, 200,  80,  59,  36, 112, 167,  12, 137,  23, 108,  38,  97,  46,   0, 235,  46,  97, 144,  20,  46,  97, 127,  27,  53,  87,   3, 206, 147,  19, 108,  38, 108,  38,  80,  59, 151,  17,  80,  59,  27, 127,  96,  46 },
  {  58,  81, 126,  27,  96,  46,  15, 156,  46,  97, 172,  10,  46,  96,  14, 159, 119,  32,  59,  80,  32, 119, 156,  15,  53,  87,  27, 127,  59,  80,  21, 142,  10, 172,  80,  59, 177,   9,  80,  59,   2, 213,  59,  80,  14, 161, 108,  38,  59,  79,  23, 137,  11, 168, 137,  23,  46,  96,  32, 119,  13, 164, 140,  22 },
  {   6, 190, 152,  17, 112,  36,  59,  79,   6, 187,  59,  79,  30, 121, 108,  38,  96,  46,  15, 156,  46,  96,  29, 123, 183,   7,  46,  96, 209,   3,  46,  96,  32, 118,  26, 130,  96,  46,  15, 158,  46,  96,  16, 153,  46,  96,  32, 118,  10, 172, 108,  38, 108,  38,  59,  79, 179,   8, 141,  21,  59,  79,  32, 119 },
  {  87,  53,  36, 112, 203,   4, 137,  23,  96,  46,  23, 137,   4, 200,  24, 135, 235,   0,  87,  53,   8, 179, 108,  38,  87,  53,  15, 156,  53,  87, 156,  15,  59,  79, 156,  15, 119,  32,  59,  79,  30, 121,  59,  79,   6, 190, 151,  17,  59,  79, 187,   6,  26, 130,   3, 206, 108,  38,  96,  46, 206,   3, 110,  37 },
  { 142,  21,  59,  79,  28, 126,  59,  79, 144,  20,  59,  79, 119,  32,  60,  79,  32, 118,  27, 129,  87,  53,   3, 209, 118,  32,  60,  79, 126,  28,  96,  46,   5, 194,  46,  96, 197,   5, 134,  24,   7, 183, 137,  23,  46,  96,  36, 112,  28, 126, 108,  38, 108,  38,  60,  79, 148,  18, 118,  32,  60,  79, 167,  12 },
  {  37, 109, 174,  10,  46,  95,  10, 174,  47,  95, 170,  11,  47,  95,   9, 177,  47,  95,  14, 159, 118,  32,  60,  79, 170,  11, 134,  24, 183,   7, 112,  36,  79,  60, 140,  22, 108,  38, 107,  38, 107,  39,  79,  60,  17, 149,  60,  79, 213,   2,  24, 135, 177,   9, 159,  14,  47,  95,   9, 175, 137,  23,  47,  95 },
  {   0, 235,  60,  79,  18, 149,  87,  53, 217,   2,  53,  87, 156,  15,  86,  53,  16, 153,  54,  86, 167,  12, 137,  23, 107,  39,  60,  79,  36, 112, 172,  10, 147,  19,  47,  95,  19, 147,   9, 175, 132,  25,   1, 227,  36, 110,   9, 175, 112,  36,  60,  79,  30, 121,  60,  79, 126,  28, 112,  36,  60,  79,  19, 147 },
  {  37, 109, 140,  22,  47,  95,  30, 121,  60,  78,  30, 121,  61,  78,  32, 118,  61,  78, 200,   4, 112,  36,  61,  78,  19, 147, 227,   1,  47,  95,  27, 129,  86,  54,   2, 217,  54,  86,  28, 126,  61,  78, 126,  28,  61,  78, 129,  26,  95,  47,  15, 158,  47,  95,  20, 144,   1, 222,  95,  47,   6, 190,  47,  95 },
  {  13, 164,  61,  78,   4, 200, 162,  13,  24, 134, 183,   7,  24, 134, 213,   2, 142,  21, 123,  29,  95,  47, 192,   6, 107,  39,  86,  54, 153,  16,  54,  86,  30, 121,  61,  78,  30, 121,  95,  47, 170,  11,  47,  95,  10, 172,  47,  94, 179,   8,  61,  78,   4, 200, 107,  39,  61,  78,  22, 140,  61,  78,  23, 137 },
  {  37, 109,  31, 120, 107,  39, 107,  39, 107,  39, 107,  39,  61,  78, 121,  30, 107,  39,  61,  78,  19, 146,  86,  54,  23, 137,  13, 164,  61,  77, 200,   4, 159,  14, 131,  25,  13, 164,   4, 200,  86,  54,  18, 148,  54,  86, 203,   4,  94,  47,  19, 146,  47,  94,  23, 137,  13, 161,  47,  94,  17, 151,  47,  94 },
  {  26, 131,   6, 187, 158,  15,  26, 131,   4, 203,  26, 131, 177,   9,  47,  94,  14, 159,  10, 174,  94,  47, 151,  17,  61,  77,  32, 118,  27, 129, 118,  32, 107,  39, 107,  39,  86,  54, 126,  28, 118,  32,  61,  77,  31, 120,  77,  61, 126,  28,  86,  54,  14, 161, 107,  39,  77,  61,   6, 190,  61,  77,   3, 206 },
  { 107,  39,  61,  77, 121,  30,  86,  54, 121,  30, 107,  39,  61,  77,  16, 153, 107,  39,  86,  54,   1, 222,  94,  47,   8, 179,  47,  94, 174,  10,  54,  86,  11, 168,   5, 194, 144,  20,  86,  54,  17, 152,   3, 209, 162,  13, 134,  24,  12, 167, 123,  29,  61,  77,   7, 185, 136,  23,  47,  94,  32, 118,  27, 127 },
  { 164,  13, 144,  20,  94,  47, 174,  10,  61,  77,  11, 170, 123,  29,  37, 110,   5, 194, 123,  29,  86,  54,  20, 143,  61,  77,   3, 206,  61,  77,  18, 148, 118,  32,  85,  54,  32, 118, 177,   9,  85,  55,  28, 126, 106,  39, 106,  39,  61,  77,   0, 235, 118,  32, 106,  39,  61,  77,  19, 147, 177,   9,  81,  58 },
  { 106,  39,  77,  61, 222,   1,  94,  47,  18, 149,  48,  93, 227,   1,  85,  55,  29, 123, 168,  11, 112,  36,  85,  55,  33, 117,  27, 129, 117,  33, 106,  39,  94,  47, 149,  18,  77,  61,  27, 129, 117,  33,  61,  77,  20, 144,   6, 190, 117,  33,  55,  85, 159,  14,  26, 131,   3, 209, 117,  32,  94,  47,  16, 153 },
  {   5, 194, 123,  29,  55,  85,  19, 146,  62,  77, 126,  28,  37, 110, 156,  15,  62,  77,  36, 112,  17, 151, 194,   5, 151,  17,  77,  62,  17, 152,   2, 217, 175,   9,  93,  47, 227,   0,  48,  93,   6, 192, 168,  11, 117,  33,  77,  62, 161,  14, 140,  22, 106,  39, 106,  39, 106,  39,  62,  77,  28, 126,  81,  58 },
  {  47,  94, 153,  16, 123,  29,  85,  55,   5, 197, 152,  17,  62,  77,  29, 123,  10, 174,  48,  93,  28, 126, 106,  39,  93,  48,   8, 181, 106,  39,  62,  77,  33, 117, 144,  20,  62,  77,  18, 148, 106,  39, 106,  39,  93,  48,  18, 147,  48,  93,  33, 117, 192,   6, 164,  13, 131,  26,  14, 158, 227,   1, 140,  22 },
  {  13, 164,  85,  55,  10, 174, 117,  33, 106,  39,  93,  48,  10, 172, 106,  39,  62,  77,   2, 209,  62,  77, 161,  14, 142,  21,  62,  77,  33, 117, 143,  20, 106,  39,  93,  48,  22, 138,  48,  93, 158,  15, 131,  26,   1, 217,  85,  55, 200,   4, 106,  39, 105,  39, 105,  40, 105,  40, 105,  40, 105,  40,  87,  53 },
  {  85,  55, 120,  31,  62,  77,   6, 187, 142,  21, 123,  29,  85,  55,   5, 194, 123,  29,  37, 110, 179,   8, 117,  33,  85,  55,  23, 136,   6, 192,  62,  77,  10, 174,   5, 197,  62,  77,   8, 179, 105,  40, 105,  40,  85,  55, 120,  31,  62,  77, 167,  12,  26, 131,  15, 158,   5, 194, 168,  11, 147,  19, 118,  32 },
  { 135,  24,   3, 209, 136,  23, 105,  40,  62,  76, 209,   3, 123,  29,  63,  76,  15, 155,  63,  76,  27, 129,  93,  48,   0, 235, 105,  40,  93,  48,  17, 151,  48,  93,  33, 116,  16, 155,  37, 110,   4, 203, 162,  13,  24, 134,  11, 168, 136,  23, 105,  40, 105,  40, 105,  40,  63,  76, 126,  28,  85,  55,   6, 190 },
  {  37, 109,  33, 117,  63,  76,  21, 142,  12, 165,  48,  93,  16, 155, 123,  29,  93,  48,  11, 170,  48,  93,  16, 155,  55,  85, 170,  11, 136,  23,  63,  76, 146,  19,  63,  76,  27, 129,  76,  63,  27, 129, 116,  33,  76,  63,  33, 117,  63,  76,  19, 147, 217,   2, 168,  11, 142,  21,  48,  93, 120,  31,  80,  59 },
  { 175,   9,  93,  49,  10, 172, 105,  40,  63,  76, 125,  28,  85,  55,   8, 179, 117,  33,  84,  55, 197,   5,  55,  84,  27, 129, 116,  33,  93,  49, 213,   2,  49,  93,  11, 170,  49,  93, 172,  10, 105,  40,  93,  49,   5, 194,  49,  93, 192,   6, 116,  33,  63,  76, 120,  31,  63,  76,   3, 206, 162,  13,  26, 131 },
  {  37, 109,  18, 149,  63,  76,   0, 235, 131,  26, 187,   6, 116,  33,  84,  55,   1, 222, 140,  22,  63,  76,  33, 116,   8, 179,  84,  55, 158,  15,  55,  84,  27, 129,  84,  55, 217,   2,  55,  84,  20, 144,  10, 174,  55,  84, 149,  18, 122,  29,  93,  49,  20, 143,  49,  93,  15, 158, 116,  33, 105,  40,  80,  59 },
  { 138,  22,  93,  49,  22, 138, 105,  40, 105,  40,  63,  76, 159,  14, 136,  23,  63,  75,  33, 116, 164,  13, 144,  20,  93,  49,   5, 194,  63,  75,  33, 116, 185,   7, 116,  33,  75,  63,  31, 120, 104,  40,  75,  63,  31, 120, 104,  41,  75,  63, 181,   8,  84,  55,   6, 192, 104,  41,  84,  55,  21, 142, 217,   2 },
  {  84,  55, 197,   5,  55,  84,  19, 146,  13, 164, 140,  22, 104,  41,  93,  49,  18, 149,  49,  93,  28, 125,  63,  75, 125,  28,  93,  49,  21, 141,  11, 168,  63,  75, 165,  12,  24, 134,  15, 158, 209,   3,  26, 131,  15, 158,   1, 227, 144,  20,  49,  93,  16, 153,  63,  75,  23, 136,  10, 172,  63,  75, 120,  30 },
  {  14, 161,  75,  63, 177,   8, 116,  33,  75,  63,  33, 116,   2, 213, 175,   9,  63,  75, 190,   6,  92,  49,   2, 213, 152,  17, 111,  36,  63,  75,  36, 112,  27, 129, 111,  36, 104,  41, 104,  41, 104,  41, 104,  41, 104,  41, 104,  41,  75,  63, 125,  28,  92,  49,  14, 161, 104,  41,  92,  49,   7, 185,  49,  92 },
  {  47,  94, 144,  20, 122,  30,  92,  49,   5, 197,  49,  92,  28, 125,  92,  49, 143,  20,  49,  92,  18, 149,  75,  63,  36, 112,  11, 168, 222,   1,  49,  92, 203,   4,  55,  84, 190,   6, 162,  13,  26, 130, 190,   6, 164,  13,  26, 130,  13, 162, 206,   3, 122,  30,  84,  55,   0, 235, 122,  30,  84,  55,  16, 152 },
  {   6, 192, 116,  33,  75,  63,  16, 155,  63,  74,  15, 156,  64,  74,  20, 143,  84,  55,  22, 138,  92,  49, 143,  20,  49,  92,  27, 129,  55,  84, 156,  15,  56,  84,  16, 155, 116,  33, 104,  41, 104,  41, 104,  41, 104,  41, 104,  41, 103,  41,  64,  74, 181,   8, 115,  33,  64,  74, 152,  17, 122,  30,  80,  59 },
  { 103,  41,  92,  49, 213,   2,  49,  92,  28, 125,  92,  49,   6, 185,  92,  49,   3, 206,  64,  74,   7, 185,  64,  74, 190,   6,  64,  74,  31, 120,  64,  74,  33, 117, 103,  41,  64,  74,  20, 144,   8, 181,  24, 134,  15, 158,   5, 197, 141,  21, 122,  30,  56,  84,  19, 146,  13, 164,  50,  91, 203,   4, 112,  36 },
  {  24, 134,  12, 167,  56,  84,  34, 115, 172,  10, 136,  23,  64,  74,  18, 149,  92,  49,  18, 149,  91,  49,  15, 156,  50,  91,  20, 144,   7, 183,  24, 134, 183,   7,  24, 134, 235,   0,  50,  91,  31, 120,  64,  74, 125,  28, 115,  34,  64,  74, 161,  14, 115,  34, 103,  41,  64,  74, 125,  28,  37, 110, 165,  12 },
  { 103,  41,  64,  74,  23, 136, 185,   7, 103,  41,  91,  50,  20, 143,  50,  91,  22, 138,  56,  84,  31, 120,  64,  74,  31, 120, 103,  41, 103,  41,  64,  74,  31, 120, 103,  41,  64,  74, 125,  28,  91,  50, 217,   2, 103,  41,  91,  50,  10, 174,  50,  91,  22, 140, 200,   4, 134,  24,   7, 183,  65,  74,  28, 126 },
  { 227,   1, 146,  19, 103,  41,  65,  74,  21, 142, 227,   1,  65,  74,   6, 190,  65,  74,   9, 175,   0, 235,  24, 134, 206,   3, 162,  13, 130,  26, 213,   2,  50,  91,  13, 162, 131,  26, 185,   7, 152,  17,  65,  74, 170,  11, 144,  20,  56,  84,   1, 222, 103,  41, 103,  41, 103,  41,  91,  50, 175,   9,  50,  91 },
  {  49,  93,  33, 116,   6, 187, 136,  23,  50,  91,  33, 116,  18, 149,  50,  91,  19, 147, 103,  41, 103,  41, 102,  41, 102,  42, 102,  42, 102,  42,  65,  74,  21, 141, 102,  42, 102,  42,  65,  74, 125,  28, 115,  34, 102,  42,  65,  74,  31, 119,  65,  74, 167,  12,  26, 130,  12, 165, 115,  34,  84,  56, 151,  17 },
  { 148,  18, 102,  42, 102,  42,  84,  56, 174,  10, 102,  42,  65,  74,  22, 140,  65,  74, 159,  14, 131,  26,  11, 168,  26, 131,  15, 158,   7, 185, 159,  14,  50,  91,   5, 197, 168,  11, 141,  21,  50,  91, 179,   8,  24, 134,   4, 203, 162,  13, 142,  21, 102,  42, 102,  42,  65,  74,   2, 217, 140,  22,  80,  59 },
  {  49,  92,   9, 175,  24, 133,   3, 209,  65,  74,  19, 146, 185,   7,  90,  50,   3, 209, 102,  42,  65,  74,  31, 120, 102,  42,  65,  74,  31, 120,  65,  73,  34, 115,  27, 129, 115,  34,  56,  84, 203,   4, 111,  36,  65,  73, 125,  28, 102,  42,  65,  73,  23, 136, 192,   6, 136,  23, 102,  42,  90,  50,   6, 187 },
  {  31, 119, 102,  42, 102,  42,  90,  50, 138,  22, 102,  42,  65,  73, 125,  28,  65,  73,  21, 141, 194,   5,  50,  90, 192,   6, 141,  21,  50,  90,  21, 141,   6, 187, 102,  42,  65,  73,  16, 155, 122,  30,  90,  50,  14, 161,  50,  90,  34, 115, 200,   4, 102,  42, 102,  42,  84,  56,  18, 149, 115,  34,  79,  59 },
  { 209,   3,  25, 133,   6, 187, 146,  19,  65,  73, 203,   4, 134,  24,  11, 168, 111,  36, 102,  42,  65,  73,  19, 147, 102,  42,  65,  73,   1, 227, 102,  42,  65,  73,  19, 146, 217,   2, 115,  34,  56,  84,  17, 152,  73,  65, 177,   9, 151,  17,  73,  65, 165,  12, 131,  26, 175,   9,  73,  65,   9, 174,  24, 134 },
  {  33, 117, 102,  42,  65,  73,  34, 115,  11, 170, 115,  34,  65,  73,  36, 111, 181,   7, 168,  11, 136,  23,  50,  90, 161,  14, 146,  19,  50,  90, 159,  14, 136,  23, 102,  42, 102,  42,  73,  65,   7, 183,  90,  50,   1, 227,  50,  90,  36, 111,  27, 129, 115,  34,  72,  65,  34, 115,  27, 127, 111,  36,  79,  59 },
  {  50,  90, 164,  13, 141,  21, 102,  42, 102,  42,  90,  50,  15, 156,  50,  90,  27, 127, 115,  34,  66,  72,   2, 217, 102,  42,  66,  72,  22, 138, 102,  42,  66,  72, 167,  12, 133,  25,  12, 165,  37, 110,  28, 125,  72,  66, 143,  20,  72,  66, 179,   8,  90,  50, 235,   0,  51,  90, 203,   4,  90,  50,   7, 183 },
  {  17, 152, 101,  42,  66,  72, 235,   0,  25, 133,   8, 181,  66,  72, 222,   1, 101,  43,  90,  50,  17, 152,  51,  90,  23, 136, 185,   7,  51,  90,   9, 175, 203,   4, 114,  34,  72,  66, 125,  28,  72,  66, 172,  10, 146,  19,  90,  51, 209,   3,  51,  90, 153,  16,  56,  84,  16, 155,  56,  84,  16, 155,  87,  53 },
  {  84,  56,   6, 192, 151,  17, 114,  35,  72,  66,  35, 114,  27, 127,  37, 110,  17, 152, 197,   5,  84,  56,  14, 161, 101,  43,  72,  66,  18, 149,  72,  66, 125,  28,  90,  51, 190,   6,  51,  90,   3, 206,  51,  90,  35, 114,  11, 170,  66,  72, 159,  14,  66,  72,  28, 125,  66,  72,  31, 119,  66,  72, 127,  27 },
  { 111,  36,  66,  72, 124,  28,  90,  51,  16, 155,  51,  90,  16, 155,  66,  72,  29, 124,  66,  72, 124,  29,  66,  72,   5, 192, 136,  23,  51,  90, 144,  19,  51,  90, 149,  18,  56,  83,  18, 149,  66,  72, 142,  20, 101,  43,  84,  56,  31, 119,  83,  56,  35, 114, 170,  10,  25, 133, 183,   7, 133,  25,   1, 222 },
  { 172,  10, 141,  21,  51,  90, 170,  11,  83,  56,   4, 200,  89,  51,  11, 170,  52,  89,  21, 141, 183,   7, 114,  35, 101,  43,  66,  72,   2, 213,  66,  72,   8, 179,  66,  72,  22, 140,  52,  89, 147,  19,  52,  89, 203,   4, 133,  25,   8, 181,  25, 133,   4, 200, 101,  43,  66,  72, 114,  35,  83,  56,  36, 111 },
  {  28, 126,  66,  72,   3, 206,  37, 110,  29, 124,  72,  66,  31, 119,  71,  66,   4, 203, 101,  43,  67,  71, 167,  12,  25, 133,  12, 165,  52,  89,  29, 124,  89,  52,   0, 235,  52,  89, 177,   9,  56,  83,  11, 170, 114,  35,  67,  71,  35, 114, 101,  43,  67,  71,  35, 114,   2, 213,  52,  89, 177,   9,  79,  59 },
  {  51,  90,  15, 156, 122,  30,  67,  71,   8, 181, 133,  25, 185,   7, 141,  21,  52,  89,  16, 155, 114,  35, 101,  43, 101,  43,  67,  71,  36, 111, 165,  12, 136,  23,  56,  83,  31, 119,  67,  71,  35, 114, 127,  27,  89,  52,  15, 156,  52,  89, 167,  12, 133,  25,  12, 165,  83,  56,  16, 155,  89,  52,  15, 156 },
  {   6, 192, 101,  43,  89,  52, 148,  18, 101,  43, 101,  43, 101,  43,  67,  71, 124,  29,  67,  71,   0, 235,  25, 133, 200,   4, 133,  25, 183,   7, 101,  43,  67,  71,  19, 146, 187,   6, 133,  25, 217,   2,  67,  71,   8, 181,  67,  71,   1, 222, 114,  35, 101,  43,  67,  71,  31, 119,  67,  71,  31, 119,  79,  59 },
  {  51,  90,  23, 135,  10, 172,  67,  71,  24, 135, 222,   1,  26, 130,  15, 158,  10, 174, 114,  35, 100,  43,  67,  71,  31, 119,  67,  70,  35, 114,  21, 141,   5, 194, 114,  35, 100,  43, 100,  43,  89,  52,  16, 155,  52,  89,  27, 127, 122,  30,  56,  83, 197,   5, 132,  25,   8, 181,  25, 133, 206,   3, 137,  23 },
  {  18, 149, 100,  43,  89,  52, 194,   5, 100,  43, 100,  43, 100,  43, 100,  43,  68,  70,   7, 185,  26, 131, 175,   9,  52,  88,  11, 170, 100,  43, 100,  43, 100,  43,  68,  70,  21, 141,  12, 165, 111,  36,  68,  70,  35, 113,  16, 155,  56,  83,  16, 155, 113,  35,  68,  70,  35, 113,  68,  70, 113,  35,  79,  59 },
  {  52,  88, 227,   1, 135,  24,  68,  70, 167,  12,  26, 130,  13, 162, 209,   3, 135,  24, 100,  43, 100,  43,  83,  56,  18, 148,  56,  83,   1, 222, 162,  13, 132,  25,  12, 167,  52,  88,  35, 113,   7, 183,  25, 133,   4, 203,  56,  83, 175,   9, 122,  30,  88,  52,  15, 156,  52,  88, 168,  11,  52,  88, 181,   8 },
  {  27, 129, 113,  35,  88,  52,  20, 143, 100,  43, 100,  43, 100,  43,  99,  43,  68,  70,  19, 146,   5, 194, 113,  35,  68,  70,  35, 113,  29, 124,  99,  44,  99,  44,  68,  70,   2, 213,  68,  70,  29, 124,  99,  44,  68,  70,  31, 119,  99,  44,  70,  68, 177,   9,  70,  68, 227,   1,  83,  56,  16, 153,  56,  83 },
  { 170,  11,  70,  68,  10, 174,  68,  70,  19, 146, 197,   5, 158,  15, 130,  26, 175,   9, 113,  35,  56,  83,  21, 140,   3, 209, 152,  17,  56,  83,  21, 141,   4, 197, 122,  30,  88,  52,  16, 153,  52,  88, 165,  12, 132,  25, 183,   7,  25, 132, 213,   2,  88,  52, 143,  20,  52,  88, 119,  31,  68,  70,  32, 118 },
  {  88,  52,  19, 147,  88,  52, 213,   2,  99,  44,  99,  44,  99,  44,  99,  44,  99,  44,  68,  70, 161,  14, 111,  36,  99,  44,  68,  70,   7, 183,  99,  44,  70,  68,  16, 153, 122,  30,  70,  68,   5, 197, 113,  35,  68,  70,  35, 113,  68,  70,  35, 113,  29, 124,  68,  70,  24, 135, 187,   6,  25, 132,   3, 209 },
  {  31, 119,  70,  68, 124,  29,  82,  57,  21, 141,  13, 164, 132,  25, 187,   6,  25, 132, 217,   2, 122,  30,  70,  68,  18, 148, 122,  30,  37, 110,  16, 153, 122,  30,  56,  82,  10, 172, 113,  35,  99,  44,  88,  52,   0, 235,  52,  88,  14, 159,  52,  88,  17, 152,   5, 194,  99,  44,  99,  44,  99,  44,  79,  60 },
  {  13, 162, 200,   4, 167,  11, 111,  36,  68,  70, 119,  31,  68,  70, 119,  31,  98,  44,  98,  45,  87,  52,   6, 190,  53,  87,   9, 177,  57,  82,  30, 122,   8, 179, 113,  35,  69,  68,   7, 185, 132,  25,  12, 164,  57,  82,  17, 152,  69,  69, 177,   9,  69,  69,  35, 113, 165,  12,  26, 130,  11, 168, 132,  25 },
  {  37, 109,  69,  69,  36, 111,  17, 151, 190,   6,  53,  87,   1, 227,  53,  87,  10, 174, 130,  26,  14, 159,  69,  69,  20, 143,  69,  69, 206,   3,  98,  45,  69,  69,   1, 227, 142,  21,  98,  45,  98,  45,  69,  69, 124,  29,  37, 110,   5, 197,  87,  53,  20, 143,  53,  87,  29, 124,  98,  45,  98,  45,  79,  60 },
  {  26, 130,  14, 159,  53,  87,  29, 124,  82,  57,  18, 148,  82,  57,  18, 148,  98,  45,  98,  45,  87,  53, 138,  22,  53,  87, 124,  29,  37, 110, 165,  12, 142,  21,  98,  45,  69,  69,  24, 135,   3, 209, 132,  25, 181,   8,  82,  57,  27, 127, 113,  35,  82,  57, 177,   9,  57,  82, 213,   2,  25, 132,   6, 187 },
  {  37, 109,  61,  78,   8, 179,  61,  78,  20, 143,  66,  72,  22, 138,  66,  72,  24, 135,   4, 200, 175,   9,  72,  66,   1, 227, 151,  17,  72,  66,  29, 124,  68,  70,  24, 135, 181,   8,  98,  45,  98,  45,  98,  45,  68,  70,  18, 148,  70,  68,  17, 151, 222,   1,  70,  68,  18, 148, 112,  35,  98,  45,  78,  61 }
};
