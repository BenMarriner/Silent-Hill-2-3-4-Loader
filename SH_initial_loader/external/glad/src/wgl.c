/**
 * SPDX-License-Identifier: (WTFPL OR CC0-1.0) AND Apache-2.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/wgl.h>

#ifndef GLAD_IMPL_UTIL_C_
#define GLAD_IMPL_UTIL_C_

#ifdef _MSC_VER
#define GLAD_IMPL_UTIL_SSCANF sscanf_s
#else
#define GLAD_IMPL_UTIL_SSCANF sscanf
#endif

#endif /* GLAD_IMPL_UTIL_C_ */

#ifdef __cplusplus
extern "C" {
#endif



int GLAD_WGL_VERSION_1_0 = 0;
int GLAD_WGL_ARB_extensions_string = 0;
int GLAD_WGL_ARB_pbuffer = 0;
int GLAD_WGL_ARB_pixel_format = 0;
int GLAD_WGL_ARB_pixel_format_float = 0;
int GLAD_WGL_ARB_render_texture = 0;
int GLAD_WGL_EXT_extensions_string = 0;
int GLAD_WGL_EXT_swap_control = 0;


static void _pre_call_wgl_callback_default(const char *name, GLADapiproc apiproc, int len_args, ...) {
    GLAD_UNUSED(name);
    GLAD_UNUSED(apiproc);
    GLAD_UNUSED(len_args);
}
static void _post_call_wgl_callback_default(void *ret, const char *name, GLADapiproc apiproc, int len_args, ...) {
    GLAD_UNUSED(ret);
    GLAD_UNUSED(name);
    GLAD_UNUSED(apiproc);
    GLAD_UNUSED(len_args);
}

static GLADprecallback _pre_call_wgl_callback = _pre_call_wgl_callback_default;
void gladSetWGLPreCallback(GLADprecallback cb) {
    _pre_call_wgl_callback = cb;
}
static GLADpostcallback _post_call_wgl_callback = _post_call_wgl_callback_default;
void gladSetWGLPostCallback(GLADpostcallback cb) {
    _post_call_wgl_callback = cb;
}

PFNWGLBINDTEXIMAGEARBPROC glad_wglBindTexImageARB = NULL;
static BOOL GLAD_API_PTR glad_debug_impl_wglBindTexImageARB(HPBUFFERARB hPbuffer, int iBuffer) {
    BOOL ret;
    _pre_call_wgl_callback("wglBindTexImageARB", (GLADapiproc) glad_wglBindTexImageARB, 2, hPbuffer, iBuffer);
    ret = glad_wglBindTexImageARB(hPbuffer, iBuffer);
    _post_call_wgl_callback((void*) &ret, "wglBindTexImageARB", (GLADapiproc) glad_wglBindTexImageARB, 2, hPbuffer, iBuffer);
    return ret;
}
PFNWGLBINDTEXIMAGEARBPROC glad_debug_wglBindTexImageARB = glad_debug_impl_wglBindTexImageARB;
PFNWGLCHOOSEPIXELFORMATARBPROC glad_wglChoosePixelFormatARB = NULL;
static BOOL GLAD_API_PTR glad_debug_impl_wglChoosePixelFormatARB(HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats) {
    BOOL ret;
    _pre_call_wgl_callback("wglChoosePixelFormatARB", (GLADapiproc) glad_wglChoosePixelFormatARB, 6, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
    ret = glad_wglChoosePixelFormatARB(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
    _post_call_wgl_callback((void*) &ret, "wglChoosePixelFormatARB", (GLADapiproc) glad_wglChoosePixelFormatARB, 6, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
    return ret;
}
PFNWGLCHOOSEPIXELFORMATARBPROC glad_debug_wglChoosePixelFormatARB = glad_debug_impl_wglChoosePixelFormatARB;
PFNWGLCREATEPBUFFERARBPROC glad_wglCreatePbufferARB = NULL;
static HPBUFFERARB GLAD_API_PTR glad_debug_impl_wglCreatePbufferARB(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList) {
    HPBUFFERARB ret;
    _pre_call_wgl_callback("wglCreatePbufferARB", (GLADapiproc) glad_wglCreatePbufferARB, 5, hDC, iPixelFormat, iWidth, iHeight, piAttribList);
    ret = glad_wglCreatePbufferARB(hDC, iPixelFormat, iWidth, iHeight, piAttribList);
    _post_call_wgl_callback((void*) &ret, "wglCreatePbufferARB", (GLADapiproc) glad_wglCreatePbufferARB, 5, hDC, iPixelFormat, iWidth, iHeight, piAttribList);
    return ret;
}
PFNWGLCREATEPBUFFERARBPROC glad_debug_wglCreatePbufferARB = glad_debug_impl_wglCreatePbufferARB;
PFNWGLDESTROYPBUFFERARBPROC glad_wglDestroyPbufferARB = NULL;
static BOOL GLAD_API_PTR glad_debug_impl_wglDestroyPbufferARB(HPBUFFERARB hPbuffer) {
    BOOL ret;
    _pre_call_wgl_callback("wglDestroyPbufferARB", (GLADapiproc) glad_wglDestroyPbufferARB, 1, hPbuffer);
    ret = glad_wglDestroyPbufferARB(hPbuffer);
    _post_call_wgl_callback((void*) &ret, "wglDestroyPbufferARB", (GLADapiproc) glad_wglDestroyPbufferARB, 1, hPbuffer);
    return ret;
}
PFNWGLDESTROYPBUFFERARBPROC glad_debug_wglDestroyPbufferARB = glad_debug_impl_wglDestroyPbufferARB;
PFNWGLGETEXTENSIONSSTRINGARBPROC glad_wglGetExtensionsStringARB = NULL;
static const char * GLAD_API_PTR glad_debug_impl_wglGetExtensionsStringARB(HDC hdc) {
    const char * ret;
    _pre_call_wgl_callback("wglGetExtensionsStringARB", (GLADapiproc) glad_wglGetExtensionsStringARB, 1, hdc);
    ret = glad_wglGetExtensionsStringARB(hdc);
    _post_call_wgl_callback((void*) &ret, "wglGetExtensionsStringARB", (GLADapiproc) glad_wglGetExtensionsStringARB, 1, hdc);
    return ret;
}
PFNWGLGETEXTENSIONSSTRINGARBPROC glad_debug_wglGetExtensionsStringARB = glad_debug_impl_wglGetExtensionsStringARB;
PFNWGLGETEXTENSIONSSTRINGEXTPROC glad_wglGetExtensionsStringEXT = NULL;
static const char * GLAD_API_PTR glad_debug_impl_wglGetExtensionsStringEXT(void) {
    const char * ret;
    _pre_call_wgl_callback("wglGetExtensionsStringEXT", (GLADapiproc) glad_wglGetExtensionsStringEXT, 0);
    ret = glad_wglGetExtensionsStringEXT();
    _post_call_wgl_callback((void*) &ret, "wglGetExtensionsStringEXT", (GLADapiproc) glad_wglGetExtensionsStringEXT, 0);
    return ret;
}
PFNWGLGETEXTENSIONSSTRINGEXTPROC glad_debug_wglGetExtensionsStringEXT = glad_debug_impl_wglGetExtensionsStringEXT;
PFNWGLGETPBUFFERDCARBPROC glad_wglGetPbufferDCARB = NULL;
static HDC GLAD_API_PTR glad_debug_impl_wglGetPbufferDCARB(HPBUFFERARB hPbuffer) {
    HDC ret;
    _pre_call_wgl_callback("wglGetPbufferDCARB", (GLADapiproc) glad_wglGetPbufferDCARB, 1, hPbuffer);
    ret = glad_wglGetPbufferDCARB(hPbuffer);
    _post_call_wgl_callback((void*) &ret, "wglGetPbufferDCARB", (GLADapiproc) glad_wglGetPbufferDCARB, 1, hPbuffer);
    return ret;
}
PFNWGLGETPBUFFERDCARBPROC glad_debug_wglGetPbufferDCARB = glad_debug_impl_wglGetPbufferDCARB;
PFNWGLGETPIXELFORMATATTRIBFVARBPROC glad_wglGetPixelFormatAttribfvARB = NULL;
static BOOL GLAD_API_PTR glad_debug_impl_wglGetPixelFormatAttribfvARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, FLOAT * pfValues) {
    BOOL ret;
    _pre_call_wgl_callback("wglGetPixelFormatAttribfvARB", (GLADapiproc) glad_wglGetPixelFormatAttribfvARB, 6, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
    ret = glad_wglGetPixelFormatAttribfvARB(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
    _post_call_wgl_callback((void*) &ret, "wglGetPixelFormatAttribfvARB", (GLADapiproc) glad_wglGetPixelFormatAttribfvARB, 6, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
    return ret;
}
PFNWGLGETPIXELFORMATATTRIBFVARBPROC glad_debug_wglGetPixelFormatAttribfvARB = glad_debug_impl_wglGetPixelFormatAttribfvARB;
PFNWGLGETPIXELFORMATATTRIBIVARBPROC glad_wglGetPixelFormatAttribivARB = NULL;
static BOOL GLAD_API_PTR glad_debug_impl_wglGetPixelFormatAttribivARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, int * piValues) {
    BOOL ret;
    _pre_call_wgl_callback("wglGetPixelFormatAttribivARB", (GLADapiproc) glad_wglGetPixelFormatAttribivARB, 6, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
    ret = glad_wglGetPixelFormatAttribivARB(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
    _post_call_wgl_callback((void*) &ret, "wglGetPixelFormatAttribivARB", (GLADapiproc) glad_wglGetPixelFormatAttribivARB, 6, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
    return ret;
}
PFNWGLGETPIXELFORMATATTRIBIVARBPROC glad_debug_wglGetPixelFormatAttribivARB = glad_debug_impl_wglGetPixelFormatAttribivARB;
PFNWGLGETSWAPINTERVALEXTPROC glad_wglGetSwapIntervalEXT = NULL;
static int GLAD_API_PTR glad_debug_impl_wglGetSwapIntervalEXT(void) {
    int ret;
    _pre_call_wgl_callback("wglGetSwapIntervalEXT", (GLADapiproc) glad_wglGetSwapIntervalEXT, 0);
    ret = glad_wglGetSwapIntervalEXT();
    _post_call_wgl_callback((void*) &ret, "wglGetSwapIntervalEXT", (GLADapiproc) glad_wglGetSwapIntervalEXT, 0);
    return ret;
}
PFNWGLGETSWAPINTERVALEXTPROC glad_debug_wglGetSwapIntervalEXT = glad_debug_impl_wglGetSwapIntervalEXT;
PFNWGLQUERYPBUFFERARBPROC glad_wglQueryPbufferARB = NULL;
static BOOL GLAD_API_PTR glad_debug_impl_wglQueryPbufferARB(HPBUFFERARB hPbuffer, int iAttribute, int * piValue) {
    BOOL ret;
    _pre_call_wgl_callback("wglQueryPbufferARB", (GLADapiproc) glad_wglQueryPbufferARB, 3, hPbuffer, iAttribute, piValue);
    ret = glad_wglQueryPbufferARB(hPbuffer, iAttribute, piValue);
    _post_call_wgl_callback((void*) &ret, "wglQueryPbufferARB", (GLADapiproc) glad_wglQueryPbufferARB, 3, hPbuffer, iAttribute, piValue);
    return ret;
}
PFNWGLQUERYPBUFFERARBPROC glad_debug_wglQueryPbufferARB = glad_debug_impl_wglQueryPbufferARB;
PFNWGLRELEASEPBUFFERDCARBPROC glad_wglReleasePbufferDCARB = NULL;
static int GLAD_API_PTR glad_debug_impl_wglReleasePbufferDCARB(HPBUFFERARB hPbuffer, HDC hDC) {
    int ret;
    _pre_call_wgl_callback("wglReleasePbufferDCARB", (GLADapiproc) glad_wglReleasePbufferDCARB, 2, hPbuffer, hDC);
    ret = glad_wglReleasePbufferDCARB(hPbuffer, hDC);
    _post_call_wgl_callback((void*) &ret, "wglReleasePbufferDCARB", (GLADapiproc) glad_wglReleasePbufferDCARB, 2, hPbuffer, hDC);
    return ret;
}
PFNWGLRELEASEPBUFFERDCARBPROC glad_debug_wglReleasePbufferDCARB = glad_debug_impl_wglReleasePbufferDCARB;
PFNWGLRELEASETEXIMAGEARBPROC glad_wglReleaseTexImageARB = NULL;
static BOOL GLAD_API_PTR glad_debug_impl_wglReleaseTexImageARB(HPBUFFERARB hPbuffer, int iBuffer) {
    BOOL ret;
    _pre_call_wgl_callback("wglReleaseTexImageARB", (GLADapiproc) glad_wglReleaseTexImageARB, 2, hPbuffer, iBuffer);
    ret = glad_wglReleaseTexImageARB(hPbuffer, iBuffer);
    _post_call_wgl_callback((void*) &ret, "wglReleaseTexImageARB", (GLADapiproc) glad_wglReleaseTexImageARB, 2, hPbuffer, iBuffer);
    return ret;
}
PFNWGLRELEASETEXIMAGEARBPROC glad_debug_wglReleaseTexImageARB = glad_debug_impl_wglReleaseTexImageARB;
PFNWGLSETPBUFFERATTRIBARBPROC glad_wglSetPbufferAttribARB = NULL;
static BOOL GLAD_API_PTR glad_debug_impl_wglSetPbufferAttribARB(HPBUFFERARB hPbuffer, const int * piAttribList) {
    BOOL ret;
    _pre_call_wgl_callback("wglSetPbufferAttribARB", (GLADapiproc) glad_wglSetPbufferAttribARB, 2, hPbuffer, piAttribList);
    ret = glad_wglSetPbufferAttribARB(hPbuffer, piAttribList);
    _post_call_wgl_callback((void*) &ret, "wglSetPbufferAttribARB", (GLADapiproc) glad_wglSetPbufferAttribARB, 2, hPbuffer, piAttribList);
    return ret;
}
PFNWGLSETPBUFFERATTRIBARBPROC glad_debug_wglSetPbufferAttribARB = glad_debug_impl_wglSetPbufferAttribARB;
PFNWGLSWAPINTERVALEXTPROC glad_wglSwapIntervalEXT = NULL;
static BOOL GLAD_API_PTR glad_debug_impl_wglSwapIntervalEXT(int interval) {
    BOOL ret;
    _pre_call_wgl_callback("wglSwapIntervalEXT", (GLADapiproc) glad_wglSwapIntervalEXT, 1, interval);
    ret = glad_wglSwapIntervalEXT(interval);
    _post_call_wgl_callback((void*) &ret, "wglSwapIntervalEXT", (GLADapiproc) glad_wglSwapIntervalEXT, 1, interval);
    return ret;
}
PFNWGLSWAPINTERVALEXTPROC glad_debug_wglSwapIntervalEXT = glad_debug_impl_wglSwapIntervalEXT;


static void glad_wgl_load_WGL_ARB_extensions_string(GLADuserptrloadfunc load, void *userptr) {
    if(!GLAD_WGL_ARB_extensions_string) return;
    glad_wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC) load(userptr, "wglGetExtensionsStringARB");
}
static void glad_wgl_load_WGL_ARB_pbuffer(GLADuserptrloadfunc load, void *userptr) {
    if(!GLAD_WGL_ARB_pbuffer) return;
    glad_wglCreatePbufferARB = (PFNWGLCREATEPBUFFERARBPROC) load(userptr, "wglCreatePbufferARB");
    glad_wglDestroyPbufferARB = (PFNWGLDESTROYPBUFFERARBPROC) load(userptr, "wglDestroyPbufferARB");
    glad_wglGetPbufferDCARB = (PFNWGLGETPBUFFERDCARBPROC) load(userptr, "wglGetPbufferDCARB");
    glad_wglQueryPbufferARB = (PFNWGLQUERYPBUFFERARBPROC) load(userptr, "wglQueryPbufferARB");
    glad_wglReleasePbufferDCARB = (PFNWGLRELEASEPBUFFERDCARBPROC) load(userptr, "wglReleasePbufferDCARB");
}
static void glad_wgl_load_WGL_ARB_pixel_format(GLADuserptrloadfunc load, void *userptr) {
    if(!GLAD_WGL_ARB_pixel_format) return;
    glad_wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC) load(userptr, "wglChoosePixelFormatARB");
    glad_wglGetPixelFormatAttribfvARB = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC) load(userptr, "wglGetPixelFormatAttribfvARB");
    glad_wglGetPixelFormatAttribivARB = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC) load(userptr, "wglGetPixelFormatAttribivARB");
}
static void glad_wgl_load_WGL_ARB_render_texture(GLADuserptrloadfunc load, void *userptr) {
    if(!GLAD_WGL_ARB_render_texture) return;
    glad_wglBindTexImageARB = (PFNWGLBINDTEXIMAGEARBPROC) load(userptr, "wglBindTexImageARB");
    glad_wglReleaseTexImageARB = (PFNWGLRELEASETEXIMAGEARBPROC) load(userptr, "wglReleaseTexImageARB");
    glad_wglSetPbufferAttribARB = (PFNWGLSETPBUFFERATTRIBARBPROC) load(userptr, "wglSetPbufferAttribARB");
}
static void glad_wgl_load_WGL_EXT_extensions_string(GLADuserptrloadfunc load, void *userptr) {
    if(!GLAD_WGL_EXT_extensions_string) return;
    glad_wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC) load(userptr, "wglGetExtensionsStringEXT");
}
static void glad_wgl_load_WGL_EXT_swap_control(GLADuserptrloadfunc load, void *userptr) {
    if(!GLAD_WGL_EXT_swap_control) return;
    glad_wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC) load(userptr, "wglGetSwapIntervalEXT");
    glad_wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC) load(userptr, "wglSwapIntervalEXT");
}


static void glad_wgl_resolve_aliases(void) {
}

static int glad_wgl_has_extension(HDC hdc, const char *ext) {
    const char *terminator;
    const char *loc;
    const char *extensions;

    if(wglGetExtensionsStringEXT == NULL && wglGetExtensionsStringARB == NULL)
        return 0;

    if(wglGetExtensionsStringARB == NULL || hdc == INVALID_HANDLE_VALUE)
        extensions = wglGetExtensionsStringEXT();
    else
        extensions = wglGetExtensionsStringARB(hdc);

    if(extensions == NULL || ext == NULL)
        return 0;

    while(1) {
        loc = strstr(extensions, ext);
        if(loc == NULL)
            break;

        terminator = loc + strlen(ext);
        if((loc == extensions || *(loc - 1) == ' ') &&
            (*terminator == ' ' || *terminator == '\0'))
        {
            return 1;
        }
        extensions = terminator;
    }

    return 0;
}

static GLADapiproc glad_wgl_get_proc_from_userptr(void *userptr, const char* name) {
    return (GLAD_GNUC_EXTENSION (GLADapiproc (*)(const char *name)) userptr)(name);
}

static int glad_wgl_find_extensions_wgl(HDC hdc) {
    GLAD_WGL_ARB_extensions_string = glad_wgl_has_extension(hdc, "WGL_ARB_extensions_string");
    GLAD_WGL_ARB_pbuffer = glad_wgl_has_extension(hdc, "WGL_ARB_pbuffer");
    GLAD_WGL_ARB_pixel_format = glad_wgl_has_extension(hdc, "WGL_ARB_pixel_format");
    GLAD_WGL_ARB_pixel_format_float = glad_wgl_has_extension(hdc, "WGL_ARB_pixel_format_float");
    GLAD_WGL_ARB_render_texture = glad_wgl_has_extension(hdc, "WGL_ARB_render_texture");
    GLAD_WGL_EXT_extensions_string = glad_wgl_has_extension(hdc, "WGL_EXT_extensions_string");
    GLAD_WGL_EXT_swap_control = glad_wgl_has_extension(hdc, "WGL_EXT_swap_control");
    return 1;
}

static int glad_wgl_find_core_wgl(void) {
    int major = 1, minor = 0;
    GLAD_WGL_VERSION_1_0 = (major == 1 && minor >= 0) || major > 1;
    return GLAD_MAKE_VERSION(major, minor);
}

int gladLoadWGLUserPtr(HDC hdc, GLADuserptrloadfunc load, void *userptr) {
    int version;
    wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC) load(userptr, "wglGetExtensionsStringARB");
    wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC) load(userptr, "wglGetExtensionsStringEXT");
    if(wglGetExtensionsStringARB == NULL && wglGetExtensionsStringEXT == NULL) return 0;
    version = glad_wgl_find_core_wgl();


    if (!glad_wgl_find_extensions_wgl(hdc)) return 0;
    glad_wgl_load_WGL_ARB_extensions_string(load, userptr);
    glad_wgl_load_WGL_ARB_pbuffer(load, userptr);
    glad_wgl_load_WGL_ARB_pixel_format(load, userptr);
    glad_wgl_load_WGL_ARB_render_texture(load, userptr);
    glad_wgl_load_WGL_EXT_extensions_string(load, userptr);
    glad_wgl_load_WGL_EXT_swap_control(load, userptr);

    glad_wgl_resolve_aliases();

    return version;
}

