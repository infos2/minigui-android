#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int gbk_index (unsigned short encoding)
{
    unsigned char ch1, ch2;

    ch1 = encoding >> 8;
    ch2 = (unsigned char)encoding;

    if (ch2 > 0x7F)
        return (ch1 - 0x81) * 190 + (ch2 - 0x41);
    else
        return (ch1 - 0x81) * 190 + (ch2 - 0x40);
}

static struct _font_info {
    char name [256];
    int def_char;
    int pixel;
    int ascent;
    int descent;
    int nr_chars;
} font_info;

typedef struct _glyph {
    int encoding;
    int dwidth;
    int bbw;
    int bbh;
    int bbx;
    int bby;
    unsigned char bitmap [72];
} glyph_t;

int main (int argc, char* argv[])
{
    FILE* fp;
    int i;
    int width, height;
    int bmp_pitch, bmp_size, bmp_pos;

    if (argc < 2) {
        printf ("usage: ./makegbkrbf <rbfname> < <dumpedbdf.txt>\n");
        return 1;
    }

    scanf ("%s\n", font_info.name);
    scanf ("%d\n", &font_info.def_char);
    scanf ("%d\n", &font_info.pixel);
    scanf ("%d\n", &font_info.ascent);
    scanf ("%d\n", &font_info.descent);
    scanf ("%d\n", &font_info.nr_chars);

    width = font_info.pixel;
    height = font_info.ascent + font_info.descent;
    bmp_pitch = (width + 7)/8;
    bmp_size = bmp_pitch * height;

    if ((fp = fopen (argv[1], "w+")) == NULL)
        return 1;

    printf ("font: %s (%dx%d)\n", font_info.name, width, height);

    fseek (fp, (0xFF - 0x80) * 190 * bmp_size - 1, SEEK_SET);
    fwrite (" ", 1, 1, fp);

    for (i = 0; i < font_info.nr_chars; i++) {
        glyph_t glyph;
        int n, j, k, skip_lines, skip_bytes;
        int bb_pitch;
        unsigned char bb_bmp [72];
        unsigned int bb_lines [24];

        scanf ("%d\n", &glyph.encoding);
        scanf ("%d\n", &glyph.dwidth);
        scanf ("%d\n", &glyph.bbw);
        scanf ("%d\n", &glyph.bbh);
        scanf ("%d\n", &glyph.bbx);
        scanf ("%d\n", &glyph.bby);

        printf ("enconding: %d (%d, %d, %d, %d)\n", 
                        glyph.encoding, glyph.bbw, glyph.bbh, glyph.bbx, glyph.bby);
        
        bb_pitch = (glyph.bbw + 7)/8;
        n = bb_pitch * glyph.bbh;

        /* read bounding box bitmap */
        for (j = 0; j < n; j++) {
            int tmp;
            scanf ("%d\n", &tmp);
            bb_bmp [j] = (unsigned char)tmp;
        }

        for (j = 0; j < glyph.bbh; j++) {
            bb_lines [j] = 0;
            for (k = 0; k < bb_pitch; k++)
                bb_lines [j] |= bb_bmp [j*bb_pitch + k] << ((bb_pitch - k - 1) * 8);

            bb_lines [j] <<= (bmp_pitch - bb_pitch) * 8;
            bb_lines [j] >>= glyph.bbx;
        }

        skip_lines = height - (glyph.bbh + glyph.bby) - font_info.descent;
        skip_bytes = skip_lines * bmp_pitch;

        memset (glyph.bitmap, 0, 72);
        for (j = 0; j < glyph.bbh; j++) {
            unsigned char* bmp = &glyph.bitmap [skip_bytes + j*bmp_pitch];
            for (k = 0; k < bmp_pitch; k++)
                bmp [k] = (unsigned char)(bb_lines [j] >> ((bmp_pitch - k - 1) * 8));
        }

        bmp_pos = bmp_size * gbk_index (glyph.encoding);

        fseek (fp, bmp_pos, SEEK_SET);
        fwrite (glyph.bitmap, bmp_size, 1, fp);
    }

    fclose (fp);
    return 0;
}

