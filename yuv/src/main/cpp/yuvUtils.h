//
// Created by MOMO on 2023/11/1.
//

#include <jni.h>
#include <string.h>
#include <iostream>
#include <filesystem>

#ifndef VIDEOARRAY_YUVUTILS_H
#define VIDEOARRAY_YUVUTILS_H


class yuvUtils {

public:
    static int simplest_yuv420_split(char *url, int w, int h, int num);
    static int simplest_yuv444_split(char *url, int w, int h, int num);



};


#endif //VIDEOARRAY_YUVUTILS_H