int gladLoadWGL(HDC hdc, GLADloadfunc load) {
    return gladLoadWGLUserPtr(hdc, glad_wgl_get_proc_from_userptr, GLAD_GNUC_EXTENSION (void*) load);
}
 
void gladInstallWGLDebug(void) {
    glad_debug_wglBindTexImageARB = glad_debug_impl_wglBindTexImageARB;
    glad_debug_wglChoosePixelFormatARB = glad_debug_impl_wglChoosePixelFormatARB;
    glad_debug_wglCreatePbufferARB = glad_debug_impl_wglCreatePbufferARB;
    glad_debug_wglDestroyPbufferARB = glad_debug_impl_wglDestroyPbufferARB;
    glad_debug_wglGetExtensionsStringARB = glad_debug_impl_wglGetExtensionsStringARB;
    glad_debug_wglGetExtensionsStringEXT = glad_debug_impl_wglGetExtensionsStringEXT;
    glad_debug_wglGetPbufferDCARB = glad_debug_impl_wglGetPbufferDCARB;
    glad_debug_wglGetPixelFormatAttribfvARB = glad_debug_impl_wglGetPixelFormatAttribfvARB;
    glad_debug_wglGetPixelFormatAttribivARB = glad_debug_impl_wglGetPixelFormatAttribivARB;
    glad_debug_wglGetSwapIntervalEXT = glad_debug_impl_wglGetSwapIntervalEXT;
    glad_debug_wglQueryPbufferARB = glad_debug_impl_wglQueryPbufferARB;
    glad_debug_wglReleasePbufferDCARB = glad_debug_impl_wglReleasePbufferDCARB;
    glad_debug_wglReleaseTexImageARB = glad_debug_impl_wglReleaseTexImageARB;
    glad_debug_wglSetPbufferAttribARB = glad_debug_impl_wglSetPbufferAttribARB;
    glad_debug_wglSwapIntervalEXT = glad_debug_impl_wglSwapIntervalEXT;
}

