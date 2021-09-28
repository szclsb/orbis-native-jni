#include "../header/ch_szclsb_orbis_math_jni_Matrix4f.h"
#include <cstdlib>

size_t size = 16;

JNIEXPORT jboolean JNICALL Java_ch_szclsb_orbis_math_jni_Matrix4f_cEqualsC
  (JNIEnv *env, jclass c, jfloatArray a, jfloatArray b, jfloat t) {
    auto *a_ptr = env->GetFloatArrayElements(a, nullptr);
    auto *b_ptr = env->GetFloatArrayElements(b, nullptr);

    float *a_ptr_tmp = a_ptr;
    float *b_ptr_tmp = b_ptr;
    auto check = true;
    for(auto i = 0; check && i < size; i++) {
        check = abs((*a_ptr_tmp) - (*b_ptr_tmp)) < t;
        a_ptr_tmp++; b_ptr_tmp++;
    }

    env->ReleaseFloatArrayElements(a, a_ptr, 2);
    env->ReleaseFloatArrayElements(b, b_ptr, 2);
    return check;
}


JNIEXPORT void JNICALL Java_ch_szclsb_orbis_math_jni_Matrix4f_cAdd
  (JNIEnv *env, jclass c, jfloatArray a, jfloatArray b, jfloatArray r) {
    auto *a_ptr = env->GetFloatArrayElements(a, nullptr);
    auto *b_ptr = env->GetFloatArrayElements(b, nullptr);
    auto *r_ptr = env->GetFloatArrayElements(r, nullptr);

    float *a_ptr_tmp = a_ptr;
    float *b_ptr_tmp = b_ptr;
    float *r_ptr_tmp = r_ptr;

    for (auto i = 0; i < size; i++) {
        *r_ptr_tmp = (*a_ptr_tmp) + (*b_ptr_tmp);
        a_ptr_tmp++; b_ptr_tmp++; r_ptr_tmp++;
    }

    env->ReleaseFloatArrayElements(a, a_ptr, 2);
    env->ReleaseFloatArrayElements(b, b_ptr, 2);
    env->ReleaseFloatArrayElements(r, r_ptr, 0);
}


JNIEXPORT void JNICALL Java_ch_szclsb_orbis_math_jni_Matrix4f_cSub
  (JNIEnv *env, jclass c, jfloatArray a, jfloatArray b, jfloatArray r) {
    auto *a_ptr = env->GetFloatArrayElements(a, nullptr);
    auto *b_ptr = env->GetFloatArrayElements(b, nullptr);
    auto *r_ptr = env->GetFloatArrayElements(r, nullptr);

    float *a_ptr_tmp = a_ptr;
    float *b_ptr_tmp = b_ptr;
    float *r_ptr_tmp = r_ptr;

    for (auto i = 0; i < size; i++) {
        *r_ptr_tmp = (*a_ptr_tmp) - (*b_ptr_tmp);
        a_ptr_tmp++; b_ptr_tmp++; r_ptr_tmp++;
    }

    env->ReleaseFloatArrayElements(a, a_ptr, 2);
    env->ReleaseFloatArrayElements(b, b_ptr, 2);
    env->ReleaseFloatArrayElements(r, r_ptr, 0);
}


JNIEXPORT void JNICALL Java_ch_szclsb_orbis_math_jni_Matrix4f_cMulElem
(JNIEnv *env, jclass c, jfloatArray a, jfloatArray b, jfloatArray r) {
    auto *a_ptr = env->GetFloatArrayElements(a, nullptr);
    auto *b_ptr = env->GetFloatArrayElements(b, nullptr);
    auto *r_ptr = env->GetFloatArrayElements(r, nullptr);

    float *a_ptr_tmp = a_ptr;
    float *b_ptr_tmp = b_ptr;
    float *r_ptr_tmp = r_ptr;

    for (auto i = 0; i < size; i++) {
        *r_ptr_tmp = (*a_ptr_tmp) * (*b_ptr_tmp);
        a_ptr_tmp++; b_ptr_tmp++; r_ptr_tmp++;
    }

    env->ReleaseFloatArrayElements(a, a_ptr, 2);
    env->ReleaseFloatArrayElements(b, b_ptr, 2);
    env->ReleaseFloatArrayElements(r, r_ptr, 0);
}


JNIEXPORT void JNICALL Java_ch_szclsb_orbis_math_jni_Matrix4f_cMul___3FF_3F
(JNIEnv *env, jclass c, jfloatArray a, jfloat s, jfloatArray r) {
    auto *a_ptr = env->GetFloatArrayElements(a, nullptr);
    auto *r_ptr = env->GetFloatArrayElements(r, nullptr);

    float *a_ptr_tmp = a_ptr;
    float *r_ptr_tmp = r_ptr;

    for (auto i = 0; i < size; i++) {
        *r_ptr_tmp = (*a_ptr_tmp) * s;
        a_ptr_tmp++; r_ptr_tmp++;
    }

    env->ReleaseFloatArrayElements(a, a_ptr, 2);
    env->ReleaseFloatArrayElements(r, r_ptr, 0);
}


JNIEXPORT void JNICALL Java_ch_szclsb_orbis_math_jni_Matrix4f_cMul___3F_3F_3F
  (JNIEnv *env, jclass c, jfloatArray a, jfloatArray b, jfloatArray r) {
    auto *a_ptr = env->GetFloatArrayElements(a, nullptr);
    auto *b_ptr = env->GetFloatArrayElements(b, nullptr);
    auto *r_ptr = env->GetFloatArrayElements(r, nullptr);

    float *a_ptr_tmp;
    float *b_ptr_tmp;
    float *tpr = r_ptr;
    float ij;
    for (auto i = 0; i < 4; i++) {
        for (auto j = 0; j < 4; j++) {
            a_ptr_tmp = a_ptr + i * 4;
            b_ptr_tmp = b_ptr + j;
            ij = 0;
            for (auto k = 0; k < 4; k++) {
                ij += (*a_ptr_tmp) * (*b_ptr_tmp);
                a_ptr_tmp += 1;
                b_ptr_tmp += 4;
            }
            *tpr = ij;
            tpr++;
        }
    }

    env->ReleaseFloatArrayElements(a, a_ptr, 2);
    env->ReleaseFloatArrayElements(b, b_ptr, 2);
    env->ReleaseFloatArrayElements(r, r_ptr, 0);
}
