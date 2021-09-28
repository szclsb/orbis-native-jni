#include "../header/ch_szclsb_orbis_math_jni_JniVectorAPI.h"
#include <cstdlib>

JNIEXPORT void JNICALL Java_ch_szclsb_orbis_math_jni_JniVectorAPI_cAdd
  (JNIEnv *env, jclass c, jint size, jfloatArray r, jfloatArray a, jfloatArray b) {
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

JNIEXPORT void JNICALL Java_ch_szclsb_orbis_math_jni_JniVectorAPI_cSub
(JNIEnv *env, jclass c, jint size, jfloatArray r, jfloatArray a, jfloatArray b) {
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

JNIEXPORT void JNICALL Java_ch_szclsb_orbis_math_jni_JniVectorAPI_cMul__I_3F_3F_3F
(JNIEnv *env, jclass c, jint size, jfloatArray r, jfloatArray a, jfloatArray b) {
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

JNIEXPORT void JNICALL Java_ch_szclsb_orbis_math_jni_JniVectorAPI_cMul__I_3F_3FF
(JNIEnv *env, jclass c, jint size, jfloatArray r, jfloatArray a, jfloat s) {
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

JNIEXPORT jfloat JNICALL Java_ch_szclsb_orbis_math_jni_JniVectorAPI_cDot
        (JNIEnv *env, jclass c, jint size, jfloatArray a, jfloatArray b) {
    auto *a_ptr = env->GetFloatArrayElements(a, nullptr);
    auto *b_ptr = env->GetFloatArrayElements(b, nullptr);

    float *a_ptr_tmp = a_ptr;
    float *b_ptr_tmp = b_ptr;

    float result = 0.0;
    for (auto i = 0; i < size; i++) {
        result += (*a_ptr_tmp) * (*b_ptr_tmp);
        a_ptr_tmp++; b_ptr_tmp++;
    }

    env->ReleaseFloatArrayElements(a, a_ptr, 2);
    env->ReleaseFloatArrayElements(b, b_ptr, 2);
    return result;
}

JNIEXPORT jboolean JNICALL Java_ch_szclsb_orbis_math_jni_JniVectorAPI_cEquals
        (JNIEnv *env, jclass c, jint size, jfloatArray a, jfloatArray b, jfloat t) {
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