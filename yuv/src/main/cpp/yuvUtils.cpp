//
// Created by MOMO on 2023/11/1.
//

#include "yuvUtils.h"

/**
 * 分离YUV420P像素数据中的Y、U、V分量
 * 调用 simplest_yuv420_split("lena_256x256_yuv420p.yuv",256,256,1);
 * @param url
 * @param w
 * @param h
 * @param num
 * @return
 */
int yuvUtils::simplest_yuv420_split(char *url, int w, int h, int num) {
    FILE *fp=fopen(url,"rb+");
    FILE *fp1=fopen("output_420_y.y","wb+");
    FILE *fp2=fopen("output_420_u.y","wb+");
    FILE *fp3=fopen("output_420_v.y","wb+");

    unsigned char *pic = (unsigned char *) malloc(w * h * 3 / 2);
    for (int i = 0; i < num; ++i) {
        fread(pic, 1, w * h * 3 / 2, fp);
        //Y
        fwrite(pic,1,w*h,fp1);
        //U
        fwrite(pic+w*h,1,w*h/4,fp2);
        //V
        fwrite(pic+w*h*5/4,1,w*h/4,fp3);
    }

    free(pic);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}

/**
 * 分离YUV444P像素数据中的Y、U、V分量
 * simplest_yuv444_split("lena_256x256_yuv444p.yuv",256,256,1);
 * @param url
 * @param w
 * @param h
 * @param num
 * @return
 */
int yuvUtils::simplest_yuv444_split(char *url, int w, int h, int num) {
    FILE *fp=fopen(url,"rb+");
    FILE *fp1=fopen("output_444_y.y","wb+");
    FILE *fp2=fopen("output_444_u.y","wb+");
    FILE *fp3=fopen("output_444_v.y","wb+");

    unsigned char *pic = (unsigned char *) malloc(w * h * 3);

    for (int i = 0; i < num; ++i) {
        fread(pic, 1, w * h * 3, fp);
        //Y
        fwrite(pic, 1, w * h, fp1);
        //U
        fwrite(pic + w * h, 1, w * h, fp2);
        //V
        fwrite(pic + w * h * 2, 1, w * h, fp3);
    }

    free(pic);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}