void gladUninstallWGLDebug(void) {
    glad_debug_wglBindTexImageARB = glad_wglBindTexImageARB;
    glad_debug_wglChoosePixelFormatARB = glad_wglChoosePixelFormatARB;
    glad_debug_wglCreatePbufferARB = glad_wglCreatePbufferARB;
    glad_debug_wglDestroyPbufferARB = glad_wglDestroyPbufferARB;
    glad_debug_wglGetExtensionsStringARB = glad_wglGetExtensionsStringARB;
    glad_debug_wglGetExtensionsStringEXT = glad_wglGetExtensionsStringEXT;
    glad_debug_wglGetPbufferDCARB = glad_wglGetPbufferDCARB;
    glad_debug_wglGetPixelFormatAttribfvARB = glad_wglGetPixelFormatAttribfvARB;
    glad_debug_wglGetPixelFormatAttribivARB = glad_wglGetPixelFormatAttribivARB;
    glad_debug_wglGetSwapIntervalEXT = glad_wglGetSwapIntervalEXT;
    glad_debug_wglQueryPbufferARB = glad_wglQueryPbufferARB;
    glad_debug_wglReleasePbufferDCARB = glad_wglReleasePbufferDCARB;
    glad_debug_wglReleaseTexImageARB = glad_wglReleaseTexImageARB;
    glad_debug_wglSetPbufferAttribARB = glad_wglSetPbufferAttribARB;
    glad_debug_wglSwapIntervalEXT = glad_wglSwapIntervalEXT;
}


#ifdef __cplusplus
}
#endif
