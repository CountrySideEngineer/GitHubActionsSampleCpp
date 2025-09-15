#pragma once
#ifndef CPP_DECL_BEGIN
#ifdef __cplusplus
#define CPP_DECL_BEGIN	extern "C" {
#define CPP_DECL_END	}
#else
#define CPP_DECL_BEGIN
#define CPP_DECL_END
#endif
#endif

#include <stdio.h>
#include <stdint.h>
