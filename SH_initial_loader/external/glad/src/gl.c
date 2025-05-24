/**
 * SPDX-License-Identifier: (WTFPL OR CC0-1.0) AND Apache-2.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/gl.h>

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



int GLAD_GL_VERSION_1_0 = 0;
int GLAD_GL_VERSION_1_1 = 0;
int GLAD_GL_VERSION_1_2 = 0;
int GLAD_GL_VERSION_1_3 = 0;
int GLAD_GL_VERSION_1_4 = 0;
int GLAD_GL_VERSION_1_5 = 0;
int GLAD_GL_VERSION_2_0 = 0;
int GLAD_GL_VERSION_2_1 = 0;
int GLAD_GL_ARB_draw_buffers = 0;
int GLAD_GL_ARB_fragment_program = 0;
int GLAD_GL_ARB_imaging = 0;
int GLAD_GL_ARB_multisample = 0;
int GLAD_GL_ARB_multitexture = 0;
int GLAD_GL_ARB_occlusion_query = 0;
int GLAD_GL_ARB_point_parameters = 0;
int GLAD_GL_ARB_shader_objects = 0;
int GLAD_GL_ARB_texture_compression = 0;
int GLAD_GL_ARB_texture_cube_map = 0;
int GLAD_GL_ARB_transpose_matrix = 0;
int GLAD_GL_ARB_vertex_buffer_object = 0;
int GLAD_GL_ARB_vertex_program = 0;
int GLAD_GL_ARB_vertex_shader = 0;
int GLAD_GL_ARB_window_pos = 0;
int GLAD_GL_ATI_draw_buffers = 0;
int GLAD_GL_ATI_separate_stencil = 0;
int GLAD_GL_EXT_blend_color = 0;
int GLAD_GL_EXT_blend_equation_separate = 0;
int GLAD_GL_EXT_blend_func_separate = 0;
int GLAD_GL_EXT_blend_minmax = 0;
int GLAD_GL_EXT_copy_texture = 0;
int GLAD_GL_EXT_draw_range_elements = 0;
int GLAD_GL_EXT_fog_coord = 0;
int GLAD_GL_EXT_multi_draw_arrays = 0;
int GLAD_GL_EXT_point_parameters = 0;
int GLAD_GL_EXT_secondary_color = 0;
int GLAD_GL_EXT_subtexture = 0;
int GLAD_GL_EXT_texture3D = 0;
int GLAD_GL_EXT_texture_compression_s3tc = 0;
int GLAD_GL_EXT_texture_filter_anisotropic = 0;
int GLAD_GL_EXT_texture_object = 0;
int GLAD_GL_EXT_vertex_array = 0;
int GLAD_GL_INGR_blend_func_separate = 0;
int GLAD_GL_KHR_debug = 0;
int GLAD_GL_MESA_window_pos = 0;
int GLAD_GL_NV_point_sprite = 0;
int GLAD_GL_NV_vertex_program = 0;
int GLAD_GL_SGIS_point_parameters = 0;


static void _pre_call_gl_callback_default(const char *name, GLADapiproc apiproc, int len_args, ...) {
    GLAD_UNUSED(len_args);

    if (apiproc == NULL) {
        fprintf(stderr, "GLAD: ERROR %s is NULL!\n", name);
        return;
    }
    if (glad_glGetError == NULL) {
        fprintf(stderr, "GLAD: ERROR glGetError is NULL!\n");
        return;
    }

    (void) glad_glGetError();
}
static void _post_call_gl_callback_default(void *ret, const char *name, GLADapiproc apiproc, int len_args, ...) {
    GLenum error_code;

    GLAD_UNUSED(ret);
    GLAD_UNUSED(apiproc);
    GLAD_UNUSED(len_args);

    error_code = glad_glGetError();

    if (error_code != GL_NO_ERROR) {
        fprintf(stderr, "GLAD: ERROR %d in %s!\n", error_code, name);
    }
}

static GLADprecallback _pre_call_gl_callback = _pre_call_gl_callback_default;
void gladSetGLPreCallback(GLADprecallback cb) {
    _pre_call_gl_callback = cb;
}
static GLADpostcallback _post_call_gl_callback = _post_call_gl_callback_default;
void gladSetGLPostCallback(GLADpostcallback cb) {
    _post_call_gl_callback = cb;
}

PFNGLACCUMPROC glad_glAccum = NULL;
static void GLAD_API_PTR glad_debug_impl_glAccum(GLenum op, GLfloat value) {
    _pre_call_gl_callback("glAccum", (GLADapiproc) glad_glAccum, 2, op, value);
    glad_glAccum(op, value);
    _post_call_gl_callback(NULL, "glAccum", (GLADapiproc) glad_glAccum, 2, op, value);
    
}
PFNGLACCUMPROC glad_debug_glAccum = glad_debug_impl_glAccum;
PFNGLACTIVETEXTUREPROC glad_glActiveTexture = NULL;
static void GLAD_API_PTR glad_debug_impl_glActiveTexture(GLenum texture) {
    _pre_call_gl_callback("glActiveTexture", (GLADapiproc) glad_glActiveTexture, 1, texture);
    glad_glActiveTexture(texture);
    _post_call_gl_callback(NULL, "glActiveTexture", (GLADapiproc) glad_glActiveTexture, 1, texture);
    
}
PFNGLACTIVETEXTUREPROC glad_debug_glActiveTexture = glad_debug_impl_glActiveTexture;
PFNGLACTIVETEXTUREARBPROC glad_glActiveTextureARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glActiveTextureARB(GLenum texture) {
    _pre_call_gl_callback("glActiveTextureARB", (GLADapiproc) glad_glActiveTextureARB, 1, texture);
    glad_glActiveTextureARB(texture);
    _post_call_gl_callback(NULL, "glActiveTextureARB", (GLADapiproc) glad_glActiveTextureARB, 1, texture);
    
}
PFNGLACTIVETEXTUREARBPROC glad_debug_glActiveTextureARB = glad_debug_impl_glActiveTextureARB;
PFNGLALPHAFUNCPROC glad_glAlphaFunc = NULL;
static void GLAD_API_PTR glad_debug_impl_glAlphaFunc(GLenum func, GLfloat ref) {
    _pre_call_gl_callback("glAlphaFunc", (GLADapiproc) glad_glAlphaFunc, 2, func, ref);
    glad_glAlphaFunc(func, ref);
    _post_call_gl_callback(NULL, "glAlphaFunc", (GLADapiproc) glad_glAlphaFunc, 2, func, ref);
    
}
PFNGLALPHAFUNCPROC glad_debug_glAlphaFunc = glad_debug_impl_glAlphaFunc;
PFNGLAREPROGRAMSRESIDENTNVPROC glad_glAreProgramsResidentNV = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glAreProgramsResidentNV(GLsizei n, const GLuint * programs, GLboolean * residences) {
    GLboolean ret;
    _pre_call_gl_callback("glAreProgramsResidentNV", (GLADapiproc) glad_glAreProgramsResidentNV, 3, n, programs, residences);
    ret = glad_glAreProgramsResidentNV(n, programs, residences);
    _post_call_gl_callback((void*) &ret, "glAreProgramsResidentNV", (GLADapiproc) glad_glAreProgramsResidentNV, 3, n, programs, residences);
    return ret;
}
PFNGLAREPROGRAMSRESIDENTNVPROC glad_debug_glAreProgramsResidentNV = glad_debug_impl_glAreProgramsResidentNV;
PFNGLARETEXTURESRESIDENTPROC glad_glAreTexturesResident = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glAreTexturesResident(GLsizei n, const GLuint * textures, GLboolean * residences) {
    GLboolean ret;
    _pre_call_gl_callback("glAreTexturesResident", (GLADapiproc) glad_glAreTexturesResident, 3, n, textures, residences);
    ret = glad_glAreTexturesResident(n, textures, residences);
    _post_call_gl_callback((void*) &ret, "glAreTexturesResident", (GLADapiproc) glad_glAreTexturesResident, 3, n, textures, residences);
    return ret;
}
PFNGLARETEXTURESRESIDENTPROC glad_debug_glAreTexturesResident = glad_debug_impl_glAreTexturesResident;
PFNGLARETEXTURESRESIDENTEXTPROC glad_glAreTexturesResidentEXT = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glAreTexturesResidentEXT(GLsizei n, const GLuint * textures, GLboolean * residences) {
    GLboolean ret;
    _pre_call_gl_callback("glAreTexturesResidentEXT", (GLADapiproc) glad_glAreTexturesResidentEXT, 3, n, textures, residences);
    ret = glad_glAreTexturesResidentEXT(n, textures, residences);
    _post_call_gl_callback((void*) &ret, "glAreTexturesResidentEXT", (GLADapiproc) glad_glAreTexturesResidentEXT, 3, n, textures, residences);
    return ret;
}
PFNGLARETEXTURESRESIDENTEXTPROC glad_debug_glAreTexturesResidentEXT = glad_debug_impl_glAreTexturesResidentEXT;
PFNGLARRAYELEMENTPROC glad_glArrayElement = NULL;
static void GLAD_API_PTR glad_debug_impl_glArrayElement(GLint i) {
    _pre_call_gl_callback("glArrayElement", (GLADapiproc) glad_glArrayElement, 1, i);
    glad_glArrayElement(i);
    _post_call_gl_callback(NULL, "glArrayElement", (GLADapiproc) glad_glArrayElement, 1, i);
    
}
PFNGLARRAYELEMENTPROC glad_debug_glArrayElement = glad_debug_impl_glArrayElement;
PFNGLARRAYELEMENTEXTPROC glad_glArrayElementEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glArrayElementEXT(GLint i) {
    _pre_call_gl_callback("glArrayElementEXT", (GLADapiproc) glad_glArrayElementEXT, 1, i);
    glad_glArrayElementEXT(i);
    _post_call_gl_callback(NULL, "glArrayElementEXT", (GLADapiproc) glad_glArrayElementEXT, 1, i);
    
}
PFNGLARRAYELEMENTEXTPROC glad_debug_glArrayElementEXT = glad_debug_impl_glArrayElementEXT;
PFNGLATTACHOBJECTARBPROC glad_glAttachObjectARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj) {
    _pre_call_gl_callback("glAttachObjectARB", (GLADapiproc) glad_glAttachObjectARB, 2, containerObj, obj);
    glad_glAttachObjectARB(containerObj, obj);
    _post_call_gl_callback(NULL, "glAttachObjectARB", (GLADapiproc) glad_glAttachObjectARB, 2, containerObj, obj);
    
}
PFNGLATTACHOBJECTARBPROC glad_debug_glAttachObjectARB = glad_debug_impl_glAttachObjectARB;
PFNGLATTACHSHADERPROC glad_glAttachShader = NULL;
static void GLAD_API_PTR glad_debug_impl_glAttachShader(GLuint program, GLuint shader) {
    _pre_call_gl_callback("glAttachShader", (GLADapiproc) glad_glAttachShader, 2, program, shader);
    glad_glAttachShader(program, shader);
    _post_call_gl_callback(NULL, "glAttachShader", (GLADapiproc) glad_glAttachShader, 2, program, shader);
    
}
PFNGLATTACHSHADERPROC glad_debug_glAttachShader = glad_debug_impl_glAttachShader;
PFNGLBEGINPROC glad_glBegin = NULL;
static void GLAD_API_PTR glad_debug_impl_glBegin(GLenum mode) {
    _pre_call_gl_callback("glBegin", (GLADapiproc) glad_glBegin, 1, mode);
    glad_glBegin(mode);
    _post_call_gl_callback(NULL, "glBegin", (GLADapiproc) glad_glBegin, 1, mode);
    
}
PFNGLBEGINPROC glad_debug_glBegin = glad_debug_impl_glBegin;
PFNGLBEGINQUERYPROC glad_glBeginQuery = NULL;
static void GLAD_API_PTR glad_debug_impl_glBeginQuery(GLenum target, GLuint id) {
    _pre_call_gl_callback("glBeginQuery", (GLADapiproc) glad_glBeginQuery, 2, target, id);
    glad_glBeginQuery(target, id);
    _post_call_gl_callback(NULL, "glBeginQuery", (GLADapiproc) glad_glBeginQuery, 2, target, id);
    
}
PFNGLBEGINQUERYPROC glad_debug_glBeginQuery = glad_debug_impl_glBeginQuery;
PFNGLBEGINQUERYARBPROC glad_glBeginQueryARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glBeginQueryARB(GLenum target, GLuint id) {
    _pre_call_gl_callback("glBeginQueryARB", (GLADapiproc) glad_glBeginQueryARB, 2, target, id);
    glad_glBeginQueryARB(target, id);
    _post_call_gl_callback(NULL, "glBeginQueryARB", (GLADapiproc) glad_glBeginQueryARB, 2, target, id);
    
}
PFNGLBEGINQUERYARBPROC glad_debug_glBeginQueryARB = glad_debug_impl_glBeginQueryARB;
PFNGLBINDATTRIBLOCATIONPROC glad_glBindAttribLocation = NULL;
static void GLAD_API_PTR glad_debug_impl_glBindAttribLocation(GLuint program, GLuint index, const GLchar * name) {
    _pre_call_gl_callback("glBindAttribLocation", (GLADapiproc) glad_glBindAttribLocation, 3, program, index, name);
    glad_glBindAttribLocation(program, index, name);
    _post_call_gl_callback(NULL, "glBindAttribLocation", (GLADapiproc) glad_glBindAttribLocation, 3, program, index, name);
    
}
PFNGLBINDATTRIBLOCATIONPROC glad_debug_glBindAttribLocation = glad_debug_impl_glBindAttribLocation;
PFNGLBINDATTRIBLOCATIONARBPROC glad_glBindAttribLocationARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glBindAttribLocationARB(GLhandleARB programObj, GLuint index, const GLcharARB * name) {
    _pre_call_gl_callback("glBindAttribLocationARB", (GLADapiproc) glad_glBindAttribLocationARB, 3, programObj, index, name);
    glad_glBindAttribLocationARB(programObj, index, name);
    _post_call_gl_callback(NULL, "glBindAttribLocationARB", (GLADapiproc) glad_glBindAttribLocationARB, 3, programObj, index, name);
    
}
PFNGLBINDATTRIBLOCATIONARBPROC glad_debug_glBindAttribLocationARB = glad_debug_impl_glBindAttribLocationARB;
PFNGLBINDBUFFERPROC glad_glBindBuffer = NULL;
static void GLAD_API_PTR glad_debug_impl_glBindBuffer(GLenum target, GLuint buffer) {
    _pre_call_gl_callback("glBindBuffer", (GLADapiproc) glad_glBindBuffer, 2, target, buffer);
    glad_glBindBuffer(target, buffer);
    _post_call_gl_callback(NULL, "glBindBuffer", (GLADapiproc) glad_glBindBuffer, 2, target, buffer);
    
}
PFNGLBINDBUFFERPROC glad_debug_glBindBuffer = glad_debug_impl_glBindBuffer;
PFNGLBINDBUFFERARBPROC glad_glBindBufferARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glBindBufferARB(GLenum target, GLuint buffer) {
    _pre_call_gl_callback("glBindBufferARB", (GLADapiproc) glad_glBindBufferARB, 2, target, buffer);
    glad_glBindBufferARB(target, buffer);
    _post_call_gl_callback(NULL, "glBindBufferARB", (GLADapiproc) glad_glBindBufferARB, 2, target, buffer);
    
}
PFNGLBINDBUFFERARBPROC glad_debug_glBindBufferARB = glad_debug_impl_glBindBufferARB;
PFNGLBINDPROGRAMARBPROC glad_glBindProgramARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glBindProgramARB(GLenum target, GLuint program) {
    _pre_call_gl_callback("glBindProgramARB", (GLADapiproc) glad_glBindProgramARB, 2, target, program);
    glad_glBindProgramARB(target, program);
    _post_call_gl_callback(NULL, "glBindProgramARB", (GLADapiproc) glad_glBindProgramARB, 2, target, program);
    
}
PFNGLBINDPROGRAMARBPROC glad_debug_glBindProgramARB = glad_debug_impl_glBindProgramARB;
PFNGLBINDPROGRAMNVPROC glad_glBindProgramNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glBindProgramNV(GLenum target, GLuint id) {
    _pre_call_gl_callback("glBindProgramNV", (GLADapiproc) glad_glBindProgramNV, 2, target, id);
    glad_glBindProgramNV(target, id);
    _post_call_gl_callback(NULL, "glBindProgramNV", (GLADapiproc) glad_glBindProgramNV, 2, target, id);
    
}
PFNGLBINDPROGRAMNVPROC glad_debug_glBindProgramNV = glad_debug_impl_glBindProgramNV;
PFNGLBINDTEXTUREPROC glad_glBindTexture = NULL;
static void GLAD_API_PTR glad_debug_impl_glBindTexture(GLenum target, GLuint texture) {
    _pre_call_gl_callback("glBindTexture", (GLADapiproc) glad_glBindTexture, 2, target, texture);
    glad_glBindTexture(target, texture);
    _post_call_gl_callback(NULL, "glBindTexture", (GLADapiproc) glad_glBindTexture, 2, target, texture);
    
}
PFNGLBINDTEXTUREPROC glad_debug_glBindTexture = glad_debug_impl_glBindTexture;
PFNGLBINDTEXTUREEXTPROC glad_glBindTextureEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glBindTextureEXT(GLenum target, GLuint texture) {
    _pre_call_gl_callback("glBindTextureEXT", (GLADapiproc) glad_glBindTextureEXT, 2, target, texture);
    glad_glBindTextureEXT(target, texture);
    _post_call_gl_callback(NULL, "glBindTextureEXT", (GLADapiproc) glad_glBindTextureEXT, 2, target, texture);
    
}
PFNGLBINDTEXTUREEXTPROC glad_debug_glBindTextureEXT = glad_debug_impl_glBindTextureEXT;
PFNGLBITMAPPROC glad_glBitmap = NULL;
static void GLAD_API_PTR glad_debug_impl_glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap) {
    _pre_call_gl_callback("glBitmap", (GLADapiproc) glad_glBitmap, 7, width, height, xorig, yorig, xmove, ymove, bitmap);
    glad_glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);
    _post_call_gl_callback(NULL, "glBitmap", (GLADapiproc) glad_glBitmap, 7, width, height, xorig, yorig, xmove, ymove, bitmap);
    
}
PFNGLBITMAPPROC glad_debug_glBitmap = glad_debug_impl_glBitmap;
PFNGLBLENDCOLORPROC glad_glBlendColor = NULL;
static void GLAD_API_PTR glad_debug_impl_glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    _pre_call_gl_callback("glBlendColor", (GLADapiproc) glad_glBlendColor, 4, red, green, blue, alpha);
    glad_glBlendColor(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glBlendColor", (GLADapiproc) glad_glBlendColor, 4, red, green, blue, alpha);
    
}
PFNGLBLENDCOLORPROC glad_debug_glBlendColor = glad_debug_impl_glBlendColor;
PFNGLBLENDCOLOREXTPROC glad_glBlendColorEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glBlendColorEXT(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    _pre_call_gl_callback("glBlendColorEXT", (GLADapiproc) glad_glBlendColorEXT, 4, red, green, blue, alpha);
    glad_glBlendColorEXT(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glBlendColorEXT", (GLADapiproc) glad_glBlendColorEXT, 4, red, green, blue, alpha);
    
}
PFNGLBLENDCOLOREXTPROC glad_debug_glBlendColorEXT = glad_debug_impl_glBlendColorEXT;
PFNGLBLENDEQUATIONPROC glad_glBlendEquation = NULL;
static void GLAD_API_PTR glad_debug_impl_glBlendEquation(GLenum mode) {
    _pre_call_gl_callback("glBlendEquation", (GLADapiproc) glad_glBlendEquation, 1, mode);
    glad_glBlendEquation(mode);
    _post_call_gl_callback(NULL, "glBlendEquation", (GLADapiproc) glad_glBlendEquation, 1, mode);
    
}
PFNGLBLENDEQUATIONPROC glad_debug_glBlendEquation = glad_debug_impl_glBlendEquation;
PFNGLBLENDEQUATIONEXTPROC glad_glBlendEquationEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glBlendEquationEXT(GLenum mode) {
    _pre_call_gl_callback("glBlendEquationEXT", (GLADapiproc) glad_glBlendEquationEXT, 1, mode);
    glad_glBlendEquationEXT(mode);
    _post_call_gl_callback(NULL, "glBlendEquationEXT", (GLADapiproc) glad_glBlendEquationEXT, 1, mode);
    
}
PFNGLBLENDEQUATIONEXTPROC glad_debug_glBlendEquationEXT = glad_debug_impl_glBlendEquationEXT;
PFNGLBLENDEQUATIONSEPARATEPROC glad_glBlendEquationSeparate = NULL;
static void GLAD_API_PTR glad_debug_impl_glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
    _pre_call_gl_callback("glBlendEquationSeparate", (GLADapiproc) glad_glBlendEquationSeparate, 2, modeRGB, modeAlpha);
    glad_glBlendEquationSeparate(modeRGB, modeAlpha);
    _post_call_gl_callback(NULL, "glBlendEquationSeparate", (GLADapiproc) glad_glBlendEquationSeparate, 2, modeRGB, modeAlpha);
    
}
PFNGLBLENDEQUATIONSEPARATEPROC glad_debug_glBlendEquationSeparate = glad_debug_impl_glBlendEquationSeparate;
PFNGLBLENDEQUATIONSEPARATEEXTPROC glad_glBlendEquationSeparateEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha) {
    _pre_call_gl_callback("glBlendEquationSeparateEXT", (GLADapiproc) glad_glBlendEquationSeparateEXT, 2, modeRGB, modeAlpha);
    glad_glBlendEquationSeparateEXT(modeRGB, modeAlpha);
    _post_call_gl_callback(NULL, "glBlendEquationSeparateEXT", (GLADapiproc) glad_glBlendEquationSeparateEXT, 2, modeRGB, modeAlpha);
    
}
PFNGLBLENDEQUATIONSEPARATEEXTPROC glad_debug_glBlendEquationSeparateEXT = glad_debug_impl_glBlendEquationSeparateEXT;
PFNGLBLENDFUNCPROC glad_glBlendFunc = NULL;
static void GLAD_API_PTR glad_debug_impl_glBlendFunc(GLenum sfactor, GLenum dfactor) {
    _pre_call_gl_callback("glBlendFunc", (GLADapiproc) glad_glBlendFunc, 2, sfactor, dfactor);
    glad_glBlendFunc(sfactor, dfactor);
    _post_call_gl_callback(NULL, "glBlendFunc", (GLADapiproc) glad_glBlendFunc, 2, sfactor, dfactor);
    
}
PFNGLBLENDFUNCPROC glad_debug_glBlendFunc = glad_debug_impl_glBlendFunc;
PFNGLBLENDFUNCSEPARATEPROC glad_glBlendFuncSeparate = NULL;
static void GLAD_API_PTR glad_debug_impl_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    _pre_call_gl_callback("glBlendFuncSeparate", (GLADapiproc) glad_glBlendFuncSeparate, 4, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    glad_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    _post_call_gl_callback(NULL, "glBlendFuncSeparate", (GLADapiproc) glad_glBlendFuncSeparate, 4, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    
}
PFNGLBLENDFUNCSEPARATEPROC glad_debug_glBlendFuncSeparate = glad_debug_impl_glBlendFuncSeparate;
PFNGLBLENDFUNCSEPARATEEXTPROC glad_glBlendFuncSeparateEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    _pre_call_gl_callback("glBlendFuncSeparateEXT", (GLADapiproc) glad_glBlendFuncSeparateEXT, 4, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    glad_glBlendFuncSeparateEXT(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    _post_call_gl_callback(NULL, "glBlendFuncSeparateEXT", (GLADapiproc) glad_glBlendFuncSeparateEXT, 4, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    
}
PFNGLBLENDFUNCSEPARATEEXTPROC glad_debug_glBlendFuncSeparateEXT = glad_debug_impl_glBlendFuncSeparateEXT;
PFNGLBLENDFUNCSEPARATEINGRPROC glad_glBlendFuncSeparateINGR = NULL;
static void GLAD_API_PTR glad_debug_impl_glBlendFuncSeparateINGR(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    _pre_call_gl_callback("glBlendFuncSeparateINGR", (GLADapiproc) glad_glBlendFuncSeparateINGR, 4, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    glad_glBlendFuncSeparateINGR(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    _post_call_gl_callback(NULL, "glBlendFuncSeparateINGR", (GLADapiproc) glad_glBlendFuncSeparateINGR, 4, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    
}
PFNGLBLENDFUNCSEPARATEINGRPROC glad_debug_glBlendFuncSeparateINGR = glad_debug_impl_glBlendFuncSeparateINGR;
PFNGLBUFFERDATAPROC glad_glBufferData = NULL;
static void GLAD_API_PTR glad_debug_impl_glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage) {
    _pre_call_gl_callback("glBufferData", (GLADapiproc) glad_glBufferData, 4, target, size, data, usage);
    glad_glBufferData(target, size, data, usage);
    _post_call_gl_callback(NULL, "glBufferData", (GLADapiproc) glad_glBufferData, 4, target, size, data, usage);
    
}
PFNGLBUFFERDATAPROC glad_debug_glBufferData = glad_debug_impl_glBufferData;
PFNGLBUFFERDATAARBPROC glad_glBufferDataARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glBufferDataARB(GLenum target, GLsizeiptrARB size, const void * data, GLenum usage) {
    _pre_call_gl_callback("glBufferDataARB", (GLADapiproc) glad_glBufferDataARB, 4, target, size, data, usage);
    glad_glBufferDataARB(target, size, data, usage);
    _post_call_gl_callback(NULL, "glBufferDataARB", (GLADapiproc) glad_glBufferDataARB, 4, target, size, data, usage);
    
}
PFNGLBUFFERDATAARBPROC glad_debug_glBufferDataARB = glad_debug_impl_glBufferDataARB;
PFNGLBUFFERSUBDATAPROC glad_glBufferSubData = NULL;
static void GLAD_API_PTR glad_debug_impl_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data) {
    _pre_call_gl_callback("glBufferSubData", (GLADapiproc) glad_glBufferSubData, 4, target, offset, size, data);
    glad_glBufferSubData(target, offset, size, data);
    _post_call_gl_callback(NULL, "glBufferSubData", (GLADapiproc) glad_glBufferSubData, 4, target, offset, size, data);
    
}
PFNGLBUFFERSUBDATAPROC glad_debug_glBufferSubData = glad_debug_impl_glBufferSubData;
PFNGLBUFFERSUBDATAARBPROC glad_glBufferSubDataARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void * data) {
    _pre_call_gl_callback("glBufferSubDataARB", (GLADapiproc) glad_glBufferSubDataARB, 4, target, offset, size, data);
    glad_glBufferSubDataARB(target, offset, size, data);
    _post_call_gl_callback(NULL, "glBufferSubDataARB", (GLADapiproc) glad_glBufferSubDataARB, 4, target, offset, size, data);
    
}
PFNGLBUFFERSUBDATAARBPROC glad_debug_glBufferSubDataARB = glad_debug_impl_glBufferSubDataARB;
PFNGLCALLLISTPROC glad_glCallList = NULL;
static void GLAD_API_PTR glad_debug_impl_glCallList(GLuint list) {
    _pre_call_gl_callback("glCallList", (GLADapiproc) glad_glCallList, 1, list);
    glad_glCallList(list);
    _post_call_gl_callback(NULL, "glCallList", (GLADapiproc) glad_glCallList, 1, list);
    
}
PFNGLCALLLISTPROC glad_debug_glCallList = glad_debug_impl_glCallList;
PFNGLCALLLISTSPROC glad_glCallLists = NULL;
static void GLAD_API_PTR glad_debug_impl_glCallLists(GLsizei n, GLenum type, const void * lists) {
    _pre_call_gl_callback("glCallLists", (GLADapiproc) glad_glCallLists, 3, n, type, lists);
    glad_glCallLists(n, type, lists);
    _post_call_gl_callback(NULL, "glCallLists", (GLADapiproc) glad_glCallLists, 3, n, type, lists);
    
}
PFNGLCALLLISTSPROC glad_debug_glCallLists = glad_debug_impl_glCallLists;
PFNGLCLEARPROC glad_glClear = NULL;
static void GLAD_API_PTR glad_debug_impl_glClear(GLbitfield mask) {
    _pre_call_gl_callback("glClear", (GLADapiproc) glad_glClear, 1, mask);
    glad_glClear(mask);
    _post_call_gl_callback(NULL, "glClear", (GLADapiproc) glad_glClear, 1, mask);
    
}
PFNGLCLEARPROC glad_debug_glClear = glad_debug_impl_glClear;
PFNGLCLEARACCUMPROC glad_glClearAccum = NULL;
static void GLAD_API_PTR glad_debug_impl_glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    _pre_call_gl_callback("glClearAccum", (GLADapiproc) glad_glClearAccum, 4, red, green, blue, alpha);
    glad_glClearAccum(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glClearAccum", (GLADapiproc) glad_glClearAccum, 4, red, green, blue, alpha);
    
}
PFNGLCLEARACCUMPROC glad_debug_glClearAccum = glad_debug_impl_glClearAccum;
PFNGLCLEARCOLORPROC glad_glClearColor = NULL;
static void GLAD_API_PTR glad_debug_impl_glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    _pre_call_gl_callback("glClearColor", (GLADapiproc) glad_glClearColor, 4, red, green, blue, alpha);
    glad_glClearColor(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glClearColor", (GLADapiproc) glad_glClearColor, 4, red, green, blue, alpha);
    
}
PFNGLCLEARCOLORPROC glad_debug_glClearColor = glad_debug_impl_glClearColor;
PFNGLCLEARDEPTHPROC glad_glClearDepth = NULL;
static void GLAD_API_PTR glad_debug_impl_glClearDepth(GLdouble depth) {
    _pre_call_gl_callback("glClearDepth", (GLADapiproc) glad_glClearDepth, 1, depth);
    glad_glClearDepth(depth);
    _post_call_gl_callback(NULL, "glClearDepth", (GLADapiproc) glad_glClearDepth, 1, depth);
    
}
PFNGLCLEARDEPTHPROC glad_debug_glClearDepth = glad_debug_impl_glClearDepth;
PFNGLCLEARINDEXPROC glad_glClearIndex = NULL;
static void GLAD_API_PTR glad_debug_impl_glClearIndex(GLfloat c) {
    _pre_call_gl_callback("glClearIndex", (GLADapiproc) glad_glClearIndex, 1, c);
    glad_glClearIndex(c);
    _post_call_gl_callback(NULL, "glClearIndex", (GLADapiproc) glad_glClearIndex, 1, c);
    
}
PFNGLCLEARINDEXPROC glad_debug_glClearIndex = glad_debug_impl_glClearIndex;
PFNGLCLEARSTENCILPROC glad_glClearStencil = NULL;
static void GLAD_API_PTR glad_debug_impl_glClearStencil(GLint s) {
    _pre_call_gl_callback("glClearStencil", (GLADapiproc) glad_glClearStencil, 1, s);
    glad_glClearStencil(s);
    _post_call_gl_callback(NULL, "glClearStencil", (GLADapiproc) glad_glClearStencil, 1, s);
    
}
PFNGLCLEARSTENCILPROC glad_debug_glClearStencil = glad_debug_impl_glClearStencil;
PFNGLCLIENTACTIVETEXTUREPROC glad_glClientActiveTexture = NULL;
static void GLAD_API_PTR glad_debug_impl_glClientActiveTexture(GLenum texture) {
    _pre_call_gl_callback("glClientActiveTexture", (GLADapiproc) glad_glClientActiveTexture, 1, texture);
    glad_glClientActiveTexture(texture);
    _post_call_gl_callback(NULL, "glClientActiveTexture", (GLADapiproc) glad_glClientActiveTexture, 1, texture);
    
}
PFNGLCLIENTACTIVETEXTUREPROC glad_debug_glClientActiveTexture = glad_debug_impl_glClientActiveTexture;
PFNGLCLIENTACTIVETEXTUREARBPROC glad_glClientActiveTextureARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glClientActiveTextureARB(GLenum texture) {
    _pre_call_gl_callback("glClientActiveTextureARB", (GLADapiproc) glad_glClientActiveTextureARB, 1, texture);
    glad_glClientActiveTextureARB(texture);
    _post_call_gl_callback(NULL, "glClientActiveTextureARB", (GLADapiproc) glad_glClientActiveTextureARB, 1, texture);
    
}
PFNGLCLIENTACTIVETEXTUREARBPROC glad_debug_glClientActiveTextureARB = glad_debug_impl_glClientActiveTextureARB;
PFNGLCLIPPLANEPROC glad_glClipPlane = NULL;
static void GLAD_API_PTR glad_debug_impl_glClipPlane(GLenum plane, const GLdouble * equation) {
    _pre_call_gl_callback("glClipPlane", (GLADapiproc) glad_glClipPlane, 2, plane, equation);
    glad_glClipPlane(plane, equation);
    _post_call_gl_callback(NULL, "glClipPlane", (GLADapiproc) glad_glClipPlane, 2, plane, equation);
    
}
PFNGLCLIPPLANEPROC glad_debug_glClipPlane = glad_debug_impl_glClipPlane;
PFNGLCOLOR3BPROC glad_glColor3b = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    _pre_call_gl_callback("glColor3b", (GLADapiproc) glad_glColor3b, 3, red, green, blue);
    glad_glColor3b(red, green, blue);
    _post_call_gl_callback(NULL, "glColor3b", (GLADapiproc) glad_glColor3b, 3, red, green, blue);
    
}
PFNGLCOLOR3BPROC glad_debug_glColor3b = glad_debug_impl_glColor3b;
PFNGLCOLOR3BVPROC glad_glColor3bv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3bv(const GLbyte * v) {
    _pre_call_gl_callback("glColor3bv", (GLADapiproc) glad_glColor3bv, 1, v);
    glad_glColor3bv(v);
    _post_call_gl_callback(NULL, "glColor3bv", (GLADapiproc) glad_glColor3bv, 1, v);
    
}
PFNGLCOLOR3BVPROC glad_debug_glColor3bv = glad_debug_impl_glColor3bv;
PFNGLCOLOR3DPROC glad_glColor3d = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    _pre_call_gl_callback("glColor3d", (GLADapiproc) glad_glColor3d, 3, red, green, blue);
    glad_glColor3d(red, green, blue);
    _post_call_gl_callback(NULL, "glColor3d", (GLADapiproc) glad_glColor3d, 3, red, green, blue);
    
}
PFNGLCOLOR3DPROC glad_debug_glColor3d = glad_debug_impl_glColor3d;
PFNGLCOLOR3DVPROC glad_glColor3dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3dv(const GLdouble * v) {
    _pre_call_gl_callback("glColor3dv", (GLADapiproc) glad_glColor3dv, 1, v);
    glad_glColor3dv(v);
    _post_call_gl_callback(NULL, "glColor3dv", (GLADapiproc) glad_glColor3dv, 1, v);
    
}
PFNGLCOLOR3DVPROC glad_debug_glColor3dv = glad_debug_impl_glColor3dv;
PFNGLCOLOR3FPROC glad_glColor3f = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    _pre_call_gl_callback("glColor3f", (GLADapiproc) glad_glColor3f, 3, red, green, blue);
    glad_glColor3f(red, green, blue);
    _post_call_gl_callback(NULL, "glColor3f", (GLADapiproc) glad_glColor3f, 3, red, green, blue);
    
}
PFNGLCOLOR3FPROC glad_debug_glColor3f = glad_debug_impl_glColor3f;
PFNGLCOLOR3FVPROC glad_glColor3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3fv(const GLfloat * v) {
    _pre_call_gl_callback("glColor3fv", (GLADapiproc) glad_glColor3fv, 1, v);
    glad_glColor3fv(v);
    _post_call_gl_callback(NULL, "glColor3fv", (GLADapiproc) glad_glColor3fv, 1, v);
    
}
PFNGLCOLOR3FVPROC glad_debug_glColor3fv = glad_debug_impl_glColor3fv;
PFNGLCOLOR3IPROC glad_glColor3i = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3i(GLint red, GLint green, GLint blue) {
    _pre_call_gl_callback("glColor3i", (GLADapiproc) glad_glColor3i, 3, red, green, blue);
    glad_glColor3i(red, green, blue);
    _post_call_gl_callback(NULL, "glColor3i", (GLADapiproc) glad_glColor3i, 3, red, green, blue);
    
}
PFNGLCOLOR3IPROC glad_debug_glColor3i = glad_debug_impl_glColor3i;
PFNGLCOLOR3IVPROC glad_glColor3iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3iv(const GLint * v) {
    _pre_call_gl_callback("glColor3iv", (GLADapiproc) glad_glColor3iv, 1, v);
    glad_glColor3iv(v);
    _post_call_gl_callback(NULL, "glColor3iv", (GLADapiproc) glad_glColor3iv, 1, v);
    
}
PFNGLCOLOR3IVPROC glad_debug_glColor3iv = glad_debug_impl_glColor3iv;
PFNGLCOLOR3SPROC glad_glColor3s = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3s(GLshort red, GLshort green, GLshort blue) {
    _pre_call_gl_callback("glColor3s", (GLADapiproc) glad_glColor3s, 3, red, green, blue);
    glad_glColor3s(red, green, blue);
    _post_call_gl_callback(NULL, "glColor3s", (GLADapiproc) glad_glColor3s, 3, red, green, blue);
    
}
PFNGLCOLOR3SPROC glad_debug_glColor3s = glad_debug_impl_glColor3s;
PFNGLCOLOR3SVPROC glad_glColor3sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3sv(const GLshort * v) {
    _pre_call_gl_callback("glColor3sv", (GLADapiproc) glad_glColor3sv, 1, v);
    glad_glColor3sv(v);
    _post_call_gl_callback(NULL, "glColor3sv", (GLADapiproc) glad_glColor3sv, 1, v);
    
}
PFNGLCOLOR3SVPROC glad_debug_glColor3sv = glad_debug_impl_glColor3sv;
PFNGLCOLOR3UBPROC glad_glColor3ub = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    _pre_call_gl_callback("glColor3ub", (GLADapiproc) glad_glColor3ub, 3, red, green, blue);
    glad_glColor3ub(red, green, blue);
    _post_call_gl_callback(NULL, "glColor3ub", (GLADapiproc) glad_glColor3ub, 3, red, green, blue);
    
}
PFNGLCOLOR3UBPROC glad_debug_glColor3ub = glad_debug_impl_glColor3ub;
PFNGLCOLOR3UBVPROC glad_glColor3ubv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3ubv(const GLubyte * v) {
    _pre_call_gl_callback("glColor3ubv", (GLADapiproc) glad_glColor3ubv, 1, v);
    glad_glColor3ubv(v);
    _post_call_gl_callback(NULL, "glColor3ubv", (GLADapiproc) glad_glColor3ubv, 1, v);
    
}
PFNGLCOLOR3UBVPROC glad_debug_glColor3ubv = glad_debug_impl_glColor3ubv;
PFNGLCOLOR3UIPROC glad_glColor3ui = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3ui(GLuint red, GLuint green, GLuint blue) {
    _pre_call_gl_callback("glColor3ui", (GLADapiproc) glad_glColor3ui, 3, red, green, blue);
    glad_glColor3ui(red, green, blue);
    _post_call_gl_callback(NULL, "glColor3ui", (GLADapiproc) glad_glColor3ui, 3, red, green, blue);
    
}
PFNGLCOLOR3UIPROC glad_debug_glColor3ui = glad_debug_impl_glColor3ui;
PFNGLCOLOR3UIVPROC glad_glColor3uiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3uiv(const GLuint * v) {
    _pre_call_gl_callback("glColor3uiv", (GLADapiproc) glad_glColor3uiv, 1, v);
    glad_glColor3uiv(v);
    _post_call_gl_callback(NULL, "glColor3uiv", (GLADapiproc) glad_glColor3uiv, 1, v);
    
}
PFNGLCOLOR3UIVPROC glad_debug_glColor3uiv = glad_debug_impl_glColor3uiv;
PFNGLCOLOR3USPROC glad_glColor3us = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3us(GLushort red, GLushort green, GLushort blue) {
    _pre_call_gl_callback("glColor3us", (GLADapiproc) glad_glColor3us, 3, red, green, blue);
    glad_glColor3us(red, green, blue);
    _post_call_gl_callback(NULL, "glColor3us", (GLADapiproc) glad_glColor3us, 3, red, green, blue);
    
}
PFNGLCOLOR3USPROC glad_debug_glColor3us = glad_debug_impl_glColor3us;
PFNGLCOLOR3USVPROC glad_glColor3usv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor3usv(const GLushort * v) {
    _pre_call_gl_callback("glColor3usv", (GLADapiproc) glad_glColor3usv, 1, v);
    glad_glColor3usv(v);
    _post_call_gl_callback(NULL, "glColor3usv", (GLADapiproc) glad_glColor3usv, 1, v);
    
}
PFNGLCOLOR3USVPROC glad_debug_glColor3usv = glad_debug_impl_glColor3usv;
PFNGLCOLOR4BPROC glad_glColor4b = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
    _pre_call_gl_callback("glColor4b", (GLADapiproc) glad_glColor4b, 4, red, green, blue, alpha);
    glad_glColor4b(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glColor4b", (GLADapiproc) glad_glColor4b, 4, red, green, blue, alpha);
    
}
PFNGLCOLOR4BPROC glad_debug_glColor4b = glad_debug_impl_glColor4b;
PFNGLCOLOR4BVPROC glad_glColor4bv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4bv(const GLbyte * v) {
    _pre_call_gl_callback("glColor4bv", (GLADapiproc) glad_glColor4bv, 1, v);
    glad_glColor4bv(v);
    _post_call_gl_callback(NULL, "glColor4bv", (GLADapiproc) glad_glColor4bv, 1, v);
    
}
PFNGLCOLOR4BVPROC glad_debug_glColor4bv = glad_debug_impl_glColor4bv;
PFNGLCOLOR4DPROC glad_glColor4d = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
    _pre_call_gl_callback("glColor4d", (GLADapiproc) glad_glColor4d, 4, red, green, blue, alpha);
    glad_glColor4d(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glColor4d", (GLADapiproc) glad_glColor4d, 4, red, green, blue, alpha);
    
}
PFNGLCOLOR4DPROC glad_debug_glColor4d = glad_debug_impl_glColor4d;
PFNGLCOLOR4DVPROC glad_glColor4dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4dv(const GLdouble * v) {
    _pre_call_gl_callback("glColor4dv", (GLADapiproc) glad_glColor4dv, 1, v);
    glad_glColor4dv(v);
    _post_call_gl_callback(NULL, "glColor4dv", (GLADapiproc) glad_glColor4dv, 1, v);
    
}
PFNGLCOLOR4DVPROC glad_debug_glColor4dv = glad_debug_impl_glColor4dv;
PFNGLCOLOR4FPROC glad_glColor4f = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    _pre_call_gl_callback("glColor4f", (GLADapiproc) glad_glColor4f, 4, red, green, blue, alpha);
    glad_glColor4f(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glColor4f", (GLADapiproc) glad_glColor4f, 4, red, green, blue, alpha);
    
}
PFNGLCOLOR4FPROC glad_debug_glColor4f = glad_debug_impl_glColor4f;
PFNGLCOLOR4FVPROC glad_glColor4fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4fv(const GLfloat * v) {
    _pre_call_gl_callback("glColor4fv", (GLADapiproc) glad_glColor4fv, 1, v);
    glad_glColor4fv(v);
    _post_call_gl_callback(NULL, "glColor4fv", (GLADapiproc) glad_glColor4fv, 1, v);
    
}
PFNGLCOLOR4FVPROC glad_debug_glColor4fv = glad_debug_impl_glColor4fv;
PFNGLCOLOR4IPROC glad_glColor4i = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {
    _pre_call_gl_callback("glColor4i", (GLADapiproc) glad_glColor4i, 4, red, green, blue, alpha);
    glad_glColor4i(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glColor4i", (GLADapiproc) glad_glColor4i, 4, red, green, blue, alpha);
    
}
PFNGLCOLOR4IPROC glad_debug_glColor4i = glad_debug_impl_glColor4i;
PFNGLCOLOR4IVPROC glad_glColor4iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4iv(const GLint * v) {
    _pre_call_gl_callback("glColor4iv", (GLADapiproc) glad_glColor4iv, 1, v);
    glad_glColor4iv(v);
    _post_call_gl_callback(NULL, "glColor4iv", (GLADapiproc) glad_glColor4iv, 1, v);
    
}
PFNGLCOLOR4IVPROC glad_debug_glColor4iv = glad_debug_impl_glColor4iv;
PFNGLCOLOR4SPROC glad_glColor4s = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
    _pre_call_gl_callback("glColor4s", (GLADapiproc) glad_glColor4s, 4, red, green, blue, alpha);
    glad_glColor4s(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glColor4s", (GLADapiproc) glad_glColor4s, 4, red, green, blue, alpha);
    
}
PFNGLCOLOR4SPROC glad_debug_glColor4s = glad_debug_impl_glColor4s;
PFNGLCOLOR4SVPROC glad_glColor4sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4sv(const GLshort * v) {
    _pre_call_gl_callback("glColor4sv", (GLADapiproc) glad_glColor4sv, 1, v);
    glad_glColor4sv(v);
    _post_call_gl_callback(NULL, "glColor4sv", (GLADapiproc) glad_glColor4sv, 1, v);
    
}
PFNGLCOLOR4SVPROC glad_debug_glColor4sv = glad_debug_impl_glColor4sv;
PFNGLCOLOR4UBPROC glad_glColor4ub = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    _pre_call_gl_callback("glColor4ub", (GLADapiproc) glad_glColor4ub, 4, red, green, blue, alpha);
    glad_glColor4ub(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glColor4ub", (GLADapiproc) glad_glColor4ub, 4, red, green, blue, alpha);
    
}
PFNGLCOLOR4UBPROC glad_debug_glColor4ub = glad_debug_impl_glColor4ub;
PFNGLCOLOR4UBVPROC glad_glColor4ubv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4ubv(const GLubyte * v) {
    _pre_call_gl_callback("glColor4ubv", (GLADapiproc) glad_glColor4ubv, 1, v);
    glad_glColor4ubv(v);
    _post_call_gl_callback(NULL, "glColor4ubv", (GLADapiproc) glad_glColor4ubv, 1, v);
    
}
PFNGLCOLOR4UBVPROC glad_debug_glColor4ubv = glad_debug_impl_glColor4ubv;
PFNGLCOLOR4UIPROC glad_glColor4ui = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
    _pre_call_gl_callback("glColor4ui", (GLADapiproc) glad_glColor4ui, 4, red, green, blue, alpha);
    glad_glColor4ui(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glColor4ui", (GLADapiproc) glad_glColor4ui, 4, red, green, blue, alpha);
    
}
PFNGLCOLOR4UIPROC glad_debug_glColor4ui = glad_debug_impl_glColor4ui;
PFNGLCOLOR4UIVPROC glad_glColor4uiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4uiv(const GLuint * v) {
    _pre_call_gl_callback("glColor4uiv", (GLADapiproc) glad_glColor4uiv, 1, v);
    glad_glColor4uiv(v);
    _post_call_gl_callback(NULL, "glColor4uiv", (GLADapiproc) glad_glColor4uiv, 1, v);
    
}
PFNGLCOLOR4UIVPROC glad_debug_glColor4uiv = glad_debug_impl_glColor4uiv;
PFNGLCOLOR4USPROC glad_glColor4us = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
    _pre_call_gl_callback("glColor4us", (GLADapiproc) glad_glColor4us, 4, red, green, blue, alpha);
    glad_glColor4us(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glColor4us", (GLADapiproc) glad_glColor4us, 4, red, green, blue, alpha);
    
}
PFNGLCOLOR4USPROC glad_debug_glColor4us = glad_debug_impl_glColor4us;
PFNGLCOLOR4USVPROC glad_glColor4usv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColor4usv(const GLushort * v) {
    _pre_call_gl_callback("glColor4usv", (GLADapiproc) glad_glColor4usv, 1, v);
    glad_glColor4usv(v);
    _post_call_gl_callback(NULL, "glColor4usv", (GLADapiproc) glad_glColor4usv, 1, v);
    
}
PFNGLCOLOR4USVPROC glad_debug_glColor4usv = glad_debug_impl_glColor4usv;
PFNGLCOLORMASKPROC glad_glColorMask = NULL;
static void GLAD_API_PTR glad_debug_impl_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    _pre_call_gl_callback("glColorMask", (GLADapiproc) glad_glColorMask, 4, red, green, blue, alpha);
    glad_glColorMask(red, green, blue, alpha);
    _post_call_gl_callback(NULL, "glColorMask", (GLADapiproc) glad_glColorMask, 4, red, green, blue, alpha);
    
}
PFNGLCOLORMASKPROC glad_debug_glColorMask = glad_debug_impl_glColorMask;
PFNGLCOLORMATERIALPROC glad_glColorMaterial = NULL;
static void GLAD_API_PTR glad_debug_impl_glColorMaterial(GLenum face, GLenum mode) {
    _pre_call_gl_callback("glColorMaterial", (GLADapiproc) glad_glColorMaterial, 2, face, mode);
    glad_glColorMaterial(face, mode);
    _post_call_gl_callback(NULL, "glColorMaterial", (GLADapiproc) glad_glColorMaterial, 2, face, mode);
    
}
PFNGLCOLORMATERIALPROC glad_debug_glColorMaterial = glad_debug_impl_glColorMaterial;
PFNGLCOLORPOINTERPROC glad_glColorPointer = NULL;
static void GLAD_API_PTR glad_debug_impl_glColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glColorPointer", (GLADapiproc) glad_glColorPointer, 4, size, type, stride, pointer);
    glad_glColorPointer(size, type, stride, pointer);
    _post_call_gl_callback(NULL, "glColorPointer", (GLADapiproc) glad_glColorPointer, 4, size, type, stride, pointer);
    
}
PFNGLCOLORPOINTERPROC glad_debug_glColorPointer = glad_debug_impl_glColorPointer;
PFNGLCOLORPOINTEREXTPROC glad_glColorPointerEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer) {
    _pre_call_gl_callback("glColorPointerEXT", (GLADapiproc) glad_glColorPointerEXT, 5, size, type, stride, count, pointer);
    glad_glColorPointerEXT(size, type, stride, count, pointer);
    _post_call_gl_callback(NULL, "glColorPointerEXT", (GLADapiproc) glad_glColorPointerEXT, 5, size, type, stride, count, pointer);
    
}
PFNGLCOLORPOINTEREXTPROC glad_debug_glColorPointerEXT = glad_debug_impl_glColorPointerEXT;
PFNGLCOLORSUBTABLEPROC glad_glColorSubTable = NULL;
static void GLAD_API_PTR glad_debug_impl_glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void * data) {
    _pre_call_gl_callback("glColorSubTable", (GLADapiproc) glad_glColorSubTable, 6, target, start, count, format, type, data);
    glad_glColorSubTable(target, start, count, format, type, data);
    _post_call_gl_callback(NULL, "glColorSubTable", (GLADapiproc) glad_glColorSubTable, 6, target, start, count, format, type, data);
    
}
PFNGLCOLORSUBTABLEPROC glad_debug_glColorSubTable = glad_debug_impl_glColorSubTable;
PFNGLCOLORTABLEPROC glad_glColorTable = NULL;
static void GLAD_API_PTR glad_debug_impl_glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * table) {
    _pre_call_gl_callback("glColorTable", (GLADapiproc) glad_glColorTable, 6, target, internalformat, width, format, type, table);
    glad_glColorTable(target, internalformat, width, format, type, table);
    _post_call_gl_callback(NULL, "glColorTable", (GLADapiproc) glad_glColorTable, 6, target, internalformat, width, format, type, table);
    
}
PFNGLCOLORTABLEPROC glad_debug_glColorTable = glad_debug_impl_glColorTable;
PFNGLCOLORTABLEPARAMETERFVPROC glad_glColorTableParameterfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glColorTableParameterfv", (GLADapiproc) glad_glColorTableParameterfv, 3, target, pname, params);
    glad_glColorTableParameterfv(target, pname, params);
    _post_call_gl_callback(NULL, "glColorTableParameterfv", (GLADapiproc) glad_glColorTableParameterfv, 3, target, pname, params);
    
}
PFNGLCOLORTABLEPARAMETERFVPROC glad_debug_glColorTableParameterfv = glad_debug_impl_glColorTableParameterfv;
PFNGLCOLORTABLEPARAMETERIVPROC glad_glColorTableParameteriv = NULL;
static void GLAD_API_PTR glad_debug_impl_glColorTableParameteriv(GLenum target, GLenum pname, const GLint * params) {
    _pre_call_gl_callback("glColorTableParameteriv", (GLADapiproc) glad_glColorTableParameteriv, 3, target, pname, params);
    glad_glColorTableParameteriv(target, pname, params);
    _post_call_gl_callback(NULL, "glColorTableParameteriv", (GLADapiproc) glad_glColorTableParameteriv, 3, target, pname, params);
    
}
PFNGLCOLORTABLEPARAMETERIVPROC glad_debug_glColorTableParameteriv = glad_debug_impl_glColorTableParameteriv;
PFNGLCOMPILESHADERPROC glad_glCompileShader = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompileShader(GLuint shader) {
    _pre_call_gl_callback("glCompileShader", (GLADapiproc) glad_glCompileShader, 1, shader);
    glad_glCompileShader(shader);
    _post_call_gl_callback(NULL, "glCompileShader", (GLADapiproc) glad_glCompileShader, 1, shader);
    
}
PFNGLCOMPILESHADERPROC glad_debug_glCompileShader = glad_debug_impl_glCompileShader;
PFNGLCOMPILESHADERARBPROC glad_glCompileShaderARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompileShaderARB(GLhandleARB shaderObj) {
    _pre_call_gl_callback("glCompileShaderARB", (GLADapiproc) glad_glCompileShaderARB, 1, shaderObj);
    glad_glCompileShaderARB(shaderObj);
    _post_call_gl_callback(NULL, "glCompileShaderARB", (GLADapiproc) glad_glCompileShaderARB, 1, shaderObj);
    
}
PFNGLCOMPILESHADERARBPROC glad_debug_glCompileShaderARB = glad_debug_impl_glCompileShaderARB;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glad_glCompressedTexImage1D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data) {
    _pre_call_gl_callback("glCompressedTexImage1D", (GLADapiproc) glad_glCompressedTexImage1D, 7, target, level, internalformat, width, border, imageSize, data);
    glad_glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);
    _post_call_gl_callback(NULL, "glCompressedTexImage1D", (GLADapiproc) glad_glCompressedTexImage1D, 7, target, level, internalformat, width, border, imageSize, data);
    
}
PFNGLCOMPRESSEDTEXIMAGE1DPROC glad_debug_glCompressedTexImage1D = glad_debug_impl_glCompressedTexImage1D;
PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glad_glCompressedTexImage1DARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data) {
    _pre_call_gl_callback("glCompressedTexImage1DARB", (GLADapiproc) glad_glCompressedTexImage1DARB, 7, target, level, internalformat, width, border, imageSize, data);
    glad_glCompressedTexImage1DARB(target, level, internalformat, width, border, imageSize, data);
    _post_call_gl_callback(NULL, "glCompressedTexImage1DARB", (GLADapiproc) glad_glCompressedTexImage1DARB, 7, target, level, internalformat, width, border, imageSize, data);
    
}
PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glad_debug_glCompressedTexImage1DARB = glad_debug_impl_glCompressedTexImage1DARB;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_glCompressedTexImage2D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) {
    _pre_call_gl_callback("glCompressedTexImage2D", (GLADapiproc) glad_glCompressedTexImage2D, 8, target, level, internalformat, width, height, border, imageSize, data);
    glad_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
    _post_call_gl_callback(NULL, "glCompressedTexImage2D", (GLADapiproc) glad_glCompressedTexImage2D, 8, target, level, internalformat, width, height, border, imageSize, data);
    
}
PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_debug_glCompressedTexImage2D = glad_debug_impl_glCompressedTexImage2D;
PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glad_glCompressedTexImage2DARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) {
    _pre_call_gl_callback("glCompressedTexImage2DARB", (GLADapiproc) glad_glCompressedTexImage2DARB, 8, target, level, internalformat, width, height, border, imageSize, data);
    glad_glCompressedTexImage2DARB(target, level, internalformat, width, height, border, imageSize, data);
    _post_call_gl_callback(NULL, "glCompressedTexImage2DARB", (GLADapiproc) glad_glCompressedTexImage2DARB, 8, target, level, internalformat, width, height, border, imageSize, data);
    
}
PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glad_debug_glCompressedTexImage2DARB = glad_debug_impl_glCompressedTexImage2DARB;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_glCompressedTexImage3D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) {
    _pre_call_gl_callback("glCompressedTexImage3D", (GLADapiproc) glad_glCompressedTexImage3D, 9, target, level, internalformat, width, height, depth, border, imageSize, data);
    glad_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
    _post_call_gl_callback(NULL, "glCompressedTexImage3D", (GLADapiproc) glad_glCompressedTexImage3D, 9, target, level, internalformat, width, height, depth, border, imageSize, data);
    
}
PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_debug_glCompressedTexImage3D = glad_debug_impl_glCompressedTexImage3D;
PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glad_glCompressedTexImage3DARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) {
    _pre_call_gl_callback("glCompressedTexImage3DARB", (GLADapiproc) glad_glCompressedTexImage3DARB, 9, target, level, internalformat, width, height, depth, border, imageSize, data);
    glad_glCompressedTexImage3DARB(target, level, internalformat, width, height, depth, border, imageSize, data);
    _post_call_gl_callback(NULL, "glCompressedTexImage3DARB", (GLADapiproc) glad_glCompressedTexImage3DARB, 9, target, level, internalformat, width, height, depth, border, imageSize, data);
    
}
PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glad_debug_glCompressedTexImage3DARB = glad_debug_impl_glCompressedTexImage3DARB;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glad_glCompressedTexSubImage1D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) {
    _pre_call_gl_callback("glCompressedTexSubImage1D", (GLADapiproc) glad_glCompressedTexSubImage1D, 7, target, level, xoffset, width, format, imageSize, data);
    glad_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
    _post_call_gl_callback(NULL, "glCompressedTexSubImage1D", (GLADapiproc) glad_glCompressedTexSubImage1D, 7, target, level, xoffset, width, format, imageSize, data);
    
}
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glad_debug_glCompressedTexSubImage1D = glad_debug_impl_glCompressedTexSubImage1D;
PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glad_glCompressedTexSubImage1DARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) {
    _pre_call_gl_callback("glCompressedTexSubImage1DARB", (GLADapiproc) glad_glCompressedTexSubImage1DARB, 7, target, level, xoffset, width, format, imageSize, data);
    glad_glCompressedTexSubImage1DARB(target, level, xoffset, width, format, imageSize, data);
    _post_call_gl_callback(NULL, "glCompressedTexSubImage1DARB", (GLADapiproc) glad_glCompressedTexSubImage1DARB, 7, target, level, xoffset, width, format, imageSize, data);
    
}
PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glad_debug_glCompressedTexSubImage1DARB = glad_debug_impl_glCompressedTexSubImage1DARB;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_glCompressedTexSubImage2D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
    _pre_call_gl_callback("glCompressedTexSubImage2D", (GLADapiproc) glad_glCompressedTexSubImage2D, 9, target, level, xoffset, yoffset, width, height, format, imageSize, data);
    glad_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
    _post_call_gl_callback(NULL, "glCompressedTexSubImage2D", (GLADapiproc) glad_glCompressedTexSubImage2D, 9, target, level, xoffset, yoffset, width, height, format, imageSize, data);
    
}
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_debug_glCompressedTexSubImage2D = glad_debug_impl_glCompressedTexSubImage2D;
PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glad_glCompressedTexSubImage2DARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
    _pre_call_gl_callback("glCompressedTexSubImage2DARB", (GLADapiproc) glad_glCompressedTexSubImage2DARB, 9, target, level, xoffset, yoffset, width, height, format, imageSize, data);
    glad_glCompressedTexSubImage2DARB(target, level, xoffset, yoffset, width, height, format, imageSize, data);
    _post_call_gl_callback(NULL, "glCompressedTexSubImage2DARB", (GLADapiproc) glad_glCompressedTexSubImage2DARB, 9, target, level, xoffset, yoffset, width, height, format, imageSize, data);
    
}
PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glad_debug_glCompressedTexSubImage2DARB = glad_debug_impl_glCompressedTexSubImage2DARB;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_glCompressedTexSubImage3D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
    _pre_call_gl_callback("glCompressedTexSubImage3D", (GLADapiproc) glad_glCompressedTexSubImage3D, 11, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
    glad_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
    _post_call_gl_callback(NULL, "glCompressedTexSubImage3D", (GLADapiproc) glad_glCompressedTexSubImage3D, 11, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
    
}
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_debug_glCompressedTexSubImage3D = glad_debug_impl_glCompressedTexSubImage3D;
PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glad_glCompressedTexSubImage3DARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
    _pre_call_gl_callback("glCompressedTexSubImage3DARB", (GLADapiproc) glad_glCompressedTexSubImage3DARB, 11, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
    glad_glCompressedTexSubImage3DARB(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
    _post_call_gl_callback(NULL, "glCompressedTexSubImage3DARB", (GLADapiproc) glad_glCompressedTexSubImage3DARB, 11, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
    
}
PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glad_debug_glCompressedTexSubImage3DARB = glad_debug_impl_glCompressedTexSubImage3DARB;
PFNGLCONVOLUTIONFILTER1DPROC glad_glConvolutionFilter1D = NULL;
static void GLAD_API_PTR glad_debug_impl_glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * image) {
    _pre_call_gl_callback("glConvolutionFilter1D", (GLADapiproc) glad_glConvolutionFilter1D, 6, target, internalformat, width, format, type, image);
    glad_glConvolutionFilter1D(target, internalformat, width, format, type, image);
    _post_call_gl_callback(NULL, "glConvolutionFilter1D", (GLADapiproc) glad_glConvolutionFilter1D, 6, target, internalformat, width, format, type, image);
    
}
PFNGLCONVOLUTIONFILTER1DPROC glad_debug_glConvolutionFilter1D = glad_debug_impl_glConvolutionFilter1D;
PFNGLCONVOLUTIONFILTER2DPROC glad_glConvolutionFilter2D = NULL;
static void GLAD_API_PTR glad_debug_impl_glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * image) {
    _pre_call_gl_callback("glConvolutionFilter2D", (GLADapiproc) glad_glConvolutionFilter2D, 7, target, internalformat, width, height, format, type, image);
    glad_glConvolutionFilter2D(target, internalformat, width, height, format, type, image);
    _post_call_gl_callback(NULL, "glConvolutionFilter2D", (GLADapiproc) glad_glConvolutionFilter2D, 7, target, internalformat, width, height, format, type, image);
    
}
PFNGLCONVOLUTIONFILTER2DPROC glad_debug_glConvolutionFilter2D = glad_debug_impl_glConvolutionFilter2D;
PFNGLCONVOLUTIONPARAMETERFPROC glad_glConvolutionParameterf = NULL;
static void GLAD_API_PTR glad_debug_impl_glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params) {
    _pre_call_gl_callback("glConvolutionParameterf", (GLADapiproc) glad_glConvolutionParameterf, 3, target, pname, params);
    glad_glConvolutionParameterf(target, pname, params);
    _post_call_gl_callback(NULL, "glConvolutionParameterf", (GLADapiproc) glad_glConvolutionParameterf, 3, target, pname, params);
    
}
PFNGLCONVOLUTIONPARAMETERFPROC glad_debug_glConvolutionParameterf = glad_debug_impl_glConvolutionParameterf;
PFNGLCONVOLUTIONPARAMETERFVPROC glad_glConvolutionParameterfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glConvolutionParameterfv", (GLADapiproc) glad_glConvolutionParameterfv, 3, target, pname, params);
    glad_glConvolutionParameterfv(target, pname, params);
    _post_call_gl_callback(NULL, "glConvolutionParameterfv", (GLADapiproc) glad_glConvolutionParameterfv, 3, target, pname, params);
    
}
PFNGLCONVOLUTIONPARAMETERFVPROC glad_debug_glConvolutionParameterfv = glad_debug_impl_glConvolutionParameterfv;
PFNGLCONVOLUTIONPARAMETERIPROC glad_glConvolutionParameteri = NULL;
static void GLAD_API_PTR glad_debug_impl_glConvolutionParameteri(GLenum target, GLenum pname, GLint params) {
    _pre_call_gl_callback("glConvolutionParameteri", (GLADapiproc) glad_glConvolutionParameteri, 3, target, pname, params);
    glad_glConvolutionParameteri(target, pname, params);
    _post_call_gl_callback(NULL, "glConvolutionParameteri", (GLADapiproc) glad_glConvolutionParameteri, 3, target, pname, params);
    
}
PFNGLCONVOLUTIONPARAMETERIPROC glad_debug_glConvolutionParameteri = glad_debug_impl_glConvolutionParameteri;
PFNGLCONVOLUTIONPARAMETERIVPROC glad_glConvolutionParameteriv = NULL;
static void GLAD_API_PTR glad_debug_impl_glConvolutionParameteriv(GLenum target, GLenum pname, const GLint * params) {
    _pre_call_gl_callback("glConvolutionParameteriv", (GLADapiproc) glad_glConvolutionParameteriv, 3, target, pname, params);
    glad_glConvolutionParameteriv(target, pname, params);
    _post_call_gl_callback(NULL, "glConvolutionParameteriv", (GLADapiproc) glad_glConvolutionParameteriv, 3, target, pname, params);
    
}
PFNGLCONVOLUTIONPARAMETERIVPROC glad_debug_glConvolutionParameteriv = glad_debug_impl_glConvolutionParameteriv;
PFNGLCOPYCOLORSUBTABLEPROC glad_glCopyColorSubTable = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
    _pre_call_gl_callback("glCopyColorSubTable", (GLADapiproc) glad_glCopyColorSubTable, 5, target, start, x, y, width);
    glad_glCopyColorSubTable(target, start, x, y, width);
    _post_call_gl_callback(NULL, "glCopyColorSubTable", (GLADapiproc) glad_glCopyColorSubTable, 5, target, start, x, y, width);
    
}
PFNGLCOPYCOLORSUBTABLEPROC glad_debug_glCopyColorSubTable = glad_debug_impl_glCopyColorSubTable;
PFNGLCOPYCOLORTABLEPROC glad_glCopyColorTable = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    _pre_call_gl_callback("glCopyColorTable", (GLADapiproc) glad_glCopyColorTable, 5, target, internalformat, x, y, width);
    glad_glCopyColorTable(target, internalformat, x, y, width);
    _post_call_gl_callback(NULL, "glCopyColorTable", (GLADapiproc) glad_glCopyColorTable, 5, target, internalformat, x, y, width);
    
}
PFNGLCOPYCOLORTABLEPROC glad_debug_glCopyColorTable = glad_debug_impl_glCopyColorTable;
PFNGLCOPYCONVOLUTIONFILTER1DPROC glad_glCopyConvolutionFilter1D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    _pre_call_gl_callback("glCopyConvolutionFilter1D", (GLADapiproc) glad_glCopyConvolutionFilter1D, 5, target, internalformat, x, y, width);
    glad_glCopyConvolutionFilter1D(target, internalformat, x, y, width);
    _post_call_gl_callback(NULL, "glCopyConvolutionFilter1D", (GLADapiproc) glad_glCopyConvolutionFilter1D, 5, target, internalformat, x, y, width);
    
}
PFNGLCOPYCONVOLUTIONFILTER1DPROC glad_debug_glCopyConvolutionFilter1D = glad_debug_impl_glCopyConvolutionFilter1D;
PFNGLCOPYCONVOLUTIONFILTER2DPROC glad_glCopyConvolutionFilter2D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
    _pre_call_gl_callback("glCopyConvolutionFilter2D", (GLADapiproc) glad_glCopyConvolutionFilter2D, 6, target, internalformat, x, y, width, height);
    glad_glCopyConvolutionFilter2D(target, internalformat, x, y, width, height);
    _post_call_gl_callback(NULL, "glCopyConvolutionFilter2D", (GLADapiproc) glad_glCopyConvolutionFilter2D, 6, target, internalformat, x, y, width, height);
    
}
PFNGLCOPYCONVOLUTIONFILTER2DPROC glad_debug_glCopyConvolutionFilter2D = glad_debug_impl_glCopyConvolutionFilter2D;
PFNGLCOPYPIXELSPROC glad_glCopyPixels = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {
    _pre_call_gl_callback("glCopyPixels", (GLADapiproc) glad_glCopyPixels, 5, x, y, width, height, type);
    glad_glCopyPixels(x, y, width, height, type);
    _post_call_gl_callback(NULL, "glCopyPixels", (GLADapiproc) glad_glCopyPixels, 5, x, y, width, height, type);
    
}
PFNGLCOPYPIXELSPROC glad_debug_glCopyPixels = glad_debug_impl_glCopyPixels;
PFNGLCOPYTEXIMAGE1DPROC glad_glCopyTexImage1D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    _pre_call_gl_callback("glCopyTexImage1D", (GLADapiproc) glad_glCopyTexImage1D, 7, target, level, internalformat, x, y, width, border);
    glad_glCopyTexImage1D(target, level, internalformat, x, y, width, border);
    _post_call_gl_callback(NULL, "glCopyTexImage1D", (GLADapiproc) glad_glCopyTexImage1D, 7, target, level, internalformat, x, y, width, border);
    
}
PFNGLCOPYTEXIMAGE1DPROC glad_debug_glCopyTexImage1D = glad_debug_impl_glCopyTexImage1D;
PFNGLCOPYTEXIMAGE1DEXTPROC glad_glCopyTexImage1DEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    _pre_call_gl_callback("glCopyTexImage1DEXT", (GLADapiproc) glad_glCopyTexImage1DEXT, 7, target, level, internalformat, x, y, width, border);
    glad_glCopyTexImage1DEXT(target, level, internalformat, x, y, width, border);
    _post_call_gl_callback(NULL, "glCopyTexImage1DEXT", (GLADapiproc) glad_glCopyTexImage1DEXT, 7, target, level, internalformat, x, y, width, border);
    
}
PFNGLCOPYTEXIMAGE1DEXTPROC glad_debug_glCopyTexImage1DEXT = glad_debug_impl_glCopyTexImage1DEXT;
PFNGLCOPYTEXIMAGE2DPROC glad_glCopyTexImage2D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    _pre_call_gl_callback("glCopyTexImage2D", (GLADapiproc) glad_glCopyTexImage2D, 8, target, level, internalformat, x, y, width, height, border);
    glad_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
    _post_call_gl_callback(NULL, "glCopyTexImage2D", (GLADapiproc) glad_glCopyTexImage2D, 8, target, level, internalformat, x, y, width, height, border);
    
}
PFNGLCOPYTEXIMAGE2DPROC glad_debug_glCopyTexImage2D = glad_debug_impl_glCopyTexImage2D;
PFNGLCOPYTEXIMAGE2DEXTPROC glad_glCopyTexImage2DEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    _pre_call_gl_callback("glCopyTexImage2DEXT", (GLADapiproc) glad_glCopyTexImage2DEXT, 8, target, level, internalformat, x, y, width, height, border);
    glad_glCopyTexImage2DEXT(target, level, internalformat, x, y, width, height, border);
    _post_call_gl_callback(NULL, "glCopyTexImage2DEXT", (GLADapiproc) glad_glCopyTexImage2DEXT, 8, target, level, internalformat, x, y, width, height, border);
    
}
PFNGLCOPYTEXIMAGE2DEXTPROC glad_debug_glCopyTexImage2DEXT = glad_debug_impl_glCopyTexImage2DEXT;
PFNGLCOPYTEXSUBIMAGE1DPROC glad_glCopyTexSubImage1D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    _pre_call_gl_callback("glCopyTexSubImage1D", (GLADapiproc) glad_glCopyTexSubImage1D, 6, target, level, xoffset, x, y, width);
    glad_glCopyTexSubImage1D(target, level, xoffset, x, y, width);
    _post_call_gl_callback(NULL, "glCopyTexSubImage1D", (GLADapiproc) glad_glCopyTexSubImage1D, 6, target, level, xoffset, x, y, width);
    
}
PFNGLCOPYTEXSUBIMAGE1DPROC glad_debug_glCopyTexSubImage1D = glad_debug_impl_glCopyTexSubImage1D;
PFNGLCOPYTEXSUBIMAGE1DEXTPROC glad_glCopyTexSubImage1DEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    _pre_call_gl_callback("glCopyTexSubImage1DEXT", (GLADapiproc) glad_glCopyTexSubImage1DEXT, 6, target, level, xoffset, x, y, width);
    glad_glCopyTexSubImage1DEXT(target, level, xoffset, x, y, width);
    _post_call_gl_callback(NULL, "glCopyTexSubImage1DEXT", (GLADapiproc) glad_glCopyTexSubImage1DEXT, 6, target, level, xoffset, x, y, width);
    
}
PFNGLCOPYTEXSUBIMAGE1DEXTPROC glad_debug_glCopyTexSubImage1DEXT = glad_debug_impl_glCopyTexSubImage1DEXT;
PFNGLCOPYTEXSUBIMAGE2DPROC glad_glCopyTexSubImage2D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    _pre_call_gl_callback("glCopyTexSubImage2D", (GLADapiproc) glad_glCopyTexSubImage2D, 8, target, level, xoffset, yoffset, x, y, width, height);
    glad_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
    _post_call_gl_callback(NULL, "glCopyTexSubImage2D", (GLADapiproc) glad_glCopyTexSubImage2D, 8, target, level, xoffset, yoffset, x, y, width, height);
    
}
PFNGLCOPYTEXSUBIMAGE2DPROC glad_debug_glCopyTexSubImage2D = glad_debug_impl_glCopyTexSubImage2D;
PFNGLCOPYTEXSUBIMAGE2DEXTPROC glad_glCopyTexSubImage2DEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    _pre_call_gl_callback("glCopyTexSubImage2DEXT", (GLADapiproc) glad_glCopyTexSubImage2DEXT, 8, target, level, xoffset, yoffset, x, y, width, height);
    glad_glCopyTexSubImage2DEXT(target, level, xoffset, yoffset, x, y, width, height);
    _post_call_gl_callback(NULL, "glCopyTexSubImage2DEXT", (GLADapiproc) glad_glCopyTexSubImage2DEXT, 8, target, level, xoffset, yoffset, x, y, width, height);
    
}
PFNGLCOPYTEXSUBIMAGE2DEXTPROC glad_debug_glCopyTexSubImage2DEXT = glad_debug_impl_glCopyTexSubImage2DEXT;
PFNGLCOPYTEXSUBIMAGE3DPROC glad_glCopyTexSubImage3D = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    _pre_call_gl_callback("glCopyTexSubImage3D", (GLADapiproc) glad_glCopyTexSubImage3D, 9, target, level, xoffset, yoffset, zoffset, x, y, width, height);
    glad_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
    _post_call_gl_callback(NULL, "glCopyTexSubImage3D", (GLADapiproc) glad_glCopyTexSubImage3D, 9, target, level, xoffset, yoffset, zoffset, x, y, width, height);
    
}
PFNGLCOPYTEXSUBIMAGE3DPROC glad_debug_glCopyTexSubImage3D = glad_debug_impl_glCopyTexSubImage3D;
PFNGLCOPYTEXSUBIMAGE3DEXTPROC glad_glCopyTexSubImage3DEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    _pre_call_gl_callback("glCopyTexSubImage3DEXT", (GLADapiproc) glad_glCopyTexSubImage3DEXT, 9, target, level, xoffset, yoffset, zoffset, x, y, width, height);
    glad_glCopyTexSubImage3DEXT(target, level, xoffset, yoffset, zoffset, x, y, width, height);
    _post_call_gl_callback(NULL, "glCopyTexSubImage3DEXT", (GLADapiproc) glad_glCopyTexSubImage3DEXT, 9, target, level, xoffset, yoffset, zoffset, x, y, width, height);
    
}
PFNGLCOPYTEXSUBIMAGE3DEXTPROC glad_debug_glCopyTexSubImage3DEXT = glad_debug_impl_glCopyTexSubImage3DEXT;
PFNGLCREATEPROGRAMPROC glad_glCreateProgram = NULL;
static GLuint GLAD_API_PTR glad_debug_impl_glCreateProgram(void) {
    GLuint ret;
    _pre_call_gl_callback("glCreateProgram", (GLADapiproc) glad_glCreateProgram, 0);
    ret = glad_glCreateProgram();
    _post_call_gl_callback((void*) &ret, "glCreateProgram", (GLADapiproc) glad_glCreateProgram, 0);
    return ret;
}
PFNGLCREATEPROGRAMPROC glad_debug_glCreateProgram = glad_debug_impl_glCreateProgram;
PFNGLCREATEPROGRAMOBJECTARBPROC glad_glCreateProgramObjectARB = NULL;
static GLhandleARB GLAD_API_PTR glad_debug_impl_glCreateProgramObjectARB(void) {
    GLhandleARB ret;
    _pre_call_gl_callback("glCreateProgramObjectARB", (GLADapiproc) glad_glCreateProgramObjectARB, 0);
    ret = glad_glCreateProgramObjectARB();
    _post_call_gl_callback((void*) &ret, "glCreateProgramObjectARB", (GLADapiproc) glad_glCreateProgramObjectARB, 0);
    return ret;
}
PFNGLCREATEPROGRAMOBJECTARBPROC glad_debug_glCreateProgramObjectARB = glad_debug_impl_glCreateProgramObjectARB;
PFNGLCREATESHADERPROC glad_glCreateShader = NULL;
static GLuint GLAD_API_PTR glad_debug_impl_glCreateShader(GLenum type) {
    GLuint ret;
    _pre_call_gl_callback("glCreateShader", (GLADapiproc) glad_glCreateShader, 1, type);
    ret = glad_glCreateShader(type);
    _post_call_gl_callback((void*) &ret, "glCreateShader", (GLADapiproc) glad_glCreateShader, 1, type);
    return ret;
}
PFNGLCREATESHADERPROC glad_debug_glCreateShader = glad_debug_impl_glCreateShader;
PFNGLCREATESHADEROBJECTARBPROC glad_glCreateShaderObjectARB = NULL;
static GLhandleARB GLAD_API_PTR glad_debug_impl_glCreateShaderObjectARB(GLenum shaderType) {
    GLhandleARB ret;
    _pre_call_gl_callback("glCreateShaderObjectARB", (GLADapiproc) glad_glCreateShaderObjectARB, 1, shaderType);
    ret = glad_glCreateShaderObjectARB(shaderType);
    _post_call_gl_callback((void*) &ret, "glCreateShaderObjectARB", (GLADapiproc) glad_glCreateShaderObjectARB, 1, shaderType);
    return ret;
}
PFNGLCREATESHADEROBJECTARBPROC glad_debug_glCreateShaderObjectARB = glad_debug_impl_glCreateShaderObjectARB;
PFNGLCULLFACEPROC glad_glCullFace = NULL;
static void GLAD_API_PTR glad_debug_impl_glCullFace(GLenum mode) {
    _pre_call_gl_callback("glCullFace", (GLADapiproc) glad_glCullFace, 1, mode);
    glad_glCullFace(mode);
    _post_call_gl_callback(NULL, "glCullFace", (GLADapiproc) glad_glCullFace, 1, mode);
    
}
PFNGLCULLFACEPROC glad_debug_glCullFace = glad_debug_impl_glCullFace;
PFNGLDEBUGMESSAGECALLBACKPROC glad_glDebugMessageCallback = NULL;
static void GLAD_API_PTR glad_debug_impl_glDebugMessageCallback(GLDEBUGPROC callback, const void * userParam) {
    _pre_call_gl_callback("glDebugMessageCallback", (GLADapiproc) glad_glDebugMessageCallback, 2, callback, userParam);
    glad_glDebugMessageCallback(callback, userParam);
    _post_call_gl_callback(NULL, "glDebugMessageCallback", (GLADapiproc) glad_glDebugMessageCallback, 2, callback, userParam);
    
}
PFNGLDEBUGMESSAGECALLBACKPROC glad_debug_glDebugMessageCallback = glad_debug_impl_glDebugMessageCallback;
PFNGLDEBUGMESSAGECONTROLPROC glad_glDebugMessageControl = NULL;
static void GLAD_API_PTR glad_debug_impl_glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled) {
    _pre_call_gl_callback("glDebugMessageControl", (GLADapiproc) glad_glDebugMessageControl, 6, source, type, severity, count, ids, enabled);
    glad_glDebugMessageControl(source, type, severity, count, ids, enabled);
    _post_call_gl_callback(NULL, "glDebugMessageControl", (GLADapiproc) glad_glDebugMessageControl, 6, source, type, severity, count, ids, enabled);
    
}
PFNGLDEBUGMESSAGECONTROLPROC glad_debug_glDebugMessageControl = glad_debug_impl_glDebugMessageControl;
PFNGLDEBUGMESSAGEINSERTPROC glad_glDebugMessageInsert = NULL;
static void GLAD_API_PTR glad_debug_impl_glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf) {
    _pre_call_gl_callback("glDebugMessageInsert", (GLADapiproc) glad_glDebugMessageInsert, 6, source, type, id, severity, length, buf);
    glad_glDebugMessageInsert(source, type, id, severity, length, buf);
    _post_call_gl_callback(NULL, "glDebugMessageInsert", (GLADapiproc) glad_glDebugMessageInsert, 6, source, type, id, severity, length, buf);
    
}
PFNGLDEBUGMESSAGEINSERTPROC glad_debug_glDebugMessageInsert = glad_debug_impl_glDebugMessageInsert;
PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers = NULL;
static void GLAD_API_PTR glad_debug_impl_glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    _pre_call_gl_callback("glDeleteBuffers", (GLADapiproc) glad_glDeleteBuffers, 2, n, buffers);
    glad_glDeleteBuffers(n, buffers);
    _post_call_gl_callback(NULL, "glDeleteBuffers", (GLADapiproc) glad_glDeleteBuffers, 2, n, buffers);
    
}
PFNGLDELETEBUFFERSPROC glad_debug_glDeleteBuffers = glad_debug_impl_glDeleteBuffers;
PFNGLDELETEBUFFERSARBPROC glad_glDeleteBuffersARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glDeleteBuffersARB(GLsizei n, const GLuint * buffers) {
    _pre_call_gl_callback("glDeleteBuffersARB", (GLADapiproc) glad_glDeleteBuffersARB, 2, n, buffers);
    glad_glDeleteBuffersARB(n, buffers);
    _post_call_gl_callback(NULL, "glDeleteBuffersARB", (GLADapiproc) glad_glDeleteBuffersARB, 2, n, buffers);
    
}
PFNGLDELETEBUFFERSARBPROC glad_debug_glDeleteBuffersARB = glad_debug_impl_glDeleteBuffersARB;
PFNGLDELETELISTSPROC glad_glDeleteLists = NULL;
static void GLAD_API_PTR glad_debug_impl_glDeleteLists(GLuint list, GLsizei range) {
    _pre_call_gl_callback("glDeleteLists", (GLADapiproc) glad_glDeleteLists, 2, list, range);
    glad_glDeleteLists(list, range);
    _post_call_gl_callback(NULL, "glDeleteLists", (GLADapiproc) glad_glDeleteLists, 2, list, range);
    
}
PFNGLDELETELISTSPROC glad_debug_glDeleteLists = glad_debug_impl_glDeleteLists;
PFNGLDELETEOBJECTARBPROC glad_glDeleteObjectARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glDeleteObjectARB(GLhandleARB obj) {
    _pre_call_gl_callback("glDeleteObjectARB", (GLADapiproc) glad_glDeleteObjectARB, 1, obj);
    glad_glDeleteObjectARB(obj);
    _post_call_gl_callback(NULL, "glDeleteObjectARB", (GLADapiproc) glad_glDeleteObjectARB, 1, obj);
    
}
PFNGLDELETEOBJECTARBPROC glad_debug_glDeleteObjectARB = glad_debug_impl_glDeleteObjectARB;
PFNGLDELETEPROGRAMPROC glad_glDeleteProgram = NULL;
static void GLAD_API_PTR glad_debug_impl_glDeleteProgram(GLuint program) {
    _pre_call_gl_callback("glDeleteProgram", (GLADapiproc) glad_glDeleteProgram, 1, program);
    glad_glDeleteProgram(program);
    _post_call_gl_callback(NULL, "glDeleteProgram", (GLADapiproc) glad_glDeleteProgram, 1, program);
    
}
PFNGLDELETEPROGRAMPROC glad_debug_glDeleteProgram = glad_debug_impl_glDeleteProgram;
PFNGLDELETEPROGRAMSARBPROC glad_glDeleteProgramsARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glDeleteProgramsARB(GLsizei n, const GLuint * programs) {
    _pre_call_gl_callback("glDeleteProgramsARB", (GLADapiproc) glad_glDeleteProgramsARB, 2, n, programs);
    glad_glDeleteProgramsARB(n, programs);
    _post_call_gl_callback(NULL, "glDeleteProgramsARB", (GLADapiproc) glad_glDeleteProgramsARB, 2, n, programs);
    
}
PFNGLDELETEPROGRAMSARBPROC glad_debug_glDeleteProgramsARB = glad_debug_impl_glDeleteProgramsARB;
PFNGLDELETEPROGRAMSNVPROC glad_glDeleteProgramsNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glDeleteProgramsNV(GLsizei n, const GLuint * programs) {
    _pre_call_gl_callback("glDeleteProgramsNV", (GLADapiproc) glad_glDeleteProgramsNV, 2, n, programs);
    glad_glDeleteProgramsNV(n, programs);
    _post_call_gl_callback(NULL, "glDeleteProgramsNV", (GLADapiproc) glad_glDeleteProgramsNV, 2, n, programs);
    
}
PFNGLDELETEPROGRAMSNVPROC glad_debug_glDeleteProgramsNV = glad_debug_impl_glDeleteProgramsNV;
PFNGLDELETEQUERIESPROC glad_glDeleteQueries = NULL;
static void GLAD_API_PTR glad_debug_impl_glDeleteQueries(GLsizei n, const GLuint * ids) {
    _pre_call_gl_callback("glDeleteQueries", (GLADapiproc) glad_glDeleteQueries, 2, n, ids);
    glad_glDeleteQueries(n, ids);
    _post_call_gl_callback(NULL, "glDeleteQueries", (GLADapiproc) glad_glDeleteQueries, 2, n, ids);
    
}
PFNGLDELETEQUERIESPROC glad_debug_glDeleteQueries = glad_debug_impl_glDeleteQueries;
PFNGLDELETEQUERIESARBPROC glad_glDeleteQueriesARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glDeleteQueriesARB(GLsizei n, const GLuint * ids) {
    _pre_call_gl_callback("glDeleteQueriesARB", (GLADapiproc) glad_glDeleteQueriesARB, 2, n, ids);
    glad_glDeleteQueriesARB(n, ids);
    _post_call_gl_callback(NULL, "glDeleteQueriesARB", (GLADapiproc) glad_glDeleteQueriesARB, 2, n, ids);
    
}
PFNGLDELETEQUERIESARBPROC glad_debug_glDeleteQueriesARB = glad_debug_impl_glDeleteQueriesARB;
PFNGLDELETESHADERPROC glad_glDeleteShader = NULL;
static void GLAD_API_PTR glad_debug_impl_glDeleteShader(GLuint shader) {
    _pre_call_gl_callback("glDeleteShader", (GLADapiproc) glad_glDeleteShader, 1, shader);
    glad_glDeleteShader(shader);
    _post_call_gl_callback(NULL, "glDeleteShader", (GLADapiproc) glad_glDeleteShader, 1, shader);
    
}
PFNGLDELETESHADERPROC glad_debug_glDeleteShader = glad_debug_impl_glDeleteShader;
PFNGLDELETETEXTURESPROC glad_glDeleteTextures = NULL;
static void GLAD_API_PTR glad_debug_impl_glDeleteTextures(GLsizei n, const GLuint * textures) {
    _pre_call_gl_callback("glDeleteTextures", (GLADapiproc) glad_glDeleteTextures, 2, n, textures);
    glad_glDeleteTextures(n, textures);
    _post_call_gl_callback(NULL, "glDeleteTextures", (GLADapiproc) glad_glDeleteTextures, 2, n, textures);
    
}
PFNGLDELETETEXTURESPROC glad_debug_glDeleteTextures = glad_debug_impl_glDeleteTextures;
PFNGLDELETETEXTURESEXTPROC glad_glDeleteTexturesEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glDeleteTexturesEXT(GLsizei n, const GLuint * textures) {
    _pre_call_gl_callback("glDeleteTexturesEXT", (GLADapiproc) glad_glDeleteTexturesEXT, 2, n, textures);
    glad_glDeleteTexturesEXT(n, textures);
    _post_call_gl_callback(NULL, "glDeleteTexturesEXT", (GLADapiproc) glad_glDeleteTexturesEXT, 2, n, textures);
    
}
PFNGLDELETETEXTURESEXTPROC glad_debug_glDeleteTexturesEXT = glad_debug_impl_glDeleteTexturesEXT;
PFNGLDEPTHFUNCPROC glad_glDepthFunc = NULL;
static void GLAD_API_PTR glad_debug_impl_glDepthFunc(GLenum func) {
    _pre_call_gl_callback("glDepthFunc", (GLADapiproc) glad_glDepthFunc, 1, func);
    glad_glDepthFunc(func);
    _post_call_gl_callback(NULL, "glDepthFunc", (GLADapiproc) glad_glDepthFunc, 1, func);
    
}
PFNGLDEPTHFUNCPROC glad_debug_glDepthFunc = glad_debug_impl_glDepthFunc;
PFNGLDEPTHMASKPROC glad_glDepthMask = NULL;
static void GLAD_API_PTR glad_debug_impl_glDepthMask(GLboolean flag) {
    _pre_call_gl_callback("glDepthMask", (GLADapiproc) glad_glDepthMask, 1, flag);
    glad_glDepthMask(flag);
    _post_call_gl_callback(NULL, "glDepthMask", (GLADapiproc) glad_glDepthMask, 1, flag);
    
}
PFNGLDEPTHMASKPROC glad_debug_glDepthMask = glad_debug_impl_glDepthMask;
PFNGLDEPTHRANGEPROC glad_glDepthRange = NULL;
static void GLAD_API_PTR glad_debug_impl_glDepthRange(GLdouble n, GLdouble f) {
    _pre_call_gl_callback("glDepthRange", (GLADapiproc) glad_glDepthRange, 2, n, f);
    glad_glDepthRange(n, f);
    _post_call_gl_callback(NULL, "glDepthRange", (GLADapiproc) glad_glDepthRange, 2, n, f);
    
}
PFNGLDEPTHRANGEPROC glad_debug_glDepthRange = glad_debug_impl_glDepthRange;
PFNGLDETACHOBJECTARBPROC glad_glDetachObjectARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj) {
    _pre_call_gl_callback("glDetachObjectARB", (GLADapiproc) glad_glDetachObjectARB, 2, containerObj, attachedObj);
    glad_glDetachObjectARB(containerObj, attachedObj);
    _post_call_gl_callback(NULL, "glDetachObjectARB", (GLADapiproc) glad_glDetachObjectARB, 2, containerObj, attachedObj);
    
}
PFNGLDETACHOBJECTARBPROC glad_debug_glDetachObjectARB = glad_debug_impl_glDetachObjectARB;
PFNGLDETACHSHADERPROC glad_glDetachShader = NULL;
static void GLAD_API_PTR glad_debug_impl_glDetachShader(GLuint program, GLuint shader) {
    _pre_call_gl_callback("glDetachShader", (GLADapiproc) glad_glDetachShader, 2, program, shader);
    glad_glDetachShader(program, shader);
    _post_call_gl_callback(NULL, "glDetachShader", (GLADapiproc) glad_glDetachShader, 2, program, shader);
    
}
PFNGLDETACHSHADERPROC glad_debug_glDetachShader = glad_debug_impl_glDetachShader;
PFNGLDISABLEPROC glad_glDisable = NULL;
static void GLAD_API_PTR glad_debug_impl_glDisable(GLenum cap) {
    _pre_call_gl_callback("glDisable", (GLADapiproc) glad_glDisable, 1, cap);
    glad_glDisable(cap);
    _post_call_gl_callback(NULL, "glDisable", (GLADapiproc) glad_glDisable, 1, cap);
    
}
PFNGLDISABLEPROC glad_debug_glDisable = glad_debug_impl_glDisable;
PFNGLDISABLECLIENTSTATEPROC glad_glDisableClientState = NULL;
static void GLAD_API_PTR glad_debug_impl_glDisableClientState(GLenum array) {
    _pre_call_gl_callback("glDisableClientState", (GLADapiproc) glad_glDisableClientState, 1, array);
    glad_glDisableClientState(array);
    _post_call_gl_callback(NULL, "glDisableClientState", (GLADapiproc) glad_glDisableClientState, 1, array);
    
}
PFNGLDISABLECLIENTSTATEPROC glad_debug_glDisableClientState = glad_debug_impl_glDisableClientState;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray = NULL;
static void GLAD_API_PTR glad_debug_impl_glDisableVertexAttribArray(GLuint index) {
    _pre_call_gl_callback("glDisableVertexAttribArray", (GLADapiproc) glad_glDisableVertexAttribArray, 1, index);
    glad_glDisableVertexAttribArray(index);
    _post_call_gl_callback(NULL, "glDisableVertexAttribArray", (GLADapiproc) glad_glDisableVertexAttribArray, 1, index);
    
}
PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_debug_glDisableVertexAttribArray = glad_debug_impl_glDisableVertexAttribArray;
PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glad_glDisableVertexAttribArrayARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glDisableVertexAttribArrayARB(GLuint index) {
    _pre_call_gl_callback("glDisableVertexAttribArrayARB", (GLADapiproc) glad_glDisableVertexAttribArrayARB, 1, index);
    glad_glDisableVertexAttribArrayARB(index);
    _post_call_gl_callback(NULL, "glDisableVertexAttribArrayARB", (GLADapiproc) glad_glDisableVertexAttribArrayARB, 1, index);
    
}
PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glad_debug_glDisableVertexAttribArrayARB = glad_debug_impl_glDisableVertexAttribArrayARB;
PFNGLDRAWARRAYSPROC glad_glDrawArrays = NULL;
static void GLAD_API_PTR glad_debug_impl_glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    _pre_call_gl_callback("glDrawArrays", (GLADapiproc) glad_glDrawArrays, 3, mode, first, count);
    glad_glDrawArrays(mode, first, count);
    _post_call_gl_callback(NULL, "glDrawArrays", (GLADapiproc) glad_glDrawArrays, 3, mode, first, count);
    
}
PFNGLDRAWARRAYSPROC glad_debug_glDrawArrays = glad_debug_impl_glDrawArrays;
PFNGLDRAWARRAYSEXTPROC glad_glDrawArraysEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glDrawArraysEXT(GLenum mode, GLint first, GLsizei count) {
    _pre_call_gl_callback("glDrawArraysEXT", (GLADapiproc) glad_glDrawArraysEXT, 3, mode, first, count);
    glad_glDrawArraysEXT(mode, first, count);
    _post_call_gl_callback(NULL, "glDrawArraysEXT", (GLADapiproc) glad_glDrawArraysEXT, 3, mode, first, count);
    
}
PFNGLDRAWARRAYSEXTPROC glad_debug_glDrawArraysEXT = glad_debug_impl_glDrawArraysEXT;
PFNGLDRAWBUFFERPROC glad_glDrawBuffer = NULL;
static void GLAD_API_PTR glad_debug_impl_glDrawBuffer(GLenum buf) {
    _pre_call_gl_callback("glDrawBuffer", (GLADapiproc) glad_glDrawBuffer, 1, buf);
    glad_glDrawBuffer(buf);
    _post_call_gl_callback(NULL, "glDrawBuffer", (GLADapiproc) glad_glDrawBuffer, 1, buf);
    
}
PFNGLDRAWBUFFERPROC glad_debug_glDrawBuffer = glad_debug_impl_glDrawBuffer;
PFNGLDRAWBUFFERSPROC glad_glDrawBuffers = NULL;
static void GLAD_API_PTR glad_debug_impl_glDrawBuffers(GLsizei n, const GLenum * bufs) {
    _pre_call_gl_callback("glDrawBuffers", (GLADapiproc) glad_glDrawBuffers, 2, n, bufs);
    glad_glDrawBuffers(n, bufs);
    _post_call_gl_callback(NULL, "glDrawBuffers", (GLADapiproc) glad_glDrawBuffers, 2, n, bufs);
    
}
PFNGLDRAWBUFFERSPROC glad_debug_glDrawBuffers = glad_debug_impl_glDrawBuffers;
PFNGLDRAWBUFFERSARBPROC glad_glDrawBuffersARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glDrawBuffersARB(GLsizei n, const GLenum * bufs) {
    _pre_call_gl_callback("glDrawBuffersARB", (GLADapiproc) glad_glDrawBuffersARB, 2, n, bufs);
    glad_glDrawBuffersARB(n, bufs);
    _post_call_gl_callback(NULL, "glDrawBuffersARB", (GLADapiproc) glad_glDrawBuffersARB, 2, n, bufs);
    
}
PFNGLDRAWBUFFERSARBPROC glad_debug_glDrawBuffersARB = glad_debug_impl_glDrawBuffersARB;
PFNGLDRAWBUFFERSATIPROC glad_glDrawBuffersATI = NULL;
static void GLAD_API_PTR glad_debug_impl_glDrawBuffersATI(GLsizei n, const GLenum * bufs) {
    _pre_call_gl_callback("glDrawBuffersATI", (GLADapiproc) glad_glDrawBuffersATI, 2, n, bufs);
    glad_glDrawBuffersATI(n, bufs);
    _post_call_gl_callback(NULL, "glDrawBuffersATI", (GLADapiproc) glad_glDrawBuffersATI, 2, n, bufs);
    
}
PFNGLDRAWBUFFERSATIPROC glad_debug_glDrawBuffersATI = glad_debug_impl_glDrawBuffersATI;
PFNGLDRAWELEMENTSPROC glad_glDrawElements = NULL;
static void GLAD_API_PTR glad_debug_impl_glDrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices) {
    _pre_call_gl_callback("glDrawElements", (GLADapiproc) glad_glDrawElements, 4, mode, count, type, indices);
    glad_glDrawElements(mode, count, type, indices);
    _post_call_gl_callback(NULL, "glDrawElements", (GLADapiproc) glad_glDrawElements, 4, mode, count, type, indices);
    
}
PFNGLDRAWELEMENTSPROC glad_debug_glDrawElements = glad_debug_impl_glDrawElements;
PFNGLDRAWPIXELSPROC glad_glDrawPixels = NULL;
static void GLAD_API_PTR glad_debug_impl_glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
    _pre_call_gl_callback("glDrawPixels", (GLADapiproc) glad_glDrawPixels, 5, width, height, format, type, pixels);
    glad_glDrawPixels(width, height, format, type, pixels);
    _post_call_gl_callback(NULL, "glDrawPixels", (GLADapiproc) glad_glDrawPixels, 5, width, height, format, type, pixels);
    
}
PFNGLDRAWPIXELSPROC glad_debug_glDrawPixels = glad_debug_impl_glDrawPixels;
PFNGLDRAWRANGEELEMENTSPROC glad_glDrawRangeElements = NULL;
static void GLAD_API_PTR glad_debug_impl_glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices) {
    _pre_call_gl_callback("glDrawRangeElements", (GLADapiproc) glad_glDrawRangeElements, 6, mode, start, end, count, type, indices);
    glad_glDrawRangeElements(mode, start, end, count, type, indices);
    _post_call_gl_callback(NULL, "glDrawRangeElements", (GLADapiproc) glad_glDrawRangeElements, 6, mode, start, end, count, type, indices);
    
}
PFNGLDRAWRANGEELEMENTSPROC glad_debug_glDrawRangeElements = glad_debug_impl_glDrawRangeElements;
PFNGLDRAWRANGEELEMENTSEXTPROC glad_glDrawRangeElementsEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices) {
    _pre_call_gl_callback("glDrawRangeElementsEXT", (GLADapiproc) glad_glDrawRangeElementsEXT, 6, mode, start, end, count, type, indices);
    glad_glDrawRangeElementsEXT(mode, start, end, count, type, indices);
    _post_call_gl_callback(NULL, "glDrawRangeElementsEXT", (GLADapiproc) glad_glDrawRangeElementsEXT, 6, mode, start, end, count, type, indices);
    
}
PFNGLDRAWRANGEELEMENTSEXTPROC glad_debug_glDrawRangeElementsEXT = glad_debug_impl_glDrawRangeElementsEXT;
PFNGLEDGEFLAGPROC glad_glEdgeFlag = NULL;
static void GLAD_API_PTR glad_debug_impl_glEdgeFlag(GLboolean flag) {
    _pre_call_gl_callback("glEdgeFlag", (GLADapiproc) glad_glEdgeFlag, 1, flag);
    glad_glEdgeFlag(flag);
    _post_call_gl_callback(NULL, "glEdgeFlag", (GLADapiproc) glad_glEdgeFlag, 1, flag);
    
}
PFNGLEDGEFLAGPROC glad_debug_glEdgeFlag = glad_debug_impl_glEdgeFlag;
PFNGLEDGEFLAGPOINTERPROC glad_glEdgeFlagPointer = NULL;
static void GLAD_API_PTR glad_debug_impl_glEdgeFlagPointer(GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glEdgeFlagPointer", (GLADapiproc) glad_glEdgeFlagPointer, 2, stride, pointer);
    glad_glEdgeFlagPointer(stride, pointer);
    _post_call_gl_callback(NULL, "glEdgeFlagPointer", (GLADapiproc) glad_glEdgeFlagPointer, 2, stride, pointer);
    
}
PFNGLEDGEFLAGPOINTERPROC glad_debug_glEdgeFlagPointer = glad_debug_impl_glEdgeFlagPointer;
PFNGLEDGEFLAGPOINTEREXTPROC glad_glEdgeFlagPointerEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, const GLboolean * pointer) {
    _pre_call_gl_callback("glEdgeFlagPointerEXT", (GLADapiproc) glad_glEdgeFlagPointerEXT, 3, stride, count, pointer);
    glad_glEdgeFlagPointerEXT(stride, count, pointer);
    _post_call_gl_callback(NULL, "glEdgeFlagPointerEXT", (GLADapiproc) glad_glEdgeFlagPointerEXT, 3, stride, count, pointer);
    
}
PFNGLEDGEFLAGPOINTEREXTPROC glad_debug_glEdgeFlagPointerEXT = glad_debug_impl_glEdgeFlagPointerEXT;
PFNGLEDGEFLAGVPROC glad_glEdgeFlagv = NULL;
static void GLAD_API_PTR glad_debug_impl_glEdgeFlagv(const GLboolean * flag) {
    _pre_call_gl_callback("glEdgeFlagv", (GLADapiproc) glad_glEdgeFlagv, 1, flag);
    glad_glEdgeFlagv(flag);
    _post_call_gl_callback(NULL, "glEdgeFlagv", (GLADapiproc) glad_glEdgeFlagv, 1, flag);
    
}
PFNGLEDGEFLAGVPROC glad_debug_glEdgeFlagv = glad_debug_impl_glEdgeFlagv;
PFNGLENABLEPROC glad_glEnable = NULL;
static void GLAD_API_PTR glad_debug_impl_glEnable(GLenum cap) {
    _pre_call_gl_callback("glEnable", (GLADapiproc) glad_glEnable, 1, cap);
    glad_glEnable(cap);
    _post_call_gl_callback(NULL, "glEnable", (GLADapiproc) glad_glEnable, 1, cap);
    
}
PFNGLENABLEPROC glad_debug_glEnable = glad_debug_impl_glEnable;
PFNGLENABLECLIENTSTATEPROC glad_glEnableClientState = NULL;
static void GLAD_API_PTR glad_debug_impl_glEnableClientState(GLenum array) {
    _pre_call_gl_callback("glEnableClientState", (GLADapiproc) glad_glEnableClientState, 1, array);
    glad_glEnableClientState(array);
    _post_call_gl_callback(NULL, "glEnableClientState", (GLADapiproc) glad_glEnableClientState, 1, array);
    
}
PFNGLENABLECLIENTSTATEPROC glad_debug_glEnableClientState = glad_debug_impl_glEnableClientState;
PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray = NULL;
static void GLAD_API_PTR glad_debug_impl_glEnableVertexAttribArray(GLuint index) {
    _pre_call_gl_callback("glEnableVertexAttribArray", (GLADapiproc) glad_glEnableVertexAttribArray, 1, index);
    glad_glEnableVertexAttribArray(index);
    _post_call_gl_callback(NULL, "glEnableVertexAttribArray", (GLADapiproc) glad_glEnableVertexAttribArray, 1, index);
    
}
PFNGLENABLEVERTEXATTRIBARRAYPROC glad_debug_glEnableVertexAttribArray = glad_debug_impl_glEnableVertexAttribArray;
PFNGLENABLEVERTEXATTRIBARRAYARBPROC glad_glEnableVertexAttribArrayARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glEnableVertexAttribArrayARB(GLuint index) {
    _pre_call_gl_callback("glEnableVertexAttribArrayARB", (GLADapiproc) glad_glEnableVertexAttribArrayARB, 1, index);
    glad_glEnableVertexAttribArrayARB(index);
    _post_call_gl_callback(NULL, "glEnableVertexAttribArrayARB", (GLADapiproc) glad_glEnableVertexAttribArrayARB, 1, index);
    
}
PFNGLENABLEVERTEXATTRIBARRAYARBPROC glad_debug_glEnableVertexAttribArrayARB = glad_debug_impl_glEnableVertexAttribArrayARB;
PFNGLENDPROC glad_glEnd = NULL;
static void GLAD_API_PTR glad_debug_impl_glEnd(void) {
    _pre_call_gl_callback("glEnd", (GLADapiproc) glad_glEnd, 0);
    glad_glEnd();
    _post_call_gl_callback(NULL, "glEnd", (GLADapiproc) glad_glEnd, 0);
    
}
PFNGLENDPROC glad_debug_glEnd = glad_debug_impl_glEnd;
PFNGLENDLISTPROC glad_glEndList = NULL;
static void GLAD_API_PTR glad_debug_impl_glEndList(void) {
    _pre_call_gl_callback("glEndList", (GLADapiproc) glad_glEndList, 0);
    glad_glEndList();
    _post_call_gl_callback(NULL, "glEndList", (GLADapiproc) glad_glEndList, 0);
    
}
PFNGLENDLISTPROC glad_debug_glEndList = glad_debug_impl_glEndList;
PFNGLENDQUERYPROC glad_glEndQuery = NULL;
static void GLAD_API_PTR glad_debug_impl_glEndQuery(GLenum target) {
    _pre_call_gl_callback("glEndQuery", (GLADapiproc) glad_glEndQuery, 1, target);
    glad_glEndQuery(target);
    _post_call_gl_callback(NULL, "glEndQuery", (GLADapiproc) glad_glEndQuery, 1, target);
    
}
PFNGLENDQUERYPROC glad_debug_glEndQuery = glad_debug_impl_glEndQuery;
PFNGLENDQUERYARBPROC glad_glEndQueryARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glEndQueryARB(GLenum target) {
    _pre_call_gl_callback("glEndQueryARB", (GLADapiproc) glad_glEndQueryARB, 1, target);
    glad_glEndQueryARB(target);
    _post_call_gl_callback(NULL, "glEndQueryARB", (GLADapiproc) glad_glEndQueryARB, 1, target);
    
}
PFNGLENDQUERYARBPROC glad_debug_glEndQueryARB = glad_debug_impl_glEndQueryARB;
PFNGLEVALCOORD1DPROC glad_glEvalCoord1d = NULL;
static void GLAD_API_PTR glad_debug_impl_glEvalCoord1d(GLdouble u) {
    _pre_call_gl_callback("glEvalCoord1d", (GLADapiproc) glad_glEvalCoord1d, 1, u);
    glad_glEvalCoord1d(u);
    _post_call_gl_callback(NULL, "glEvalCoord1d", (GLADapiproc) glad_glEvalCoord1d, 1, u);
    
}
PFNGLEVALCOORD1DPROC glad_debug_glEvalCoord1d = glad_debug_impl_glEvalCoord1d;
PFNGLEVALCOORD1DVPROC glad_glEvalCoord1dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glEvalCoord1dv(const GLdouble * u) {
    _pre_call_gl_callback("glEvalCoord1dv", (GLADapiproc) glad_glEvalCoord1dv, 1, u);
    glad_glEvalCoord1dv(u);
    _post_call_gl_callback(NULL, "glEvalCoord1dv", (GLADapiproc) glad_glEvalCoord1dv, 1, u);
    
}
PFNGLEVALCOORD1DVPROC glad_debug_glEvalCoord1dv = glad_debug_impl_glEvalCoord1dv;
PFNGLEVALCOORD1FPROC glad_glEvalCoord1f = NULL;
static void GLAD_API_PTR glad_debug_impl_glEvalCoord1f(GLfloat u) {
    _pre_call_gl_callback("glEvalCoord1f", (GLADapiproc) glad_glEvalCoord1f, 1, u);
    glad_glEvalCoord1f(u);
    _post_call_gl_callback(NULL, "glEvalCoord1f", (GLADapiproc) glad_glEvalCoord1f, 1, u);
    
}
PFNGLEVALCOORD1FPROC glad_debug_glEvalCoord1f = glad_debug_impl_glEvalCoord1f;
PFNGLEVALCOORD1FVPROC glad_glEvalCoord1fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glEvalCoord1fv(const GLfloat * u) {
    _pre_call_gl_callback("glEvalCoord1fv", (GLADapiproc) glad_glEvalCoord1fv, 1, u);
    glad_glEvalCoord1fv(u);
    _post_call_gl_callback(NULL, "glEvalCoord1fv", (GLADapiproc) glad_glEvalCoord1fv, 1, u);
    
}
PFNGLEVALCOORD1FVPROC glad_debug_glEvalCoord1fv = glad_debug_impl_glEvalCoord1fv;
PFNGLEVALCOORD2DPROC glad_glEvalCoord2d = NULL;
static void GLAD_API_PTR glad_debug_impl_glEvalCoord2d(GLdouble u, GLdouble v) {
    _pre_call_gl_callback("glEvalCoord2d", (GLADapiproc) glad_glEvalCoord2d, 2, u, v);
    glad_glEvalCoord2d(u, v);
    _post_call_gl_callback(NULL, "glEvalCoord2d", (GLADapiproc) glad_glEvalCoord2d, 2, u, v);
    
}
PFNGLEVALCOORD2DPROC glad_debug_glEvalCoord2d = glad_debug_impl_glEvalCoord2d;
PFNGLEVALCOORD2DVPROC glad_glEvalCoord2dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glEvalCoord2dv(const GLdouble * u) {
    _pre_call_gl_callback("glEvalCoord2dv", (GLADapiproc) glad_glEvalCoord2dv, 1, u);
    glad_glEvalCoord2dv(u);
    _post_call_gl_callback(NULL, "glEvalCoord2dv", (GLADapiproc) glad_glEvalCoord2dv, 1, u);
    
}
PFNGLEVALCOORD2DVPROC glad_debug_glEvalCoord2dv = glad_debug_impl_glEvalCoord2dv;
PFNGLEVALCOORD2FPROC glad_glEvalCoord2f = NULL;
static void GLAD_API_PTR glad_debug_impl_glEvalCoord2f(GLfloat u, GLfloat v) {
    _pre_call_gl_callback("glEvalCoord2f", (GLADapiproc) glad_glEvalCoord2f, 2, u, v);
    glad_glEvalCoord2f(u, v);
    _post_call_gl_callback(NULL, "glEvalCoord2f", (GLADapiproc) glad_glEvalCoord2f, 2, u, v);
    
}
PFNGLEVALCOORD2FPROC glad_debug_glEvalCoord2f = glad_debug_impl_glEvalCoord2f;
PFNGLEVALCOORD2FVPROC glad_glEvalCoord2fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glEvalCoord2fv(const GLfloat * u) {
    _pre_call_gl_callback("glEvalCoord2fv", (GLADapiproc) glad_glEvalCoord2fv, 1, u);
    glad_glEvalCoord2fv(u);
    _post_call_gl_callback(NULL, "glEvalCoord2fv", (GLADapiproc) glad_glEvalCoord2fv, 1, u);
    
}
PFNGLEVALCOORD2FVPROC glad_debug_glEvalCoord2fv = glad_debug_impl_glEvalCoord2fv;
PFNGLEVALMESH1PROC glad_glEvalMesh1 = NULL;
static void GLAD_API_PTR glad_debug_impl_glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
    _pre_call_gl_callback("glEvalMesh1", (GLADapiproc) glad_glEvalMesh1, 3, mode, i1, i2);
    glad_glEvalMesh1(mode, i1, i2);
    _post_call_gl_callback(NULL, "glEvalMesh1", (GLADapiproc) glad_glEvalMesh1, 3, mode, i1, i2);
    
}
PFNGLEVALMESH1PROC glad_debug_glEvalMesh1 = glad_debug_impl_glEvalMesh1;
PFNGLEVALMESH2PROC glad_glEvalMesh2 = NULL;
static void GLAD_API_PTR glad_debug_impl_glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
    _pre_call_gl_callback("glEvalMesh2", (GLADapiproc) glad_glEvalMesh2, 5, mode, i1, i2, j1, j2);
    glad_glEvalMesh2(mode, i1, i2, j1, j2);
    _post_call_gl_callback(NULL, "glEvalMesh2", (GLADapiproc) glad_glEvalMesh2, 5, mode, i1, i2, j1, j2);
    
}
PFNGLEVALMESH2PROC glad_debug_glEvalMesh2 = glad_debug_impl_glEvalMesh2;
PFNGLEVALPOINT1PROC glad_glEvalPoint1 = NULL;
static void GLAD_API_PTR glad_debug_impl_glEvalPoint1(GLint i) {
    _pre_call_gl_callback("glEvalPoint1", (GLADapiproc) glad_glEvalPoint1, 1, i);
    glad_glEvalPoint1(i);
    _post_call_gl_callback(NULL, "glEvalPoint1", (GLADapiproc) glad_glEvalPoint1, 1, i);
    
}
PFNGLEVALPOINT1PROC glad_debug_glEvalPoint1 = glad_debug_impl_glEvalPoint1;
PFNGLEVALPOINT2PROC glad_glEvalPoint2 = NULL;
static void GLAD_API_PTR glad_debug_impl_glEvalPoint2(GLint i, GLint j) {
    _pre_call_gl_callback("glEvalPoint2", (GLADapiproc) glad_glEvalPoint2, 2, i, j);
    glad_glEvalPoint2(i, j);
    _post_call_gl_callback(NULL, "glEvalPoint2", (GLADapiproc) glad_glEvalPoint2, 2, i, j);
    
}
PFNGLEVALPOINT2PROC glad_debug_glEvalPoint2 = glad_debug_impl_glEvalPoint2;
PFNGLEXECUTEPROGRAMNVPROC glad_glExecuteProgramNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glExecuteProgramNV(GLenum target, GLuint id, const GLfloat * params) {
    _pre_call_gl_callback("glExecuteProgramNV", (GLADapiproc) glad_glExecuteProgramNV, 3, target, id, params);
    glad_glExecuteProgramNV(target, id, params);
    _post_call_gl_callback(NULL, "glExecuteProgramNV", (GLADapiproc) glad_glExecuteProgramNV, 3, target, id, params);
    
}
PFNGLEXECUTEPROGRAMNVPROC glad_debug_glExecuteProgramNV = glad_debug_impl_glExecuteProgramNV;
PFNGLFEEDBACKBUFFERPROC glad_glFeedbackBuffer = NULL;
static void GLAD_API_PTR glad_debug_impl_glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer) {
    _pre_call_gl_callback("glFeedbackBuffer", (GLADapiproc) glad_glFeedbackBuffer, 3, size, type, buffer);
    glad_glFeedbackBuffer(size, type, buffer);
    _post_call_gl_callback(NULL, "glFeedbackBuffer", (GLADapiproc) glad_glFeedbackBuffer, 3, size, type, buffer);
    
}
PFNGLFEEDBACKBUFFERPROC glad_debug_glFeedbackBuffer = glad_debug_impl_glFeedbackBuffer;
PFNGLFINISHPROC glad_glFinish = NULL;
static void GLAD_API_PTR glad_debug_impl_glFinish(void) {
    _pre_call_gl_callback("glFinish", (GLADapiproc) glad_glFinish, 0);
    glad_glFinish();
    _post_call_gl_callback(NULL, "glFinish", (GLADapiproc) glad_glFinish, 0);
    
}
PFNGLFINISHPROC glad_debug_glFinish = glad_debug_impl_glFinish;
PFNGLFLUSHPROC glad_glFlush = NULL;
static void GLAD_API_PTR glad_debug_impl_glFlush(void) {
    _pre_call_gl_callback("glFlush", (GLADapiproc) glad_glFlush, 0);
    glad_glFlush();
    _post_call_gl_callback(NULL, "glFlush", (GLADapiproc) glad_glFlush, 0);
    
}
PFNGLFLUSHPROC glad_debug_glFlush = glad_debug_impl_glFlush;
PFNGLFOGCOORDPOINTERPROC glad_glFogCoordPointer = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogCoordPointer(GLenum type, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glFogCoordPointer", (GLADapiproc) glad_glFogCoordPointer, 3, type, stride, pointer);
    glad_glFogCoordPointer(type, stride, pointer);
    _post_call_gl_callback(NULL, "glFogCoordPointer", (GLADapiproc) glad_glFogCoordPointer, 3, type, stride, pointer);
    
}
PFNGLFOGCOORDPOINTERPROC glad_debug_glFogCoordPointer = glad_debug_impl_glFogCoordPointer;
PFNGLFOGCOORDPOINTEREXTPROC glad_glFogCoordPointerEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogCoordPointerEXT(GLenum type, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glFogCoordPointerEXT", (GLADapiproc) glad_glFogCoordPointerEXT, 3, type, stride, pointer);
    glad_glFogCoordPointerEXT(type, stride, pointer);
    _post_call_gl_callback(NULL, "glFogCoordPointerEXT", (GLADapiproc) glad_glFogCoordPointerEXT, 3, type, stride, pointer);
    
}
PFNGLFOGCOORDPOINTEREXTPROC glad_debug_glFogCoordPointerEXT = glad_debug_impl_glFogCoordPointerEXT;
PFNGLFOGCOORDDPROC glad_glFogCoordd = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogCoordd(GLdouble coord) {
    _pre_call_gl_callback("glFogCoordd", (GLADapiproc) glad_glFogCoordd, 1, coord);
    glad_glFogCoordd(coord);
    _post_call_gl_callback(NULL, "glFogCoordd", (GLADapiproc) glad_glFogCoordd, 1, coord);
    
}
PFNGLFOGCOORDDPROC glad_debug_glFogCoordd = glad_debug_impl_glFogCoordd;
PFNGLFOGCOORDDEXTPROC glad_glFogCoorddEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogCoorddEXT(GLdouble coord) {
    _pre_call_gl_callback("glFogCoorddEXT", (GLADapiproc) glad_glFogCoorddEXT, 1, coord);
    glad_glFogCoorddEXT(coord);
    _post_call_gl_callback(NULL, "glFogCoorddEXT", (GLADapiproc) glad_glFogCoorddEXT, 1, coord);
    
}
PFNGLFOGCOORDDEXTPROC glad_debug_glFogCoorddEXT = glad_debug_impl_glFogCoorddEXT;
PFNGLFOGCOORDDVPROC glad_glFogCoorddv = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogCoorddv(const GLdouble * coord) {
    _pre_call_gl_callback("glFogCoorddv", (GLADapiproc) glad_glFogCoorddv, 1, coord);
    glad_glFogCoorddv(coord);
    _post_call_gl_callback(NULL, "glFogCoorddv", (GLADapiproc) glad_glFogCoorddv, 1, coord);
    
}
PFNGLFOGCOORDDVPROC glad_debug_glFogCoorddv = glad_debug_impl_glFogCoorddv;
PFNGLFOGCOORDDVEXTPROC glad_glFogCoorddvEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogCoorddvEXT(const GLdouble * coord) {
    _pre_call_gl_callback("glFogCoorddvEXT", (GLADapiproc) glad_glFogCoorddvEXT, 1, coord);
    glad_glFogCoorddvEXT(coord);
    _post_call_gl_callback(NULL, "glFogCoorddvEXT", (GLADapiproc) glad_glFogCoorddvEXT, 1, coord);
    
}
PFNGLFOGCOORDDVEXTPROC glad_debug_glFogCoorddvEXT = glad_debug_impl_glFogCoorddvEXT;
PFNGLFOGCOORDFPROC glad_glFogCoordf = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogCoordf(GLfloat coord) {
    _pre_call_gl_callback("glFogCoordf", (GLADapiproc) glad_glFogCoordf, 1, coord);
    glad_glFogCoordf(coord);
    _post_call_gl_callback(NULL, "glFogCoordf", (GLADapiproc) glad_glFogCoordf, 1, coord);
    
}
PFNGLFOGCOORDFPROC glad_debug_glFogCoordf = glad_debug_impl_glFogCoordf;
PFNGLFOGCOORDFEXTPROC glad_glFogCoordfEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogCoordfEXT(GLfloat coord) {
    _pre_call_gl_callback("glFogCoordfEXT", (GLADapiproc) glad_glFogCoordfEXT, 1, coord);
    glad_glFogCoordfEXT(coord);
    _post_call_gl_callback(NULL, "glFogCoordfEXT", (GLADapiproc) glad_glFogCoordfEXT, 1, coord);
    
}
PFNGLFOGCOORDFEXTPROC glad_debug_glFogCoordfEXT = glad_debug_impl_glFogCoordfEXT;
PFNGLFOGCOORDFVPROC glad_glFogCoordfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogCoordfv(const GLfloat * coord) {
    _pre_call_gl_callback("glFogCoordfv", (GLADapiproc) glad_glFogCoordfv, 1, coord);
    glad_glFogCoordfv(coord);
    _post_call_gl_callback(NULL, "glFogCoordfv", (GLADapiproc) glad_glFogCoordfv, 1, coord);
    
}
PFNGLFOGCOORDFVPROC glad_debug_glFogCoordfv = glad_debug_impl_glFogCoordfv;
PFNGLFOGCOORDFVEXTPROC glad_glFogCoordfvEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogCoordfvEXT(const GLfloat * coord) {
    _pre_call_gl_callback("glFogCoordfvEXT", (GLADapiproc) glad_glFogCoordfvEXT, 1, coord);
    glad_glFogCoordfvEXT(coord);
    _post_call_gl_callback(NULL, "glFogCoordfvEXT", (GLADapiproc) glad_glFogCoordfvEXT, 1, coord);
    
}
PFNGLFOGCOORDFVEXTPROC glad_debug_glFogCoordfvEXT = glad_debug_impl_glFogCoordfvEXT;
PFNGLFOGFPROC glad_glFogf = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogf(GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glFogf", (GLADapiproc) glad_glFogf, 2, pname, param);
    glad_glFogf(pname, param);
    _post_call_gl_callback(NULL, "glFogf", (GLADapiproc) glad_glFogf, 2, pname, param);
    
}
PFNGLFOGFPROC glad_debug_glFogf = glad_debug_impl_glFogf;
PFNGLFOGFVPROC glad_glFogfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogfv(GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glFogfv", (GLADapiproc) glad_glFogfv, 2, pname, params);
    glad_glFogfv(pname, params);
    _post_call_gl_callback(NULL, "glFogfv", (GLADapiproc) glad_glFogfv, 2, pname, params);
    
}
PFNGLFOGFVPROC glad_debug_glFogfv = glad_debug_impl_glFogfv;
PFNGLFOGIPROC glad_glFogi = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogi(GLenum pname, GLint param) {
    _pre_call_gl_callback("glFogi", (GLADapiproc) glad_glFogi, 2, pname, param);
    glad_glFogi(pname, param);
    _post_call_gl_callback(NULL, "glFogi", (GLADapiproc) glad_glFogi, 2, pname, param);
    
}
PFNGLFOGIPROC glad_debug_glFogi = glad_debug_impl_glFogi;
PFNGLFOGIVPROC glad_glFogiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glFogiv(GLenum pname, const GLint * params) {
    _pre_call_gl_callback("glFogiv", (GLADapiproc) glad_glFogiv, 2, pname, params);
    glad_glFogiv(pname, params);
    _post_call_gl_callback(NULL, "glFogiv", (GLADapiproc) glad_glFogiv, 2, pname, params);
    
}
PFNGLFOGIVPROC glad_debug_glFogiv = glad_debug_impl_glFogiv;
PFNGLFRONTFACEPROC glad_glFrontFace = NULL;
static void GLAD_API_PTR glad_debug_impl_glFrontFace(GLenum mode) {
    _pre_call_gl_callback("glFrontFace", (GLADapiproc) glad_glFrontFace, 1, mode);
    glad_glFrontFace(mode);
    _post_call_gl_callback(NULL, "glFrontFace", (GLADapiproc) glad_glFrontFace, 1, mode);
    
}
PFNGLFRONTFACEPROC glad_debug_glFrontFace = glad_debug_impl_glFrontFace;
PFNGLFRUSTUMPROC glad_glFrustum = NULL;
static void GLAD_API_PTR glad_debug_impl_glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    _pre_call_gl_callback("glFrustum", (GLADapiproc) glad_glFrustum, 6, left, right, bottom, top, zNear, zFar);
    glad_glFrustum(left, right, bottom, top, zNear, zFar);
    _post_call_gl_callback(NULL, "glFrustum", (GLADapiproc) glad_glFrustum, 6, left, right, bottom, top, zNear, zFar);
    
}
PFNGLFRUSTUMPROC glad_debug_glFrustum = glad_debug_impl_glFrustum;
PFNGLGENBUFFERSPROC glad_glGenBuffers = NULL;
static void GLAD_API_PTR glad_debug_impl_glGenBuffers(GLsizei n, GLuint * buffers) {
    _pre_call_gl_callback("glGenBuffers", (GLADapiproc) glad_glGenBuffers, 2, n, buffers);
    glad_glGenBuffers(n, buffers);
    _post_call_gl_callback(NULL, "glGenBuffers", (GLADapiproc) glad_glGenBuffers, 2, n, buffers);
    
}
PFNGLGENBUFFERSPROC glad_debug_glGenBuffers = glad_debug_impl_glGenBuffers;
PFNGLGENBUFFERSARBPROC glad_glGenBuffersARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGenBuffersARB(GLsizei n, GLuint * buffers) {
    _pre_call_gl_callback("glGenBuffersARB", (GLADapiproc) glad_glGenBuffersARB, 2, n, buffers);
    glad_glGenBuffersARB(n, buffers);
    _post_call_gl_callback(NULL, "glGenBuffersARB", (GLADapiproc) glad_glGenBuffersARB, 2, n, buffers);
    
}
PFNGLGENBUFFERSARBPROC glad_debug_glGenBuffersARB = glad_debug_impl_glGenBuffersARB;
PFNGLGENLISTSPROC glad_glGenLists = NULL;
static GLuint GLAD_API_PTR glad_debug_impl_glGenLists(GLsizei range) {
    GLuint ret;
    _pre_call_gl_callback("glGenLists", (GLADapiproc) glad_glGenLists, 1, range);
    ret = glad_glGenLists(range);
    _post_call_gl_callback((void*) &ret, "glGenLists", (GLADapiproc) glad_glGenLists, 1, range);
    return ret;
}
PFNGLGENLISTSPROC glad_debug_glGenLists = glad_debug_impl_glGenLists;
PFNGLGENPROGRAMSARBPROC glad_glGenProgramsARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGenProgramsARB(GLsizei n, GLuint * programs) {
    _pre_call_gl_callback("glGenProgramsARB", (GLADapiproc) glad_glGenProgramsARB, 2, n, programs);
    glad_glGenProgramsARB(n, programs);
    _post_call_gl_callback(NULL, "glGenProgramsARB", (GLADapiproc) glad_glGenProgramsARB, 2, n, programs);
    
}
PFNGLGENPROGRAMSARBPROC glad_debug_glGenProgramsARB = glad_debug_impl_glGenProgramsARB;
PFNGLGENPROGRAMSNVPROC glad_glGenProgramsNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glGenProgramsNV(GLsizei n, GLuint * programs) {
    _pre_call_gl_callback("glGenProgramsNV", (GLADapiproc) glad_glGenProgramsNV, 2, n, programs);
    glad_glGenProgramsNV(n, programs);
    _post_call_gl_callback(NULL, "glGenProgramsNV", (GLADapiproc) glad_glGenProgramsNV, 2, n, programs);
    
}
PFNGLGENPROGRAMSNVPROC glad_debug_glGenProgramsNV = glad_debug_impl_glGenProgramsNV;
PFNGLGENQUERIESPROC glad_glGenQueries = NULL;
static void GLAD_API_PTR glad_debug_impl_glGenQueries(GLsizei n, GLuint * ids) {
    _pre_call_gl_callback("glGenQueries", (GLADapiproc) glad_glGenQueries, 2, n, ids);
    glad_glGenQueries(n, ids);
    _post_call_gl_callback(NULL, "glGenQueries", (GLADapiproc) glad_glGenQueries, 2, n, ids);
    
}
PFNGLGENQUERIESPROC glad_debug_glGenQueries = glad_debug_impl_glGenQueries;
PFNGLGENQUERIESARBPROC glad_glGenQueriesARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGenQueriesARB(GLsizei n, GLuint * ids) {
    _pre_call_gl_callback("glGenQueriesARB", (GLADapiproc) glad_glGenQueriesARB, 2, n, ids);
    glad_glGenQueriesARB(n, ids);
    _post_call_gl_callback(NULL, "glGenQueriesARB", (GLADapiproc) glad_glGenQueriesARB, 2, n, ids);
    
}
PFNGLGENQUERIESARBPROC glad_debug_glGenQueriesARB = glad_debug_impl_glGenQueriesARB;
PFNGLGENTEXTURESPROC glad_glGenTextures = NULL;
static void GLAD_API_PTR glad_debug_impl_glGenTextures(GLsizei n, GLuint * textures) {
    _pre_call_gl_callback("glGenTextures", (GLADapiproc) glad_glGenTextures, 2, n, textures);
    glad_glGenTextures(n, textures);
    _post_call_gl_callback(NULL, "glGenTextures", (GLADapiproc) glad_glGenTextures, 2, n, textures);
    
}
PFNGLGENTEXTURESPROC glad_debug_glGenTextures = glad_debug_impl_glGenTextures;
PFNGLGENTEXTURESEXTPROC glad_glGenTexturesEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glGenTexturesEXT(GLsizei n, GLuint * textures) {
    _pre_call_gl_callback("glGenTexturesEXT", (GLADapiproc) glad_glGenTexturesEXT, 2, n, textures);
    glad_glGenTexturesEXT(n, textures);
    _post_call_gl_callback(NULL, "glGenTexturesEXT", (GLADapiproc) glad_glGenTexturesEXT, 2, n, textures);
    
}
PFNGLGENTEXTURESEXTPROC glad_debug_glGenTexturesEXT = glad_debug_impl_glGenTexturesEXT;
PFNGLGETACTIVEATTRIBPROC glad_glGetActiveAttrib = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    _pre_call_gl_callback("glGetActiveAttrib", (GLADapiproc) glad_glGetActiveAttrib, 7, program, index, bufSize, length, size, type, name);
    glad_glGetActiveAttrib(program, index, bufSize, length, size, type, name);
    _post_call_gl_callback(NULL, "glGetActiveAttrib", (GLADapiproc) glad_glGetActiveAttrib, 7, program, index, bufSize, length, size, type, name);
    
}
PFNGLGETACTIVEATTRIBPROC glad_debug_glGetActiveAttrib = glad_debug_impl_glGetActiveAttrib;
PFNGLGETACTIVEATTRIBARBPROC glad_glGetActiveAttribARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name) {
    _pre_call_gl_callback("glGetActiveAttribARB", (GLADapiproc) glad_glGetActiveAttribARB, 7, programObj, index, maxLength, length, size, type, name);
    glad_glGetActiveAttribARB(programObj, index, maxLength, length, size, type, name);
    _post_call_gl_callback(NULL, "glGetActiveAttribARB", (GLADapiproc) glad_glGetActiveAttribARB, 7, programObj, index, maxLength, length, size, type, name);
    
}
PFNGLGETACTIVEATTRIBARBPROC glad_debug_glGetActiveAttribARB = glad_debug_impl_glGetActiveAttribARB;
PFNGLGETACTIVEUNIFORMPROC glad_glGetActiveUniform = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    _pre_call_gl_callback("glGetActiveUniform", (GLADapiproc) glad_glGetActiveUniform, 7, program, index, bufSize, length, size, type, name);
    glad_glGetActiveUniform(program, index, bufSize, length, size, type, name);
    _post_call_gl_callback(NULL, "glGetActiveUniform", (GLADapiproc) glad_glGetActiveUniform, 7, program, index, bufSize, length, size, type, name);
    
}
PFNGLGETACTIVEUNIFORMPROC glad_debug_glGetActiveUniform = glad_debug_impl_glGetActiveUniform;
PFNGLGETACTIVEUNIFORMARBPROC glad_glGetActiveUniformARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name) {
    _pre_call_gl_callback("glGetActiveUniformARB", (GLADapiproc) glad_glGetActiveUniformARB, 7, programObj, index, maxLength, length, size, type, name);
    glad_glGetActiveUniformARB(programObj, index, maxLength, length, size, type, name);
    _post_call_gl_callback(NULL, "glGetActiveUniformARB", (GLADapiproc) glad_glGetActiveUniformARB, 7, programObj, index, maxLength, length, size, type, name);
    
}
PFNGLGETACTIVEUNIFORMARBPROC glad_debug_glGetActiveUniformARB = glad_debug_impl_glGetActiveUniformARB;
PFNGLGETATTACHEDOBJECTSARBPROC glad_glGetAttachedObjectsARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei * count, GLhandleARB * obj) {
    _pre_call_gl_callback("glGetAttachedObjectsARB", (GLADapiproc) glad_glGetAttachedObjectsARB, 4, containerObj, maxCount, count, obj);
    glad_glGetAttachedObjectsARB(containerObj, maxCount, count, obj);
    _post_call_gl_callback(NULL, "glGetAttachedObjectsARB", (GLADapiproc) glad_glGetAttachedObjectsARB, 4, containerObj, maxCount, count, obj);
    
}
PFNGLGETATTACHEDOBJECTSARBPROC glad_debug_glGetAttachedObjectsARB = glad_debug_impl_glGetAttachedObjectsARB;
PFNGLGETATTACHEDSHADERSPROC glad_glGetAttachedShaders = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders) {
    _pre_call_gl_callback("glGetAttachedShaders", (GLADapiproc) glad_glGetAttachedShaders, 4, program, maxCount, count, shaders);
    glad_glGetAttachedShaders(program, maxCount, count, shaders);
    _post_call_gl_callback(NULL, "glGetAttachedShaders", (GLADapiproc) glad_glGetAttachedShaders, 4, program, maxCount, count, shaders);
    
}
PFNGLGETATTACHEDSHADERSPROC glad_debug_glGetAttachedShaders = glad_debug_impl_glGetAttachedShaders;
PFNGLGETATTRIBLOCATIONPROC glad_glGetAttribLocation = NULL;
static GLint GLAD_API_PTR glad_debug_impl_glGetAttribLocation(GLuint program, const GLchar * name) {
    GLint ret;
    _pre_call_gl_callback("glGetAttribLocation", (GLADapiproc) glad_glGetAttribLocation, 2, program, name);
    ret = glad_glGetAttribLocation(program, name);
    _post_call_gl_callback((void*) &ret, "glGetAttribLocation", (GLADapiproc) glad_glGetAttribLocation, 2, program, name);
    return ret;
}
PFNGLGETATTRIBLOCATIONPROC glad_debug_glGetAttribLocation = glad_debug_impl_glGetAttribLocation;
PFNGLGETATTRIBLOCATIONARBPROC glad_glGetAttribLocationARB = NULL;
static GLint GLAD_API_PTR glad_debug_impl_glGetAttribLocationARB(GLhandleARB programObj, const GLcharARB * name) {
    GLint ret;
    _pre_call_gl_callback("glGetAttribLocationARB", (GLADapiproc) glad_glGetAttribLocationARB, 2, programObj, name);
    ret = glad_glGetAttribLocationARB(programObj, name);
    _post_call_gl_callback((void*) &ret, "glGetAttribLocationARB", (GLADapiproc) glad_glGetAttribLocationARB, 2, programObj, name);
    return ret;
}
PFNGLGETATTRIBLOCATIONARBPROC glad_debug_glGetAttribLocationARB = glad_debug_impl_glGetAttribLocationARB;
PFNGLGETBOOLEANVPROC glad_glGetBooleanv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetBooleanv(GLenum pname, GLboolean * data) {
    _pre_call_gl_callback("glGetBooleanv", (GLADapiproc) glad_glGetBooleanv, 2, pname, data);
    glad_glGetBooleanv(pname, data);
    _post_call_gl_callback(NULL, "glGetBooleanv", (GLADapiproc) glad_glGetBooleanv, 2, pname, data);
    
}
PFNGLGETBOOLEANVPROC glad_debug_glGetBooleanv = glad_debug_impl_glGetBooleanv;
PFNGLGETBUFFERPARAMETERIVPROC glad_glGetBufferParameteriv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetBufferParameteriv", (GLADapiproc) glad_glGetBufferParameteriv, 3, target, pname, params);
    glad_glGetBufferParameteriv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetBufferParameteriv", (GLADapiproc) glad_glGetBufferParameteriv, 3, target, pname, params);
    
}
PFNGLGETBUFFERPARAMETERIVPROC glad_debug_glGetBufferParameteriv = glad_debug_impl_glGetBufferParameteriv;
PFNGLGETBUFFERPARAMETERIVARBPROC glad_glGetBufferParameterivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetBufferParameterivARB(GLenum target, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetBufferParameterivARB", (GLADapiproc) glad_glGetBufferParameterivARB, 3, target, pname, params);
    glad_glGetBufferParameterivARB(target, pname, params);
    _post_call_gl_callback(NULL, "glGetBufferParameterivARB", (GLADapiproc) glad_glGetBufferParameterivARB, 3, target, pname, params);
    
}
PFNGLGETBUFFERPARAMETERIVARBPROC glad_debug_glGetBufferParameterivARB = glad_debug_impl_glGetBufferParameterivARB;
PFNGLGETBUFFERPOINTERVPROC glad_glGetBufferPointerv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetBufferPointerv(GLenum target, GLenum pname, void ** params) {
    _pre_call_gl_callback("glGetBufferPointerv", (GLADapiproc) glad_glGetBufferPointerv, 3, target, pname, params);
    glad_glGetBufferPointerv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetBufferPointerv", (GLADapiproc) glad_glGetBufferPointerv, 3, target, pname, params);
    
}
PFNGLGETBUFFERPOINTERVPROC glad_debug_glGetBufferPointerv = glad_debug_impl_glGetBufferPointerv;
PFNGLGETBUFFERPOINTERVARBPROC glad_glGetBufferPointervARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetBufferPointervARB(GLenum target, GLenum pname, void ** params) {
    _pre_call_gl_callback("glGetBufferPointervARB", (GLADapiproc) glad_glGetBufferPointervARB, 3, target, pname, params);
    glad_glGetBufferPointervARB(target, pname, params);
    _post_call_gl_callback(NULL, "glGetBufferPointervARB", (GLADapiproc) glad_glGetBufferPointervARB, 3, target, pname, params);
    
}
PFNGLGETBUFFERPOINTERVARBPROC glad_debug_glGetBufferPointervARB = glad_debug_impl_glGetBufferPointervARB;
PFNGLGETBUFFERSUBDATAPROC glad_glGetBufferSubData = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void * data) {
    _pre_call_gl_callback("glGetBufferSubData", (GLADapiproc) glad_glGetBufferSubData, 4, target, offset, size, data);
    glad_glGetBufferSubData(target, offset, size, data);
    _post_call_gl_callback(NULL, "glGetBufferSubData", (GLADapiproc) glad_glGetBufferSubData, 4, target, offset, size, data);
    
}
PFNGLGETBUFFERSUBDATAPROC glad_debug_glGetBufferSubData = glad_debug_impl_glGetBufferSubData;
PFNGLGETBUFFERSUBDATAARBPROC glad_glGetBufferSubDataARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, void * data) {
    _pre_call_gl_callback("glGetBufferSubDataARB", (GLADapiproc) glad_glGetBufferSubDataARB, 4, target, offset, size, data);
    glad_glGetBufferSubDataARB(target, offset, size, data);
    _post_call_gl_callback(NULL, "glGetBufferSubDataARB", (GLADapiproc) glad_glGetBufferSubDataARB, 4, target, offset, size, data);
    
}
PFNGLGETBUFFERSUBDATAARBPROC glad_debug_glGetBufferSubDataARB = glad_debug_impl_glGetBufferSubDataARB;
PFNGLGETCLIPPLANEPROC glad_glGetClipPlane = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetClipPlane(GLenum plane, GLdouble * equation) {
    _pre_call_gl_callback("glGetClipPlane", (GLADapiproc) glad_glGetClipPlane, 2, plane, equation);
    glad_glGetClipPlane(plane, equation);
    _post_call_gl_callback(NULL, "glGetClipPlane", (GLADapiproc) glad_glGetClipPlane, 2, plane, equation);
    
}
PFNGLGETCLIPPLANEPROC glad_debug_glGetClipPlane = glad_debug_impl_glGetClipPlane;
PFNGLGETCOLORTABLEPROC glad_glGetColorTable = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetColorTable(GLenum target, GLenum format, GLenum type, void * table) {
    _pre_call_gl_callback("glGetColorTable", (GLADapiproc) glad_glGetColorTable, 4, target, format, type, table);
    glad_glGetColorTable(target, format, type, table);
    _post_call_gl_callback(NULL, "glGetColorTable", (GLADapiproc) glad_glGetColorTable, 4, target, format, type, table);
    
}
PFNGLGETCOLORTABLEPROC glad_debug_glGetColorTable = glad_debug_impl_glGetColorTable;
PFNGLGETCOLORTABLEPARAMETERFVPROC glad_glGetColorTableParameterfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetColorTableParameterfv", (GLADapiproc) glad_glGetColorTableParameterfv, 3, target, pname, params);
    glad_glGetColorTableParameterfv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetColorTableParameterfv", (GLADapiproc) glad_glGetColorTableParameterfv, 3, target, pname, params);
    
}
PFNGLGETCOLORTABLEPARAMETERFVPROC glad_debug_glGetColorTableParameterfv = glad_debug_impl_glGetColorTableParameterfv;
PFNGLGETCOLORTABLEPARAMETERIVPROC glad_glGetColorTableParameteriv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetColorTableParameteriv(GLenum target, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetColorTableParameteriv", (GLADapiproc) glad_glGetColorTableParameteriv, 3, target, pname, params);
    glad_glGetColorTableParameteriv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetColorTableParameteriv", (GLADapiproc) glad_glGetColorTableParameteriv, 3, target, pname, params);
    
}
PFNGLGETCOLORTABLEPARAMETERIVPROC glad_debug_glGetColorTableParameteriv = glad_debug_impl_glGetColorTableParameteriv;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glad_glGetCompressedTexImage = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetCompressedTexImage(GLenum target, GLint level, void * img) {
    _pre_call_gl_callback("glGetCompressedTexImage", (GLADapiproc) glad_glGetCompressedTexImage, 3, target, level, img);
    glad_glGetCompressedTexImage(target, level, img);
    _post_call_gl_callback(NULL, "glGetCompressedTexImage", (GLADapiproc) glad_glGetCompressedTexImage, 3, target, level, img);
    
}
PFNGLGETCOMPRESSEDTEXIMAGEPROC glad_debug_glGetCompressedTexImage = glad_debug_impl_glGetCompressedTexImage;
PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glad_glGetCompressedTexImageARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetCompressedTexImageARB(GLenum target, GLint level, void * img) {
    _pre_call_gl_callback("glGetCompressedTexImageARB", (GLADapiproc) glad_glGetCompressedTexImageARB, 3, target, level, img);
    glad_glGetCompressedTexImageARB(target, level, img);
    _post_call_gl_callback(NULL, "glGetCompressedTexImageARB", (GLADapiproc) glad_glGetCompressedTexImageARB, 3, target, level, img);
    
}
PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glad_debug_glGetCompressedTexImageARB = glad_debug_impl_glGetCompressedTexImageARB;
PFNGLGETCONVOLUTIONFILTERPROC glad_glGetConvolutionFilter = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, void * image) {
    _pre_call_gl_callback("glGetConvolutionFilter", (GLADapiproc) glad_glGetConvolutionFilter, 4, target, format, type, image);
    glad_glGetConvolutionFilter(target, format, type, image);
    _post_call_gl_callback(NULL, "glGetConvolutionFilter", (GLADapiproc) glad_glGetConvolutionFilter, 4, target, format, type, image);
    
}
PFNGLGETCONVOLUTIONFILTERPROC glad_debug_glGetConvolutionFilter = glad_debug_impl_glGetConvolutionFilter;
PFNGLGETCONVOLUTIONPARAMETERFVPROC glad_glGetConvolutionParameterfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetConvolutionParameterfv", (GLADapiproc) glad_glGetConvolutionParameterfv, 3, target, pname, params);
    glad_glGetConvolutionParameterfv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetConvolutionParameterfv", (GLADapiproc) glad_glGetConvolutionParameterfv, 3, target, pname, params);
    
}
PFNGLGETCONVOLUTIONPARAMETERFVPROC glad_debug_glGetConvolutionParameterfv = glad_debug_impl_glGetConvolutionParameterfv;
PFNGLGETCONVOLUTIONPARAMETERIVPROC glad_glGetConvolutionParameteriv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetConvolutionParameteriv", (GLADapiproc) glad_glGetConvolutionParameteriv, 3, target, pname, params);
    glad_glGetConvolutionParameteriv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetConvolutionParameteriv", (GLADapiproc) glad_glGetConvolutionParameteriv, 3, target, pname, params);
    
}
PFNGLGETCONVOLUTIONPARAMETERIVPROC glad_debug_glGetConvolutionParameteriv = glad_debug_impl_glGetConvolutionParameteriv;
PFNGLGETDEBUGMESSAGELOGPROC glad_glGetDebugMessageLog = NULL;
static GLuint GLAD_API_PTR glad_debug_impl_glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog) {
    GLuint ret;
    _pre_call_gl_callback("glGetDebugMessageLog", (GLADapiproc) glad_glGetDebugMessageLog, 8, count, bufSize, sources, types, ids, severities, lengths, messageLog);
    ret = glad_glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog);
    _post_call_gl_callback((void*) &ret, "glGetDebugMessageLog", (GLADapiproc) glad_glGetDebugMessageLog, 8, count, bufSize, sources, types, ids, severities, lengths, messageLog);
    return ret;
}
PFNGLGETDEBUGMESSAGELOGPROC glad_debug_glGetDebugMessageLog = glad_debug_impl_glGetDebugMessageLog;
PFNGLGETDOUBLEVPROC glad_glGetDoublev = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetDoublev(GLenum pname, GLdouble * data) {
    _pre_call_gl_callback("glGetDoublev", (GLADapiproc) glad_glGetDoublev, 2, pname, data);
    glad_glGetDoublev(pname, data);
    _post_call_gl_callback(NULL, "glGetDoublev", (GLADapiproc) glad_glGetDoublev, 2, pname, data);
    
}
PFNGLGETDOUBLEVPROC glad_debug_glGetDoublev = glad_debug_impl_glGetDoublev;
PFNGLGETERRORPROC glad_glGetError = NULL;
static GLenum GLAD_API_PTR glad_debug_impl_glGetError(void) {
    GLenum ret;
    _pre_call_gl_callback("glGetError", (GLADapiproc) glad_glGetError, 0);
    ret = glad_glGetError();
    _post_call_gl_callback((void*) &ret, "glGetError", (GLADapiproc) glad_glGetError, 0);
    return ret;
}
PFNGLGETERRORPROC glad_debug_glGetError = glad_debug_impl_glGetError;
PFNGLGETFLOATVPROC glad_glGetFloatv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetFloatv(GLenum pname, GLfloat * data) {
    _pre_call_gl_callback("glGetFloatv", (GLADapiproc) glad_glGetFloatv, 2, pname, data);
    glad_glGetFloatv(pname, data);
    _post_call_gl_callback(NULL, "glGetFloatv", (GLADapiproc) glad_glGetFloatv, 2, pname, data);
    
}
PFNGLGETFLOATVPROC glad_debug_glGetFloatv = glad_debug_impl_glGetFloatv;
PFNGLGETHANDLEARBPROC glad_glGetHandleARB = NULL;
static GLhandleARB GLAD_API_PTR glad_debug_impl_glGetHandleARB(GLenum pname) {
    GLhandleARB ret;
    _pre_call_gl_callback("glGetHandleARB", (GLADapiproc) glad_glGetHandleARB, 1, pname);
    ret = glad_glGetHandleARB(pname);
    _post_call_gl_callback((void*) &ret, "glGetHandleARB", (GLADapiproc) glad_glGetHandleARB, 1, pname);
    return ret;
}
PFNGLGETHANDLEARBPROC glad_debug_glGetHandleARB = glad_debug_impl_glGetHandleARB;
PFNGLGETHISTOGRAMPROC glad_glGetHistogram = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values) {
    _pre_call_gl_callback("glGetHistogram", (GLADapiproc) glad_glGetHistogram, 5, target, reset, format, type, values);
    glad_glGetHistogram(target, reset, format, type, values);
    _post_call_gl_callback(NULL, "glGetHistogram", (GLADapiproc) glad_glGetHistogram, 5, target, reset, format, type, values);
    
}
PFNGLGETHISTOGRAMPROC glad_debug_glGetHistogram = glad_debug_impl_glGetHistogram;
PFNGLGETHISTOGRAMPARAMETERFVPROC glad_glGetHistogramParameterfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetHistogramParameterfv", (GLADapiproc) glad_glGetHistogramParameterfv, 3, target, pname, params);
    glad_glGetHistogramParameterfv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetHistogramParameterfv", (GLADapiproc) glad_glGetHistogramParameterfv, 3, target, pname, params);
    
}
PFNGLGETHISTOGRAMPARAMETERFVPROC glad_debug_glGetHistogramParameterfv = glad_debug_impl_glGetHistogramParameterfv;
PFNGLGETHISTOGRAMPARAMETERIVPROC glad_glGetHistogramParameteriv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetHistogramParameteriv(GLenum target, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetHistogramParameteriv", (GLADapiproc) glad_glGetHistogramParameteriv, 3, target, pname, params);
    glad_glGetHistogramParameteriv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetHistogramParameteriv", (GLADapiproc) glad_glGetHistogramParameteriv, 3, target, pname, params);
    
}
PFNGLGETHISTOGRAMPARAMETERIVPROC glad_debug_glGetHistogramParameteriv = glad_debug_impl_glGetHistogramParameteriv;
PFNGLGETINFOLOGARBPROC glad_glGetInfoLogARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * infoLog) {
    _pre_call_gl_callback("glGetInfoLogARB", (GLADapiproc) glad_glGetInfoLogARB, 4, obj, maxLength, length, infoLog);
    glad_glGetInfoLogARB(obj, maxLength, length, infoLog);
    _post_call_gl_callback(NULL, "glGetInfoLogARB", (GLADapiproc) glad_glGetInfoLogARB, 4, obj, maxLength, length, infoLog);
    
}
PFNGLGETINFOLOGARBPROC glad_debug_glGetInfoLogARB = glad_debug_impl_glGetInfoLogARB;
PFNGLGETINTEGERVPROC glad_glGetIntegerv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetIntegerv(GLenum pname, GLint * data) {
    _pre_call_gl_callback("glGetIntegerv", (GLADapiproc) glad_glGetIntegerv, 2, pname, data);
    glad_glGetIntegerv(pname, data);
    _post_call_gl_callback(NULL, "glGetIntegerv", (GLADapiproc) glad_glGetIntegerv, 2, pname, data);
    
}
PFNGLGETINTEGERVPROC glad_debug_glGetIntegerv = glad_debug_impl_glGetIntegerv;
PFNGLGETLIGHTFVPROC glad_glGetLightfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetLightfv", (GLADapiproc) glad_glGetLightfv, 3, light, pname, params);
    glad_glGetLightfv(light, pname, params);
    _post_call_gl_callback(NULL, "glGetLightfv", (GLADapiproc) glad_glGetLightfv, 3, light, pname, params);
    
}
PFNGLGETLIGHTFVPROC glad_debug_glGetLightfv = glad_debug_impl_glGetLightfv;
PFNGLGETLIGHTIVPROC glad_glGetLightiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetLightiv(GLenum light, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetLightiv", (GLADapiproc) glad_glGetLightiv, 3, light, pname, params);
    glad_glGetLightiv(light, pname, params);
    _post_call_gl_callback(NULL, "glGetLightiv", (GLADapiproc) glad_glGetLightiv, 3, light, pname, params);
    
}
PFNGLGETLIGHTIVPROC glad_debug_glGetLightiv = glad_debug_impl_glGetLightiv;
PFNGLGETMAPDVPROC glad_glGetMapdv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetMapdv(GLenum target, GLenum query, GLdouble * v) {
    _pre_call_gl_callback("glGetMapdv", (GLADapiproc) glad_glGetMapdv, 3, target, query, v);
    glad_glGetMapdv(target, query, v);
    _post_call_gl_callback(NULL, "glGetMapdv", (GLADapiproc) glad_glGetMapdv, 3, target, query, v);
    
}
PFNGLGETMAPDVPROC glad_debug_glGetMapdv = glad_debug_impl_glGetMapdv;
PFNGLGETMAPFVPROC glad_glGetMapfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetMapfv(GLenum target, GLenum query, GLfloat * v) {
    _pre_call_gl_callback("glGetMapfv", (GLADapiproc) glad_glGetMapfv, 3, target, query, v);
    glad_glGetMapfv(target, query, v);
    _post_call_gl_callback(NULL, "glGetMapfv", (GLADapiproc) glad_glGetMapfv, 3, target, query, v);
    
}
PFNGLGETMAPFVPROC glad_debug_glGetMapfv = glad_debug_impl_glGetMapfv;
PFNGLGETMAPIVPROC glad_glGetMapiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetMapiv(GLenum target, GLenum query, GLint * v) {
    _pre_call_gl_callback("glGetMapiv", (GLADapiproc) glad_glGetMapiv, 3, target, query, v);
    glad_glGetMapiv(target, query, v);
    _post_call_gl_callback(NULL, "glGetMapiv", (GLADapiproc) glad_glGetMapiv, 3, target, query, v);
    
}
PFNGLGETMAPIVPROC glad_debug_glGetMapiv = glad_debug_impl_glGetMapiv;
PFNGLGETMATERIALFVPROC glad_glGetMaterialfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetMaterialfv", (GLADapiproc) glad_glGetMaterialfv, 3, face, pname, params);
    glad_glGetMaterialfv(face, pname, params);
    _post_call_gl_callback(NULL, "glGetMaterialfv", (GLADapiproc) glad_glGetMaterialfv, 3, face, pname, params);
    
}
PFNGLGETMATERIALFVPROC glad_debug_glGetMaterialfv = glad_debug_impl_glGetMaterialfv;
PFNGLGETMATERIALIVPROC glad_glGetMaterialiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetMaterialiv(GLenum face, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetMaterialiv", (GLADapiproc) glad_glGetMaterialiv, 3, face, pname, params);
    glad_glGetMaterialiv(face, pname, params);
    _post_call_gl_callback(NULL, "glGetMaterialiv", (GLADapiproc) glad_glGetMaterialiv, 3, face, pname, params);
    
}
PFNGLGETMATERIALIVPROC glad_debug_glGetMaterialiv = glad_debug_impl_glGetMaterialiv;
PFNGLGETMINMAXPROC glad_glGetMinmax = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values) {
    _pre_call_gl_callback("glGetMinmax", (GLADapiproc) glad_glGetMinmax, 5, target, reset, format, type, values);
    glad_glGetMinmax(target, reset, format, type, values);
    _post_call_gl_callback(NULL, "glGetMinmax", (GLADapiproc) glad_glGetMinmax, 5, target, reset, format, type, values);
    
}
PFNGLGETMINMAXPROC glad_debug_glGetMinmax = glad_debug_impl_glGetMinmax;
PFNGLGETMINMAXPARAMETERFVPROC glad_glGetMinmaxParameterfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetMinmaxParameterfv", (GLADapiproc) glad_glGetMinmaxParameterfv, 3, target, pname, params);
    glad_glGetMinmaxParameterfv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetMinmaxParameterfv", (GLADapiproc) glad_glGetMinmaxParameterfv, 3, target, pname, params);
    
}
PFNGLGETMINMAXPARAMETERFVPROC glad_debug_glGetMinmaxParameterfv = glad_debug_impl_glGetMinmaxParameterfv;
PFNGLGETMINMAXPARAMETERIVPROC glad_glGetMinmaxParameteriv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetMinmaxParameteriv", (GLADapiproc) glad_glGetMinmaxParameteriv, 3, target, pname, params);
    glad_glGetMinmaxParameteriv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetMinmaxParameteriv", (GLADapiproc) glad_glGetMinmaxParameteriv, 3, target, pname, params);
    
}
PFNGLGETMINMAXPARAMETERIVPROC glad_debug_glGetMinmaxParameteriv = glad_debug_impl_glGetMinmaxParameteriv;
PFNGLGETOBJECTLABELPROC glad_glGetObjectLabel = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label) {
    _pre_call_gl_callback("glGetObjectLabel", (GLADapiproc) glad_glGetObjectLabel, 5, identifier, name, bufSize, length, label);
    glad_glGetObjectLabel(identifier, name, bufSize, length, label);
    _post_call_gl_callback(NULL, "glGetObjectLabel", (GLADapiproc) glad_glGetObjectLabel, 5, identifier, name, bufSize, length, label);
    
}
PFNGLGETOBJECTLABELPROC glad_debug_glGetObjectLabel = glad_debug_impl_glGetObjectLabel;
PFNGLGETOBJECTPARAMETERFVARBPROC glad_glGetObjectParameterfvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetObjectParameterfvARB", (GLADapiproc) glad_glGetObjectParameterfvARB, 3, obj, pname, params);
    glad_glGetObjectParameterfvARB(obj, pname, params);
    _post_call_gl_callback(NULL, "glGetObjectParameterfvARB", (GLADapiproc) glad_glGetObjectParameterfvARB, 3, obj, pname, params);
    
}
PFNGLGETOBJECTPARAMETERFVARBPROC glad_debug_glGetObjectParameterfvARB = glad_debug_impl_glGetObjectParameterfvARB;
PFNGLGETOBJECTPARAMETERIVARBPROC glad_glGetObjectParameterivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetObjectParameterivARB", (GLADapiproc) glad_glGetObjectParameterivARB, 3, obj, pname, params);
    glad_glGetObjectParameterivARB(obj, pname, params);
    _post_call_gl_callback(NULL, "glGetObjectParameterivARB", (GLADapiproc) glad_glGetObjectParameterivARB, 3, obj, pname, params);
    
}
PFNGLGETOBJECTPARAMETERIVARBPROC glad_debug_glGetObjectParameterivARB = glad_debug_impl_glGetObjectParameterivARB;
PFNGLGETOBJECTPTRLABELPROC glad_glGetObjectPtrLabel = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetObjectPtrLabel(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label) {
    _pre_call_gl_callback("glGetObjectPtrLabel", (GLADapiproc) glad_glGetObjectPtrLabel, 4, ptr, bufSize, length, label);
    glad_glGetObjectPtrLabel(ptr, bufSize, length, label);
    _post_call_gl_callback(NULL, "glGetObjectPtrLabel", (GLADapiproc) glad_glGetObjectPtrLabel, 4, ptr, bufSize, length, label);
    
}
PFNGLGETOBJECTPTRLABELPROC glad_debug_glGetObjectPtrLabel = glad_debug_impl_glGetObjectPtrLabel;
PFNGLGETPIXELMAPFVPROC glad_glGetPixelMapfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetPixelMapfv(GLenum map, GLfloat * values) {
    _pre_call_gl_callback("glGetPixelMapfv", (GLADapiproc) glad_glGetPixelMapfv, 2, map, values);
    glad_glGetPixelMapfv(map, values);
    _post_call_gl_callback(NULL, "glGetPixelMapfv", (GLADapiproc) glad_glGetPixelMapfv, 2, map, values);
    
}
PFNGLGETPIXELMAPFVPROC glad_debug_glGetPixelMapfv = glad_debug_impl_glGetPixelMapfv;
PFNGLGETPIXELMAPUIVPROC glad_glGetPixelMapuiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetPixelMapuiv(GLenum map, GLuint * values) {
    _pre_call_gl_callback("glGetPixelMapuiv", (GLADapiproc) glad_glGetPixelMapuiv, 2, map, values);
    glad_glGetPixelMapuiv(map, values);
    _post_call_gl_callback(NULL, "glGetPixelMapuiv", (GLADapiproc) glad_glGetPixelMapuiv, 2, map, values);
    
}
PFNGLGETPIXELMAPUIVPROC glad_debug_glGetPixelMapuiv = glad_debug_impl_glGetPixelMapuiv;
PFNGLGETPIXELMAPUSVPROC glad_glGetPixelMapusv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetPixelMapusv(GLenum map, GLushort * values) {
    _pre_call_gl_callback("glGetPixelMapusv", (GLADapiproc) glad_glGetPixelMapusv, 2, map, values);
    glad_glGetPixelMapusv(map, values);
    _post_call_gl_callback(NULL, "glGetPixelMapusv", (GLADapiproc) glad_glGetPixelMapusv, 2, map, values);
    
}
PFNGLGETPIXELMAPUSVPROC glad_debug_glGetPixelMapusv = glad_debug_impl_glGetPixelMapusv;
PFNGLGETPOINTERVPROC glad_glGetPointerv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetPointerv(GLenum pname, void ** params) {
    _pre_call_gl_callback("glGetPointerv", (GLADapiproc) glad_glGetPointerv, 2, pname, params);
    glad_glGetPointerv(pname, params);
    _post_call_gl_callback(NULL, "glGetPointerv", (GLADapiproc) glad_glGetPointerv, 2, pname, params);
    
}
PFNGLGETPOINTERVPROC glad_debug_glGetPointerv = glad_debug_impl_glGetPointerv;
PFNGLGETPOINTERVEXTPROC glad_glGetPointervEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetPointervEXT(GLenum pname, void ** params) {
    _pre_call_gl_callback("glGetPointervEXT", (GLADapiproc) glad_glGetPointervEXT, 2, pname, params);
    glad_glGetPointervEXT(pname, params);
    _post_call_gl_callback(NULL, "glGetPointervEXT", (GLADapiproc) glad_glGetPointervEXT, 2, pname, params);
    
}
PFNGLGETPOINTERVEXTPROC glad_debug_glGetPointervEXT = glad_debug_impl_glGetPointervEXT;
PFNGLGETPOLYGONSTIPPLEPROC glad_glGetPolygonStipple = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetPolygonStipple(GLubyte * mask) {
    _pre_call_gl_callback("glGetPolygonStipple", (GLADapiproc) glad_glGetPolygonStipple, 1, mask);
    glad_glGetPolygonStipple(mask);
    _post_call_gl_callback(NULL, "glGetPolygonStipple", (GLADapiproc) glad_glGetPolygonStipple, 1, mask);
    
}
PFNGLGETPOLYGONSTIPPLEPROC glad_debug_glGetPolygonStipple = glad_debug_impl_glGetPolygonStipple;
PFNGLGETPROGRAMENVPARAMETERDVARBPROC glad_glGetProgramEnvParameterdvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble * params) {
    _pre_call_gl_callback("glGetProgramEnvParameterdvARB", (GLADapiproc) glad_glGetProgramEnvParameterdvARB, 3, target, index, params);
    glad_glGetProgramEnvParameterdvARB(target, index, params);
    _post_call_gl_callback(NULL, "glGetProgramEnvParameterdvARB", (GLADapiproc) glad_glGetProgramEnvParameterdvARB, 3, target, index, params);
    
}
PFNGLGETPROGRAMENVPARAMETERDVARBPROC glad_debug_glGetProgramEnvParameterdvARB = glad_debug_impl_glGetProgramEnvParameterdvARB;
PFNGLGETPROGRAMENVPARAMETERFVARBPROC glad_glGetProgramEnvParameterfvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat * params) {
    _pre_call_gl_callback("glGetProgramEnvParameterfvARB", (GLADapiproc) glad_glGetProgramEnvParameterfvARB, 3, target, index, params);
    glad_glGetProgramEnvParameterfvARB(target, index, params);
    _post_call_gl_callback(NULL, "glGetProgramEnvParameterfvARB", (GLADapiproc) glad_glGetProgramEnvParameterfvARB, 3, target, index, params);
    
}
PFNGLGETPROGRAMENVPARAMETERFVARBPROC glad_debug_glGetProgramEnvParameterfvARB = glad_debug_impl_glGetProgramEnvParameterfvARB;
PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    _pre_call_gl_callback("glGetProgramInfoLog", (GLADapiproc) glad_glGetProgramInfoLog, 4, program, bufSize, length, infoLog);
    glad_glGetProgramInfoLog(program, bufSize, length, infoLog);
    _post_call_gl_callback(NULL, "glGetProgramInfoLog", (GLADapiproc) glad_glGetProgramInfoLog, 4, program, bufSize, length, infoLog);
    
}
PFNGLGETPROGRAMINFOLOGPROC glad_debug_glGetProgramInfoLog = glad_debug_impl_glGetProgramInfoLog;
PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glad_glGetProgramLocalParameterdvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble * params) {
    _pre_call_gl_callback("glGetProgramLocalParameterdvARB", (GLADapiproc) glad_glGetProgramLocalParameterdvARB, 3, target, index, params);
    glad_glGetProgramLocalParameterdvARB(target, index, params);
    _post_call_gl_callback(NULL, "glGetProgramLocalParameterdvARB", (GLADapiproc) glad_glGetProgramLocalParameterdvARB, 3, target, index, params);
    
}
PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glad_debug_glGetProgramLocalParameterdvARB = glad_debug_impl_glGetProgramLocalParameterdvARB;
PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glad_glGetProgramLocalParameterfvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat * params) {
    _pre_call_gl_callback("glGetProgramLocalParameterfvARB", (GLADapiproc) glad_glGetProgramLocalParameterfvARB, 3, target, index, params);
    glad_glGetProgramLocalParameterfvARB(target, index, params);
    _post_call_gl_callback(NULL, "glGetProgramLocalParameterfvARB", (GLADapiproc) glad_glGetProgramLocalParameterfvARB, 3, target, index, params);
    
}
PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glad_debug_glGetProgramLocalParameterfvARB = glad_debug_impl_glGetProgramLocalParameterfvARB;
PFNGLGETPROGRAMPARAMETERDVNVPROC glad_glGetProgramParameterdvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetProgramParameterdvNV(GLenum target, GLuint index, GLenum pname, GLdouble * params) {
    _pre_call_gl_callback("glGetProgramParameterdvNV", (GLADapiproc) glad_glGetProgramParameterdvNV, 4, target, index, pname, params);
    glad_glGetProgramParameterdvNV(target, index, pname, params);
    _post_call_gl_callback(NULL, "glGetProgramParameterdvNV", (GLADapiproc) glad_glGetProgramParameterdvNV, 4, target, index, pname, params);
    
}
PFNGLGETPROGRAMPARAMETERDVNVPROC glad_debug_glGetProgramParameterdvNV = glad_debug_impl_glGetProgramParameterdvNV;
PFNGLGETPROGRAMPARAMETERFVNVPROC glad_glGetProgramParameterfvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetProgramParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetProgramParameterfvNV", (GLADapiproc) glad_glGetProgramParameterfvNV, 4, target, index, pname, params);
    glad_glGetProgramParameterfvNV(target, index, pname, params);
    _post_call_gl_callback(NULL, "glGetProgramParameterfvNV", (GLADapiproc) glad_glGetProgramParameterfvNV, 4, target, index, pname, params);
    
}
PFNGLGETPROGRAMPARAMETERFVNVPROC glad_debug_glGetProgramParameterfvNV = glad_debug_impl_glGetProgramParameterfvNV;
PFNGLGETPROGRAMSTRINGARBPROC glad_glGetProgramStringARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetProgramStringARB(GLenum target, GLenum pname, void * string) {
    _pre_call_gl_callback("glGetProgramStringARB", (GLADapiproc) glad_glGetProgramStringARB, 3, target, pname, string);
    glad_glGetProgramStringARB(target, pname, string);
    _post_call_gl_callback(NULL, "glGetProgramStringARB", (GLADapiproc) glad_glGetProgramStringARB, 3, target, pname, string);
    
}
PFNGLGETPROGRAMSTRINGARBPROC glad_debug_glGetProgramStringARB = glad_debug_impl_glGetProgramStringARB;
PFNGLGETPROGRAMSTRINGNVPROC glad_glGetProgramStringNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetProgramStringNV(GLuint id, GLenum pname, GLubyte * program) {
    _pre_call_gl_callback("glGetProgramStringNV", (GLADapiproc) glad_glGetProgramStringNV, 3, id, pname, program);
    glad_glGetProgramStringNV(id, pname, program);
    _post_call_gl_callback(NULL, "glGetProgramStringNV", (GLADapiproc) glad_glGetProgramStringNV, 3, id, pname, program);
    
}
PFNGLGETPROGRAMSTRINGNVPROC glad_debug_glGetProgramStringNV = glad_debug_impl_glGetProgramStringNV;
PFNGLGETPROGRAMIVPROC glad_glGetProgramiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetProgramiv(GLuint program, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetProgramiv", (GLADapiproc) glad_glGetProgramiv, 3, program, pname, params);
    glad_glGetProgramiv(program, pname, params);
    _post_call_gl_callback(NULL, "glGetProgramiv", (GLADapiproc) glad_glGetProgramiv, 3, program, pname, params);
    
}
PFNGLGETPROGRAMIVPROC glad_debug_glGetProgramiv = glad_debug_impl_glGetProgramiv;
PFNGLGETPROGRAMIVARBPROC glad_glGetProgramivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetProgramivARB(GLenum target, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetProgramivARB", (GLADapiproc) glad_glGetProgramivARB, 3, target, pname, params);
    glad_glGetProgramivARB(target, pname, params);
    _post_call_gl_callback(NULL, "glGetProgramivARB", (GLADapiproc) glad_glGetProgramivARB, 3, target, pname, params);
    
}
PFNGLGETPROGRAMIVARBPROC glad_debug_glGetProgramivARB = glad_debug_impl_glGetProgramivARB;
PFNGLGETPROGRAMIVNVPROC glad_glGetProgramivNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetProgramivNV(GLuint id, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetProgramivNV", (GLADapiproc) glad_glGetProgramivNV, 3, id, pname, params);
    glad_glGetProgramivNV(id, pname, params);
    _post_call_gl_callback(NULL, "glGetProgramivNV", (GLADapiproc) glad_glGetProgramivNV, 3, id, pname, params);
    
}
PFNGLGETPROGRAMIVNVPROC glad_debug_glGetProgramivNV = glad_debug_impl_glGetProgramivNV;
PFNGLGETQUERYOBJECTIVPROC glad_glGetQueryObjectiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetQueryObjectiv", (GLADapiproc) glad_glGetQueryObjectiv, 3, id, pname, params);
    glad_glGetQueryObjectiv(id, pname, params);
    _post_call_gl_callback(NULL, "glGetQueryObjectiv", (GLADapiproc) glad_glGetQueryObjectiv, 3, id, pname, params);
    
}
PFNGLGETQUERYOBJECTIVPROC glad_debug_glGetQueryObjectiv = glad_debug_impl_glGetQueryObjectiv;
PFNGLGETQUERYOBJECTIVARBPROC glad_glGetQueryObjectivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetQueryObjectivARB(GLuint id, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetQueryObjectivARB", (GLADapiproc) glad_glGetQueryObjectivARB, 3, id, pname, params);
    glad_glGetQueryObjectivARB(id, pname, params);
    _post_call_gl_callback(NULL, "glGetQueryObjectivARB", (GLADapiproc) glad_glGetQueryObjectivARB, 3, id, pname, params);
    
}
PFNGLGETQUERYOBJECTIVARBPROC glad_debug_glGetQueryObjectivARB = glad_debug_impl_glGetQueryObjectivARB;
PFNGLGETQUERYOBJECTUIVPROC glad_glGetQueryObjectuiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) {
    _pre_call_gl_callback("glGetQueryObjectuiv", (GLADapiproc) glad_glGetQueryObjectuiv, 3, id, pname, params);
    glad_glGetQueryObjectuiv(id, pname, params);
    _post_call_gl_callback(NULL, "glGetQueryObjectuiv", (GLADapiproc) glad_glGetQueryObjectuiv, 3, id, pname, params);
    
}
PFNGLGETQUERYOBJECTUIVPROC glad_debug_glGetQueryObjectuiv = glad_debug_impl_glGetQueryObjectuiv;
PFNGLGETQUERYOBJECTUIVARBPROC glad_glGetQueryObjectuivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint * params) {
    _pre_call_gl_callback("glGetQueryObjectuivARB", (GLADapiproc) glad_glGetQueryObjectuivARB, 3, id, pname, params);
    glad_glGetQueryObjectuivARB(id, pname, params);
    _post_call_gl_callback(NULL, "glGetQueryObjectuivARB", (GLADapiproc) glad_glGetQueryObjectuivARB, 3, id, pname, params);
    
}
PFNGLGETQUERYOBJECTUIVARBPROC glad_debug_glGetQueryObjectuivARB = glad_debug_impl_glGetQueryObjectuivARB;
PFNGLGETQUERYIVPROC glad_glGetQueryiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetQueryiv(GLenum target, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetQueryiv", (GLADapiproc) glad_glGetQueryiv, 3, target, pname, params);
    glad_glGetQueryiv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetQueryiv", (GLADapiproc) glad_glGetQueryiv, 3, target, pname, params);
    
}
PFNGLGETQUERYIVPROC glad_debug_glGetQueryiv = glad_debug_impl_glGetQueryiv;
PFNGLGETQUERYIVARBPROC glad_glGetQueryivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetQueryivARB(GLenum target, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetQueryivARB", (GLADapiproc) glad_glGetQueryivARB, 3, target, pname, params);
    glad_glGetQueryivARB(target, pname, params);
    _post_call_gl_callback(NULL, "glGetQueryivARB", (GLADapiproc) glad_glGetQueryivARB, 3, target, pname, params);
    
}
PFNGLGETQUERYIVARBPROC glad_debug_glGetQueryivARB = glad_debug_impl_glGetQueryivARB;
PFNGLGETSEPARABLEFILTERPROC glad_glGetSeparableFilter = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetSeparableFilter(GLenum target, GLenum format, GLenum type, void * row, void * column, void * span) {
    _pre_call_gl_callback("glGetSeparableFilter", (GLADapiproc) glad_glGetSeparableFilter, 6, target, format, type, row, column, span);
    glad_glGetSeparableFilter(target, format, type, row, column, span);
    _post_call_gl_callback(NULL, "glGetSeparableFilter", (GLADapiproc) glad_glGetSeparableFilter, 6, target, format, type, row, column, span);
    
}
PFNGLGETSEPARABLEFILTERPROC glad_debug_glGetSeparableFilter = glad_debug_impl_glGetSeparableFilter;
PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    _pre_call_gl_callback("glGetShaderInfoLog", (GLADapiproc) glad_glGetShaderInfoLog, 4, shader, bufSize, length, infoLog);
    glad_glGetShaderInfoLog(shader, bufSize, length, infoLog);
    _post_call_gl_callback(NULL, "glGetShaderInfoLog", (GLADapiproc) glad_glGetShaderInfoLog, 4, shader, bufSize, length, infoLog);
    
}
PFNGLGETSHADERINFOLOGPROC glad_debug_glGetShaderInfoLog = glad_debug_impl_glGetShaderInfoLog;
PFNGLGETSHADERSOURCEPROC glad_glGetShaderSource = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
    _pre_call_gl_callback("glGetShaderSource", (GLADapiproc) glad_glGetShaderSource, 4, shader, bufSize, length, source);
    glad_glGetShaderSource(shader, bufSize, length, source);
    _post_call_gl_callback(NULL, "glGetShaderSource", (GLADapiproc) glad_glGetShaderSource, 4, shader, bufSize, length, source);
    
}
PFNGLGETSHADERSOURCEPROC glad_debug_glGetShaderSource = glad_debug_impl_glGetShaderSource;
PFNGLGETSHADERSOURCEARBPROC glad_glGetShaderSourceARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * source) {
    _pre_call_gl_callback("glGetShaderSourceARB", (GLADapiproc) glad_glGetShaderSourceARB, 4, obj, maxLength, length, source);
    glad_glGetShaderSourceARB(obj, maxLength, length, source);
    _post_call_gl_callback(NULL, "glGetShaderSourceARB", (GLADapiproc) glad_glGetShaderSourceARB, 4, obj, maxLength, length, source);
    
}
PFNGLGETSHADERSOURCEARBPROC glad_debug_glGetShaderSourceARB = glad_debug_impl_glGetShaderSourceARB;
PFNGLGETSHADERIVPROC glad_glGetShaderiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetShaderiv(GLuint shader, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetShaderiv", (GLADapiproc) glad_glGetShaderiv, 3, shader, pname, params);
    glad_glGetShaderiv(shader, pname, params);
    _post_call_gl_callback(NULL, "glGetShaderiv", (GLADapiproc) glad_glGetShaderiv, 3, shader, pname, params);
    
}
PFNGLGETSHADERIVPROC glad_debug_glGetShaderiv = glad_debug_impl_glGetShaderiv;
PFNGLGETSTRINGPROC glad_glGetString = NULL;
static const GLubyte * GLAD_API_PTR glad_debug_impl_glGetString(GLenum name) {
    const GLubyte * ret;
    _pre_call_gl_callback("glGetString", (GLADapiproc) glad_glGetString, 1, name);
    ret = glad_glGetString(name);
    _post_call_gl_callback((void*) &ret, "glGetString", (GLADapiproc) glad_glGetString, 1, name);
    return ret;
}
PFNGLGETSTRINGPROC glad_debug_glGetString = glad_debug_impl_glGetString;
PFNGLGETTEXENVFVPROC glad_glGetTexEnvfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetTexEnvfv", (GLADapiproc) glad_glGetTexEnvfv, 3, target, pname, params);
    glad_glGetTexEnvfv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetTexEnvfv", (GLADapiproc) glad_glGetTexEnvfv, 3, target, pname, params);
    
}
PFNGLGETTEXENVFVPROC glad_debug_glGetTexEnvfv = glad_debug_impl_glGetTexEnvfv;
PFNGLGETTEXENVIVPROC glad_glGetTexEnviv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetTexEnviv", (GLADapiproc) glad_glGetTexEnviv, 3, target, pname, params);
    glad_glGetTexEnviv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetTexEnviv", (GLADapiproc) glad_glGetTexEnviv, 3, target, pname, params);
    
}
PFNGLGETTEXENVIVPROC glad_debug_glGetTexEnviv = glad_debug_impl_glGetTexEnviv;
PFNGLGETTEXGENDVPROC glad_glGetTexGendv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params) {
    _pre_call_gl_callback("glGetTexGendv", (GLADapiproc) glad_glGetTexGendv, 3, coord, pname, params);
    glad_glGetTexGendv(coord, pname, params);
    _post_call_gl_callback(NULL, "glGetTexGendv", (GLADapiproc) glad_glGetTexGendv, 3, coord, pname, params);
    
}
PFNGLGETTEXGENDVPROC glad_debug_glGetTexGendv = glad_debug_impl_glGetTexGendv;
PFNGLGETTEXGENFVPROC glad_glGetTexGenfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetTexGenfv", (GLADapiproc) glad_glGetTexGenfv, 3, coord, pname, params);
    glad_glGetTexGenfv(coord, pname, params);
    _post_call_gl_callback(NULL, "glGetTexGenfv", (GLADapiproc) glad_glGetTexGenfv, 3, coord, pname, params);
    
}
PFNGLGETTEXGENFVPROC glad_debug_glGetTexGenfv = glad_debug_impl_glGetTexGenfv;
PFNGLGETTEXGENIVPROC glad_glGetTexGeniv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetTexGeniv(GLenum coord, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetTexGeniv", (GLADapiproc) glad_glGetTexGeniv, 3, coord, pname, params);
    glad_glGetTexGeniv(coord, pname, params);
    _post_call_gl_callback(NULL, "glGetTexGeniv", (GLADapiproc) glad_glGetTexGeniv, 3, coord, pname, params);
    
}
PFNGLGETTEXGENIVPROC glad_debug_glGetTexGeniv = glad_debug_impl_glGetTexGeniv;
PFNGLGETTEXIMAGEPROC glad_glGetTexImage = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void * pixels) {
    _pre_call_gl_callback("glGetTexImage", (GLADapiproc) glad_glGetTexImage, 5, target, level, format, type, pixels);
    glad_glGetTexImage(target, level, format, type, pixels);
    _post_call_gl_callback(NULL, "glGetTexImage", (GLADapiproc) glad_glGetTexImage, 5, target, level, format, type, pixels);
    
}
PFNGLGETTEXIMAGEPROC glad_debug_glGetTexImage = glad_debug_impl_glGetTexImage;
PFNGLGETTEXLEVELPARAMETERFVPROC glad_glGetTexLevelParameterfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetTexLevelParameterfv", (GLADapiproc) glad_glGetTexLevelParameterfv, 4, target, level, pname, params);
    glad_glGetTexLevelParameterfv(target, level, pname, params);
    _post_call_gl_callback(NULL, "glGetTexLevelParameterfv", (GLADapiproc) glad_glGetTexLevelParameterfv, 4, target, level, pname, params);
    
}
PFNGLGETTEXLEVELPARAMETERFVPROC glad_debug_glGetTexLevelParameterfv = glad_debug_impl_glGetTexLevelParameterfv;
PFNGLGETTEXLEVELPARAMETERIVPROC glad_glGetTexLevelParameteriv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetTexLevelParameteriv", (GLADapiproc) glad_glGetTexLevelParameteriv, 4, target, level, pname, params);
    glad_glGetTexLevelParameteriv(target, level, pname, params);
    _post_call_gl_callback(NULL, "glGetTexLevelParameteriv", (GLADapiproc) glad_glGetTexLevelParameteriv, 4, target, level, pname, params);
    
}
PFNGLGETTEXLEVELPARAMETERIVPROC glad_debug_glGetTexLevelParameteriv = glad_debug_impl_glGetTexLevelParameteriv;
PFNGLGETTEXPARAMETERFVPROC glad_glGetTexParameterfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetTexParameterfv", (GLADapiproc) glad_glGetTexParameterfv, 3, target, pname, params);
    glad_glGetTexParameterfv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetTexParameterfv", (GLADapiproc) glad_glGetTexParameterfv, 3, target, pname, params);
    
}
PFNGLGETTEXPARAMETERFVPROC glad_debug_glGetTexParameterfv = glad_debug_impl_glGetTexParameterfv;
PFNGLGETTEXPARAMETERIVPROC glad_glGetTexParameteriv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetTexParameteriv", (GLADapiproc) glad_glGetTexParameteriv, 3, target, pname, params);
    glad_glGetTexParameteriv(target, pname, params);
    _post_call_gl_callback(NULL, "glGetTexParameteriv", (GLADapiproc) glad_glGetTexParameteriv, 3, target, pname, params);
    
}
PFNGLGETTEXPARAMETERIVPROC glad_debug_glGetTexParameteriv = glad_debug_impl_glGetTexParameteriv;
PFNGLGETTRACKMATRIXIVNVPROC glad_glGetTrackMatrixivNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetTrackMatrixivNV(GLenum target, GLuint address, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetTrackMatrixivNV", (GLADapiproc) glad_glGetTrackMatrixivNV, 4, target, address, pname, params);
    glad_glGetTrackMatrixivNV(target, address, pname, params);
    _post_call_gl_callback(NULL, "glGetTrackMatrixivNV", (GLADapiproc) glad_glGetTrackMatrixivNV, 4, target, address, pname, params);
    
}
PFNGLGETTRACKMATRIXIVNVPROC glad_debug_glGetTrackMatrixivNV = glad_debug_impl_glGetTrackMatrixivNV;
PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation = NULL;
static GLint GLAD_API_PTR glad_debug_impl_glGetUniformLocation(GLuint program, const GLchar * name) {
    GLint ret;
    _pre_call_gl_callback("glGetUniformLocation", (GLADapiproc) glad_glGetUniformLocation, 2, program, name);
    ret = glad_glGetUniformLocation(program, name);
    _post_call_gl_callback((void*) &ret, "glGetUniformLocation", (GLADapiproc) glad_glGetUniformLocation, 2, program, name);
    return ret;
}
PFNGLGETUNIFORMLOCATIONPROC glad_debug_glGetUniformLocation = glad_debug_impl_glGetUniformLocation;
PFNGLGETUNIFORMLOCATIONARBPROC glad_glGetUniformLocationARB = NULL;
static GLint GLAD_API_PTR glad_debug_impl_glGetUniformLocationARB(GLhandleARB programObj, const GLcharARB * name) {
    GLint ret;
    _pre_call_gl_callback("glGetUniformLocationARB", (GLADapiproc) glad_glGetUniformLocationARB, 2, programObj, name);
    ret = glad_glGetUniformLocationARB(programObj, name);
    _post_call_gl_callback((void*) &ret, "glGetUniformLocationARB", (GLADapiproc) glad_glGetUniformLocationARB, 2, programObj, name);
    return ret;
}
PFNGLGETUNIFORMLOCATIONARBPROC glad_debug_glGetUniformLocationARB = glad_debug_impl_glGetUniformLocationARB;
PFNGLGETUNIFORMFVPROC glad_glGetUniformfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetUniformfv(GLuint program, GLint location, GLfloat * params) {
    _pre_call_gl_callback("glGetUniformfv", (GLADapiproc) glad_glGetUniformfv, 3, program, location, params);
    glad_glGetUniformfv(program, location, params);
    _post_call_gl_callback(NULL, "glGetUniformfv", (GLADapiproc) glad_glGetUniformfv, 3, program, location, params);
    
}
PFNGLGETUNIFORMFVPROC glad_debug_glGetUniformfv = glad_debug_impl_glGetUniformfv;
PFNGLGETUNIFORMFVARBPROC glad_glGetUniformfvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat * params) {
    _pre_call_gl_callback("glGetUniformfvARB", (GLADapiproc) glad_glGetUniformfvARB, 3, programObj, location, params);
    glad_glGetUniformfvARB(programObj, location, params);
    _post_call_gl_callback(NULL, "glGetUniformfvARB", (GLADapiproc) glad_glGetUniformfvARB, 3, programObj, location, params);
    
}
PFNGLGETUNIFORMFVARBPROC glad_debug_glGetUniformfvARB = glad_debug_impl_glGetUniformfvARB;
PFNGLGETUNIFORMIVPROC glad_glGetUniformiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetUniformiv(GLuint program, GLint location, GLint * params) {
    _pre_call_gl_callback("glGetUniformiv", (GLADapiproc) glad_glGetUniformiv, 3, program, location, params);
    glad_glGetUniformiv(program, location, params);
    _post_call_gl_callback(NULL, "glGetUniformiv", (GLADapiproc) glad_glGetUniformiv, 3, program, location, params);
    
}
PFNGLGETUNIFORMIVPROC glad_debug_glGetUniformiv = glad_debug_impl_glGetUniformiv;
PFNGLGETUNIFORMIVARBPROC glad_glGetUniformivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetUniformivARB(GLhandleARB programObj, GLint location, GLint * params) {
    _pre_call_gl_callback("glGetUniformivARB", (GLADapiproc) glad_glGetUniformivARB, 3, programObj, location, params);
    glad_glGetUniformivARB(programObj, location, params);
    _post_call_gl_callback(NULL, "glGetUniformivARB", (GLADapiproc) glad_glGetUniformivARB, 3, programObj, location, params);
    
}
PFNGLGETUNIFORMIVARBPROC glad_debug_glGetUniformivARB = glad_debug_impl_glGetUniformivARB;
PFNGLGETVERTEXATTRIBPOINTERVPROC glad_glGetVertexAttribPointerv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer) {
    _pre_call_gl_callback("glGetVertexAttribPointerv", (GLADapiproc) glad_glGetVertexAttribPointerv, 3, index, pname, pointer);
    glad_glGetVertexAttribPointerv(index, pname, pointer);
    _post_call_gl_callback(NULL, "glGetVertexAttribPointerv", (GLADapiproc) glad_glGetVertexAttribPointerv, 3, index, pname, pointer);
    
}
PFNGLGETVERTEXATTRIBPOINTERVPROC glad_debug_glGetVertexAttribPointerv = glad_debug_impl_glGetVertexAttribPointerv;
PFNGLGETVERTEXATTRIBPOINTERVARBPROC glad_glGetVertexAttribPointervARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetVertexAttribPointervARB(GLuint index, GLenum pname, void ** pointer) {
    _pre_call_gl_callback("glGetVertexAttribPointervARB", (GLADapiproc) glad_glGetVertexAttribPointervARB, 3, index, pname, pointer);
    glad_glGetVertexAttribPointervARB(index, pname, pointer);
    _post_call_gl_callback(NULL, "glGetVertexAttribPointervARB", (GLADapiproc) glad_glGetVertexAttribPointervARB, 3, index, pname, pointer);
    
}
PFNGLGETVERTEXATTRIBPOINTERVARBPROC glad_debug_glGetVertexAttribPointervARB = glad_debug_impl_glGetVertexAttribPointervARB;
PFNGLGETVERTEXATTRIBPOINTERVNVPROC glad_glGetVertexAttribPointervNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetVertexAttribPointervNV(GLuint index, GLenum pname, void ** pointer) {
    _pre_call_gl_callback("glGetVertexAttribPointervNV", (GLADapiproc) glad_glGetVertexAttribPointervNV, 3, index, pname, pointer);
    glad_glGetVertexAttribPointervNV(index, pname, pointer);
    _post_call_gl_callback(NULL, "glGetVertexAttribPointervNV", (GLADapiproc) glad_glGetVertexAttribPointervNV, 3, index, pname, pointer);
    
}
PFNGLGETVERTEXATTRIBPOINTERVNVPROC glad_debug_glGetVertexAttribPointervNV = glad_debug_impl_glGetVertexAttribPointervNV;
PFNGLGETVERTEXATTRIBDVPROC glad_glGetVertexAttribdv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble * params) {
    _pre_call_gl_callback("glGetVertexAttribdv", (GLADapiproc) glad_glGetVertexAttribdv, 3, index, pname, params);
    glad_glGetVertexAttribdv(index, pname, params);
    _post_call_gl_callback(NULL, "glGetVertexAttribdv", (GLADapiproc) glad_glGetVertexAttribdv, 3, index, pname, params);
    
}
PFNGLGETVERTEXATTRIBDVPROC glad_debug_glGetVertexAttribdv = glad_debug_impl_glGetVertexAttribdv;
PFNGLGETVERTEXATTRIBDVARBPROC glad_glGetVertexAttribdvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble * params) {
    _pre_call_gl_callback("glGetVertexAttribdvARB", (GLADapiproc) glad_glGetVertexAttribdvARB, 3, index, pname, params);
    glad_glGetVertexAttribdvARB(index, pname, params);
    _post_call_gl_callback(NULL, "glGetVertexAttribdvARB", (GLADapiproc) glad_glGetVertexAttribdvARB, 3, index, pname, params);
    
}
PFNGLGETVERTEXATTRIBDVARBPROC glad_debug_glGetVertexAttribdvARB = glad_debug_impl_glGetVertexAttribdvARB;
PFNGLGETVERTEXATTRIBDVNVPROC glad_glGetVertexAttribdvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetVertexAttribdvNV(GLuint index, GLenum pname, GLdouble * params) {
    _pre_call_gl_callback("glGetVertexAttribdvNV", (GLADapiproc) glad_glGetVertexAttribdvNV, 3, index, pname, params);
    glad_glGetVertexAttribdvNV(index, pname, params);
    _post_call_gl_callback(NULL, "glGetVertexAttribdvNV", (GLADapiproc) glad_glGetVertexAttribdvNV, 3, index, pname, params);
    
}
PFNGLGETVERTEXATTRIBDVNVPROC glad_debug_glGetVertexAttribdvNV = glad_debug_impl_glGetVertexAttribdvNV;
PFNGLGETVERTEXATTRIBFVPROC glad_glGetVertexAttribfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetVertexAttribfv", (GLADapiproc) glad_glGetVertexAttribfv, 3, index, pname, params);
    glad_glGetVertexAttribfv(index, pname, params);
    _post_call_gl_callback(NULL, "glGetVertexAttribfv", (GLADapiproc) glad_glGetVertexAttribfv, 3, index, pname, params);
    
}
PFNGLGETVERTEXATTRIBFVPROC glad_debug_glGetVertexAttribfv = glad_debug_impl_glGetVertexAttribfv;
PFNGLGETVERTEXATTRIBFVARBPROC glad_glGetVertexAttribfvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetVertexAttribfvARB", (GLADapiproc) glad_glGetVertexAttribfvARB, 3, index, pname, params);
    glad_glGetVertexAttribfvARB(index, pname, params);
    _post_call_gl_callback(NULL, "glGetVertexAttribfvARB", (GLADapiproc) glad_glGetVertexAttribfvARB, 3, index, pname, params);
    
}
PFNGLGETVERTEXATTRIBFVARBPROC glad_debug_glGetVertexAttribfvARB = glad_debug_impl_glGetVertexAttribfvARB;
PFNGLGETVERTEXATTRIBFVNVPROC glad_glGetVertexAttribfvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetVertexAttribfvNV(GLuint index, GLenum pname, GLfloat * params) {
    _pre_call_gl_callback("glGetVertexAttribfvNV", (GLADapiproc) glad_glGetVertexAttribfvNV, 3, index, pname, params);
    glad_glGetVertexAttribfvNV(index, pname, params);
    _post_call_gl_callback(NULL, "glGetVertexAttribfvNV", (GLADapiproc) glad_glGetVertexAttribfvNV, 3, index, pname, params);
    
}
PFNGLGETVERTEXATTRIBFVNVPROC glad_debug_glGetVertexAttribfvNV = glad_debug_impl_glGetVertexAttribfvNV;
PFNGLGETVERTEXATTRIBIVPROC glad_glGetVertexAttribiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetVertexAttribiv", (GLADapiproc) glad_glGetVertexAttribiv, 3, index, pname, params);
    glad_glGetVertexAttribiv(index, pname, params);
    _post_call_gl_callback(NULL, "glGetVertexAttribiv", (GLADapiproc) glad_glGetVertexAttribiv, 3, index, pname, params);
    
}
PFNGLGETVERTEXATTRIBIVPROC glad_debug_glGetVertexAttribiv = glad_debug_impl_glGetVertexAttribiv;
PFNGLGETVERTEXATTRIBIVARBPROC glad_glGetVertexAttribivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetVertexAttribivARB(GLuint index, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetVertexAttribivARB", (GLADapiproc) glad_glGetVertexAttribivARB, 3, index, pname, params);
    glad_glGetVertexAttribivARB(index, pname, params);
    _post_call_gl_callback(NULL, "glGetVertexAttribivARB", (GLADapiproc) glad_glGetVertexAttribivARB, 3, index, pname, params);
    
}
PFNGLGETVERTEXATTRIBIVARBPROC glad_debug_glGetVertexAttribivARB = glad_debug_impl_glGetVertexAttribivARB;
PFNGLGETVERTEXATTRIBIVNVPROC glad_glGetVertexAttribivNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glGetVertexAttribivNV(GLuint index, GLenum pname, GLint * params) {
    _pre_call_gl_callback("glGetVertexAttribivNV", (GLADapiproc) glad_glGetVertexAttribivNV, 3, index, pname, params);
    glad_glGetVertexAttribivNV(index, pname, params);
    _post_call_gl_callback(NULL, "glGetVertexAttribivNV", (GLADapiproc) glad_glGetVertexAttribivNV, 3, index, pname, params);
    
}
PFNGLGETVERTEXATTRIBIVNVPROC glad_debug_glGetVertexAttribivNV = glad_debug_impl_glGetVertexAttribivNV;
PFNGLHINTPROC glad_glHint = NULL;
static void GLAD_API_PTR glad_debug_impl_glHint(GLenum target, GLenum mode) {
    _pre_call_gl_callback("glHint", (GLADapiproc) glad_glHint, 2, target, mode);
    glad_glHint(target, mode);
    _post_call_gl_callback(NULL, "glHint", (GLADapiproc) glad_glHint, 2, target, mode);
    
}
PFNGLHINTPROC glad_debug_glHint = glad_debug_impl_glHint;
PFNGLHISTOGRAMPROC glad_glHistogram = NULL;
static void GLAD_API_PTR glad_debug_impl_glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
    _pre_call_gl_callback("glHistogram", (GLADapiproc) glad_glHistogram, 4, target, width, internalformat, sink);
    glad_glHistogram(target, width, internalformat, sink);
    _post_call_gl_callback(NULL, "glHistogram", (GLADapiproc) glad_glHistogram, 4, target, width, internalformat, sink);
    
}
PFNGLHISTOGRAMPROC glad_debug_glHistogram = glad_debug_impl_glHistogram;
PFNGLINDEXMASKPROC glad_glIndexMask = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexMask(GLuint mask) {
    _pre_call_gl_callback("glIndexMask", (GLADapiproc) glad_glIndexMask, 1, mask);
    glad_glIndexMask(mask);
    _post_call_gl_callback(NULL, "glIndexMask", (GLADapiproc) glad_glIndexMask, 1, mask);
    
}
PFNGLINDEXMASKPROC glad_debug_glIndexMask = glad_debug_impl_glIndexMask;
PFNGLINDEXPOINTERPROC glad_glIndexPointer = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexPointer(GLenum type, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glIndexPointer", (GLADapiproc) glad_glIndexPointer, 3, type, stride, pointer);
    glad_glIndexPointer(type, stride, pointer);
    _post_call_gl_callback(NULL, "glIndexPointer", (GLADapiproc) glad_glIndexPointer, 3, type, stride, pointer);
    
}
PFNGLINDEXPOINTERPROC glad_debug_glIndexPointer = glad_debug_impl_glIndexPointer;
PFNGLINDEXPOINTEREXTPROC glad_glIndexPointerEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void * pointer) {
    _pre_call_gl_callback("glIndexPointerEXT", (GLADapiproc) glad_glIndexPointerEXT, 4, type, stride, count, pointer);
    glad_glIndexPointerEXT(type, stride, count, pointer);
    _post_call_gl_callback(NULL, "glIndexPointerEXT", (GLADapiproc) glad_glIndexPointerEXT, 4, type, stride, count, pointer);
    
}
PFNGLINDEXPOINTEREXTPROC glad_debug_glIndexPointerEXT = glad_debug_impl_glIndexPointerEXT;
PFNGLINDEXDPROC glad_glIndexd = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexd(GLdouble c) {
    _pre_call_gl_callback("glIndexd", (GLADapiproc) glad_glIndexd, 1, c);
    glad_glIndexd(c);
    _post_call_gl_callback(NULL, "glIndexd", (GLADapiproc) glad_glIndexd, 1, c);
    
}
PFNGLINDEXDPROC glad_debug_glIndexd = glad_debug_impl_glIndexd;
PFNGLINDEXDVPROC glad_glIndexdv = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexdv(const GLdouble * c) {
    _pre_call_gl_callback("glIndexdv", (GLADapiproc) glad_glIndexdv, 1, c);
    glad_glIndexdv(c);
    _post_call_gl_callback(NULL, "glIndexdv", (GLADapiproc) glad_glIndexdv, 1, c);
    
}
PFNGLINDEXDVPROC glad_debug_glIndexdv = glad_debug_impl_glIndexdv;
PFNGLINDEXFPROC glad_glIndexf = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexf(GLfloat c) {
    _pre_call_gl_callback("glIndexf", (GLADapiproc) glad_glIndexf, 1, c);
    glad_glIndexf(c);
    _post_call_gl_callback(NULL, "glIndexf", (GLADapiproc) glad_glIndexf, 1, c);
    
}
PFNGLINDEXFPROC glad_debug_glIndexf = glad_debug_impl_glIndexf;
PFNGLINDEXFVPROC glad_glIndexfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexfv(const GLfloat * c) {
    _pre_call_gl_callback("glIndexfv", (GLADapiproc) glad_glIndexfv, 1, c);
    glad_glIndexfv(c);
    _post_call_gl_callback(NULL, "glIndexfv", (GLADapiproc) glad_glIndexfv, 1, c);
    
}
PFNGLINDEXFVPROC glad_debug_glIndexfv = glad_debug_impl_glIndexfv;
PFNGLINDEXIPROC glad_glIndexi = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexi(GLint c) {
    _pre_call_gl_callback("glIndexi", (GLADapiproc) glad_glIndexi, 1, c);
    glad_glIndexi(c);
    _post_call_gl_callback(NULL, "glIndexi", (GLADapiproc) glad_glIndexi, 1, c);
    
}
PFNGLINDEXIPROC glad_debug_glIndexi = glad_debug_impl_glIndexi;
PFNGLINDEXIVPROC glad_glIndexiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexiv(const GLint * c) {
    _pre_call_gl_callback("glIndexiv", (GLADapiproc) glad_glIndexiv, 1, c);
    glad_glIndexiv(c);
    _post_call_gl_callback(NULL, "glIndexiv", (GLADapiproc) glad_glIndexiv, 1, c);
    
}
PFNGLINDEXIVPROC glad_debug_glIndexiv = glad_debug_impl_glIndexiv;
PFNGLINDEXSPROC glad_glIndexs = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexs(GLshort c) {
    _pre_call_gl_callback("glIndexs", (GLADapiproc) glad_glIndexs, 1, c);
    glad_glIndexs(c);
    _post_call_gl_callback(NULL, "glIndexs", (GLADapiproc) glad_glIndexs, 1, c);
    
}
PFNGLINDEXSPROC glad_debug_glIndexs = glad_debug_impl_glIndexs;
PFNGLINDEXSVPROC glad_glIndexsv = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexsv(const GLshort * c) {
    _pre_call_gl_callback("glIndexsv", (GLADapiproc) glad_glIndexsv, 1, c);
    glad_glIndexsv(c);
    _post_call_gl_callback(NULL, "glIndexsv", (GLADapiproc) glad_glIndexsv, 1, c);
    
}
PFNGLINDEXSVPROC glad_debug_glIndexsv = glad_debug_impl_glIndexsv;
PFNGLINDEXUBPROC glad_glIndexub = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexub(GLubyte c) {
    _pre_call_gl_callback("glIndexub", (GLADapiproc) glad_glIndexub, 1, c);
    glad_glIndexub(c);
    _post_call_gl_callback(NULL, "glIndexub", (GLADapiproc) glad_glIndexub, 1, c);
    
}
PFNGLINDEXUBPROC glad_debug_glIndexub = glad_debug_impl_glIndexub;
PFNGLINDEXUBVPROC glad_glIndexubv = NULL;
static void GLAD_API_PTR glad_debug_impl_glIndexubv(const GLubyte * c) {
    _pre_call_gl_callback("glIndexubv", (GLADapiproc) glad_glIndexubv, 1, c);
    glad_glIndexubv(c);
    _post_call_gl_callback(NULL, "glIndexubv", (GLADapiproc) glad_glIndexubv, 1, c);
    
}
PFNGLINDEXUBVPROC glad_debug_glIndexubv = glad_debug_impl_glIndexubv;
PFNGLINITNAMESPROC glad_glInitNames = NULL;
static void GLAD_API_PTR glad_debug_impl_glInitNames(void) {
    _pre_call_gl_callback("glInitNames", (GLADapiproc) glad_glInitNames, 0);
    glad_glInitNames();
    _post_call_gl_callback(NULL, "glInitNames", (GLADapiproc) glad_glInitNames, 0);
    
}
PFNGLINITNAMESPROC glad_debug_glInitNames = glad_debug_impl_glInitNames;
PFNGLINTERLEAVEDARRAYSPROC glad_glInterleavedArrays = NULL;
static void GLAD_API_PTR glad_debug_impl_glInterleavedArrays(GLenum format, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glInterleavedArrays", (GLADapiproc) glad_glInterleavedArrays, 3, format, stride, pointer);
    glad_glInterleavedArrays(format, stride, pointer);
    _post_call_gl_callback(NULL, "glInterleavedArrays", (GLADapiproc) glad_glInterleavedArrays, 3, format, stride, pointer);
    
}
PFNGLINTERLEAVEDARRAYSPROC glad_debug_glInterleavedArrays = glad_debug_impl_glInterleavedArrays;
PFNGLISBUFFERPROC glad_glIsBuffer = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glIsBuffer(GLuint buffer) {
    GLboolean ret;
    _pre_call_gl_callback("glIsBuffer", (GLADapiproc) glad_glIsBuffer, 1, buffer);
    ret = glad_glIsBuffer(buffer);
    _post_call_gl_callback((void*) &ret, "glIsBuffer", (GLADapiproc) glad_glIsBuffer, 1, buffer);
    return ret;
}
PFNGLISBUFFERPROC glad_debug_glIsBuffer = glad_debug_impl_glIsBuffer;
PFNGLISBUFFERARBPROC glad_glIsBufferARB = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glIsBufferARB(GLuint buffer) {
    GLboolean ret;
    _pre_call_gl_callback("glIsBufferARB", (GLADapiproc) glad_glIsBufferARB, 1, buffer);
    ret = glad_glIsBufferARB(buffer);
    _post_call_gl_callback((void*) &ret, "glIsBufferARB", (GLADapiproc) glad_glIsBufferARB, 1, buffer);
    return ret;
}
PFNGLISBUFFERARBPROC glad_debug_glIsBufferARB = glad_debug_impl_glIsBufferARB;
PFNGLISENABLEDPROC glad_glIsEnabled = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glIsEnabled(GLenum cap) {
    GLboolean ret;
    _pre_call_gl_callback("glIsEnabled", (GLADapiproc) glad_glIsEnabled, 1, cap);
    ret = glad_glIsEnabled(cap);
    _post_call_gl_callback((void*) &ret, "glIsEnabled", (GLADapiproc) glad_glIsEnabled, 1, cap);
    return ret;
}
PFNGLISENABLEDPROC glad_debug_glIsEnabled = glad_debug_impl_glIsEnabled;
PFNGLISLISTPROC glad_glIsList = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glIsList(GLuint list) {
    GLboolean ret;
    _pre_call_gl_callback("glIsList", (GLADapiproc) glad_glIsList, 1, list);
    ret = glad_glIsList(list);
    _post_call_gl_callback((void*) &ret, "glIsList", (GLADapiproc) glad_glIsList, 1, list);
    return ret;
}
PFNGLISLISTPROC glad_debug_glIsList = glad_debug_impl_glIsList;
PFNGLISPROGRAMPROC glad_glIsProgram = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glIsProgram(GLuint program) {
    GLboolean ret;
    _pre_call_gl_callback("glIsProgram", (GLADapiproc) glad_glIsProgram, 1, program);
    ret = glad_glIsProgram(program);
    _post_call_gl_callback((void*) &ret, "glIsProgram", (GLADapiproc) glad_glIsProgram, 1, program);
    return ret;
}
PFNGLISPROGRAMPROC glad_debug_glIsProgram = glad_debug_impl_glIsProgram;
PFNGLISPROGRAMARBPROC glad_glIsProgramARB = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glIsProgramARB(GLuint program) {
    GLboolean ret;
    _pre_call_gl_callback("glIsProgramARB", (GLADapiproc) glad_glIsProgramARB, 1, program);
    ret = glad_glIsProgramARB(program);
    _post_call_gl_callback((void*) &ret, "glIsProgramARB", (GLADapiproc) glad_glIsProgramARB, 1, program);
    return ret;
}
PFNGLISPROGRAMARBPROC glad_debug_glIsProgramARB = glad_debug_impl_glIsProgramARB;
PFNGLISPROGRAMNVPROC glad_glIsProgramNV = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glIsProgramNV(GLuint id) {
    GLboolean ret;
    _pre_call_gl_callback("glIsProgramNV", (GLADapiproc) glad_glIsProgramNV, 1, id);
    ret = glad_glIsProgramNV(id);
    _post_call_gl_callback((void*) &ret, "glIsProgramNV", (GLADapiproc) glad_glIsProgramNV, 1, id);
    return ret;
}
PFNGLISPROGRAMNVPROC glad_debug_glIsProgramNV = glad_debug_impl_glIsProgramNV;
PFNGLISQUERYPROC glad_glIsQuery = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glIsQuery(GLuint id) {
    GLboolean ret;
    _pre_call_gl_callback("glIsQuery", (GLADapiproc) glad_glIsQuery, 1, id);
    ret = glad_glIsQuery(id);
    _post_call_gl_callback((void*) &ret, "glIsQuery", (GLADapiproc) glad_glIsQuery, 1, id);
    return ret;
}
PFNGLISQUERYPROC glad_debug_glIsQuery = glad_debug_impl_glIsQuery;
PFNGLISQUERYARBPROC glad_glIsQueryARB = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glIsQueryARB(GLuint id) {
    GLboolean ret;
    _pre_call_gl_callback("glIsQueryARB", (GLADapiproc) glad_glIsQueryARB, 1, id);
    ret = glad_glIsQueryARB(id);
    _post_call_gl_callback((void*) &ret, "glIsQueryARB", (GLADapiproc) glad_glIsQueryARB, 1, id);
    return ret;
}
PFNGLISQUERYARBPROC glad_debug_glIsQueryARB = glad_debug_impl_glIsQueryARB;
PFNGLISSHADERPROC glad_glIsShader = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glIsShader(GLuint shader) {
    GLboolean ret;
    _pre_call_gl_callback("glIsShader", (GLADapiproc) glad_glIsShader, 1, shader);
    ret = glad_glIsShader(shader);
    _post_call_gl_callback((void*) &ret, "glIsShader", (GLADapiproc) glad_glIsShader, 1, shader);
    return ret;
}
PFNGLISSHADERPROC glad_debug_glIsShader = glad_debug_impl_glIsShader;
PFNGLISTEXTUREPROC glad_glIsTexture = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glIsTexture(GLuint texture) {
    GLboolean ret;
    _pre_call_gl_callback("glIsTexture", (GLADapiproc) glad_glIsTexture, 1, texture);
    ret = glad_glIsTexture(texture);
    _post_call_gl_callback((void*) &ret, "glIsTexture", (GLADapiproc) glad_glIsTexture, 1, texture);
    return ret;
}
PFNGLISTEXTUREPROC glad_debug_glIsTexture = glad_debug_impl_glIsTexture;
PFNGLISTEXTUREEXTPROC glad_glIsTextureEXT = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glIsTextureEXT(GLuint texture) {
    GLboolean ret;
    _pre_call_gl_callback("glIsTextureEXT", (GLADapiproc) glad_glIsTextureEXT, 1, texture);
    ret = glad_glIsTextureEXT(texture);
    _post_call_gl_callback((void*) &ret, "glIsTextureEXT", (GLADapiproc) glad_glIsTextureEXT, 1, texture);
    return ret;
}
PFNGLISTEXTUREEXTPROC glad_debug_glIsTextureEXT = glad_debug_impl_glIsTextureEXT;
PFNGLLIGHTMODELFPROC glad_glLightModelf = NULL;
static void GLAD_API_PTR glad_debug_impl_glLightModelf(GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glLightModelf", (GLADapiproc) glad_glLightModelf, 2, pname, param);
    glad_glLightModelf(pname, param);
    _post_call_gl_callback(NULL, "glLightModelf", (GLADapiproc) glad_glLightModelf, 2, pname, param);
    
}
PFNGLLIGHTMODELFPROC glad_debug_glLightModelf = glad_debug_impl_glLightModelf;
PFNGLLIGHTMODELFVPROC glad_glLightModelfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glLightModelfv(GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glLightModelfv", (GLADapiproc) glad_glLightModelfv, 2, pname, params);
    glad_glLightModelfv(pname, params);
    _post_call_gl_callback(NULL, "glLightModelfv", (GLADapiproc) glad_glLightModelfv, 2, pname, params);
    
}
PFNGLLIGHTMODELFVPROC glad_debug_glLightModelfv = glad_debug_impl_glLightModelfv;
PFNGLLIGHTMODELIPROC glad_glLightModeli = NULL;
static void GLAD_API_PTR glad_debug_impl_glLightModeli(GLenum pname, GLint param) {
    _pre_call_gl_callback("glLightModeli", (GLADapiproc) glad_glLightModeli, 2, pname, param);
    glad_glLightModeli(pname, param);
    _post_call_gl_callback(NULL, "glLightModeli", (GLADapiproc) glad_glLightModeli, 2, pname, param);
    
}
PFNGLLIGHTMODELIPROC glad_debug_glLightModeli = glad_debug_impl_glLightModeli;
PFNGLLIGHTMODELIVPROC glad_glLightModeliv = NULL;
static void GLAD_API_PTR glad_debug_impl_glLightModeliv(GLenum pname, const GLint * params) {
    _pre_call_gl_callback("glLightModeliv", (GLADapiproc) glad_glLightModeliv, 2, pname, params);
    glad_glLightModeliv(pname, params);
    _post_call_gl_callback(NULL, "glLightModeliv", (GLADapiproc) glad_glLightModeliv, 2, pname, params);
    
}
PFNGLLIGHTMODELIVPROC glad_debug_glLightModeliv = glad_debug_impl_glLightModeliv;
PFNGLLIGHTFPROC glad_glLightf = NULL;
static void GLAD_API_PTR glad_debug_impl_glLightf(GLenum light, GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glLightf", (GLADapiproc) glad_glLightf, 3, light, pname, param);
    glad_glLightf(light, pname, param);
    _post_call_gl_callback(NULL, "glLightf", (GLADapiproc) glad_glLightf, 3, light, pname, param);
    
}
PFNGLLIGHTFPROC glad_debug_glLightf = glad_debug_impl_glLightf;
PFNGLLIGHTFVPROC glad_glLightfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glLightfv", (GLADapiproc) glad_glLightfv, 3, light, pname, params);
    glad_glLightfv(light, pname, params);
    _post_call_gl_callback(NULL, "glLightfv", (GLADapiproc) glad_glLightfv, 3, light, pname, params);
    
}
PFNGLLIGHTFVPROC glad_debug_glLightfv = glad_debug_impl_glLightfv;
PFNGLLIGHTIPROC glad_glLighti = NULL;
static void GLAD_API_PTR glad_debug_impl_glLighti(GLenum light, GLenum pname, GLint param) {
    _pre_call_gl_callback("glLighti", (GLADapiproc) glad_glLighti, 3, light, pname, param);
    glad_glLighti(light, pname, param);
    _post_call_gl_callback(NULL, "glLighti", (GLADapiproc) glad_glLighti, 3, light, pname, param);
    
}
PFNGLLIGHTIPROC glad_debug_glLighti = glad_debug_impl_glLighti;
PFNGLLIGHTIVPROC glad_glLightiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glLightiv(GLenum light, GLenum pname, const GLint * params) {
    _pre_call_gl_callback("glLightiv", (GLADapiproc) glad_glLightiv, 3, light, pname, params);
    glad_glLightiv(light, pname, params);
    _post_call_gl_callback(NULL, "glLightiv", (GLADapiproc) glad_glLightiv, 3, light, pname, params);
    
}
PFNGLLIGHTIVPROC glad_debug_glLightiv = glad_debug_impl_glLightiv;
PFNGLLINESTIPPLEPROC glad_glLineStipple = NULL;
static void GLAD_API_PTR glad_debug_impl_glLineStipple(GLint factor, GLushort pattern) {
    _pre_call_gl_callback("glLineStipple", (GLADapiproc) glad_glLineStipple, 2, factor, pattern);
    glad_glLineStipple(factor, pattern);
    _post_call_gl_callback(NULL, "glLineStipple", (GLADapiproc) glad_glLineStipple, 2, factor, pattern);
    
}
PFNGLLINESTIPPLEPROC glad_debug_glLineStipple = glad_debug_impl_glLineStipple;
PFNGLLINEWIDTHPROC glad_glLineWidth = NULL;
static void GLAD_API_PTR glad_debug_impl_glLineWidth(GLfloat width) {
    _pre_call_gl_callback("glLineWidth", (GLADapiproc) glad_glLineWidth, 1, width);
    glad_glLineWidth(width);
    _post_call_gl_callback(NULL, "glLineWidth", (GLADapiproc) glad_glLineWidth, 1, width);
    
}
PFNGLLINEWIDTHPROC glad_debug_glLineWidth = glad_debug_impl_glLineWidth;
PFNGLLINKPROGRAMPROC glad_glLinkProgram = NULL;
static void GLAD_API_PTR glad_debug_impl_glLinkProgram(GLuint program) {
    _pre_call_gl_callback("glLinkProgram", (GLADapiproc) glad_glLinkProgram, 1, program);
    glad_glLinkProgram(program);
    _post_call_gl_callback(NULL, "glLinkProgram", (GLADapiproc) glad_glLinkProgram, 1, program);
    
}
PFNGLLINKPROGRAMPROC glad_debug_glLinkProgram = glad_debug_impl_glLinkProgram;
PFNGLLINKPROGRAMARBPROC glad_glLinkProgramARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glLinkProgramARB(GLhandleARB programObj) {
    _pre_call_gl_callback("glLinkProgramARB", (GLADapiproc) glad_glLinkProgramARB, 1, programObj);
    glad_glLinkProgramARB(programObj);
    _post_call_gl_callback(NULL, "glLinkProgramARB", (GLADapiproc) glad_glLinkProgramARB, 1, programObj);
    
}
PFNGLLINKPROGRAMARBPROC glad_debug_glLinkProgramARB = glad_debug_impl_glLinkProgramARB;
PFNGLLISTBASEPROC glad_glListBase = NULL;
static void GLAD_API_PTR glad_debug_impl_glListBase(GLuint base) {
    _pre_call_gl_callback("glListBase", (GLADapiproc) glad_glListBase, 1, base);
    glad_glListBase(base);
    _post_call_gl_callback(NULL, "glListBase", (GLADapiproc) glad_glListBase, 1, base);
    
}
PFNGLLISTBASEPROC glad_debug_glListBase = glad_debug_impl_glListBase;
PFNGLLOADIDENTITYPROC glad_glLoadIdentity = NULL;
static void GLAD_API_PTR glad_debug_impl_glLoadIdentity(void) {
    _pre_call_gl_callback("glLoadIdentity", (GLADapiproc) glad_glLoadIdentity, 0);
    glad_glLoadIdentity();
    _post_call_gl_callback(NULL, "glLoadIdentity", (GLADapiproc) glad_glLoadIdentity, 0);
    
}
PFNGLLOADIDENTITYPROC glad_debug_glLoadIdentity = glad_debug_impl_glLoadIdentity;
PFNGLLOADMATRIXDPROC glad_glLoadMatrixd = NULL;
static void GLAD_API_PTR glad_debug_impl_glLoadMatrixd(const GLdouble * m) {
    _pre_call_gl_callback("glLoadMatrixd", (GLADapiproc) glad_glLoadMatrixd, 1, m);
    glad_glLoadMatrixd(m);
    _post_call_gl_callback(NULL, "glLoadMatrixd", (GLADapiproc) glad_glLoadMatrixd, 1, m);
    
}
PFNGLLOADMATRIXDPROC glad_debug_glLoadMatrixd = glad_debug_impl_glLoadMatrixd;
PFNGLLOADMATRIXFPROC glad_glLoadMatrixf = NULL;
static void GLAD_API_PTR glad_debug_impl_glLoadMatrixf(const GLfloat * m) {
    _pre_call_gl_callback("glLoadMatrixf", (GLADapiproc) glad_glLoadMatrixf, 1, m);
    glad_glLoadMatrixf(m);
    _post_call_gl_callback(NULL, "glLoadMatrixf", (GLADapiproc) glad_glLoadMatrixf, 1, m);
    
}
PFNGLLOADMATRIXFPROC glad_debug_glLoadMatrixf = glad_debug_impl_glLoadMatrixf;
PFNGLLOADNAMEPROC glad_glLoadName = NULL;
static void GLAD_API_PTR glad_debug_impl_glLoadName(GLuint name) {
    _pre_call_gl_callback("glLoadName", (GLADapiproc) glad_glLoadName, 1, name);
    glad_glLoadName(name);
    _post_call_gl_callback(NULL, "glLoadName", (GLADapiproc) glad_glLoadName, 1, name);
    
}
PFNGLLOADNAMEPROC glad_debug_glLoadName = glad_debug_impl_glLoadName;
PFNGLLOADPROGRAMNVPROC glad_glLoadProgramNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glLoadProgramNV(GLenum target, GLuint id, GLsizei len, const GLubyte * program) {
    _pre_call_gl_callback("glLoadProgramNV", (GLADapiproc) glad_glLoadProgramNV, 4, target, id, len, program);
    glad_glLoadProgramNV(target, id, len, program);
    _post_call_gl_callback(NULL, "glLoadProgramNV", (GLADapiproc) glad_glLoadProgramNV, 4, target, id, len, program);
    
}
PFNGLLOADPROGRAMNVPROC glad_debug_glLoadProgramNV = glad_debug_impl_glLoadProgramNV;
PFNGLLOADTRANSPOSEMATRIXDPROC glad_glLoadTransposeMatrixd = NULL;
static void GLAD_API_PTR glad_debug_impl_glLoadTransposeMatrixd(const GLdouble * m) {
    _pre_call_gl_callback("glLoadTransposeMatrixd", (GLADapiproc) glad_glLoadTransposeMatrixd, 1, m);
    glad_glLoadTransposeMatrixd(m);
    _post_call_gl_callback(NULL, "glLoadTransposeMatrixd", (GLADapiproc) glad_glLoadTransposeMatrixd, 1, m);
    
}
PFNGLLOADTRANSPOSEMATRIXDPROC glad_debug_glLoadTransposeMatrixd = glad_debug_impl_glLoadTransposeMatrixd;
PFNGLLOADTRANSPOSEMATRIXDARBPROC glad_glLoadTransposeMatrixdARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glLoadTransposeMatrixdARB(const GLdouble * m) {
    _pre_call_gl_callback("glLoadTransposeMatrixdARB", (GLADapiproc) glad_glLoadTransposeMatrixdARB, 1, m);
    glad_glLoadTransposeMatrixdARB(m);
    _post_call_gl_callback(NULL, "glLoadTransposeMatrixdARB", (GLADapiproc) glad_glLoadTransposeMatrixdARB, 1, m);
    
}
PFNGLLOADTRANSPOSEMATRIXDARBPROC glad_debug_glLoadTransposeMatrixdARB = glad_debug_impl_glLoadTransposeMatrixdARB;
PFNGLLOADTRANSPOSEMATRIXFPROC glad_glLoadTransposeMatrixf = NULL;
static void GLAD_API_PTR glad_debug_impl_glLoadTransposeMatrixf(const GLfloat * m) {
    _pre_call_gl_callback("glLoadTransposeMatrixf", (GLADapiproc) glad_glLoadTransposeMatrixf, 1, m);
    glad_glLoadTransposeMatrixf(m);
    _post_call_gl_callback(NULL, "glLoadTransposeMatrixf", (GLADapiproc) glad_glLoadTransposeMatrixf, 1, m);
    
}
PFNGLLOADTRANSPOSEMATRIXFPROC glad_debug_glLoadTransposeMatrixf = glad_debug_impl_glLoadTransposeMatrixf;
PFNGLLOADTRANSPOSEMATRIXFARBPROC glad_glLoadTransposeMatrixfARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glLoadTransposeMatrixfARB(const GLfloat * m) {
    _pre_call_gl_callback("glLoadTransposeMatrixfARB", (GLADapiproc) glad_glLoadTransposeMatrixfARB, 1, m);
    glad_glLoadTransposeMatrixfARB(m);
    _post_call_gl_callback(NULL, "glLoadTransposeMatrixfARB", (GLADapiproc) glad_glLoadTransposeMatrixfARB, 1, m);
    
}
PFNGLLOADTRANSPOSEMATRIXFARBPROC glad_debug_glLoadTransposeMatrixfARB = glad_debug_impl_glLoadTransposeMatrixfARB;
PFNGLLOGICOPPROC glad_glLogicOp = NULL;
static void GLAD_API_PTR glad_debug_impl_glLogicOp(GLenum opcode) {
    _pre_call_gl_callback("glLogicOp", (GLADapiproc) glad_glLogicOp, 1, opcode);
    glad_glLogicOp(opcode);
    _post_call_gl_callback(NULL, "glLogicOp", (GLADapiproc) glad_glLogicOp, 1, opcode);
    
}
PFNGLLOGICOPPROC glad_debug_glLogicOp = glad_debug_impl_glLogicOp;
PFNGLMAP1DPROC glad_glMap1d = NULL;
static void GLAD_API_PTR glad_debug_impl_glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points) {
    _pre_call_gl_callback("glMap1d", (GLADapiproc) glad_glMap1d, 6, target, u1, u2, stride, order, points);
    glad_glMap1d(target, u1, u2, stride, order, points);
    _post_call_gl_callback(NULL, "glMap1d", (GLADapiproc) glad_glMap1d, 6, target, u1, u2, stride, order, points);
    
}
PFNGLMAP1DPROC glad_debug_glMap1d = glad_debug_impl_glMap1d;
PFNGLMAP1FPROC glad_glMap1f = NULL;
static void GLAD_API_PTR glad_debug_impl_glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points) {
    _pre_call_gl_callback("glMap1f", (GLADapiproc) glad_glMap1f, 6, target, u1, u2, stride, order, points);
    glad_glMap1f(target, u1, u2, stride, order, points);
    _post_call_gl_callback(NULL, "glMap1f", (GLADapiproc) glad_glMap1f, 6, target, u1, u2, stride, order, points);
    
}
PFNGLMAP1FPROC glad_debug_glMap1f = glad_debug_impl_glMap1f;
PFNGLMAP2DPROC glad_glMap2d = NULL;
static void GLAD_API_PTR glad_debug_impl_glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points) {
    _pre_call_gl_callback("glMap2d", (GLADapiproc) glad_glMap2d, 10, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
    glad_glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
    _post_call_gl_callback(NULL, "glMap2d", (GLADapiproc) glad_glMap2d, 10, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
    
}
PFNGLMAP2DPROC glad_debug_glMap2d = glad_debug_impl_glMap2d;
PFNGLMAP2FPROC glad_glMap2f = NULL;
static void GLAD_API_PTR glad_debug_impl_glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points) {
    _pre_call_gl_callback("glMap2f", (GLADapiproc) glad_glMap2f, 10, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
    glad_glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
    _post_call_gl_callback(NULL, "glMap2f", (GLADapiproc) glad_glMap2f, 10, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
    
}
PFNGLMAP2FPROC glad_debug_glMap2f = glad_debug_impl_glMap2f;
PFNGLMAPBUFFERPROC glad_glMapBuffer = NULL;
static void * GLAD_API_PTR glad_debug_impl_glMapBuffer(GLenum target, GLenum access) {
    void * ret;
    _pre_call_gl_callback("glMapBuffer", (GLADapiproc) glad_glMapBuffer, 2, target, access);
    ret = glad_glMapBuffer(target, access);
    _post_call_gl_callback((void*) &ret, "glMapBuffer", (GLADapiproc) glad_glMapBuffer, 2, target, access);
    return ret;
}
PFNGLMAPBUFFERPROC glad_debug_glMapBuffer = glad_debug_impl_glMapBuffer;
PFNGLMAPBUFFERARBPROC glad_glMapBufferARB = NULL;
static void * GLAD_API_PTR glad_debug_impl_glMapBufferARB(GLenum target, GLenum access) {
    void * ret;
    _pre_call_gl_callback("glMapBufferARB", (GLADapiproc) glad_glMapBufferARB, 2, target, access);
    ret = glad_glMapBufferARB(target, access);
    _post_call_gl_callback((void*) &ret, "glMapBufferARB", (GLADapiproc) glad_glMapBufferARB, 2, target, access);
    return ret;
}
PFNGLMAPBUFFERARBPROC glad_debug_glMapBufferARB = glad_debug_impl_glMapBufferARB;
PFNGLMAPGRID1DPROC glad_glMapGrid1d = NULL;
static void GLAD_API_PTR glad_debug_impl_glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    _pre_call_gl_callback("glMapGrid1d", (GLADapiproc) glad_glMapGrid1d, 3, un, u1, u2);
    glad_glMapGrid1d(un, u1, u2);
    _post_call_gl_callback(NULL, "glMapGrid1d", (GLADapiproc) glad_glMapGrid1d, 3, un, u1, u2);
    
}
PFNGLMAPGRID1DPROC glad_debug_glMapGrid1d = glad_debug_impl_glMapGrid1d;
PFNGLMAPGRID1FPROC glad_glMapGrid1f = NULL;
static void GLAD_API_PTR glad_debug_impl_glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
    _pre_call_gl_callback("glMapGrid1f", (GLADapiproc) glad_glMapGrid1f, 3, un, u1, u2);
    glad_glMapGrid1f(un, u1, u2);
    _post_call_gl_callback(NULL, "glMapGrid1f", (GLADapiproc) glad_glMapGrid1f, 3, un, u1, u2);
    
}
PFNGLMAPGRID1FPROC glad_debug_glMapGrid1f = glad_debug_impl_glMapGrid1f;
PFNGLMAPGRID2DPROC glad_glMapGrid2d = NULL;
static void GLAD_API_PTR glad_debug_impl_glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {
    _pre_call_gl_callback("glMapGrid2d", (GLADapiproc) glad_glMapGrid2d, 6, un, u1, u2, vn, v1, v2);
    glad_glMapGrid2d(un, u1, u2, vn, v1, v2);
    _post_call_gl_callback(NULL, "glMapGrid2d", (GLADapiproc) glad_glMapGrid2d, 6, un, u1, u2, vn, v1, v2);
    
}
PFNGLMAPGRID2DPROC glad_debug_glMapGrid2d = glad_debug_impl_glMapGrid2d;
PFNGLMAPGRID2FPROC glad_glMapGrid2f = NULL;
static void GLAD_API_PTR glad_debug_impl_glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {
    _pre_call_gl_callback("glMapGrid2f", (GLADapiproc) glad_glMapGrid2f, 6, un, u1, u2, vn, v1, v2);
    glad_glMapGrid2f(un, u1, u2, vn, v1, v2);
    _post_call_gl_callback(NULL, "glMapGrid2f", (GLADapiproc) glad_glMapGrid2f, 6, un, u1, u2, vn, v1, v2);
    
}
PFNGLMAPGRID2FPROC glad_debug_glMapGrid2f = glad_debug_impl_glMapGrid2f;
PFNGLMATERIALFPROC glad_glMaterialf = NULL;
static void GLAD_API_PTR glad_debug_impl_glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glMaterialf", (GLADapiproc) glad_glMaterialf, 3, face, pname, param);
    glad_glMaterialf(face, pname, param);
    _post_call_gl_callback(NULL, "glMaterialf", (GLADapiproc) glad_glMaterialf, 3, face, pname, param);
    
}
PFNGLMATERIALFPROC glad_debug_glMaterialf = glad_debug_impl_glMaterialf;
PFNGLMATERIALFVPROC glad_glMaterialfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glMaterialfv", (GLADapiproc) glad_glMaterialfv, 3, face, pname, params);
    glad_glMaterialfv(face, pname, params);
    _post_call_gl_callback(NULL, "glMaterialfv", (GLADapiproc) glad_glMaterialfv, 3, face, pname, params);
    
}
PFNGLMATERIALFVPROC glad_debug_glMaterialfv = glad_debug_impl_glMaterialfv;
PFNGLMATERIALIPROC glad_glMateriali = NULL;
static void GLAD_API_PTR glad_debug_impl_glMateriali(GLenum face, GLenum pname, GLint param) {
    _pre_call_gl_callback("glMateriali", (GLADapiproc) glad_glMateriali, 3, face, pname, param);
    glad_glMateriali(face, pname, param);
    _post_call_gl_callback(NULL, "glMateriali", (GLADapiproc) glad_glMateriali, 3, face, pname, param);
    
}
PFNGLMATERIALIPROC glad_debug_glMateriali = glad_debug_impl_glMateriali;
PFNGLMATERIALIVPROC glad_glMaterialiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMaterialiv(GLenum face, GLenum pname, const GLint * params) {
    _pre_call_gl_callback("glMaterialiv", (GLADapiproc) glad_glMaterialiv, 3, face, pname, params);
    glad_glMaterialiv(face, pname, params);
    _post_call_gl_callback(NULL, "glMaterialiv", (GLADapiproc) glad_glMaterialiv, 3, face, pname, params);
    
}
PFNGLMATERIALIVPROC glad_debug_glMaterialiv = glad_debug_impl_glMaterialiv;
PFNGLMATRIXMODEPROC glad_glMatrixMode = NULL;
static void GLAD_API_PTR glad_debug_impl_glMatrixMode(GLenum mode) {
    _pre_call_gl_callback("glMatrixMode", (GLADapiproc) glad_glMatrixMode, 1, mode);
    glad_glMatrixMode(mode);
    _post_call_gl_callback(NULL, "glMatrixMode", (GLADapiproc) glad_glMatrixMode, 1, mode);
    
}
PFNGLMATRIXMODEPROC glad_debug_glMatrixMode = glad_debug_impl_glMatrixMode;
PFNGLMINMAXPROC glad_glMinmax = NULL;
static void GLAD_API_PTR glad_debug_impl_glMinmax(GLenum target, GLenum internalformat, GLboolean sink) {
    _pre_call_gl_callback("glMinmax", (GLADapiproc) glad_glMinmax, 3, target, internalformat, sink);
    glad_glMinmax(target, internalformat, sink);
    _post_call_gl_callback(NULL, "glMinmax", (GLADapiproc) glad_glMinmax, 3, target, internalformat, sink);
    
}
PFNGLMINMAXPROC glad_debug_glMinmax = glad_debug_impl_glMinmax;
PFNGLMULTMATRIXDPROC glad_glMultMatrixd = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultMatrixd(const GLdouble * m) {
    _pre_call_gl_callback("glMultMatrixd", (GLADapiproc) glad_glMultMatrixd, 1, m);
    glad_glMultMatrixd(m);
    _post_call_gl_callback(NULL, "glMultMatrixd", (GLADapiproc) glad_glMultMatrixd, 1, m);
    
}
PFNGLMULTMATRIXDPROC glad_debug_glMultMatrixd = glad_debug_impl_glMultMatrixd;
PFNGLMULTMATRIXFPROC glad_glMultMatrixf = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultMatrixf(const GLfloat * m) {
    _pre_call_gl_callback("glMultMatrixf", (GLADapiproc) glad_glMultMatrixf, 1, m);
    glad_glMultMatrixf(m);
    _post_call_gl_callback(NULL, "glMultMatrixf", (GLADapiproc) glad_glMultMatrixf, 1, m);
    
}
PFNGLMULTMATRIXFPROC glad_debug_glMultMatrixf = glad_debug_impl_glMultMatrixf;
PFNGLMULTTRANSPOSEMATRIXDPROC glad_glMultTransposeMatrixd = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultTransposeMatrixd(const GLdouble * m) {
    _pre_call_gl_callback("glMultTransposeMatrixd", (GLADapiproc) glad_glMultTransposeMatrixd, 1, m);
    glad_glMultTransposeMatrixd(m);
    _post_call_gl_callback(NULL, "glMultTransposeMatrixd", (GLADapiproc) glad_glMultTransposeMatrixd, 1, m);
    
}
PFNGLMULTTRANSPOSEMATRIXDPROC glad_debug_glMultTransposeMatrixd = glad_debug_impl_glMultTransposeMatrixd;
PFNGLMULTTRANSPOSEMATRIXDARBPROC glad_glMultTransposeMatrixdARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultTransposeMatrixdARB(const GLdouble * m) {
    _pre_call_gl_callback("glMultTransposeMatrixdARB", (GLADapiproc) glad_glMultTransposeMatrixdARB, 1, m);
    glad_glMultTransposeMatrixdARB(m);
    _post_call_gl_callback(NULL, "glMultTransposeMatrixdARB", (GLADapiproc) glad_glMultTransposeMatrixdARB, 1, m);
    
}
PFNGLMULTTRANSPOSEMATRIXDARBPROC glad_debug_glMultTransposeMatrixdARB = glad_debug_impl_glMultTransposeMatrixdARB;
PFNGLMULTTRANSPOSEMATRIXFPROC glad_glMultTransposeMatrixf = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultTransposeMatrixf(const GLfloat * m) {
    _pre_call_gl_callback("glMultTransposeMatrixf", (GLADapiproc) glad_glMultTransposeMatrixf, 1, m);
    glad_glMultTransposeMatrixf(m);
    _post_call_gl_callback(NULL, "glMultTransposeMatrixf", (GLADapiproc) glad_glMultTransposeMatrixf, 1, m);
    
}
PFNGLMULTTRANSPOSEMATRIXFPROC glad_debug_glMultTransposeMatrixf = glad_debug_impl_glMultTransposeMatrixf;
PFNGLMULTTRANSPOSEMATRIXFARBPROC glad_glMultTransposeMatrixfARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultTransposeMatrixfARB(const GLfloat * m) {
    _pre_call_gl_callback("glMultTransposeMatrixfARB", (GLADapiproc) glad_glMultTransposeMatrixfARB, 1, m);
    glad_glMultTransposeMatrixfARB(m);
    _post_call_gl_callback(NULL, "glMultTransposeMatrixfARB", (GLADapiproc) glad_glMultTransposeMatrixfARB, 1, m);
    
}
PFNGLMULTTRANSPOSEMATRIXFARBPROC glad_debug_glMultTransposeMatrixfARB = glad_debug_impl_glMultTransposeMatrixfARB;
PFNGLMULTIDRAWARRAYSPROC glad_glMultiDrawArrays = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) {
    _pre_call_gl_callback("glMultiDrawArrays", (GLADapiproc) glad_glMultiDrawArrays, 4, mode, first, count, drawcount);
    glad_glMultiDrawArrays(mode, first, count, drawcount);
    _post_call_gl_callback(NULL, "glMultiDrawArrays", (GLADapiproc) glad_glMultiDrawArrays, 4, mode, first, count, drawcount);
    
}
PFNGLMULTIDRAWARRAYSPROC glad_debug_glMultiDrawArrays = glad_debug_impl_glMultiDrawArrays;
PFNGLMULTIDRAWARRAYSEXTPROC glad_glMultiDrawArraysEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiDrawArraysEXT(GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount) {
    _pre_call_gl_callback("glMultiDrawArraysEXT", (GLADapiproc) glad_glMultiDrawArraysEXT, 4, mode, first, count, primcount);
    glad_glMultiDrawArraysEXT(mode, first, count, primcount);
    _post_call_gl_callback(NULL, "glMultiDrawArraysEXT", (GLADapiproc) glad_glMultiDrawArraysEXT, 4, mode, first, count, primcount);
    
}
PFNGLMULTIDRAWARRAYSEXTPROC glad_debug_glMultiDrawArraysEXT = glad_debug_impl_glMultiDrawArraysEXT;
PFNGLMULTIDRAWELEMENTSPROC glad_glMultiDrawElements = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount) {
    _pre_call_gl_callback("glMultiDrawElements", (GLADapiproc) glad_glMultiDrawElements, 5, mode, count, type, indices, drawcount);
    glad_glMultiDrawElements(mode, count, type, indices, drawcount);
    _post_call_gl_callback(NULL, "glMultiDrawElements", (GLADapiproc) glad_glMultiDrawElements, 5, mode, count, type, indices, drawcount);
    
}
PFNGLMULTIDRAWELEMENTSPROC glad_debug_glMultiDrawElements = glad_debug_impl_glMultiDrawElements;
PFNGLMULTIDRAWELEMENTSEXTPROC glad_glMultiDrawElementsEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiDrawElementsEXT(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei primcount) {
    _pre_call_gl_callback("glMultiDrawElementsEXT", (GLADapiproc) glad_glMultiDrawElementsEXT, 5, mode, count, type, indices, primcount);
    glad_glMultiDrawElementsEXT(mode, count, type, indices, primcount);
    _post_call_gl_callback(NULL, "glMultiDrawElementsEXT", (GLADapiproc) glad_glMultiDrawElementsEXT, 5, mode, count, type, indices, primcount);
    
}
PFNGLMULTIDRAWELEMENTSEXTPROC glad_debug_glMultiDrawElementsEXT = glad_debug_impl_glMultiDrawElementsEXT;
PFNGLMULTITEXCOORD1DPROC glad_glMultiTexCoord1d = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1d(GLenum target, GLdouble s) {
    _pre_call_gl_callback("glMultiTexCoord1d", (GLADapiproc) glad_glMultiTexCoord1d, 2, target, s);
    glad_glMultiTexCoord1d(target, s);
    _post_call_gl_callback(NULL, "glMultiTexCoord1d", (GLADapiproc) glad_glMultiTexCoord1d, 2, target, s);
    
}
PFNGLMULTITEXCOORD1DPROC glad_debug_glMultiTexCoord1d = glad_debug_impl_glMultiTexCoord1d;
PFNGLMULTITEXCOORD1DARBPROC glad_glMultiTexCoord1dARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1dARB(GLenum target, GLdouble s) {
    _pre_call_gl_callback("glMultiTexCoord1dARB", (GLADapiproc) glad_glMultiTexCoord1dARB, 2, target, s);
    glad_glMultiTexCoord1dARB(target, s);
    _post_call_gl_callback(NULL, "glMultiTexCoord1dARB", (GLADapiproc) glad_glMultiTexCoord1dARB, 2, target, s);
    
}
PFNGLMULTITEXCOORD1DARBPROC glad_debug_glMultiTexCoord1dARB = glad_debug_impl_glMultiTexCoord1dARB;
PFNGLMULTITEXCOORD1DVPROC glad_glMultiTexCoord1dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1dv(GLenum target, const GLdouble * v) {
    _pre_call_gl_callback("glMultiTexCoord1dv", (GLADapiproc) glad_glMultiTexCoord1dv, 2, target, v);
    glad_glMultiTexCoord1dv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord1dv", (GLADapiproc) glad_glMultiTexCoord1dv, 2, target, v);
    
}
PFNGLMULTITEXCOORD1DVPROC glad_debug_glMultiTexCoord1dv = glad_debug_impl_glMultiTexCoord1dv;
PFNGLMULTITEXCOORD1DVARBPROC glad_glMultiTexCoord1dvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1dvARB(GLenum target, const GLdouble * v) {
    _pre_call_gl_callback("glMultiTexCoord1dvARB", (GLADapiproc) glad_glMultiTexCoord1dvARB, 2, target, v);
    glad_glMultiTexCoord1dvARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord1dvARB", (GLADapiproc) glad_glMultiTexCoord1dvARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD1DVARBPROC glad_debug_glMultiTexCoord1dvARB = glad_debug_impl_glMultiTexCoord1dvARB;
PFNGLMULTITEXCOORD1FPROC glad_glMultiTexCoord1f = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1f(GLenum target, GLfloat s) {
    _pre_call_gl_callback("glMultiTexCoord1f", (GLADapiproc) glad_glMultiTexCoord1f, 2, target, s);
    glad_glMultiTexCoord1f(target, s);
    _post_call_gl_callback(NULL, "glMultiTexCoord1f", (GLADapiproc) glad_glMultiTexCoord1f, 2, target, s);
    
}
PFNGLMULTITEXCOORD1FPROC glad_debug_glMultiTexCoord1f = glad_debug_impl_glMultiTexCoord1f;
PFNGLMULTITEXCOORD1FARBPROC glad_glMultiTexCoord1fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1fARB(GLenum target, GLfloat s) {
    _pre_call_gl_callback("glMultiTexCoord1fARB", (GLADapiproc) glad_glMultiTexCoord1fARB, 2, target, s);
    glad_glMultiTexCoord1fARB(target, s);
    _post_call_gl_callback(NULL, "glMultiTexCoord1fARB", (GLADapiproc) glad_glMultiTexCoord1fARB, 2, target, s);
    
}
PFNGLMULTITEXCOORD1FARBPROC glad_debug_glMultiTexCoord1fARB = glad_debug_impl_glMultiTexCoord1fARB;
PFNGLMULTITEXCOORD1FVPROC glad_glMultiTexCoord1fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1fv(GLenum target, const GLfloat * v) {
    _pre_call_gl_callback("glMultiTexCoord1fv", (GLADapiproc) glad_glMultiTexCoord1fv, 2, target, v);
    glad_glMultiTexCoord1fv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord1fv", (GLADapiproc) glad_glMultiTexCoord1fv, 2, target, v);
    
}
PFNGLMULTITEXCOORD1FVPROC glad_debug_glMultiTexCoord1fv = glad_debug_impl_glMultiTexCoord1fv;
PFNGLMULTITEXCOORD1FVARBPROC glad_glMultiTexCoord1fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1fvARB(GLenum target, const GLfloat * v) {
    _pre_call_gl_callback("glMultiTexCoord1fvARB", (GLADapiproc) glad_glMultiTexCoord1fvARB, 2, target, v);
    glad_glMultiTexCoord1fvARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord1fvARB", (GLADapiproc) glad_glMultiTexCoord1fvARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD1FVARBPROC glad_debug_glMultiTexCoord1fvARB = glad_debug_impl_glMultiTexCoord1fvARB;
PFNGLMULTITEXCOORD1IPROC glad_glMultiTexCoord1i = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1i(GLenum target, GLint s) {
    _pre_call_gl_callback("glMultiTexCoord1i", (GLADapiproc) glad_glMultiTexCoord1i, 2, target, s);
    glad_glMultiTexCoord1i(target, s);
    _post_call_gl_callback(NULL, "glMultiTexCoord1i", (GLADapiproc) glad_glMultiTexCoord1i, 2, target, s);
    
}
PFNGLMULTITEXCOORD1IPROC glad_debug_glMultiTexCoord1i = glad_debug_impl_glMultiTexCoord1i;
PFNGLMULTITEXCOORD1IARBPROC glad_glMultiTexCoord1iARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1iARB(GLenum target, GLint s) {
    _pre_call_gl_callback("glMultiTexCoord1iARB", (GLADapiproc) glad_glMultiTexCoord1iARB, 2, target, s);
    glad_glMultiTexCoord1iARB(target, s);
    _post_call_gl_callback(NULL, "glMultiTexCoord1iARB", (GLADapiproc) glad_glMultiTexCoord1iARB, 2, target, s);
    
}
PFNGLMULTITEXCOORD1IARBPROC glad_debug_glMultiTexCoord1iARB = glad_debug_impl_glMultiTexCoord1iARB;
PFNGLMULTITEXCOORD1IVPROC glad_glMultiTexCoord1iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1iv(GLenum target, const GLint * v) {
    _pre_call_gl_callback("glMultiTexCoord1iv", (GLADapiproc) glad_glMultiTexCoord1iv, 2, target, v);
    glad_glMultiTexCoord1iv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord1iv", (GLADapiproc) glad_glMultiTexCoord1iv, 2, target, v);
    
}
PFNGLMULTITEXCOORD1IVPROC glad_debug_glMultiTexCoord1iv = glad_debug_impl_glMultiTexCoord1iv;
PFNGLMULTITEXCOORD1IVARBPROC glad_glMultiTexCoord1ivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1ivARB(GLenum target, const GLint * v) {
    _pre_call_gl_callback("glMultiTexCoord1ivARB", (GLADapiproc) glad_glMultiTexCoord1ivARB, 2, target, v);
    glad_glMultiTexCoord1ivARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord1ivARB", (GLADapiproc) glad_glMultiTexCoord1ivARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD1IVARBPROC glad_debug_glMultiTexCoord1ivARB = glad_debug_impl_glMultiTexCoord1ivARB;
PFNGLMULTITEXCOORD1SPROC glad_glMultiTexCoord1s = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1s(GLenum target, GLshort s) {
    _pre_call_gl_callback("glMultiTexCoord1s", (GLADapiproc) glad_glMultiTexCoord1s, 2, target, s);
    glad_glMultiTexCoord1s(target, s);
    _post_call_gl_callback(NULL, "glMultiTexCoord1s", (GLADapiproc) glad_glMultiTexCoord1s, 2, target, s);
    
}
PFNGLMULTITEXCOORD1SPROC glad_debug_glMultiTexCoord1s = glad_debug_impl_glMultiTexCoord1s;
PFNGLMULTITEXCOORD1SARBPROC glad_glMultiTexCoord1sARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1sARB(GLenum target, GLshort s) {
    _pre_call_gl_callback("glMultiTexCoord1sARB", (GLADapiproc) glad_glMultiTexCoord1sARB, 2, target, s);
    glad_glMultiTexCoord1sARB(target, s);
    _post_call_gl_callback(NULL, "glMultiTexCoord1sARB", (GLADapiproc) glad_glMultiTexCoord1sARB, 2, target, s);
    
}
PFNGLMULTITEXCOORD1SARBPROC glad_debug_glMultiTexCoord1sARB = glad_debug_impl_glMultiTexCoord1sARB;
PFNGLMULTITEXCOORD1SVPROC glad_glMultiTexCoord1sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1sv(GLenum target, const GLshort * v) {
    _pre_call_gl_callback("glMultiTexCoord1sv", (GLADapiproc) glad_glMultiTexCoord1sv, 2, target, v);
    glad_glMultiTexCoord1sv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord1sv", (GLADapiproc) glad_glMultiTexCoord1sv, 2, target, v);
    
}
PFNGLMULTITEXCOORD1SVPROC glad_debug_glMultiTexCoord1sv = glad_debug_impl_glMultiTexCoord1sv;
PFNGLMULTITEXCOORD1SVARBPROC glad_glMultiTexCoord1svARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord1svARB(GLenum target, const GLshort * v) {
    _pre_call_gl_callback("glMultiTexCoord1svARB", (GLADapiproc) glad_glMultiTexCoord1svARB, 2, target, v);
    glad_glMultiTexCoord1svARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord1svARB", (GLADapiproc) glad_glMultiTexCoord1svARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD1SVARBPROC glad_debug_glMultiTexCoord1svARB = glad_debug_impl_glMultiTexCoord1svARB;
PFNGLMULTITEXCOORD2DPROC glad_glMultiTexCoord2d = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) {
    _pre_call_gl_callback("glMultiTexCoord2d", (GLADapiproc) glad_glMultiTexCoord2d, 3, target, s, t);
    glad_glMultiTexCoord2d(target, s, t);
    _post_call_gl_callback(NULL, "glMultiTexCoord2d", (GLADapiproc) glad_glMultiTexCoord2d, 3, target, s, t);
    
}
PFNGLMULTITEXCOORD2DPROC glad_debug_glMultiTexCoord2d = glad_debug_impl_glMultiTexCoord2d;
PFNGLMULTITEXCOORD2DARBPROC glad_glMultiTexCoord2dARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t) {
    _pre_call_gl_callback("glMultiTexCoord2dARB", (GLADapiproc) glad_glMultiTexCoord2dARB, 3, target, s, t);
    glad_glMultiTexCoord2dARB(target, s, t);
    _post_call_gl_callback(NULL, "glMultiTexCoord2dARB", (GLADapiproc) glad_glMultiTexCoord2dARB, 3, target, s, t);
    
}
PFNGLMULTITEXCOORD2DARBPROC glad_debug_glMultiTexCoord2dARB = glad_debug_impl_glMultiTexCoord2dARB;
PFNGLMULTITEXCOORD2DVPROC glad_glMultiTexCoord2dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2dv(GLenum target, const GLdouble * v) {
    _pre_call_gl_callback("glMultiTexCoord2dv", (GLADapiproc) glad_glMultiTexCoord2dv, 2, target, v);
    glad_glMultiTexCoord2dv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord2dv", (GLADapiproc) glad_glMultiTexCoord2dv, 2, target, v);
    
}
PFNGLMULTITEXCOORD2DVPROC glad_debug_glMultiTexCoord2dv = glad_debug_impl_glMultiTexCoord2dv;
PFNGLMULTITEXCOORD2DVARBPROC glad_glMultiTexCoord2dvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2dvARB(GLenum target, const GLdouble * v) {
    _pre_call_gl_callback("glMultiTexCoord2dvARB", (GLADapiproc) glad_glMultiTexCoord2dvARB, 2, target, v);
    glad_glMultiTexCoord2dvARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord2dvARB", (GLADapiproc) glad_glMultiTexCoord2dvARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD2DVARBPROC glad_debug_glMultiTexCoord2dvARB = glad_debug_impl_glMultiTexCoord2dvARB;
PFNGLMULTITEXCOORD2FPROC glad_glMultiTexCoord2f = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    _pre_call_gl_callback("glMultiTexCoord2f", (GLADapiproc) glad_glMultiTexCoord2f, 3, target, s, t);
    glad_glMultiTexCoord2f(target, s, t);
    _post_call_gl_callback(NULL, "glMultiTexCoord2f", (GLADapiproc) glad_glMultiTexCoord2f, 3, target, s, t);
    
}
PFNGLMULTITEXCOORD2FPROC glad_debug_glMultiTexCoord2f = glad_debug_impl_glMultiTexCoord2f;
PFNGLMULTITEXCOORD2FARBPROC glad_glMultiTexCoord2fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t) {
    _pre_call_gl_callback("glMultiTexCoord2fARB", (GLADapiproc) glad_glMultiTexCoord2fARB, 3, target, s, t);
    glad_glMultiTexCoord2fARB(target, s, t);
    _post_call_gl_callback(NULL, "glMultiTexCoord2fARB", (GLADapiproc) glad_glMultiTexCoord2fARB, 3, target, s, t);
    
}
PFNGLMULTITEXCOORD2FARBPROC glad_debug_glMultiTexCoord2fARB = glad_debug_impl_glMultiTexCoord2fARB;
PFNGLMULTITEXCOORD2FVPROC glad_glMultiTexCoord2fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2fv(GLenum target, const GLfloat * v) {
    _pre_call_gl_callback("glMultiTexCoord2fv", (GLADapiproc) glad_glMultiTexCoord2fv, 2, target, v);
    glad_glMultiTexCoord2fv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord2fv", (GLADapiproc) glad_glMultiTexCoord2fv, 2, target, v);
    
}
PFNGLMULTITEXCOORD2FVPROC glad_debug_glMultiTexCoord2fv = glad_debug_impl_glMultiTexCoord2fv;
PFNGLMULTITEXCOORD2FVARBPROC glad_glMultiTexCoord2fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2fvARB(GLenum target, const GLfloat * v) {
    _pre_call_gl_callback("glMultiTexCoord2fvARB", (GLADapiproc) glad_glMultiTexCoord2fvARB, 2, target, v);
    glad_glMultiTexCoord2fvARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord2fvARB", (GLADapiproc) glad_glMultiTexCoord2fvARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD2FVARBPROC glad_debug_glMultiTexCoord2fvARB = glad_debug_impl_glMultiTexCoord2fvARB;
PFNGLMULTITEXCOORD2IPROC glad_glMultiTexCoord2i = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2i(GLenum target, GLint s, GLint t) {
    _pre_call_gl_callback("glMultiTexCoord2i", (GLADapiproc) glad_glMultiTexCoord2i, 3, target, s, t);
    glad_glMultiTexCoord2i(target, s, t);
    _post_call_gl_callback(NULL, "glMultiTexCoord2i", (GLADapiproc) glad_glMultiTexCoord2i, 3, target, s, t);
    
}
PFNGLMULTITEXCOORD2IPROC glad_debug_glMultiTexCoord2i = glad_debug_impl_glMultiTexCoord2i;
PFNGLMULTITEXCOORD2IARBPROC glad_glMultiTexCoord2iARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2iARB(GLenum target, GLint s, GLint t) {
    _pre_call_gl_callback("glMultiTexCoord2iARB", (GLADapiproc) glad_glMultiTexCoord2iARB, 3, target, s, t);
    glad_glMultiTexCoord2iARB(target, s, t);
    _post_call_gl_callback(NULL, "glMultiTexCoord2iARB", (GLADapiproc) glad_glMultiTexCoord2iARB, 3, target, s, t);
    
}
PFNGLMULTITEXCOORD2IARBPROC glad_debug_glMultiTexCoord2iARB = glad_debug_impl_glMultiTexCoord2iARB;
PFNGLMULTITEXCOORD2IVPROC glad_glMultiTexCoord2iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2iv(GLenum target, const GLint * v) {
    _pre_call_gl_callback("glMultiTexCoord2iv", (GLADapiproc) glad_glMultiTexCoord2iv, 2, target, v);
    glad_glMultiTexCoord2iv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord2iv", (GLADapiproc) glad_glMultiTexCoord2iv, 2, target, v);
    
}
PFNGLMULTITEXCOORD2IVPROC glad_debug_glMultiTexCoord2iv = glad_debug_impl_glMultiTexCoord2iv;
PFNGLMULTITEXCOORD2IVARBPROC glad_glMultiTexCoord2ivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2ivARB(GLenum target, const GLint * v) {
    _pre_call_gl_callback("glMultiTexCoord2ivARB", (GLADapiproc) glad_glMultiTexCoord2ivARB, 2, target, v);
    glad_glMultiTexCoord2ivARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord2ivARB", (GLADapiproc) glad_glMultiTexCoord2ivARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD2IVARBPROC glad_debug_glMultiTexCoord2ivARB = glad_debug_impl_glMultiTexCoord2ivARB;
PFNGLMULTITEXCOORD2SPROC glad_glMultiTexCoord2s = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) {
    _pre_call_gl_callback("glMultiTexCoord2s", (GLADapiproc) glad_glMultiTexCoord2s, 3, target, s, t);
    glad_glMultiTexCoord2s(target, s, t);
    _post_call_gl_callback(NULL, "glMultiTexCoord2s", (GLADapiproc) glad_glMultiTexCoord2s, 3, target, s, t);
    
}
PFNGLMULTITEXCOORD2SPROC glad_debug_glMultiTexCoord2s = glad_debug_impl_glMultiTexCoord2s;
PFNGLMULTITEXCOORD2SARBPROC glad_glMultiTexCoord2sARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t) {
    _pre_call_gl_callback("glMultiTexCoord2sARB", (GLADapiproc) glad_glMultiTexCoord2sARB, 3, target, s, t);
    glad_glMultiTexCoord2sARB(target, s, t);
    _post_call_gl_callback(NULL, "glMultiTexCoord2sARB", (GLADapiproc) glad_glMultiTexCoord2sARB, 3, target, s, t);
    
}
PFNGLMULTITEXCOORD2SARBPROC glad_debug_glMultiTexCoord2sARB = glad_debug_impl_glMultiTexCoord2sARB;
PFNGLMULTITEXCOORD2SVPROC glad_glMultiTexCoord2sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2sv(GLenum target, const GLshort * v) {
    _pre_call_gl_callback("glMultiTexCoord2sv", (GLADapiproc) glad_glMultiTexCoord2sv, 2, target, v);
    glad_glMultiTexCoord2sv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord2sv", (GLADapiproc) glad_glMultiTexCoord2sv, 2, target, v);
    
}
PFNGLMULTITEXCOORD2SVPROC glad_debug_glMultiTexCoord2sv = glad_debug_impl_glMultiTexCoord2sv;
PFNGLMULTITEXCOORD2SVARBPROC glad_glMultiTexCoord2svARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord2svARB(GLenum target, const GLshort * v) {
    _pre_call_gl_callback("glMultiTexCoord2svARB", (GLADapiproc) glad_glMultiTexCoord2svARB, 2, target, v);
    glad_glMultiTexCoord2svARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord2svARB", (GLADapiproc) glad_glMultiTexCoord2svARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD2SVARBPROC glad_debug_glMultiTexCoord2svARB = glad_debug_impl_glMultiTexCoord2svARB;
PFNGLMULTITEXCOORD3DPROC glad_glMultiTexCoord3d = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    _pre_call_gl_callback("glMultiTexCoord3d", (GLADapiproc) glad_glMultiTexCoord3d, 4, target, s, t, r);
    glad_glMultiTexCoord3d(target, s, t, r);
    _post_call_gl_callback(NULL, "glMultiTexCoord3d", (GLADapiproc) glad_glMultiTexCoord3d, 4, target, s, t, r);
    
}
PFNGLMULTITEXCOORD3DPROC glad_debug_glMultiTexCoord3d = glad_debug_impl_glMultiTexCoord3d;
PFNGLMULTITEXCOORD3DARBPROC glad_glMultiTexCoord3dARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    _pre_call_gl_callback("glMultiTexCoord3dARB", (GLADapiproc) glad_glMultiTexCoord3dARB, 4, target, s, t, r);
    glad_glMultiTexCoord3dARB(target, s, t, r);
    _post_call_gl_callback(NULL, "glMultiTexCoord3dARB", (GLADapiproc) glad_glMultiTexCoord3dARB, 4, target, s, t, r);
    
}
PFNGLMULTITEXCOORD3DARBPROC glad_debug_glMultiTexCoord3dARB = glad_debug_impl_glMultiTexCoord3dARB;
PFNGLMULTITEXCOORD3DVPROC glad_glMultiTexCoord3dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3dv(GLenum target, const GLdouble * v) {
    _pre_call_gl_callback("glMultiTexCoord3dv", (GLADapiproc) glad_glMultiTexCoord3dv, 2, target, v);
    glad_glMultiTexCoord3dv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord3dv", (GLADapiproc) glad_glMultiTexCoord3dv, 2, target, v);
    
}
PFNGLMULTITEXCOORD3DVPROC glad_debug_glMultiTexCoord3dv = glad_debug_impl_glMultiTexCoord3dv;
PFNGLMULTITEXCOORD3DVARBPROC glad_glMultiTexCoord3dvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3dvARB(GLenum target, const GLdouble * v) {
    _pre_call_gl_callback("glMultiTexCoord3dvARB", (GLADapiproc) glad_glMultiTexCoord3dvARB, 2, target, v);
    glad_glMultiTexCoord3dvARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord3dvARB", (GLADapiproc) glad_glMultiTexCoord3dvARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD3DVARBPROC glad_debug_glMultiTexCoord3dvARB = glad_debug_impl_glMultiTexCoord3dvARB;
PFNGLMULTITEXCOORD3FPROC glad_glMultiTexCoord3f = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    _pre_call_gl_callback("glMultiTexCoord3f", (GLADapiproc) glad_glMultiTexCoord3f, 4, target, s, t, r);
    glad_glMultiTexCoord3f(target, s, t, r);
    _post_call_gl_callback(NULL, "glMultiTexCoord3f", (GLADapiproc) glad_glMultiTexCoord3f, 4, target, s, t, r);
    
}
PFNGLMULTITEXCOORD3FPROC glad_debug_glMultiTexCoord3f = glad_debug_impl_glMultiTexCoord3f;
PFNGLMULTITEXCOORD3FARBPROC glad_glMultiTexCoord3fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    _pre_call_gl_callback("glMultiTexCoord3fARB", (GLADapiproc) glad_glMultiTexCoord3fARB, 4, target, s, t, r);
    glad_glMultiTexCoord3fARB(target, s, t, r);
    _post_call_gl_callback(NULL, "glMultiTexCoord3fARB", (GLADapiproc) glad_glMultiTexCoord3fARB, 4, target, s, t, r);
    
}
PFNGLMULTITEXCOORD3FARBPROC glad_debug_glMultiTexCoord3fARB = glad_debug_impl_glMultiTexCoord3fARB;
PFNGLMULTITEXCOORD3FVPROC glad_glMultiTexCoord3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3fv(GLenum target, const GLfloat * v) {
    _pre_call_gl_callback("glMultiTexCoord3fv", (GLADapiproc) glad_glMultiTexCoord3fv, 2, target, v);
    glad_glMultiTexCoord3fv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord3fv", (GLADapiproc) glad_glMultiTexCoord3fv, 2, target, v);
    
}
PFNGLMULTITEXCOORD3FVPROC glad_debug_glMultiTexCoord3fv = glad_debug_impl_glMultiTexCoord3fv;
PFNGLMULTITEXCOORD3FVARBPROC glad_glMultiTexCoord3fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3fvARB(GLenum target, const GLfloat * v) {
    _pre_call_gl_callback("glMultiTexCoord3fvARB", (GLADapiproc) glad_glMultiTexCoord3fvARB, 2, target, v);
    glad_glMultiTexCoord3fvARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord3fvARB", (GLADapiproc) glad_glMultiTexCoord3fvARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD3FVARBPROC glad_debug_glMultiTexCoord3fvARB = glad_debug_impl_glMultiTexCoord3fvARB;
PFNGLMULTITEXCOORD3IPROC glad_glMultiTexCoord3i = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) {
    _pre_call_gl_callback("glMultiTexCoord3i", (GLADapiproc) glad_glMultiTexCoord3i, 4, target, s, t, r);
    glad_glMultiTexCoord3i(target, s, t, r);
    _post_call_gl_callback(NULL, "glMultiTexCoord3i", (GLADapiproc) glad_glMultiTexCoord3i, 4, target, s, t, r);
    
}
PFNGLMULTITEXCOORD3IPROC glad_debug_glMultiTexCoord3i = glad_debug_impl_glMultiTexCoord3i;
PFNGLMULTITEXCOORD3IARBPROC glad_glMultiTexCoord3iARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r) {
    _pre_call_gl_callback("glMultiTexCoord3iARB", (GLADapiproc) glad_glMultiTexCoord3iARB, 4, target, s, t, r);
    glad_glMultiTexCoord3iARB(target, s, t, r);
    _post_call_gl_callback(NULL, "glMultiTexCoord3iARB", (GLADapiproc) glad_glMultiTexCoord3iARB, 4, target, s, t, r);
    
}
PFNGLMULTITEXCOORD3IARBPROC glad_debug_glMultiTexCoord3iARB = glad_debug_impl_glMultiTexCoord3iARB;
PFNGLMULTITEXCOORD3IVPROC glad_glMultiTexCoord3iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3iv(GLenum target, const GLint * v) {
    _pre_call_gl_callback("glMultiTexCoord3iv", (GLADapiproc) glad_glMultiTexCoord3iv, 2, target, v);
    glad_glMultiTexCoord3iv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord3iv", (GLADapiproc) glad_glMultiTexCoord3iv, 2, target, v);
    
}
PFNGLMULTITEXCOORD3IVPROC glad_debug_glMultiTexCoord3iv = glad_debug_impl_glMultiTexCoord3iv;
PFNGLMULTITEXCOORD3IVARBPROC glad_glMultiTexCoord3ivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3ivARB(GLenum target, const GLint * v) {
    _pre_call_gl_callback("glMultiTexCoord3ivARB", (GLADapiproc) glad_glMultiTexCoord3ivARB, 2, target, v);
    glad_glMultiTexCoord3ivARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord3ivARB", (GLADapiproc) glad_glMultiTexCoord3ivARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD3IVARBPROC glad_debug_glMultiTexCoord3ivARB = glad_debug_impl_glMultiTexCoord3ivARB;
PFNGLMULTITEXCOORD3SPROC glad_glMultiTexCoord3s = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) {
    _pre_call_gl_callback("glMultiTexCoord3s", (GLADapiproc) glad_glMultiTexCoord3s, 4, target, s, t, r);
    glad_glMultiTexCoord3s(target, s, t, r);
    _post_call_gl_callback(NULL, "glMultiTexCoord3s", (GLADapiproc) glad_glMultiTexCoord3s, 4, target, s, t, r);
    
}
PFNGLMULTITEXCOORD3SPROC glad_debug_glMultiTexCoord3s = glad_debug_impl_glMultiTexCoord3s;
PFNGLMULTITEXCOORD3SARBPROC glad_glMultiTexCoord3sARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r) {
    _pre_call_gl_callback("glMultiTexCoord3sARB", (GLADapiproc) glad_glMultiTexCoord3sARB, 4, target, s, t, r);
    glad_glMultiTexCoord3sARB(target, s, t, r);
    _post_call_gl_callback(NULL, "glMultiTexCoord3sARB", (GLADapiproc) glad_glMultiTexCoord3sARB, 4, target, s, t, r);
    
}
PFNGLMULTITEXCOORD3SARBPROC glad_debug_glMultiTexCoord3sARB = glad_debug_impl_glMultiTexCoord3sARB;
PFNGLMULTITEXCOORD3SVPROC glad_glMultiTexCoord3sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3sv(GLenum target, const GLshort * v) {
    _pre_call_gl_callback("glMultiTexCoord3sv", (GLADapiproc) glad_glMultiTexCoord3sv, 2, target, v);
    glad_glMultiTexCoord3sv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord3sv", (GLADapiproc) glad_glMultiTexCoord3sv, 2, target, v);
    
}
PFNGLMULTITEXCOORD3SVPROC glad_debug_glMultiTexCoord3sv = glad_debug_impl_glMultiTexCoord3sv;
PFNGLMULTITEXCOORD3SVARBPROC glad_glMultiTexCoord3svARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord3svARB(GLenum target, const GLshort * v) {
    _pre_call_gl_callback("glMultiTexCoord3svARB", (GLADapiproc) glad_glMultiTexCoord3svARB, 2, target, v);
    glad_glMultiTexCoord3svARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord3svARB", (GLADapiproc) glad_glMultiTexCoord3svARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD3SVARBPROC glad_debug_glMultiTexCoord3svARB = glad_debug_impl_glMultiTexCoord3svARB;
PFNGLMULTITEXCOORD4DPROC glad_glMultiTexCoord4d = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    _pre_call_gl_callback("glMultiTexCoord4d", (GLADapiproc) glad_glMultiTexCoord4d, 5, target, s, t, r, q);
    glad_glMultiTexCoord4d(target, s, t, r, q);
    _post_call_gl_callback(NULL, "glMultiTexCoord4d", (GLADapiproc) glad_glMultiTexCoord4d, 5, target, s, t, r, q);
    
}
PFNGLMULTITEXCOORD4DPROC glad_debug_glMultiTexCoord4d = glad_debug_impl_glMultiTexCoord4d;
PFNGLMULTITEXCOORD4DARBPROC glad_glMultiTexCoord4dARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    _pre_call_gl_callback("glMultiTexCoord4dARB", (GLADapiproc) glad_glMultiTexCoord4dARB, 5, target, s, t, r, q);
    glad_glMultiTexCoord4dARB(target, s, t, r, q);
    _post_call_gl_callback(NULL, "glMultiTexCoord4dARB", (GLADapiproc) glad_glMultiTexCoord4dARB, 5, target, s, t, r, q);
    
}
PFNGLMULTITEXCOORD4DARBPROC glad_debug_glMultiTexCoord4dARB = glad_debug_impl_glMultiTexCoord4dARB;
PFNGLMULTITEXCOORD4DVPROC glad_glMultiTexCoord4dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4dv(GLenum target, const GLdouble * v) {
    _pre_call_gl_callback("glMultiTexCoord4dv", (GLADapiproc) glad_glMultiTexCoord4dv, 2, target, v);
    glad_glMultiTexCoord4dv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord4dv", (GLADapiproc) glad_glMultiTexCoord4dv, 2, target, v);
    
}
PFNGLMULTITEXCOORD4DVPROC glad_debug_glMultiTexCoord4dv = glad_debug_impl_glMultiTexCoord4dv;
PFNGLMULTITEXCOORD4DVARBPROC glad_glMultiTexCoord4dvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4dvARB(GLenum target, const GLdouble * v) {
    _pre_call_gl_callback("glMultiTexCoord4dvARB", (GLADapiproc) glad_glMultiTexCoord4dvARB, 2, target, v);
    glad_glMultiTexCoord4dvARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord4dvARB", (GLADapiproc) glad_glMultiTexCoord4dvARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD4DVARBPROC glad_debug_glMultiTexCoord4dvARB = glad_debug_impl_glMultiTexCoord4dvARB;
PFNGLMULTITEXCOORD4FPROC glad_glMultiTexCoord4f = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    _pre_call_gl_callback("glMultiTexCoord4f", (GLADapiproc) glad_glMultiTexCoord4f, 5, target, s, t, r, q);
    glad_glMultiTexCoord4f(target, s, t, r, q);
    _post_call_gl_callback(NULL, "glMultiTexCoord4f", (GLADapiproc) glad_glMultiTexCoord4f, 5, target, s, t, r, q);
    
}
PFNGLMULTITEXCOORD4FPROC glad_debug_glMultiTexCoord4f = glad_debug_impl_glMultiTexCoord4f;
PFNGLMULTITEXCOORD4FARBPROC glad_glMultiTexCoord4fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    _pre_call_gl_callback("glMultiTexCoord4fARB", (GLADapiproc) glad_glMultiTexCoord4fARB, 5, target, s, t, r, q);
    glad_glMultiTexCoord4fARB(target, s, t, r, q);
    _post_call_gl_callback(NULL, "glMultiTexCoord4fARB", (GLADapiproc) glad_glMultiTexCoord4fARB, 5, target, s, t, r, q);
    
}
PFNGLMULTITEXCOORD4FARBPROC glad_debug_glMultiTexCoord4fARB = glad_debug_impl_glMultiTexCoord4fARB;
PFNGLMULTITEXCOORD4FVPROC glad_glMultiTexCoord4fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4fv(GLenum target, const GLfloat * v) {
    _pre_call_gl_callback("glMultiTexCoord4fv", (GLADapiproc) glad_glMultiTexCoord4fv, 2, target, v);
    glad_glMultiTexCoord4fv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord4fv", (GLADapiproc) glad_glMultiTexCoord4fv, 2, target, v);
    
}
PFNGLMULTITEXCOORD4FVPROC glad_debug_glMultiTexCoord4fv = glad_debug_impl_glMultiTexCoord4fv;
PFNGLMULTITEXCOORD4FVARBPROC glad_glMultiTexCoord4fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4fvARB(GLenum target, const GLfloat * v) {
    _pre_call_gl_callback("glMultiTexCoord4fvARB", (GLADapiproc) glad_glMultiTexCoord4fvARB, 2, target, v);
    glad_glMultiTexCoord4fvARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord4fvARB", (GLADapiproc) glad_glMultiTexCoord4fvARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD4FVARBPROC glad_debug_glMultiTexCoord4fvARB = glad_debug_impl_glMultiTexCoord4fvARB;
PFNGLMULTITEXCOORD4IPROC glad_glMultiTexCoord4i = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) {
    _pre_call_gl_callback("glMultiTexCoord4i", (GLADapiproc) glad_glMultiTexCoord4i, 5, target, s, t, r, q);
    glad_glMultiTexCoord4i(target, s, t, r, q);
    _post_call_gl_callback(NULL, "glMultiTexCoord4i", (GLADapiproc) glad_glMultiTexCoord4i, 5, target, s, t, r, q);
    
}
PFNGLMULTITEXCOORD4IPROC glad_debug_glMultiTexCoord4i = glad_debug_impl_glMultiTexCoord4i;
PFNGLMULTITEXCOORD4IARBPROC glad_glMultiTexCoord4iARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q) {
    _pre_call_gl_callback("glMultiTexCoord4iARB", (GLADapiproc) glad_glMultiTexCoord4iARB, 5, target, s, t, r, q);
    glad_glMultiTexCoord4iARB(target, s, t, r, q);
    _post_call_gl_callback(NULL, "glMultiTexCoord4iARB", (GLADapiproc) glad_glMultiTexCoord4iARB, 5, target, s, t, r, q);
    
}
PFNGLMULTITEXCOORD4IARBPROC glad_debug_glMultiTexCoord4iARB = glad_debug_impl_glMultiTexCoord4iARB;
PFNGLMULTITEXCOORD4IVPROC glad_glMultiTexCoord4iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4iv(GLenum target, const GLint * v) {
    _pre_call_gl_callback("glMultiTexCoord4iv", (GLADapiproc) glad_glMultiTexCoord4iv, 2, target, v);
    glad_glMultiTexCoord4iv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord4iv", (GLADapiproc) glad_glMultiTexCoord4iv, 2, target, v);
    
}
PFNGLMULTITEXCOORD4IVPROC glad_debug_glMultiTexCoord4iv = glad_debug_impl_glMultiTexCoord4iv;
PFNGLMULTITEXCOORD4IVARBPROC glad_glMultiTexCoord4ivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4ivARB(GLenum target, const GLint * v) {
    _pre_call_gl_callback("glMultiTexCoord4ivARB", (GLADapiproc) glad_glMultiTexCoord4ivARB, 2, target, v);
    glad_glMultiTexCoord4ivARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord4ivARB", (GLADapiproc) glad_glMultiTexCoord4ivARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD4IVARBPROC glad_debug_glMultiTexCoord4ivARB = glad_debug_impl_glMultiTexCoord4ivARB;
PFNGLMULTITEXCOORD4SPROC glad_glMultiTexCoord4s = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
    _pre_call_gl_callback("glMultiTexCoord4s", (GLADapiproc) glad_glMultiTexCoord4s, 5, target, s, t, r, q);
    glad_glMultiTexCoord4s(target, s, t, r, q);
    _post_call_gl_callback(NULL, "glMultiTexCoord4s", (GLADapiproc) glad_glMultiTexCoord4s, 5, target, s, t, r, q);
    
}
PFNGLMULTITEXCOORD4SPROC glad_debug_glMultiTexCoord4s = glad_debug_impl_glMultiTexCoord4s;
PFNGLMULTITEXCOORD4SARBPROC glad_glMultiTexCoord4sARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
    _pre_call_gl_callback("glMultiTexCoord4sARB", (GLADapiproc) glad_glMultiTexCoord4sARB, 5, target, s, t, r, q);
    glad_glMultiTexCoord4sARB(target, s, t, r, q);
    _post_call_gl_callback(NULL, "glMultiTexCoord4sARB", (GLADapiproc) glad_glMultiTexCoord4sARB, 5, target, s, t, r, q);
    
}
PFNGLMULTITEXCOORD4SARBPROC glad_debug_glMultiTexCoord4sARB = glad_debug_impl_glMultiTexCoord4sARB;
PFNGLMULTITEXCOORD4SVPROC glad_glMultiTexCoord4sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4sv(GLenum target, const GLshort * v) {
    _pre_call_gl_callback("glMultiTexCoord4sv", (GLADapiproc) glad_glMultiTexCoord4sv, 2, target, v);
    glad_glMultiTexCoord4sv(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord4sv", (GLADapiproc) glad_glMultiTexCoord4sv, 2, target, v);
    
}
PFNGLMULTITEXCOORD4SVPROC glad_debug_glMultiTexCoord4sv = glad_debug_impl_glMultiTexCoord4sv;
PFNGLMULTITEXCOORD4SVARBPROC glad_glMultiTexCoord4svARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glMultiTexCoord4svARB(GLenum target, const GLshort * v) {
    _pre_call_gl_callback("glMultiTexCoord4svARB", (GLADapiproc) glad_glMultiTexCoord4svARB, 2, target, v);
    glad_glMultiTexCoord4svARB(target, v);
    _post_call_gl_callback(NULL, "glMultiTexCoord4svARB", (GLADapiproc) glad_glMultiTexCoord4svARB, 2, target, v);
    
}
PFNGLMULTITEXCOORD4SVARBPROC glad_debug_glMultiTexCoord4svARB = glad_debug_impl_glMultiTexCoord4svARB;
PFNGLNEWLISTPROC glad_glNewList = NULL;
static void GLAD_API_PTR glad_debug_impl_glNewList(GLuint list, GLenum mode) {
    _pre_call_gl_callback("glNewList", (GLADapiproc) glad_glNewList, 2, list, mode);
    glad_glNewList(list, mode);
    _post_call_gl_callback(NULL, "glNewList", (GLADapiproc) glad_glNewList, 2, list, mode);
    
}
PFNGLNEWLISTPROC glad_debug_glNewList = glad_debug_impl_glNewList;
PFNGLNORMAL3BPROC glad_glNormal3b = NULL;
static void GLAD_API_PTR glad_debug_impl_glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
    _pre_call_gl_callback("glNormal3b", (GLADapiproc) glad_glNormal3b, 3, nx, ny, nz);
    glad_glNormal3b(nx, ny, nz);
    _post_call_gl_callback(NULL, "glNormal3b", (GLADapiproc) glad_glNormal3b, 3, nx, ny, nz);
    
}
PFNGLNORMAL3BPROC glad_debug_glNormal3b = glad_debug_impl_glNormal3b;
PFNGLNORMAL3BVPROC glad_glNormal3bv = NULL;
static void GLAD_API_PTR glad_debug_impl_glNormal3bv(const GLbyte * v) {
    _pre_call_gl_callback("glNormal3bv", (GLADapiproc) glad_glNormal3bv, 1, v);
    glad_glNormal3bv(v);
    _post_call_gl_callback(NULL, "glNormal3bv", (GLADapiproc) glad_glNormal3bv, 1, v);
    
}
PFNGLNORMAL3BVPROC glad_debug_glNormal3bv = glad_debug_impl_glNormal3bv;
PFNGLNORMAL3DPROC glad_glNormal3d = NULL;
static void GLAD_API_PTR glad_debug_impl_glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
    _pre_call_gl_callback("glNormal3d", (GLADapiproc) glad_glNormal3d, 3, nx, ny, nz);
    glad_glNormal3d(nx, ny, nz);
    _post_call_gl_callback(NULL, "glNormal3d", (GLADapiproc) glad_glNormal3d, 3, nx, ny, nz);
    
}
PFNGLNORMAL3DPROC glad_debug_glNormal3d = glad_debug_impl_glNormal3d;
PFNGLNORMAL3DVPROC glad_glNormal3dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glNormal3dv(const GLdouble * v) {
    _pre_call_gl_callback("glNormal3dv", (GLADapiproc) glad_glNormal3dv, 1, v);
    glad_glNormal3dv(v);
    _post_call_gl_callback(NULL, "glNormal3dv", (GLADapiproc) glad_glNormal3dv, 1, v);
    
}
PFNGLNORMAL3DVPROC glad_debug_glNormal3dv = glad_debug_impl_glNormal3dv;
PFNGLNORMAL3FPROC glad_glNormal3f = NULL;
static void GLAD_API_PTR glad_debug_impl_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    _pre_call_gl_callback("glNormal3f", (GLADapiproc) glad_glNormal3f, 3, nx, ny, nz);
    glad_glNormal3f(nx, ny, nz);
    _post_call_gl_callback(NULL, "glNormal3f", (GLADapiproc) glad_glNormal3f, 3, nx, ny, nz);
    
}
PFNGLNORMAL3FPROC glad_debug_glNormal3f = glad_debug_impl_glNormal3f;
PFNGLNORMAL3FVPROC glad_glNormal3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glNormal3fv(const GLfloat * v) {
    _pre_call_gl_callback("glNormal3fv", (GLADapiproc) glad_glNormal3fv, 1, v);
    glad_glNormal3fv(v);
    _post_call_gl_callback(NULL, "glNormal3fv", (GLADapiproc) glad_glNormal3fv, 1, v);
    
}
PFNGLNORMAL3FVPROC glad_debug_glNormal3fv = glad_debug_impl_glNormal3fv;
PFNGLNORMAL3IPROC glad_glNormal3i = NULL;
static void GLAD_API_PTR glad_debug_impl_glNormal3i(GLint nx, GLint ny, GLint nz) {
    _pre_call_gl_callback("glNormal3i", (GLADapiproc) glad_glNormal3i, 3, nx, ny, nz);
    glad_glNormal3i(nx, ny, nz);
    _post_call_gl_callback(NULL, "glNormal3i", (GLADapiproc) glad_glNormal3i, 3, nx, ny, nz);
    
}
PFNGLNORMAL3IPROC glad_debug_glNormal3i = glad_debug_impl_glNormal3i;
PFNGLNORMAL3IVPROC glad_glNormal3iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glNormal3iv(const GLint * v) {
    _pre_call_gl_callback("glNormal3iv", (GLADapiproc) glad_glNormal3iv, 1, v);
    glad_glNormal3iv(v);
    _post_call_gl_callback(NULL, "glNormal3iv", (GLADapiproc) glad_glNormal3iv, 1, v);
    
}
PFNGLNORMAL3IVPROC glad_debug_glNormal3iv = glad_debug_impl_glNormal3iv;
PFNGLNORMAL3SPROC glad_glNormal3s = NULL;
static void GLAD_API_PTR glad_debug_impl_glNormal3s(GLshort nx, GLshort ny, GLshort nz) {
    _pre_call_gl_callback("glNormal3s", (GLADapiproc) glad_glNormal3s, 3, nx, ny, nz);
    glad_glNormal3s(nx, ny, nz);
    _post_call_gl_callback(NULL, "glNormal3s", (GLADapiproc) glad_glNormal3s, 3, nx, ny, nz);
    
}
PFNGLNORMAL3SPROC glad_debug_glNormal3s = glad_debug_impl_glNormal3s;
PFNGLNORMAL3SVPROC glad_glNormal3sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glNormal3sv(const GLshort * v) {
    _pre_call_gl_callback("glNormal3sv", (GLADapiproc) glad_glNormal3sv, 1, v);
    glad_glNormal3sv(v);
    _post_call_gl_callback(NULL, "glNormal3sv", (GLADapiproc) glad_glNormal3sv, 1, v);
    
}
PFNGLNORMAL3SVPROC glad_debug_glNormal3sv = glad_debug_impl_glNormal3sv;
PFNGLNORMALPOINTERPROC glad_glNormalPointer = NULL;
static void GLAD_API_PTR glad_debug_impl_glNormalPointer(GLenum type, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glNormalPointer", (GLADapiproc) glad_glNormalPointer, 3, type, stride, pointer);
    glad_glNormalPointer(type, stride, pointer);
    _post_call_gl_callback(NULL, "glNormalPointer", (GLADapiproc) glad_glNormalPointer, 3, type, stride, pointer);
    
}
PFNGLNORMALPOINTERPROC glad_debug_glNormalPointer = glad_debug_impl_glNormalPointer;
PFNGLNORMALPOINTEREXTPROC glad_glNormalPointerEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void * pointer) {
    _pre_call_gl_callback("glNormalPointerEXT", (GLADapiproc) glad_glNormalPointerEXT, 4, type, stride, count, pointer);
    glad_glNormalPointerEXT(type, stride, count, pointer);
    _post_call_gl_callback(NULL, "glNormalPointerEXT", (GLADapiproc) glad_glNormalPointerEXT, 4, type, stride, count, pointer);
    
}
PFNGLNORMALPOINTEREXTPROC glad_debug_glNormalPointerEXT = glad_debug_impl_glNormalPointerEXT;
PFNGLOBJECTLABELPROC glad_glObjectLabel = NULL;
static void GLAD_API_PTR glad_debug_impl_glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar * label) {
    _pre_call_gl_callback("glObjectLabel", (GLADapiproc) glad_glObjectLabel, 4, identifier, name, length, label);
    glad_glObjectLabel(identifier, name, length, label);
    _post_call_gl_callback(NULL, "glObjectLabel", (GLADapiproc) glad_glObjectLabel, 4, identifier, name, length, label);
    
}
PFNGLOBJECTLABELPROC glad_debug_glObjectLabel = glad_debug_impl_glObjectLabel;
PFNGLOBJECTPTRLABELPROC glad_glObjectPtrLabel = NULL;
static void GLAD_API_PTR glad_debug_impl_glObjectPtrLabel(const void * ptr, GLsizei length, const GLchar * label) {
    _pre_call_gl_callback("glObjectPtrLabel", (GLADapiproc) glad_glObjectPtrLabel, 3, ptr, length, label);
    glad_glObjectPtrLabel(ptr, length, label);
    _post_call_gl_callback(NULL, "glObjectPtrLabel", (GLADapiproc) glad_glObjectPtrLabel, 3, ptr, length, label);
    
}
PFNGLOBJECTPTRLABELPROC glad_debug_glObjectPtrLabel = glad_debug_impl_glObjectPtrLabel;
PFNGLORTHOPROC glad_glOrtho = NULL;
static void GLAD_API_PTR glad_debug_impl_glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    _pre_call_gl_callback("glOrtho", (GLADapiproc) glad_glOrtho, 6, left, right, bottom, top, zNear, zFar);
    glad_glOrtho(left, right, bottom, top, zNear, zFar);
    _post_call_gl_callback(NULL, "glOrtho", (GLADapiproc) glad_glOrtho, 6, left, right, bottom, top, zNear, zFar);
    
}
PFNGLORTHOPROC glad_debug_glOrtho = glad_debug_impl_glOrtho;
PFNGLPASSTHROUGHPROC glad_glPassThrough = NULL;
static void GLAD_API_PTR glad_debug_impl_glPassThrough(GLfloat token) {
    _pre_call_gl_callback("glPassThrough", (GLADapiproc) glad_glPassThrough, 1, token);
    glad_glPassThrough(token);
    _post_call_gl_callback(NULL, "glPassThrough", (GLADapiproc) glad_glPassThrough, 1, token);
    
}
PFNGLPASSTHROUGHPROC glad_debug_glPassThrough = glad_debug_impl_glPassThrough;
PFNGLPIXELMAPFVPROC glad_glPixelMapfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat * values) {
    _pre_call_gl_callback("glPixelMapfv", (GLADapiproc) glad_glPixelMapfv, 3, map, mapsize, values);
    glad_glPixelMapfv(map, mapsize, values);
    _post_call_gl_callback(NULL, "glPixelMapfv", (GLADapiproc) glad_glPixelMapfv, 3, map, mapsize, values);
    
}
PFNGLPIXELMAPFVPROC glad_debug_glPixelMapfv = glad_debug_impl_glPixelMapfv;
PFNGLPIXELMAPUIVPROC glad_glPixelMapuiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint * values) {
    _pre_call_gl_callback("glPixelMapuiv", (GLADapiproc) glad_glPixelMapuiv, 3, map, mapsize, values);
    glad_glPixelMapuiv(map, mapsize, values);
    _post_call_gl_callback(NULL, "glPixelMapuiv", (GLADapiproc) glad_glPixelMapuiv, 3, map, mapsize, values);
    
}
PFNGLPIXELMAPUIVPROC glad_debug_glPixelMapuiv = glad_debug_impl_glPixelMapuiv;
PFNGLPIXELMAPUSVPROC glad_glPixelMapusv = NULL;
static void GLAD_API_PTR glad_debug_impl_glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort * values) {
    _pre_call_gl_callback("glPixelMapusv", (GLADapiproc) glad_glPixelMapusv, 3, map, mapsize, values);
    glad_glPixelMapusv(map, mapsize, values);
    _post_call_gl_callback(NULL, "glPixelMapusv", (GLADapiproc) glad_glPixelMapusv, 3, map, mapsize, values);
    
}
PFNGLPIXELMAPUSVPROC glad_debug_glPixelMapusv = glad_debug_impl_glPixelMapusv;
PFNGLPIXELSTOREFPROC glad_glPixelStoref = NULL;
static void GLAD_API_PTR glad_debug_impl_glPixelStoref(GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glPixelStoref", (GLADapiproc) glad_glPixelStoref, 2, pname, param);
    glad_glPixelStoref(pname, param);
    _post_call_gl_callback(NULL, "glPixelStoref", (GLADapiproc) glad_glPixelStoref, 2, pname, param);
    
}
PFNGLPIXELSTOREFPROC glad_debug_glPixelStoref = glad_debug_impl_glPixelStoref;
PFNGLPIXELSTOREIPROC glad_glPixelStorei = NULL;
static void GLAD_API_PTR glad_debug_impl_glPixelStorei(GLenum pname, GLint param) {
    _pre_call_gl_callback("glPixelStorei", (GLADapiproc) glad_glPixelStorei, 2, pname, param);
    glad_glPixelStorei(pname, param);
    _post_call_gl_callback(NULL, "glPixelStorei", (GLADapiproc) glad_glPixelStorei, 2, pname, param);
    
}
PFNGLPIXELSTOREIPROC glad_debug_glPixelStorei = glad_debug_impl_glPixelStorei;
PFNGLPIXELTRANSFERFPROC glad_glPixelTransferf = NULL;
static void GLAD_API_PTR glad_debug_impl_glPixelTransferf(GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glPixelTransferf", (GLADapiproc) glad_glPixelTransferf, 2, pname, param);
    glad_glPixelTransferf(pname, param);
    _post_call_gl_callback(NULL, "glPixelTransferf", (GLADapiproc) glad_glPixelTransferf, 2, pname, param);
    
}
PFNGLPIXELTRANSFERFPROC glad_debug_glPixelTransferf = glad_debug_impl_glPixelTransferf;
PFNGLPIXELTRANSFERIPROC glad_glPixelTransferi = NULL;
static void GLAD_API_PTR glad_debug_impl_glPixelTransferi(GLenum pname, GLint param) {
    _pre_call_gl_callback("glPixelTransferi", (GLADapiproc) glad_glPixelTransferi, 2, pname, param);
    glad_glPixelTransferi(pname, param);
    _post_call_gl_callback(NULL, "glPixelTransferi", (GLADapiproc) glad_glPixelTransferi, 2, pname, param);
    
}
PFNGLPIXELTRANSFERIPROC glad_debug_glPixelTransferi = glad_debug_impl_glPixelTransferi;
PFNGLPIXELZOOMPROC glad_glPixelZoom = NULL;
static void GLAD_API_PTR glad_debug_impl_glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
    _pre_call_gl_callback("glPixelZoom", (GLADapiproc) glad_glPixelZoom, 2, xfactor, yfactor);
    glad_glPixelZoom(xfactor, yfactor);
    _post_call_gl_callback(NULL, "glPixelZoom", (GLADapiproc) glad_glPixelZoom, 2, xfactor, yfactor);
    
}
PFNGLPIXELZOOMPROC glad_debug_glPixelZoom = glad_debug_impl_glPixelZoom;
PFNGLPOINTPARAMETERFPROC glad_glPointParameterf = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointParameterf(GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glPointParameterf", (GLADapiproc) glad_glPointParameterf, 2, pname, param);
    glad_glPointParameterf(pname, param);
    _post_call_gl_callback(NULL, "glPointParameterf", (GLADapiproc) glad_glPointParameterf, 2, pname, param);
    
}
PFNGLPOINTPARAMETERFPROC glad_debug_glPointParameterf = glad_debug_impl_glPointParameterf;
PFNGLPOINTPARAMETERFARBPROC glad_glPointParameterfARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointParameterfARB(GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glPointParameterfARB", (GLADapiproc) glad_glPointParameterfARB, 2, pname, param);
    glad_glPointParameterfARB(pname, param);
    _post_call_gl_callback(NULL, "glPointParameterfARB", (GLADapiproc) glad_glPointParameterfARB, 2, pname, param);
    
}
PFNGLPOINTPARAMETERFARBPROC glad_debug_glPointParameterfARB = glad_debug_impl_glPointParameterfARB;
PFNGLPOINTPARAMETERFEXTPROC glad_glPointParameterfEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointParameterfEXT(GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glPointParameterfEXT", (GLADapiproc) glad_glPointParameterfEXT, 2, pname, param);
    glad_glPointParameterfEXT(pname, param);
    _post_call_gl_callback(NULL, "glPointParameterfEXT", (GLADapiproc) glad_glPointParameterfEXT, 2, pname, param);
    
}
PFNGLPOINTPARAMETERFEXTPROC glad_debug_glPointParameterfEXT = glad_debug_impl_glPointParameterfEXT;
PFNGLPOINTPARAMETERFSGISPROC glad_glPointParameterfSGIS = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointParameterfSGIS(GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glPointParameterfSGIS", (GLADapiproc) glad_glPointParameterfSGIS, 2, pname, param);
    glad_glPointParameterfSGIS(pname, param);
    _post_call_gl_callback(NULL, "glPointParameterfSGIS", (GLADapiproc) glad_glPointParameterfSGIS, 2, pname, param);
    
}
PFNGLPOINTPARAMETERFSGISPROC glad_debug_glPointParameterfSGIS = glad_debug_impl_glPointParameterfSGIS;
PFNGLPOINTPARAMETERFVPROC glad_glPointParameterfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointParameterfv(GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glPointParameterfv", (GLADapiproc) glad_glPointParameterfv, 2, pname, params);
    glad_glPointParameterfv(pname, params);
    _post_call_gl_callback(NULL, "glPointParameterfv", (GLADapiproc) glad_glPointParameterfv, 2, pname, params);
    
}
PFNGLPOINTPARAMETERFVPROC glad_debug_glPointParameterfv = glad_debug_impl_glPointParameterfv;
PFNGLPOINTPARAMETERFVARBPROC glad_glPointParameterfvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointParameterfvARB(GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glPointParameterfvARB", (GLADapiproc) glad_glPointParameterfvARB, 2, pname, params);
    glad_glPointParameterfvARB(pname, params);
    _post_call_gl_callback(NULL, "glPointParameterfvARB", (GLADapiproc) glad_glPointParameterfvARB, 2, pname, params);
    
}
PFNGLPOINTPARAMETERFVARBPROC glad_debug_glPointParameterfvARB = glad_debug_impl_glPointParameterfvARB;
PFNGLPOINTPARAMETERFVEXTPROC glad_glPointParameterfvEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointParameterfvEXT(GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glPointParameterfvEXT", (GLADapiproc) glad_glPointParameterfvEXT, 2, pname, params);
    glad_glPointParameterfvEXT(pname, params);
    _post_call_gl_callback(NULL, "glPointParameterfvEXT", (GLADapiproc) glad_glPointParameterfvEXT, 2, pname, params);
    
}
PFNGLPOINTPARAMETERFVEXTPROC glad_debug_glPointParameterfvEXT = glad_debug_impl_glPointParameterfvEXT;
PFNGLPOINTPARAMETERFVSGISPROC glad_glPointParameterfvSGIS = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointParameterfvSGIS(GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glPointParameterfvSGIS", (GLADapiproc) glad_glPointParameterfvSGIS, 2, pname, params);
    glad_glPointParameterfvSGIS(pname, params);
    _post_call_gl_callback(NULL, "glPointParameterfvSGIS", (GLADapiproc) glad_glPointParameterfvSGIS, 2, pname, params);
    
}
PFNGLPOINTPARAMETERFVSGISPROC glad_debug_glPointParameterfvSGIS = glad_debug_impl_glPointParameterfvSGIS;
PFNGLPOINTPARAMETERIPROC glad_glPointParameteri = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointParameteri(GLenum pname, GLint param) {
    _pre_call_gl_callback("glPointParameteri", (GLADapiproc) glad_glPointParameteri, 2, pname, param);
    glad_glPointParameteri(pname, param);
    _post_call_gl_callback(NULL, "glPointParameteri", (GLADapiproc) glad_glPointParameteri, 2, pname, param);
    
}
PFNGLPOINTPARAMETERIPROC glad_debug_glPointParameteri = glad_debug_impl_glPointParameteri;
PFNGLPOINTPARAMETERINVPROC glad_glPointParameteriNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointParameteriNV(GLenum pname, GLint param) {
    _pre_call_gl_callback("glPointParameteriNV", (GLADapiproc) glad_glPointParameteriNV, 2, pname, param);
    glad_glPointParameteriNV(pname, param);
    _post_call_gl_callback(NULL, "glPointParameteriNV", (GLADapiproc) glad_glPointParameteriNV, 2, pname, param);
    
}
PFNGLPOINTPARAMETERINVPROC glad_debug_glPointParameteriNV = glad_debug_impl_glPointParameteriNV;
PFNGLPOINTPARAMETERIVPROC glad_glPointParameteriv = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointParameteriv(GLenum pname, const GLint * params) {
    _pre_call_gl_callback("glPointParameteriv", (GLADapiproc) glad_glPointParameteriv, 2, pname, params);
    glad_glPointParameteriv(pname, params);
    _post_call_gl_callback(NULL, "glPointParameteriv", (GLADapiproc) glad_glPointParameteriv, 2, pname, params);
    
}
PFNGLPOINTPARAMETERIVPROC glad_debug_glPointParameteriv = glad_debug_impl_glPointParameteriv;
PFNGLPOINTPARAMETERIVNVPROC glad_glPointParameterivNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointParameterivNV(GLenum pname, const GLint * params) {
    _pre_call_gl_callback("glPointParameterivNV", (GLADapiproc) glad_glPointParameterivNV, 2, pname, params);
    glad_glPointParameterivNV(pname, params);
    _post_call_gl_callback(NULL, "glPointParameterivNV", (GLADapiproc) glad_glPointParameterivNV, 2, pname, params);
    
}
PFNGLPOINTPARAMETERIVNVPROC glad_debug_glPointParameterivNV = glad_debug_impl_glPointParameterivNV;
PFNGLPOINTSIZEPROC glad_glPointSize = NULL;
static void GLAD_API_PTR glad_debug_impl_glPointSize(GLfloat size) {
    _pre_call_gl_callback("glPointSize", (GLADapiproc) glad_glPointSize, 1, size);
    glad_glPointSize(size);
    _post_call_gl_callback(NULL, "glPointSize", (GLADapiproc) glad_glPointSize, 1, size);
    
}
PFNGLPOINTSIZEPROC glad_debug_glPointSize = glad_debug_impl_glPointSize;
PFNGLPOLYGONMODEPROC glad_glPolygonMode = NULL;
static void GLAD_API_PTR glad_debug_impl_glPolygonMode(GLenum face, GLenum mode) {
    _pre_call_gl_callback("glPolygonMode", (GLADapiproc) glad_glPolygonMode, 2, face, mode);
    glad_glPolygonMode(face, mode);
    _post_call_gl_callback(NULL, "glPolygonMode", (GLADapiproc) glad_glPolygonMode, 2, face, mode);
    
}
PFNGLPOLYGONMODEPROC glad_debug_glPolygonMode = glad_debug_impl_glPolygonMode;
PFNGLPOLYGONOFFSETPROC glad_glPolygonOffset = NULL;
static void GLAD_API_PTR glad_debug_impl_glPolygonOffset(GLfloat factor, GLfloat units) {
    _pre_call_gl_callback("glPolygonOffset", (GLADapiproc) glad_glPolygonOffset, 2, factor, units);
    glad_glPolygonOffset(factor, units);
    _post_call_gl_callback(NULL, "glPolygonOffset", (GLADapiproc) glad_glPolygonOffset, 2, factor, units);
    
}
PFNGLPOLYGONOFFSETPROC glad_debug_glPolygonOffset = glad_debug_impl_glPolygonOffset;
PFNGLPOLYGONSTIPPLEPROC glad_glPolygonStipple = NULL;
static void GLAD_API_PTR glad_debug_impl_glPolygonStipple(const GLubyte * mask) {
    _pre_call_gl_callback("glPolygonStipple", (GLADapiproc) glad_glPolygonStipple, 1, mask);
    glad_glPolygonStipple(mask);
    _post_call_gl_callback(NULL, "glPolygonStipple", (GLADapiproc) glad_glPolygonStipple, 1, mask);
    
}
PFNGLPOLYGONSTIPPLEPROC glad_debug_glPolygonStipple = glad_debug_impl_glPolygonStipple;
PFNGLPOPATTRIBPROC glad_glPopAttrib = NULL;
static void GLAD_API_PTR glad_debug_impl_glPopAttrib(void) {
    _pre_call_gl_callback("glPopAttrib", (GLADapiproc) glad_glPopAttrib, 0);
    glad_glPopAttrib();
    _post_call_gl_callback(NULL, "glPopAttrib", (GLADapiproc) glad_glPopAttrib, 0);
    
}
PFNGLPOPATTRIBPROC glad_debug_glPopAttrib = glad_debug_impl_glPopAttrib;
PFNGLPOPCLIENTATTRIBPROC glad_glPopClientAttrib = NULL;
static void GLAD_API_PTR glad_debug_impl_glPopClientAttrib(void) {
    _pre_call_gl_callback("glPopClientAttrib", (GLADapiproc) glad_glPopClientAttrib, 0);
    glad_glPopClientAttrib();
    _post_call_gl_callback(NULL, "glPopClientAttrib", (GLADapiproc) glad_glPopClientAttrib, 0);
    
}
PFNGLPOPCLIENTATTRIBPROC glad_debug_glPopClientAttrib = glad_debug_impl_glPopClientAttrib;
PFNGLPOPDEBUGGROUPPROC glad_glPopDebugGroup = NULL;
static void GLAD_API_PTR glad_debug_impl_glPopDebugGroup(void) {
    _pre_call_gl_callback("glPopDebugGroup", (GLADapiproc) glad_glPopDebugGroup, 0);
    glad_glPopDebugGroup();
    _post_call_gl_callback(NULL, "glPopDebugGroup", (GLADapiproc) glad_glPopDebugGroup, 0);
    
}
PFNGLPOPDEBUGGROUPPROC glad_debug_glPopDebugGroup = glad_debug_impl_glPopDebugGroup;
PFNGLPOPMATRIXPROC glad_glPopMatrix = NULL;
static void GLAD_API_PTR glad_debug_impl_glPopMatrix(void) {
    _pre_call_gl_callback("glPopMatrix", (GLADapiproc) glad_glPopMatrix, 0);
    glad_glPopMatrix();
    _post_call_gl_callback(NULL, "glPopMatrix", (GLADapiproc) glad_glPopMatrix, 0);
    
}
PFNGLPOPMATRIXPROC glad_debug_glPopMatrix = glad_debug_impl_glPopMatrix;
PFNGLPOPNAMEPROC glad_glPopName = NULL;
static void GLAD_API_PTR glad_debug_impl_glPopName(void) {
    _pre_call_gl_callback("glPopName", (GLADapiproc) glad_glPopName, 0);
    glad_glPopName();
    _post_call_gl_callback(NULL, "glPopName", (GLADapiproc) glad_glPopName, 0);
    
}
PFNGLPOPNAMEPROC glad_debug_glPopName = glad_debug_impl_glPopName;
PFNGLPRIORITIZETEXTURESPROC glad_glPrioritizeTextures = NULL;
static void GLAD_API_PTR glad_debug_impl_glPrioritizeTextures(GLsizei n, const GLuint * textures, const GLfloat * priorities) {
    _pre_call_gl_callback("glPrioritizeTextures", (GLADapiproc) glad_glPrioritizeTextures, 3, n, textures, priorities);
    glad_glPrioritizeTextures(n, textures, priorities);
    _post_call_gl_callback(NULL, "glPrioritizeTextures", (GLADapiproc) glad_glPrioritizeTextures, 3, n, textures, priorities);
    
}
PFNGLPRIORITIZETEXTURESPROC glad_debug_glPrioritizeTextures = glad_debug_impl_glPrioritizeTextures;
PFNGLPRIORITIZETEXTURESEXTPROC glad_glPrioritizeTexturesEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glPrioritizeTexturesEXT(GLsizei n, const GLuint * textures, const GLclampf * priorities) {
    _pre_call_gl_callback("glPrioritizeTexturesEXT", (GLADapiproc) glad_glPrioritizeTexturesEXT, 3, n, textures, priorities);
    glad_glPrioritizeTexturesEXT(n, textures, priorities);
    _post_call_gl_callback(NULL, "glPrioritizeTexturesEXT", (GLADapiproc) glad_glPrioritizeTexturesEXT, 3, n, textures, priorities);
    
}
PFNGLPRIORITIZETEXTURESEXTPROC glad_debug_glPrioritizeTexturesEXT = glad_debug_impl_glPrioritizeTexturesEXT;
PFNGLPROGRAMENVPARAMETER4DARBPROC glad_glProgramEnvParameter4dARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    _pre_call_gl_callback("glProgramEnvParameter4dARB", (GLADapiproc) glad_glProgramEnvParameter4dARB, 6, target, index, x, y, z, w);
    glad_glProgramEnvParameter4dARB(target, index, x, y, z, w);
    _post_call_gl_callback(NULL, "glProgramEnvParameter4dARB", (GLADapiproc) glad_glProgramEnvParameter4dARB, 6, target, index, x, y, z, w);
    
}
PFNGLPROGRAMENVPARAMETER4DARBPROC glad_debug_glProgramEnvParameter4dARB = glad_debug_impl_glProgramEnvParameter4dARB;
PFNGLPROGRAMENVPARAMETER4DVARBPROC glad_glProgramEnvParameter4dvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramEnvParameter4dvARB(GLenum target, GLuint index, const GLdouble * params) {
    _pre_call_gl_callback("glProgramEnvParameter4dvARB", (GLADapiproc) glad_glProgramEnvParameter4dvARB, 3, target, index, params);
    glad_glProgramEnvParameter4dvARB(target, index, params);
    _post_call_gl_callback(NULL, "glProgramEnvParameter4dvARB", (GLADapiproc) glad_glProgramEnvParameter4dvARB, 3, target, index, params);
    
}
PFNGLPROGRAMENVPARAMETER4DVARBPROC glad_debug_glProgramEnvParameter4dvARB = glad_debug_impl_glProgramEnvParameter4dvARB;
PFNGLPROGRAMENVPARAMETER4FARBPROC glad_glProgramEnvParameter4fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _pre_call_gl_callback("glProgramEnvParameter4fARB", (GLADapiproc) glad_glProgramEnvParameter4fARB, 6, target, index, x, y, z, w);
    glad_glProgramEnvParameter4fARB(target, index, x, y, z, w);
    _post_call_gl_callback(NULL, "glProgramEnvParameter4fARB", (GLADapiproc) glad_glProgramEnvParameter4fARB, 6, target, index, x, y, z, w);
    
}
PFNGLPROGRAMENVPARAMETER4FARBPROC glad_debug_glProgramEnvParameter4fARB = glad_debug_impl_glProgramEnvParameter4fARB;
PFNGLPROGRAMENVPARAMETER4FVARBPROC glad_glProgramEnvParameter4fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramEnvParameter4fvARB(GLenum target, GLuint index, const GLfloat * params) {
    _pre_call_gl_callback("glProgramEnvParameter4fvARB", (GLADapiproc) glad_glProgramEnvParameter4fvARB, 3, target, index, params);
    glad_glProgramEnvParameter4fvARB(target, index, params);
    _post_call_gl_callback(NULL, "glProgramEnvParameter4fvARB", (GLADapiproc) glad_glProgramEnvParameter4fvARB, 3, target, index, params);
    
}
PFNGLPROGRAMENVPARAMETER4FVARBPROC glad_debug_glProgramEnvParameter4fvARB = glad_debug_impl_glProgramEnvParameter4fvARB;
PFNGLPROGRAMLOCALPARAMETER4DARBPROC glad_glProgramLocalParameter4dARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    _pre_call_gl_callback("glProgramLocalParameter4dARB", (GLADapiproc) glad_glProgramLocalParameter4dARB, 6, target, index, x, y, z, w);
    glad_glProgramLocalParameter4dARB(target, index, x, y, z, w);
    _post_call_gl_callback(NULL, "glProgramLocalParameter4dARB", (GLADapiproc) glad_glProgramLocalParameter4dARB, 6, target, index, x, y, z, w);
    
}
PFNGLPROGRAMLOCALPARAMETER4DARBPROC glad_debug_glProgramLocalParameter4dARB = glad_debug_impl_glProgramLocalParameter4dARB;
PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glad_glProgramLocalParameter4dvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramLocalParameter4dvARB(GLenum target, GLuint index, const GLdouble * params) {
    _pre_call_gl_callback("glProgramLocalParameter4dvARB", (GLADapiproc) glad_glProgramLocalParameter4dvARB, 3, target, index, params);
    glad_glProgramLocalParameter4dvARB(target, index, params);
    _post_call_gl_callback(NULL, "glProgramLocalParameter4dvARB", (GLADapiproc) glad_glProgramLocalParameter4dvARB, 3, target, index, params);
    
}
PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glad_debug_glProgramLocalParameter4dvARB = glad_debug_impl_glProgramLocalParameter4dvARB;
PFNGLPROGRAMLOCALPARAMETER4FARBPROC glad_glProgramLocalParameter4fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _pre_call_gl_callback("glProgramLocalParameter4fARB", (GLADapiproc) glad_glProgramLocalParameter4fARB, 6, target, index, x, y, z, w);
    glad_glProgramLocalParameter4fARB(target, index, x, y, z, w);
    _post_call_gl_callback(NULL, "glProgramLocalParameter4fARB", (GLADapiproc) glad_glProgramLocalParameter4fARB, 6, target, index, x, y, z, w);
    
}
PFNGLPROGRAMLOCALPARAMETER4FARBPROC glad_debug_glProgramLocalParameter4fARB = glad_debug_impl_glProgramLocalParameter4fARB;
PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glad_glProgramLocalParameter4fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramLocalParameter4fvARB(GLenum target, GLuint index, const GLfloat * params) {
    _pre_call_gl_callback("glProgramLocalParameter4fvARB", (GLADapiproc) glad_glProgramLocalParameter4fvARB, 3, target, index, params);
    glad_glProgramLocalParameter4fvARB(target, index, params);
    _post_call_gl_callback(NULL, "glProgramLocalParameter4fvARB", (GLADapiproc) glad_glProgramLocalParameter4fvARB, 3, target, index, params);
    
}
PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glad_debug_glProgramLocalParameter4fvARB = glad_debug_impl_glProgramLocalParameter4fvARB;
PFNGLPROGRAMPARAMETER4DNVPROC glad_glProgramParameter4dNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramParameter4dNV(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    _pre_call_gl_callback("glProgramParameter4dNV", (GLADapiproc) glad_glProgramParameter4dNV, 6, target, index, x, y, z, w);
    glad_glProgramParameter4dNV(target, index, x, y, z, w);
    _post_call_gl_callback(NULL, "glProgramParameter4dNV", (GLADapiproc) glad_glProgramParameter4dNV, 6, target, index, x, y, z, w);
    
}
PFNGLPROGRAMPARAMETER4DNVPROC glad_debug_glProgramParameter4dNV = glad_debug_impl_glProgramParameter4dNV;
PFNGLPROGRAMPARAMETER4DVNVPROC glad_glProgramParameter4dvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramParameter4dvNV(GLenum target, GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glProgramParameter4dvNV", (GLADapiproc) glad_glProgramParameter4dvNV, 3, target, index, v);
    glad_glProgramParameter4dvNV(target, index, v);
    _post_call_gl_callback(NULL, "glProgramParameter4dvNV", (GLADapiproc) glad_glProgramParameter4dvNV, 3, target, index, v);
    
}
PFNGLPROGRAMPARAMETER4DVNVPROC glad_debug_glProgramParameter4dvNV = glad_debug_impl_glProgramParameter4dvNV;
PFNGLPROGRAMPARAMETER4FNVPROC glad_glProgramParameter4fNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramParameter4fNV(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _pre_call_gl_callback("glProgramParameter4fNV", (GLADapiproc) glad_glProgramParameter4fNV, 6, target, index, x, y, z, w);
    glad_glProgramParameter4fNV(target, index, x, y, z, w);
    _post_call_gl_callback(NULL, "glProgramParameter4fNV", (GLADapiproc) glad_glProgramParameter4fNV, 6, target, index, x, y, z, w);
    
}
PFNGLPROGRAMPARAMETER4FNVPROC glad_debug_glProgramParameter4fNV = glad_debug_impl_glProgramParameter4fNV;
PFNGLPROGRAMPARAMETER4FVNVPROC glad_glProgramParameter4fvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramParameter4fvNV(GLenum target, GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glProgramParameter4fvNV", (GLADapiproc) glad_glProgramParameter4fvNV, 3, target, index, v);
    glad_glProgramParameter4fvNV(target, index, v);
    _post_call_gl_callback(NULL, "glProgramParameter4fvNV", (GLADapiproc) glad_glProgramParameter4fvNV, 3, target, index, v);
    
}
PFNGLPROGRAMPARAMETER4FVNVPROC glad_debug_glProgramParameter4fvNV = glad_debug_impl_glProgramParameter4fvNV;
PFNGLPROGRAMPARAMETERS4DVNVPROC glad_glProgramParameters4dvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramParameters4dvNV(GLenum target, GLuint index, GLsizei count, const GLdouble * v) {
    _pre_call_gl_callback("glProgramParameters4dvNV", (GLADapiproc) glad_glProgramParameters4dvNV, 4, target, index, count, v);
    glad_glProgramParameters4dvNV(target, index, count, v);
    _post_call_gl_callback(NULL, "glProgramParameters4dvNV", (GLADapiproc) glad_glProgramParameters4dvNV, 4, target, index, count, v);
    
}
PFNGLPROGRAMPARAMETERS4DVNVPROC glad_debug_glProgramParameters4dvNV = glad_debug_impl_glProgramParameters4dvNV;
PFNGLPROGRAMPARAMETERS4FVNVPROC glad_glProgramParameters4fvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramParameters4fvNV(GLenum target, GLuint index, GLsizei count, const GLfloat * v) {
    _pre_call_gl_callback("glProgramParameters4fvNV", (GLADapiproc) glad_glProgramParameters4fvNV, 4, target, index, count, v);
    glad_glProgramParameters4fvNV(target, index, count, v);
    _post_call_gl_callback(NULL, "glProgramParameters4fvNV", (GLADapiproc) glad_glProgramParameters4fvNV, 4, target, index, count, v);
    
}
PFNGLPROGRAMPARAMETERS4FVNVPROC glad_debug_glProgramParameters4fvNV = glad_debug_impl_glProgramParameters4fvNV;
PFNGLPROGRAMSTRINGARBPROC glad_glProgramStringARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glProgramStringARB(GLenum target, GLenum format, GLsizei len, const void * string) {
    _pre_call_gl_callback("glProgramStringARB", (GLADapiproc) glad_glProgramStringARB, 4, target, format, len, string);
    glad_glProgramStringARB(target, format, len, string);
    _post_call_gl_callback(NULL, "glProgramStringARB", (GLADapiproc) glad_glProgramStringARB, 4, target, format, len, string);
    
}
PFNGLPROGRAMSTRINGARBPROC glad_debug_glProgramStringARB = glad_debug_impl_glProgramStringARB;
PFNGLPUSHATTRIBPROC glad_glPushAttrib = NULL;
static void GLAD_API_PTR glad_debug_impl_glPushAttrib(GLbitfield mask) {
    _pre_call_gl_callback("glPushAttrib", (GLADapiproc) glad_glPushAttrib, 1, mask);
    glad_glPushAttrib(mask);
    _post_call_gl_callback(NULL, "glPushAttrib", (GLADapiproc) glad_glPushAttrib, 1, mask);
    
}
PFNGLPUSHATTRIBPROC glad_debug_glPushAttrib = glad_debug_impl_glPushAttrib;
PFNGLPUSHCLIENTATTRIBPROC glad_glPushClientAttrib = NULL;
static void GLAD_API_PTR glad_debug_impl_glPushClientAttrib(GLbitfield mask) {
    _pre_call_gl_callback("glPushClientAttrib", (GLADapiproc) glad_glPushClientAttrib, 1, mask);
    glad_glPushClientAttrib(mask);
    _post_call_gl_callback(NULL, "glPushClientAttrib", (GLADapiproc) glad_glPushClientAttrib, 1, mask);
    
}
PFNGLPUSHCLIENTATTRIBPROC glad_debug_glPushClientAttrib = glad_debug_impl_glPushClientAttrib;
PFNGLPUSHDEBUGGROUPPROC glad_glPushDebugGroup = NULL;
static void GLAD_API_PTR glad_debug_impl_glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar * message) {
    _pre_call_gl_callback("glPushDebugGroup", (GLADapiproc) glad_glPushDebugGroup, 4, source, id, length, message);
    glad_glPushDebugGroup(source, id, length, message);
    _post_call_gl_callback(NULL, "glPushDebugGroup", (GLADapiproc) glad_glPushDebugGroup, 4, source, id, length, message);
    
}
PFNGLPUSHDEBUGGROUPPROC glad_debug_glPushDebugGroup = glad_debug_impl_glPushDebugGroup;
PFNGLPUSHMATRIXPROC glad_glPushMatrix = NULL;
static void GLAD_API_PTR glad_debug_impl_glPushMatrix(void) {
    _pre_call_gl_callback("glPushMatrix", (GLADapiproc) glad_glPushMatrix, 0);
    glad_glPushMatrix();
    _post_call_gl_callback(NULL, "glPushMatrix", (GLADapiproc) glad_glPushMatrix, 0);
    
}
PFNGLPUSHMATRIXPROC glad_debug_glPushMatrix = glad_debug_impl_glPushMatrix;
PFNGLPUSHNAMEPROC glad_glPushName = NULL;
static void GLAD_API_PTR glad_debug_impl_glPushName(GLuint name) {
    _pre_call_gl_callback("glPushName", (GLADapiproc) glad_glPushName, 1, name);
    glad_glPushName(name);
    _post_call_gl_callback(NULL, "glPushName", (GLADapiproc) glad_glPushName, 1, name);
    
}
PFNGLPUSHNAMEPROC glad_debug_glPushName = glad_debug_impl_glPushName;
PFNGLRASTERPOS2DPROC glad_glRasterPos2d = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos2d(GLdouble x, GLdouble y) {
    _pre_call_gl_callback("glRasterPos2d", (GLADapiproc) glad_glRasterPos2d, 2, x, y);
    glad_glRasterPos2d(x, y);
    _post_call_gl_callback(NULL, "glRasterPos2d", (GLADapiproc) glad_glRasterPos2d, 2, x, y);
    
}
PFNGLRASTERPOS2DPROC glad_debug_glRasterPos2d = glad_debug_impl_glRasterPos2d;
PFNGLRASTERPOS2DVPROC glad_glRasterPos2dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos2dv(const GLdouble * v) {
    _pre_call_gl_callback("glRasterPos2dv", (GLADapiproc) glad_glRasterPos2dv, 1, v);
    glad_glRasterPos2dv(v);
    _post_call_gl_callback(NULL, "glRasterPos2dv", (GLADapiproc) glad_glRasterPos2dv, 1, v);
    
}
PFNGLRASTERPOS2DVPROC glad_debug_glRasterPos2dv = glad_debug_impl_glRasterPos2dv;
PFNGLRASTERPOS2FPROC glad_glRasterPos2f = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos2f(GLfloat x, GLfloat y) {
    _pre_call_gl_callback("glRasterPos2f", (GLADapiproc) glad_glRasterPos2f, 2, x, y);
    glad_glRasterPos2f(x, y);
    _post_call_gl_callback(NULL, "glRasterPos2f", (GLADapiproc) glad_glRasterPos2f, 2, x, y);
    
}
PFNGLRASTERPOS2FPROC glad_debug_glRasterPos2f = glad_debug_impl_glRasterPos2f;
PFNGLRASTERPOS2FVPROC glad_glRasterPos2fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos2fv(const GLfloat * v) {
    _pre_call_gl_callback("glRasterPos2fv", (GLADapiproc) glad_glRasterPos2fv, 1, v);
    glad_glRasterPos2fv(v);
    _post_call_gl_callback(NULL, "glRasterPos2fv", (GLADapiproc) glad_glRasterPos2fv, 1, v);
    
}
PFNGLRASTERPOS2FVPROC glad_debug_glRasterPos2fv = glad_debug_impl_glRasterPos2fv;
PFNGLRASTERPOS2IPROC glad_glRasterPos2i = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos2i(GLint x, GLint y) {
    _pre_call_gl_callback("glRasterPos2i", (GLADapiproc) glad_glRasterPos2i, 2, x, y);
    glad_glRasterPos2i(x, y);
    _post_call_gl_callback(NULL, "glRasterPos2i", (GLADapiproc) glad_glRasterPos2i, 2, x, y);
    
}
PFNGLRASTERPOS2IPROC glad_debug_glRasterPos2i = glad_debug_impl_glRasterPos2i;
PFNGLRASTERPOS2IVPROC glad_glRasterPos2iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos2iv(const GLint * v) {
    _pre_call_gl_callback("glRasterPos2iv", (GLADapiproc) glad_glRasterPos2iv, 1, v);
    glad_glRasterPos2iv(v);
    _post_call_gl_callback(NULL, "glRasterPos2iv", (GLADapiproc) glad_glRasterPos2iv, 1, v);
    
}
PFNGLRASTERPOS2IVPROC glad_debug_glRasterPos2iv = glad_debug_impl_glRasterPos2iv;
PFNGLRASTERPOS2SPROC glad_glRasterPos2s = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos2s(GLshort x, GLshort y) {
    _pre_call_gl_callback("glRasterPos2s", (GLADapiproc) glad_glRasterPos2s, 2, x, y);
    glad_glRasterPos2s(x, y);
    _post_call_gl_callback(NULL, "glRasterPos2s", (GLADapiproc) glad_glRasterPos2s, 2, x, y);
    
}
PFNGLRASTERPOS2SPROC glad_debug_glRasterPos2s = glad_debug_impl_glRasterPos2s;
PFNGLRASTERPOS2SVPROC glad_glRasterPos2sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos2sv(const GLshort * v) {
    _pre_call_gl_callback("glRasterPos2sv", (GLADapiproc) glad_glRasterPos2sv, 1, v);
    glad_glRasterPos2sv(v);
    _post_call_gl_callback(NULL, "glRasterPos2sv", (GLADapiproc) glad_glRasterPos2sv, 1, v);
    
}
PFNGLRASTERPOS2SVPROC glad_debug_glRasterPos2sv = glad_debug_impl_glRasterPos2sv;
PFNGLRASTERPOS3DPROC glad_glRasterPos3d = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
    _pre_call_gl_callback("glRasterPos3d", (GLADapiproc) glad_glRasterPos3d, 3, x, y, z);
    glad_glRasterPos3d(x, y, z);
    _post_call_gl_callback(NULL, "glRasterPos3d", (GLADapiproc) glad_glRasterPos3d, 3, x, y, z);
    
}
PFNGLRASTERPOS3DPROC glad_debug_glRasterPos3d = glad_debug_impl_glRasterPos3d;
PFNGLRASTERPOS3DVPROC glad_glRasterPos3dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos3dv(const GLdouble * v) {
    _pre_call_gl_callback("glRasterPos3dv", (GLADapiproc) glad_glRasterPos3dv, 1, v);
    glad_glRasterPos3dv(v);
    _post_call_gl_callback(NULL, "glRasterPos3dv", (GLADapiproc) glad_glRasterPos3dv, 1, v);
    
}
PFNGLRASTERPOS3DVPROC glad_debug_glRasterPos3dv = glad_debug_impl_glRasterPos3dv;
PFNGLRASTERPOS3FPROC glad_glRasterPos3f = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
    _pre_call_gl_callback("glRasterPos3f", (GLADapiproc) glad_glRasterPos3f, 3, x, y, z);
    glad_glRasterPos3f(x, y, z);
    _post_call_gl_callback(NULL, "glRasterPos3f", (GLADapiproc) glad_glRasterPos3f, 3, x, y, z);
    
}
PFNGLRASTERPOS3FPROC glad_debug_glRasterPos3f = glad_debug_impl_glRasterPos3f;
PFNGLRASTERPOS3FVPROC glad_glRasterPos3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos3fv(const GLfloat * v) {
    _pre_call_gl_callback("glRasterPos3fv", (GLADapiproc) glad_glRasterPos3fv, 1, v);
    glad_glRasterPos3fv(v);
    _post_call_gl_callback(NULL, "glRasterPos3fv", (GLADapiproc) glad_glRasterPos3fv, 1, v);
    
}
PFNGLRASTERPOS3FVPROC glad_debug_glRasterPos3fv = glad_debug_impl_glRasterPos3fv;
PFNGLRASTERPOS3IPROC glad_glRasterPos3i = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos3i(GLint x, GLint y, GLint z) {
    _pre_call_gl_callback("glRasterPos3i", (GLADapiproc) glad_glRasterPos3i, 3, x, y, z);
    glad_glRasterPos3i(x, y, z);
    _post_call_gl_callback(NULL, "glRasterPos3i", (GLADapiproc) glad_glRasterPos3i, 3, x, y, z);
    
}
PFNGLRASTERPOS3IPROC glad_debug_glRasterPos3i = glad_debug_impl_glRasterPos3i;
PFNGLRASTERPOS3IVPROC glad_glRasterPos3iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos3iv(const GLint * v) {
    _pre_call_gl_callback("glRasterPos3iv", (GLADapiproc) glad_glRasterPos3iv, 1, v);
    glad_glRasterPos3iv(v);
    _post_call_gl_callback(NULL, "glRasterPos3iv", (GLADapiproc) glad_glRasterPos3iv, 1, v);
    
}
PFNGLRASTERPOS3IVPROC glad_debug_glRasterPos3iv = glad_debug_impl_glRasterPos3iv;
PFNGLRASTERPOS3SPROC glad_glRasterPos3s = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos3s(GLshort x, GLshort y, GLshort z) {
    _pre_call_gl_callback("glRasterPos3s", (GLADapiproc) glad_glRasterPos3s, 3, x, y, z);
    glad_glRasterPos3s(x, y, z);
    _post_call_gl_callback(NULL, "glRasterPos3s", (GLADapiproc) glad_glRasterPos3s, 3, x, y, z);
    
}
PFNGLRASTERPOS3SPROC glad_debug_glRasterPos3s = glad_debug_impl_glRasterPos3s;
PFNGLRASTERPOS3SVPROC glad_glRasterPos3sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos3sv(const GLshort * v) {
    _pre_call_gl_callback("glRasterPos3sv", (GLADapiproc) glad_glRasterPos3sv, 1, v);
    glad_glRasterPos3sv(v);
    _post_call_gl_callback(NULL, "glRasterPos3sv", (GLADapiproc) glad_glRasterPos3sv, 1, v);
    
}
PFNGLRASTERPOS3SVPROC glad_debug_glRasterPos3sv = glad_debug_impl_glRasterPos3sv;
PFNGLRASTERPOS4DPROC glad_glRasterPos4d = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    _pre_call_gl_callback("glRasterPos4d", (GLADapiproc) glad_glRasterPos4d, 4, x, y, z, w);
    glad_glRasterPos4d(x, y, z, w);
    _post_call_gl_callback(NULL, "glRasterPos4d", (GLADapiproc) glad_glRasterPos4d, 4, x, y, z, w);
    
}
PFNGLRASTERPOS4DPROC glad_debug_glRasterPos4d = glad_debug_impl_glRasterPos4d;
PFNGLRASTERPOS4DVPROC glad_glRasterPos4dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos4dv(const GLdouble * v) {
    _pre_call_gl_callback("glRasterPos4dv", (GLADapiproc) glad_glRasterPos4dv, 1, v);
    glad_glRasterPos4dv(v);
    _post_call_gl_callback(NULL, "glRasterPos4dv", (GLADapiproc) glad_glRasterPos4dv, 1, v);
    
}
PFNGLRASTERPOS4DVPROC glad_debug_glRasterPos4dv = glad_debug_impl_glRasterPos4dv;
PFNGLRASTERPOS4FPROC glad_glRasterPos4f = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _pre_call_gl_callback("glRasterPos4f", (GLADapiproc) glad_glRasterPos4f, 4, x, y, z, w);
    glad_glRasterPos4f(x, y, z, w);
    _post_call_gl_callback(NULL, "glRasterPos4f", (GLADapiproc) glad_glRasterPos4f, 4, x, y, z, w);
    
}
PFNGLRASTERPOS4FPROC glad_debug_glRasterPos4f = glad_debug_impl_glRasterPos4f;
PFNGLRASTERPOS4FVPROC glad_glRasterPos4fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos4fv(const GLfloat * v) {
    _pre_call_gl_callback("glRasterPos4fv", (GLADapiproc) glad_glRasterPos4fv, 1, v);
    glad_glRasterPos4fv(v);
    _post_call_gl_callback(NULL, "glRasterPos4fv", (GLADapiproc) glad_glRasterPos4fv, 1, v);
    
}
PFNGLRASTERPOS4FVPROC glad_debug_glRasterPos4fv = glad_debug_impl_glRasterPos4fv;
PFNGLRASTERPOS4IPROC glad_glRasterPos4i = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {
    _pre_call_gl_callback("glRasterPos4i", (GLADapiproc) glad_glRasterPos4i, 4, x, y, z, w);
    glad_glRasterPos4i(x, y, z, w);
    _post_call_gl_callback(NULL, "glRasterPos4i", (GLADapiproc) glad_glRasterPos4i, 4, x, y, z, w);
    
}
PFNGLRASTERPOS4IPROC glad_debug_glRasterPos4i = glad_debug_impl_glRasterPos4i;
PFNGLRASTERPOS4IVPROC glad_glRasterPos4iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos4iv(const GLint * v) {
    _pre_call_gl_callback("glRasterPos4iv", (GLADapiproc) glad_glRasterPos4iv, 1, v);
    glad_glRasterPos4iv(v);
    _post_call_gl_callback(NULL, "glRasterPos4iv", (GLADapiproc) glad_glRasterPos4iv, 1, v);
    
}
PFNGLRASTERPOS4IVPROC glad_debug_glRasterPos4iv = glad_debug_impl_glRasterPos4iv;
PFNGLRASTERPOS4SPROC glad_glRasterPos4s = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    _pre_call_gl_callback("glRasterPos4s", (GLADapiproc) glad_glRasterPos4s, 4, x, y, z, w);
    glad_glRasterPos4s(x, y, z, w);
    _post_call_gl_callback(NULL, "glRasterPos4s", (GLADapiproc) glad_glRasterPos4s, 4, x, y, z, w);
    
}
PFNGLRASTERPOS4SPROC glad_debug_glRasterPos4s = glad_debug_impl_glRasterPos4s;
PFNGLRASTERPOS4SVPROC glad_glRasterPos4sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRasterPos4sv(const GLshort * v) {
    _pre_call_gl_callback("glRasterPos4sv", (GLADapiproc) glad_glRasterPos4sv, 1, v);
    glad_glRasterPos4sv(v);
    _post_call_gl_callback(NULL, "glRasterPos4sv", (GLADapiproc) glad_glRasterPos4sv, 1, v);
    
}
PFNGLRASTERPOS4SVPROC glad_debug_glRasterPos4sv = glad_debug_impl_glRasterPos4sv;
PFNGLREADBUFFERPROC glad_glReadBuffer = NULL;
static void GLAD_API_PTR glad_debug_impl_glReadBuffer(GLenum src) {
    _pre_call_gl_callback("glReadBuffer", (GLADapiproc) glad_glReadBuffer, 1, src);
    glad_glReadBuffer(src);
    _post_call_gl_callback(NULL, "glReadBuffer", (GLADapiproc) glad_glReadBuffer, 1, src);
    
}
PFNGLREADBUFFERPROC glad_debug_glReadBuffer = glad_debug_impl_glReadBuffer;
PFNGLREADPIXELSPROC glad_glReadPixels = NULL;
static void GLAD_API_PTR glad_debug_impl_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels) {
    _pre_call_gl_callback("glReadPixels", (GLADapiproc) glad_glReadPixels, 7, x, y, width, height, format, type, pixels);
    glad_glReadPixels(x, y, width, height, format, type, pixels);
    _post_call_gl_callback(NULL, "glReadPixels", (GLADapiproc) glad_glReadPixels, 7, x, y, width, height, format, type, pixels);
    
}
PFNGLREADPIXELSPROC glad_debug_glReadPixels = glad_debug_impl_glReadPixels;
PFNGLRECTDPROC glad_glRectd = NULL;
static void GLAD_API_PTR glad_debug_impl_glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
    _pre_call_gl_callback("glRectd", (GLADapiproc) glad_glRectd, 4, x1, y1, x2, y2);
    glad_glRectd(x1, y1, x2, y2);
    _post_call_gl_callback(NULL, "glRectd", (GLADapiproc) glad_glRectd, 4, x1, y1, x2, y2);
    
}
PFNGLRECTDPROC glad_debug_glRectd = glad_debug_impl_glRectd;
PFNGLRECTDVPROC glad_glRectdv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRectdv(const GLdouble * v1, const GLdouble * v2) {
    _pre_call_gl_callback("glRectdv", (GLADapiproc) glad_glRectdv, 2, v1, v2);
    glad_glRectdv(v1, v2);
    _post_call_gl_callback(NULL, "glRectdv", (GLADapiproc) glad_glRectdv, 2, v1, v2);
    
}
PFNGLRECTDVPROC glad_debug_glRectdv = glad_debug_impl_glRectdv;
PFNGLRECTFPROC glad_glRectf = NULL;
static void GLAD_API_PTR glad_debug_impl_glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    _pre_call_gl_callback("glRectf", (GLADapiproc) glad_glRectf, 4, x1, y1, x2, y2);
    glad_glRectf(x1, y1, x2, y2);
    _post_call_gl_callback(NULL, "glRectf", (GLADapiproc) glad_glRectf, 4, x1, y1, x2, y2);
    
}
PFNGLRECTFPROC glad_debug_glRectf = glad_debug_impl_glRectf;
PFNGLRECTFVPROC glad_glRectfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRectfv(const GLfloat * v1, const GLfloat * v2) {
    _pre_call_gl_callback("glRectfv", (GLADapiproc) glad_glRectfv, 2, v1, v2);
    glad_glRectfv(v1, v2);
    _post_call_gl_callback(NULL, "glRectfv", (GLADapiproc) glad_glRectfv, 2, v1, v2);
    
}
PFNGLRECTFVPROC glad_debug_glRectfv = glad_debug_impl_glRectfv;
PFNGLRECTIPROC glad_glRecti = NULL;
static void GLAD_API_PTR glad_debug_impl_glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {
    _pre_call_gl_callback("glRecti", (GLADapiproc) glad_glRecti, 4, x1, y1, x2, y2);
    glad_glRecti(x1, y1, x2, y2);
    _post_call_gl_callback(NULL, "glRecti", (GLADapiproc) glad_glRecti, 4, x1, y1, x2, y2);
    
}
PFNGLRECTIPROC glad_debug_glRecti = glad_debug_impl_glRecti;
PFNGLRECTIVPROC glad_glRectiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRectiv(const GLint * v1, const GLint * v2) {
    _pre_call_gl_callback("glRectiv", (GLADapiproc) glad_glRectiv, 2, v1, v2);
    glad_glRectiv(v1, v2);
    _post_call_gl_callback(NULL, "glRectiv", (GLADapiproc) glad_glRectiv, 2, v1, v2);
    
}
PFNGLRECTIVPROC glad_debug_glRectiv = glad_debug_impl_glRectiv;
PFNGLRECTSPROC glad_glRects = NULL;
static void GLAD_API_PTR glad_debug_impl_glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
    _pre_call_gl_callback("glRects", (GLADapiproc) glad_glRects, 4, x1, y1, x2, y2);
    glad_glRects(x1, y1, x2, y2);
    _post_call_gl_callback(NULL, "glRects", (GLADapiproc) glad_glRects, 4, x1, y1, x2, y2);
    
}
PFNGLRECTSPROC glad_debug_glRects = glad_debug_impl_glRects;
PFNGLRECTSVPROC glad_glRectsv = NULL;
static void GLAD_API_PTR glad_debug_impl_glRectsv(const GLshort * v1, const GLshort * v2) {
    _pre_call_gl_callback("glRectsv", (GLADapiproc) glad_glRectsv, 2, v1, v2);
    glad_glRectsv(v1, v2);
    _post_call_gl_callback(NULL, "glRectsv", (GLADapiproc) glad_glRectsv, 2, v1, v2);
    
}
PFNGLRECTSVPROC glad_debug_glRectsv = glad_debug_impl_glRectsv;
PFNGLRENDERMODEPROC glad_glRenderMode = NULL;
static GLint GLAD_API_PTR glad_debug_impl_glRenderMode(GLenum mode) {
    GLint ret;
    _pre_call_gl_callback("glRenderMode", (GLADapiproc) glad_glRenderMode, 1, mode);
    ret = glad_glRenderMode(mode);
    _post_call_gl_callback((void*) &ret, "glRenderMode", (GLADapiproc) glad_glRenderMode, 1, mode);
    return ret;
}
PFNGLRENDERMODEPROC glad_debug_glRenderMode = glad_debug_impl_glRenderMode;
PFNGLREQUESTRESIDENTPROGRAMSNVPROC glad_glRequestResidentProgramsNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glRequestResidentProgramsNV(GLsizei n, const GLuint * programs) {
    _pre_call_gl_callback("glRequestResidentProgramsNV", (GLADapiproc) glad_glRequestResidentProgramsNV, 2, n, programs);
    glad_glRequestResidentProgramsNV(n, programs);
    _post_call_gl_callback(NULL, "glRequestResidentProgramsNV", (GLADapiproc) glad_glRequestResidentProgramsNV, 2, n, programs);
    
}
PFNGLREQUESTRESIDENTPROGRAMSNVPROC glad_debug_glRequestResidentProgramsNV = glad_debug_impl_glRequestResidentProgramsNV;
PFNGLRESETHISTOGRAMPROC glad_glResetHistogram = NULL;
static void GLAD_API_PTR glad_debug_impl_glResetHistogram(GLenum target) {
    _pre_call_gl_callback("glResetHistogram", (GLADapiproc) glad_glResetHistogram, 1, target);
    glad_glResetHistogram(target);
    _post_call_gl_callback(NULL, "glResetHistogram", (GLADapiproc) glad_glResetHistogram, 1, target);
    
}
PFNGLRESETHISTOGRAMPROC glad_debug_glResetHistogram = glad_debug_impl_glResetHistogram;
PFNGLRESETMINMAXPROC glad_glResetMinmax = NULL;
static void GLAD_API_PTR glad_debug_impl_glResetMinmax(GLenum target) {
    _pre_call_gl_callback("glResetMinmax", (GLADapiproc) glad_glResetMinmax, 1, target);
    glad_glResetMinmax(target);
    _post_call_gl_callback(NULL, "glResetMinmax", (GLADapiproc) glad_glResetMinmax, 1, target);
    
}
PFNGLRESETMINMAXPROC glad_debug_glResetMinmax = glad_debug_impl_glResetMinmax;
PFNGLROTATEDPROC glad_glRotated = NULL;
static void GLAD_API_PTR glad_debug_impl_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    _pre_call_gl_callback("glRotated", (GLADapiproc) glad_glRotated, 4, angle, x, y, z);
    glad_glRotated(angle, x, y, z);
    _post_call_gl_callback(NULL, "glRotated", (GLADapiproc) glad_glRotated, 4, angle, x, y, z);
    
}
PFNGLROTATEDPROC glad_debug_glRotated = glad_debug_impl_glRotated;
PFNGLROTATEFPROC glad_glRotatef = NULL;
static void GLAD_API_PTR glad_debug_impl_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    _pre_call_gl_callback("glRotatef", (GLADapiproc) glad_glRotatef, 4, angle, x, y, z);
    glad_glRotatef(angle, x, y, z);
    _post_call_gl_callback(NULL, "glRotatef", (GLADapiproc) glad_glRotatef, 4, angle, x, y, z);
    
}
PFNGLROTATEFPROC glad_debug_glRotatef = glad_debug_impl_glRotatef;
PFNGLSAMPLECOVERAGEPROC glad_glSampleCoverage = NULL;
static void GLAD_API_PTR glad_debug_impl_glSampleCoverage(GLfloat value, GLboolean invert) {
    _pre_call_gl_callback("glSampleCoverage", (GLADapiproc) glad_glSampleCoverage, 2, value, invert);
    glad_glSampleCoverage(value, invert);
    _post_call_gl_callback(NULL, "glSampleCoverage", (GLADapiproc) glad_glSampleCoverage, 2, value, invert);
    
}
PFNGLSAMPLECOVERAGEPROC glad_debug_glSampleCoverage = glad_debug_impl_glSampleCoverage;
PFNGLSAMPLECOVERAGEARBPROC glad_glSampleCoverageARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glSampleCoverageARB(GLfloat value, GLboolean invert) {
    _pre_call_gl_callback("glSampleCoverageARB", (GLADapiproc) glad_glSampleCoverageARB, 2, value, invert);
    glad_glSampleCoverageARB(value, invert);
    _post_call_gl_callback(NULL, "glSampleCoverageARB", (GLADapiproc) glad_glSampleCoverageARB, 2, value, invert);
    
}
PFNGLSAMPLECOVERAGEARBPROC glad_debug_glSampleCoverageARB = glad_debug_impl_glSampleCoverageARB;
PFNGLSCALEDPROC glad_glScaled = NULL;
static void GLAD_API_PTR glad_debug_impl_glScaled(GLdouble x, GLdouble y, GLdouble z) {
    _pre_call_gl_callback("glScaled", (GLADapiproc) glad_glScaled, 3, x, y, z);
    glad_glScaled(x, y, z);
    _post_call_gl_callback(NULL, "glScaled", (GLADapiproc) glad_glScaled, 3, x, y, z);
    
}
PFNGLSCALEDPROC glad_debug_glScaled = glad_debug_impl_glScaled;
PFNGLSCALEFPROC glad_glScalef = NULL;
static void GLAD_API_PTR glad_debug_impl_glScalef(GLfloat x, GLfloat y, GLfloat z) {
    _pre_call_gl_callback("glScalef", (GLADapiproc) glad_glScalef, 3, x, y, z);
    glad_glScalef(x, y, z);
    _post_call_gl_callback(NULL, "glScalef", (GLADapiproc) glad_glScalef, 3, x, y, z);
    
}
PFNGLSCALEFPROC glad_debug_glScalef = glad_debug_impl_glScalef;
PFNGLSCISSORPROC glad_glScissor = NULL;
static void GLAD_API_PTR glad_debug_impl_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    _pre_call_gl_callback("glScissor", (GLADapiproc) glad_glScissor, 4, x, y, width, height);
    glad_glScissor(x, y, width, height);
    _post_call_gl_callback(NULL, "glScissor", (GLADapiproc) glad_glScissor, 4, x, y, width, height);
    
}
PFNGLSCISSORPROC glad_debug_glScissor = glad_debug_impl_glScissor;
PFNGLSECONDARYCOLOR3BPROC glad_glSecondaryColor3b = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    _pre_call_gl_callback("glSecondaryColor3b", (GLADapiproc) glad_glSecondaryColor3b, 3, red, green, blue);
    glad_glSecondaryColor3b(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3b", (GLADapiproc) glad_glSecondaryColor3b, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3BPROC glad_debug_glSecondaryColor3b = glad_debug_impl_glSecondaryColor3b;
PFNGLSECONDARYCOLOR3BEXTPROC glad_glSecondaryColor3bEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue) {
    _pre_call_gl_callback("glSecondaryColor3bEXT", (GLADapiproc) glad_glSecondaryColor3bEXT, 3, red, green, blue);
    glad_glSecondaryColor3bEXT(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3bEXT", (GLADapiproc) glad_glSecondaryColor3bEXT, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3BEXTPROC glad_debug_glSecondaryColor3bEXT = glad_debug_impl_glSecondaryColor3bEXT;
PFNGLSECONDARYCOLOR3BVPROC glad_glSecondaryColor3bv = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3bv(const GLbyte * v) {
    _pre_call_gl_callback("glSecondaryColor3bv", (GLADapiproc) glad_glSecondaryColor3bv, 1, v);
    glad_glSecondaryColor3bv(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3bv", (GLADapiproc) glad_glSecondaryColor3bv, 1, v);
    
}
PFNGLSECONDARYCOLOR3BVPROC glad_debug_glSecondaryColor3bv = glad_debug_impl_glSecondaryColor3bv;
PFNGLSECONDARYCOLOR3BVEXTPROC glad_glSecondaryColor3bvEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3bvEXT(const GLbyte * v) {
    _pre_call_gl_callback("glSecondaryColor3bvEXT", (GLADapiproc) glad_glSecondaryColor3bvEXT, 1, v);
    glad_glSecondaryColor3bvEXT(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3bvEXT", (GLADapiproc) glad_glSecondaryColor3bvEXT, 1, v);
    
}
PFNGLSECONDARYCOLOR3BVEXTPROC glad_debug_glSecondaryColor3bvEXT = glad_debug_impl_glSecondaryColor3bvEXT;
PFNGLSECONDARYCOLOR3DPROC glad_glSecondaryColor3d = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    _pre_call_gl_callback("glSecondaryColor3d", (GLADapiproc) glad_glSecondaryColor3d, 3, red, green, blue);
    glad_glSecondaryColor3d(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3d", (GLADapiproc) glad_glSecondaryColor3d, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3DPROC glad_debug_glSecondaryColor3d = glad_debug_impl_glSecondaryColor3d;
PFNGLSECONDARYCOLOR3DEXTPROC glad_glSecondaryColor3dEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue) {
    _pre_call_gl_callback("glSecondaryColor3dEXT", (GLADapiproc) glad_glSecondaryColor3dEXT, 3, red, green, blue);
    glad_glSecondaryColor3dEXT(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3dEXT", (GLADapiproc) glad_glSecondaryColor3dEXT, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3DEXTPROC glad_debug_glSecondaryColor3dEXT = glad_debug_impl_glSecondaryColor3dEXT;
PFNGLSECONDARYCOLOR3DVPROC glad_glSecondaryColor3dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3dv(const GLdouble * v) {
    _pre_call_gl_callback("glSecondaryColor3dv", (GLADapiproc) glad_glSecondaryColor3dv, 1, v);
    glad_glSecondaryColor3dv(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3dv", (GLADapiproc) glad_glSecondaryColor3dv, 1, v);
    
}
PFNGLSECONDARYCOLOR3DVPROC glad_debug_glSecondaryColor3dv = glad_debug_impl_glSecondaryColor3dv;
PFNGLSECONDARYCOLOR3DVEXTPROC glad_glSecondaryColor3dvEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3dvEXT(const GLdouble * v) {
    _pre_call_gl_callback("glSecondaryColor3dvEXT", (GLADapiproc) glad_glSecondaryColor3dvEXT, 1, v);
    glad_glSecondaryColor3dvEXT(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3dvEXT", (GLADapiproc) glad_glSecondaryColor3dvEXT, 1, v);
    
}
PFNGLSECONDARYCOLOR3DVEXTPROC glad_debug_glSecondaryColor3dvEXT = glad_debug_impl_glSecondaryColor3dvEXT;
PFNGLSECONDARYCOLOR3FPROC glad_glSecondaryColor3f = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    _pre_call_gl_callback("glSecondaryColor3f", (GLADapiproc) glad_glSecondaryColor3f, 3, red, green, blue);
    glad_glSecondaryColor3f(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3f", (GLADapiproc) glad_glSecondaryColor3f, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3FPROC glad_debug_glSecondaryColor3f = glad_debug_impl_glSecondaryColor3f;
PFNGLSECONDARYCOLOR3FEXTPROC glad_glSecondaryColor3fEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue) {
    _pre_call_gl_callback("glSecondaryColor3fEXT", (GLADapiproc) glad_glSecondaryColor3fEXT, 3, red, green, blue);
    glad_glSecondaryColor3fEXT(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3fEXT", (GLADapiproc) glad_glSecondaryColor3fEXT, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3FEXTPROC glad_debug_glSecondaryColor3fEXT = glad_debug_impl_glSecondaryColor3fEXT;
PFNGLSECONDARYCOLOR3FVPROC glad_glSecondaryColor3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3fv(const GLfloat * v) {
    _pre_call_gl_callback("glSecondaryColor3fv", (GLADapiproc) glad_glSecondaryColor3fv, 1, v);
    glad_glSecondaryColor3fv(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3fv", (GLADapiproc) glad_glSecondaryColor3fv, 1, v);
    
}
PFNGLSECONDARYCOLOR3FVPROC glad_debug_glSecondaryColor3fv = glad_debug_impl_glSecondaryColor3fv;
PFNGLSECONDARYCOLOR3FVEXTPROC glad_glSecondaryColor3fvEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3fvEXT(const GLfloat * v) {
    _pre_call_gl_callback("glSecondaryColor3fvEXT", (GLADapiproc) glad_glSecondaryColor3fvEXT, 1, v);
    glad_glSecondaryColor3fvEXT(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3fvEXT", (GLADapiproc) glad_glSecondaryColor3fvEXT, 1, v);
    
}
PFNGLSECONDARYCOLOR3FVEXTPROC glad_debug_glSecondaryColor3fvEXT = glad_debug_impl_glSecondaryColor3fvEXT;
PFNGLSECONDARYCOLOR3IPROC glad_glSecondaryColor3i = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3i(GLint red, GLint green, GLint blue) {
    _pre_call_gl_callback("glSecondaryColor3i", (GLADapiproc) glad_glSecondaryColor3i, 3, red, green, blue);
    glad_glSecondaryColor3i(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3i", (GLADapiproc) glad_glSecondaryColor3i, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3IPROC glad_debug_glSecondaryColor3i = glad_debug_impl_glSecondaryColor3i;
PFNGLSECONDARYCOLOR3IEXTPROC glad_glSecondaryColor3iEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3iEXT(GLint red, GLint green, GLint blue) {
    _pre_call_gl_callback("glSecondaryColor3iEXT", (GLADapiproc) glad_glSecondaryColor3iEXT, 3, red, green, blue);
    glad_glSecondaryColor3iEXT(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3iEXT", (GLADapiproc) glad_glSecondaryColor3iEXT, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3IEXTPROC glad_debug_glSecondaryColor3iEXT = glad_debug_impl_glSecondaryColor3iEXT;
PFNGLSECONDARYCOLOR3IVPROC glad_glSecondaryColor3iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3iv(const GLint * v) {
    _pre_call_gl_callback("glSecondaryColor3iv", (GLADapiproc) glad_glSecondaryColor3iv, 1, v);
    glad_glSecondaryColor3iv(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3iv", (GLADapiproc) glad_glSecondaryColor3iv, 1, v);
    
}
PFNGLSECONDARYCOLOR3IVPROC glad_debug_glSecondaryColor3iv = glad_debug_impl_glSecondaryColor3iv;
PFNGLSECONDARYCOLOR3IVEXTPROC glad_glSecondaryColor3ivEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3ivEXT(const GLint * v) {
    _pre_call_gl_callback("glSecondaryColor3ivEXT", (GLADapiproc) glad_glSecondaryColor3ivEXT, 1, v);
    glad_glSecondaryColor3ivEXT(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3ivEXT", (GLADapiproc) glad_glSecondaryColor3ivEXT, 1, v);
    
}
PFNGLSECONDARYCOLOR3IVEXTPROC glad_debug_glSecondaryColor3ivEXT = glad_debug_impl_glSecondaryColor3ivEXT;
PFNGLSECONDARYCOLOR3SPROC glad_glSecondaryColor3s = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) {
    _pre_call_gl_callback("glSecondaryColor3s", (GLADapiproc) glad_glSecondaryColor3s, 3, red, green, blue);
    glad_glSecondaryColor3s(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3s", (GLADapiproc) glad_glSecondaryColor3s, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3SPROC glad_debug_glSecondaryColor3s = glad_debug_impl_glSecondaryColor3s;
PFNGLSECONDARYCOLOR3SEXTPROC glad_glSecondaryColor3sEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue) {
    _pre_call_gl_callback("glSecondaryColor3sEXT", (GLADapiproc) glad_glSecondaryColor3sEXT, 3, red, green, blue);
    glad_glSecondaryColor3sEXT(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3sEXT", (GLADapiproc) glad_glSecondaryColor3sEXT, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3SEXTPROC glad_debug_glSecondaryColor3sEXT = glad_debug_impl_glSecondaryColor3sEXT;
PFNGLSECONDARYCOLOR3SVPROC glad_glSecondaryColor3sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3sv(const GLshort * v) {
    _pre_call_gl_callback("glSecondaryColor3sv", (GLADapiproc) glad_glSecondaryColor3sv, 1, v);
    glad_glSecondaryColor3sv(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3sv", (GLADapiproc) glad_glSecondaryColor3sv, 1, v);
    
}
PFNGLSECONDARYCOLOR3SVPROC glad_debug_glSecondaryColor3sv = glad_debug_impl_glSecondaryColor3sv;
PFNGLSECONDARYCOLOR3SVEXTPROC glad_glSecondaryColor3svEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3svEXT(const GLshort * v) {
    _pre_call_gl_callback("glSecondaryColor3svEXT", (GLADapiproc) glad_glSecondaryColor3svEXT, 1, v);
    glad_glSecondaryColor3svEXT(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3svEXT", (GLADapiproc) glad_glSecondaryColor3svEXT, 1, v);
    
}
PFNGLSECONDARYCOLOR3SVEXTPROC glad_debug_glSecondaryColor3svEXT = glad_debug_impl_glSecondaryColor3svEXT;
PFNGLSECONDARYCOLOR3UBPROC glad_glSecondaryColor3ub = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    _pre_call_gl_callback("glSecondaryColor3ub", (GLADapiproc) glad_glSecondaryColor3ub, 3, red, green, blue);
    glad_glSecondaryColor3ub(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3ub", (GLADapiproc) glad_glSecondaryColor3ub, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3UBPROC glad_debug_glSecondaryColor3ub = glad_debug_impl_glSecondaryColor3ub;
PFNGLSECONDARYCOLOR3UBEXTPROC glad_glSecondaryColor3ubEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue) {
    _pre_call_gl_callback("glSecondaryColor3ubEXT", (GLADapiproc) glad_glSecondaryColor3ubEXT, 3, red, green, blue);
    glad_glSecondaryColor3ubEXT(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3ubEXT", (GLADapiproc) glad_glSecondaryColor3ubEXT, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3UBEXTPROC glad_debug_glSecondaryColor3ubEXT = glad_debug_impl_glSecondaryColor3ubEXT;
PFNGLSECONDARYCOLOR3UBVPROC glad_glSecondaryColor3ubv = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3ubv(const GLubyte * v) {
    _pre_call_gl_callback("glSecondaryColor3ubv", (GLADapiproc) glad_glSecondaryColor3ubv, 1, v);
    glad_glSecondaryColor3ubv(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3ubv", (GLADapiproc) glad_glSecondaryColor3ubv, 1, v);
    
}
PFNGLSECONDARYCOLOR3UBVPROC glad_debug_glSecondaryColor3ubv = glad_debug_impl_glSecondaryColor3ubv;
PFNGLSECONDARYCOLOR3UBVEXTPROC glad_glSecondaryColor3ubvEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3ubvEXT(const GLubyte * v) {
    _pre_call_gl_callback("glSecondaryColor3ubvEXT", (GLADapiproc) glad_glSecondaryColor3ubvEXT, 1, v);
    glad_glSecondaryColor3ubvEXT(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3ubvEXT", (GLADapiproc) glad_glSecondaryColor3ubvEXT, 1, v);
    
}
PFNGLSECONDARYCOLOR3UBVEXTPROC glad_debug_glSecondaryColor3ubvEXT = glad_debug_impl_glSecondaryColor3ubvEXT;
PFNGLSECONDARYCOLOR3UIPROC glad_glSecondaryColor3ui = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) {
    _pre_call_gl_callback("glSecondaryColor3ui", (GLADapiproc) glad_glSecondaryColor3ui, 3, red, green, blue);
    glad_glSecondaryColor3ui(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3ui", (GLADapiproc) glad_glSecondaryColor3ui, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3UIPROC glad_debug_glSecondaryColor3ui = glad_debug_impl_glSecondaryColor3ui;
PFNGLSECONDARYCOLOR3UIEXTPROC glad_glSecondaryColor3uiEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue) {
    _pre_call_gl_callback("glSecondaryColor3uiEXT", (GLADapiproc) glad_glSecondaryColor3uiEXT, 3, red, green, blue);
    glad_glSecondaryColor3uiEXT(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3uiEXT", (GLADapiproc) glad_glSecondaryColor3uiEXT, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3UIEXTPROC glad_debug_glSecondaryColor3uiEXT = glad_debug_impl_glSecondaryColor3uiEXT;
PFNGLSECONDARYCOLOR3UIVPROC glad_glSecondaryColor3uiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3uiv(const GLuint * v) {
    _pre_call_gl_callback("glSecondaryColor3uiv", (GLADapiproc) glad_glSecondaryColor3uiv, 1, v);
    glad_glSecondaryColor3uiv(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3uiv", (GLADapiproc) glad_glSecondaryColor3uiv, 1, v);
    
}
PFNGLSECONDARYCOLOR3UIVPROC glad_debug_glSecondaryColor3uiv = glad_debug_impl_glSecondaryColor3uiv;
PFNGLSECONDARYCOLOR3UIVEXTPROC glad_glSecondaryColor3uivEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3uivEXT(const GLuint * v) {
    _pre_call_gl_callback("glSecondaryColor3uivEXT", (GLADapiproc) glad_glSecondaryColor3uivEXT, 1, v);
    glad_glSecondaryColor3uivEXT(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3uivEXT", (GLADapiproc) glad_glSecondaryColor3uivEXT, 1, v);
    
}
PFNGLSECONDARYCOLOR3UIVEXTPROC glad_debug_glSecondaryColor3uivEXT = glad_debug_impl_glSecondaryColor3uivEXT;
PFNGLSECONDARYCOLOR3USPROC glad_glSecondaryColor3us = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) {
    _pre_call_gl_callback("glSecondaryColor3us", (GLADapiproc) glad_glSecondaryColor3us, 3, red, green, blue);
    glad_glSecondaryColor3us(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3us", (GLADapiproc) glad_glSecondaryColor3us, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3USPROC glad_debug_glSecondaryColor3us = glad_debug_impl_glSecondaryColor3us;
PFNGLSECONDARYCOLOR3USEXTPROC glad_glSecondaryColor3usEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue) {
    _pre_call_gl_callback("glSecondaryColor3usEXT", (GLADapiproc) glad_glSecondaryColor3usEXT, 3, red, green, blue);
    glad_glSecondaryColor3usEXT(red, green, blue);
    _post_call_gl_callback(NULL, "glSecondaryColor3usEXT", (GLADapiproc) glad_glSecondaryColor3usEXT, 3, red, green, blue);
    
}
PFNGLSECONDARYCOLOR3USEXTPROC glad_debug_glSecondaryColor3usEXT = glad_debug_impl_glSecondaryColor3usEXT;
PFNGLSECONDARYCOLOR3USVPROC glad_glSecondaryColor3usv = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3usv(const GLushort * v) {
    _pre_call_gl_callback("glSecondaryColor3usv", (GLADapiproc) glad_glSecondaryColor3usv, 1, v);
    glad_glSecondaryColor3usv(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3usv", (GLADapiproc) glad_glSecondaryColor3usv, 1, v);
    
}
PFNGLSECONDARYCOLOR3USVPROC glad_debug_glSecondaryColor3usv = glad_debug_impl_glSecondaryColor3usv;
PFNGLSECONDARYCOLOR3USVEXTPROC glad_glSecondaryColor3usvEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColor3usvEXT(const GLushort * v) {
    _pre_call_gl_callback("glSecondaryColor3usvEXT", (GLADapiproc) glad_glSecondaryColor3usvEXT, 1, v);
    glad_glSecondaryColor3usvEXT(v);
    _post_call_gl_callback(NULL, "glSecondaryColor3usvEXT", (GLADapiproc) glad_glSecondaryColor3usvEXT, 1, v);
    
}
PFNGLSECONDARYCOLOR3USVEXTPROC glad_debug_glSecondaryColor3usvEXT = glad_debug_impl_glSecondaryColor3usvEXT;
PFNGLSECONDARYCOLORPOINTERPROC glad_glSecondaryColorPointer = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glSecondaryColorPointer", (GLADapiproc) glad_glSecondaryColorPointer, 4, size, type, stride, pointer);
    glad_glSecondaryColorPointer(size, type, stride, pointer);
    _post_call_gl_callback(NULL, "glSecondaryColorPointer", (GLADapiproc) glad_glSecondaryColorPointer, 4, size, type, stride, pointer);
    
}
PFNGLSECONDARYCOLORPOINTERPROC glad_debug_glSecondaryColorPointer = glad_debug_impl_glSecondaryColorPointer;
PFNGLSECONDARYCOLORPOINTEREXTPROC glad_glSecondaryColorPointerEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glSecondaryColorPointerEXT", (GLADapiproc) glad_glSecondaryColorPointerEXT, 4, size, type, stride, pointer);
    glad_glSecondaryColorPointerEXT(size, type, stride, pointer);
    _post_call_gl_callback(NULL, "glSecondaryColorPointerEXT", (GLADapiproc) glad_glSecondaryColorPointerEXT, 4, size, type, stride, pointer);
    
}
PFNGLSECONDARYCOLORPOINTEREXTPROC glad_debug_glSecondaryColorPointerEXT = glad_debug_impl_glSecondaryColorPointerEXT;
PFNGLSELECTBUFFERPROC glad_glSelectBuffer = NULL;
static void GLAD_API_PTR glad_debug_impl_glSelectBuffer(GLsizei size, GLuint * buffer) {
    _pre_call_gl_callback("glSelectBuffer", (GLADapiproc) glad_glSelectBuffer, 2, size, buffer);
    glad_glSelectBuffer(size, buffer);
    _post_call_gl_callback(NULL, "glSelectBuffer", (GLADapiproc) glad_glSelectBuffer, 2, size, buffer);
    
}
PFNGLSELECTBUFFERPROC glad_debug_glSelectBuffer = glad_debug_impl_glSelectBuffer;
PFNGLSEPARABLEFILTER2DPROC glad_glSeparableFilter2D = NULL;
static void GLAD_API_PTR glad_debug_impl_glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * row, const void * column) {
    _pre_call_gl_callback("glSeparableFilter2D", (GLADapiproc) glad_glSeparableFilter2D, 8, target, internalformat, width, height, format, type, row, column);
    glad_glSeparableFilter2D(target, internalformat, width, height, format, type, row, column);
    _post_call_gl_callback(NULL, "glSeparableFilter2D", (GLADapiproc) glad_glSeparableFilter2D, 8, target, internalformat, width, height, format, type, row, column);
    
}
PFNGLSEPARABLEFILTER2DPROC glad_debug_glSeparableFilter2D = glad_debug_impl_glSeparableFilter2D;
PFNGLSHADEMODELPROC glad_glShadeModel = NULL;
static void GLAD_API_PTR glad_debug_impl_glShadeModel(GLenum mode) {
    _pre_call_gl_callback("glShadeModel", (GLADapiproc) glad_glShadeModel, 1, mode);
    glad_glShadeModel(mode);
    _post_call_gl_callback(NULL, "glShadeModel", (GLADapiproc) glad_glShadeModel, 1, mode);
    
}
PFNGLSHADEMODELPROC glad_debug_glShadeModel = glad_debug_impl_glShadeModel;
PFNGLSHADERSOURCEPROC glad_glShaderSource = NULL;
static void GLAD_API_PTR glad_debug_impl_glShaderSource(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length) {
    _pre_call_gl_callback("glShaderSource", (GLADapiproc) glad_glShaderSource, 4, shader, count, string, length);
    glad_glShaderSource(shader, count, string, length);
    _post_call_gl_callback(NULL, "glShaderSource", (GLADapiproc) glad_glShaderSource, 4, shader, count, string, length);
    
}
PFNGLSHADERSOURCEPROC glad_debug_glShaderSource = glad_debug_impl_glShaderSource;
PFNGLSHADERSOURCEARBPROC glad_glShaderSourceARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, const GLcharARB ** string, const GLint * length) {
    _pre_call_gl_callback("glShaderSourceARB", (GLADapiproc) glad_glShaderSourceARB, 4, shaderObj, count, string, length);
    glad_glShaderSourceARB(shaderObj, count, string, length);
    _post_call_gl_callback(NULL, "glShaderSourceARB", (GLADapiproc) glad_glShaderSourceARB, 4, shaderObj, count, string, length);
    
}
PFNGLSHADERSOURCEARBPROC glad_debug_glShaderSourceARB = glad_debug_impl_glShaderSourceARB;
PFNGLSTENCILFUNCPROC glad_glStencilFunc = NULL;
static void GLAD_API_PTR glad_debug_impl_glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    _pre_call_gl_callback("glStencilFunc", (GLADapiproc) glad_glStencilFunc, 3, func, ref, mask);
    glad_glStencilFunc(func, ref, mask);
    _post_call_gl_callback(NULL, "glStencilFunc", (GLADapiproc) glad_glStencilFunc, 3, func, ref, mask);
    
}
PFNGLSTENCILFUNCPROC glad_debug_glStencilFunc = glad_debug_impl_glStencilFunc;
PFNGLSTENCILFUNCSEPARATEPROC glad_glStencilFuncSeparate = NULL;
static void GLAD_API_PTR glad_debug_impl_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
    _pre_call_gl_callback("glStencilFuncSeparate", (GLADapiproc) glad_glStencilFuncSeparate, 4, face, func, ref, mask);
    glad_glStencilFuncSeparate(face, func, ref, mask);
    _post_call_gl_callback(NULL, "glStencilFuncSeparate", (GLADapiproc) glad_glStencilFuncSeparate, 4, face, func, ref, mask);
    
}
PFNGLSTENCILFUNCSEPARATEPROC glad_debug_glStencilFuncSeparate = glad_debug_impl_glStencilFuncSeparate;
PFNGLSTENCILFUNCSEPARATEATIPROC glad_glStencilFuncSeparateATI = NULL;
static void GLAD_API_PTR glad_debug_impl_glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask) {
    _pre_call_gl_callback("glStencilFuncSeparateATI", (GLADapiproc) glad_glStencilFuncSeparateATI, 4, frontfunc, backfunc, ref, mask);
    glad_glStencilFuncSeparateATI(frontfunc, backfunc, ref, mask);
    _post_call_gl_callback(NULL, "glStencilFuncSeparateATI", (GLADapiproc) glad_glStencilFuncSeparateATI, 4, frontfunc, backfunc, ref, mask);
    
}
PFNGLSTENCILFUNCSEPARATEATIPROC glad_debug_glStencilFuncSeparateATI = glad_debug_impl_glStencilFuncSeparateATI;
PFNGLSTENCILMASKPROC glad_glStencilMask = NULL;
static void GLAD_API_PTR glad_debug_impl_glStencilMask(GLuint mask) {
    _pre_call_gl_callback("glStencilMask", (GLADapiproc) glad_glStencilMask, 1, mask);
    glad_glStencilMask(mask);
    _post_call_gl_callback(NULL, "glStencilMask", (GLADapiproc) glad_glStencilMask, 1, mask);
    
}
PFNGLSTENCILMASKPROC glad_debug_glStencilMask = glad_debug_impl_glStencilMask;
PFNGLSTENCILMASKSEPARATEPROC glad_glStencilMaskSeparate = NULL;
static void GLAD_API_PTR glad_debug_impl_glStencilMaskSeparate(GLenum face, GLuint mask) {
    _pre_call_gl_callback("glStencilMaskSeparate", (GLADapiproc) glad_glStencilMaskSeparate, 2, face, mask);
    glad_glStencilMaskSeparate(face, mask);
    _post_call_gl_callback(NULL, "glStencilMaskSeparate", (GLADapiproc) glad_glStencilMaskSeparate, 2, face, mask);
    
}
PFNGLSTENCILMASKSEPARATEPROC glad_debug_glStencilMaskSeparate = glad_debug_impl_glStencilMaskSeparate;
PFNGLSTENCILOPPROC glad_glStencilOp = NULL;
static void GLAD_API_PTR glad_debug_impl_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    _pre_call_gl_callback("glStencilOp", (GLADapiproc) glad_glStencilOp, 3, fail, zfail, zpass);
    glad_glStencilOp(fail, zfail, zpass);
    _post_call_gl_callback(NULL, "glStencilOp", (GLADapiproc) glad_glStencilOp, 3, fail, zfail, zpass);
    
}
PFNGLSTENCILOPPROC glad_debug_glStencilOp = glad_debug_impl_glStencilOp;
PFNGLSTENCILOPSEPARATEPROC glad_glStencilOpSeparate = NULL;
static void GLAD_API_PTR glad_debug_impl_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
    _pre_call_gl_callback("glStencilOpSeparate", (GLADapiproc) glad_glStencilOpSeparate, 4, face, sfail, dpfail, dppass);
    glad_glStencilOpSeparate(face, sfail, dpfail, dppass);
    _post_call_gl_callback(NULL, "glStencilOpSeparate", (GLADapiproc) glad_glStencilOpSeparate, 4, face, sfail, dpfail, dppass);
    
}
PFNGLSTENCILOPSEPARATEPROC glad_debug_glStencilOpSeparate = glad_debug_impl_glStencilOpSeparate;
PFNGLSTENCILOPSEPARATEATIPROC glad_glStencilOpSeparateATI = NULL;
static void GLAD_API_PTR glad_debug_impl_glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
    _pre_call_gl_callback("glStencilOpSeparateATI", (GLADapiproc) glad_glStencilOpSeparateATI, 4, face, sfail, dpfail, dppass);
    glad_glStencilOpSeparateATI(face, sfail, dpfail, dppass);
    _post_call_gl_callback(NULL, "glStencilOpSeparateATI", (GLADapiproc) glad_glStencilOpSeparateATI, 4, face, sfail, dpfail, dppass);
    
}
PFNGLSTENCILOPSEPARATEATIPROC glad_debug_glStencilOpSeparateATI = glad_debug_impl_glStencilOpSeparateATI;
PFNGLTEXCOORD1DPROC glad_glTexCoord1d = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord1d(GLdouble s) {
    _pre_call_gl_callback("glTexCoord1d", (GLADapiproc) glad_glTexCoord1d, 1, s);
    glad_glTexCoord1d(s);
    _post_call_gl_callback(NULL, "glTexCoord1d", (GLADapiproc) glad_glTexCoord1d, 1, s);
    
}
PFNGLTEXCOORD1DPROC glad_debug_glTexCoord1d = glad_debug_impl_glTexCoord1d;
PFNGLTEXCOORD1DVPROC glad_glTexCoord1dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord1dv(const GLdouble * v) {
    _pre_call_gl_callback("glTexCoord1dv", (GLADapiproc) glad_glTexCoord1dv, 1, v);
    glad_glTexCoord1dv(v);
    _post_call_gl_callback(NULL, "glTexCoord1dv", (GLADapiproc) glad_glTexCoord1dv, 1, v);
    
}
PFNGLTEXCOORD1DVPROC glad_debug_glTexCoord1dv = glad_debug_impl_glTexCoord1dv;
PFNGLTEXCOORD1FPROC glad_glTexCoord1f = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord1f(GLfloat s) {
    _pre_call_gl_callback("glTexCoord1f", (GLADapiproc) glad_glTexCoord1f, 1, s);
    glad_glTexCoord1f(s);
    _post_call_gl_callback(NULL, "glTexCoord1f", (GLADapiproc) glad_glTexCoord1f, 1, s);
    
}
PFNGLTEXCOORD1FPROC glad_debug_glTexCoord1f = glad_debug_impl_glTexCoord1f;
PFNGLTEXCOORD1FVPROC glad_glTexCoord1fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord1fv(const GLfloat * v) {
    _pre_call_gl_callback("glTexCoord1fv", (GLADapiproc) glad_glTexCoord1fv, 1, v);
    glad_glTexCoord1fv(v);
    _post_call_gl_callback(NULL, "glTexCoord1fv", (GLADapiproc) glad_glTexCoord1fv, 1, v);
    
}
PFNGLTEXCOORD1FVPROC glad_debug_glTexCoord1fv = glad_debug_impl_glTexCoord1fv;
PFNGLTEXCOORD1IPROC glad_glTexCoord1i = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord1i(GLint s) {
    _pre_call_gl_callback("glTexCoord1i", (GLADapiproc) glad_glTexCoord1i, 1, s);
    glad_glTexCoord1i(s);
    _post_call_gl_callback(NULL, "glTexCoord1i", (GLADapiproc) glad_glTexCoord1i, 1, s);
    
}
PFNGLTEXCOORD1IPROC glad_debug_glTexCoord1i = glad_debug_impl_glTexCoord1i;
PFNGLTEXCOORD1IVPROC glad_glTexCoord1iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord1iv(const GLint * v) {
    _pre_call_gl_callback("glTexCoord1iv", (GLADapiproc) glad_glTexCoord1iv, 1, v);
    glad_glTexCoord1iv(v);
    _post_call_gl_callback(NULL, "glTexCoord1iv", (GLADapiproc) glad_glTexCoord1iv, 1, v);
    
}
PFNGLTEXCOORD1IVPROC glad_debug_glTexCoord1iv = glad_debug_impl_glTexCoord1iv;
PFNGLTEXCOORD1SPROC glad_glTexCoord1s = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord1s(GLshort s) {
    _pre_call_gl_callback("glTexCoord1s", (GLADapiproc) glad_glTexCoord1s, 1, s);
    glad_glTexCoord1s(s);
    _post_call_gl_callback(NULL, "glTexCoord1s", (GLADapiproc) glad_glTexCoord1s, 1, s);
    
}
PFNGLTEXCOORD1SPROC glad_debug_glTexCoord1s = glad_debug_impl_glTexCoord1s;
PFNGLTEXCOORD1SVPROC glad_glTexCoord1sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord1sv(const GLshort * v) {
    _pre_call_gl_callback("glTexCoord1sv", (GLADapiproc) glad_glTexCoord1sv, 1, v);
    glad_glTexCoord1sv(v);
    _post_call_gl_callback(NULL, "glTexCoord1sv", (GLADapiproc) glad_glTexCoord1sv, 1, v);
    
}
PFNGLTEXCOORD1SVPROC glad_debug_glTexCoord1sv = glad_debug_impl_glTexCoord1sv;
PFNGLTEXCOORD2DPROC glad_glTexCoord2d = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord2d(GLdouble s, GLdouble t) {
    _pre_call_gl_callback("glTexCoord2d", (GLADapiproc) glad_glTexCoord2d, 2, s, t);
    glad_glTexCoord2d(s, t);
    _post_call_gl_callback(NULL, "glTexCoord2d", (GLADapiproc) glad_glTexCoord2d, 2, s, t);
    
}
PFNGLTEXCOORD2DPROC glad_debug_glTexCoord2d = glad_debug_impl_glTexCoord2d;
PFNGLTEXCOORD2DVPROC glad_glTexCoord2dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord2dv(const GLdouble * v) {
    _pre_call_gl_callback("glTexCoord2dv", (GLADapiproc) glad_glTexCoord2dv, 1, v);
    glad_glTexCoord2dv(v);
    _post_call_gl_callback(NULL, "glTexCoord2dv", (GLADapiproc) glad_glTexCoord2dv, 1, v);
    
}
PFNGLTEXCOORD2DVPROC glad_debug_glTexCoord2dv = glad_debug_impl_glTexCoord2dv;
PFNGLTEXCOORD2FPROC glad_glTexCoord2f = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord2f(GLfloat s, GLfloat t) {
    _pre_call_gl_callback("glTexCoord2f", (GLADapiproc) glad_glTexCoord2f, 2, s, t);
    glad_glTexCoord2f(s, t);
    _post_call_gl_callback(NULL, "glTexCoord2f", (GLADapiproc) glad_glTexCoord2f, 2, s, t);
    
}
PFNGLTEXCOORD2FPROC glad_debug_glTexCoord2f = glad_debug_impl_glTexCoord2f;
PFNGLTEXCOORD2FVPROC glad_glTexCoord2fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord2fv(const GLfloat * v) {
    _pre_call_gl_callback("glTexCoord2fv", (GLADapiproc) glad_glTexCoord2fv, 1, v);
    glad_glTexCoord2fv(v);
    _post_call_gl_callback(NULL, "glTexCoord2fv", (GLADapiproc) glad_glTexCoord2fv, 1, v);
    
}
PFNGLTEXCOORD2FVPROC glad_debug_glTexCoord2fv = glad_debug_impl_glTexCoord2fv;
PFNGLTEXCOORD2IPROC glad_glTexCoord2i = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord2i(GLint s, GLint t) {
    _pre_call_gl_callback("glTexCoord2i", (GLADapiproc) glad_glTexCoord2i, 2, s, t);
    glad_glTexCoord2i(s, t);
    _post_call_gl_callback(NULL, "glTexCoord2i", (GLADapiproc) glad_glTexCoord2i, 2, s, t);
    
}
PFNGLTEXCOORD2IPROC glad_debug_glTexCoord2i = glad_debug_impl_glTexCoord2i;
PFNGLTEXCOORD2IVPROC glad_glTexCoord2iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord2iv(const GLint * v) {
    _pre_call_gl_callback("glTexCoord2iv", (GLADapiproc) glad_glTexCoord2iv, 1, v);
    glad_glTexCoord2iv(v);
    _post_call_gl_callback(NULL, "glTexCoord2iv", (GLADapiproc) glad_glTexCoord2iv, 1, v);
    
}
PFNGLTEXCOORD2IVPROC glad_debug_glTexCoord2iv = glad_debug_impl_glTexCoord2iv;
PFNGLTEXCOORD2SPROC glad_glTexCoord2s = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord2s(GLshort s, GLshort t) {
    _pre_call_gl_callback("glTexCoord2s", (GLADapiproc) glad_glTexCoord2s, 2, s, t);
    glad_glTexCoord2s(s, t);
    _post_call_gl_callback(NULL, "glTexCoord2s", (GLADapiproc) glad_glTexCoord2s, 2, s, t);
    
}
PFNGLTEXCOORD2SPROC glad_debug_glTexCoord2s = glad_debug_impl_glTexCoord2s;
PFNGLTEXCOORD2SVPROC glad_glTexCoord2sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord2sv(const GLshort * v) {
    _pre_call_gl_callback("glTexCoord2sv", (GLADapiproc) glad_glTexCoord2sv, 1, v);
    glad_glTexCoord2sv(v);
    _post_call_gl_callback(NULL, "glTexCoord2sv", (GLADapiproc) glad_glTexCoord2sv, 1, v);
    
}
PFNGLTEXCOORD2SVPROC glad_debug_glTexCoord2sv = glad_debug_impl_glTexCoord2sv;
PFNGLTEXCOORD3DPROC glad_glTexCoord3d = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
    _pre_call_gl_callback("glTexCoord3d", (GLADapiproc) glad_glTexCoord3d, 3, s, t, r);
    glad_glTexCoord3d(s, t, r);
    _post_call_gl_callback(NULL, "glTexCoord3d", (GLADapiproc) glad_glTexCoord3d, 3, s, t, r);
    
}
PFNGLTEXCOORD3DPROC glad_debug_glTexCoord3d = glad_debug_impl_glTexCoord3d;
PFNGLTEXCOORD3DVPROC glad_glTexCoord3dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord3dv(const GLdouble * v) {
    _pre_call_gl_callback("glTexCoord3dv", (GLADapiproc) glad_glTexCoord3dv, 1, v);
    glad_glTexCoord3dv(v);
    _post_call_gl_callback(NULL, "glTexCoord3dv", (GLADapiproc) glad_glTexCoord3dv, 1, v);
    
}
PFNGLTEXCOORD3DVPROC glad_debug_glTexCoord3dv = glad_debug_impl_glTexCoord3dv;
PFNGLTEXCOORD3FPROC glad_glTexCoord3f = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
    _pre_call_gl_callback("glTexCoord3f", (GLADapiproc) glad_glTexCoord3f, 3, s, t, r);
    glad_glTexCoord3f(s, t, r);
    _post_call_gl_callback(NULL, "glTexCoord3f", (GLADapiproc) glad_glTexCoord3f, 3, s, t, r);
    
}
PFNGLTEXCOORD3FPROC glad_debug_glTexCoord3f = glad_debug_impl_glTexCoord3f;
PFNGLTEXCOORD3FVPROC glad_glTexCoord3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord3fv(const GLfloat * v) {
    _pre_call_gl_callback("glTexCoord3fv", (GLADapiproc) glad_glTexCoord3fv, 1, v);
    glad_glTexCoord3fv(v);
    _post_call_gl_callback(NULL, "glTexCoord3fv", (GLADapiproc) glad_glTexCoord3fv, 1, v);
    
}
PFNGLTEXCOORD3FVPROC glad_debug_glTexCoord3fv = glad_debug_impl_glTexCoord3fv;
PFNGLTEXCOORD3IPROC glad_glTexCoord3i = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord3i(GLint s, GLint t, GLint r) {
    _pre_call_gl_callback("glTexCoord3i", (GLADapiproc) glad_glTexCoord3i, 3, s, t, r);
    glad_glTexCoord3i(s, t, r);
    _post_call_gl_callback(NULL, "glTexCoord3i", (GLADapiproc) glad_glTexCoord3i, 3, s, t, r);
    
}
PFNGLTEXCOORD3IPROC glad_debug_glTexCoord3i = glad_debug_impl_glTexCoord3i;
PFNGLTEXCOORD3IVPROC glad_glTexCoord3iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord3iv(const GLint * v) {
    _pre_call_gl_callback("glTexCoord3iv", (GLADapiproc) glad_glTexCoord3iv, 1, v);
    glad_glTexCoord3iv(v);
    _post_call_gl_callback(NULL, "glTexCoord3iv", (GLADapiproc) glad_glTexCoord3iv, 1, v);
    
}
PFNGLTEXCOORD3IVPROC glad_debug_glTexCoord3iv = glad_debug_impl_glTexCoord3iv;
PFNGLTEXCOORD3SPROC glad_glTexCoord3s = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord3s(GLshort s, GLshort t, GLshort r) {
    _pre_call_gl_callback("glTexCoord3s", (GLADapiproc) glad_glTexCoord3s, 3, s, t, r);
    glad_glTexCoord3s(s, t, r);
    _post_call_gl_callback(NULL, "glTexCoord3s", (GLADapiproc) glad_glTexCoord3s, 3, s, t, r);
    
}
PFNGLTEXCOORD3SPROC glad_debug_glTexCoord3s = glad_debug_impl_glTexCoord3s;
PFNGLTEXCOORD3SVPROC glad_glTexCoord3sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord3sv(const GLshort * v) {
    _pre_call_gl_callback("glTexCoord3sv", (GLADapiproc) glad_glTexCoord3sv, 1, v);
    glad_glTexCoord3sv(v);
    _post_call_gl_callback(NULL, "glTexCoord3sv", (GLADapiproc) glad_glTexCoord3sv, 1, v);
    
}
PFNGLTEXCOORD3SVPROC glad_debug_glTexCoord3sv = glad_debug_impl_glTexCoord3sv;
PFNGLTEXCOORD4DPROC glad_glTexCoord4d = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    _pre_call_gl_callback("glTexCoord4d", (GLADapiproc) glad_glTexCoord4d, 4, s, t, r, q);
    glad_glTexCoord4d(s, t, r, q);
    _post_call_gl_callback(NULL, "glTexCoord4d", (GLADapiproc) glad_glTexCoord4d, 4, s, t, r, q);
    
}
PFNGLTEXCOORD4DPROC glad_debug_glTexCoord4d = glad_debug_impl_glTexCoord4d;
PFNGLTEXCOORD4DVPROC glad_glTexCoord4dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord4dv(const GLdouble * v) {
    _pre_call_gl_callback("glTexCoord4dv", (GLADapiproc) glad_glTexCoord4dv, 1, v);
    glad_glTexCoord4dv(v);
    _post_call_gl_callback(NULL, "glTexCoord4dv", (GLADapiproc) glad_glTexCoord4dv, 1, v);
    
}
PFNGLTEXCOORD4DVPROC glad_debug_glTexCoord4dv = glad_debug_impl_glTexCoord4dv;
PFNGLTEXCOORD4FPROC glad_glTexCoord4f = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    _pre_call_gl_callback("glTexCoord4f", (GLADapiproc) glad_glTexCoord4f, 4, s, t, r, q);
    glad_glTexCoord4f(s, t, r, q);
    _post_call_gl_callback(NULL, "glTexCoord4f", (GLADapiproc) glad_glTexCoord4f, 4, s, t, r, q);
    
}
PFNGLTEXCOORD4FPROC glad_debug_glTexCoord4f = glad_debug_impl_glTexCoord4f;
PFNGLTEXCOORD4FVPROC glad_glTexCoord4fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord4fv(const GLfloat * v) {
    _pre_call_gl_callback("glTexCoord4fv", (GLADapiproc) glad_glTexCoord4fv, 1, v);
    glad_glTexCoord4fv(v);
    _post_call_gl_callback(NULL, "glTexCoord4fv", (GLADapiproc) glad_glTexCoord4fv, 1, v);
    
}
PFNGLTEXCOORD4FVPROC glad_debug_glTexCoord4fv = glad_debug_impl_glTexCoord4fv;
PFNGLTEXCOORD4IPROC glad_glTexCoord4i = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {
    _pre_call_gl_callback("glTexCoord4i", (GLADapiproc) glad_glTexCoord4i, 4, s, t, r, q);
    glad_glTexCoord4i(s, t, r, q);
    _post_call_gl_callback(NULL, "glTexCoord4i", (GLADapiproc) glad_glTexCoord4i, 4, s, t, r, q);
    
}
PFNGLTEXCOORD4IPROC glad_debug_glTexCoord4i = glad_debug_impl_glTexCoord4i;
PFNGLTEXCOORD4IVPROC glad_glTexCoord4iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord4iv(const GLint * v) {
    _pre_call_gl_callback("glTexCoord4iv", (GLADapiproc) glad_glTexCoord4iv, 1, v);
    glad_glTexCoord4iv(v);
    _post_call_gl_callback(NULL, "glTexCoord4iv", (GLADapiproc) glad_glTexCoord4iv, 1, v);
    
}
PFNGLTEXCOORD4IVPROC glad_debug_glTexCoord4iv = glad_debug_impl_glTexCoord4iv;
PFNGLTEXCOORD4SPROC glad_glTexCoord4s = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
    _pre_call_gl_callback("glTexCoord4s", (GLADapiproc) glad_glTexCoord4s, 4, s, t, r, q);
    glad_glTexCoord4s(s, t, r, q);
    _post_call_gl_callback(NULL, "glTexCoord4s", (GLADapiproc) glad_glTexCoord4s, 4, s, t, r, q);
    
}
PFNGLTEXCOORD4SPROC glad_debug_glTexCoord4s = glad_debug_impl_glTexCoord4s;
PFNGLTEXCOORD4SVPROC glad_glTexCoord4sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoord4sv(const GLshort * v) {
    _pre_call_gl_callback("glTexCoord4sv", (GLADapiproc) glad_glTexCoord4sv, 1, v);
    glad_glTexCoord4sv(v);
    _post_call_gl_callback(NULL, "glTexCoord4sv", (GLADapiproc) glad_glTexCoord4sv, 1, v);
    
}
PFNGLTEXCOORD4SVPROC glad_debug_glTexCoord4sv = glad_debug_impl_glTexCoord4sv;
PFNGLTEXCOORDPOINTERPROC glad_glTexCoordPointer = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glTexCoordPointer", (GLADapiproc) glad_glTexCoordPointer, 4, size, type, stride, pointer);
    glad_glTexCoordPointer(size, type, stride, pointer);
    _post_call_gl_callback(NULL, "glTexCoordPointer", (GLADapiproc) glad_glTexCoordPointer, 4, size, type, stride, pointer);
    
}
PFNGLTEXCOORDPOINTERPROC glad_debug_glTexCoordPointer = glad_debug_impl_glTexCoordPointer;
PFNGLTEXCOORDPOINTEREXTPROC glad_glTexCoordPointerEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer) {
    _pre_call_gl_callback("glTexCoordPointerEXT", (GLADapiproc) glad_glTexCoordPointerEXT, 5, size, type, stride, count, pointer);
    glad_glTexCoordPointerEXT(size, type, stride, count, pointer);
    _post_call_gl_callback(NULL, "glTexCoordPointerEXT", (GLADapiproc) glad_glTexCoordPointerEXT, 5, size, type, stride, count, pointer);
    
}
PFNGLTEXCOORDPOINTEREXTPROC glad_debug_glTexCoordPointerEXT = glad_debug_impl_glTexCoordPointerEXT;
PFNGLTEXENVFPROC glad_glTexEnvf = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glTexEnvf", (GLADapiproc) glad_glTexEnvf, 3, target, pname, param);
    glad_glTexEnvf(target, pname, param);
    _post_call_gl_callback(NULL, "glTexEnvf", (GLADapiproc) glad_glTexEnvf, 3, target, pname, param);
    
}
PFNGLTEXENVFPROC glad_debug_glTexEnvf = glad_debug_impl_glTexEnvf;
PFNGLTEXENVFVPROC glad_glTexEnvfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glTexEnvfv", (GLADapiproc) glad_glTexEnvfv, 3, target, pname, params);
    glad_glTexEnvfv(target, pname, params);
    _post_call_gl_callback(NULL, "glTexEnvfv", (GLADapiproc) glad_glTexEnvfv, 3, target, pname, params);
    
}
PFNGLTEXENVFVPROC glad_debug_glTexEnvfv = glad_debug_impl_glTexEnvfv;
PFNGLTEXENVIPROC glad_glTexEnvi = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexEnvi(GLenum target, GLenum pname, GLint param) {
    _pre_call_gl_callback("glTexEnvi", (GLADapiproc) glad_glTexEnvi, 3, target, pname, param);
    glad_glTexEnvi(target, pname, param);
    _post_call_gl_callback(NULL, "glTexEnvi", (GLADapiproc) glad_glTexEnvi, 3, target, pname, param);
    
}
PFNGLTEXENVIPROC glad_debug_glTexEnvi = glad_debug_impl_glTexEnvi;
PFNGLTEXENVIVPROC glad_glTexEnviv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    _pre_call_gl_callback("glTexEnviv", (GLADapiproc) glad_glTexEnviv, 3, target, pname, params);
    glad_glTexEnviv(target, pname, params);
    _post_call_gl_callback(NULL, "glTexEnviv", (GLADapiproc) glad_glTexEnviv, 3, target, pname, params);
    
}
PFNGLTEXENVIVPROC glad_debug_glTexEnviv = glad_debug_impl_glTexEnviv;
PFNGLTEXGENDPROC glad_glTexGend = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexGend(GLenum coord, GLenum pname, GLdouble param) {
    _pre_call_gl_callback("glTexGend", (GLADapiproc) glad_glTexGend, 3, coord, pname, param);
    glad_glTexGend(coord, pname, param);
    _post_call_gl_callback(NULL, "glTexGend", (GLADapiproc) glad_glTexGend, 3, coord, pname, param);
    
}
PFNGLTEXGENDPROC glad_debug_glTexGend = glad_debug_impl_glTexGend;
PFNGLTEXGENDVPROC glad_glTexGendv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexGendv(GLenum coord, GLenum pname, const GLdouble * params) {
    _pre_call_gl_callback("glTexGendv", (GLADapiproc) glad_glTexGendv, 3, coord, pname, params);
    glad_glTexGendv(coord, pname, params);
    _post_call_gl_callback(NULL, "glTexGendv", (GLADapiproc) glad_glTexGendv, 3, coord, pname, params);
    
}
PFNGLTEXGENDVPROC glad_debug_glTexGendv = glad_debug_impl_glTexGendv;
PFNGLTEXGENFPROC glad_glTexGenf = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glTexGenf", (GLADapiproc) glad_glTexGenf, 3, coord, pname, param);
    glad_glTexGenf(coord, pname, param);
    _post_call_gl_callback(NULL, "glTexGenf", (GLADapiproc) glad_glTexGenf, 3, coord, pname, param);
    
}
PFNGLTEXGENFPROC glad_debug_glTexGenf = glad_debug_impl_glTexGenf;
PFNGLTEXGENFVPROC glad_glTexGenfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glTexGenfv", (GLADapiproc) glad_glTexGenfv, 3, coord, pname, params);
    glad_glTexGenfv(coord, pname, params);
    _post_call_gl_callback(NULL, "glTexGenfv", (GLADapiproc) glad_glTexGenfv, 3, coord, pname, params);
    
}
PFNGLTEXGENFVPROC glad_debug_glTexGenfv = glad_debug_impl_glTexGenfv;
PFNGLTEXGENIPROC glad_glTexGeni = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexGeni(GLenum coord, GLenum pname, GLint param) {
    _pre_call_gl_callback("glTexGeni", (GLADapiproc) glad_glTexGeni, 3, coord, pname, param);
    glad_glTexGeni(coord, pname, param);
    _post_call_gl_callback(NULL, "glTexGeni", (GLADapiproc) glad_glTexGeni, 3, coord, pname, param);
    
}
PFNGLTEXGENIPROC glad_debug_glTexGeni = glad_debug_impl_glTexGeni;
PFNGLTEXGENIVPROC glad_glTexGeniv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexGeniv(GLenum coord, GLenum pname, const GLint * params) {
    _pre_call_gl_callback("glTexGeniv", (GLADapiproc) glad_glTexGeniv, 3, coord, pname, params);
    glad_glTexGeniv(coord, pname, params);
    _post_call_gl_callback(NULL, "glTexGeniv", (GLADapiproc) glad_glTexGeniv, 3, coord, pname, params);
    
}
PFNGLTEXGENIVPROC glad_debug_glTexGeniv = glad_debug_impl_glTexGeniv;
PFNGLTEXIMAGE1DPROC glad_glTexImage1D = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels) {
    _pre_call_gl_callback("glTexImage1D", (GLADapiproc) glad_glTexImage1D, 8, target, level, internalformat, width, border, format, type, pixels);
    glad_glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
    _post_call_gl_callback(NULL, "glTexImage1D", (GLADapiproc) glad_glTexImage1D, 8, target, level, internalformat, width, border, format, type, pixels);
    
}
PFNGLTEXIMAGE1DPROC glad_debug_glTexImage1D = glad_debug_impl_glTexImage1D;
PFNGLTEXIMAGE2DPROC glad_glTexImage2D = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) {
    _pre_call_gl_callback("glTexImage2D", (GLADapiproc) glad_glTexImage2D, 9, target, level, internalformat, width, height, border, format, type, pixels);
    glad_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
    _post_call_gl_callback(NULL, "glTexImage2D", (GLADapiproc) glad_glTexImage2D, 9, target, level, internalformat, width, height, border, format, type, pixels);
    
}
PFNGLTEXIMAGE2DPROC glad_debug_glTexImage2D = glad_debug_impl_glTexImage2D;
PFNGLTEXIMAGE3DPROC glad_glTexImage3D = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) {
    _pre_call_gl_callback("glTexImage3D", (GLADapiproc) glad_glTexImage3D, 10, target, level, internalformat, width, height, depth, border, format, type, pixels);
    glad_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
    _post_call_gl_callback(NULL, "glTexImage3D", (GLADapiproc) glad_glTexImage3D, 10, target, level, internalformat, width, height, depth, border, format, type, pixels);
    
}
PFNGLTEXIMAGE3DPROC glad_debug_glTexImage3D = glad_debug_impl_glTexImage3D;
PFNGLTEXIMAGE3DEXTPROC glad_glTexImage3DEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) {
    _pre_call_gl_callback("glTexImage3DEXT", (GLADapiproc) glad_glTexImage3DEXT, 10, target, level, internalformat, width, height, depth, border, format, type, pixels);
    glad_glTexImage3DEXT(target, level, internalformat, width, height, depth, border, format, type, pixels);
    _post_call_gl_callback(NULL, "glTexImage3DEXT", (GLADapiproc) glad_glTexImage3DEXT, 10, target, level, internalformat, width, height, depth, border, format, type, pixels);
    
}
PFNGLTEXIMAGE3DEXTPROC glad_debug_glTexImage3DEXT = glad_debug_impl_glTexImage3DEXT;
PFNGLTEXPARAMETERFPROC glad_glTexParameterf = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    _pre_call_gl_callback("glTexParameterf", (GLADapiproc) glad_glTexParameterf, 3, target, pname, param);
    glad_glTexParameterf(target, pname, param);
    _post_call_gl_callback(NULL, "glTexParameterf", (GLADapiproc) glad_glTexParameterf, 3, target, pname, param);
    
}
PFNGLTEXPARAMETERFPROC glad_debug_glTexParameterf = glad_debug_impl_glTexParameterf;
PFNGLTEXPARAMETERFVPROC glad_glTexParameterfv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    _pre_call_gl_callback("glTexParameterfv", (GLADapiproc) glad_glTexParameterfv, 3, target, pname, params);
    glad_glTexParameterfv(target, pname, params);
    _post_call_gl_callback(NULL, "glTexParameterfv", (GLADapiproc) glad_glTexParameterfv, 3, target, pname, params);
    
}
PFNGLTEXPARAMETERFVPROC glad_debug_glTexParameterfv = glad_debug_impl_glTexParameterfv;
PFNGLTEXPARAMETERIPROC glad_glTexParameteri = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexParameteri(GLenum target, GLenum pname, GLint param) {
    _pre_call_gl_callback("glTexParameteri", (GLADapiproc) glad_glTexParameteri, 3, target, pname, param);
    glad_glTexParameteri(target, pname, param);
    _post_call_gl_callback(NULL, "glTexParameteri", (GLADapiproc) glad_glTexParameteri, 3, target, pname, param);
    
}
PFNGLTEXPARAMETERIPROC glad_debug_glTexParameteri = glad_debug_impl_glTexParameteri;
PFNGLTEXPARAMETERIVPROC glad_glTexParameteriv = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    _pre_call_gl_callback("glTexParameteriv", (GLADapiproc) glad_glTexParameteriv, 3, target, pname, params);
    glad_glTexParameteriv(target, pname, params);
    _post_call_gl_callback(NULL, "glTexParameteriv", (GLADapiproc) glad_glTexParameteriv, 3, target, pname, params);
    
}
PFNGLTEXPARAMETERIVPROC glad_debug_glTexParameteriv = glad_debug_impl_glTexParameteriv;
PFNGLTEXSUBIMAGE1DPROC glad_glTexSubImage1D = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
    _pre_call_gl_callback("glTexSubImage1D", (GLADapiproc) glad_glTexSubImage1D, 7, target, level, xoffset, width, format, type, pixels);
    glad_glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
    _post_call_gl_callback(NULL, "glTexSubImage1D", (GLADapiproc) glad_glTexSubImage1D, 7, target, level, xoffset, width, format, type, pixels);
    
}
PFNGLTEXSUBIMAGE1DPROC glad_debug_glTexSubImage1D = glad_debug_impl_glTexSubImage1D;
PFNGLTEXSUBIMAGE1DEXTPROC glad_glTexSubImage1DEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
    _pre_call_gl_callback("glTexSubImage1DEXT", (GLADapiproc) glad_glTexSubImage1DEXT, 7, target, level, xoffset, width, format, type, pixels);
    glad_glTexSubImage1DEXT(target, level, xoffset, width, format, type, pixels);
    _post_call_gl_callback(NULL, "glTexSubImage1DEXT", (GLADapiproc) glad_glTexSubImage1DEXT, 7, target, level, xoffset, width, format, type, pixels);
    
}
PFNGLTEXSUBIMAGE1DEXTPROC glad_debug_glTexSubImage1DEXT = glad_debug_impl_glTexSubImage1DEXT;
PFNGLTEXSUBIMAGE2DPROC glad_glTexSubImage2D = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
    _pre_call_gl_callback("glTexSubImage2D", (GLADapiproc) glad_glTexSubImage2D, 9, target, level, xoffset, yoffset, width, height, format, type, pixels);
    glad_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
    _post_call_gl_callback(NULL, "glTexSubImage2D", (GLADapiproc) glad_glTexSubImage2D, 9, target, level, xoffset, yoffset, width, height, format, type, pixels);
    
}
PFNGLTEXSUBIMAGE2DPROC glad_debug_glTexSubImage2D = glad_debug_impl_glTexSubImage2D;
PFNGLTEXSUBIMAGE2DEXTPROC glad_glTexSubImage2DEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
    _pre_call_gl_callback("glTexSubImage2DEXT", (GLADapiproc) glad_glTexSubImage2DEXT, 9, target, level, xoffset, yoffset, width, height, format, type, pixels);
    glad_glTexSubImage2DEXT(target, level, xoffset, yoffset, width, height, format, type, pixels);
    _post_call_gl_callback(NULL, "glTexSubImage2DEXT", (GLADapiproc) glad_glTexSubImage2DEXT, 9, target, level, xoffset, yoffset, width, height, format, type, pixels);
    
}
PFNGLTEXSUBIMAGE2DEXTPROC glad_debug_glTexSubImage2DEXT = glad_debug_impl_glTexSubImage2DEXT;
PFNGLTEXSUBIMAGE3DPROC glad_glTexSubImage3D = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
    _pre_call_gl_callback("glTexSubImage3D", (GLADapiproc) glad_glTexSubImage3D, 11, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    glad_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    _post_call_gl_callback(NULL, "glTexSubImage3D", (GLADapiproc) glad_glTexSubImage3D, 11, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    
}
PFNGLTEXSUBIMAGE3DPROC glad_debug_glTexSubImage3D = glad_debug_impl_glTexSubImage3D;
PFNGLTEXSUBIMAGE3DEXTPROC glad_glTexSubImage3DEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
    _pre_call_gl_callback("glTexSubImage3DEXT", (GLADapiproc) glad_glTexSubImage3DEXT, 11, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    glad_glTexSubImage3DEXT(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    _post_call_gl_callback(NULL, "glTexSubImage3DEXT", (GLADapiproc) glad_glTexSubImage3DEXT, 11, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    
}
PFNGLTEXSUBIMAGE3DEXTPROC glad_debug_glTexSubImage3DEXT = glad_debug_impl_glTexSubImage3DEXT;
PFNGLTRACKMATRIXNVPROC glad_glTrackMatrixNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glTrackMatrixNV(GLenum target, GLuint address, GLenum matrix, GLenum transform) {
    _pre_call_gl_callback("glTrackMatrixNV", (GLADapiproc) glad_glTrackMatrixNV, 4, target, address, matrix, transform);
    glad_glTrackMatrixNV(target, address, matrix, transform);
    _post_call_gl_callback(NULL, "glTrackMatrixNV", (GLADapiproc) glad_glTrackMatrixNV, 4, target, address, matrix, transform);
    
}
PFNGLTRACKMATRIXNVPROC glad_debug_glTrackMatrixNV = glad_debug_impl_glTrackMatrixNV;
PFNGLTRANSLATEDPROC glad_glTranslated = NULL;
static void GLAD_API_PTR glad_debug_impl_glTranslated(GLdouble x, GLdouble y, GLdouble z) {
    _pre_call_gl_callback("glTranslated", (GLADapiproc) glad_glTranslated, 3, x, y, z);
    glad_glTranslated(x, y, z);
    _post_call_gl_callback(NULL, "glTranslated", (GLADapiproc) glad_glTranslated, 3, x, y, z);
    
}
PFNGLTRANSLATEDPROC glad_debug_glTranslated = glad_debug_impl_glTranslated;
PFNGLTRANSLATEFPROC glad_glTranslatef = NULL;
static void GLAD_API_PTR glad_debug_impl_glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    _pre_call_gl_callback("glTranslatef", (GLADapiproc) glad_glTranslatef, 3, x, y, z);
    glad_glTranslatef(x, y, z);
    _post_call_gl_callback(NULL, "glTranslatef", (GLADapiproc) glad_glTranslatef, 3, x, y, z);
    
}
PFNGLTRANSLATEFPROC glad_debug_glTranslatef = glad_debug_impl_glTranslatef;
PFNGLUNIFORM1FPROC glad_glUniform1f = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform1f(GLint location, GLfloat v0) {
    _pre_call_gl_callback("glUniform1f", (GLADapiproc) glad_glUniform1f, 2, location, v0);
    glad_glUniform1f(location, v0);
    _post_call_gl_callback(NULL, "glUniform1f", (GLADapiproc) glad_glUniform1f, 2, location, v0);
    
}
PFNGLUNIFORM1FPROC glad_debug_glUniform1f = glad_debug_impl_glUniform1f;
PFNGLUNIFORM1FARBPROC glad_glUniform1fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform1fARB(GLint location, GLfloat v0) {
    _pre_call_gl_callback("glUniform1fARB", (GLADapiproc) glad_glUniform1fARB, 2, location, v0);
    glad_glUniform1fARB(location, v0);
    _post_call_gl_callback(NULL, "glUniform1fARB", (GLADapiproc) glad_glUniform1fARB, 2, location, v0);
    
}
PFNGLUNIFORM1FARBPROC glad_debug_glUniform1fARB = glad_debug_impl_glUniform1fARB;
PFNGLUNIFORM1FVPROC glad_glUniform1fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform1fv(GLint location, GLsizei count, const GLfloat * value) {
    _pre_call_gl_callback("glUniform1fv", (GLADapiproc) glad_glUniform1fv, 3, location, count, value);
    glad_glUniform1fv(location, count, value);
    _post_call_gl_callback(NULL, "glUniform1fv", (GLADapiproc) glad_glUniform1fv, 3, location, count, value);
    
}
PFNGLUNIFORM1FVPROC glad_debug_glUniform1fv = glad_debug_impl_glUniform1fv;
PFNGLUNIFORM1FVARBPROC glad_glUniform1fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform1fvARB(GLint location, GLsizei count, const GLfloat * value) {
    _pre_call_gl_callback("glUniform1fvARB", (GLADapiproc) glad_glUniform1fvARB, 3, location, count, value);
    glad_glUniform1fvARB(location, count, value);
    _post_call_gl_callback(NULL, "glUniform1fvARB", (GLADapiproc) glad_glUniform1fvARB, 3, location, count, value);
    
}
PFNGLUNIFORM1FVARBPROC glad_debug_glUniform1fvARB = glad_debug_impl_glUniform1fvARB;
PFNGLUNIFORM1IPROC glad_glUniform1i = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform1i(GLint location, GLint v0) {
    _pre_call_gl_callback("glUniform1i", (GLADapiproc) glad_glUniform1i, 2, location, v0);
    glad_glUniform1i(location, v0);
    _post_call_gl_callback(NULL, "glUniform1i", (GLADapiproc) glad_glUniform1i, 2, location, v0);
    
}
PFNGLUNIFORM1IPROC glad_debug_glUniform1i = glad_debug_impl_glUniform1i;
PFNGLUNIFORM1IARBPROC glad_glUniform1iARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform1iARB(GLint location, GLint v0) {
    _pre_call_gl_callback("glUniform1iARB", (GLADapiproc) glad_glUniform1iARB, 2, location, v0);
    glad_glUniform1iARB(location, v0);
    _post_call_gl_callback(NULL, "glUniform1iARB", (GLADapiproc) glad_glUniform1iARB, 2, location, v0);
    
}
PFNGLUNIFORM1IARBPROC glad_debug_glUniform1iARB = glad_debug_impl_glUniform1iARB;
PFNGLUNIFORM1IVPROC glad_glUniform1iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform1iv(GLint location, GLsizei count, const GLint * value) {
    _pre_call_gl_callback("glUniform1iv", (GLADapiproc) glad_glUniform1iv, 3, location, count, value);
    glad_glUniform1iv(location, count, value);
    _post_call_gl_callback(NULL, "glUniform1iv", (GLADapiproc) glad_glUniform1iv, 3, location, count, value);
    
}
PFNGLUNIFORM1IVPROC glad_debug_glUniform1iv = glad_debug_impl_glUniform1iv;
PFNGLUNIFORM1IVARBPROC glad_glUniform1ivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform1ivARB(GLint location, GLsizei count, const GLint * value) {
    _pre_call_gl_callback("glUniform1ivARB", (GLADapiproc) glad_glUniform1ivARB, 3, location, count, value);
    glad_glUniform1ivARB(location, count, value);
    _post_call_gl_callback(NULL, "glUniform1ivARB", (GLADapiproc) glad_glUniform1ivARB, 3, location, count, value);
    
}
PFNGLUNIFORM1IVARBPROC glad_debug_glUniform1ivARB = glad_debug_impl_glUniform1ivARB;
PFNGLUNIFORM2FPROC glad_glUniform2f = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
    _pre_call_gl_callback("glUniform2f", (GLADapiproc) glad_glUniform2f, 3, location, v0, v1);
    glad_glUniform2f(location, v0, v1);
    _post_call_gl_callback(NULL, "glUniform2f", (GLADapiproc) glad_glUniform2f, 3, location, v0, v1);
    
}
PFNGLUNIFORM2FPROC glad_debug_glUniform2f = glad_debug_impl_glUniform2f;
PFNGLUNIFORM2FARBPROC glad_glUniform2fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform2fARB(GLint location, GLfloat v0, GLfloat v1) {
    _pre_call_gl_callback("glUniform2fARB", (GLADapiproc) glad_glUniform2fARB, 3, location, v0, v1);
    glad_glUniform2fARB(location, v0, v1);
    _post_call_gl_callback(NULL, "glUniform2fARB", (GLADapiproc) glad_glUniform2fARB, 3, location, v0, v1);
    
}
PFNGLUNIFORM2FARBPROC glad_debug_glUniform2fARB = glad_debug_impl_glUniform2fARB;
PFNGLUNIFORM2FVPROC glad_glUniform2fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform2fv(GLint location, GLsizei count, const GLfloat * value) {
    _pre_call_gl_callback("glUniform2fv", (GLADapiproc) glad_glUniform2fv, 3, location, count, value);
    glad_glUniform2fv(location, count, value);
    _post_call_gl_callback(NULL, "glUniform2fv", (GLADapiproc) glad_glUniform2fv, 3, location, count, value);
    
}
PFNGLUNIFORM2FVPROC glad_debug_glUniform2fv = glad_debug_impl_glUniform2fv;
PFNGLUNIFORM2FVARBPROC glad_glUniform2fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform2fvARB(GLint location, GLsizei count, const GLfloat * value) {
    _pre_call_gl_callback("glUniform2fvARB", (GLADapiproc) glad_glUniform2fvARB, 3, location, count, value);
    glad_glUniform2fvARB(location, count, value);
    _post_call_gl_callback(NULL, "glUniform2fvARB", (GLADapiproc) glad_glUniform2fvARB, 3, location, count, value);
    
}
PFNGLUNIFORM2FVARBPROC glad_debug_glUniform2fvARB = glad_debug_impl_glUniform2fvARB;
PFNGLUNIFORM2IPROC glad_glUniform2i = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform2i(GLint location, GLint v0, GLint v1) {
    _pre_call_gl_callback("glUniform2i", (GLADapiproc) glad_glUniform2i, 3, location, v0, v1);
    glad_glUniform2i(location, v0, v1);
    _post_call_gl_callback(NULL, "glUniform2i", (GLADapiproc) glad_glUniform2i, 3, location, v0, v1);
    
}
PFNGLUNIFORM2IPROC glad_debug_glUniform2i = glad_debug_impl_glUniform2i;
PFNGLUNIFORM2IARBPROC glad_glUniform2iARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform2iARB(GLint location, GLint v0, GLint v1) {
    _pre_call_gl_callback("glUniform2iARB", (GLADapiproc) glad_glUniform2iARB, 3, location, v0, v1);
    glad_glUniform2iARB(location, v0, v1);
    _post_call_gl_callback(NULL, "glUniform2iARB", (GLADapiproc) glad_glUniform2iARB, 3, location, v0, v1);
    
}
PFNGLUNIFORM2IARBPROC glad_debug_glUniform2iARB = glad_debug_impl_glUniform2iARB;
PFNGLUNIFORM2IVPROC glad_glUniform2iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform2iv(GLint location, GLsizei count, const GLint * value) {
    _pre_call_gl_callback("glUniform2iv", (GLADapiproc) glad_glUniform2iv, 3, location, count, value);
    glad_glUniform2iv(location, count, value);
    _post_call_gl_callback(NULL, "glUniform2iv", (GLADapiproc) glad_glUniform2iv, 3, location, count, value);
    
}
PFNGLUNIFORM2IVPROC glad_debug_glUniform2iv = glad_debug_impl_glUniform2iv;
PFNGLUNIFORM2IVARBPROC glad_glUniform2ivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform2ivARB(GLint location, GLsizei count, const GLint * value) {
    _pre_call_gl_callback("glUniform2ivARB", (GLADapiproc) glad_glUniform2ivARB, 3, location, count, value);
    glad_glUniform2ivARB(location, count, value);
    _post_call_gl_callback(NULL, "glUniform2ivARB", (GLADapiproc) glad_glUniform2ivARB, 3, location, count, value);
    
}
PFNGLUNIFORM2IVARBPROC glad_debug_glUniform2ivARB = glad_debug_impl_glUniform2ivARB;
PFNGLUNIFORM3FPROC glad_glUniform3f = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    _pre_call_gl_callback("glUniform3f", (GLADapiproc) glad_glUniform3f, 4, location, v0, v1, v2);
    glad_glUniform3f(location, v0, v1, v2);
    _post_call_gl_callback(NULL, "glUniform3f", (GLADapiproc) glad_glUniform3f, 4, location, v0, v1, v2);
    
}
PFNGLUNIFORM3FPROC glad_debug_glUniform3f = glad_debug_impl_glUniform3f;
PFNGLUNIFORM3FARBPROC glad_glUniform3fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    _pre_call_gl_callback("glUniform3fARB", (GLADapiproc) glad_glUniform3fARB, 4, location, v0, v1, v2);
    glad_glUniform3fARB(location, v0, v1, v2);
    _post_call_gl_callback(NULL, "glUniform3fARB", (GLADapiproc) glad_glUniform3fARB, 4, location, v0, v1, v2);
    
}
PFNGLUNIFORM3FARBPROC glad_debug_glUniform3fARB = glad_debug_impl_glUniform3fARB;
PFNGLUNIFORM3FVPROC glad_glUniform3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform3fv(GLint location, GLsizei count, const GLfloat * value) {
    _pre_call_gl_callback("glUniform3fv", (GLADapiproc) glad_glUniform3fv, 3, location, count, value);
    glad_glUniform3fv(location, count, value);
    _post_call_gl_callback(NULL, "glUniform3fv", (GLADapiproc) glad_glUniform3fv, 3, location, count, value);
    
}
PFNGLUNIFORM3FVPROC glad_debug_glUniform3fv = glad_debug_impl_glUniform3fv;
PFNGLUNIFORM3FVARBPROC glad_glUniform3fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform3fvARB(GLint location, GLsizei count, const GLfloat * value) {
    _pre_call_gl_callback("glUniform3fvARB", (GLADapiproc) glad_glUniform3fvARB, 3, location, count, value);
    glad_glUniform3fvARB(location, count, value);
    _post_call_gl_callback(NULL, "glUniform3fvARB", (GLADapiproc) glad_glUniform3fvARB, 3, location, count, value);
    
}
PFNGLUNIFORM3FVARBPROC glad_debug_glUniform3fvARB = glad_debug_impl_glUniform3fvARB;
PFNGLUNIFORM3IPROC glad_glUniform3i = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    _pre_call_gl_callback("glUniform3i", (GLADapiproc) glad_glUniform3i, 4, location, v0, v1, v2);
    glad_glUniform3i(location, v0, v1, v2);
    _post_call_gl_callback(NULL, "glUniform3i", (GLADapiproc) glad_glUniform3i, 4, location, v0, v1, v2);
    
}
PFNGLUNIFORM3IPROC glad_debug_glUniform3i = glad_debug_impl_glUniform3i;
PFNGLUNIFORM3IARBPROC glad_glUniform3iARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2) {
    _pre_call_gl_callback("glUniform3iARB", (GLADapiproc) glad_glUniform3iARB, 4, location, v0, v1, v2);
    glad_glUniform3iARB(location, v0, v1, v2);
    _post_call_gl_callback(NULL, "glUniform3iARB", (GLADapiproc) glad_glUniform3iARB, 4, location, v0, v1, v2);
    
}
PFNGLUNIFORM3IARBPROC glad_debug_glUniform3iARB = glad_debug_impl_glUniform3iARB;
PFNGLUNIFORM3IVPROC glad_glUniform3iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform3iv(GLint location, GLsizei count, const GLint * value) {
    _pre_call_gl_callback("glUniform3iv", (GLADapiproc) glad_glUniform3iv, 3, location, count, value);
    glad_glUniform3iv(location, count, value);
    _post_call_gl_callback(NULL, "glUniform3iv", (GLADapiproc) glad_glUniform3iv, 3, location, count, value);
    
}
PFNGLUNIFORM3IVPROC glad_debug_glUniform3iv = glad_debug_impl_glUniform3iv;
PFNGLUNIFORM3IVARBPROC glad_glUniform3ivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform3ivARB(GLint location, GLsizei count, const GLint * value) {
    _pre_call_gl_callback("glUniform3ivARB", (GLADapiproc) glad_glUniform3ivARB, 3, location, count, value);
    glad_glUniform3ivARB(location, count, value);
    _post_call_gl_callback(NULL, "glUniform3ivARB", (GLADapiproc) glad_glUniform3ivARB, 3, location, count, value);
    
}
PFNGLUNIFORM3IVARBPROC glad_debug_glUniform3ivARB = glad_debug_impl_glUniform3ivARB;
PFNGLUNIFORM4FPROC glad_glUniform4f = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    _pre_call_gl_callback("glUniform4f", (GLADapiproc) glad_glUniform4f, 5, location, v0, v1, v2, v3);
    glad_glUniform4f(location, v0, v1, v2, v3);
    _post_call_gl_callback(NULL, "glUniform4f", (GLADapiproc) glad_glUniform4f, 5, location, v0, v1, v2, v3);
    
}
PFNGLUNIFORM4FPROC glad_debug_glUniform4f = glad_debug_impl_glUniform4f;
PFNGLUNIFORM4FARBPROC glad_glUniform4fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    _pre_call_gl_callback("glUniform4fARB", (GLADapiproc) glad_glUniform4fARB, 5, location, v0, v1, v2, v3);
    glad_glUniform4fARB(location, v0, v1, v2, v3);
    _post_call_gl_callback(NULL, "glUniform4fARB", (GLADapiproc) glad_glUniform4fARB, 5, location, v0, v1, v2, v3);
    
}
PFNGLUNIFORM4FARBPROC glad_debug_glUniform4fARB = glad_debug_impl_glUniform4fARB;
PFNGLUNIFORM4FVPROC glad_glUniform4fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform4fv(GLint location, GLsizei count, const GLfloat * value) {
    _pre_call_gl_callback("glUniform4fv", (GLADapiproc) glad_glUniform4fv, 3, location, count, value);
    glad_glUniform4fv(location, count, value);
    _post_call_gl_callback(NULL, "glUniform4fv", (GLADapiproc) glad_glUniform4fv, 3, location, count, value);
    
}
PFNGLUNIFORM4FVPROC glad_debug_glUniform4fv = glad_debug_impl_glUniform4fv;
PFNGLUNIFORM4FVARBPROC glad_glUniform4fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform4fvARB(GLint location, GLsizei count, const GLfloat * value) {
    _pre_call_gl_callback("glUniform4fvARB", (GLADapiproc) glad_glUniform4fvARB, 3, location, count, value);
    glad_glUniform4fvARB(location, count, value);
    _post_call_gl_callback(NULL, "glUniform4fvARB", (GLADapiproc) glad_glUniform4fvARB, 3, location, count, value);
    
}
PFNGLUNIFORM4FVARBPROC glad_debug_glUniform4fvARB = glad_debug_impl_glUniform4fvARB;
PFNGLUNIFORM4IPROC glad_glUniform4i = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    _pre_call_gl_callback("glUniform4i", (GLADapiproc) glad_glUniform4i, 5, location, v0, v1, v2, v3);
    glad_glUniform4i(location, v0, v1, v2, v3);
    _post_call_gl_callback(NULL, "glUniform4i", (GLADapiproc) glad_glUniform4i, 5, location, v0, v1, v2, v3);
    
}
PFNGLUNIFORM4IPROC glad_debug_glUniform4i = glad_debug_impl_glUniform4i;
PFNGLUNIFORM4IARBPROC glad_glUniform4iARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    _pre_call_gl_callback("glUniform4iARB", (GLADapiproc) glad_glUniform4iARB, 5, location, v0, v1, v2, v3);
    glad_glUniform4iARB(location, v0, v1, v2, v3);
    _post_call_gl_callback(NULL, "glUniform4iARB", (GLADapiproc) glad_glUniform4iARB, 5, location, v0, v1, v2, v3);
    
}
PFNGLUNIFORM4IARBPROC glad_debug_glUniform4iARB = glad_debug_impl_glUniform4iARB;
PFNGLUNIFORM4IVPROC glad_glUniform4iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform4iv(GLint location, GLsizei count, const GLint * value) {
    _pre_call_gl_callback("glUniform4iv", (GLADapiproc) glad_glUniform4iv, 3, location, count, value);
    glad_glUniform4iv(location, count, value);
    _post_call_gl_callback(NULL, "glUniform4iv", (GLADapiproc) glad_glUniform4iv, 3, location, count, value);
    
}
PFNGLUNIFORM4IVPROC glad_debug_glUniform4iv = glad_debug_impl_glUniform4iv;
PFNGLUNIFORM4IVARBPROC glad_glUniform4ivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniform4ivARB(GLint location, GLsizei count, const GLint * value) {
    _pre_call_gl_callback("glUniform4ivARB", (GLADapiproc) glad_glUniform4ivARB, 3, location, count, value);
    glad_glUniform4ivARB(location, count, value);
    _post_call_gl_callback(NULL, "glUniform4ivARB", (GLADapiproc) glad_glUniform4ivARB, 3, location, count, value);
    
}
PFNGLUNIFORM4IVARBPROC glad_debug_glUniform4ivARB = glad_debug_impl_glUniform4ivARB;
PFNGLUNIFORMMATRIX2FVPROC glad_glUniformMatrix2fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    _pre_call_gl_callback("glUniformMatrix2fv", (GLADapiproc) glad_glUniformMatrix2fv, 4, location, count, transpose, value);
    glad_glUniformMatrix2fv(location, count, transpose, value);
    _post_call_gl_callback(NULL, "glUniformMatrix2fv", (GLADapiproc) glad_glUniformMatrix2fv, 4, location, count, transpose, value);
    
}
PFNGLUNIFORMMATRIX2FVPROC glad_debug_glUniformMatrix2fv = glad_debug_impl_glUniformMatrix2fv;
PFNGLUNIFORMMATRIX2FVARBPROC glad_glUniformMatrix2fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    _pre_call_gl_callback("glUniformMatrix2fvARB", (GLADapiproc) glad_glUniformMatrix2fvARB, 4, location, count, transpose, value);
    glad_glUniformMatrix2fvARB(location, count, transpose, value);
    _post_call_gl_callback(NULL, "glUniformMatrix2fvARB", (GLADapiproc) glad_glUniformMatrix2fvARB, 4, location, count, transpose, value);
    
}
PFNGLUNIFORMMATRIX2FVARBPROC glad_debug_glUniformMatrix2fvARB = glad_debug_impl_glUniformMatrix2fvARB;
PFNGLUNIFORMMATRIX2X3FVPROC glad_glUniformMatrix2x3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    _pre_call_gl_callback("glUniformMatrix2x3fv", (GLADapiproc) glad_glUniformMatrix2x3fv, 4, location, count, transpose, value);
    glad_glUniformMatrix2x3fv(location, count, transpose, value);
    _post_call_gl_callback(NULL, "glUniformMatrix2x3fv", (GLADapiproc) glad_glUniformMatrix2x3fv, 4, location, count, transpose, value);
    
}
PFNGLUNIFORMMATRIX2X3FVPROC glad_debug_glUniformMatrix2x3fv = glad_debug_impl_glUniformMatrix2x3fv;
PFNGLUNIFORMMATRIX2X4FVPROC glad_glUniformMatrix2x4fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    _pre_call_gl_callback("glUniformMatrix2x4fv", (GLADapiproc) glad_glUniformMatrix2x4fv, 4, location, count, transpose, value);
    glad_glUniformMatrix2x4fv(location, count, transpose, value);
    _post_call_gl_callback(NULL, "glUniformMatrix2x4fv", (GLADapiproc) glad_glUniformMatrix2x4fv, 4, location, count, transpose, value);
    
}
PFNGLUNIFORMMATRIX2X4FVPROC glad_debug_glUniformMatrix2x4fv = glad_debug_impl_glUniformMatrix2x4fv;
PFNGLUNIFORMMATRIX3FVPROC glad_glUniformMatrix3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    _pre_call_gl_callback("glUniformMatrix3fv", (GLADapiproc) glad_glUniformMatrix3fv, 4, location, count, transpose, value);
    glad_glUniformMatrix3fv(location, count, transpose, value);
    _post_call_gl_callback(NULL, "glUniformMatrix3fv", (GLADapiproc) glad_glUniformMatrix3fv, 4, location, count, transpose, value);
    
}
PFNGLUNIFORMMATRIX3FVPROC glad_debug_glUniformMatrix3fv = glad_debug_impl_glUniformMatrix3fv;
PFNGLUNIFORMMATRIX3FVARBPROC glad_glUniformMatrix3fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    _pre_call_gl_callback("glUniformMatrix3fvARB", (GLADapiproc) glad_glUniformMatrix3fvARB, 4, location, count, transpose, value);
    glad_glUniformMatrix3fvARB(location, count, transpose, value);
    _post_call_gl_callback(NULL, "glUniformMatrix3fvARB", (GLADapiproc) glad_glUniformMatrix3fvARB, 4, location, count, transpose, value);
    
}
PFNGLUNIFORMMATRIX3FVARBPROC glad_debug_glUniformMatrix3fvARB = glad_debug_impl_glUniformMatrix3fvARB;
PFNGLUNIFORMMATRIX3X2FVPROC glad_glUniformMatrix3x2fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    _pre_call_gl_callback("glUniformMatrix3x2fv", (GLADapiproc) glad_glUniformMatrix3x2fv, 4, location, count, transpose, value);
    glad_glUniformMatrix3x2fv(location, count, transpose, value);
    _post_call_gl_callback(NULL, "glUniformMatrix3x2fv", (GLADapiproc) glad_glUniformMatrix3x2fv, 4, location, count, transpose, value);
    
}
PFNGLUNIFORMMATRIX3X2FVPROC glad_debug_glUniformMatrix3x2fv = glad_debug_impl_glUniformMatrix3x2fv;
PFNGLUNIFORMMATRIX3X4FVPROC glad_glUniformMatrix3x4fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    _pre_call_gl_callback("glUniformMatrix3x4fv", (GLADapiproc) glad_glUniformMatrix3x4fv, 4, location, count, transpose, value);
    glad_glUniformMatrix3x4fv(location, count, transpose, value);
    _post_call_gl_callback(NULL, "glUniformMatrix3x4fv", (GLADapiproc) glad_glUniformMatrix3x4fv, 4, location, count, transpose, value);
    
}
PFNGLUNIFORMMATRIX3X4FVPROC glad_debug_glUniformMatrix3x4fv = glad_debug_impl_glUniformMatrix3x4fv;
PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    _pre_call_gl_callback("glUniformMatrix4fv", (GLADapiproc) glad_glUniformMatrix4fv, 4, location, count, transpose, value);
    glad_glUniformMatrix4fv(location, count, transpose, value);
    _post_call_gl_callback(NULL, "glUniformMatrix4fv", (GLADapiproc) glad_glUniformMatrix4fv, 4, location, count, transpose, value);
    
}
PFNGLUNIFORMMATRIX4FVPROC glad_debug_glUniformMatrix4fv = glad_debug_impl_glUniformMatrix4fv;
PFNGLUNIFORMMATRIX4FVARBPROC glad_glUniformMatrix4fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    _pre_call_gl_callback("glUniformMatrix4fvARB", (GLADapiproc) glad_glUniformMatrix4fvARB, 4, location, count, transpose, value);
    glad_glUniformMatrix4fvARB(location, count, transpose, value);
    _post_call_gl_callback(NULL, "glUniformMatrix4fvARB", (GLADapiproc) glad_glUniformMatrix4fvARB, 4, location, count, transpose, value);
    
}
PFNGLUNIFORMMATRIX4FVARBPROC glad_debug_glUniformMatrix4fvARB = glad_debug_impl_glUniformMatrix4fvARB;
PFNGLUNIFORMMATRIX4X2FVPROC glad_glUniformMatrix4x2fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    _pre_call_gl_callback("glUniformMatrix4x2fv", (GLADapiproc) glad_glUniformMatrix4x2fv, 4, location, count, transpose, value);
    glad_glUniformMatrix4x2fv(location, count, transpose, value);
    _post_call_gl_callback(NULL, "glUniformMatrix4x2fv", (GLADapiproc) glad_glUniformMatrix4x2fv, 4, location, count, transpose, value);
    
}
PFNGLUNIFORMMATRIX4X2FVPROC glad_debug_glUniformMatrix4x2fv = glad_debug_impl_glUniformMatrix4x2fv;
PFNGLUNIFORMMATRIX4X3FVPROC glad_glUniformMatrix4x3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    _pre_call_gl_callback("glUniformMatrix4x3fv", (GLADapiproc) glad_glUniformMatrix4x3fv, 4, location, count, transpose, value);
    glad_glUniformMatrix4x3fv(location, count, transpose, value);
    _post_call_gl_callback(NULL, "glUniformMatrix4x3fv", (GLADapiproc) glad_glUniformMatrix4x3fv, 4, location, count, transpose, value);
    
}
PFNGLUNIFORMMATRIX4X3FVPROC glad_debug_glUniformMatrix4x3fv = glad_debug_impl_glUniformMatrix4x3fv;
PFNGLUNMAPBUFFERPROC glad_glUnmapBuffer = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glUnmapBuffer(GLenum target) {
    GLboolean ret;
    _pre_call_gl_callback("glUnmapBuffer", (GLADapiproc) glad_glUnmapBuffer, 1, target);
    ret = glad_glUnmapBuffer(target);
    _post_call_gl_callback((void*) &ret, "glUnmapBuffer", (GLADapiproc) glad_glUnmapBuffer, 1, target);
    return ret;
}
PFNGLUNMAPBUFFERPROC glad_debug_glUnmapBuffer = glad_debug_impl_glUnmapBuffer;
PFNGLUNMAPBUFFERARBPROC glad_glUnmapBufferARB = NULL;
static GLboolean GLAD_API_PTR glad_debug_impl_glUnmapBufferARB(GLenum target) {
    GLboolean ret;
    _pre_call_gl_callback("glUnmapBufferARB", (GLADapiproc) glad_glUnmapBufferARB, 1, target);
    ret = glad_glUnmapBufferARB(target);
    _post_call_gl_callback((void*) &ret, "glUnmapBufferARB", (GLADapiproc) glad_glUnmapBufferARB, 1, target);
    return ret;
}
PFNGLUNMAPBUFFERARBPROC glad_debug_glUnmapBufferARB = glad_debug_impl_glUnmapBufferARB;
PFNGLUSEPROGRAMPROC glad_glUseProgram = NULL;
static void GLAD_API_PTR glad_debug_impl_glUseProgram(GLuint program) {
    _pre_call_gl_callback("glUseProgram", (GLADapiproc) glad_glUseProgram, 1, program);
    glad_glUseProgram(program);
    _post_call_gl_callback(NULL, "glUseProgram", (GLADapiproc) glad_glUseProgram, 1, program);
    
}
PFNGLUSEPROGRAMPROC glad_debug_glUseProgram = glad_debug_impl_glUseProgram;
PFNGLUSEPROGRAMOBJECTARBPROC glad_glUseProgramObjectARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glUseProgramObjectARB(GLhandleARB programObj) {
    _pre_call_gl_callback("glUseProgramObjectARB", (GLADapiproc) glad_glUseProgramObjectARB, 1, programObj);
    glad_glUseProgramObjectARB(programObj);
    _post_call_gl_callback(NULL, "glUseProgramObjectARB", (GLADapiproc) glad_glUseProgramObjectARB, 1, programObj);
    
}
PFNGLUSEPROGRAMOBJECTARBPROC glad_debug_glUseProgramObjectARB = glad_debug_impl_glUseProgramObjectARB;
PFNGLVALIDATEPROGRAMPROC glad_glValidateProgram = NULL;
static void GLAD_API_PTR glad_debug_impl_glValidateProgram(GLuint program) {
    _pre_call_gl_callback("glValidateProgram", (GLADapiproc) glad_glValidateProgram, 1, program);
    glad_glValidateProgram(program);
    _post_call_gl_callback(NULL, "glValidateProgram", (GLADapiproc) glad_glValidateProgram, 1, program);
    
}
PFNGLVALIDATEPROGRAMPROC glad_debug_glValidateProgram = glad_debug_impl_glValidateProgram;
PFNGLVALIDATEPROGRAMARBPROC glad_glValidateProgramARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glValidateProgramARB(GLhandleARB programObj) {
    _pre_call_gl_callback("glValidateProgramARB", (GLADapiproc) glad_glValidateProgramARB, 1, programObj);
    glad_glValidateProgramARB(programObj);
    _post_call_gl_callback(NULL, "glValidateProgramARB", (GLADapiproc) glad_glValidateProgramARB, 1, programObj);
    
}
PFNGLVALIDATEPROGRAMARBPROC glad_debug_glValidateProgramARB = glad_debug_impl_glValidateProgramARB;
PFNGLVERTEX2DPROC glad_glVertex2d = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex2d(GLdouble x, GLdouble y) {
    _pre_call_gl_callback("glVertex2d", (GLADapiproc) glad_glVertex2d, 2, x, y);
    glad_glVertex2d(x, y);
    _post_call_gl_callback(NULL, "glVertex2d", (GLADapiproc) glad_glVertex2d, 2, x, y);
    
}
PFNGLVERTEX2DPROC glad_debug_glVertex2d = glad_debug_impl_glVertex2d;
PFNGLVERTEX2DVPROC glad_glVertex2dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex2dv(const GLdouble * v) {
    _pre_call_gl_callback("glVertex2dv", (GLADapiproc) glad_glVertex2dv, 1, v);
    glad_glVertex2dv(v);
    _post_call_gl_callback(NULL, "glVertex2dv", (GLADapiproc) glad_glVertex2dv, 1, v);
    
}
PFNGLVERTEX2DVPROC glad_debug_glVertex2dv = glad_debug_impl_glVertex2dv;
PFNGLVERTEX2FPROC glad_glVertex2f = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex2f(GLfloat x, GLfloat y) {
    _pre_call_gl_callback("glVertex2f", (GLADapiproc) glad_glVertex2f, 2, x, y);
    glad_glVertex2f(x, y);
    _post_call_gl_callback(NULL, "glVertex2f", (GLADapiproc) glad_glVertex2f, 2, x, y);
    
}
PFNGLVERTEX2FPROC glad_debug_glVertex2f = glad_debug_impl_glVertex2f;
PFNGLVERTEX2FVPROC glad_glVertex2fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex2fv(const GLfloat * v) {
    _pre_call_gl_callback("glVertex2fv", (GLADapiproc) glad_glVertex2fv, 1, v);
    glad_glVertex2fv(v);
    _post_call_gl_callback(NULL, "glVertex2fv", (GLADapiproc) glad_glVertex2fv, 1, v);
    
}
PFNGLVERTEX2FVPROC glad_debug_glVertex2fv = glad_debug_impl_glVertex2fv;
PFNGLVERTEX2IPROC glad_glVertex2i = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex2i(GLint x, GLint y) {
    _pre_call_gl_callback("glVertex2i", (GLADapiproc) glad_glVertex2i, 2, x, y);
    glad_glVertex2i(x, y);
    _post_call_gl_callback(NULL, "glVertex2i", (GLADapiproc) glad_glVertex2i, 2, x, y);
    
}
PFNGLVERTEX2IPROC glad_debug_glVertex2i = glad_debug_impl_glVertex2i;
PFNGLVERTEX2IVPROC glad_glVertex2iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex2iv(const GLint * v) {
    _pre_call_gl_callback("glVertex2iv", (GLADapiproc) glad_glVertex2iv, 1, v);
    glad_glVertex2iv(v);
    _post_call_gl_callback(NULL, "glVertex2iv", (GLADapiproc) glad_glVertex2iv, 1, v);
    
}
PFNGLVERTEX2IVPROC glad_debug_glVertex2iv = glad_debug_impl_glVertex2iv;
PFNGLVERTEX2SPROC glad_glVertex2s = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex2s(GLshort x, GLshort y) {
    _pre_call_gl_callback("glVertex2s", (GLADapiproc) glad_glVertex2s, 2, x, y);
    glad_glVertex2s(x, y);
    _post_call_gl_callback(NULL, "glVertex2s", (GLADapiproc) glad_glVertex2s, 2, x, y);
    
}
PFNGLVERTEX2SPROC glad_debug_glVertex2s = glad_debug_impl_glVertex2s;
PFNGLVERTEX2SVPROC glad_glVertex2sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex2sv(const GLshort * v) {
    _pre_call_gl_callback("glVertex2sv", (GLADapiproc) glad_glVertex2sv, 1, v);
    glad_glVertex2sv(v);
    _post_call_gl_callback(NULL, "glVertex2sv", (GLADapiproc) glad_glVertex2sv, 1, v);
    
}
PFNGLVERTEX2SVPROC glad_debug_glVertex2sv = glad_debug_impl_glVertex2sv;
PFNGLVERTEX3DPROC glad_glVertex3d = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex3d(GLdouble x, GLdouble y, GLdouble z) {
    _pre_call_gl_callback("glVertex3d", (GLADapiproc) glad_glVertex3d, 3, x, y, z);
    glad_glVertex3d(x, y, z);
    _post_call_gl_callback(NULL, "glVertex3d", (GLADapiproc) glad_glVertex3d, 3, x, y, z);
    
}
PFNGLVERTEX3DPROC glad_debug_glVertex3d = glad_debug_impl_glVertex3d;
PFNGLVERTEX3DVPROC glad_glVertex3dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex3dv(const GLdouble * v) {
    _pre_call_gl_callback("glVertex3dv", (GLADapiproc) glad_glVertex3dv, 1, v);
    glad_glVertex3dv(v);
    _post_call_gl_callback(NULL, "glVertex3dv", (GLADapiproc) glad_glVertex3dv, 1, v);
    
}
PFNGLVERTEX3DVPROC glad_debug_glVertex3dv = glad_debug_impl_glVertex3dv;
PFNGLVERTEX3FPROC glad_glVertex3f = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    _pre_call_gl_callback("glVertex3f", (GLADapiproc) glad_glVertex3f, 3, x, y, z);
    glad_glVertex3f(x, y, z);
    _post_call_gl_callback(NULL, "glVertex3f", (GLADapiproc) glad_glVertex3f, 3, x, y, z);
    
}
PFNGLVERTEX3FPROC glad_debug_glVertex3f = glad_debug_impl_glVertex3f;
PFNGLVERTEX3FVPROC glad_glVertex3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex3fv(const GLfloat * v) {
    _pre_call_gl_callback("glVertex3fv", (GLADapiproc) glad_glVertex3fv, 1, v);
    glad_glVertex3fv(v);
    _post_call_gl_callback(NULL, "glVertex3fv", (GLADapiproc) glad_glVertex3fv, 1, v);
    
}
PFNGLVERTEX3FVPROC glad_debug_glVertex3fv = glad_debug_impl_glVertex3fv;
PFNGLVERTEX3IPROC glad_glVertex3i = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex3i(GLint x, GLint y, GLint z) {
    _pre_call_gl_callback("glVertex3i", (GLADapiproc) glad_glVertex3i, 3, x, y, z);
    glad_glVertex3i(x, y, z);
    _post_call_gl_callback(NULL, "glVertex3i", (GLADapiproc) glad_glVertex3i, 3, x, y, z);
    
}
PFNGLVERTEX3IPROC glad_debug_glVertex3i = glad_debug_impl_glVertex3i;
PFNGLVERTEX3IVPROC glad_glVertex3iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex3iv(const GLint * v) {
    _pre_call_gl_callback("glVertex3iv", (GLADapiproc) glad_glVertex3iv, 1, v);
    glad_glVertex3iv(v);
    _post_call_gl_callback(NULL, "glVertex3iv", (GLADapiproc) glad_glVertex3iv, 1, v);
    
}
PFNGLVERTEX3IVPROC glad_debug_glVertex3iv = glad_debug_impl_glVertex3iv;
PFNGLVERTEX3SPROC glad_glVertex3s = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex3s(GLshort x, GLshort y, GLshort z) {
    _pre_call_gl_callback("glVertex3s", (GLADapiproc) glad_glVertex3s, 3, x, y, z);
    glad_glVertex3s(x, y, z);
    _post_call_gl_callback(NULL, "glVertex3s", (GLADapiproc) glad_glVertex3s, 3, x, y, z);
    
}
PFNGLVERTEX3SPROC glad_debug_glVertex3s = glad_debug_impl_glVertex3s;
PFNGLVERTEX3SVPROC glad_glVertex3sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex3sv(const GLshort * v) {
    _pre_call_gl_callback("glVertex3sv", (GLADapiproc) glad_glVertex3sv, 1, v);
    glad_glVertex3sv(v);
    _post_call_gl_callback(NULL, "glVertex3sv", (GLADapiproc) glad_glVertex3sv, 1, v);
    
}
PFNGLVERTEX3SVPROC glad_debug_glVertex3sv = glad_debug_impl_glVertex3sv;
PFNGLVERTEX4DPROC glad_glVertex4d = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    _pre_call_gl_callback("glVertex4d", (GLADapiproc) glad_glVertex4d, 4, x, y, z, w);
    glad_glVertex4d(x, y, z, w);
    _post_call_gl_callback(NULL, "glVertex4d", (GLADapiproc) glad_glVertex4d, 4, x, y, z, w);
    
}
PFNGLVERTEX4DPROC glad_debug_glVertex4d = glad_debug_impl_glVertex4d;
PFNGLVERTEX4DVPROC glad_glVertex4dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex4dv(const GLdouble * v) {
    _pre_call_gl_callback("glVertex4dv", (GLADapiproc) glad_glVertex4dv, 1, v);
    glad_glVertex4dv(v);
    _post_call_gl_callback(NULL, "glVertex4dv", (GLADapiproc) glad_glVertex4dv, 1, v);
    
}
PFNGLVERTEX4DVPROC glad_debug_glVertex4dv = glad_debug_impl_glVertex4dv;
PFNGLVERTEX4FPROC glad_glVertex4f = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _pre_call_gl_callback("glVertex4f", (GLADapiproc) glad_glVertex4f, 4, x, y, z, w);
    glad_glVertex4f(x, y, z, w);
    _post_call_gl_callback(NULL, "glVertex4f", (GLADapiproc) glad_glVertex4f, 4, x, y, z, w);
    
}
PFNGLVERTEX4FPROC glad_debug_glVertex4f = glad_debug_impl_glVertex4f;
PFNGLVERTEX4FVPROC glad_glVertex4fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex4fv(const GLfloat * v) {
    _pre_call_gl_callback("glVertex4fv", (GLADapiproc) glad_glVertex4fv, 1, v);
    glad_glVertex4fv(v);
    _post_call_gl_callback(NULL, "glVertex4fv", (GLADapiproc) glad_glVertex4fv, 1, v);
    
}
PFNGLVERTEX4FVPROC glad_debug_glVertex4fv = glad_debug_impl_glVertex4fv;
PFNGLVERTEX4IPROC glad_glVertex4i = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex4i(GLint x, GLint y, GLint z, GLint w) {
    _pre_call_gl_callback("glVertex4i", (GLADapiproc) glad_glVertex4i, 4, x, y, z, w);
    glad_glVertex4i(x, y, z, w);
    _post_call_gl_callback(NULL, "glVertex4i", (GLADapiproc) glad_glVertex4i, 4, x, y, z, w);
    
}
PFNGLVERTEX4IPROC glad_debug_glVertex4i = glad_debug_impl_glVertex4i;
PFNGLVERTEX4IVPROC glad_glVertex4iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex4iv(const GLint * v) {
    _pre_call_gl_callback("glVertex4iv", (GLADapiproc) glad_glVertex4iv, 1, v);
    glad_glVertex4iv(v);
    _post_call_gl_callback(NULL, "glVertex4iv", (GLADapiproc) glad_glVertex4iv, 1, v);
    
}
PFNGLVERTEX4IVPROC glad_debug_glVertex4iv = glad_debug_impl_glVertex4iv;
PFNGLVERTEX4SPROC glad_glVertex4s = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    _pre_call_gl_callback("glVertex4s", (GLADapiproc) glad_glVertex4s, 4, x, y, z, w);
    glad_glVertex4s(x, y, z, w);
    _post_call_gl_callback(NULL, "glVertex4s", (GLADapiproc) glad_glVertex4s, 4, x, y, z, w);
    
}
PFNGLVERTEX4SPROC glad_debug_glVertex4s = glad_debug_impl_glVertex4s;
PFNGLVERTEX4SVPROC glad_glVertex4sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertex4sv(const GLshort * v) {
    _pre_call_gl_callback("glVertex4sv", (GLADapiproc) glad_glVertex4sv, 1, v);
    glad_glVertex4sv(v);
    _post_call_gl_callback(NULL, "glVertex4sv", (GLADapiproc) glad_glVertex4sv, 1, v);
    
}
PFNGLVERTEX4SVPROC glad_debug_glVertex4sv = glad_debug_impl_glVertex4sv;
PFNGLVERTEXATTRIB1DPROC glad_glVertexAttrib1d = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1d(GLuint index, GLdouble x) {
    _pre_call_gl_callback("glVertexAttrib1d", (GLADapiproc) glad_glVertexAttrib1d, 2, index, x);
    glad_glVertexAttrib1d(index, x);
    _post_call_gl_callback(NULL, "glVertexAttrib1d", (GLADapiproc) glad_glVertexAttrib1d, 2, index, x);
    
}
PFNGLVERTEXATTRIB1DPROC glad_debug_glVertexAttrib1d = glad_debug_impl_glVertexAttrib1d;
PFNGLVERTEXATTRIB1DARBPROC glad_glVertexAttrib1dARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1dARB(GLuint index, GLdouble x) {
    _pre_call_gl_callback("glVertexAttrib1dARB", (GLADapiproc) glad_glVertexAttrib1dARB, 2, index, x);
    glad_glVertexAttrib1dARB(index, x);
    _post_call_gl_callback(NULL, "glVertexAttrib1dARB", (GLADapiproc) glad_glVertexAttrib1dARB, 2, index, x);
    
}
PFNGLVERTEXATTRIB1DARBPROC glad_debug_glVertexAttrib1dARB = glad_debug_impl_glVertexAttrib1dARB;
PFNGLVERTEXATTRIB1DNVPROC glad_glVertexAttrib1dNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1dNV(GLuint index, GLdouble x) {
    _pre_call_gl_callback("glVertexAttrib1dNV", (GLADapiproc) glad_glVertexAttrib1dNV, 2, index, x);
    glad_glVertexAttrib1dNV(index, x);
    _post_call_gl_callback(NULL, "glVertexAttrib1dNV", (GLADapiproc) glad_glVertexAttrib1dNV, 2, index, x);
    
}
PFNGLVERTEXATTRIB1DNVPROC glad_debug_glVertexAttrib1dNV = glad_debug_impl_glVertexAttrib1dNV;
PFNGLVERTEXATTRIB1DVPROC glad_glVertexAttrib1dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1dv(GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttrib1dv", (GLADapiproc) glad_glVertexAttrib1dv, 2, index, v);
    glad_glVertexAttrib1dv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib1dv", (GLADapiproc) glad_glVertexAttrib1dv, 2, index, v);
    
}
PFNGLVERTEXATTRIB1DVPROC glad_debug_glVertexAttrib1dv = glad_debug_impl_glVertexAttrib1dv;
PFNGLVERTEXATTRIB1DVARBPROC glad_glVertexAttrib1dvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1dvARB(GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttrib1dvARB", (GLADapiproc) glad_glVertexAttrib1dvARB, 2, index, v);
    glad_glVertexAttrib1dvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib1dvARB", (GLADapiproc) glad_glVertexAttrib1dvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB1DVARBPROC glad_debug_glVertexAttrib1dvARB = glad_debug_impl_glVertexAttrib1dvARB;
PFNGLVERTEXATTRIB1DVNVPROC glad_glVertexAttrib1dvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1dvNV(GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttrib1dvNV", (GLADapiproc) glad_glVertexAttrib1dvNV, 2, index, v);
    glad_glVertexAttrib1dvNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib1dvNV", (GLADapiproc) glad_glVertexAttrib1dvNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB1DVNVPROC glad_debug_glVertexAttrib1dvNV = glad_debug_impl_glVertexAttrib1dvNV;
PFNGLVERTEXATTRIB1FPROC glad_glVertexAttrib1f = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1f(GLuint index, GLfloat x) {
    _pre_call_gl_callback("glVertexAttrib1f", (GLADapiproc) glad_glVertexAttrib1f, 2, index, x);
    glad_glVertexAttrib1f(index, x);
    _post_call_gl_callback(NULL, "glVertexAttrib1f", (GLADapiproc) glad_glVertexAttrib1f, 2, index, x);
    
}
PFNGLVERTEXATTRIB1FPROC glad_debug_glVertexAttrib1f = glad_debug_impl_glVertexAttrib1f;
PFNGLVERTEXATTRIB1FARBPROC glad_glVertexAttrib1fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1fARB(GLuint index, GLfloat x) {
    _pre_call_gl_callback("glVertexAttrib1fARB", (GLADapiproc) glad_glVertexAttrib1fARB, 2, index, x);
    glad_glVertexAttrib1fARB(index, x);
    _post_call_gl_callback(NULL, "glVertexAttrib1fARB", (GLADapiproc) glad_glVertexAttrib1fARB, 2, index, x);
    
}
PFNGLVERTEXATTRIB1FARBPROC glad_debug_glVertexAttrib1fARB = glad_debug_impl_glVertexAttrib1fARB;
PFNGLVERTEXATTRIB1FNVPROC glad_glVertexAttrib1fNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1fNV(GLuint index, GLfloat x) {
    _pre_call_gl_callback("glVertexAttrib1fNV", (GLADapiproc) glad_glVertexAttrib1fNV, 2, index, x);
    glad_glVertexAttrib1fNV(index, x);
    _post_call_gl_callback(NULL, "glVertexAttrib1fNV", (GLADapiproc) glad_glVertexAttrib1fNV, 2, index, x);
    
}
PFNGLVERTEXATTRIB1FNVPROC glad_debug_glVertexAttrib1fNV = glad_debug_impl_glVertexAttrib1fNV;
PFNGLVERTEXATTRIB1FVPROC glad_glVertexAttrib1fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1fv(GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttrib1fv", (GLADapiproc) glad_glVertexAttrib1fv, 2, index, v);
    glad_glVertexAttrib1fv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib1fv", (GLADapiproc) glad_glVertexAttrib1fv, 2, index, v);
    
}
PFNGLVERTEXATTRIB1FVPROC glad_debug_glVertexAttrib1fv = glad_debug_impl_glVertexAttrib1fv;
PFNGLVERTEXATTRIB1FVARBPROC glad_glVertexAttrib1fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1fvARB(GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttrib1fvARB", (GLADapiproc) glad_glVertexAttrib1fvARB, 2, index, v);
    glad_glVertexAttrib1fvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib1fvARB", (GLADapiproc) glad_glVertexAttrib1fvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB1FVARBPROC glad_debug_glVertexAttrib1fvARB = glad_debug_impl_glVertexAttrib1fvARB;
PFNGLVERTEXATTRIB1FVNVPROC glad_glVertexAttrib1fvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1fvNV(GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttrib1fvNV", (GLADapiproc) glad_glVertexAttrib1fvNV, 2, index, v);
    glad_glVertexAttrib1fvNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib1fvNV", (GLADapiproc) glad_glVertexAttrib1fvNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB1FVNVPROC glad_debug_glVertexAttrib1fvNV = glad_debug_impl_glVertexAttrib1fvNV;
PFNGLVERTEXATTRIB1SPROC glad_glVertexAttrib1s = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1s(GLuint index, GLshort x) {
    _pre_call_gl_callback("glVertexAttrib1s", (GLADapiproc) glad_glVertexAttrib1s, 2, index, x);
    glad_glVertexAttrib1s(index, x);
    _post_call_gl_callback(NULL, "glVertexAttrib1s", (GLADapiproc) glad_glVertexAttrib1s, 2, index, x);
    
}
PFNGLVERTEXATTRIB1SPROC glad_debug_glVertexAttrib1s = glad_debug_impl_glVertexAttrib1s;
PFNGLVERTEXATTRIB1SARBPROC glad_glVertexAttrib1sARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1sARB(GLuint index, GLshort x) {
    _pre_call_gl_callback("glVertexAttrib1sARB", (GLADapiproc) glad_glVertexAttrib1sARB, 2, index, x);
    glad_glVertexAttrib1sARB(index, x);
    _post_call_gl_callback(NULL, "glVertexAttrib1sARB", (GLADapiproc) glad_glVertexAttrib1sARB, 2, index, x);
    
}
PFNGLVERTEXATTRIB1SARBPROC glad_debug_glVertexAttrib1sARB = glad_debug_impl_glVertexAttrib1sARB;
PFNGLVERTEXATTRIB1SNVPROC glad_glVertexAttrib1sNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1sNV(GLuint index, GLshort x) {
    _pre_call_gl_callback("glVertexAttrib1sNV", (GLADapiproc) glad_glVertexAttrib1sNV, 2, index, x);
    glad_glVertexAttrib1sNV(index, x);
    _post_call_gl_callback(NULL, "glVertexAttrib1sNV", (GLADapiproc) glad_glVertexAttrib1sNV, 2, index, x);
    
}
PFNGLVERTEXATTRIB1SNVPROC glad_debug_glVertexAttrib1sNV = glad_debug_impl_glVertexAttrib1sNV;
PFNGLVERTEXATTRIB1SVPROC glad_glVertexAttrib1sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1sv(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib1sv", (GLADapiproc) glad_glVertexAttrib1sv, 2, index, v);
    glad_glVertexAttrib1sv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib1sv", (GLADapiproc) glad_glVertexAttrib1sv, 2, index, v);
    
}
PFNGLVERTEXATTRIB1SVPROC glad_debug_glVertexAttrib1sv = glad_debug_impl_glVertexAttrib1sv;
PFNGLVERTEXATTRIB1SVARBPROC glad_glVertexAttrib1svARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1svARB(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib1svARB", (GLADapiproc) glad_glVertexAttrib1svARB, 2, index, v);
    glad_glVertexAttrib1svARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib1svARB", (GLADapiproc) glad_glVertexAttrib1svARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB1SVARBPROC glad_debug_glVertexAttrib1svARB = glad_debug_impl_glVertexAttrib1svARB;
PFNGLVERTEXATTRIB1SVNVPROC glad_glVertexAttrib1svNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib1svNV(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib1svNV", (GLADapiproc) glad_glVertexAttrib1svNV, 2, index, v);
    glad_glVertexAttrib1svNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib1svNV", (GLADapiproc) glad_glVertexAttrib1svNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB1SVNVPROC glad_debug_glVertexAttrib1svNV = glad_debug_impl_glVertexAttrib1svNV;
PFNGLVERTEXATTRIB2DPROC glad_glVertexAttrib2d = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) {
    _pre_call_gl_callback("glVertexAttrib2d", (GLADapiproc) glad_glVertexAttrib2d, 3, index, x, y);
    glad_glVertexAttrib2d(index, x, y);
    _post_call_gl_callback(NULL, "glVertexAttrib2d", (GLADapiproc) glad_glVertexAttrib2d, 3, index, x, y);
    
}
PFNGLVERTEXATTRIB2DPROC glad_debug_glVertexAttrib2d = glad_debug_impl_glVertexAttrib2d;
PFNGLVERTEXATTRIB2DARBPROC glad_glVertexAttrib2dARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y) {
    _pre_call_gl_callback("glVertexAttrib2dARB", (GLADapiproc) glad_glVertexAttrib2dARB, 3, index, x, y);
    glad_glVertexAttrib2dARB(index, x, y);
    _post_call_gl_callback(NULL, "glVertexAttrib2dARB", (GLADapiproc) glad_glVertexAttrib2dARB, 3, index, x, y);
    
}
PFNGLVERTEXATTRIB2DARBPROC glad_debug_glVertexAttrib2dARB = glad_debug_impl_glVertexAttrib2dARB;
PFNGLVERTEXATTRIB2DNVPROC glad_glVertexAttrib2dNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2dNV(GLuint index, GLdouble x, GLdouble y) {
    _pre_call_gl_callback("glVertexAttrib2dNV", (GLADapiproc) glad_glVertexAttrib2dNV, 3, index, x, y);
    glad_glVertexAttrib2dNV(index, x, y);
    _post_call_gl_callback(NULL, "glVertexAttrib2dNV", (GLADapiproc) glad_glVertexAttrib2dNV, 3, index, x, y);
    
}
PFNGLVERTEXATTRIB2DNVPROC glad_debug_glVertexAttrib2dNV = glad_debug_impl_glVertexAttrib2dNV;
PFNGLVERTEXATTRIB2DVPROC glad_glVertexAttrib2dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2dv(GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttrib2dv", (GLADapiproc) glad_glVertexAttrib2dv, 2, index, v);
    glad_glVertexAttrib2dv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib2dv", (GLADapiproc) glad_glVertexAttrib2dv, 2, index, v);
    
}
PFNGLVERTEXATTRIB2DVPROC glad_debug_glVertexAttrib2dv = glad_debug_impl_glVertexAttrib2dv;
PFNGLVERTEXATTRIB2DVARBPROC glad_glVertexAttrib2dvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2dvARB(GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttrib2dvARB", (GLADapiproc) glad_glVertexAttrib2dvARB, 2, index, v);
    glad_glVertexAttrib2dvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib2dvARB", (GLADapiproc) glad_glVertexAttrib2dvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB2DVARBPROC glad_debug_glVertexAttrib2dvARB = glad_debug_impl_glVertexAttrib2dvARB;
PFNGLVERTEXATTRIB2DVNVPROC glad_glVertexAttrib2dvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2dvNV(GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttrib2dvNV", (GLADapiproc) glad_glVertexAttrib2dvNV, 2, index, v);
    glad_glVertexAttrib2dvNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib2dvNV", (GLADapiproc) glad_glVertexAttrib2dvNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB2DVNVPROC glad_debug_glVertexAttrib2dvNV = glad_debug_impl_glVertexAttrib2dvNV;
PFNGLVERTEXATTRIB2FPROC glad_glVertexAttrib2f = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
    _pre_call_gl_callback("glVertexAttrib2f", (GLADapiproc) glad_glVertexAttrib2f, 3, index, x, y);
    glad_glVertexAttrib2f(index, x, y);
    _post_call_gl_callback(NULL, "glVertexAttrib2f", (GLADapiproc) glad_glVertexAttrib2f, 3, index, x, y);
    
}
PFNGLVERTEXATTRIB2FPROC glad_debug_glVertexAttrib2f = glad_debug_impl_glVertexAttrib2f;
PFNGLVERTEXATTRIB2FARBPROC glad_glVertexAttrib2fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y) {
    _pre_call_gl_callback("glVertexAttrib2fARB", (GLADapiproc) glad_glVertexAttrib2fARB, 3, index, x, y);
    glad_glVertexAttrib2fARB(index, x, y);
    _post_call_gl_callback(NULL, "glVertexAttrib2fARB", (GLADapiproc) glad_glVertexAttrib2fARB, 3, index, x, y);
    
}
PFNGLVERTEXATTRIB2FARBPROC glad_debug_glVertexAttrib2fARB = glad_debug_impl_glVertexAttrib2fARB;
PFNGLVERTEXATTRIB2FNVPROC glad_glVertexAttrib2fNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2fNV(GLuint index, GLfloat x, GLfloat y) {
    _pre_call_gl_callback("glVertexAttrib2fNV", (GLADapiproc) glad_glVertexAttrib2fNV, 3, index, x, y);
    glad_glVertexAttrib2fNV(index, x, y);
    _post_call_gl_callback(NULL, "glVertexAttrib2fNV", (GLADapiproc) glad_glVertexAttrib2fNV, 3, index, x, y);
    
}
PFNGLVERTEXATTRIB2FNVPROC glad_debug_glVertexAttrib2fNV = glad_debug_impl_glVertexAttrib2fNV;
PFNGLVERTEXATTRIB2FVPROC glad_glVertexAttrib2fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2fv(GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttrib2fv", (GLADapiproc) glad_glVertexAttrib2fv, 2, index, v);
    glad_glVertexAttrib2fv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib2fv", (GLADapiproc) glad_glVertexAttrib2fv, 2, index, v);
    
}
PFNGLVERTEXATTRIB2FVPROC glad_debug_glVertexAttrib2fv = glad_debug_impl_glVertexAttrib2fv;
PFNGLVERTEXATTRIB2FVARBPROC glad_glVertexAttrib2fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2fvARB(GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttrib2fvARB", (GLADapiproc) glad_glVertexAttrib2fvARB, 2, index, v);
    glad_glVertexAttrib2fvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib2fvARB", (GLADapiproc) glad_glVertexAttrib2fvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB2FVARBPROC glad_debug_glVertexAttrib2fvARB = glad_debug_impl_glVertexAttrib2fvARB;
PFNGLVERTEXATTRIB2FVNVPROC glad_glVertexAttrib2fvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2fvNV(GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttrib2fvNV", (GLADapiproc) glad_glVertexAttrib2fvNV, 2, index, v);
    glad_glVertexAttrib2fvNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib2fvNV", (GLADapiproc) glad_glVertexAttrib2fvNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB2FVNVPROC glad_debug_glVertexAttrib2fvNV = glad_debug_impl_glVertexAttrib2fvNV;
PFNGLVERTEXATTRIB2SPROC glad_glVertexAttrib2s = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2s(GLuint index, GLshort x, GLshort y) {
    _pre_call_gl_callback("glVertexAttrib2s", (GLADapiproc) glad_glVertexAttrib2s, 3, index, x, y);
    glad_glVertexAttrib2s(index, x, y);
    _post_call_gl_callback(NULL, "glVertexAttrib2s", (GLADapiproc) glad_glVertexAttrib2s, 3, index, x, y);
    
}
PFNGLVERTEXATTRIB2SPROC glad_debug_glVertexAttrib2s = glad_debug_impl_glVertexAttrib2s;
PFNGLVERTEXATTRIB2SARBPROC glad_glVertexAttrib2sARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y) {
    _pre_call_gl_callback("glVertexAttrib2sARB", (GLADapiproc) glad_glVertexAttrib2sARB, 3, index, x, y);
    glad_glVertexAttrib2sARB(index, x, y);
    _post_call_gl_callback(NULL, "glVertexAttrib2sARB", (GLADapiproc) glad_glVertexAttrib2sARB, 3, index, x, y);
    
}
PFNGLVERTEXATTRIB2SARBPROC glad_debug_glVertexAttrib2sARB = glad_debug_impl_glVertexAttrib2sARB;
PFNGLVERTEXATTRIB2SNVPROC glad_glVertexAttrib2sNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2sNV(GLuint index, GLshort x, GLshort y) {
    _pre_call_gl_callback("glVertexAttrib2sNV", (GLADapiproc) glad_glVertexAttrib2sNV, 3, index, x, y);
    glad_glVertexAttrib2sNV(index, x, y);
    _post_call_gl_callback(NULL, "glVertexAttrib2sNV", (GLADapiproc) glad_glVertexAttrib2sNV, 3, index, x, y);
    
}
PFNGLVERTEXATTRIB2SNVPROC glad_debug_glVertexAttrib2sNV = glad_debug_impl_glVertexAttrib2sNV;
PFNGLVERTEXATTRIB2SVPROC glad_glVertexAttrib2sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2sv(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib2sv", (GLADapiproc) glad_glVertexAttrib2sv, 2, index, v);
    glad_glVertexAttrib2sv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib2sv", (GLADapiproc) glad_glVertexAttrib2sv, 2, index, v);
    
}
PFNGLVERTEXATTRIB2SVPROC glad_debug_glVertexAttrib2sv = glad_debug_impl_glVertexAttrib2sv;
PFNGLVERTEXATTRIB2SVARBPROC glad_glVertexAttrib2svARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2svARB(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib2svARB", (GLADapiproc) glad_glVertexAttrib2svARB, 2, index, v);
    glad_glVertexAttrib2svARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib2svARB", (GLADapiproc) glad_glVertexAttrib2svARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB2SVARBPROC glad_debug_glVertexAttrib2svARB = glad_debug_impl_glVertexAttrib2svARB;
PFNGLVERTEXATTRIB2SVNVPROC glad_glVertexAttrib2svNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib2svNV(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib2svNV", (GLADapiproc) glad_glVertexAttrib2svNV, 2, index, v);
    glad_glVertexAttrib2svNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib2svNV", (GLADapiproc) glad_glVertexAttrib2svNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB2SVNVPROC glad_debug_glVertexAttrib2svNV = glad_debug_impl_glVertexAttrib2svNV;
PFNGLVERTEXATTRIB3DPROC glad_glVertexAttrib3d = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    _pre_call_gl_callback("glVertexAttrib3d", (GLADapiproc) glad_glVertexAttrib3d, 4, index, x, y, z);
    glad_glVertexAttrib3d(index, x, y, z);
    _post_call_gl_callback(NULL, "glVertexAttrib3d", (GLADapiproc) glad_glVertexAttrib3d, 4, index, x, y, z);
    
}
PFNGLVERTEXATTRIB3DPROC glad_debug_glVertexAttrib3d = glad_debug_impl_glVertexAttrib3d;
PFNGLVERTEXATTRIB3DARBPROC glad_glVertexAttrib3dARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    _pre_call_gl_callback("glVertexAttrib3dARB", (GLADapiproc) glad_glVertexAttrib3dARB, 4, index, x, y, z);
    glad_glVertexAttrib3dARB(index, x, y, z);
    _post_call_gl_callback(NULL, "glVertexAttrib3dARB", (GLADapiproc) glad_glVertexAttrib3dARB, 4, index, x, y, z);
    
}
PFNGLVERTEXATTRIB3DARBPROC glad_debug_glVertexAttrib3dARB = glad_debug_impl_glVertexAttrib3dARB;
PFNGLVERTEXATTRIB3DNVPROC glad_glVertexAttrib3dNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    _pre_call_gl_callback("glVertexAttrib3dNV", (GLADapiproc) glad_glVertexAttrib3dNV, 4, index, x, y, z);
    glad_glVertexAttrib3dNV(index, x, y, z);
    _post_call_gl_callback(NULL, "glVertexAttrib3dNV", (GLADapiproc) glad_glVertexAttrib3dNV, 4, index, x, y, z);
    
}
PFNGLVERTEXATTRIB3DNVPROC glad_debug_glVertexAttrib3dNV = glad_debug_impl_glVertexAttrib3dNV;
PFNGLVERTEXATTRIB3DVPROC glad_glVertexAttrib3dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3dv(GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttrib3dv", (GLADapiproc) glad_glVertexAttrib3dv, 2, index, v);
    glad_glVertexAttrib3dv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib3dv", (GLADapiproc) glad_glVertexAttrib3dv, 2, index, v);
    
}
PFNGLVERTEXATTRIB3DVPROC glad_debug_glVertexAttrib3dv = glad_debug_impl_glVertexAttrib3dv;
PFNGLVERTEXATTRIB3DVARBPROC glad_glVertexAttrib3dvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3dvARB(GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttrib3dvARB", (GLADapiproc) glad_glVertexAttrib3dvARB, 2, index, v);
    glad_glVertexAttrib3dvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib3dvARB", (GLADapiproc) glad_glVertexAttrib3dvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB3DVARBPROC glad_debug_glVertexAttrib3dvARB = glad_debug_impl_glVertexAttrib3dvARB;
PFNGLVERTEXATTRIB3DVNVPROC glad_glVertexAttrib3dvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3dvNV(GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttrib3dvNV", (GLADapiproc) glad_glVertexAttrib3dvNV, 2, index, v);
    glad_glVertexAttrib3dvNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib3dvNV", (GLADapiproc) glad_glVertexAttrib3dvNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB3DVNVPROC glad_debug_glVertexAttrib3dvNV = glad_debug_impl_glVertexAttrib3dvNV;
PFNGLVERTEXATTRIB3FPROC glad_glVertexAttrib3f = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    _pre_call_gl_callback("glVertexAttrib3f", (GLADapiproc) glad_glVertexAttrib3f, 4, index, x, y, z);
    glad_glVertexAttrib3f(index, x, y, z);
    _post_call_gl_callback(NULL, "glVertexAttrib3f", (GLADapiproc) glad_glVertexAttrib3f, 4, index, x, y, z);
    
}
PFNGLVERTEXATTRIB3FPROC glad_debug_glVertexAttrib3f = glad_debug_impl_glVertexAttrib3f;
PFNGLVERTEXATTRIB3FARBPROC glad_glVertexAttrib3fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    _pre_call_gl_callback("glVertexAttrib3fARB", (GLADapiproc) glad_glVertexAttrib3fARB, 4, index, x, y, z);
    glad_glVertexAttrib3fARB(index, x, y, z);
    _post_call_gl_callback(NULL, "glVertexAttrib3fARB", (GLADapiproc) glad_glVertexAttrib3fARB, 4, index, x, y, z);
    
}
PFNGLVERTEXATTRIB3FARBPROC glad_debug_glVertexAttrib3fARB = glad_debug_impl_glVertexAttrib3fARB;
PFNGLVERTEXATTRIB3FNVPROC glad_glVertexAttrib3fNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    _pre_call_gl_callback("glVertexAttrib3fNV", (GLADapiproc) glad_glVertexAttrib3fNV, 4, index, x, y, z);
    glad_glVertexAttrib3fNV(index, x, y, z);
    _post_call_gl_callback(NULL, "glVertexAttrib3fNV", (GLADapiproc) glad_glVertexAttrib3fNV, 4, index, x, y, z);
    
}
PFNGLVERTEXATTRIB3FNVPROC glad_debug_glVertexAttrib3fNV = glad_debug_impl_glVertexAttrib3fNV;
PFNGLVERTEXATTRIB3FVPROC glad_glVertexAttrib3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3fv(GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttrib3fv", (GLADapiproc) glad_glVertexAttrib3fv, 2, index, v);
    glad_glVertexAttrib3fv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib3fv", (GLADapiproc) glad_glVertexAttrib3fv, 2, index, v);
    
}
PFNGLVERTEXATTRIB3FVPROC glad_debug_glVertexAttrib3fv = glad_debug_impl_glVertexAttrib3fv;
PFNGLVERTEXATTRIB3FVARBPROC glad_glVertexAttrib3fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3fvARB(GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttrib3fvARB", (GLADapiproc) glad_glVertexAttrib3fvARB, 2, index, v);
    glad_glVertexAttrib3fvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib3fvARB", (GLADapiproc) glad_glVertexAttrib3fvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB3FVARBPROC glad_debug_glVertexAttrib3fvARB = glad_debug_impl_glVertexAttrib3fvARB;
PFNGLVERTEXATTRIB3FVNVPROC glad_glVertexAttrib3fvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3fvNV(GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttrib3fvNV", (GLADapiproc) glad_glVertexAttrib3fvNV, 2, index, v);
    glad_glVertexAttrib3fvNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib3fvNV", (GLADapiproc) glad_glVertexAttrib3fvNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB3FVNVPROC glad_debug_glVertexAttrib3fvNV = glad_debug_impl_glVertexAttrib3fvNV;
PFNGLVERTEXATTRIB3SPROC glad_glVertexAttrib3s = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) {
    _pre_call_gl_callback("glVertexAttrib3s", (GLADapiproc) glad_glVertexAttrib3s, 4, index, x, y, z);
    glad_glVertexAttrib3s(index, x, y, z);
    _post_call_gl_callback(NULL, "glVertexAttrib3s", (GLADapiproc) glad_glVertexAttrib3s, 4, index, x, y, z);
    
}
PFNGLVERTEXATTRIB3SPROC glad_debug_glVertexAttrib3s = glad_debug_impl_glVertexAttrib3s;
PFNGLVERTEXATTRIB3SARBPROC glad_glVertexAttrib3sARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z) {
    _pre_call_gl_callback("glVertexAttrib3sARB", (GLADapiproc) glad_glVertexAttrib3sARB, 4, index, x, y, z);
    glad_glVertexAttrib3sARB(index, x, y, z);
    _post_call_gl_callback(NULL, "glVertexAttrib3sARB", (GLADapiproc) glad_glVertexAttrib3sARB, 4, index, x, y, z);
    
}
PFNGLVERTEXATTRIB3SARBPROC glad_debug_glVertexAttrib3sARB = glad_debug_impl_glVertexAttrib3sARB;
PFNGLVERTEXATTRIB3SNVPROC glad_glVertexAttrib3sNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3sNV(GLuint index, GLshort x, GLshort y, GLshort z) {
    _pre_call_gl_callback("glVertexAttrib3sNV", (GLADapiproc) glad_glVertexAttrib3sNV, 4, index, x, y, z);
    glad_glVertexAttrib3sNV(index, x, y, z);
    _post_call_gl_callback(NULL, "glVertexAttrib3sNV", (GLADapiproc) glad_glVertexAttrib3sNV, 4, index, x, y, z);
    
}
PFNGLVERTEXATTRIB3SNVPROC glad_debug_glVertexAttrib3sNV = glad_debug_impl_glVertexAttrib3sNV;
PFNGLVERTEXATTRIB3SVPROC glad_glVertexAttrib3sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3sv(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib3sv", (GLADapiproc) glad_glVertexAttrib3sv, 2, index, v);
    glad_glVertexAttrib3sv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib3sv", (GLADapiproc) glad_glVertexAttrib3sv, 2, index, v);
    
}
PFNGLVERTEXATTRIB3SVPROC glad_debug_glVertexAttrib3sv = glad_debug_impl_glVertexAttrib3sv;
PFNGLVERTEXATTRIB3SVARBPROC glad_glVertexAttrib3svARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3svARB(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib3svARB", (GLADapiproc) glad_glVertexAttrib3svARB, 2, index, v);
    glad_glVertexAttrib3svARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib3svARB", (GLADapiproc) glad_glVertexAttrib3svARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB3SVARBPROC glad_debug_glVertexAttrib3svARB = glad_debug_impl_glVertexAttrib3svARB;
PFNGLVERTEXATTRIB3SVNVPROC glad_glVertexAttrib3svNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib3svNV(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib3svNV", (GLADapiproc) glad_glVertexAttrib3svNV, 2, index, v);
    glad_glVertexAttrib3svNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib3svNV", (GLADapiproc) glad_glVertexAttrib3svNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB3SVNVPROC glad_debug_glVertexAttrib3svNV = glad_debug_impl_glVertexAttrib3svNV;
PFNGLVERTEXATTRIB4NBVPROC glad_glVertexAttrib4Nbv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4Nbv(GLuint index, const GLbyte * v) {
    _pre_call_gl_callback("glVertexAttrib4Nbv", (GLADapiproc) glad_glVertexAttrib4Nbv, 2, index, v);
    glad_glVertexAttrib4Nbv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4Nbv", (GLADapiproc) glad_glVertexAttrib4Nbv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4NBVPROC glad_debug_glVertexAttrib4Nbv = glad_debug_impl_glVertexAttrib4Nbv;
PFNGLVERTEXATTRIB4NBVARBPROC glad_glVertexAttrib4NbvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4NbvARB(GLuint index, const GLbyte * v) {
    _pre_call_gl_callback("glVertexAttrib4NbvARB", (GLADapiproc) glad_glVertexAttrib4NbvARB, 2, index, v);
    glad_glVertexAttrib4NbvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4NbvARB", (GLADapiproc) glad_glVertexAttrib4NbvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4NBVARBPROC glad_debug_glVertexAttrib4NbvARB = glad_debug_impl_glVertexAttrib4NbvARB;
PFNGLVERTEXATTRIB4NIVPROC glad_glVertexAttrib4Niv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4Niv(GLuint index, const GLint * v) {
    _pre_call_gl_callback("glVertexAttrib4Niv", (GLADapiproc) glad_glVertexAttrib4Niv, 2, index, v);
    glad_glVertexAttrib4Niv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4Niv", (GLADapiproc) glad_glVertexAttrib4Niv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4NIVPROC glad_debug_glVertexAttrib4Niv = glad_debug_impl_glVertexAttrib4Niv;
PFNGLVERTEXATTRIB4NIVARBPROC glad_glVertexAttrib4NivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4NivARB(GLuint index, const GLint * v) {
    _pre_call_gl_callback("glVertexAttrib4NivARB", (GLADapiproc) glad_glVertexAttrib4NivARB, 2, index, v);
    glad_glVertexAttrib4NivARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4NivARB", (GLADapiproc) glad_glVertexAttrib4NivARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4NIVARBPROC glad_debug_glVertexAttrib4NivARB = glad_debug_impl_glVertexAttrib4NivARB;
PFNGLVERTEXATTRIB4NSVPROC glad_glVertexAttrib4Nsv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4Nsv(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib4Nsv", (GLADapiproc) glad_glVertexAttrib4Nsv, 2, index, v);
    glad_glVertexAttrib4Nsv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4Nsv", (GLADapiproc) glad_glVertexAttrib4Nsv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4NSVPROC glad_debug_glVertexAttrib4Nsv = glad_debug_impl_glVertexAttrib4Nsv;
PFNGLVERTEXATTRIB4NSVARBPROC glad_glVertexAttrib4NsvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4NsvARB(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib4NsvARB", (GLADapiproc) glad_glVertexAttrib4NsvARB, 2, index, v);
    glad_glVertexAttrib4NsvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4NsvARB", (GLADapiproc) glad_glVertexAttrib4NsvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4NSVARBPROC glad_debug_glVertexAttrib4NsvARB = glad_debug_impl_glVertexAttrib4NsvARB;
PFNGLVERTEXATTRIB4NUBPROC glad_glVertexAttrib4Nub = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
    _pre_call_gl_callback("glVertexAttrib4Nub", (GLADapiproc) glad_glVertexAttrib4Nub, 5, index, x, y, z, w);
    glad_glVertexAttrib4Nub(index, x, y, z, w);
    _post_call_gl_callback(NULL, "glVertexAttrib4Nub", (GLADapiproc) glad_glVertexAttrib4Nub, 5, index, x, y, z, w);
    
}
PFNGLVERTEXATTRIB4NUBPROC glad_debug_glVertexAttrib4Nub = glad_debug_impl_glVertexAttrib4Nub;
PFNGLVERTEXATTRIB4NUBARBPROC glad_glVertexAttrib4NubARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
    _pre_call_gl_callback("glVertexAttrib4NubARB", (GLADapiproc) glad_glVertexAttrib4NubARB, 5, index, x, y, z, w);
    glad_glVertexAttrib4NubARB(index, x, y, z, w);
    _post_call_gl_callback(NULL, "glVertexAttrib4NubARB", (GLADapiproc) glad_glVertexAttrib4NubARB, 5, index, x, y, z, w);
    
}
PFNGLVERTEXATTRIB4NUBARBPROC glad_debug_glVertexAttrib4NubARB = glad_debug_impl_glVertexAttrib4NubARB;
PFNGLVERTEXATTRIB4NUBVPROC glad_glVertexAttrib4Nubv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4Nubv(GLuint index, const GLubyte * v) {
    _pre_call_gl_callback("glVertexAttrib4Nubv", (GLADapiproc) glad_glVertexAttrib4Nubv, 2, index, v);
    glad_glVertexAttrib4Nubv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4Nubv", (GLADapiproc) glad_glVertexAttrib4Nubv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4NUBVPROC glad_debug_glVertexAttrib4Nubv = glad_debug_impl_glVertexAttrib4Nubv;
PFNGLVERTEXATTRIB4NUBVARBPROC glad_glVertexAttrib4NubvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4NubvARB(GLuint index, const GLubyte * v) {
    _pre_call_gl_callback("glVertexAttrib4NubvARB", (GLADapiproc) glad_glVertexAttrib4NubvARB, 2, index, v);
    glad_glVertexAttrib4NubvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4NubvARB", (GLADapiproc) glad_glVertexAttrib4NubvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4NUBVARBPROC glad_debug_glVertexAttrib4NubvARB = glad_debug_impl_glVertexAttrib4NubvARB;
PFNGLVERTEXATTRIB4NUIVPROC glad_glVertexAttrib4Nuiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4Nuiv(GLuint index, const GLuint * v) {
    _pre_call_gl_callback("glVertexAttrib4Nuiv", (GLADapiproc) glad_glVertexAttrib4Nuiv, 2, index, v);
    glad_glVertexAttrib4Nuiv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4Nuiv", (GLADapiproc) glad_glVertexAttrib4Nuiv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4NUIVPROC glad_debug_glVertexAttrib4Nuiv = glad_debug_impl_glVertexAttrib4Nuiv;
PFNGLVERTEXATTRIB4NUIVARBPROC glad_glVertexAttrib4NuivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4NuivARB(GLuint index, const GLuint * v) {
    _pre_call_gl_callback("glVertexAttrib4NuivARB", (GLADapiproc) glad_glVertexAttrib4NuivARB, 2, index, v);
    glad_glVertexAttrib4NuivARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4NuivARB", (GLADapiproc) glad_glVertexAttrib4NuivARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4NUIVARBPROC glad_debug_glVertexAttrib4NuivARB = glad_debug_impl_glVertexAttrib4NuivARB;
PFNGLVERTEXATTRIB4NUSVPROC glad_glVertexAttrib4Nusv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4Nusv(GLuint index, const GLushort * v) {
    _pre_call_gl_callback("glVertexAttrib4Nusv", (GLADapiproc) glad_glVertexAttrib4Nusv, 2, index, v);
    glad_glVertexAttrib4Nusv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4Nusv", (GLADapiproc) glad_glVertexAttrib4Nusv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4NUSVPROC glad_debug_glVertexAttrib4Nusv = glad_debug_impl_glVertexAttrib4Nusv;
PFNGLVERTEXATTRIB4NUSVARBPROC glad_glVertexAttrib4NusvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4NusvARB(GLuint index, const GLushort * v) {
    _pre_call_gl_callback("glVertexAttrib4NusvARB", (GLADapiproc) glad_glVertexAttrib4NusvARB, 2, index, v);
    glad_glVertexAttrib4NusvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4NusvARB", (GLADapiproc) glad_glVertexAttrib4NusvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4NUSVARBPROC glad_debug_glVertexAttrib4NusvARB = glad_debug_impl_glVertexAttrib4NusvARB;
PFNGLVERTEXATTRIB4BVPROC glad_glVertexAttrib4bv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4bv(GLuint index, const GLbyte * v) {
    _pre_call_gl_callback("glVertexAttrib4bv", (GLADapiproc) glad_glVertexAttrib4bv, 2, index, v);
    glad_glVertexAttrib4bv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4bv", (GLADapiproc) glad_glVertexAttrib4bv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4BVPROC glad_debug_glVertexAttrib4bv = glad_debug_impl_glVertexAttrib4bv;
PFNGLVERTEXATTRIB4BVARBPROC glad_glVertexAttrib4bvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4bvARB(GLuint index, const GLbyte * v) {
    _pre_call_gl_callback("glVertexAttrib4bvARB", (GLADapiproc) glad_glVertexAttrib4bvARB, 2, index, v);
    glad_glVertexAttrib4bvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4bvARB", (GLADapiproc) glad_glVertexAttrib4bvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4BVARBPROC glad_debug_glVertexAttrib4bvARB = glad_debug_impl_glVertexAttrib4bvARB;
PFNGLVERTEXATTRIB4DPROC glad_glVertexAttrib4d = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    _pre_call_gl_callback("glVertexAttrib4d", (GLADapiproc) glad_glVertexAttrib4d, 5, index, x, y, z, w);
    glad_glVertexAttrib4d(index, x, y, z, w);
    _post_call_gl_callback(NULL, "glVertexAttrib4d", (GLADapiproc) glad_glVertexAttrib4d, 5, index, x, y, z, w);
    
}
PFNGLVERTEXATTRIB4DPROC glad_debug_glVertexAttrib4d = glad_debug_impl_glVertexAttrib4d;
PFNGLVERTEXATTRIB4DARBPROC glad_glVertexAttrib4dARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    _pre_call_gl_callback("glVertexAttrib4dARB", (GLADapiproc) glad_glVertexAttrib4dARB, 5, index, x, y, z, w);
    glad_glVertexAttrib4dARB(index, x, y, z, w);
    _post_call_gl_callback(NULL, "glVertexAttrib4dARB", (GLADapiproc) glad_glVertexAttrib4dARB, 5, index, x, y, z, w);
    
}
PFNGLVERTEXATTRIB4DARBPROC glad_debug_glVertexAttrib4dARB = glad_debug_impl_glVertexAttrib4dARB;
PFNGLVERTEXATTRIB4DNVPROC glad_glVertexAttrib4dNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    _pre_call_gl_callback("glVertexAttrib4dNV", (GLADapiproc) glad_glVertexAttrib4dNV, 5, index, x, y, z, w);
    glad_glVertexAttrib4dNV(index, x, y, z, w);
    _post_call_gl_callback(NULL, "glVertexAttrib4dNV", (GLADapiproc) glad_glVertexAttrib4dNV, 5, index, x, y, z, w);
    
}
PFNGLVERTEXATTRIB4DNVPROC glad_debug_glVertexAttrib4dNV = glad_debug_impl_glVertexAttrib4dNV;
PFNGLVERTEXATTRIB4DVPROC glad_glVertexAttrib4dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4dv(GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttrib4dv", (GLADapiproc) glad_glVertexAttrib4dv, 2, index, v);
    glad_glVertexAttrib4dv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4dv", (GLADapiproc) glad_glVertexAttrib4dv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4DVPROC glad_debug_glVertexAttrib4dv = glad_debug_impl_glVertexAttrib4dv;
PFNGLVERTEXATTRIB4DVARBPROC glad_glVertexAttrib4dvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4dvARB(GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttrib4dvARB", (GLADapiproc) glad_glVertexAttrib4dvARB, 2, index, v);
    glad_glVertexAttrib4dvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4dvARB", (GLADapiproc) glad_glVertexAttrib4dvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4DVARBPROC glad_debug_glVertexAttrib4dvARB = glad_debug_impl_glVertexAttrib4dvARB;
PFNGLVERTEXATTRIB4DVNVPROC glad_glVertexAttrib4dvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4dvNV(GLuint index, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttrib4dvNV", (GLADapiproc) glad_glVertexAttrib4dvNV, 2, index, v);
    glad_glVertexAttrib4dvNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4dvNV", (GLADapiproc) glad_glVertexAttrib4dvNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB4DVNVPROC glad_debug_glVertexAttrib4dvNV = glad_debug_impl_glVertexAttrib4dvNV;
PFNGLVERTEXATTRIB4FPROC glad_glVertexAttrib4f = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _pre_call_gl_callback("glVertexAttrib4f", (GLADapiproc) glad_glVertexAttrib4f, 5, index, x, y, z, w);
    glad_glVertexAttrib4f(index, x, y, z, w);
    _post_call_gl_callback(NULL, "glVertexAttrib4f", (GLADapiproc) glad_glVertexAttrib4f, 5, index, x, y, z, w);
    
}
PFNGLVERTEXATTRIB4FPROC glad_debug_glVertexAttrib4f = glad_debug_impl_glVertexAttrib4f;
PFNGLVERTEXATTRIB4FARBPROC glad_glVertexAttrib4fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _pre_call_gl_callback("glVertexAttrib4fARB", (GLADapiproc) glad_glVertexAttrib4fARB, 5, index, x, y, z, w);
    glad_glVertexAttrib4fARB(index, x, y, z, w);
    _post_call_gl_callback(NULL, "glVertexAttrib4fARB", (GLADapiproc) glad_glVertexAttrib4fARB, 5, index, x, y, z, w);
    
}
PFNGLVERTEXATTRIB4FARBPROC glad_debug_glVertexAttrib4fARB = glad_debug_impl_glVertexAttrib4fARB;
PFNGLVERTEXATTRIB4FNVPROC glad_glVertexAttrib4fNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _pre_call_gl_callback("glVertexAttrib4fNV", (GLADapiproc) glad_glVertexAttrib4fNV, 5, index, x, y, z, w);
    glad_glVertexAttrib4fNV(index, x, y, z, w);
    _post_call_gl_callback(NULL, "glVertexAttrib4fNV", (GLADapiproc) glad_glVertexAttrib4fNV, 5, index, x, y, z, w);
    
}
PFNGLVERTEXATTRIB4FNVPROC glad_debug_glVertexAttrib4fNV = glad_debug_impl_glVertexAttrib4fNV;
PFNGLVERTEXATTRIB4FVPROC glad_glVertexAttrib4fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4fv(GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttrib4fv", (GLADapiproc) glad_glVertexAttrib4fv, 2, index, v);
    glad_glVertexAttrib4fv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4fv", (GLADapiproc) glad_glVertexAttrib4fv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4FVPROC glad_debug_glVertexAttrib4fv = glad_debug_impl_glVertexAttrib4fv;
PFNGLVERTEXATTRIB4FVARBPROC glad_glVertexAttrib4fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4fvARB(GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttrib4fvARB", (GLADapiproc) glad_glVertexAttrib4fvARB, 2, index, v);
    glad_glVertexAttrib4fvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4fvARB", (GLADapiproc) glad_glVertexAttrib4fvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4FVARBPROC glad_debug_glVertexAttrib4fvARB = glad_debug_impl_glVertexAttrib4fvARB;
PFNGLVERTEXATTRIB4FVNVPROC glad_glVertexAttrib4fvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4fvNV(GLuint index, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttrib4fvNV", (GLADapiproc) glad_glVertexAttrib4fvNV, 2, index, v);
    glad_glVertexAttrib4fvNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4fvNV", (GLADapiproc) glad_glVertexAttrib4fvNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB4FVNVPROC glad_debug_glVertexAttrib4fvNV = glad_debug_impl_glVertexAttrib4fvNV;
PFNGLVERTEXATTRIB4IVPROC glad_glVertexAttrib4iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4iv(GLuint index, const GLint * v) {
    _pre_call_gl_callback("glVertexAttrib4iv", (GLADapiproc) glad_glVertexAttrib4iv, 2, index, v);
    glad_glVertexAttrib4iv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4iv", (GLADapiproc) glad_glVertexAttrib4iv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4IVPROC glad_debug_glVertexAttrib4iv = glad_debug_impl_glVertexAttrib4iv;
PFNGLVERTEXATTRIB4IVARBPROC glad_glVertexAttrib4ivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4ivARB(GLuint index, const GLint * v) {
    _pre_call_gl_callback("glVertexAttrib4ivARB", (GLADapiproc) glad_glVertexAttrib4ivARB, 2, index, v);
    glad_glVertexAttrib4ivARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4ivARB", (GLADapiproc) glad_glVertexAttrib4ivARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4IVARBPROC glad_debug_glVertexAttrib4ivARB = glad_debug_impl_glVertexAttrib4ivARB;
PFNGLVERTEXATTRIB4SPROC glad_glVertexAttrib4s = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
    _pre_call_gl_callback("glVertexAttrib4s", (GLADapiproc) glad_glVertexAttrib4s, 5, index, x, y, z, w);
    glad_glVertexAttrib4s(index, x, y, z, w);
    _post_call_gl_callback(NULL, "glVertexAttrib4s", (GLADapiproc) glad_glVertexAttrib4s, 5, index, x, y, z, w);
    
}
PFNGLVERTEXATTRIB4SPROC glad_debug_glVertexAttrib4s = glad_debug_impl_glVertexAttrib4s;
PFNGLVERTEXATTRIB4SARBPROC glad_glVertexAttrib4sARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
    _pre_call_gl_callback("glVertexAttrib4sARB", (GLADapiproc) glad_glVertexAttrib4sARB, 5, index, x, y, z, w);
    glad_glVertexAttrib4sARB(index, x, y, z, w);
    _post_call_gl_callback(NULL, "glVertexAttrib4sARB", (GLADapiproc) glad_glVertexAttrib4sARB, 5, index, x, y, z, w);
    
}
PFNGLVERTEXATTRIB4SARBPROC glad_debug_glVertexAttrib4sARB = glad_debug_impl_glVertexAttrib4sARB;
PFNGLVERTEXATTRIB4SNVPROC glad_glVertexAttrib4sNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4sNV(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
    _pre_call_gl_callback("glVertexAttrib4sNV", (GLADapiproc) glad_glVertexAttrib4sNV, 5, index, x, y, z, w);
    glad_glVertexAttrib4sNV(index, x, y, z, w);
    _post_call_gl_callback(NULL, "glVertexAttrib4sNV", (GLADapiproc) glad_glVertexAttrib4sNV, 5, index, x, y, z, w);
    
}
PFNGLVERTEXATTRIB4SNVPROC glad_debug_glVertexAttrib4sNV = glad_debug_impl_glVertexAttrib4sNV;
PFNGLVERTEXATTRIB4SVPROC glad_glVertexAttrib4sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4sv(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib4sv", (GLADapiproc) glad_glVertexAttrib4sv, 2, index, v);
    glad_glVertexAttrib4sv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4sv", (GLADapiproc) glad_glVertexAttrib4sv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4SVPROC glad_debug_glVertexAttrib4sv = glad_debug_impl_glVertexAttrib4sv;
PFNGLVERTEXATTRIB4SVARBPROC glad_glVertexAttrib4svARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4svARB(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib4svARB", (GLADapiproc) glad_glVertexAttrib4svARB, 2, index, v);
    glad_glVertexAttrib4svARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4svARB", (GLADapiproc) glad_glVertexAttrib4svARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4SVARBPROC glad_debug_glVertexAttrib4svARB = glad_debug_impl_glVertexAttrib4svARB;
PFNGLVERTEXATTRIB4SVNVPROC glad_glVertexAttrib4svNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4svNV(GLuint index, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttrib4svNV", (GLADapiproc) glad_glVertexAttrib4svNV, 2, index, v);
    glad_glVertexAttrib4svNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4svNV", (GLADapiproc) glad_glVertexAttrib4svNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB4SVNVPROC glad_debug_glVertexAttrib4svNV = glad_debug_impl_glVertexAttrib4svNV;
PFNGLVERTEXATTRIB4UBNVPROC glad_glVertexAttrib4ubNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4ubNV(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
    _pre_call_gl_callback("glVertexAttrib4ubNV", (GLADapiproc) glad_glVertexAttrib4ubNV, 5, index, x, y, z, w);
    glad_glVertexAttrib4ubNV(index, x, y, z, w);
    _post_call_gl_callback(NULL, "glVertexAttrib4ubNV", (GLADapiproc) glad_glVertexAttrib4ubNV, 5, index, x, y, z, w);
    
}
PFNGLVERTEXATTRIB4UBNVPROC glad_debug_glVertexAttrib4ubNV = glad_debug_impl_glVertexAttrib4ubNV;
PFNGLVERTEXATTRIB4UBVPROC glad_glVertexAttrib4ubv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4ubv(GLuint index, const GLubyte * v) {
    _pre_call_gl_callback("glVertexAttrib4ubv", (GLADapiproc) glad_glVertexAttrib4ubv, 2, index, v);
    glad_glVertexAttrib4ubv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4ubv", (GLADapiproc) glad_glVertexAttrib4ubv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4UBVPROC glad_debug_glVertexAttrib4ubv = glad_debug_impl_glVertexAttrib4ubv;
PFNGLVERTEXATTRIB4UBVARBPROC glad_glVertexAttrib4ubvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4ubvARB(GLuint index, const GLubyte * v) {
    _pre_call_gl_callback("glVertexAttrib4ubvARB", (GLADapiproc) glad_glVertexAttrib4ubvARB, 2, index, v);
    glad_glVertexAttrib4ubvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4ubvARB", (GLADapiproc) glad_glVertexAttrib4ubvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4UBVARBPROC glad_debug_glVertexAttrib4ubvARB = glad_debug_impl_glVertexAttrib4ubvARB;
PFNGLVERTEXATTRIB4UBVNVPROC glad_glVertexAttrib4ubvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4ubvNV(GLuint index, const GLubyte * v) {
    _pre_call_gl_callback("glVertexAttrib4ubvNV", (GLADapiproc) glad_glVertexAttrib4ubvNV, 2, index, v);
    glad_glVertexAttrib4ubvNV(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4ubvNV", (GLADapiproc) glad_glVertexAttrib4ubvNV, 2, index, v);
    
}
PFNGLVERTEXATTRIB4UBVNVPROC glad_debug_glVertexAttrib4ubvNV = glad_debug_impl_glVertexAttrib4ubvNV;
PFNGLVERTEXATTRIB4UIVPROC glad_glVertexAttrib4uiv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4uiv(GLuint index, const GLuint * v) {
    _pre_call_gl_callback("glVertexAttrib4uiv", (GLADapiproc) glad_glVertexAttrib4uiv, 2, index, v);
    glad_glVertexAttrib4uiv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4uiv", (GLADapiproc) glad_glVertexAttrib4uiv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4UIVPROC glad_debug_glVertexAttrib4uiv = glad_debug_impl_glVertexAttrib4uiv;
PFNGLVERTEXATTRIB4UIVARBPROC glad_glVertexAttrib4uivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4uivARB(GLuint index, const GLuint * v) {
    _pre_call_gl_callback("glVertexAttrib4uivARB", (GLADapiproc) glad_glVertexAttrib4uivARB, 2, index, v);
    glad_glVertexAttrib4uivARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4uivARB", (GLADapiproc) glad_glVertexAttrib4uivARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4UIVARBPROC glad_debug_glVertexAttrib4uivARB = glad_debug_impl_glVertexAttrib4uivARB;
PFNGLVERTEXATTRIB4USVPROC glad_glVertexAttrib4usv = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4usv(GLuint index, const GLushort * v) {
    _pre_call_gl_callback("glVertexAttrib4usv", (GLADapiproc) glad_glVertexAttrib4usv, 2, index, v);
    glad_glVertexAttrib4usv(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4usv", (GLADapiproc) glad_glVertexAttrib4usv, 2, index, v);
    
}
PFNGLVERTEXATTRIB4USVPROC glad_debug_glVertexAttrib4usv = glad_debug_impl_glVertexAttrib4usv;
PFNGLVERTEXATTRIB4USVARBPROC glad_glVertexAttrib4usvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttrib4usvARB(GLuint index, const GLushort * v) {
    _pre_call_gl_callback("glVertexAttrib4usvARB", (GLADapiproc) glad_glVertexAttrib4usvARB, 2, index, v);
    glad_glVertexAttrib4usvARB(index, v);
    _post_call_gl_callback(NULL, "glVertexAttrib4usvARB", (GLADapiproc) glad_glVertexAttrib4usvARB, 2, index, v);
    
}
PFNGLVERTEXATTRIB4USVARBPROC glad_debug_glVertexAttrib4usvARB = glad_debug_impl_glVertexAttrib4usvARB;
PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glVertexAttribPointer", (GLADapiproc) glad_glVertexAttribPointer, 6, index, size, type, normalized, stride, pointer);
    glad_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    _post_call_gl_callback(NULL, "glVertexAttribPointer", (GLADapiproc) glad_glVertexAttribPointer, 6, index, size, type, normalized, stride, pointer);
    
}
PFNGLVERTEXATTRIBPOINTERPROC glad_debug_glVertexAttribPointer = glad_debug_impl_glVertexAttribPointer;
PFNGLVERTEXATTRIBPOINTERARBPROC glad_glVertexAttribPointerARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glVertexAttribPointerARB", (GLADapiproc) glad_glVertexAttribPointerARB, 6, index, size, type, normalized, stride, pointer);
    glad_glVertexAttribPointerARB(index, size, type, normalized, stride, pointer);
    _post_call_gl_callback(NULL, "glVertexAttribPointerARB", (GLADapiproc) glad_glVertexAttribPointerARB, 6, index, size, type, normalized, stride, pointer);
    
}
PFNGLVERTEXATTRIBPOINTERARBPROC glad_debug_glVertexAttribPointerARB = glad_debug_impl_glVertexAttribPointerARB;
PFNGLVERTEXATTRIBPOINTERNVPROC glad_glVertexAttribPointerNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribPointerNV(GLuint index, GLint fsize, GLenum type, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glVertexAttribPointerNV", (GLADapiproc) glad_glVertexAttribPointerNV, 5, index, fsize, type, stride, pointer);
    glad_glVertexAttribPointerNV(index, fsize, type, stride, pointer);
    _post_call_gl_callback(NULL, "glVertexAttribPointerNV", (GLADapiproc) glad_glVertexAttribPointerNV, 5, index, fsize, type, stride, pointer);
    
}
PFNGLVERTEXATTRIBPOINTERNVPROC glad_debug_glVertexAttribPointerNV = glad_debug_impl_glVertexAttribPointerNV;
PFNGLVERTEXATTRIBS1DVNVPROC glad_glVertexAttribs1dvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs1dvNV(GLuint index, GLsizei count, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttribs1dvNV", (GLADapiproc) glad_glVertexAttribs1dvNV, 3, index, count, v);
    glad_glVertexAttribs1dvNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs1dvNV", (GLADapiproc) glad_glVertexAttribs1dvNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS1DVNVPROC glad_debug_glVertexAttribs1dvNV = glad_debug_impl_glVertexAttribs1dvNV;
PFNGLVERTEXATTRIBS1FVNVPROC glad_glVertexAttribs1fvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs1fvNV(GLuint index, GLsizei count, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttribs1fvNV", (GLADapiproc) glad_glVertexAttribs1fvNV, 3, index, count, v);
    glad_glVertexAttribs1fvNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs1fvNV", (GLADapiproc) glad_glVertexAttribs1fvNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS1FVNVPROC glad_debug_glVertexAttribs1fvNV = glad_debug_impl_glVertexAttribs1fvNV;
PFNGLVERTEXATTRIBS1SVNVPROC glad_glVertexAttribs1svNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs1svNV(GLuint index, GLsizei count, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttribs1svNV", (GLADapiproc) glad_glVertexAttribs1svNV, 3, index, count, v);
    glad_glVertexAttribs1svNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs1svNV", (GLADapiproc) glad_glVertexAttribs1svNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS1SVNVPROC glad_debug_glVertexAttribs1svNV = glad_debug_impl_glVertexAttribs1svNV;
PFNGLVERTEXATTRIBS2DVNVPROC glad_glVertexAttribs2dvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs2dvNV(GLuint index, GLsizei count, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttribs2dvNV", (GLADapiproc) glad_glVertexAttribs2dvNV, 3, index, count, v);
    glad_glVertexAttribs2dvNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs2dvNV", (GLADapiproc) glad_glVertexAttribs2dvNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS2DVNVPROC glad_debug_glVertexAttribs2dvNV = glad_debug_impl_glVertexAttribs2dvNV;
PFNGLVERTEXATTRIBS2FVNVPROC glad_glVertexAttribs2fvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs2fvNV(GLuint index, GLsizei count, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttribs2fvNV", (GLADapiproc) glad_glVertexAttribs2fvNV, 3, index, count, v);
    glad_glVertexAttribs2fvNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs2fvNV", (GLADapiproc) glad_glVertexAttribs2fvNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS2FVNVPROC glad_debug_glVertexAttribs2fvNV = glad_debug_impl_glVertexAttribs2fvNV;
PFNGLVERTEXATTRIBS2SVNVPROC glad_glVertexAttribs2svNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs2svNV(GLuint index, GLsizei count, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttribs2svNV", (GLADapiproc) glad_glVertexAttribs2svNV, 3, index, count, v);
    glad_glVertexAttribs2svNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs2svNV", (GLADapiproc) glad_glVertexAttribs2svNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS2SVNVPROC glad_debug_glVertexAttribs2svNV = glad_debug_impl_glVertexAttribs2svNV;
PFNGLVERTEXATTRIBS3DVNVPROC glad_glVertexAttribs3dvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs3dvNV(GLuint index, GLsizei count, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttribs3dvNV", (GLADapiproc) glad_glVertexAttribs3dvNV, 3, index, count, v);
    glad_glVertexAttribs3dvNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs3dvNV", (GLADapiproc) glad_glVertexAttribs3dvNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS3DVNVPROC glad_debug_glVertexAttribs3dvNV = glad_debug_impl_glVertexAttribs3dvNV;
PFNGLVERTEXATTRIBS3FVNVPROC glad_glVertexAttribs3fvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs3fvNV(GLuint index, GLsizei count, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttribs3fvNV", (GLADapiproc) glad_glVertexAttribs3fvNV, 3, index, count, v);
    glad_glVertexAttribs3fvNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs3fvNV", (GLADapiproc) glad_glVertexAttribs3fvNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS3FVNVPROC glad_debug_glVertexAttribs3fvNV = glad_debug_impl_glVertexAttribs3fvNV;
PFNGLVERTEXATTRIBS3SVNVPROC glad_glVertexAttribs3svNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs3svNV(GLuint index, GLsizei count, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttribs3svNV", (GLADapiproc) glad_glVertexAttribs3svNV, 3, index, count, v);
    glad_glVertexAttribs3svNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs3svNV", (GLADapiproc) glad_glVertexAttribs3svNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS3SVNVPROC glad_debug_glVertexAttribs3svNV = glad_debug_impl_glVertexAttribs3svNV;
PFNGLVERTEXATTRIBS4DVNVPROC glad_glVertexAttribs4dvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs4dvNV(GLuint index, GLsizei count, const GLdouble * v) {
    _pre_call_gl_callback("glVertexAttribs4dvNV", (GLADapiproc) glad_glVertexAttribs4dvNV, 3, index, count, v);
    glad_glVertexAttribs4dvNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs4dvNV", (GLADapiproc) glad_glVertexAttribs4dvNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS4DVNVPROC glad_debug_glVertexAttribs4dvNV = glad_debug_impl_glVertexAttribs4dvNV;
PFNGLVERTEXATTRIBS4FVNVPROC glad_glVertexAttribs4fvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs4fvNV(GLuint index, GLsizei count, const GLfloat * v) {
    _pre_call_gl_callback("glVertexAttribs4fvNV", (GLADapiproc) glad_glVertexAttribs4fvNV, 3, index, count, v);
    glad_glVertexAttribs4fvNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs4fvNV", (GLADapiproc) glad_glVertexAttribs4fvNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS4FVNVPROC glad_debug_glVertexAttribs4fvNV = glad_debug_impl_glVertexAttribs4fvNV;
PFNGLVERTEXATTRIBS4SVNVPROC glad_glVertexAttribs4svNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs4svNV(GLuint index, GLsizei count, const GLshort * v) {
    _pre_call_gl_callback("glVertexAttribs4svNV", (GLADapiproc) glad_glVertexAttribs4svNV, 3, index, count, v);
    glad_glVertexAttribs4svNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs4svNV", (GLADapiproc) glad_glVertexAttribs4svNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS4SVNVPROC glad_debug_glVertexAttribs4svNV = glad_debug_impl_glVertexAttribs4svNV;
PFNGLVERTEXATTRIBS4UBVNVPROC glad_glVertexAttribs4ubvNV = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexAttribs4ubvNV(GLuint index, GLsizei count, const GLubyte * v) {
    _pre_call_gl_callback("glVertexAttribs4ubvNV", (GLADapiproc) glad_glVertexAttribs4ubvNV, 3, index, count, v);
    glad_glVertexAttribs4ubvNV(index, count, v);
    _post_call_gl_callback(NULL, "glVertexAttribs4ubvNV", (GLADapiproc) glad_glVertexAttribs4ubvNV, 3, index, count, v);
    
}
PFNGLVERTEXATTRIBS4UBVNVPROC glad_debug_glVertexAttribs4ubvNV = glad_debug_impl_glVertexAttribs4ubvNV;
PFNGLVERTEXPOINTERPROC glad_glVertexPointer = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
    _pre_call_gl_callback("glVertexPointer", (GLADapiproc) glad_glVertexPointer, 4, size, type, stride, pointer);
    glad_glVertexPointer(size, type, stride, pointer);
    _post_call_gl_callback(NULL, "glVertexPointer", (GLADapiproc) glad_glVertexPointer, 4, size, type, stride, pointer);
    
}
PFNGLVERTEXPOINTERPROC glad_debug_glVertexPointer = glad_debug_impl_glVertexPointer;
PFNGLVERTEXPOINTEREXTPROC glad_glVertexPointerEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_glVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer) {
    _pre_call_gl_callback("glVertexPointerEXT", (GLADapiproc) glad_glVertexPointerEXT, 5, size, type, stride, count, pointer);
    glad_glVertexPointerEXT(size, type, stride, count, pointer);
    _post_call_gl_callback(NULL, "glVertexPointerEXT", (GLADapiproc) glad_glVertexPointerEXT, 5, size, type, stride, count, pointer);
    
}
PFNGLVERTEXPOINTEREXTPROC glad_debug_glVertexPointerEXT = glad_debug_impl_glVertexPointerEXT;
PFNGLVIEWPORTPROC glad_glViewport = NULL;
static void GLAD_API_PTR glad_debug_impl_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    _pre_call_gl_callback("glViewport", (GLADapiproc) glad_glViewport, 4, x, y, width, height);
    glad_glViewport(x, y, width, height);
    _post_call_gl_callback(NULL, "glViewport", (GLADapiproc) glad_glViewport, 4, x, y, width, height);
    
}
PFNGLVIEWPORTPROC glad_debug_glViewport = glad_debug_impl_glViewport;
PFNGLWINDOWPOS2DPROC glad_glWindowPos2d = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2d(GLdouble x, GLdouble y) {
    _pre_call_gl_callback("glWindowPos2d", (GLADapiproc) glad_glWindowPos2d, 2, x, y);
    glad_glWindowPos2d(x, y);
    _post_call_gl_callback(NULL, "glWindowPos2d", (GLADapiproc) glad_glWindowPos2d, 2, x, y);
    
}
PFNGLWINDOWPOS2DPROC glad_debug_glWindowPos2d = glad_debug_impl_glWindowPos2d;
PFNGLWINDOWPOS2DARBPROC glad_glWindowPos2dARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2dARB(GLdouble x, GLdouble y) {
    _pre_call_gl_callback("glWindowPos2dARB", (GLADapiproc) glad_glWindowPos2dARB, 2, x, y);
    glad_glWindowPos2dARB(x, y);
    _post_call_gl_callback(NULL, "glWindowPos2dARB", (GLADapiproc) glad_glWindowPos2dARB, 2, x, y);
    
}
PFNGLWINDOWPOS2DARBPROC glad_debug_glWindowPos2dARB = glad_debug_impl_glWindowPos2dARB;
PFNGLWINDOWPOS2DMESAPROC glad_glWindowPos2dMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2dMESA(GLdouble x, GLdouble y) {
    _pre_call_gl_callback("glWindowPos2dMESA", (GLADapiproc) glad_glWindowPos2dMESA, 2, x, y);
    glad_glWindowPos2dMESA(x, y);
    _post_call_gl_callback(NULL, "glWindowPos2dMESA", (GLADapiproc) glad_glWindowPos2dMESA, 2, x, y);
    
}
PFNGLWINDOWPOS2DMESAPROC glad_debug_glWindowPos2dMESA = glad_debug_impl_glWindowPos2dMESA;
PFNGLWINDOWPOS2DVPROC glad_glWindowPos2dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2dv(const GLdouble * v) {
    _pre_call_gl_callback("glWindowPos2dv", (GLADapiproc) glad_glWindowPos2dv, 1, v);
    glad_glWindowPos2dv(v);
    _post_call_gl_callback(NULL, "glWindowPos2dv", (GLADapiproc) glad_glWindowPos2dv, 1, v);
    
}
PFNGLWINDOWPOS2DVPROC glad_debug_glWindowPos2dv = glad_debug_impl_glWindowPos2dv;
PFNGLWINDOWPOS2DVARBPROC glad_glWindowPos2dvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2dvARB(const GLdouble * v) {
    _pre_call_gl_callback("glWindowPos2dvARB", (GLADapiproc) glad_glWindowPos2dvARB, 1, v);
    glad_glWindowPos2dvARB(v);
    _post_call_gl_callback(NULL, "glWindowPos2dvARB", (GLADapiproc) glad_glWindowPos2dvARB, 1, v);
    
}
PFNGLWINDOWPOS2DVARBPROC glad_debug_glWindowPos2dvARB = glad_debug_impl_glWindowPos2dvARB;
PFNGLWINDOWPOS2DVMESAPROC glad_glWindowPos2dvMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2dvMESA(const GLdouble * v) {
    _pre_call_gl_callback("glWindowPos2dvMESA", (GLADapiproc) glad_glWindowPos2dvMESA, 1, v);
    glad_glWindowPos2dvMESA(v);
    _post_call_gl_callback(NULL, "glWindowPos2dvMESA", (GLADapiproc) glad_glWindowPos2dvMESA, 1, v);
    
}
PFNGLWINDOWPOS2DVMESAPROC glad_debug_glWindowPos2dvMESA = glad_debug_impl_glWindowPos2dvMESA;
PFNGLWINDOWPOS2FPROC glad_glWindowPos2f = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2f(GLfloat x, GLfloat y) {
    _pre_call_gl_callback("glWindowPos2f", (GLADapiproc) glad_glWindowPos2f, 2, x, y);
    glad_glWindowPos2f(x, y);
    _post_call_gl_callback(NULL, "glWindowPos2f", (GLADapiproc) glad_glWindowPos2f, 2, x, y);
    
}
PFNGLWINDOWPOS2FPROC glad_debug_glWindowPos2f = glad_debug_impl_glWindowPos2f;
PFNGLWINDOWPOS2FARBPROC glad_glWindowPos2fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2fARB(GLfloat x, GLfloat y) {
    _pre_call_gl_callback("glWindowPos2fARB", (GLADapiproc) glad_glWindowPos2fARB, 2, x, y);
    glad_glWindowPos2fARB(x, y);
    _post_call_gl_callback(NULL, "glWindowPos2fARB", (GLADapiproc) glad_glWindowPos2fARB, 2, x, y);
    
}
PFNGLWINDOWPOS2FARBPROC glad_debug_glWindowPos2fARB = glad_debug_impl_glWindowPos2fARB;
PFNGLWINDOWPOS2FMESAPROC glad_glWindowPos2fMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2fMESA(GLfloat x, GLfloat y) {
    _pre_call_gl_callback("glWindowPos2fMESA", (GLADapiproc) glad_glWindowPos2fMESA, 2, x, y);
    glad_glWindowPos2fMESA(x, y);
    _post_call_gl_callback(NULL, "glWindowPos2fMESA", (GLADapiproc) glad_glWindowPos2fMESA, 2, x, y);
    
}
PFNGLWINDOWPOS2FMESAPROC glad_debug_glWindowPos2fMESA = glad_debug_impl_glWindowPos2fMESA;
PFNGLWINDOWPOS2FVPROC glad_glWindowPos2fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2fv(const GLfloat * v) {
    _pre_call_gl_callback("glWindowPos2fv", (GLADapiproc) glad_glWindowPos2fv, 1, v);
    glad_glWindowPos2fv(v);
    _post_call_gl_callback(NULL, "glWindowPos2fv", (GLADapiproc) glad_glWindowPos2fv, 1, v);
    
}
PFNGLWINDOWPOS2FVPROC glad_debug_glWindowPos2fv = glad_debug_impl_glWindowPos2fv;
PFNGLWINDOWPOS2FVARBPROC glad_glWindowPos2fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2fvARB(const GLfloat * v) {
    _pre_call_gl_callback("glWindowPos2fvARB", (GLADapiproc) glad_glWindowPos2fvARB, 1, v);
    glad_glWindowPos2fvARB(v);
    _post_call_gl_callback(NULL, "glWindowPos2fvARB", (GLADapiproc) glad_glWindowPos2fvARB, 1, v);
    
}
PFNGLWINDOWPOS2FVARBPROC glad_debug_glWindowPos2fvARB = glad_debug_impl_glWindowPos2fvARB;
PFNGLWINDOWPOS2FVMESAPROC glad_glWindowPos2fvMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2fvMESA(const GLfloat * v) {
    _pre_call_gl_callback("glWindowPos2fvMESA", (GLADapiproc) glad_glWindowPos2fvMESA, 1, v);
    glad_glWindowPos2fvMESA(v);
    _post_call_gl_callback(NULL, "glWindowPos2fvMESA", (GLADapiproc) glad_glWindowPos2fvMESA, 1, v);
    
}
PFNGLWINDOWPOS2FVMESAPROC glad_debug_glWindowPos2fvMESA = glad_debug_impl_glWindowPos2fvMESA;
PFNGLWINDOWPOS2IPROC glad_glWindowPos2i = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2i(GLint x, GLint y) {
    _pre_call_gl_callback("glWindowPos2i", (GLADapiproc) glad_glWindowPos2i, 2, x, y);
    glad_glWindowPos2i(x, y);
    _post_call_gl_callback(NULL, "glWindowPos2i", (GLADapiproc) glad_glWindowPos2i, 2, x, y);
    
}
PFNGLWINDOWPOS2IPROC glad_debug_glWindowPos2i = glad_debug_impl_glWindowPos2i;
PFNGLWINDOWPOS2IARBPROC glad_glWindowPos2iARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2iARB(GLint x, GLint y) {
    _pre_call_gl_callback("glWindowPos2iARB", (GLADapiproc) glad_glWindowPos2iARB, 2, x, y);
    glad_glWindowPos2iARB(x, y);
    _post_call_gl_callback(NULL, "glWindowPos2iARB", (GLADapiproc) glad_glWindowPos2iARB, 2, x, y);
    
}
PFNGLWINDOWPOS2IARBPROC glad_debug_glWindowPos2iARB = glad_debug_impl_glWindowPos2iARB;
PFNGLWINDOWPOS2IMESAPROC glad_glWindowPos2iMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2iMESA(GLint x, GLint y) {
    _pre_call_gl_callback("glWindowPos2iMESA", (GLADapiproc) glad_glWindowPos2iMESA, 2, x, y);
    glad_glWindowPos2iMESA(x, y);
    _post_call_gl_callback(NULL, "glWindowPos2iMESA", (GLADapiproc) glad_glWindowPos2iMESA, 2, x, y);
    
}
PFNGLWINDOWPOS2IMESAPROC glad_debug_glWindowPos2iMESA = glad_debug_impl_glWindowPos2iMESA;
PFNGLWINDOWPOS2IVPROC glad_glWindowPos2iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2iv(const GLint * v) {
    _pre_call_gl_callback("glWindowPos2iv", (GLADapiproc) glad_glWindowPos2iv, 1, v);
    glad_glWindowPos2iv(v);
    _post_call_gl_callback(NULL, "glWindowPos2iv", (GLADapiproc) glad_glWindowPos2iv, 1, v);
    
}
PFNGLWINDOWPOS2IVPROC glad_debug_glWindowPos2iv = glad_debug_impl_glWindowPos2iv;
PFNGLWINDOWPOS2IVARBPROC glad_glWindowPos2ivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2ivARB(const GLint * v) {
    _pre_call_gl_callback("glWindowPos2ivARB", (GLADapiproc) glad_glWindowPos2ivARB, 1, v);
    glad_glWindowPos2ivARB(v);
    _post_call_gl_callback(NULL, "glWindowPos2ivARB", (GLADapiproc) glad_glWindowPos2ivARB, 1, v);
    
}
PFNGLWINDOWPOS2IVARBPROC glad_debug_glWindowPos2ivARB = glad_debug_impl_glWindowPos2ivARB;
PFNGLWINDOWPOS2IVMESAPROC glad_glWindowPos2ivMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2ivMESA(const GLint * v) {
    _pre_call_gl_callback("glWindowPos2ivMESA", (GLADapiproc) glad_glWindowPos2ivMESA, 1, v);
    glad_glWindowPos2ivMESA(v);
    _post_call_gl_callback(NULL, "glWindowPos2ivMESA", (GLADapiproc) glad_glWindowPos2ivMESA, 1, v);
    
}
PFNGLWINDOWPOS2IVMESAPROC glad_debug_glWindowPos2ivMESA = glad_debug_impl_glWindowPos2ivMESA;
PFNGLWINDOWPOS2SPROC glad_glWindowPos2s = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2s(GLshort x, GLshort y) {
    _pre_call_gl_callback("glWindowPos2s", (GLADapiproc) glad_glWindowPos2s, 2, x, y);
    glad_glWindowPos2s(x, y);
    _post_call_gl_callback(NULL, "glWindowPos2s", (GLADapiproc) glad_glWindowPos2s, 2, x, y);
    
}
PFNGLWINDOWPOS2SPROC glad_debug_glWindowPos2s = glad_debug_impl_glWindowPos2s;
PFNGLWINDOWPOS2SARBPROC glad_glWindowPos2sARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2sARB(GLshort x, GLshort y) {
    _pre_call_gl_callback("glWindowPos2sARB", (GLADapiproc) glad_glWindowPos2sARB, 2, x, y);
    glad_glWindowPos2sARB(x, y);
    _post_call_gl_callback(NULL, "glWindowPos2sARB", (GLADapiproc) glad_glWindowPos2sARB, 2, x, y);
    
}
PFNGLWINDOWPOS2SARBPROC glad_debug_glWindowPos2sARB = glad_debug_impl_glWindowPos2sARB;
PFNGLWINDOWPOS2SMESAPROC glad_glWindowPos2sMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2sMESA(GLshort x, GLshort y) {
    _pre_call_gl_callback("glWindowPos2sMESA", (GLADapiproc) glad_glWindowPos2sMESA, 2, x, y);
    glad_glWindowPos2sMESA(x, y);
    _post_call_gl_callback(NULL, "glWindowPos2sMESA", (GLADapiproc) glad_glWindowPos2sMESA, 2, x, y);
    
}
PFNGLWINDOWPOS2SMESAPROC glad_debug_glWindowPos2sMESA = glad_debug_impl_glWindowPos2sMESA;
PFNGLWINDOWPOS2SVPROC glad_glWindowPos2sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2sv(const GLshort * v) {
    _pre_call_gl_callback("glWindowPos2sv", (GLADapiproc) glad_glWindowPos2sv, 1, v);
    glad_glWindowPos2sv(v);
    _post_call_gl_callback(NULL, "glWindowPos2sv", (GLADapiproc) glad_glWindowPos2sv, 1, v);
    
}
PFNGLWINDOWPOS2SVPROC glad_debug_glWindowPos2sv = glad_debug_impl_glWindowPos2sv;
PFNGLWINDOWPOS2SVARBPROC glad_glWindowPos2svARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2svARB(const GLshort * v) {
    _pre_call_gl_callback("glWindowPos2svARB", (GLADapiproc) glad_glWindowPos2svARB, 1, v);
    glad_glWindowPos2svARB(v);
    _post_call_gl_callback(NULL, "glWindowPos2svARB", (GLADapiproc) glad_glWindowPos2svARB, 1, v);
    
}
PFNGLWINDOWPOS2SVARBPROC glad_debug_glWindowPos2svARB = glad_debug_impl_glWindowPos2svARB;
PFNGLWINDOWPOS2SVMESAPROC glad_glWindowPos2svMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos2svMESA(const GLshort * v) {
    _pre_call_gl_callback("glWindowPos2svMESA", (GLADapiproc) glad_glWindowPos2svMESA, 1, v);
    glad_glWindowPos2svMESA(v);
    _post_call_gl_callback(NULL, "glWindowPos2svMESA", (GLADapiproc) glad_glWindowPos2svMESA, 1, v);
    
}
PFNGLWINDOWPOS2SVMESAPROC glad_debug_glWindowPos2svMESA = glad_debug_impl_glWindowPos2svMESA;
PFNGLWINDOWPOS3DPROC glad_glWindowPos3d = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) {
    _pre_call_gl_callback("glWindowPos3d", (GLADapiproc) glad_glWindowPos3d, 3, x, y, z);
    glad_glWindowPos3d(x, y, z);
    _post_call_gl_callback(NULL, "glWindowPos3d", (GLADapiproc) glad_glWindowPos3d, 3, x, y, z);
    
}
PFNGLWINDOWPOS3DPROC glad_debug_glWindowPos3d = glad_debug_impl_glWindowPos3d;
PFNGLWINDOWPOS3DARBPROC glad_glWindowPos3dARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z) {
    _pre_call_gl_callback("glWindowPos3dARB", (GLADapiproc) glad_glWindowPos3dARB, 3, x, y, z);
    glad_glWindowPos3dARB(x, y, z);
    _post_call_gl_callback(NULL, "glWindowPos3dARB", (GLADapiproc) glad_glWindowPos3dARB, 3, x, y, z);
    
}
PFNGLWINDOWPOS3DARBPROC glad_debug_glWindowPos3dARB = glad_debug_impl_glWindowPos3dARB;
PFNGLWINDOWPOS3DMESAPROC glad_glWindowPos3dMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3dMESA(GLdouble x, GLdouble y, GLdouble z) {
    _pre_call_gl_callback("glWindowPos3dMESA", (GLADapiproc) glad_glWindowPos3dMESA, 3, x, y, z);
    glad_glWindowPos3dMESA(x, y, z);
    _post_call_gl_callback(NULL, "glWindowPos3dMESA", (GLADapiproc) glad_glWindowPos3dMESA, 3, x, y, z);
    
}
PFNGLWINDOWPOS3DMESAPROC glad_debug_glWindowPos3dMESA = glad_debug_impl_glWindowPos3dMESA;
PFNGLWINDOWPOS3DVPROC glad_glWindowPos3dv = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3dv(const GLdouble * v) {
    _pre_call_gl_callback("glWindowPos3dv", (GLADapiproc) glad_glWindowPos3dv, 1, v);
    glad_glWindowPos3dv(v);
    _post_call_gl_callback(NULL, "glWindowPos3dv", (GLADapiproc) glad_glWindowPos3dv, 1, v);
    
}
PFNGLWINDOWPOS3DVPROC glad_debug_glWindowPos3dv = glad_debug_impl_glWindowPos3dv;
PFNGLWINDOWPOS3DVARBPROC glad_glWindowPos3dvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3dvARB(const GLdouble * v) {
    _pre_call_gl_callback("glWindowPos3dvARB", (GLADapiproc) glad_glWindowPos3dvARB, 1, v);
    glad_glWindowPos3dvARB(v);
    _post_call_gl_callback(NULL, "glWindowPos3dvARB", (GLADapiproc) glad_glWindowPos3dvARB, 1, v);
    
}
PFNGLWINDOWPOS3DVARBPROC glad_debug_glWindowPos3dvARB = glad_debug_impl_glWindowPos3dvARB;
PFNGLWINDOWPOS3DVMESAPROC glad_glWindowPos3dvMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3dvMESA(const GLdouble * v) {
    _pre_call_gl_callback("glWindowPos3dvMESA", (GLADapiproc) glad_glWindowPos3dvMESA, 1, v);
    glad_glWindowPos3dvMESA(v);
    _post_call_gl_callback(NULL, "glWindowPos3dvMESA", (GLADapiproc) glad_glWindowPos3dvMESA, 1, v);
    
}
PFNGLWINDOWPOS3DVMESAPROC glad_debug_glWindowPos3dvMESA = glad_debug_impl_glWindowPos3dvMESA;
PFNGLWINDOWPOS3FPROC glad_glWindowPos3f = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
    _pre_call_gl_callback("glWindowPos3f", (GLADapiproc) glad_glWindowPos3f, 3, x, y, z);
    glad_glWindowPos3f(x, y, z);
    _post_call_gl_callback(NULL, "glWindowPos3f", (GLADapiproc) glad_glWindowPos3f, 3, x, y, z);
    
}
PFNGLWINDOWPOS3FPROC glad_debug_glWindowPos3f = glad_debug_impl_glWindowPos3f;
PFNGLWINDOWPOS3FARBPROC glad_glWindowPos3fARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z) {
    _pre_call_gl_callback("glWindowPos3fARB", (GLADapiproc) glad_glWindowPos3fARB, 3, x, y, z);
    glad_glWindowPos3fARB(x, y, z);
    _post_call_gl_callback(NULL, "glWindowPos3fARB", (GLADapiproc) glad_glWindowPos3fARB, 3, x, y, z);
    
}
PFNGLWINDOWPOS3FARBPROC glad_debug_glWindowPos3fARB = glad_debug_impl_glWindowPos3fARB;
PFNGLWINDOWPOS3FMESAPROC glad_glWindowPos3fMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3fMESA(GLfloat x, GLfloat y, GLfloat z) {
    _pre_call_gl_callback("glWindowPos3fMESA", (GLADapiproc) glad_glWindowPos3fMESA, 3, x, y, z);
    glad_glWindowPos3fMESA(x, y, z);
    _post_call_gl_callback(NULL, "glWindowPos3fMESA", (GLADapiproc) glad_glWindowPos3fMESA, 3, x, y, z);
    
}
PFNGLWINDOWPOS3FMESAPROC glad_debug_glWindowPos3fMESA = glad_debug_impl_glWindowPos3fMESA;
PFNGLWINDOWPOS3FVPROC glad_glWindowPos3fv = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3fv(const GLfloat * v) {
    _pre_call_gl_callback("glWindowPos3fv", (GLADapiproc) glad_glWindowPos3fv, 1, v);
    glad_glWindowPos3fv(v);
    _post_call_gl_callback(NULL, "glWindowPos3fv", (GLADapiproc) glad_glWindowPos3fv, 1, v);
    
}
PFNGLWINDOWPOS3FVPROC glad_debug_glWindowPos3fv = glad_debug_impl_glWindowPos3fv;
PFNGLWINDOWPOS3FVARBPROC glad_glWindowPos3fvARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3fvARB(const GLfloat * v) {
    _pre_call_gl_callback("glWindowPos3fvARB", (GLADapiproc) glad_glWindowPos3fvARB, 1, v);
    glad_glWindowPos3fvARB(v);
    _post_call_gl_callback(NULL, "glWindowPos3fvARB", (GLADapiproc) glad_glWindowPos3fvARB, 1, v);
    
}
PFNGLWINDOWPOS3FVARBPROC glad_debug_glWindowPos3fvARB = glad_debug_impl_glWindowPos3fvARB;
PFNGLWINDOWPOS3FVMESAPROC glad_glWindowPos3fvMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3fvMESA(const GLfloat * v) {
    _pre_call_gl_callback("glWindowPos3fvMESA", (GLADapiproc) glad_glWindowPos3fvMESA, 1, v);
    glad_glWindowPos3fvMESA(v);
    _post_call_gl_callback(NULL, "glWindowPos3fvMESA", (GLADapiproc) glad_glWindowPos3fvMESA, 1, v);
    
}
PFNGLWINDOWPOS3FVMESAPROC glad_debug_glWindowPos3fvMESA = glad_debug_impl_glWindowPos3fvMESA;
PFNGLWINDOWPOS3IPROC glad_glWindowPos3i = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3i(GLint x, GLint y, GLint z) {
    _pre_call_gl_callback("glWindowPos3i", (GLADapiproc) glad_glWindowPos3i, 3, x, y, z);
    glad_glWindowPos3i(x, y, z);
    _post_call_gl_callback(NULL, "glWindowPos3i", (GLADapiproc) glad_glWindowPos3i, 3, x, y, z);
    
}
PFNGLWINDOWPOS3IPROC glad_debug_glWindowPos3i = glad_debug_impl_glWindowPos3i;
PFNGLWINDOWPOS3IARBPROC glad_glWindowPos3iARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3iARB(GLint x, GLint y, GLint z) {
    _pre_call_gl_callback("glWindowPos3iARB", (GLADapiproc) glad_glWindowPos3iARB, 3, x, y, z);
    glad_glWindowPos3iARB(x, y, z);
    _post_call_gl_callback(NULL, "glWindowPos3iARB", (GLADapiproc) glad_glWindowPos3iARB, 3, x, y, z);
    
}
PFNGLWINDOWPOS3IARBPROC glad_debug_glWindowPos3iARB = glad_debug_impl_glWindowPos3iARB;
PFNGLWINDOWPOS3IMESAPROC glad_glWindowPos3iMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3iMESA(GLint x, GLint y, GLint z) {
    _pre_call_gl_callback("glWindowPos3iMESA", (GLADapiproc) glad_glWindowPos3iMESA, 3, x, y, z);
    glad_glWindowPos3iMESA(x, y, z);
    _post_call_gl_callback(NULL, "glWindowPos3iMESA", (GLADapiproc) glad_glWindowPos3iMESA, 3, x, y, z);
    
}
PFNGLWINDOWPOS3IMESAPROC glad_debug_glWindowPos3iMESA = glad_debug_impl_glWindowPos3iMESA;
PFNGLWINDOWPOS3IVPROC glad_glWindowPos3iv = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3iv(const GLint * v) {
    _pre_call_gl_callback("glWindowPos3iv", (GLADapiproc) glad_glWindowPos3iv, 1, v);
    glad_glWindowPos3iv(v);
    _post_call_gl_callback(NULL, "glWindowPos3iv", (GLADapiproc) glad_glWindowPos3iv, 1, v);
    
}
PFNGLWINDOWPOS3IVPROC glad_debug_glWindowPos3iv = glad_debug_impl_glWindowPos3iv;
PFNGLWINDOWPOS3IVARBPROC glad_glWindowPos3ivARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3ivARB(const GLint * v) {
    _pre_call_gl_callback("glWindowPos3ivARB", (GLADapiproc) glad_glWindowPos3ivARB, 1, v);
    glad_glWindowPos3ivARB(v);
    _post_call_gl_callback(NULL, "glWindowPos3ivARB", (GLADapiproc) glad_glWindowPos3ivARB, 1, v);
    
}
PFNGLWINDOWPOS3IVARBPROC glad_debug_glWindowPos3ivARB = glad_debug_impl_glWindowPos3ivARB;
PFNGLWINDOWPOS3IVMESAPROC glad_glWindowPos3ivMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3ivMESA(const GLint * v) {
    _pre_call_gl_callback("glWindowPos3ivMESA", (GLADapiproc) glad_glWindowPos3ivMESA, 1, v);
    glad_glWindowPos3ivMESA(v);
    _post_call_gl_callback(NULL, "glWindowPos3ivMESA", (GLADapiproc) glad_glWindowPos3ivMESA, 1, v);
    
}
PFNGLWINDOWPOS3IVMESAPROC glad_debug_glWindowPos3ivMESA = glad_debug_impl_glWindowPos3ivMESA;
PFNGLWINDOWPOS3SPROC glad_glWindowPos3s = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3s(GLshort x, GLshort y, GLshort z) {
    _pre_call_gl_callback("glWindowPos3s", (GLADapiproc) glad_glWindowPos3s, 3, x, y, z);
    glad_glWindowPos3s(x, y, z);
    _post_call_gl_callback(NULL, "glWindowPos3s", (GLADapiproc) glad_glWindowPos3s, 3, x, y, z);
    
}
PFNGLWINDOWPOS3SPROC glad_debug_glWindowPos3s = glad_debug_impl_glWindowPos3s;
PFNGLWINDOWPOS3SARBPROC glad_glWindowPos3sARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3sARB(GLshort x, GLshort y, GLshort z) {
    _pre_call_gl_callback("glWindowPos3sARB", (GLADapiproc) glad_glWindowPos3sARB, 3, x, y, z);
    glad_glWindowPos3sARB(x, y, z);
    _post_call_gl_callback(NULL, "glWindowPos3sARB", (GLADapiproc) glad_glWindowPos3sARB, 3, x, y, z);
    
}
PFNGLWINDOWPOS3SARBPROC glad_debug_glWindowPos3sARB = glad_debug_impl_glWindowPos3sARB;
PFNGLWINDOWPOS3SMESAPROC glad_glWindowPos3sMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3sMESA(GLshort x, GLshort y, GLshort z) {
    _pre_call_gl_callback("glWindowPos3sMESA", (GLADapiproc) glad_glWindowPos3sMESA, 3, x, y, z);
    glad_glWindowPos3sMESA(x, y, z);
    _post_call_gl_callback(NULL, "glWindowPos3sMESA", (GLADapiproc) glad_glWindowPos3sMESA, 3, x, y, z);
    
}
PFNGLWINDOWPOS3SMESAPROC glad_debug_glWindowPos3sMESA = glad_debug_impl_glWindowPos3sMESA;
PFNGLWINDOWPOS3SVPROC glad_glWindowPos3sv = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3sv(const GLshort * v) {
    _pre_call_gl_callback("glWindowPos3sv", (GLADapiproc) glad_glWindowPos3sv, 1, v);
    glad_glWindowPos3sv(v);
    _post_call_gl_callback(NULL, "glWindowPos3sv", (GLADapiproc) glad_glWindowPos3sv, 1, v);
    
}
PFNGLWINDOWPOS3SVPROC glad_debug_glWindowPos3sv = glad_debug_impl_glWindowPos3sv;
PFNGLWINDOWPOS3SVARBPROC glad_glWindowPos3svARB = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3svARB(const GLshort * v) {
    _pre_call_gl_callback("glWindowPos3svARB", (GLADapiproc) glad_glWindowPos3svARB, 1, v);
    glad_glWindowPos3svARB(v);
    _post_call_gl_callback(NULL, "glWindowPos3svARB", (GLADapiproc) glad_glWindowPos3svARB, 1, v);
    
}
PFNGLWINDOWPOS3SVARBPROC glad_debug_glWindowPos3svARB = glad_debug_impl_glWindowPos3svARB;
PFNGLWINDOWPOS3SVMESAPROC glad_glWindowPos3svMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos3svMESA(const GLshort * v) {
    _pre_call_gl_callback("glWindowPos3svMESA", (GLADapiproc) glad_glWindowPos3svMESA, 1, v);
    glad_glWindowPos3svMESA(v);
    _post_call_gl_callback(NULL, "glWindowPos3svMESA", (GLADapiproc) glad_glWindowPos3svMESA, 1, v);
    
}
PFNGLWINDOWPOS3SVMESAPROC glad_debug_glWindowPos3svMESA = glad_debug_impl_glWindowPos3svMESA;
PFNGLWINDOWPOS4DMESAPROC glad_glWindowPos4dMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos4dMESA(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    _pre_call_gl_callback("glWindowPos4dMESA", (GLADapiproc) glad_glWindowPos4dMESA, 4, x, y, z, w);
    glad_glWindowPos4dMESA(x, y, z, w);
    _post_call_gl_callback(NULL, "glWindowPos4dMESA", (GLADapiproc) glad_glWindowPos4dMESA, 4, x, y, z, w);
    
}
PFNGLWINDOWPOS4DMESAPROC glad_debug_glWindowPos4dMESA = glad_debug_impl_glWindowPos4dMESA;
PFNGLWINDOWPOS4DVMESAPROC glad_glWindowPos4dvMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos4dvMESA(const GLdouble * v) {
    _pre_call_gl_callback("glWindowPos4dvMESA", (GLADapiproc) glad_glWindowPos4dvMESA, 1, v);
    glad_glWindowPos4dvMESA(v);
    _post_call_gl_callback(NULL, "glWindowPos4dvMESA", (GLADapiproc) glad_glWindowPos4dvMESA, 1, v);
    
}
PFNGLWINDOWPOS4DVMESAPROC glad_debug_glWindowPos4dvMESA = glad_debug_impl_glWindowPos4dvMESA;
PFNGLWINDOWPOS4FMESAPROC glad_glWindowPos4fMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos4fMESA(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _pre_call_gl_callback("glWindowPos4fMESA", (GLADapiproc) glad_glWindowPos4fMESA, 4, x, y, z, w);
    glad_glWindowPos4fMESA(x, y, z, w);
    _post_call_gl_callback(NULL, "glWindowPos4fMESA", (GLADapiproc) glad_glWindowPos4fMESA, 4, x, y, z, w);
    
}
PFNGLWINDOWPOS4FMESAPROC glad_debug_glWindowPos4fMESA = glad_debug_impl_glWindowPos4fMESA;
PFNGLWINDOWPOS4FVMESAPROC glad_glWindowPos4fvMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos4fvMESA(const GLfloat * v) {
    _pre_call_gl_callback("glWindowPos4fvMESA", (GLADapiproc) glad_glWindowPos4fvMESA, 1, v);
    glad_glWindowPos4fvMESA(v);
    _post_call_gl_callback(NULL, "glWindowPos4fvMESA", (GLADapiproc) glad_glWindowPos4fvMESA, 1, v);
    
}
PFNGLWINDOWPOS4FVMESAPROC glad_debug_glWindowPos4fvMESA = glad_debug_impl_glWindowPos4fvMESA;
PFNGLWINDOWPOS4IMESAPROC glad_glWindowPos4iMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos4iMESA(GLint x, GLint y, GLint z, GLint w) {
    _pre_call_gl_callback("glWindowPos4iMESA", (GLADapiproc) glad_glWindowPos4iMESA, 4, x, y, z, w);
    glad_glWindowPos4iMESA(x, y, z, w);
    _post_call_gl_callback(NULL, "glWindowPos4iMESA", (GLADapiproc) glad_glWindowPos4iMESA, 4, x, y, z, w);
    
}
PFNGLWINDOWPOS4IMESAPROC glad_debug_glWindowPos4iMESA = glad_debug_impl_glWindowPos4iMESA;
PFNGLWINDOWPOS4IVMESAPROC glad_glWindowPos4ivMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos4ivMESA(const GLint * v) {
    _pre_call_gl_callback("glWindowPos4ivMESA", (GLADapiproc) glad_glWindowPos4ivMESA, 1, v);
    glad_glWindowPos4ivMESA(v);
    _post_call_gl_callback(NULL, "glWindowPos4ivMESA", (GLADapiproc) glad_glWindowPos4ivMESA, 1, v);
    
}
PFNGLWINDOWPOS4IVMESAPROC glad_debug_glWindowPos4ivMESA = glad_debug_impl_glWindowPos4ivMESA;
PFNGLWINDOWPOS4SMESAPROC glad_glWindowPos4sMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos4sMESA(GLshort x, GLshort y, GLshort z, GLshort w) {
    _pre_call_gl_callback("glWindowPos4sMESA", (GLADapiproc) glad_glWindowPos4sMESA, 4, x, y, z, w);
    glad_glWindowPos4sMESA(x, y, z, w);
    _post_call_gl_callback(NULL, "glWindowPos4sMESA", (GLADapiproc) glad_glWindowPos4sMESA, 4, x, y, z, w);
    
}
PFNGLWINDOWPOS4SMESAPROC glad_debug_glWindowPos4sMESA = glad_debug_impl_glWindowPos4sMESA;
PFNGLWINDOWPOS4SVMESAPROC glad_glWindowPos4svMESA = NULL;
static void GLAD_API_PTR glad_debug_impl_glWindowPos4svMESA(const GLshort * v) {
    _pre_call_gl_callback("glWindowPos4svMESA", (GLADapiproc) glad_glWindowPos4svMESA, 1, v);
    glad_glWindowPos4svMESA(v);
    _post_call_gl_callback(NULL, "glWindowPos4svMESA", (GLADapiproc) glad_glWindowPos4svMESA, 1, v);
    
}
PFNGLWINDOWPOS4SVMESAPROC glad_debug_glWindowPos4svMESA = glad_debug_impl_glWindowPos4svMESA;


static void glad_gl_load_GL_VERSION_1_0( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_VERSION_1_0) return;
    glad_glAccum = (PFNGLACCUMPROC) load(userptr, "glAccum");
    glad_glAlphaFunc = (PFNGLALPHAFUNCPROC) load(userptr, "glAlphaFunc");
    glad_glBegin = (PFNGLBEGINPROC) load(userptr, "glBegin");
    glad_glBitmap = (PFNGLBITMAPPROC) load(userptr, "glBitmap");
    glad_glBlendFunc = (PFNGLBLENDFUNCPROC) load(userptr, "glBlendFunc");
    glad_glCallList = (PFNGLCALLLISTPROC) load(userptr, "glCallList");
    glad_glCallLists = (PFNGLCALLLISTSPROC) load(userptr, "glCallLists");
    glad_glClear = (PFNGLCLEARPROC) load(userptr, "glClear");
    glad_glClearAccum = (PFNGLCLEARACCUMPROC) load(userptr, "glClearAccum");
    glad_glClearColor = (PFNGLCLEARCOLORPROC) load(userptr, "glClearColor");
    glad_glClearDepth = (PFNGLCLEARDEPTHPROC) load(userptr, "glClearDepth");
    glad_glClearIndex = (PFNGLCLEARINDEXPROC) load(userptr, "glClearIndex");
    glad_glClearStencil = (PFNGLCLEARSTENCILPROC) load(userptr, "glClearStencil");
    glad_glClipPlane = (PFNGLCLIPPLANEPROC) load(userptr, "glClipPlane");
    glad_glColor3b = (PFNGLCOLOR3BPROC) load(userptr, "glColor3b");
    glad_glColor3bv = (PFNGLCOLOR3BVPROC) load(userptr, "glColor3bv");
    glad_glColor3d = (PFNGLCOLOR3DPROC) load(userptr, "glColor3d");
    glad_glColor3dv = (PFNGLCOLOR3DVPROC) load(userptr, "glColor3dv");
    glad_glColor3f = (PFNGLCOLOR3FPROC) load(userptr, "glColor3f");
    glad_glColor3fv = (PFNGLCOLOR3FVPROC) load(userptr, "glColor3fv");
    glad_glColor3i = (PFNGLCOLOR3IPROC) load(userptr, "glColor3i");
    glad_glColor3iv = (PFNGLCOLOR3IVPROC) load(userptr, "glColor3iv");
    glad_glColor3s = (PFNGLCOLOR3SPROC) load(userptr, "glColor3s");
    glad_glColor3sv = (PFNGLCOLOR3SVPROC) load(userptr, "glColor3sv");
    glad_glColor3ub = (PFNGLCOLOR3UBPROC) load(userptr, "glColor3ub");
    glad_glColor3ubv = (PFNGLCOLOR3UBVPROC) load(userptr, "glColor3ubv");
    glad_glColor3ui = (PFNGLCOLOR3UIPROC) load(userptr, "glColor3ui");
    glad_glColor3uiv = (PFNGLCOLOR3UIVPROC) load(userptr, "glColor3uiv");
    glad_glColor3us = (PFNGLCOLOR3USPROC) load(userptr, "glColor3us");
    glad_glColor3usv = (PFNGLCOLOR3USVPROC) load(userptr, "glColor3usv");
    glad_glColor4b = (PFNGLCOLOR4BPROC) load(userptr, "glColor4b");
    glad_glColor4bv = (PFNGLCOLOR4BVPROC) load(userptr, "glColor4bv");
    glad_glColor4d = (PFNGLCOLOR4DPROC) load(userptr, "glColor4d");
    glad_glColor4dv = (PFNGLCOLOR4DVPROC) load(userptr, "glColor4dv");
    glad_glColor4f = (PFNGLCOLOR4FPROC) load(userptr, "glColor4f");
    glad_glColor4fv = (PFNGLCOLOR4FVPROC) load(userptr, "glColor4fv");
    glad_glColor4i = (PFNGLCOLOR4IPROC) load(userptr, "glColor4i");
    glad_glColor4iv = (PFNGLCOLOR4IVPROC) load(userptr, "glColor4iv");
    glad_glColor4s = (PFNGLCOLOR4SPROC) load(userptr, "glColor4s");
    glad_glColor4sv = (PFNGLCOLOR4SVPROC) load(userptr, "glColor4sv");
    glad_glColor4ub = (PFNGLCOLOR4UBPROC) load(userptr, "glColor4ub");
    glad_glColor4ubv = (PFNGLCOLOR4UBVPROC) load(userptr, "glColor4ubv");
    glad_glColor4ui = (PFNGLCOLOR4UIPROC) load(userptr, "glColor4ui");
    glad_glColor4uiv = (PFNGLCOLOR4UIVPROC) load(userptr, "glColor4uiv");
    glad_glColor4us = (PFNGLCOLOR4USPROC) load(userptr, "glColor4us");
    glad_glColor4usv = (PFNGLCOLOR4USVPROC) load(userptr, "glColor4usv");
    glad_glColorMask = (PFNGLCOLORMASKPROC) load(userptr, "glColorMask");
    glad_glColorMaterial = (PFNGLCOLORMATERIALPROC) load(userptr, "glColorMaterial");
    glad_glCopyPixels = (PFNGLCOPYPIXELSPROC) load(userptr, "glCopyPixels");
    glad_glCullFace = (PFNGLCULLFACEPROC) load(userptr, "glCullFace");
    glad_glDeleteLists = (PFNGLDELETELISTSPROC) load(userptr, "glDeleteLists");
    glad_glDepthFunc = (PFNGLDEPTHFUNCPROC) load(userptr, "glDepthFunc");
    glad_glDepthMask = (PFNGLDEPTHMASKPROC) load(userptr, "glDepthMask");
    glad_glDepthRange = (PFNGLDEPTHRANGEPROC) load(userptr, "glDepthRange");
    glad_glDisable = (PFNGLDISABLEPROC) load(userptr, "glDisable");
    glad_glDrawBuffer = (PFNGLDRAWBUFFERPROC) load(userptr, "glDrawBuffer");
    glad_glDrawPixels = (PFNGLDRAWPIXELSPROC) load(userptr, "glDrawPixels");
    glad_glEdgeFlag = (PFNGLEDGEFLAGPROC) load(userptr, "glEdgeFlag");
    glad_glEdgeFlagv = (PFNGLEDGEFLAGVPROC) load(userptr, "glEdgeFlagv");
    glad_glEnable = (PFNGLENABLEPROC) load(userptr, "glEnable");
    glad_glEnd = (PFNGLENDPROC) load(userptr, "glEnd");
    glad_glEndList = (PFNGLENDLISTPROC) load(userptr, "glEndList");
    glad_glEvalCoord1d = (PFNGLEVALCOORD1DPROC) load(userptr, "glEvalCoord1d");
    glad_glEvalCoord1dv = (PFNGLEVALCOORD1DVPROC) load(userptr, "glEvalCoord1dv");
    glad_glEvalCoord1f = (PFNGLEVALCOORD1FPROC) load(userptr, "glEvalCoord1f");
    glad_glEvalCoord1fv = (PFNGLEVALCOORD1FVPROC) load(userptr, "glEvalCoord1fv");
    glad_glEvalCoord2d = (PFNGLEVALCOORD2DPROC) load(userptr, "glEvalCoord2d");
    glad_glEvalCoord2dv = (PFNGLEVALCOORD2DVPROC) load(userptr, "glEvalCoord2dv");
    glad_glEvalCoord2f = (PFNGLEVALCOORD2FPROC) load(userptr, "glEvalCoord2f");
    glad_glEvalCoord2fv = (PFNGLEVALCOORD2FVPROC) load(userptr, "glEvalCoord2fv");
    glad_glEvalMesh1 = (PFNGLEVALMESH1PROC) load(userptr, "glEvalMesh1");
    glad_glEvalMesh2 = (PFNGLEVALMESH2PROC) load(userptr, "glEvalMesh2");
    glad_glEvalPoint1 = (PFNGLEVALPOINT1PROC) load(userptr, "glEvalPoint1");
    glad_glEvalPoint2 = (PFNGLEVALPOINT2PROC) load(userptr, "glEvalPoint2");
    glad_glFeedbackBuffer = (PFNGLFEEDBACKBUFFERPROC) load(userptr, "glFeedbackBuffer");
    glad_glFinish = (PFNGLFINISHPROC) load(userptr, "glFinish");
    glad_glFlush = (PFNGLFLUSHPROC) load(userptr, "glFlush");
    glad_glFogf = (PFNGLFOGFPROC) load(userptr, "glFogf");
    glad_glFogfv = (PFNGLFOGFVPROC) load(userptr, "glFogfv");
    glad_glFogi = (PFNGLFOGIPROC) load(userptr, "glFogi");
    glad_glFogiv = (PFNGLFOGIVPROC) load(userptr, "glFogiv");
    glad_glFrontFace = (PFNGLFRONTFACEPROC) load(userptr, "glFrontFace");
    glad_glFrustum = (PFNGLFRUSTUMPROC) load(userptr, "glFrustum");
    glad_glGenLists = (PFNGLGENLISTSPROC) load(userptr, "glGenLists");
    glad_glGetBooleanv = (PFNGLGETBOOLEANVPROC) load(userptr, "glGetBooleanv");
    glad_glGetClipPlane = (PFNGLGETCLIPPLANEPROC) load(userptr, "glGetClipPlane");
    glad_glGetDoublev = (PFNGLGETDOUBLEVPROC) load(userptr, "glGetDoublev");
    glad_glGetError = (PFNGLGETERRORPROC) load(userptr, "glGetError");
    glad_glGetFloatv = (PFNGLGETFLOATVPROC) load(userptr, "glGetFloatv");
    glad_glGetIntegerv = (PFNGLGETINTEGERVPROC) load(userptr, "glGetIntegerv");
    glad_glGetLightfv = (PFNGLGETLIGHTFVPROC) load(userptr, "glGetLightfv");
    glad_glGetLightiv = (PFNGLGETLIGHTIVPROC) load(userptr, "glGetLightiv");
    glad_glGetMapdv = (PFNGLGETMAPDVPROC) load(userptr, "glGetMapdv");
    glad_glGetMapfv = (PFNGLGETMAPFVPROC) load(userptr, "glGetMapfv");
    glad_glGetMapiv = (PFNGLGETMAPIVPROC) load(userptr, "glGetMapiv");
    glad_glGetMaterialfv = (PFNGLGETMATERIALFVPROC) load(userptr, "glGetMaterialfv");
    glad_glGetMaterialiv = (PFNGLGETMATERIALIVPROC) load(userptr, "glGetMaterialiv");
    glad_glGetPixelMapfv = (PFNGLGETPIXELMAPFVPROC) load(userptr, "glGetPixelMapfv");
    glad_glGetPixelMapuiv = (PFNGLGETPIXELMAPUIVPROC) load(userptr, "glGetPixelMapuiv");
    glad_glGetPixelMapusv = (PFNGLGETPIXELMAPUSVPROC) load(userptr, "glGetPixelMapusv");
    glad_glGetPolygonStipple = (PFNGLGETPOLYGONSTIPPLEPROC) load(userptr, "glGetPolygonStipple");
    glad_glGetString = (PFNGLGETSTRINGPROC) load(userptr, "glGetString");
    glad_glGetTexEnvfv = (PFNGLGETTEXENVFVPROC) load(userptr, "glGetTexEnvfv");
    glad_glGetTexEnviv = (PFNGLGETTEXENVIVPROC) load(userptr, "glGetTexEnviv");
    glad_glGetTexGendv = (PFNGLGETTEXGENDVPROC) load(userptr, "glGetTexGendv");
    glad_glGetTexGenfv = (PFNGLGETTEXGENFVPROC) load(userptr, "glGetTexGenfv");
    glad_glGetTexGeniv = (PFNGLGETTEXGENIVPROC) load(userptr, "glGetTexGeniv");
    glad_glGetTexImage = (PFNGLGETTEXIMAGEPROC) load(userptr, "glGetTexImage");
    glad_glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC) load(userptr, "glGetTexLevelParameterfv");
    glad_glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC) load(userptr, "glGetTexLevelParameteriv");
    glad_glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC) load(userptr, "glGetTexParameterfv");
    glad_glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC) load(userptr, "glGetTexParameteriv");
    glad_glHint = (PFNGLHINTPROC) load(userptr, "glHint");
    glad_glIndexMask = (PFNGLINDEXMASKPROC) load(userptr, "glIndexMask");
    glad_glIndexd = (PFNGLINDEXDPROC) load(userptr, "glIndexd");
    glad_glIndexdv = (PFNGLINDEXDVPROC) load(userptr, "glIndexdv");
    glad_glIndexf = (PFNGLINDEXFPROC) load(userptr, "glIndexf");
    glad_glIndexfv = (PFNGLINDEXFVPROC) load(userptr, "glIndexfv");
    glad_glIndexi = (PFNGLINDEXIPROC) load(userptr, "glIndexi");
    glad_glIndexiv = (PFNGLINDEXIVPROC) load(userptr, "glIndexiv");
    glad_glIndexs = (PFNGLINDEXSPROC) load(userptr, "glIndexs");
    glad_glIndexsv = (PFNGLINDEXSVPROC) load(userptr, "glIndexsv");
    glad_glInitNames = (PFNGLINITNAMESPROC) load(userptr, "glInitNames");
    glad_glIsEnabled = (PFNGLISENABLEDPROC) load(userptr, "glIsEnabled");
    glad_glIsList = (PFNGLISLISTPROC) load(userptr, "glIsList");
    glad_glLightModelf = (PFNGLLIGHTMODELFPROC) load(userptr, "glLightModelf");
    glad_glLightModelfv = (PFNGLLIGHTMODELFVPROC) load(userptr, "glLightModelfv");
    glad_glLightModeli = (PFNGLLIGHTMODELIPROC) load(userptr, "glLightModeli");
    glad_glLightModeliv = (PFNGLLIGHTMODELIVPROC) load(userptr, "glLightModeliv");
    glad_glLightf = (PFNGLLIGHTFPROC) load(userptr, "glLightf");
    glad_glLightfv = (PFNGLLIGHTFVPROC) load(userptr, "glLightfv");
    glad_glLighti = (PFNGLLIGHTIPROC) load(userptr, "glLighti");
    glad_glLightiv = (PFNGLLIGHTIVPROC) load(userptr, "glLightiv");
    glad_glLineStipple = (PFNGLLINESTIPPLEPROC) load(userptr, "glLineStipple");
    glad_glLineWidth = (PFNGLLINEWIDTHPROC) load(userptr, "glLineWidth");
    glad_glListBase = (PFNGLLISTBASEPROC) load(userptr, "glListBase");
    glad_glLoadIdentity = (PFNGLLOADIDENTITYPROC) load(userptr, "glLoadIdentity");
    glad_glLoadMatrixd = (PFNGLLOADMATRIXDPROC) load(userptr, "glLoadMatrixd");
    glad_glLoadMatrixf = (PFNGLLOADMATRIXFPROC) load(userptr, "glLoadMatrixf");
    glad_glLoadName = (PFNGLLOADNAMEPROC) load(userptr, "glLoadName");
    glad_glLogicOp = (PFNGLLOGICOPPROC) load(userptr, "glLogicOp");
    glad_glMap1d = (PFNGLMAP1DPROC) load(userptr, "glMap1d");
    glad_glMap1f = (PFNGLMAP1FPROC) load(userptr, "glMap1f");
    glad_glMap2d = (PFNGLMAP2DPROC) load(userptr, "glMap2d");
    glad_glMap2f = (PFNGLMAP2FPROC) load(userptr, "glMap2f");
    glad_glMapGrid1d = (PFNGLMAPGRID1DPROC) load(userptr, "glMapGrid1d");
    glad_glMapGrid1f = (PFNGLMAPGRID1FPROC) load(userptr, "glMapGrid1f");
    glad_glMapGrid2d = (PFNGLMAPGRID2DPROC) load(userptr, "glMapGrid2d");
    glad_glMapGrid2f = (PFNGLMAPGRID2FPROC) load(userptr, "glMapGrid2f");
    glad_glMaterialf = (PFNGLMATERIALFPROC) load(userptr, "glMaterialf");
    glad_glMaterialfv = (PFNGLMATERIALFVPROC) load(userptr, "glMaterialfv");
    glad_glMateriali = (PFNGLMATERIALIPROC) load(userptr, "glMateriali");
    glad_glMaterialiv = (PFNGLMATERIALIVPROC) load(userptr, "glMaterialiv");
    glad_glMatrixMode = (PFNGLMATRIXMODEPROC) load(userptr, "glMatrixMode");
    glad_glMultMatrixd = (PFNGLMULTMATRIXDPROC) load(userptr, "glMultMatrixd");
    glad_glMultMatrixf = (PFNGLMULTMATRIXFPROC) load(userptr, "glMultMatrixf");
    glad_glNewList = (PFNGLNEWLISTPROC) load(userptr, "glNewList");
    glad_glNormal3b = (PFNGLNORMAL3BPROC) load(userptr, "glNormal3b");
    glad_glNormal3bv = (PFNGLNORMAL3BVPROC) load(userptr, "glNormal3bv");
    glad_glNormal3d = (PFNGLNORMAL3DPROC) load(userptr, "glNormal3d");
    glad_glNormal3dv = (PFNGLNORMAL3DVPROC) load(userptr, "glNormal3dv");
    glad_glNormal3f = (PFNGLNORMAL3FPROC) load(userptr, "glNormal3f");
    glad_glNormal3fv = (PFNGLNORMAL3FVPROC) load(userptr, "glNormal3fv");
    glad_glNormal3i = (PFNGLNORMAL3IPROC) load(userptr, "glNormal3i");
    glad_glNormal3iv = (PFNGLNORMAL3IVPROC) load(userptr, "glNormal3iv");
    glad_glNormal3s = (PFNGLNORMAL3SPROC) load(userptr, "glNormal3s");
    glad_glNormal3sv = (PFNGLNORMAL3SVPROC) load(userptr, "glNormal3sv");
    glad_glOrtho = (PFNGLORTHOPROC) load(userptr, "glOrtho");
    glad_glPassThrough = (PFNGLPASSTHROUGHPROC) load(userptr, "glPassThrough");
    glad_glPixelMapfv = (PFNGLPIXELMAPFVPROC) load(userptr, "glPixelMapfv");
    glad_glPixelMapuiv = (PFNGLPIXELMAPUIVPROC) load(userptr, "glPixelMapuiv");
    glad_glPixelMapusv = (PFNGLPIXELMAPUSVPROC) load(userptr, "glPixelMapusv");
    glad_glPixelStoref = (PFNGLPIXELSTOREFPROC) load(userptr, "glPixelStoref");
    glad_glPixelStorei = (PFNGLPIXELSTOREIPROC) load(userptr, "glPixelStorei");
    glad_glPixelTransferf = (PFNGLPIXELTRANSFERFPROC) load(userptr, "glPixelTransferf");
    glad_glPixelTransferi = (PFNGLPIXELTRANSFERIPROC) load(userptr, "glPixelTransferi");
    glad_glPixelZoom = (PFNGLPIXELZOOMPROC) load(userptr, "glPixelZoom");
    glad_glPointSize = (PFNGLPOINTSIZEPROC) load(userptr, "glPointSize");
    glad_glPolygonMode = (PFNGLPOLYGONMODEPROC) load(userptr, "glPolygonMode");
    glad_glPolygonStipple = (PFNGLPOLYGONSTIPPLEPROC) load(userptr, "glPolygonStipple");
    glad_glPopAttrib = (PFNGLPOPATTRIBPROC) load(userptr, "glPopAttrib");
    glad_glPopMatrix = (PFNGLPOPMATRIXPROC) load(userptr, "glPopMatrix");
    glad_glPopName = (PFNGLPOPNAMEPROC) load(userptr, "glPopName");
    glad_glPushAttrib = (PFNGLPUSHATTRIBPROC) load(userptr, "glPushAttrib");
    glad_glPushMatrix = (PFNGLPUSHMATRIXPROC) load(userptr, "glPushMatrix");
    glad_glPushName = (PFNGLPUSHNAMEPROC) load(userptr, "glPushName");
    glad_glRasterPos2d = (PFNGLRASTERPOS2DPROC) load(userptr, "glRasterPos2d");
    glad_glRasterPos2dv = (PFNGLRASTERPOS2DVPROC) load(userptr, "glRasterPos2dv");
    glad_glRasterPos2f = (PFNGLRASTERPOS2FPROC) load(userptr, "glRasterPos2f");
    glad_glRasterPos2fv = (PFNGLRASTERPOS2FVPROC) load(userptr, "glRasterPos2fv");
    glad_glRasterPos2i = (PFNGLRASTERPOS2IPROC) load(userptr, "glRasterPos2i");
    glad_glRasterPos2iv = (PFNGLRASTERPOS2IVPROC) load(userptr, "glRasterPos2iv");
    glad_glRasterPos2s = (PFNGLRASTERPOS2SPROC) load(userptr, "glRasterPos2s");
    glad_glRasterPos2sv = (PFNGLRASTERPOS2SVPROC) load(userptr, "glRasterPos2sv");
    glad_glRasterPos3d = (PFNGLRASTERPOS3DPROC) load(userptr, "glRasterPos3d");
    glad_glRasterPos3dv = (PFNGLRASTERPOS3DVPROC) load(userptr, "glRasterPos3dv");
    glad_glRasterPos3f = (PFNGLRASTERPOS3FPROC) load(userptr, "glRasterPos3f");
    glad_glRasterPos3fv = (PFNGLRASTERPOS3FVPROC) load(userptr, "glRasterPos3fv");
    glad_glRasterPos3i = (PFNGLRASTERPOS3IPROC) load(userptr, "glRasterPos3i");
    glad_glRasterPos3iv = (PFNGLRASTERPOS3IVPROC) load(userptr, "glRasterPos3iv");
    glad_glRasterPos3s = (PFNGLRASTERPOS3SPROC) load(userptr, "glRasterPos3s");
    glad_glRasterPos3sv = (PFNGLRASTERPOS3SVPROC) load(userptr, "glRasterPos3sv");
    glad_glRasterPos4d = (PFNGLRASTERPOS4DPROC) load(userptr, "glRasterPos4d");
    glad_glRasterPos4dv = (PFNGLRASTERPOS4DVPROC) load(userptr, "glRasterPos4dv");
    glad_glRasterPos4f = (PFNGLRASTERPOS4FPROC) load(userptr, "glRasterPos4f");
    glad_glRasterPos4fv = (PFNGLRASTERPOS4FVPROC) load(userptr, "glRasterPos4fv");
    glad_glRasterPos4i = (PFNGLRASTERPOS4IPROC) load(userptr, "glRasterPos4i");
    glad_glRasterPos4iv = (PFNGLRASTERPOS4IVPROC) load(userptr, "glRasterPos4iv");
    glad_glRasterPos4s = (PFNGLRASTERPOS4SPROC) load(userptr, "glRasterPos4s");
    glad_glRasterPos4sv = (PFNGLRASTERPOS4SVPROC) load(userptr, "glRasterPos4sv");
    glad_glReadBuffer = (PFNGLREADBUFFERPROC) load(userptr, "glReadBuffer");
    glad_glReadPixels = (PFNGLREADPIXELSPROC) load(userptr, "glReadPixels");
    glad_glRectd = (PFNGLRECTDPROC) load(userptr, "glRectd");
    glad_glRectdv = (PFNGLRECTDVPROC) load(userptr, "glRectdv");
    glad_glRectf = (PFNGLRECTFPROC) load(userptr, "glRectf");
    glad_glRectfv = (PFNGLRECTFVPROC) load(userptr, "glRectfv");
    glad_glRecti = (PFNGLRECTIPROC) load(userptr, "glRecti");
    glad_glRectiv = (PFNGLRECTIVPROC) load(userptr, "glRectiv");
    glad_glRects = (PFNGLRECTSPROC) load(userptr, "glRects");
    glad_glRectsv = (PFNGLRECTSVPROC) load(userptr, "glRectsv");
    glad_glRenderMode = (PFNGLRENDERMODEPROC) load(userptr, "glRenderMode");
    glad_glRotated = (PFNGLROTATEDPROC) load(userptr, "glRotated");
    glad_glRotatef = (PFNGLROTATEFPROC) load(userptr, "glRotatef");
    glad_glScaled = (PFNGLSCALEDPROC) load(userptr, "glScaled");
    glad_glScalef = (PFNGLSCALEFPROC) load(userptr, "glScalef");
    glad_glScissor = (PFNGLSCISSORPROC) load(userptr, "glScissor");
    glad_glSelectBuffer = (PFNGLSELECTBUFFERPROC) load(userptr, "glSelectBuffer");
    glad_glShadeModel = (PFNGLSHADEMODELPROC) load(userptr, "glShadeModel");
    glad_glStencilFunc = (PFNGLSTENCILFUNCPROC) load(userptr, "glStencilFunc");
    glad_glStencilMask = (PFNGLSTENCILMASKPROC) load(userptr, "glStencilMask");
    glad_glStencilOp = (PFNGLSTENCILOPPROC) load(userptr, "glStencilOp");
    glad_glTexCoord1d = (PFNGLTEXCOORD1DPROC) load(userptr, "glTexCoord1d");
    glad_glTexCoord1dv = (PFNGLTEXCOORD1DVPROC) load(userptr, "glTexCoord1dv");
    glad_glTexCoord1f = (PFNGLTEXCOORD1FPROC) load(userptr, "glTexCoord1f");
    glad_glTexCoord1fv = (PFNGLTEXCOORD1FVPROC) load(userptr, "glTexCoord1fv");
    glad_glTexCoord1i = (PFNGLTEXCOORD1IPROC) load(userptr, "glTexCoord1i");
    glad_glTexCoord1iv = (PFNGLTEXCOORD1IVPROC) load(userptr, "glTexCoord1iv");
    glad_glTexCoord1s = (PFNGLTEXCOORD1SPROC) load(userptr, "glTexCoord1s");
    glad_glTexCoord1sv = (PFNGLTEXCOORD1SVPROC) load(userptr, "glTexCoord1sv");
    glad_glTexCoord2d = (PFNGLTEXCOORD2DPROC) load(userptr, "glTexCoord2d");
    glad_glTexCoord2dv = (PFNGLTEXCOORD2DVPROC) load(userptr, "glTexCoord2dv");
    glad_glTexCoord2f = (PFNGLTEXCOORD2FPROC) load(userptr, "glTexCoord2f");
    glad_glTexCoord2fv = (PFNGLTEXCOORD2FVPROC) load(userptr, "glTexCoord2fv");
    glad_glTexCoord2i = (PFNGLTEXCOORD2IPROC) load(userptr, "glTexCoord2i");
    glad_glTexCoord2iv = (PFNGLTEXCOORD2IVPROC) load(userptr, "glTexCoord2iv");
    glad_glTexCoord2s = (PFNGLTEXCOORD2SPROC) load(userptr, "glTexCoord2s");
    glad_glTexCoord2sv = (PFNGLTEXCOORD2SVPROC) load(userptr, "glTexCoord2sv");
    glad_glTexCoord3d = (PFNGLTEXCOORD3DPROC) load(userptr, "glTexCoord3d");
    glad_glTexCoord3dv = (PFNGLTEXCOORD3DVPROC) load(userptr, "glTexCoord3dv");
    glad_glTexCoord3f = (PFNGLTEXCOORD3FPROC) load(userptr, "glTexCoord3f");
    glad_glTexCoord3fv = (PFNGLTEXCOORD3FVPROC) load(userptr, "glTexCoord3fv");
    glad_glTexCoord3i = (PFNGLTEXCOORD3IPROC) load(userptr, "glTexCoord3i");
    glad_glTexCoord3iv = (PFNGLTEXCOORD3IVPROC) load(userptr, "glTexCoord3iv");
    glad_glTexCoord3s = (PFNGLTEXCOORD3SPROC) load(userptr, "glTexCoord3s");
    glad_glTexCoord3sv = (PFNGLTEXCOORD3SVPROC) load(userptr, "glTexCoord3sv");
    glad_glTexCoord4d = (PFNGLTEXCOORD4DPROC) load(userptr, "glTexCoord4d");
    glad_glTexCoord4dv = (PFNGLTEXCOORD4DVPROC) load(userptr, "glTexCoord4dv");
    glad_glTexCoord4f = (PFNGLTEXCOORD4FPROC) load(userptr, "glTexCoord4f");
    glad_glTexCoord4fv = (PFNGLTEXCOORD4FVPROC) load(userptr, "glTexCoord4fv");
    glad_glTexCoord4i = (PFNGLTEXCOORD4IPROC) load(userptr, "glTexCoord4i");
    glad_glTexCoord4iv = (PFNGLTEXCOORD4IVPROC) load(userptr, "glTexCoord4iv");
    glad_glTexCoord4s = (PFNGLTEXCOORD4SPROC) load(userptr, "glTexCoord4s");
    glad_glTexCoord4sv = (PFNGLTEXCOORD4SVPROC) load(userptr, "glTexCoord4sv");
    glad_glTexEnvf = (PFNGLTEXENVFPROC) load(userptr, "glTexEnvf");
    glad_glTexEnvfv = (PFNGLTEXENVFVPROC) load(userptr, "glTexEnvfv");
    glad_glTexEnvi = (PFNGLTEXENVIPROC) load(userptr, "glTexEnvi");
    glad_glTexEnviv = (PFNGLTEXENVIVPROC) load(userptr, "glTexEnviv");
    glad_glTexGend = (PFNGLTEXGENDPROC) load(userptr, "glTexGend");
    glad_glTexGendv = (PFNGLTEXGENDVPROC) load(userptr, "glTexGendv");
    glad_glTexGenf = (PFNGLTEXGENFPROC) load(userptr, "glTexGenf");
    glad_glTexGenfv = (PFNGLTEXGENFVPROC) load(userptr, "glTexGenfv");
    glad_glTexGeni = (PFNGLTEXGENIPROC) load(userptr, "glTexGeni");
    glad_glTexGeniv = (PFNGLTEXGENIVPROC) load(userptr, "glTexGeniv");
    glad_glTexImage1D = (PFNGLTEXIMAGE1DPROC) load(userptr, "glTexImage1D");
    glad_glTexImage2D = (PFNGLTEXIMAGE2DPROC) load(userptr, "glTexImage2D");
    glad_glTexParameterf = (PFNGLTEXPARAMETERFPROC) load(userptr, "glTexParameterf");
    glad_glTexParameterfv = (PFNGLTEXPARAMETERFVPROC) load(userptr, "glTexParameterfv");
    glad_glTexParameteri = (PFNGLTEXPARAMETERIPROC) load(userptr, "glTexParameteri");
    glad_glTexParameteriv = (PFNGLTEXPARAMETERIVPROC) load(userptr, "glTexParameteriv");
    glad_glTranslated = (PFNGLTRANSLATEDPROC) load(userptr, "glTranslated");
    glad_glTranslatef = (PFNGLTRANSLATEFPROC) load(userptr, "glTranslatef");
    glad_glVertex2d = (PFNGLVERTEX2DPROC) load(userptr, "glVertex2d");
    glad_glVertex2dv = (PFNGLVERTEX2DVPROC) load(userptr, "glVertex2dv");
    glad_glVertex2f = (PFNGLVERTEX2FPROC) load(userptr, "glVertex2f");
    glad_glVertex2fv = (PFNGLVERTEX2FVPROC) load(userptr, "glVertex2fv");
    glad_glVertex2i = (PFNGLVERTEX2IPROC) load(userptr, "glVertex2i");
    glad_glVertex2iv = (PFNGLVERTEX2IVPROC) load(userptr, "glVertex2iv");
    glad_glVertex2s = (PFNGLVERTEX2SPROC) load(userptr, "glVertex2s");
    glad_glVertex2sv = (PFNGLVERTEX2SVPROC) load(userptr, "glVertex2sv");
    glad_glVertex3d = (PFNGLVERTEX3DPROC) load(userptr, "glVertex3d");
    glad_glVertex3dv = (PFNGLVERTEX3DVPROC) load(userptr, "glVertex3dv");
    glad_glVertex3f = (PFNGLVERTEX3FPROC) load(userptr, "glVertex3f");
    glad_glVertex3fv = (PFNGLVERTEX3FVPROC) load(userptr, "glVertex3fv");
    glad_glVertex3i = (PFNGLVERTEX3IPROC) load(userptr, "glVertex3i");
    glad_glVertex3iv = (PFNGLVERTEX3IVPROC) load(userptr, "glVertex3iv");
    glad_glVertex3s = (PFNGLVERTEX3SPROC) load(userptr, "glVertex3s");
    glad_glVertex3sv = (PFNGLVERTEX3SVPROC) load(userptr, "glVertex3sv");
    glad_glVertex4d = (PFNGLVERTEX4DPROC) load(userptr, "glVertex4d");
    glad_glVertex4dv = (PFNGLVERTEX4DVPROC) load(userptr, "glVertex4dv");
    glad_glVertex4f = (PFNGLVERTEX4FPROC) load(userptr, "glVertex4f");
    glad_glVertex4fv = (PFNGLVERTEX4FVPROC) load(userptr, "glVertex4fv");
    glad_glVertex4i = (PFNGLVERTEX4IPROC) load(userptr, "glVertex4i");
    glad_glVertex4iv = (PFNGLVERTEX4IVPROC) load(userptr, "glVertex4iv");
    glad_glVertex4s = (PFNGLVERTEX4SPROC) load(userptr, "glVertex4s");
    glad_glVertex4sv = (PFNGLVERTEX4SVPROC) load(userptr, "glVertex4sv");
    glad_glViewport = (PFNGLVIEWPORTPROC) load(userptr, "glViewport");
}
static void glad_gl_load_GL_VERSION_1_1( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_VERSION_1_1) return;
    glad_glAreTexturesResident = (PFNGLARETEXTURESRESIDENTPROC) load(userptr, "glAreTexturesResident");
    glad_glArrayElement = (PFNGLARRAYELEMENTPROC) load(userptr, "glArrayElement");
    glad_glBindTexture = (PFNGLBINDTEXTUREPROC) load(userptr, "glBindTexture");
    glad_glColorPointer = (PFNGLCOLORPOINTERPROC) load(userptr, "glColorPointer");
    glad_glCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC) load(userptr, "glCopyTexImage1D");
    glad_glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC) load(userptr, "glCopyTexImage2D");
    glad_glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC) load(userptr, "glCopyTexSubImage1D");
    glad_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC) load(userptr, "glCopyTexSubImage2D");
    glad_glDeleteTextures = (PFNGLDELETETEXTURESPROC) load(userptr, "glDeleteTextures");
    glad_glDisableClientState = (PFNGLDISABLECLIENTSTATEPROC) load(userptr, "glDisableClientState");
    glad_glDrawArrays = (PFNGLDRAWARRAYSPROC) load(userptr, "glDrawArrays");
    glad_glDrawElements = (PFNGLDRAWELEMENTSPROC) load(userptr, "glDrawElements");
    glad_glEdgeFlagPointer = (PFNGLEDGEFLAGPOINTERPROC) load(userptr, "glEdgeFlagPointer");
    glad_glEnableClientState = (PFNGLENABLECLIENTSTATEPROC) load(userptr, "glEnableClientState");
    glad_glGenTextures = (PFNGLGENTEXTURESPROC) load(userptr, "glGenTextures");
    glad_glGetPointerv = (PFNGLGETPOINTERVPROC) load(userptr, "glGetPointerv");
    glad_glIndexPointer = (PFNGLINDEXPOINTERPROC) load(userptr, "glIndexPointer");
    glad_glIndexub = (PFNGLINDEXUBPROC) load(userptr, "glIndexub");
    glad_glIndexubv = (PFNGLINDEXUBVPROC) load(userptr, "glIndexubv");
    glad_glInterleavedArrays = (PFNGLINTERLEAVEDARRAYSPROC) load(userptr, "glInterleavedArrays");
    glad_glIsTexture = (PFNGLISTEXTUREPROC) load(userptr, "glIsTexture");
    glad_glNormalPointer = (PFNGLNORMALPOINTERPROC) load(userptr, "glNormalPointer");
    glad_glPolygonOffset = (PFNGLPOLYGONOFFSETPROC) load(userptr, "glPolygonOffset");
    glad_glPopClientAttrib = (PFNGLPOPCLIENTATTRIBPROC) load(userptr, "glPopClientAttrib");
    glad_glPrioritizeTextures = (PFNGLPRIORITIZETEXTURESPROC) load(userptr, "glPrioritizeTextures");
    glad_glPushClientAttrib = (PFNGLPUSHCLIENTATTRIBPROC) load(userptr, "glPushClientAttrib");
    glad_glTexCoordPointer = (PFNGLTEXCOORDPOINTERPROC) load(userptr, "glTexCoordPointer");
    glad_glTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC) load(userptr, "glTexSubImage1D");
    glad_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC) load(userptr, "glTexSubImage2D");
    glad_glVertexPointer = (PFNGLVERTEXPOINTERPROC) load(userptr, "glVertexPointer");
}
static void glad_gl_load_GL_VERSION_1_2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_VERSION_1_2) return;
    glad_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC) load(userptr, "glCopyTexSubImage3D");
    glad_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC) load(userptr, "glDrawRangeElements");
    glad_glTexImage3D = (PFNGLTEXIMAGE3DPROC) load(userptr, "glTexImage3D");
    glad_glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC) load(userptr, "glTexSubImage3D");
}
static void glad_gl_load_GL_VERSION_1_3( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_VERSION_1_3) return;
    glad_glActiveTexture = (PFNGLACTIVETEXTUREPROC) load(userptr, "glActiveTexture");
    glad_glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC) load(userptr, "glClientActiveTexture");
    glad_glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC) load(userptr, "glCompressedTexImage1D");
    glad_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC) load(userptr, "glCompressedTexImage2D");
    glad_glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC) load(userptr, "glCompressedTexImage3D");
    glad_glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) load(userptr, "glCompressedTexSubImage1D");
    glad_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) load(userptr, "glCompressedTexSubImage2D");
    glad_glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) load(userptr, "glCompressedTexSubImage3D");
    glad_glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC) load(userptr, "glGetCompressedTexImage");
    glad_glLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC) load(userptr, "glLoadTransposeMatrixd");
    glad_glLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC) load(userptr, "glLoadTransposeMatrixf");
    glad_glMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC) load(userptr, "glMultTransposeMatrixd");
    glad_glMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC) load(userptr, "glMultTransposeMatrixf");
    glad_glMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC) load(userptr, "glMultiTexCoord1d");
    glad_glMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC) load(userptr, "glMultiTexCoord1dv");
    glad_glMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC) load(userptr, "glMultiTexCoord1f");
    glad_glMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC) load(userptr, "glMultiTexCoord1fv");
    glad_glMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC) load(userptr, "glMultiTexCoord1i");
    glad_glMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC) load(userptr, "glMultiTexCoord1iv");
    glad_glMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC) load(userptr, "glMultiTexCoord1s");
    glad_glMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC) load(userptr, "glMultiTexCoord1sv");
    glad_glMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC) load(userptr, "glMultiTexCoord2d");
    glad_glMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC) load(userptr, "glMultiTexCoord2dv");
    glad_glMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC) load(userptr, "glMultiTexCoord2f");
    glad_glMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC) load(userptr, "glMultiTexCoord2fv");
    glad_glMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC) load(userptr, "glMultiTexCoord2i");
    glad_glMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC) load(userptr, "glMultiTexCoord2iv");
    glad_glMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC) load(userptr, "glMultiTexCoord2s");
    glad_glMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC) load(userptr, "glMultiTexCoord2sv");
    glad_glMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC) load(userptr, "glMultiTexCoord3d");
    glad_glMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC) load(userptr, "glMultiTexCoord3dv");
    glad_glMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC) load(userptr, "glMultiTexCoord3f");
    glad_glMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC) load(userptr, "glMultiTexCoord3fv");
    glad_glMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC) load(userptr, "glMultiTexCoord3i");
    glad_glMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC) load(userptr, "glMultiTexCoord3iv");
    glad_glMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC) load(userptr, "glMultiTexCoord3s");
    glad_glMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC) load(userptr, "glMultiTexCoord3sv");
    glad_glMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC) load(userptr, "glMultiTexCoord4d");
    glad_glMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC) load(userptr, "glMultiTexCoord4dv");
    glad_glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC) load(userptr, "glMultiTexCoord4f");
    glad_glMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC) load(userptr, "glMultiTexCoord4fv");
    glad_glMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC) load(userptr, "glMultiTexCoord4i");
    glad_glMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC) load(userptr, "glMultiTexCoord4iv");
    glad_glMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC) load(userptr, "glMultiTexCoord4s");
    glad_glMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC) load(userptr, "glMultiTexCoord4sv");
    glad_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC) load(userptr, "glSampleCoverage");
}
static void glad_gl_load_GL_VERSION_1_4( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_VERSION_1_4) return;
    glad_glBlendColor = (PFNGLBLENDCOLORPROC) load(userptr, "glBlendColor");
    glad_glBlendEquation = (PFNGLBLENDEQUATIONPROC) load(userptr, "glBlendEquation");
    glad_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC) load(userptr, "glBlendFuncSeparate");
    glad_glFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC) load(userptr, "glFogCoordPointer");
    glad_glFogCoordd = (PFNGLFOGCOORDDPROC) load(userptr, "glFogCoordd");
    glad_glFogCoorddv = (PFNGLFOGCOORDDVPROC) load(userptr, "glFogCoorddv");
    glad_glFogCoordf = (PFNGLFOGCOORDFPROC) load(userptr, "glFogCoordf");
    glad_glFogCoordfv = (PFNGLFOGCOORDFVPROC) load(userptr, "glFogCoordfv");
    glad_glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC) load(userptr, "glMultiDrawArrays");
    glad_glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC) load(userptr, "glMultiDrawElements");
    glad_glPointParameterf = (PFNGLPOINTPARAMETERFPROC) load(userptr, "glPointParameterf");
    glad_glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC) load(userptr, "glPointParameterfv");
    glad_glPointParameteri = (PFNGLPOINTPARAMETERIPROC) load(userptr, "glPointParameteri");
    glad_glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC) load(userptr, "glPointParameteriv");
    glad_glSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC) load(userptr, "glSecondaryColor3b");
    glad_glSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC) load(userptr, "glSecondaryColor3bv");
    glad_glSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC) load(userptr, "glSecondaryColor3d");
    glad_glSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC) load(userptr, "glSecondaryColor3dv");
    glad_glSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC) load(userptr, "glSecondaryColor3f");
    glad_glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC) load(userptr, "glSecondaryColor3fv");
    glad_glSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC) load(userptr, "glSecondaryColor3i");
    glad_glSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC) load(userptr, "glSecondaryColor3iv");
    glad_glSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC) load(userptr, "glSecondaryColor3s");
    glad_glSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC) load(userptr, "glSecondaryColor3sv");
    glad_glSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC) load(userptr, "glSecondaryColor3ub");
    glad_glSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC) load(userptr, "glSecondaryColor3ubv");
    glad_glSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC) load(userptr, "glSecondaryColor3ui");
    glad_glSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC) load(userptr, "glSecondaryColor3uiv");
    glad_glSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC) load(userptr, "glSecondaryColor3us");
    glad_glSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC) load(userptr, "glSecondaryColor3usv");
    glad_glSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC) load(userptr, "glSecondaryColorPointer");
    glad_glWindowPos2d = (PFNGLWINDOWPOS2DPROC) load(userptr, "glWindowPos2d");
    glad_glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC) load(userptr, "glWindowPos2dv");
    glad_glWindowPos2f = (PFNGLWINDOWPOS2FPROC) load(userptr, "glWindowPos2f");
    glad_glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC) load(userptr, "glWindowPos2fv");
    glad_glWindowPos2i = (PFNGLWINDOWPOS2IPROC) load(userptr, "glWindowPos2i");
    glad_glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC) load(userptr, "glWindowPos2iv");
    glad_glWindowPos2s = (PFNGLWINDOWPOS2SPROC) load(userptr, "glWindowPos2s");
    glad_glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC) load(userptr, "glWindowPos2sv");
    glad_glWindowPos3d = (PFNGLWINDOWPOS3DPROC) load(userptr, "glWindowPos3d");
    glad_glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC) load(userptr, "glWindowPos3dv");
    glad_glWindowPos3f = (PFNGLWINDOWPOS3FPROC) load(userptr, "glWindowPos3f");
    glad_glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC) load(userptr, "glWindowPos3fv");
    glad_glWindowPos3i = (PFNGLWINDOWPOS3IPROC) load(userptr, "glWindowPos3i");
    glad_glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC) load(userptr, "glWindowPos3iv");
    glad_glWindowPos3s = (PFNGLWINDOWPOS3SPROC) load(userptr, "glWindowPos3s");
    glad_glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC) load(userptr, "glWindowPos3sv");
}
static void glad_gl_load_GL_VERSION_1_5( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_VERSION_1_5) return;
    glad_glBeginQuery = (PFNGLBEGINQUERYPROC) load(userptr, "glBeginQuery");
    glad_glBindBuffer = (PFNGLBINDBUFFERPROC) load(userptr, "glBindBuffer");
    glad_glBufferData = (PFNGLBUFFERDATAPROC) load(userptr, "glBufferData");
    glad_glBufferSubData = (PFNGLBUFFERSUBDATAPROC) load(userptr, "glBufferSubData");
    glad_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC) load(userptr, "glDeleteBuffers");
    glad_glDeleteQueries = (PFNGLDELETEQUERIESPROC) load(userptr, "glDeleteQueries");
    glad_glEndQuery = (PFNGLENDQUERYPROC) load(userptr, "glEndQuery");
    glad_glGenBuffers = (PFNGLGENBUFFERSPROC) load(userptr, "glGenBuffers");
    glad_glGenQueries = (PFNGLGENQUERIESPROC) load(userptr, "glGenQueries");
    glad_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC) load(userptr, "glGetBufferParameteriv");
    glad_glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC) load(userptr, "glGetBufferPointerv");
    glad_glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC) load(userptr, "glGetBufferSubData");
    glad_glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC) load(userptr, "glGetQueryObjectiv");
    glad_glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC) load(userptr, "glGetQueryObjectuiv");
    glad_glGetQueryiv = (PFNGLGETQUERYIVPROC) load(userptr, "glGetQueryiv");
    glad_glIsBuffer = (PFNGLISBUFFERPROC) load(userptr, "glIsBuffer");
    glad_glIsQuery = (PFNGLISQUERYPROC) load(userptr, "glIsQuery");
    glad_glMapBuffer = (PFNGLMAPBUFFERPROC) load(userptr, "glMapBuffer");
    glad_glUnmapBuffer = (PFNGLUNMAPBUFFERPROC) load(userptr, "glUnmapBuffer");
}
static void glad_gl_load_GL_VERSION_2_0( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_VERSION_2_0) return;
    glad_glAttachShader = (PFNGLATTACHSHADERPROC) load(userptr, "glAttachShader");
    glad_glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC) load(userptr, "glBindAttribLocation");
    glad_glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC) load(userptr, "glBlendEquationSeparate");
    glad_glCompileShader = (PFNGLCOMPILESHADERPROC) load(userptr, "glCompileShader");
    glad_glCreateProgram = (PFNGLCREATEPROGRAMPROC) load(userptr, "glCreateProgram");
    glad_glCreateShader = (PFNGLCREATESHADERPROC) load(userptr, "glCreateShader");
    glad_glDeleteProgram = (PFNGLDELETEPROGRAMPROC) load(userptr, "glDeleteProgram");
    glad_glDeleteShader = (PFNGLDELETESHADERPROC) load(userptr, "glDeleteShader");
    glad_glDetachShader = (PFNGLDETACHSHADERPROC) load(userptr, "glDetachShader");
    glad_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) load(userptr, "glDisableVertexAttribArray");
    glad_glDrawBuffers = (PFNGLDRAWBUFFERSPROC) load(userptr, "glDrawBuffers");
    glad_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC) load(userptr, "glEnableVertexAttribArray");
    glad_glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC) load(userptr, "glGetActiveAttrib");
    glad_glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC) load(userptr, "glGetActiveUniform");
    glad_glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC) load(userptr, "glGetAttachedShaders");
    glad_glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC) load(userptr, "glGetAttribLocation");
    glad_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC) load(userptr, "glGetProgramInfoLog");
    glad_glGetProgramiv = (PFNGLGETPROGRAMIVPROC) load(userptr, "glGetProgramiv");
    glad_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC) load(userptr, "glGetShaderInfoLog");
    glad_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC) load(userptr, "glGetShaderSource");
    glad_glGetShaderiv = (PFNGLGETSHADERIVPROC) load(userptr, "glGetShaderiv");
    glad_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC) load(userptr, "glGetUniformLocation");
    glad_glGetUniformfv = (PFNGLGETUNIFORMFVPROC) load(userptr, "glGetUniformfv");
    glad_glGetUniformiv = (PFNGLGETUNIFORMIVPROC) load(userptr, "glGetUniformiv");
    glad_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC) load(userptr, "glGetVertexAttribPointerv");
    glad_glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC) load(userptr, "glGetVertexAttribdv");
    glad_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC) load(userptr, "glGetVertexAttribfv");
    glad_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC) load(userptr, "glGetVertexAttribiv");
    glad_glIsProgram = (PFNGLISPROGRAMPROC) load(userptr, "glIsProgram");
    glad_glIsShader = (PFNGLISSHADERPROC) load(userptr, "glIsShader");
    glad_glLinkProgram = (PFNGLLINKPROGRAMPROC) load(userptr, "glLinkProgram");
    glad_glShaderSource = (PFNGLSHADERSOURCEPROC) load(userptr, "glShaderSource");
    glad_glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC) load(userptr, "glStencilFuncSeparate");
    glad_glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC) load(userptr, "glStencilMaskSeparate");
    glad_glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC) load(userptr, "glStencilOpSeparate");
    glad_glUniform1f = (PFNGLUNIFORM1FPROC) load(userptr, "glUniform1f");
    glad_glUniform1fv = (PFNGLUNIFORM1FVPROC) load(userptr, "glUniform1fv");
    glad_glUniform1i = (PFNGLUNIFORM1IPROC) load(userptr, "glUniform1i");
    glad_glUniform1iv = (PFNGLUNIFORM1IVPROC) load(userptr, "glUniform1iv");
    glad_glUniform2f = (PFNGLUNIFORM2FPROC) load(userptr, "glUniform2f");
    glad_glUniform2fv = (PFNGLUNIFORM2FVPROC) load(userptr, "glUniform2fv");
    glad_glUniform2i = (PFNGLUNIFORM2IPROC) load(userptr, "glUniform2i");
    glad_glUniform2iv = (PFNGLUNIFORM2IVPROC) load(userptr, "glUniform2iv");
    glad_glUniform3f = (PFNGLUNIFORM3FPROC) load(userptr, "glUniform3f");
    glad_glUniform3fv = (PFNGLUNIFORM3FVPROC) load(userptr, "glUniform3fv");
    glad_glUniform3i = (PFNGLUNIFORM3IPROC) load(userptr, "glUniform3i");
    glad_glUniform3iv = (PFNGLUNIFORM3IVPROC) load(userptr, "glUniform3iv");
    glad_glUniform4f = (PFNGLUNIFORM4FPROC) load(userptr, "glUniform4f");
    glad_glUniform4fv = (PFNGLUNIFORM4FVPROC) load(userptr, "glUniform4fv");
    glad_glUniform4i = (PFNGLUNIFORM4IPROC) load(userptr, "glUniform4i");
    glad_glUniform4iv = (PFNGLUNIFORM4IVPROC) load(userptr, "glUniform4iv");
    glad_glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC) load(userptr, "glUniformMatrix2fv");
    glad_glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC) load(userptr, "glUniformMatrix3fv");
    glad_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC) load(userptr, "glUniformMatrix4fv");
    glad_glUseProgram = (PFNGLUSEPROGRAMPROC) load(userptr, "glUseProgram");
    glad_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC) load(userptr, "glValidateProgram");
    glad_glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC) load(userptr, "glVertexAttrib1d");
    glad_glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC) load(userptr, "glVertexAttrib1dv");
    glad_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC) load(userptr, "glVertexAttrib1f");
    glad_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC) load(userptr, "glVertexAttrib1fv");
    glad_glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC) load(userptr, "glVertexAttrib1s");
    glad_glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC) load(userptr, "glVertexAttrib1sv");
    glad_glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC) load(userptr, "glVertexAttrib2d");
    glad_glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC) load(userptr, "glVertexAttrib2dv");
    glad_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC) load(userptr, "glVertexAttrib2f");
    glad_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC) load(userptr, "glVertexAttrib2fv");
    glad_glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC) load(userptr, "glVertexAttrib2s");
    glad_glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC) load(userptr, "glVertexAttrib2sv");
    glad_glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC) load(userptr, "glVertexAttrib3d");
    glad_glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC) load(userptr, "glVertexAttrib3dv");
    glad_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC) load(userptr, "glVertexAttrib3f");
    glad_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC) load(userptr, "glVertexAttrib3fv");
    glad_glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC) load(userptr, "glVertexAttrib3s");
    glad_glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC) load(userptr, "glVertexAttrib3sv");
    glad_glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC) load(userptr, "glVertexAttrib4Nbv");
    glad_glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC) load(userptr, "glVertexAttrib4Niv");
    glad_glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC) load(userptr, "glVertexAttrib4Nsv");
    glad_glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC) load(userptr, "glVertexAttrib4Nub");
    glad_glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC) load(userptr, "glVertexAttrib4Nubv");
    glad_glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC) load(userptr, "glVertexAttrib4Nuiv");
    glad_glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC) load(userptr, "glVertexAttrib4Nusv");
    glad_glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC) load(userptr, "glVertexAttrib4bv");
    glad_glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC) load(userptr, "glVertexAttrib4d");
    glad_glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC) load(userptr, "glVertexAttrib4dv");
    glad_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC) load(userptr, "glVertexAttrib4f");
    glad_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC) load(userptr, "glVertexAttrib4fv");
    glad_glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC) load(userptr, "glVertexAttrib4iv");
    glad_glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC) load(userptr, "glVertexAttrib4s");
    glad_glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC) load(userptr, "glVertexAttrib4sv");
    glad_glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC) load(userptr, "glVertexAttrib4ubv");
    glad_glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC) load(userptr, "glVertexAttrib4uiv");
    glad_glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC) load(userptr, "glVertexAttrib4usv");
    glad_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC) load(userptr, "glVertexAttribPointer");
}
static void glad_gl_load_GL_VERSION_2_1( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_VERSION_2_1) return;
    glad_glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC) load(userptr, "glUniformMatrix2x3fv");
    glad_glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC) load(userptr, "glUniformMatrix2x4fv");
    glad_glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC) load(userptr, "glUniformMatrix3x2fv");
    glad_glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC) load(userptr, "glUniformMatrix3x4fv");
    glad_glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC) load(userptr, "glUniformMatrix4x2fv");
    glad_glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC) load(userptr, "glUniformMatrix4x3fv");
}
static void glad_gl_load_GL_ARB_draw_buffers( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_draw_buffers) return;
    glad_glDrawBuffersARB = (PFNGLDRAWBUFFERSARBPROC) load(userptr, "glDrawBuffersARB");
}
static void glad_gl_load_GL_ARB_fragment_program( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_fragment_program) return;
    glad_glBindProgramARB = (PFNGLBINDPROGRAMARBPROC) load(userptr, "glBindProgramARB");
    glad_glDeleteProgramsARB = (PFNGLDELETEPROGRAMSARBPROC) load(userptr, "glDeleteProgramsARB");
    glad_glGenProgramsARB = (PFNGLGENPROGRAMSARBPROC) load(userptr, "glGenProgramsARB");
    glad_glGetProgramEnvParameterdvARB = (PFNGLGETPROGRAMENVPARAMETERDVARBPROC) load(userptr, "glGetProgramEnvParameterdvARB");
    glad_glGetProgramEnvParameterfvARB = (PFNGLGETPROGRAMENVPARAMETERFVARBPROC) load(userptr, "glGetProgramEnvParameterfvARB");
    glad_glGetProgramLocalParameterdvARB = (PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC) load(userptr, "glGetProgramLocalParameterdvARB");
    glad_glGetProgramLocalParameterfvARB = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC) load(userptr, "glGetProgramLocalParameterfvARB");
    glad_glGetProgramStringARB = (PFNGLGETPROGRAMSTRINGARBPROC) load(userptr, "glGetProgramStringARB");
    glad_glGetProgramivARB = (PFNGLGETPROGRAMIVARBPROC) load(userptr, "glGetProgramivARB");
    glad_glIsProgramARB = (PFNGLISPROGRAMARBPROC) load(userptr, "glIsProgramARB");
    glad_glProgramEnvParameter4dARB = (PFNGLPROGRAMENVPARAMETER4DARBPROC) load(userptr, "glProgramEnvParameter4dARB");
    glad_glProgramEnvParameter4dvARB = (PFNGLPROGRAMENVPARAMETER4DVARBPROC) load(userptr, "glProgramEnvParameter4dvARB");
    glad_glProgramEnvParameter4fARB = (PFNGLPROGRAMENVPARAMETER4FARBPROC) load(userptr, "glProgramEnvParameter4fARB");
    glad_glProgramEnvParameter4fvARB = (PFNGLPROGRAMENVPARAMETER4FVARBPROC) load(userptr, "glProgramEnvParameter4fvARB");
    glad_glProgramLocalParameter4dARB = (PFNGLPROGRAMLOCALPARAMETER4DARBPROC) load(userptr, "glProgramLocalParameter4dARB");
    glad_glProgramLocalParameter4dvARB = (PFNGLPROGRAMLOCALPARAMETER4DVARBPROC) load(userptr, "glProgramLocalParameter4dvARB");
    glad_glProgramLocalParameter4fARB = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC) load(userptr, "glProgramLocalParameter4fARB");
    glad_glProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC) load(userptr, "glProgramLocalParameter4fvARB");
    glad_glProgramStringARB = (PFNGLPROGRAMSTRINGARBPROC) load(userptr, "glProgramStringARB");
}
static void glad_gl_load_GL_ARB_imaging( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_imaging) return;
    glad_glBlendColor = (PFNGLBLENDCOLORPROC) load(userptr, "glBlendColor");
    glad_glBlendEquation = (PFNGLBLENDEQUATIONPROC) load(userptr, "glBlendEquation");
    glad_glColorSubTable = (PFNGLCOLORSUBTABLEPROC) load(userptr, "glColorSubTable");
    glad_glColorTable = (PFNGLCOLORTABLEPROC) load(userptr, "glColorTable");
    glad_glColorTableParameterfv = (PFNGLCOLORTABLEPARAMETERFVPROC) load(userptr, "glColorTableParameterfv");
    glad_glColorTableParameteriv = (PFNGLCOLORTABLEPARAMETERIVPROC) load(userptr, "glColorTableParameteriv");
    glad_glConvolutionFilter1D = (PFNGLCONVOLUTIONFILTER1DPROC) load(userptr, "glConvolutionFilter1D");
    glad_glConvolutionFilter2D = (PFNGLCONVOLUTIONFILTER2DPROC) load(userptr, "glConvolutionFilter2D");
    glad_glConvolutionParameterf = (PFNGLCONVOLUTIONPARAMETERFPROC) load(userptr, "glConvolutionParameterf");
    glad_glConvolutionParameterfv = (PFNGLCONVOLUTIONPARAMETERFVPROC) load(userptr, "glConvolutionParameterfv");
    glad_glConvolutionParameteri = (PFNGLCONVOLUTIONPARAMETERIPROC) load(userptr, "glConvolutionParameteri");
    glad_glConvolutionParameteriv = (PFNGLCONVOLUTIONPARAMETERIVPROC) load(userptr, "glConvolutionParameteriv");
    glad_glCopyColorSubTable = (PFNGLCOPYCOLORSUBTABLEPROC) load(userptr, "glCopyColorSubTable");
    glad_glCopyColorTable = (PFNGLCOPYCOLORTABLEPROC) load(userptr, "glCopyColorTable");
    glad_glCopyConvolutionFilter1D = (PFNGLCOPYCONVOLUTIONFILTER1DPROC) load(userptr, "glCopyConvolutionFilter1D");
    glad_glCopyConvolutionFilter2D = (PFNGLCOPYCONVOLUTIONFILTER2DPROC) load(userptr, "glCopyConvolutionFilter2D");
    glad_glGetColorTable = (PFNGLGETCOLORTABLEPROC) load(userptr, "glGetColorTable");
    glad_glGetColorTableParameterfv = (PFNGLGETCOLORTABLEPARAMETERFVPROC) load(userptr, "glGetColorTableParameterfv");
    glad_glGetColorTableParameteriv = (PFNGLGETCOLORTABLEPARAMETERIVPROC) load(userptr, "glGetColorTableParameteriv");
    glad_glGetConvolutionFilter = (PFNGLGETCONVOLUTIONFILTERPROC) load(userptr, "glGetConvolutionFilter");
    glad_glGetConvolutionParameterfv = (PFNGLGETCONVOLUTIONPARAMETERFVPROC) load(userptr, "glGetConvolutionParameterfv");
    glad_glGetConvolutionParameteriv = (PFNGLGETCONVOLUTIONPARAMETERIVPROC) load(userptr, "glGetConvolutionParameteriv");
    glad_glGetHistogram = (PFNGLGETHISTOGRAMPROC) load(userptr, "glGetHistogram");
    glad_glGetHistogramParameterfv = (PFNGLGETHISTOGRAMPARAMETERFVPROC) load(userptr, "glGetHistogramParameterfv");
    glad_glGetHistogramParameteriv = (PFNGLGETHISTOGRAMPARAMETERIVPROC) load(userptr, "glGetHistogramParameteriv");
    glad_glGetMinmax = (PFNGLGETMINMAXPROC) load(userptr, "glGetMinmax");
    glad_glGetMinmaxParameterfv = (PFNGLGETMINMAXPARAMETERFVPROC) load(userptr, "glGetMinmaxParameterfv");
    glad_glGetMinmaxParameteriv = (PFNGLGETMINMAXPARAMETERIVPROC) load(userptr, "glGetMinmaxParameteriv");
    glad_glGetSeparableFilter = (PFNGLGETSEPARABLEFILTERPROC) load(userptr, "glGetSeparableFilter");
    glad_glHistogram = (PFNGLHISTOGRAMPROC) load(userptr, "glHistogram");
    glad_glMinmax = (PFNGLMINMAXPROC) load(userptr, "glMinmax");
    glad_glResetHistogram = (PFNGLRESETHISTOGRAMPROC) load(userptr, "glResetHistogram");
    glad_glResetMinmax = (PFNGLRESETMINMAXPROC) load(userptr, "glResetMinmax");
    glad_glSeparableFilter2D = (PFNGLSEPARABLEFILTER2DPROC) load(userptr, "glSeparableFilter2D");
}
static void glad_gl_load_GL_ARB_multisample( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_multisample) return;
    glad_glSampleCoverageARB = (PFNGLSAMPLECOVERAGEARBPROC) load(userptr, "glSampleCoverageARB");
}
static void glad_gl_load_GL_ARB_multitexture( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_multitexture) return;
    glad_glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC) load(userptr, "glActiveTextureARB");
    glad_glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC) load(userptr, "glClientActiveTextureARB");
    glad_glMultiTexCoord1dARB = (PFNGLMULTITEXCOORD1DARBPROC) load(userptr, "glMultiTexCoord1dARB");
    glad_glMultiTexCoord1dvARB = (PFNGLMULTITEXCOORD1DVARBPROC) load(userptr, "glMultiTexCoord1dvARB");
    glad_glMultiTexCoord1fARB = (PFNGLMULTITEXCOORD1FARBPROC) load(userptr, "glMultiTexCoord1fARB");
    glad_glMultiTexCoord1fvARB = (PFNGLMULTITEXCOORD1FVARBPROC) load(userptr, "glMultiTexCoord1fvARB");
    glad_glMultiTexCoord1iARB = (PFNGLMULTITEXCOORD1IARBPROC) load(userptr, "glMultiTexCoord1iARB");
    glad_glMultiTexCoord1ivARB = (PFNGLMULTITEXCOORD1IVARBPROC) load(userptr, "glMultiTexCoord1ivARB");
    glad_glMultiTexCoord1sARB = (PFNGLMULTITEXCOORD1SARBPROC) load(userptr, "glMultiTexCoord1sARB");
    glad_glMultiTexCoord1svARB = (PFNGLMULTITEXCOORD1SVARBPROC) load(userptr, "glMultiTexCoord1svARB");
    glad_glMultiTexCoord2dARB = (PFNGLMULTITEXCOORD2DARBPROC) load(userptr, "glMultiTexCoord2dARB");
    glad_glMultiTexCoord2dvARB = (PFNGLMULTITEXCOORD2DVARBPROC) load(userptr, "glMultiTexCoord2dvARB");
    glad_glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC) load(userptr, "glMultiTexCoord2fARB");
    glad_glMultiTexCoord2fvARB = (PFNGLMULTITEXCOORD2FVARBPROC) load(userptr, "glMultiTexCoord2fvARB");
    glad_glMultiTexCoord2iARB = (PFNGLMULTITEXCOORD2IARBPROC) load(userptr, "glMultiTexCoord2iARB");
    glad_glMultiTexCoord2ivARB = (PFNGLMULTITEXCOORD2IVARBPROC) load(userptr, "glMultiTexCoord2ivARB");
    glad_glMultiTexCoord2sARB = (PFNGLMULTITEXCOORD2SARBPROC) load(userptr, "glMultiTexCoord2sARB");
    glad_glMultiTexCoord2svARB = (PFNGLMULTITEXCOORD2SVARBPROC) load(userptr, "glMultiTexCoord2svARB");
    glad_glMultiTexCoord3dARB = (PFNGLMULTITEXCOORD3DARBPROC) load(userptr, "glMultiTexCoord3dARB");
    glad_glMultiTexCoord3dvARB = (PFNGLMULTITEXCOORD3DVARBPROC) load(userptr, "glMultiTexCoord3dvARB");
    glad_glMultiTexCoord3fARB = (PFNGLMULTITEXCOORD3FARBPROC) load(userptr, "glMultiTexCoord3fARB");
    glad_glMultiTexCoord3fvARB = (PFNGLMULTITEXCOORD3FVARBPROC) load(userptr, "glMultiTexCoord3fvARB");
    glad_glMultiTexCoord3iARB = (PFNGLMULTITEXCOORD3IARBPROC) load(userptr, "glMultiTexCoord3iARB");
    glad_glMultiTexCoord3ivARB = (PFNGLMULTITEXCOORD3IVARBPROC) load(userptr, "glMultiTexCoord3ivARB");
    glad_glMultiTexCoord3sARB = (PFNGLMULTITEXCOORD3SARBPROC) load(userptr, "glMultiTexCoord3sARB");
    glad_glMultiTexCoord3svARB = (PFNGLMULTITEXCOORD3SVARBPROC) load(userptr, "glMultiTexCoord3svARB");
    glad_glMultiTexCoord4dARB = (PFNGLMULTITEXCOORD4DARBPROC) load(userptr, "glMultiTexCoord4dARB");
    glad_glMultiTexCoord4dvARB = (PFNGLMULTITEXCOORD4DVARBPROC) load(userptr, "glMultiTexCoord4dvARB");
    glad_glMultiTexCoord4fARB = (PFNGLMULTITEXCOORD4FARBPROC) load(userptr, "glMultiTexCoord4fARB");
    glad_glMultiTexCoord4fvARB = (PFNGLMULTITEXCOORD4FVARBPROC) load(userptr, "glMultiTexCoord4fvARB");
    glad_glMultiTexCoord4iARB = (PFNGLMULTITEXCOORD4IARBPROC) load(userptr, "glMultiTexCoord4iARB");
    glad_glMultiTexCoord4ivARB = (PFNGLMULTITEXCOORD4IVARBPROC) load(userptr, "glMultiTexCoord4ivARB");
    glad_glMultiTexCoord4sARB = (PFNGLMULTITEXCOORD4SARBPROC) load(userptr, "glMultiTexCoord4sARB");
    glad_glMultiTexCoord4svARB = (PFNGLMULTITEXCOORD4SVARBPROC) load(userptr, "glMultiTexCoord4svARB");
}
static void glad_gl_load_GL_ARB_occlusion_query( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_occlusion_query) return;
    glad_glBeginQueryARB = (PFNGLBEGINQUERYARBPROC) load(userptr, "glBeginQueryARB");
    glad_glDeleteQueriesARB = (PFNGLDELETEQUERIESARBPROC) load(userptr, "glDeleteQueriesARB");
    glad_glEndQueryARB = (PFNGLENDQUERYARBPROC) load(userptr, "glEndQueryARB");
    glad_glGenQueriesARB = (PFNGLGENQUERIESARBPROC) load(userptr, "glGenQueriesARB");
    glad_glGetQueryObjectivARB = (PFNGLGETQUERYOBJECTIVARBPROC) load(userptr, "glGetQueryObjectivARB");
    glad_glGetQueryObjectuivARB = (PFNGLGETQUERYOBJECTUIVARBPROC) load(userptr, "glGetQueryObjectuivARB");
    glad_glGetQueryivARB = (PFNGLGETQUERYIVARBPROC) load(userptr, "glGetQueryivARB");
    glad_glIsQueryARB = (PFNGLISQUERYARBPROC) load(userptr, "glIsQueryARB");
}
static void glad_gl_load_GL_ARB_point_parameters( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_point_parameters) return;
    glad_glPointParameterfARB = (PFNGLPOINTPARAMETERFARBPROC) load(userptr, "glPointParameterfARB");
    glad_glPointParameterfvARB = (PFNGLPOINTPARAMETERFVARBPROC) load(userptr, "glPointParameterfvARB");
}
static void glad_gl_load_GL_ARB_shader_objects( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_shader_objects) return;
    glad_glAttachObjectARB = (PFNGLATTACHOBJECTARBPROC) load(userptr, "glAttachObjectARB");
    glad_glCompileShaderARB = (PFNGLCOMPILESHADERARBPROC) load(userptr, "glCompileShaderARB");
    glad_glCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC) load(userptr, "glCreateProgramObjectARB");
    glad_glCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC) load(userptr, "glCreateShaderObjectARB");
    glad_glDeleteObjectARB = (PFNGLDELETEOBJECTARBPROC) load(userptr, "glDeleteObjectARB");
    glad_glDetachObjectARB = (PFNGLDETACHOBJECTARBPROC) load(userptr, "glDetachObjectARB");
    glad_glGetActiveUniformARB = (PFNGLGETACTIVEUNIFORMARBPROC) load(userptr, "glGetActiveUniformARB");
    glad_glGetAttachedObjectsARB = (PFNGLGETATTACHEDOBJECTSARBPROC) load(userptr, "glGetAttachedObjectsARB");
    glad_glGetHandleARB = (PFNGLGETHANDLEARBPROC) load(userptr, "glGetHandleARB");
    glad_glGetInfoLogARB = (PFNGLGETINFOLOGARBPROC) load(userptr, "glGetInfoLogARB");
    glad_glGetObjectParameterfvARB = (PFNGLGETOBJECTPARAMETERFVARBPROC) load(userptr, "glGetObjectParameterfvARB");
    glad_glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC) load(userptr, "glGetObjectParameterivARB");
    glad_glGetShaderSourceARB = (PFNGLGETSHADERSOURCEARBPROC) load(userptr, "glGetShaderSourceARB");
    glad_glGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC) load(userptr, "glGetUniformLocationARB");
    glad_glGetUniformfvARB = (PFNGLGETUNIFORMFVARBPROC) load(userptr, "glGetUniformfvARB");
    glad_glGetUniformivARB = (PFNGLGETUNIFORMIVARBPROC) load(userptr, "glGetUniformivARB");
    glad_glLinkProgramARB = (PFNGLLINKPROGRAMARBPROC) load(userptr, "glLinkProgramARB");
    glad_glShaderSourceARB = (PFNGLSHADERSOURCEARBPROC) load(userptr, "glShaderSourceARB");
    glad_glUniform1fARB = (PFNGLUNIFORM1FARBPROC) load(userptr, "glUniform1fARB");
    glad_glUniform1fvARB = (PFNGLUNIFORM1FVARBPROC) load(userptr, "glUniform1fvARB");
    glad_glUniform1iARB = (PFNGLUNIFORM1IARBPROC) load(userptr, "glUniform1iARB");
    glad_glUniform1ivARB = (PFNGLUNIFORM1IVARBPROC) load(userptr, "glUniform1ivARB");
    glad_glUniform2fARB = (PFNGLUNIFORM2FARBPROC) load(userptr, "glUniform2fARB");
    glad_glUniform2fvARB = (PFNGLUNIFORM2FVARBPROC) load(userptr, "glUniform2fvARB");
    glad_glUniform2iARB = (PFNGLUNIFORM2IARBPROC) load(userptr, "glUniform2iARB");
    glad_glUniform2ivARB = (PFNGLUNIFORM2IVARBPROC) load(userptr, "glUniform2ivARB");
    glad_glUniform3fARB = (PFNGLUNIFORM3FARBPROC) load(userptr, "glUniform3fARB");
    glad_glUniform3fvARB = (PFNGLUNIFORM3FVARBPROC) load(userptr, "glUniform3fvARB");
    glad_glUniform3iARB = (PFNGLUNIFORM3IARBPROC) load(userptr, "glUniform3iARB");
    glad_glUniform3ivARB = (PFNGLUNIFORM3IVARBPROC) load(userptr, "glUniform3ivARB");
    glad_glUniform4fARB = (PFNGLUNIFORM4FARBPROC) load(userptr, "glUniform4fARB");
    glad_glUniform4fvARB = (PFNGLUNIFORM4FVARBPROC) load(userptr, "glUniform4fvARB");
    glad_glUniform4iARB = (PFNGLUNIFORM4IARBPROC) load(userptr, "glUniform4iARB");
    glad_glUniform4ivARB = (PFNGLUNIFORM4IVARBPROC) load(userptr, "glUniform4ivARB");
    glad_glUniformMatrix2fvARB = (PFNGLUNIFORMMATRIX2FVARBPROC) load(userptr, "glUniformMatrix2fvARB");
    glad_glUniformMatrix3fvARB = (PFNGLUNIFORMMATRIX3FVARBPROC) load(userptr, "glUniformMatrix3fvARB");
    glad_glUniformMatrix4fvARB = (PFNGLUNIFORMMATRIX4FVARBPROC) load(userptr, "glUniformMatrix4fvARB");
    glad_glUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC) load(userptr, "glUseProgramObjectARB");
    glad_glValidateProgramARB = (PFNGLVALIDATEPROGRAMARBPROC) load(userptr, "glValidateProgramARB");
}
static void glad_gl_load_GL_ARB_texture_compression( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_texture_compression) return;
    glad_glCompressedTexImage1DARB = (PFNGLCOMPRESSEDTEXIMAGE1DARBPROC) load(userptr, "glCompressedTexImage1DARB");
    glad_glCompressedTexImage2DARB = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC) load(userptr, "glCompressedTexImage2DARB");
    glad_glCompressedTexImage3DARB = (PFNGLCOMPRESSEDTEXIMAGE3DARBPROC) load(userptr, "glCompressedTexImage3DARB");
    glad_glCompressedTexSubImage1DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC) load(userptr, "glCompressedTexSubImage1DARB");
    glad_glCompressedTexSubImage2DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC) load(userptr, "glCompressedTexSubImage2DARB");
    glad_glCompressedTexSubImage3DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC) load(userptr, "glCompressedTexSubImage3DARB");
    glad_glGetCompressedTexImageARB = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC) load(userptr, "glGetCompressedTexImageARB");
}
static void glad_gl_load_GL_ARB_transpose_matrix( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_transpose_matrix) return;
    glad_glLoadTransposeMatrixdARB = (PFNGLLOADTRANSPOSEMATRIXDARBPROC) load(userptr, "glLoadTransposeMatrixdARB");
    glad_glLoadTransposeMatrixfARB = (PFNGLLOADTRANSPOSEMATRIXFARBPROC) load(userptr, "glLoadTransposeMatrixfARB");
    glad_glMultTransposeMatrixdARB = (PFNGLMULTTRANSPOSEMATRIXDARBPROC) load(userptr, "glMultTransposeMatrixdARB");
    glad_glMultTransposeMatrixfARB = (PFNGLMULTTRANSPOSEMATRIXFARBPROC) load(userptr, "glMultTransposeMatrixfARB");
}
static void glad_gl_load_GL_ARB_vertex_buffer_object( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_vertex_buffer_object) return;
    glad_glBindBufferARB = (PFNGLBINDBUFFERARBPROC) load(userptr, "glBindBufferARB");
    glad_glBufferDataARB = (PFNGLBUFFERDATAARBPROC) load(userptr, "glBufferDataARB");
    glad_glBufferSubDataARB = (PFNGLBUFFERSUBDATAARBPROC) load(userptr, "glBufferSubDataARB");
    glad_glDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC) load(userptr, "glDeleteBuffersARB");
    glad_glGenBuffersARB = (PFNGLGENBUFFERSARBPROC) load(userptr, "glGenBuffersARB");
    glad_glGetBufferParameterivARB = (PFNGLGETBUFFERPARAMETERIVARBPROC) load(userptr, "glGetBufferParameterivARB");
    glad_glGetBufferPointervARB = (PFNGLGETBUFFERPOINTERVARBPROC) load(userptr, "glGetBufferPointervARB");
    glad_glGetBufferSubDataARB = (PFNGLGETBUFFERSUBDATAARBPROC) load(userptr, "glGetBufferSubDataARB");
    glad_glIsBufferARB = (PFNGLISBUFFERARBPROC) load(userptr, "glIsBufferARB");
    glad_glMapBufferARB = (PFNGLMAPBUFFERARBPROC) load(userptr, "glMapBufferARB");
    glad_glUnmapBufferARB = (PFNGLUNMAPBUFFERARBPROC) load(userptr, "glUnmapBufferARB");
}
static void glad_gl_load_GL_ARB_vertex_program( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_vertex_program) return;
    glad_glBindProgramARB = (PFNGLBINDPROGRAMARBPROC) load(userptr, "glBindProgramARB");
    glad_glDeleteProgramsARB = (PFNGLDELETEPROGRAMSARBPROC) load(userptr, "glDeleteProgramsARB");
    glad_glDisableVertexAttribArrayARB = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC) load(userptr, "glDisableVertexAttribArrayARB");
    glad_glEnableVertexAttribArrayARB = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC) load(userptr, "glEnableVertexAttribArrayARB");
    glad_glGenProgramsARB = (PFNGLGENPROGRAMSARBPROC) load(userptr, "glGenProgramsARB");
    glad_glGetProgramEnvParameterdvARB = (PFNGLGETPROGRAMENVPARAMETERDVARBPROC) load(userptr, "glGetProgramEnvParameterdvARB");
    glad_glGetProgramEnvParameterfvARB = (PFNGLGETPROGRAMENVPARAMETERFVARBPROC) load(userptr, "glGetProgramEnvParameterfvARB");
    glad_glGetProgramLocalParameterdvARB = (PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC) load(userptr, "glGetProgramLocalParameterdvARB");
    glad_glGetProgramLocalParameterfvARB = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC) load(userptr, "glGetProgramLocalParameterfvARB");
    glad_glGetProgramStringARB = (PFNGLGETPROGRAMSTRINGARBPROC) load(userptr, "glGetProgramStringARB");
    glad_glGetProgramivARB = (PFNGLGETPROGRAMIVARBPROC) load(userptr, "glGetProgramivARB");
    glad_glGetVertexAttribPointervARB = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC) load(userptr, "glGetVertexAttribPointervARB");
    glad_glGetVertexAttribdvARB = (PFNGLGETVERTEXATTRIBDVARBPROC) load(userptr, "glGetVertexAttribdvARB");
    glad_glGetVertexAttribfvARB = (PFNGLGETVERTEXATTRIBFVARBPROC) load(userptr, "glGetVertexAttribfvARB");
    glad_glGetVertexAttribivARB = (PFNGLGETVERTEXATTRIBIVARBPROC) load(userptr, "glGetVertexAttribivARB");
    glad_glIsProgramARB = (PFNGLISPROGRAMARBPROC) load(userptr, "glIsProgramARB");
    glad_glProgramEnvParameter4dARB = (PFNGLPROGRAMENVPARAMETER4DARBPROC) load(userptr, "glProgramEnvParameter4dARB");
    glad_glProgramEnvParameter4dvARB = (PFNGLPROGRAMENVPARAMETER4DVARBPROC) load(userptr, "glProgramEnvParameter4dvARB");
    glad_glProgramEnvParameter4fARB = (PFNGLPROGRAMENVPARAMETER4FARBPROC) load(userptr, "glProgramEnvParameter4fARB");
    glad_glProgramEnvParameter4fvARB = (PFNGLPROGRAMENVPARAMETER4FVARBPROC) load(userptr, "glProgramEnvParameter4fvARB");
    glad_glProgramLocalParameter4dARB = (PFNGLPROGRAMLOCALPARAMETER4DARBPROC) load(userptr, "glProgramLocalParameter4dARB");
    glad_glProgramLocalParameter4dvARB = (PFNGLPROGRAMLOCALPARAMETER4DVARBPROC) load(userptr, "glProgramLocalParameter4dvARB");
    glad_glProgramLocalParameter4fARB = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC) load(userptr, "glProgramLocalParameter4fARB");
    glad_glProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC) load(userptr, "glProgramLocalParameter4fvARB");
    glad_glProgramStringARB = (PFNGLPROGRAMSTRINGARBPROC) load(userptr, "glProgramStringARB");
    glad_glVertexAttrib1dARB = (PFNGLVERTEXATTRIB1DARBPROC) load(userptr, "glVertexAttrib1dARB");
    glad_glVertexAttrib1dvARB = (PFNGLVERTEXATTRIB1DVARBPROC) load(userptr, "glVertexAttrib1dvARB");
    glad_glVertexAttrib1fARB = (PFNGLVERTEXATTRIB1FARBPROC) load(userptr, "glVertexAttrib1fARB");
    glad_glVertexAttrib1fvARB = (PFNGLVERTEXATTRIB1FVARBPROC) load(userptr, "glVertexAttrib1fvARB");
    glad_glVertexAttrib1sARB = (PFNGLVERTEXATTRIB1SARBPROC) load(userptr, "glVertexAttrib1sARB");
    glad_glVertexAttrib1svARB = (PFNGLVERTEXATTRIB1SVARBPROC) load(userptr, "glVertexAttrib1svARB");
    glad_glVertexAttrib2dARB = (PFNGLVERTEXATTRIB2DARBPROC) load(userptr, "glVertexAttrib2dARB");
    glad_glVertexAttrib2dvARB = (PFNGLVERTEXATTRIB2DVARBPROC) load(userptr, "glVertexAttrib2dvARB");
    glad_glVertexAttrib2fARB = (PFNGLVERTEXATTRIB2FARBPROC) load(userptr, "glVertexAttrib2fARB");
    glad_glVertexAttrib2fvARB = (PFNGLVERTEXATTRIB2FVARBPROC) load(userptr, "glVertexAttrib2fvARB");
    glad_glVertexAttrib2sARB = (PFNGLVERTEXATTRIB2SARBPROC) load(userptr, "glVertexAttrib2sARB");
    glad_glVertexAttrib2svARB = (PFNGLVERTEXATTRIB2SVARBPROC) load(userptr, "glVertexAttrib2svARB");
    glad_glVertexAttrib3dARB = (PFNGLVERTEXATTRIB3DARBPROC) load(userptr, "glVertexAttrib3dARB");
    glad_glVertexAttrib3dvARB = (PFNGLVERTEXATTRIB3DVARBPROC) load(userptr, "glVertexAttrib3dvARB");
    glad_glVertexAttrib3fARB = (PFNGLVERTEXATTRIB3FARBPROC) load(userptr, "glVertexAttrib3fARB");
    glad_glVertexAttrib3fvARB = (PFNGLVERTEXATTRIB3FVARBPROC) load(userptr, "glVertexAttrib3fvARB");
    glad_glVertexAttrib3sARB = (PFNGLVERTEXATTRIB3SARBPROC) load(userptr, "glVertexAttrib3sARB");
    glad_glVertexAttrib3svARB = (PFNGLVERTEXATTRIB3SVARBPROC) load(userptr, "glVertexAttrib3svARB");
    glad_glVertexAttrib4NbvARB = (PFNGLVERTEXATTRIB4NBVARBPROC) load(userptr, "glVertexAttrib4NbvARB");
    glad_glVertexAttrib4NivARB = (PFNGLVERTEXATTRIB4NIVARBPROC) load(userptr, "glVertexAttrib4NivARB");
    glad_glVertexAttrib4NsvARB = (PFNGLVERTEXATTRIB4NSVARBPROC) load(userptr, "glVertexAttrib4NsvARB");
    glad_glVertexAttrib4NubARB = (PFNGLVERTEXATTRIB4NUBARBPROC) load(userptr, "glVertexAttrib4NubARB");
    glad_glVertexAttrib4NubvARB = (PFNGLVERTEXATTRIB4NUBVARBPROC) load(userptr, "glVertexAttrib4NubvARB");
    glad_glVertexAttrib4NuivARB = (PFNGLVERTEXATTRIB4NUIVARBPROC) load(userptr, "glVertexAttrib4NuivARB");
    glad_glVertexAttrib4NusvARB = (PFNGLVERTEXATTRIB4NUSVARBPROC) load(userptr, "glVertexAttrib4NusvARB");
    glad_glVertexAttrib4bvARB = (PFNGLVERTEXATTRIB4BVARBPROC) load(userptr, "glVertexAttrib4bvARB");
    glad_glVertexAttrib4dARB = (PFNGLVERTEXATTRIB4DARBPROC) load(userptr, "glVertexAttrib4dARB");
    glad_glVertexAttrib4dvARB = (PFNGLVERTEXATTRIB4DVARBPROC) load(userptr, "glVertexAttrib4dvARB");
    glad_glVertexAttrib4fARB = (PFNGLVERTEXATTRIB4FARBPROC) load(userptr, "glVertexAttrib4fARB");
    glad_glVertexAttrib4fvARB = (PFNGLVERTEXATTRIB4FVARBPROC) load(userptr, "glVertexAttrib4fvARB");
    glad_glVertexAttrib4ivARB = (PFNGLVERTEXATTRIB4IVARBPROC) load(userptr, "glVertexAttrib4ivARB");
    glad_glVertexAttrib4sARB = (PFNGLVERTEXATTRIB4SARBPROC) load(userptr, "glVertexAttrib4sARB");
    glad_glVertexAttrib4svARB = (PFNGLVERTEXATTRIB4SVARBPROC) load(userptr, "glVertexAttrib4svARB");
    glad_glVertexAttrib4ubvARB = (PFNGLVERTEXATTRIB4UBVARBPROC) load(userptr, "glVertexAttrib4ubvARB");
    glad_glVertexAttrib4uivARB = (PFNGLVERTEXATTRIB4UIVARBPROC) load(userptr, "glVertexAttrib4uivARB");
    glad_glVertexAttrib4usvARB = (PFNGLVERTEXATTRIB4USVARBPROC) load(userptr, "glVertexAttrib4usvARB");
    glad_glVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARBPROC) load(userptr, "glVertexAttribPointerARB");
}
static void glad_gl_load_GL_ARB_vertex_shader( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_vertex_shader) return;
    glad_glBindAttribLocationARB = (PFNGLBINDATTRIBLOCATIONARBPROC) load(userptr, "glBindAttribLocationARB");
    glad_glDisableVertexAttribArrayARB = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC) load(userptr, "glDisableVertexAttribArrayARB");
    glad_glEnableVertexAttribArrayARB = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC) load(userptr, "glEnableVertexAttribArrayARB");
    glad_glGetActiveAttribARB = (PFNGLGETACTIVEATTRIBARBPROC) load(userptr, "glGetActiveAttribARB");
    glad_glGetAttribLocationARB = (PFNGLGETATTRIBLOCATIONARBPROC) load(userptr, "glGetAttribLocationARB");
    glad_glGetVertexAttribPointervARB = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC) load(userptr, "glGetVertexAttribPointervARB");
    glad_glGetVertexAttribdvARB = (PFNGLGETVERTEXATTRIBDVARBPROC) load(userptr, "glGetVertexAttribdvARB");
    glad_glGetVertexAttribfvARB = (PFNGLGETVERTEXATTRIBFVARBPROC) load(userptr, "glGetVertexAttribfvARB");
    glad_glGetVertexAttribivARB = (PFNGLGETVERTEXATTRIBIVARBPROC) load(userptr, "glGetVertexAttribivARB");
    glad_glVertexAttrib1dARB = (PFNGLVERTEXATTRIB1DARBPROC) load(userptr, "glVertexAttrib1dARB");
    glad_glVertexAttrib1dvARB = (PFNGLVERTEXATTRIB1DVARBPROC) load(userptr, "glVertexAttrib1dvARB");
    glad_glVertexAttrib1fARB = (PFNGLVERTEXATTRIB1FARBPROC) load(userptr, "glVertexAttrib1fARB");
    glad_glVertexAttrib1fvARB = (PFNGLVERTEXATTRIB1FVARBPROC) load(userptr, "glVertexAttrib1fvARB");
    glad_glVertexAttrib1sARB = (PFNGLVERTEXATTRIB1SARBPROC) load(userptr, "glVertexAttrib1sARB");
    glad_glVertexAttrib1svARB = (PFNGLVERTEXATTRIB1SVARBPROC) load(userptr, "glVertexAttrib1svARB");
    glad_glVertexAttrib2dARB = (PFNGLVERTEXATTRIB2DARBPROC) load(userptr, "glVertexAttrib2dARB");
    glad_glVertexAttrib2dvARB = (PFNGLVERTEXATTRIB2DVARBPROC) load(userptr, "glVertexAttrib2dvARB");
    glad_glVertexAttrib2fARB = (PFNGLVERTEXATTRIB2FARBPROC) load(userptr, "glVertexAttrib2fARB");
    glad_glVertexAttrib2fvARB = (PFNGLVERTEXATTRIB2FVARBPROC) load(userptr, "glVertexAttrib2fvARB");
    glad_glVertexAttrib2sARB = (PFNGLVERTEXATTRIB2SARBPROC) load(userptr, "glVertexAttrib2sARB");
    glad_glVertexAttrib2svARB = (PFNGLVERTEXATTRIB2SVARBPROC) load(userptr, "glVertexAttrib2svARB");
    glad_glVertexAttrib3dARB = (PFNGLVERTEXATTRIB3DARBPROC) load(userptr, "glVertexAttrib3dARB");
    glad_glVertexAttrib3dvARB = (PFNGLVERTEXATTRIB3DVARBPROC) load(userptr, "glVertexAttrib3dvARB");
    glad_glVertexAttrib3fARB = (PFNGLVERTEXATTRIB3FARBPROC) load(userptr, "glVertexAttrib3fARB");
    glad_glVertexAttrib3fvARB = (PFNGLVERTEXATTRIB3FVARBPROC) load(userptr, "glVertexAttrib3fvARB");
    glad_glVertexAttrib3sARB = (PFNGLVERTEXATTRIB3SARBPROC) load(userptr, "glVertexAttrib3sARB");
    glad_glVertexAttrib3svARB = (PFNGLVERTEXATTRIB3SVARBPROC) load(userptr, "glVertexAttrib3svARB");
    glad_glVertexAttrib4NbvARB = (PFNGLVERTEXATTRIB4NBVARBPROC) load(userptr, "glVertexAttrib4NbvARB");
    glad_glVertexAttrib4NivARB = (PFNGLVERTEXATTRIB4NIVARBPROC) load(userptr, "glVertexAttrib4NivARB");
    glad_glVertexAttrib4NsvARB = (PFNGLVERTEXATTRIB4NSVARBPROC) load(userptr, "glVertexAttrib4NsvARB");
    glad_glVertexAttrib4NubARB = (PFNGLVERTEXATTRIB4NUBARBPROC) load(userptr, "glVertexAttrib4NubARB");
    glad_glVertexAttrib4NubvARB = (PFNGLVERTEXATTRIB4NUBVARBPROC) load(userptr, "glVertexAttrib4NubvARB");
    glad_glVertexAttrib4NuivARB = (PFNGLVERTEXATTRIB4NUIVARBPROC) load(userptr, "glVertexAttrib4NuivARB");
    glad_glVertexAttrib4NusvARB = (PFNGLVERTEXATTRIB4NUSVARBPROC) load(userptr, "glVertexAttrib4NusvARB");
    glad_glVertexAttrib4bvARB = (PFNGLVERTEXATTRIB4BVARBPROC) load(userptr, "glVertexAttrib4bvARB");
    glad_glVertexAttrib4dARB = (PFNGLVERTEXATTRIB4DARBPROC) load(userptr, "glVertexAttrib4dARB");
    glad_glVertexAttrib4dvARB = (PFNGLVERTEXATTRIB4DVARBPROC) load(userptr, "glVertexAttrib4dvARB");
    glad_glVertexAttrib4fARB = (PFNGLVERTEXATTRIB4FARBPROC) load(userptr, "glVertexAttrib4fARB");
    glad_glVertexAttrib4fvARB = (PFNGLVERTEXATTRIB4FVARBPROC) load(userptr, "glVertexAttrib4fvARB");
    glad_glVertexAttrib4ivARB = (PFNGLVERTEXATTRIB4IVARBPROC) load(userptr, "glVertexAttrib4ivARB");
    glad_glVertexAttrib4sARB = (PFNGLVERTEXATTRIB4SARBPROC) load(userptr, "glVertexAttrib4sARB");
    glad_glVertexAttrib4svARB = (PFNGLVERTEXATTRIB4SVARBPROC) load(userptr, "glVertexAttrib4svARB");
    glad_glVertexAttrib4ubvARB = (PFNGLVERTEXATTRIB4UBVARBPROC) load(userptr, "glVertexAttrib4ubvARB");
    glad_glVertexAttrib4uivARB = (PFNGLVERTEXATTRIB4UIVARBPROC) load(userptr, "glVertexAttrib4uivARB");
    glad_glVertexAttrib4usvARB = (PFNGLVERTEXATTRIB4USVARBPROC) load(userptr, "glVertexAttrib4usvARB");
    glad_glVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARBPROC) load(userptr, "glVertexAttribPointerARB");
}
static void glad_gl_load_GL_ARB_window_pos( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ARB_window_pos) return;
    glad_glWindowPos2dARB = (PFNGLWINDOWPOS2DARBPROC) load(userptr, "glWindowPos2dARB");
    glad_glWindowPos2dvARB = (PFNGLWINDOWPOS2DVARBPROC) load(userptr, "glWindowPos2dvARB");
    glad_glWindowPos2fARB = (PFNGLWINDOWPOS2FARBPROC) load(userptr, "glWindowPos2fARB");
    glad_glWindowPos2fvARB = (PFNGLWINDOWPOS2FVARBPROC) load(userptr, "glWindowPos2fvARB");
    glad_glWindowPos2iARB = (PFNGLWINDOWPOS2IARBPROC) load(userptr, "glWindowPos2iARB");
    glad_glWindowPos2ivARB = (PFNGLWINDOWPOS2IVARBPROC) load(userptr, "glWindowPos2ivARB");
    glad_glWindowPos2sARB = (PFNGLWINDOWPOS2SARBPROC) load(userptr, "glWindowPos2sARB");
    glad_glWindowPos2svARB = (PFNGLWINDOWPOS2SVARBPROC) load(userptr, "glWindowPos2svARB");
    glad_glWindowPos3dARB = (PFNGLWINDOWPOS3DARBPROC) load(userptr, "glWindowPos3dARB");
    glad_glWindowPos3dvARB = (PFNGLWINDOWPOS3DVARBPROC) load(userptr, "glWindowPos3dvARB");
    glad_glWindowPos3fARB = (PFNGLWINDOWPOS3FARBPROC) load(userptr, "glWindowPos3fARB");
    glad_glWindowPos3fvARB = (PFNGLWINDOWPOS3FVARBPROC) load(userptr, "glWindowPos3fvARB");
    glad_glWindowPos3iARB = (PFNGLWINDOWPOS3IARBPROC) load(userptr, "glWindowPos3iARB");
    glad_glWindowPos3ivARB = (PFNGLWINDOWPOS3IVARBPROC) load(userptr, "glWindowPos3ivARB");
    glad_glWindowPos3sARB = (PFNGLWINDOWPOS3SARBPROC) load(userptr, "glWindowPos3sARB");
    glad_glWindowPos3svARB = (PFNGLWINDOWPOS3SVARBPROC) load(userptr, "glWindowPos3svARB");
}
static void glad_gl_load_GL_ATI_draw_buffers( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ATI_draw_buffers) return;
    glad_glDrawBuffersATI = (PFNGLDRAWBUFFERSATIPROC) load(userptr, "glDrawBuffersATI");
}
static void glad_gl_load_GL_ATI_separate_stencil( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_ATI_separate_stencil) return;
    glad_glStencilFuncSeparateATI = (PFNGLSTENCILFUNCSEPARATEATIPROC) load(userptr, "glStencilFuncSeparateATI");
    glad_glStencilOpSeparateATI = (PFNGLSTENCILOPSEPARATEATIPROC) load(userptr, "glStencilOpSeparateATI");
}
static void glad_gl_load_GL_EXT_blend_color( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_blend_color) return;
    glad_glBlendColorEXT = (PFNGLBLENDCOLOREXTPROC) load(userptr, "glBlendColorEXT");
}
static void glad_gl_load_GL_EXT_blend_equation_separate( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_blend_equation_separate) return;
    glad_glBlendEquationSeparateEXT = (PFNGLBLENDEQUATIONSEPARATEEXTPROC) load(userptr, "glBlendEquationSeparateEXT");
}
static void glad_gl_load_GL_EXT_blend_func_separate( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_blend_func_separate) return;
    glad_glBlendFuncSeparateEXT = (PFNGLBLENDFUNCSEPARATEEXTPROC) load(userptr, "glBlendFuncSeparateEXT");
}
static void glad_gl_load_GL_EXT_blend_minmax( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_blend_minmax) return;
    glad_glBlendEquationEXT = (PFNGLBLENDEQUATIONEXTPROC) load(userptr, "glBlendEquationEXT");
}
static void glad_gl_load_GL_EXT_copy_texture( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_copy_texture) return;
    glad_glCopyTexImage1DEXT = (PFNGLCOPYTEXIMAGE1DEXTPROC) load(userptr, "glCopyTexImage1DEXT");
    glad_glCopyTexImage2DEXT = (PFNGLCOPYTEXIMAGE2DEXTPROC) load(userptr, "glCopyTexImage2DEXT");
    glad_glCopyTexSubImage1DEXT = (PFNGLCOPYTEXSUBIMAGE1DEXTPROC) load(userptr, "glCopyTexSubImage1DEXT");
    glad_glCopyTexSubImage2DEXT = (PFNGLCOPYTEXSUBIMAGE2DEXTPROC) load(userptr, "glCopyTexSubImage2DEXT");
    glad_glCopyTexSubImage3DEXT = (PFNGLCOPYTEXSUBIMAGE3DEXTPROC) load(userptr, "glCopyTexSubImage3DEXT");
}
static void glad_gl_load_GL_EXT_draw_range_elements( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_draw_range_elements) return;
    glad_glDrawRangeElementsEXT = (PFNGLDRAWRANGEELEMENTSEXTPROC) load(userptr, "glDrawRangeElementsEXT");
}
static void glad_gl_load_GL_EXT_fog_coord( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_fog_coord) return;
    glad_glFogCoordPointerEXT = (PFNGLFOGCOORDPOINTEREXTPROC) load(userptr, "glFogCoordPointerEXT");
    glad_glFogCoorddEXT = (PFNGLFOGCOORDDEXTPROC) load(userptr, "glFogCoorddEXT");
    glad_glFogCoorddvEXT = (PFNGLFOGCOORDDVEXTPROC) load(userptr, "glFogCoorddvEXT");
    glad_glFogCoordfEXT = (PFNGLFOGCOORDFEXTPROC) load(userptr, "glFogCoordfEXT");
    glad_glFogCoordfvEXT = (PFNGLFOGCOORDFVEXTPROC) load(userptr, "glFogCoordfvEXT");
}
static void glad_gl_load_GL_EXT_multi_draw_arrays( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_multi_draw_arrays) return;
    glad_glMultiDrawArraysEXT = (PFNGLMULTIDRAWARRAYSEXTPROC) load(userptr, "glMultiDrawArraysEXT");
    glad_glMultiDrawElementsEXT = (PFNGLMULTIDRAWELEMENTSEXTPROC) load(userptr, "glMultiDrawElementsEXT");
}
static void glad_gl_load_GL_EXT_point_parameters( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_point_parameters) return;
    glad_glPointParameterfEXT = (PFNGLPOINTPARAMETERFEXTPROC) load(userptr, "glPointParameterfEXT");
    glad_glPointParameterfvEXT = (PFNGLPOINTPARAMETERFVEXTPROC) load(userptr, "glPointParameterfvEXT");
}
static void glad_gl_load_GL_EXT_secondary_color( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_secondary_color) return;
    glad_glSecondaryColor3bEXT = (PFNGLSECONDARYCOLOR3BEXTPROC) load(userptr, "glSecondaryColor3bEXT");
    glad_glSecondaryColor3bvEXT = (PFNGLSECONDARYCOLOR3BVEXTPROC) load(userptr, "glSecondaryColor3bvEXT");
    glad_glSecondaryColor3dEXT = (PFNGLSECONDARYCOLOR3DEXTPROC) load(userptr, "glSecondaryColor3dEXT");
    glad_glSecondaryColor3dvEXT = (PFNGLSECONDARYCOLOR3DVEXTPROC) load(userptr, "glSecondaryColor3dvEXT");
    glad_glSecondaryColor3fEXT = (PFNGLSECONDARYCOLOR3FEXTPROC) load(userptr, "glSecondaryColor3fEXT");
    glad_glSecondaryColor3fvEXT = (PFNGLSECONDARYCOLOR3FVEXTPROC) load(userptr, "glSecondaryColor3fvEXT");
    glad_glSecondaryColor3iEXT = (PFNGLSECONDARYCOLOR3IEXTPROC) load(userptr, "glSecondaryColor3iEXT");
    glad_glSecondaryColor3ivEXT = (PFNGLSECONDARYCOLOR3IVEXTPROC) load(userptr, "glSecondaryColor3ivEXT");
    glad_glSecondaryColor3sEXT = (PFNGLSECONDARYCOLOR3SEXTPROC) load(userptr, "glSecondaryColor3sEXT");
    glad_glSecondaryColor3svEXT = (PFNGLSECONDARYCOLOR3SVEXTPROC) load(userptr, "glSecondaryColor3svEXT");
    glad_glSecondaryColor3ubEXT = (PFNGLSECONDARYCOLOR3UBEXTPROC) load(userptr, "glSecondaryColor3ubEXT");
    glad_glSecondaryColor3ubvEXT = (PFNGLSECONDARYCOLOR3UBVEXTPROC) load(userptr, "glSecondaryColor3ubvEXT");
    glad_glSecondaryColor3uiEXT = (PFNGLSECONDARYCOLOR3UIEXTPROC) load(userptr, "glSecondaryColor3uiEXT");
    glad_glSecondaryColor3uivEXT = (PFNGLSECONDARYCOLOR3UIVEXTPROC) load(userptr, "glSecondaryColor3uivEXT");
    glad_glSecondaryColor3usEXT = (PFNGLSECONDARYCOLOR3USEXTPROC) load(userptr, "glSecondaryColor3usEXT");
    glad_glSecondaryColor3usvEXT = (PFNGLSECONDARYCOLOR3USVEXTPROC) load(userptr, "glSecondaryColor3usvEXT");
    glad_glSecondaryColorPointerEXT = (PFNGLSECONDARYCOLORPOINTEREXTPROC) load(userptr, "glSecondaryColorPointerEXT");
}
static void glad_gl_load_GL_EXT_subtexture( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_subtexture) return;
    glad_glTexSubImage1DEXT = (PFNGLTEXSUBIMAGE1DEXTPROC) load(userptr, "glTexSubImage1DEXT");
    glad_glTexSubImage2DEXT = (PFNGLTEXSUBIMAGE2DEXTPROC) load(userptr, "glTexSubImage2DEXT");
}
static void glad_gl_load_GL_EXT_texture3D( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_texture3D) return;
    glad_glTexImage3DEXT = (PFNGLTEXIMAGE3DEXTPROC) load(userptr, "glTexImage3DEXT");
    glad_glTexSubImage3DEXT = (PFNGLTEXSUBIMAGE3DEXTPROC) load(userptr, "glTexSubImage3DEXT");
}
static void glad_gl_load_GL_EXT_texture_object( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_texture_object) return;
    glad_glAreTexturesResidentEXT = (PFNGLARETEXTURESRESIDENTEXTPROC) load(userptr, "glAreTexturesResidentEXT");
    glad_glBindTextureEXT = (PFNGLBINDTEXTUREEXTPROC) load(userptr, "glBindTextureEXT");
    glad_glDeleteTexturesEXT = (PFNGLDELETETEXTURESEXTPROC) load(userptr, "glDeleteTexturesEXT");
    glad_glGenTexturesEXT = (PFNGLGENTEXTURESEXTPROC) load(userptr, "glGenTexturesEXT");
    glad_glIsTextureEXT = (PFNGLISTEXTUREEXTPROC) load(userptr, "glIsTextureEXT");
    glad_glPrioritizeTexturesEXT = (PFNGLPRIORITIZETEXTURESEXTPROC) load(userptr, "glPrioritizeTexturesEXT");
}
static void glad_gl_load_GL_EXT_vertex_array( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_EXT_vertex_array) return;
    glad_glArrayElementEXT = (PFNGLARRAYELEMENTEXTPROC) load(userptr, "glArrayElementEXT");
    glad_glColorPointerEXT = (PFNGLCOLORPOINTEREXTPROC) load(userptr, "glColorPointerEXT");
    glad_glDrawArraysEXT = (PFNGLDRAWARRAYSEXTPROC) load(userptr, "glDrawArraysEXT");
    glad_glEdgeFlagPointerEXT = (PFNGLEDGEFLAGPOINTEREXTPROC) load(userptr, "glEdgeFlagPointerEXT");
    glad_glGetPointervEXT = (PFNGLGETPOINTERVEXTPROC) load(userptr, "glGetPointervEXT");
    glad_glIndexPointerEXT = (PFNGLINDEXPOINTEREXTPROC) load(userptr, "glIndexPointerEXT");
    glad_glNormalPointerEXT = (PFNGLNORMALPOINTEREXTPROC) load(userptr, "glNormalPointerEXT");
    glad_glTexCoordPointerEXT = (PFNGLTEXCOORDPOINTEREXTPROC) load(userptr, "glTexCoordPointerEXT");
    glad_glVertexPointerEXT = (PFNGLVERTEXPOINTEREXTPROC) load(userptr, "glVertexPointerEXT");
}
static void glad_gl_load_GL_INGR_blend_func_separate( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_INGR_blend_func_separate) return;
    glad_glBlendFuncSeparateINGR = (PFNGLBLENDFUNCSEPARATEINGRPROC) load(userptr, "glBlendFuncSeparateINGR");
}
static void glad_gl_load_GL_KHR_debug( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_KHR_debug) return;
    glad_glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC) load(userptr, "glDebugMessageCallback");
    glad_glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC) load(userptr, "glDebugMessageControl");
    glad_glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC) load(userptr, "glDebugMessageInsert");
    glad_glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC) load(userptr, "glGetDebugMessageLog");
    glad_glGetObjectLabel = (PFNGLGETOBJECTLABELPROC) load(userptr, "glGetObjectLabel");
    glad_glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC) load(userptr, "glGetObjectPtrLabel");
    glad_glGetPointerv = (PFNGLGETPOINTERVPROC) load(userptr, "glGetPointerv");
    glad_glObjectLabel = (PFNGLOBJECTLABELPROC) load(userptr, "glObjectLabel");
    glad_glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC) load(userptr, "glObjectPtrLabel");
    glad_glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC) load(userptr, "glPopDebugGroup");
    glad_glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC) load(userptr, "glPushDebugGroup");
}
static void glad_gl_load_GL_MESA_window_pos( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_MESA_window_pos) return;
    glad_glWindowPos2dMESA = (PFNGLWINDOWPOS2DMESAPROC) load(userptr, "glWindowPos2dMESA");
    glad_glWindowPos2dvMESA = (PFNGLWINDOWPOS2DVMESAPROC) load(userptr, "glWindowPos2dvMESA");
    glad_glWindowPos2fMESA = (PFNGLWINDOWPOS2FMESAPROC) load(userptr, "glWindowPos2fMESA");
    glad_glWindowPos2fvMESA = (PFNGLWINDOWPOS2FVMESAPROC) load(userptr, "glWindowPos2fvMESA");
    glad_glWindowPos2iMESA = (PFNGLWINDOWPOS2IMESAPROC) load(userptr, "glWindowPos2iMESA");
    glad_glWindowPos2ivMESA = (PFNGLWINDOWPOS2IVMESAPROC) load(userptr, "glWindowPos2ivMESA");
    glad_glWindowPos2sMESA = (PFNGLWINDOWPOS2SMESAPROC) load(userptr, "glWindowPos2sMESA");
    glad_glWindowPos2svMESA = (PFNGLWINDOWPOS2SVMESAPROC) load(userptr, "glWindowPos2svMESA");
    glad_glWindowPos3dMESA = (PFNGLWINDOWPOS3DMESAPROC) load(userptr, "glWindowPos3dMESA");
    glad_glWindowPos3dvMESA = (PFNGLWINDOWPOS3DVMESAPROC) load(userptr, "glWindowPos3dvMESA");
    glad_glWindowPos3fMESA = (PFNGLWINDOWPOS3FMESAPROC) load(userptr, "glWindowPos3fMESA");
    glad_glWindowPos3fvMESA = (PFNGLWINDOWPOS3FVMESAPROC) load(userptr, "glWindowPos3fvMESA");
    glad_glWindowPos3iMESA = (PFNGLWINDOWPOS3IMESAPROC) load(userptr, "glWindowPos3iMESA");
    glad_glWindowPos3ivMESA = (PFNGLWINDOWPOS3IVMESAPROC) load(userptr, "glWindowPos3ivMESA");
    glad_glWindowPos3sMESA = (PFNGLWINDOWPOS3SMESAPROC) load(userptr, "glWindowPos3sMESA");
    glad_glWindowPos3svMESA = (PFNGLWINDOWPOS3SVMESAPROC) load(userptr, "glWindowPos3svMESA");
    glad_glWindowPos4dMESA = (PFNGLWINDOWPOS4DMESAPROC) load(userptr, "glWindowPos4dMESA");
    glad_glWindowPos4dvMESA = (PFNGLWINDOWPOS4DVMESAPROC) load(userptr, "glWindowPos4dvMESA");
    glad_glWindowPos4fMESA = (PFNGLWINDOWPOS4FMESAPROC) load(userptr, "glWindowPos4fMESA");
    glad_glWindowPos4fvMESA = (PFNGLWINDOWPOS4FVMESAPROC) load(userptr, "glWindowPos4fvMESA");
    glad_glWindowPos4iMESA = (PFNGLWINDOWPOS4IMESAPROC) load(userptr, "glWindowPos4iMESA");
    glad_glWindowPos4ivMESA = (PFNGLWINDOWPOS4IVMESAPROC) load(userptr, "glWindowPos4ivMESA");
    glad_glWindowPos4sMESA = (PFNGLWINDOWPOS4SMESAPROC) load(userptr, "glWindowPos4sMESA");
    glad_glWindowPos4svMESA = (PFNGLWINDOWPOS4SVMESAPROC) load(userptr, "glWindowPos4svMESA");
}
static void glad_gl_load_GL_NV_point_sprite( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_NV_point_sprite) return;
    glad_glPointParameteriNV = (PFNGLPOINTPARAMETERINVPROC) load(userptr, "glPointParameteriNV");
    glad_glPointParameterivNV = (PFNGLPOINTPARAMETERIVNVPROC) load(userptr, "glPointParameterivNV");
}
static void glad_gl_load_GL_NV_vertex_program( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_NV_vertex_program) return;
    glad_glAreProgramsResidentNV = (PFNGLAREPROGRAMSRESIDENTNVPROC) load(userptr, "glAreProgramsResidentNV");
    glad_glBindProgramNV = (PFNGLBINDPROGRAMNVPROC) load(userptr, "glBindProgramNV");
    glad_glDeleteProgramsNV = (PFNGLDELETEPROGRAMSNVPROC) load(userptr, "glDeleteProgramsNV");
    glad_glExecuteProgramNV = (PFNGLEXECUTEPROGRAMNVPROC) load(userptr, "glExecuteProgramNV");
    glad_glGenProgramsNV = (PFNGLGENPROGRAMSNVPROC) load(userptr, "glGenProgramsNV");
    glad_glGetProgramParameterdvNV = (PFNGLGETPROGRAMPARAMETERDVNVPROC) load(userptr, "glGetProgramParameterdvNV");
    glad_glGetProgramParameterfvNV = (PFNGLGETPROGRAMPARAMETERFVNVPROC) load(userptr, "glGetProgramParameterfvNV");
    glad_glGetProgramStringNV = (PFNGLGETPROGRAMSTRINGNVPROC) load(userptr, "glGetProgramStringNV");
    glad_glGetProgramivNV = (PFNGLGETPROGRAMIVNVPROC) load(userptr, "glGetProgramivNV");
    glad_glGetTrackMatrixivNV = (PFNGLGETTRACKMATRIXIVNVPROC) load(userptr, "glGetTrackMatrixivNV");
    glad_glGetVertexAttribPointervNV = (PFNGLGETVERTEXATTRIBPOINTERVNVPROC) load(userptr, "glGetVertexAttribPointervNV");
    glad_glGetVertexAttribdvNV = (PFNGLGETVERTEXATTRIBDVNVPROC) load(userptr, "glGetVertexAttribdvNV");
    glad_glGetVertexAttribfvNV = (PFNGLGETVERTEXATTRIBFVNVPROC) load(userptr, "glGetVertexAttribfvNV");
    glad_glGetVertexAttribivNV = (PFNGLGETVERTEXATTRIBIVNVPROC) load(userptr, "glGetVertexAttribivNV");
    glad_glIsProgramNV = (PFNGLISPROGRAMNVPROC) load(userptr, "glIsProgramNV");
    glad_glLoadProgramNV = (PFNGLLOADPROGRAMNVPROC) load(userptr, "glLoadProgramNV");
    glad_glProgramParameter4dNV = (PFNGLPROGRAMPARAMETER4DNVPROC) load(userptr, "glProgramParameter4dNV");
    glad_glProgramParameter4dvNV = (PFNGLPROGRAMPARAMETER4DVNVPROC) load(userptr, "glProgramParameter4dvNV");
    glad_glProgramParameter4fNV = (PFNGLPROGRAMPARAMETER4FNVPROC) load(userptr, "glProgramParameter4fNV");
    glad_glProgramParameter4fvNV = (PFNGLPROGRAMPARAMETER4FVNVPROC) load(userptr, "glProgramParameter4fvNV");
    glad_glProgramParameters4dvNV = (PFNGLPROGRAMPARAMETERS4DVNVPROC) load(userptr, "glProgramParameters4dvNV");
    glad_glProgramParameters4fvNV = (PFNGLPROGRAMPARAMETERS4FVNVPROC) load(userptr, "glProgramParameters4fvNV");
    glad_glRequestResidentProgramsNV = (PFNGLREQUESTRESIDENTPROGRAMSNVPROC) load(userptr, "glRequestResidentProgramsNV");
    glad_glTrackMatrixNV = (PFNGLTRACKMATRIXNVPROC) load(userptr, "glTrackMatrixNV");
    glad_glVertexAttrib1dNV = (PFNGLVERTEXATTRIB1DNVPROC) load(userptr, "glVertexAttrib1dNV");
    glad_glVertexAttrib1dvNV = (PFNGLVERTEXATTRIB1DVNVPROC) load(userptr, "glVertexAttrib1dvNV");
    glad_glVertexAttrib1fNV = (PFNGLVERTEXATTRIB1FNVPROC) load(userptr, "glVertexAttrib1fNV");
    glad_glVertexAttrib1fvNV = (PFNGLVERTEXATTRIB1FVNVPROC) load(userptr, "glVertexAttrib1fvNV");
    glad_glVertexAttrib1sNV = (PFNGLVERTEXATTRIB1SNVPROC) load(userptr, "glVertexAttrib1sNV");
    glad_glVertexAttrib1svNV = (PFNGLVERTEXATTRIB1SVNVPROC) load(userptr, "glVertexAttrib1svNV");
    glad_glVertexAttrib2dNV = (PFNGLVERTEXATTRIB2DNVPROC) load(userptr, "glVertexAttrib2dNV");
    glad_glVertexAttrib2dvNV = (PFNGLVERTEXATTRIB2DVNVPROC) load(userptr, "glVertexAttrib2dvNV");
    glad_glVertexAttrib2fNV = (PFNGLVERTEXATTRIB2FNVPROC) load(userptr, "glVertexAttrib2fNV");
    glad_glVertexAttrib2fvNV = (PFNGLVERTEXATTRIB2FVNVPROC) load(userptr, "glVertexAttrib2fvNV");
    glad_glVertexAttrib2sNV = (PFNGLVERTEXATTRIB2SNVPROC) load(userptr, "glVertexAttrib2sNV");
    glad_glVertexAttrib2svNV = (PFNGLVERTEXATTRIB2SVNVPROC) load(userptr, "glVertexAttrib2svNV");
    glad_glVertexAttrib3dNV = (PFNGLVERTEXATTRIB3DNVPROC) load(userptr, "glVertexAttrib3dNV");
    glad_glVertexAttrib3dvNV = (PFNGLVERTEXATTRIB3DVNVPROC) load(userptr, "glVertexAttrib3dvNV");
    glad_glVertexAttrib3fNV = (PFNGLVERTEXATTRIB3FNVPROC) load(userptr, "glVertexAttrib3fNV");
    glad_glVertexAttrib3fvNV = (PFNGLVERTEXATTRIB3FVNVPROC) load(userptr, "glVertexAttrib3fvNV");
    glad_glVertexAttrib3sNV = (PFNGLVERTEXATTRIB3SNVPROC) load(userptr, "glVertexAttrib3sNV");
    glad_glVertexAttrib3svNV = (PFNGLVERTEXATTRIB3SVNVPROC) load(userptr, "glVertexAttrib3svNV");
    glad_glVertexAttrib4dNV = (PFNGLVERTEXATTRIB4DNVPROC) load(userptr, "glVertexAttrib4dNV");
    glad_glVertexAttrib4dvNV = (PFNGLVERTEXATTRIB4DVNVPROC) load(userptr, "glVertexAttrib4dvNV");
    glad_glVertexAttrib4fNV = (PFNGLVERTEXATTRIB4FNVPROC) load(userptr, "glVertexAttrib4fNV");
    glad_glVertexAttrib4fvNV = (PFNGLVERTEXATTRIB4FVNVPROC) load(userptr, "glVertexAttrib4fvNV");
    glad_glVertexAttrib4sNV = (PFNGLVERTEXATTRIB4SNVPROC) load(userptr, "glVertexAttrib4sNV");
    glad_glVertexAttrib4svNV = (PFNGLVERTEXATTRIB4SVNVPROC) load(userptr, "glVertexAttrib4svNV");
    glad_glVertexAttrib4ubNV = (PFNGLVERTEXATTRIB4UBNVPROC) load(userptr, "glVertexAttrib4ubNV");
    glad_glVertexAttrib4ubvNV = (PFNGLVERTEXATTRIB4UBVNVPROC) load(userptr, "glVertexAttrib4ubvNV");
    glad_glVertexAttribPointerNV = (PFNGLVERTEXATTRIBPOINTERNVPROC) load(userptr, "glVertexAttribPointerNV");
    glad_glVertexAttribs1dvNV = (PFNGLVERTEXATTRIBS1DVNVPROC) load(userptr, "glVertexAttribs1dvNV");
    glad_glVertexAttribs1fvNV = (PFNGLVERTEXATTRIBS1FVNVPROC) load(userptr, "glVertexAttribs1fvNV");
    glad_glVertexAttribs1svNV = (PFNGLVERTEXATTRIBS1SVNVPROC) load(userptr, "glVertexAttribs1svNV");
    glad_glVertexAttribs2dvNV = (PFNGLVERTEXATTRIBS2DVNVPROC) load(userptr, "glVertexAttribs2dvNV");
    glad_glVertexAttribs2fvNV = (PFNGLVERTEXATTRIBS2FVNVPROC) load(userptr, "glVertexAttribs2fvNV");
    glad_glVertexAttribs2svNV = (PFNGLVERTEXATTRIBS2SVNVPROC) load(userptr, "glVertexAttribs2svNV");
    glad_glVertexAttribs3dvNV = (PFNGLVERTEXATTRIBS3DVNVPROC) load(userptr, "glVertexAttribs3dvNV");
    glad_glVertexAttribs3fvNV = (PFNGLVERTEXATTRIBS3FVNVPROC) load(userptr, "glVertexAttribs3fvNV");
    glad_glVertexAttribs3svNV = (PFNGLVERTEXATTRIBS3SVNVPROC) load(userptr, "glVertexAttribs3svNV");
    glad_glVertexAttribs4dvNV = (PFNGLVERTEXATTRIBS4DVNVPROC) load(userptr, "glVertexAttribs4dvNV");
    glad_glVertexAttribs4fvNV = (PFNGLVERTEXATTRIBS4FVNVPROC) load(userptr, "glVertexAttribs4fvNV");
    glad_glVertexAttribs4svNV = (PFNGLVERTEXATTRIBS4SVNVPROC) load(userptr, "glVertexAttribs4svNV");
    glad_glVertexAttribs4ubvNV = (PFNGLVERTEXATTRIBS4UBVNVPROC) load(userptr, "glVertexAttribs4ubvNV");
}
static void glad_gl_load_GL_SGIS_point_parameters( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_GL_SGIS_point_parameters) return;
    glad_glPointParameterfSGIS = (PFNGLPOINTPARAMETERFSGISPROC) load(userptr, "glPointParameterfSGIS");
    glad_glPointParameterfvSGIS = (PFNGLPOINTPARAMETERFVSGISPROC) load(userptr, "glPointParameterfvSGIS");
}


static void glad_gl_resolve_aliases(void) {
    if (glad_glActiveTexture == NULL && glad_glActiveTextureARB != NULL) glad_glActiveTexture = (PFNGLACTIVETEXTUREPROC)glad_glActiveTextureARB;
    if (glad_glActiveTextureARB == NULL && glad_glActiveTexture != NULL) glad_glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)glad_glActiveTexture;
    if (glad_glArrayElement == NULL && glad_glArrayElementEXT != NULL) glad_glArrayElement = (PFNGLARRAYELEMENTPROC)glad_glArrayElementEXT;
    if (glad_glArrayElementEXT == NULL && glad_glArrayElement != NULL) glad_glArrayElementEXT = (PFNGLARRAYELEMENTEXTPROC)glad_glArrayElement;
    if (glad_glAttachObjectARB == NULL && glad_glAttachShader != NULL) glad_glAttachObjectARB = (PFNGLATTACHOBJECTARBPROC)glad_glAttachShader;
    if (glad_glAttachShader == NULL && glad_glAttachObjectARB != NULL) glad_glAttachShader = (PFNGLATTACHSHADERPROC)glad_glAttachObjectARB;
    if (glad_glBeginQuery == NULL && glad_glBeginQueryARB != NULL) glad_glBeginQuery = (PFNGLBEGINQUERYPROC)glad_glBeginQueryARB;
    if (glad_glBeginQueryARB == NULL && glad_glBeginQuery != NULL) glad_glBeginQueryARB = (PFNGLBEGINQUERYARBPROC)glad_glBeginQuery;
    if (glad_glBindAttribLocation == NULL && glad_glBindAttribLocationARB != NULL) glad_glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)glad_glBindAttribLocationARB;
    if (glad_glBindAttribLocationARB == NULL && glad_glBindAttribLocation != NULL) glad_glBindAttribLocationARB = (PFNGLBINDATTRIBLOCATIONARBPROC)glad_glBindAttribLocation;
    if (glad_glBindBuffer == NULL && glad_glBindBufferARB != NULL) glad_glBindBuffer = (PFNGLBINDBUFFERPROC)glad_glBindBufferARB;
    if (glad_glBindBufferARB == NULL && glad_glBindBuffer != NULL) glad_glBindBufferARB = (PFNGLBINDBUFFERARBPROC)glad_glBindBuffer;
    if (glad_glBindProgramARB == NULL && glad_glBindProgramNV != NULL) glad_glBindProgramARB = (PFNGLBINDPROGRAMARBPROC)glad_glBindProgramNV;
    if (glad_glBindProgramNV == NULL && glad_glBindProgramARB != NULL) glad_glBindProgramNV = (PFNGLBINDPROGRAMNVPROC)glad_glBindProgramARB;
    if (glad_glBindTexture == NULL && glad_glBindTextureEXT != NULL) glad_glBindTexture = (PFNGLBINDTEXTUREPROC)glad_glBindTextureEXT;
    if (glad_glBindTextureEXT == NULL && glad_glBindTexture != NULL) glad_glBindTextureEXT = (PFNGLBINDTEXTUREEXTPROC)glad_glBindTexture;
    if (glad_glBlendColor == NULL && glad_glBlendColorEXT != NULL) glad_glBlendColor = (PFNGLBLENDCOLORPROC)glad_glBlendColorEXT;
    if (glad_glBlendColorEXT == NULL && glad_glBlendColor != NULL) glad_glBlendColorEXT = (PFNGLBLENDCOLOREXTPROC)glad_glBlendColor;
    if (glad_glBlendEquation == NULL && glad_glBlendEquationEXT != NULL) glad_glBlendEquation = (PFNGLBLENDEQUATIONPROC)glad_glBlendEquationEXT;
    if (glad_glBlendEquationEXT == NULL && glad_glBlendEquation != NULL) glad_glBlendEquationEXT = (PFNGLBLENDEQUATIONEXTPROC)glad_glBlendEquation;
    if (glad_glBlendEquationSeparate == NULL && glad_glBlendEquationSeparateEXT != NULL) glad_glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)glad_glBlendEquationSeparateEXT;
    if (glad_glBlendEquationSeparateEXT == NULL && glad_glBlendEquationSeparate != NULL) glad_glBlendEquationSeparateEXT = (PFNGLBLENDEQUATIONSEPARATEEXTPROC)glad_glBlendEquationSeparate;
    if (glad_glBlendFuncSeparate == NULL && glad_glBlendFuncSeparateEXT != NULL) glad_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)glad_glBlendFuncSeparateEXT;
    if (glad_glBlendFuncSeparate == NULL && glad_glBlendFuncSeparateINGR != NULL) glad_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)glad_glBlendFuncSeparateINGR;
    if (glad_glBlendFuncSeparateEXT == NULL && glad_glBlendFuncSeparate != NULL) glad_glBlendFuncSeparateEXT = (PFNGLBLENDFUNCSEPARATEEXTPROC)glad_glBlendFuncSeparate;
    if (glad_glBlendFuncSeparateEXT == NULL && glad_glBlendFuncSeparateINGR != NULL) glad_glBlendFuncSeparateEXT = (PFNGLBLENDFUNCSEPARATEEXTPROC)glad_glBlendFuncSeparateINGR;
    if (glad_glBlendFuncSeparateINGR == NULL && glad_glBlendFuncSeparate != NULL) glad_glBlendFuncSeparateINGR = (PFNGLBLENDFUNCSEPARATEINGRPROC)glad_glBlendFuncSeparate;
    if (glad_glBlendFuncSeparateINGR == NULL && glad_glBlendFuncSeparateEXT != NULL) glad_glBlendFuncSeparateINGR = (PFNGLBLENDFUNCSEPARATEINGRPROC)glad_glBlendFuncSeparateEXT;
    if (glad_glBufferData == NULL && glad_glBufferDataARB != NULL) glad_glBufferData = (PFNGLBUFFERDATAPROC)glad_glBufferDataARB;
    if (glad_glBufferDataARB == NULL && glad_glBufferData != NULL) glad_glBufferDataARB = (PFNGLBUFFERDATAARBPROC)glad_glBufferData;
    if (glad_glBufferSubData == NULL && glad_glBufferSubDataARB != NULL) glad_glBufferSubData = (PFNGLBUFFERSUBDATAPROC)glad_glBufferSubDataARB;
    if (glad_glBufferSubDataARB == NULL && glad_glBufferSubData != NULL) glad_glBufferSubDataARB = (PFNGLBUFFERSUBDATAARBPROC)glad_glBufferSubData;
    if (glad_glClientActiveTexture == NULL && glad_glClientActiveTextureARB != NULL) glad_glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)glad_glClientActiveTextureARB;
    if (glad_glClientActiveTextureARB == NULL && glad_glClientActiveTexture != NULL) glad_glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC)glad_glClientActiveTexture;
    if (glad_glCompileShader == NULL && glad_glCompileShaderARB != NULL) glad_glCompileShader = (PFNGLCOMPILESHADERPROC)glad_glCompileShaderARB;
    if (glad_glCompileShaderARB == NULL && glad_glCompileShader != NULL) glad_glCompileShaderARB = (PFNGLCOMPILESHADERARBPROC)glad_glCompileShader;
    if (glad_glCompressedTexImage1D == NULL && glad_glCompressedTexImage1DARB != NULL) glad_glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)glad_glCompressedTexImage1DARB;
    if (glad_glCompressedTexImage1DARB == NULL && glad_glCompressedTexImage1D != NULL) glad_glCompressedTexImage1DARB = (PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)glad_glCompressedTexImage1D;
    if (glad_glCompressedTexImage2D == NULL && glad_glCompressedTexImage2DARB != NULL) glad_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)glad_glCompressedTexImage2DARB;
    if (glad_glCompressedTexImage2DARB == NULL && glad_glCompressedTexImage2D != NULL) glad_glCompressedTexImage2DARB = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)glad_glCompressedTexImage2D;
    if (glad_glCompressedTexImage3D == NULL && glad_glCompressedTexImage3DARB != NULL) glad_glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)glad_glCompressedTexImage3DARB;
    if (glad_glCompressedTexImage3DARB == NULL && glad_glCompressedTexImage3D != NULL) glad_glCompressedTexImage3DARB = (PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)glad_glCompressedTexImage3D;
    if (glad_glCompressedTexSubImage1D == NULL && glad_glCompressedTexSubImage1DARB != NULL) glad_glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)glad_glCompressedTexSubImage1DARB;
    if (glad_glCompressedTexSubImage1DARB == NULL && glad_glCompressedTexSubImage1D != NULL) glad_glCompressedTexSubImage1DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)glad_glCompressedTexSubImage1D;
    if (glad_glCompressedTexSubImage2D == NULL && glad_glCompressedTexSubImage2DARB != NULL) glad_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)glad_glCompressedTexSubImage2DARB;
    if (glad_glCompressedTexSubImage2DARB == NULL && glad_glCompressedTexSubImage2D != NULL) glad_glCompressedTexSubImage2DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)glad_glCompressedTexSubImage2D;
    if (glad_glCompressedTexSubImage3D == NULL && glad_glCompressedTexSubImage3DARB != NULL) glad_glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)glad_glCompressedTexSubImage3DARB;
    if (glad_glCompressedTexSubImage3DARB == NULL && glad_glCompressedTexSubImage3D != NULL) glad_glCompressedTexSubImage3DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)glad_glCompressedTexSubImage3D;
    if (glad_glCopyTexImage1D == NULL && glad_glCopyTexImage1DEXT != NULL) glad_glCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC)glad_glCopyTexImage1DEXT;
    if (glad_glCopyTexImage1DEXT == NULL && glad_glCopyTexImage1D != NULL) glad_glCopyTexImage1DEXT = (PFNGLCOPYTEXIMAGE1DEXTPROC)glad_glCopyTexImage1D;
    if (glad_glCopyTexImage2D == NULL && glad_glCopyTexImage2DEXT != NULL) glad_glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)glad_glCopyTexImage2DEXT;
    if (glad_glCopyTexImage2DEXT == NULL && glad_glCopyTexImage2D != NULL) glad_glCopyTexImage2DEXT = (PFNGLCOPYTEXIMAGE2DEXTPROC)glad_glCopyTexImage2D;
    if (glad_glCopyTexSubImage1D == NULL && glad_glCopyTexSubImage1DEXT != NULL) glad_glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC)glad_glCopyTexSubImage1DEXT;
    if (glad_glCopyTexSubImage1DEXT == NULL && glad_glCopyTexSubImage1D != NULL) glad_glCopyTexSubImage1DEXT = (PFNGLCOPYTEXSUBIMAGE1DEXTPROC)glad_glCopyTexSubImage1D;
    if (glad_glCopyTexSubImage2D == NULL && glad_glCopyTexSubImage2DEXT != NULL) glad_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)glad_glCopyTexSubImage2DEXT;
    if (glad_glCopyTexSubImage2DEXT == NULL && glad_glCopyTexSubImage2D != NULL) glad_glCopyTexSubImage2DEXT = (PFNGLCOPYTEXSUBIMAGE2DEXTPROC)glad_glCopyTexSubImage2D;
    if (glad_glCopyTexSubImage3D == NULL && glad_glCopyTexSubImage3DEXT != NULL) glad_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)glad_glCopyTexSubImage3DEXT;
    if (glad_glCopyTexSubImage3DEXT == NULL && glad_glCopyTexSubImage3D != NULL) glad_glCopyTexSubImage3DEXT = (PFNGLCOPYTEXSUBIMAGE3DEXTPROC)glad_glCopyTexSubImage3D;
    if (glad_glCreateProgram == NULL && glad_glCreateProgramObjectARB != NULL) glad_glCreateProgram = (PFNGLCREATEPROGRAMPROC)glad_glCreateProgramObjectARB;
    if (glad_glCreateProgramObjectARB == NULL && glad_glCreateProgram != NULL) glad_glCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC)glad_glCreateProgram;
    if (glad_glCreateShader == NULL && glad_glCreateShaderObjectARB != NULL) glad_glCreateShader = (PFNGLCREATESHADERPROC)glad_glCreateShaderObjectARB;
    if (glad_glCreateShaderObjectARB == NULL && glad_glCreateShader != NULL) glad_glCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC)glad_glCreateShader;
    if (glad_glDeleteBuffers == NULL && glad_glDeleteBuffersARB != NULL) glad_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)glad_glDeleteBuffersARB;
    if (glad_glDeleteBuffersARB == NULL && glad_glDeleteBuffers != NULL) glad_glDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC)glad_glDeleteBuffers;
    if (glad_glDeleteProgramsARB == NULL && glad_glDeleteProgramsNV != NULL) glad_glDeleteProgramsARB = (PFNGLDELETEPROGRAMSARBPROC)glad_glDeleteProgramsNV;
    if (glad_glDeleteProgramsNV == NULL && glad_glDeleteProgramsARB != NULL) glad_glDeleteProgramsNV = (PFNGLDELETEPROGRAMSNVPROC)glad_glDeleteProgramsARB;
    if (glad_glDeleteQueries == NULL && glad_glDeleteQueriesARB != NULL) glad_glDeleteQueries = (PFNGLDELETEQUERIESPROC)glad_glDeleteQueriesARB;
    if (glad_glDeleteQueriesARB == NULL && glad_glDeleteQueries != NULL) glad_glDeleteQueriesARB = (PFNGLDELETEQUERIESARBPROC)glad_glDeleteQueries;
    if (glad_glDetachObjectARB == NULL && glad_glDetachShader != NULL) glad_glDetachObjectARB = (PFNGLDETACHOBJECTARBPROC)glad_glDetachShader;
    if (glad_glDetachShader == NULL && glad_glDetachObjectARB != NULL) glad_glDetachShader = (PFNGLDETACHSHADERPROC)glad_glDetachObjectARB;
    if (glad_glDisableVertexAttribArray == NULL && glad_glDisableVertexAttribArrayARB != NULL) glad_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)glad_glDisableVertexAttribArrayARB;
    if (glad_glDisableVertexAttribArrayARB == NULL && glad_glDisableVertexAttribArray != NULL) glad_glDisableVertexAttribArrayARB = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)glad_glDisableVertexAttribArray;
    if (glad_glDrawArrays == NULL && glad_glDrawArraysEXT != NULL) glad_glDrawArrays = (PFNGLDRAWARRAYSPROC)glad_glDrawArraysEXT;
    if (glad_glDrawArraysEXT == NULL && glad_glDrawArrays != NULL) glad_glDrawArraysEXT = (PFNGLDRAWARRAYSEXTPROC)glad_glDrawArrays;
    if (glad_glDrawBuffers == NULL && glad_glDrawBuffersARB != NULL) glad_glDrawBuffers = (PFNGLDRAWBUFFERSPROC)glad_glDrawBuffersARB;
    if (glad_glDrawBuffers == NULL && glad_glDrawBuffersATI != NULL) glad_glDrawBuffers = (PFNGLDRAWBUFFERSPROC)glad_glDrawBuffersATI;
    if (glad_glDrawBuffersARB == NULL && glad_glDrawBuffers != NULL) glad_glDrawBuffersARB = (PFNGLDRAWBUFFERSARBPROC)glad_glDrawBuffers;
    if (glad_glDrawBuffersARB == NULL && glad_glDrawBuffersATI != NULL) glad_glDrawBuffersARB = (PFNGLDRAWBUFFERSARBPROC)glad_glDrawBuffersATI;
    if (glad_glDrawBuffersATI == NULL && glad_glDrawBuffers != NULL) glad_glDrawBuffersATI = (PFNGLDRAWBUFFERSATIPROC)glad_glDrawBuffers;
    if (glad_glDrawBuffersATI == NULL && glad_glDrawBuffersARB != NULL) glad_glDrawBuffersATI = (PFNGLDRAWBUFFERSATIPROC)glad_glDrawBuffersARB;
    if (glad_glDrawRangeElements == NULL && glad_glDrawRangeElementsEXT != NULL) glad_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)glad_glDrawRangeElementsEXT;
    if (glad_glDrawRangeElementsEXT == NULL && glad_glDrawRangeElements != NULL) glad_glDrawRangeElementsEXT = (PFNGLDRAWRANGEELEMENTSEXTPROC)glad_glDrawRangeElements;
    if (glad_glEnableVertexAttribArray == NULL && glad_glEnableVertexAttribArrayARB != NULL) glad_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)glad_glEnableVertexAttribArrayARB;
    if (glad_glEnableVertexAttribArrayARB == NULL && glad_glEnableVertexAttribArray != NULL) glad_glEnableVertexAttribArrayARB = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC)glad_glEnableVertexAttribArray;
    if (glad_glEndQuery == NULL && glad_glEndQueryARB != NULL) glad_glEndQuery = (PFNGLENDQUERYPROC)glad_glEndQueryARB;
    if (glad_glEndQueryARB == NULL && glad_glEndQuery != NULL) glad_glEndQueryARB = (PFNGLENDQUERYARBPROC)glad_glEndQuery;
    if (glad_glFogCoordd == NULL && glad_glFogCoorddEXT != NULL) glad_glFogCoordd = (PFNGLFOGCOORDDPROC)glad_glFogCoorddEXT;
    if (glad_glFogCoorddEXT == NULL && glad_glFogCoordd != NULL) glad_glFogCoorddEXT = (PFNGLFOGCOORDDEXTPROC)glad_glFogCoordd;
    if (glad_glFogCoorddv == NULL && glad_glFogCoorddvEXT != NULL) glad_glFogCoorddv = (PFNGLFOGCOORDDVPROC)glad_glFogCoorddvEXT;
    if (glad_glFogCoorddvEXT == NULL && glad_glFogCoorddv != NULL) glad_glFogCoorddvEXT = (PFNGLFOGCOORDDVEXTPROC)glad_glFogCoorddv;
    if (glad_glFogCoordf == NULL && glad_glFogCoordfEXT != NULL) glad_glFogCoordf = (PFNGLFOGCOORDFPROC)glad_glFogCoordfEXT;
    if (glad_glFogCoordfEXT == NULL && glad_glFogCoordf != NULL) glad_glFogCoordfEXT = (PFNGLFOGCOORDFEXTPROC)glad_glFogCoordf;
    if (glad_glFogCoordfv == NULL && glad_glFogCoordfvEXT != NULL) glad_glFogCoordfv = (PFNGLFOGCOORDFVPROC)glad_glFogCoordfvEXT;
    if (glad_glFogCoordfvEXT == NULL && glad_glFogCoordfv != NULL) glad_glFogCoordfvEXT = (PFNGLFOGCOORDFVEXTPROC)glad_glFogCoordfv;
    if (glad_glFogCoordPointer == NULL && glad_glFogCoordPointerEXT != NULL) glad_glFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC)glad_glFogCoordPointerEXT;
    if (glad_glFogCoordPointerEXT == NULL && glad_glFogCoordPointer != NULL) glad_glFogCoordPointerEXT = (PFNGLFOGCOORDPOINTEREXTPROC)glad_glFogCoordPointer;
    if (glad_glGenBuffers == NULL && glad_glGenBuffersARB != NULL) glad_glGenBuffers = (PFNGLGENBUFFERSPROC)glad_glGenBuffersARB;
    if (glad_glGenBuffersARB == NULL && glad_glGenBuffers != NULL) glad_glGenBuffersARB = (PFNGLGENBUFFERSARBPROC)glad_glGenBuffers;
    if (glad_glGenProgramsARB == NULL && glad_glGenProgramsNV != NULL) glad_glGenProgramsARB = (PFNGLGENPROGRAMSARBPROC)glad_glGenProgramsNV;
    if (glad_glGenProgramsNV == NULL && glad_glGenProgramsARB != NULL) glad_glGenProgramsNV = (PFNGLGENPROGRAMSNVPROC)glad_glGenProgramsARB;
    if (glad_glGenQueries == NULL && glad_glGenQueriesARB != NULL) glad_glGenQueries = (PFNGLGENQUERIESPROC)glad_glGenQueriesARB;
    if (glad_glGenQueriesARB == NULL && glad_glGenQueries != NULL) glad_glGenQueriesARB = (PFNGLGENQUERIESARBPROC)glad_glGenQueries;
    if (glad_glGetActiveAttrib == NULL && glad_glGetActiveAttribARB != NULL) glad_glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)glad_glGetActiveAttribARB;
    if (glad_glGetActiveAttribARB == NULL && glad_glGetActiveAttrib != NULL) glad_glGetActiveAttribARB = (PFNGLGETACTIVEATTRIBARBPROC)glad_glGetActiveAttrib;
    if (glad_glGetActiveUniform == NULL && glad_glGetActiveUniformARB != NULL) glad_glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)glad_glGetActiveUniformARB;
    if (glad_glGetActiveUniformARB == NULL && glad_glGetActiveUniform != NULL) glad_glGetActiveUniformARB = (PFNGLGETACTIVEUNIFORMARBPROC)glad_glGetActiveUniform;
    if (glad_glGetAttribLocation == NULL && glad_glGetAttribLocationARB != NULL) glad_glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)glad_glGetAttribLocationARB;
    if (glad_glGetAttribLocationARB == NULL && glad_glGetAttribLocation != NULL) glad_glGetAttribLocationARB = (PFNGLGETATTRIBLOCATIONARBPROC)glad_glGetAttribLocation;
    if (glad_glGetBufferParameteriv == NULL && glad_glGetBufferParameterivARB != NULL) glad_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)glad_glGetBufferParameterivARB;
    if (glad_glGetBufferParameterivARB == NULL && glad_glGetBufferParameteriv != NULL) glad_glGetBufferParameterivARB = (PFNGLGETBUFFERPARAMETERIVARBPROC)glad_glGetBufferParameteriv;
    if (glad_glGetBufferPointerv == NULL && glad_glGetBufferPointervARB != NULL) glad_glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)glad_glGetBufferPointervARB;
    if (glad_glGetBufferPointervARB == NULL && glad_glGetBufferPointerv != NULL) glad_glGetBufferPointervARB = (PFNGLGETBUFFERPOINTERVARBPROC)glad_glGetBufferPointerv;
    if (glad_glGetBufferSubData == NULL && glad_glGetBufferSubDataARB != NULL) glad_glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)glad_glGetBufferSubDataARB;
    if (glad_glGetBufferSubDataARB == NULL && glad_glGetBufferSubData != NULL) glad_glGetBufferSubDataARB = (PFNGLGETBUFFERSUBDATAARBPROC)glad_glGetBufferSubData;
    if (glad_glGetCompressedTexImage == NULL && glad_glGetCompressedTexImageARB != NULL) glad_glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)glad_glGetCompressedTexImageARB;
    if (glad_glGetCompressedTexImageARB == NULL && glad_glGetCompressedTexImage != NULL) glad_glGetCompressedTexImageARB = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)glad_glGetCompressedTexImage;
    if (glad_glGetPointerv == NULL && glad_glGetPointervEXT != NULL) glad_glGetPointerv = (PFNGLGETPOINTERVPROC)glad_glGetPointervEXT;
    if (glad_glGetPointervEXT == NULL && glad_glGetPointerv != NULL) glad_glGetPointervEXT = (PFNGLGETPOINTERVEXTPROC)glad_glGetPointerv;
    if (glad_glGetQueryiv == NULL && glad_glGetQueryivARB != NULL) glad_glGetQueryiv = (PFNGLGETQUERYIVPROC)glad_glGetQueryivARB;
    if (glad_glGetQueryivARB == NULL && glad_glGetQueryiv != NULL) glad_glGetQueryivARB = (PFNGLGETQUERYIVARBPROC)glad_glGetQueryiv;
    if (glad_glGetQueryObjectiv == NULL && glad_glGetQueryObjectivARB != NULL) glad_glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)glad_glGetQueryObjectivARB;
    if (glad_glGetQueryObjectivARB == NULL && glad_glGetQueryObjectiv != NULL) glad_glGetQueryObjectivARB = (PFNGLGETQUERYOBJECTIVARBPROC)glad_glGetQueryObjectiv;
    if (glad_glGetQueryObjectuiv == NULL && glad_glGetQueryObjectuivARB != NULL) glad_glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)glad_glGetQueryObjectuivARB;
    if (glad_glGetQueryObjectuivARB == NULL && glad_glGetQueryObjectuiv != NULL) glad_glGetQueryObjectuivARB = (PFNGLGETQUERYOBJECTUIVARBPROC)glad_glGetQueryObjectuiv;
    if (glad_glGetShaderSource == NULL && glad_glGetShaderSourceARB != NULL) glad_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)glad_glGetShaderSourceARB;
    if (glad_glGetShaderSourceARB == NULL && glad_glGetShaderSource != NULL) glad_glGetShaderSourceARB = (PFNGLGETSHADERSOURCEARBPROC)glad_glGetShaderSource;
    if (glad_glGetUniformfv == NULL && glad_glGetUniformfvARB != NULL) glad_glGetUniformfv = (PFNGLGETUNIFORMFVPROC)glad_glGetUniformfvARB;
    if (glad_glGetUniformfvARB == NULL && glad_glGetUniformfv != NULL) glad_glGetUniformfvARB = (PFNGLGETUNIFORMFVARBPROC)glad_glGetUniformfv;
    if (glad_glGetUniformiv == NULL && glad_glGetUniformivARB != NULL) glad_glGetUniformiv = (PFNGLGETUNIFORMIVPROC)glad_glGetUniformivARB;
    if (glad_glGetUniformivARB == NULL && glad_glGetUniformiv != NULL) glad_glGetUniformivARB = (PFNGLGETUNIFORMIVARBPROC)glad_glGetUniformiv;
    if (glad_glGetUniformLocation == NULL && glad_glGetUniformLocationARB != NULL) glad_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)glad_glGetUniformLocationARB;
    if (glad_glGetUniformLocationARB == NULL && glad_glGetUniformLocation != NULL) glad_glGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC)glad_glGetUniformLocation;
    if (glad_glGetVertexAttribdv == NULL && glad_glGetVertexAttribdvARB != NULL) glad_glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)glad_glGetVertexAttribdvARB;
    if (glad_glGetVertexAttribdv == NULL && glad_glGetVertexAttribdvNV != NULL) glad_glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)glad_glGetVertexAttribdvNV;
    if (glad_glGetVertexAttribdvARB == NULL && glad_glGetVertexAttribdv != NULL) glad_glGetVertexAttribdvARB = (PFNGLGETVERTEXATTRIBDVARBPROC)glad_glGetVertexAttribdv;
    if (glad_glGetVertexAttribdvARB == NULL && glad_glGetVertexAttribdvNV != NULL) glad_glGetVertexAttribdvARB = (PFNGLGETVERTEXATTRIBDVARBPROC)glad_glGetVertexAttribdvNV;
    if (glad_glGetVertexAttribdvNV == NULL && glad_glGetVertexAttribdv != NULL) glad_glGetVertexAttribdvNV = (PFNGLGETVERTEXATTRIBDVNVPROC)glad_glGetVertexAttribdv;
    if (glad_glGetVertexAttribdvNV == NULL && glad_glGetVertexAttribdvARB != NULL) glad_glGetVertexAttribdvNV = (PFNGLGETVERTEXATTRIBDVNVPROC)glad_glGetVertexAttribdvARB;
    if (glad_glGetVertexAttribfv == NULL && glad_glGetVertexAttribfvARB != NULL) glad_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)glad_glGetVertexAttribfvARB;
    if (glad_glGetVertexAttribfv == NULL && glad_glGetVertexAttribfvNV != NULL) glad_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)glad_glGetVertexAttribfvNV;
    if (glad_glGetVertexAttribfvARB == NULL && glad_glGetVertexAttribfv != NULL) glad_glGetVertexAttribfvARB = (PFNGLGETVERTEXATTRIBFVARBPROC)glad_glGetVertexAttribfv;
    if (glad_glGetVertexAttribfvARB == NULL && glad_glGetVertexAttribfvNV != NULL) glad_glGetVertexAttribfvARB = (PFNGLGETVERTEXATTRIBFVARBPROC)glad_glGetVertexAttribfvNV;
    if (glad_glGetVertexAttribfvNV == NULL && glad_glGetVertexAttribfv != NULL) glad_glGetVertexAttribfvNV = (PFNGLGETVERTEXATTRIBFVNVPROC)glad_glGetVertexAttribfv;
    if (glad_glGetVertexAttribfvNV == NULL && glad_glGetVertexAttribfvARB != NULL) glad_glGetVertexAttribfvNV = (PFNGLGETVERTEXATTRIBFVNVPROC)glad_glGetVertexAttribfvARB;
    if (glad_glGetVertexAttribiv == NULL && glad_glGetVertexAttribivARB != NULL) glad_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)glad_glGetVertexAttribivARB;
    if (glad_glGetVertexAttribiv == NULL && glad_glGetVertexAttribivNV != NULL) glad_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)glad_glGetVertexAttribivNV;
    if (glad_glGetVertexAttribivARB == NULL && glad_glGetVertexAttribiv != NULL) glad_glGetVertexAttribivARB = (PFNGLGETVERTEXATTRIBIVARBPROC)glad_glGetVertexAttribiv;
    if (glad_glGetVertexAttribivARB == NULL && glad_glGetVertexAttribivNV != NULL) glad_glGetVertexAttribivARB = (PFNGLGETVERTEXATTRIBIVARBPROC)glad_glGetVertexAttribivNV;
    if (glad_glGetVertexAttribivNV == NULL && glad_glGetVertexAttribiv != NULL) glad_glGetVertexAttribivNV = (PFNGLGETVERTEXATTRIBIVNVPROC)glad_glGetVertexAttribiv;
    if (glad_glGetVertexAttribivNV == NULL && glad_glGetVertexAttribivARB != NULL) glad_glGetVertexAttribivNV = (PFNGLGETVERTEXATTRIBIVNVPROC)glad_glGetVertexAttribivARB;
    if (glad_glGetVertexAttribPointerv == NULL && glad_glGetVertexAttribPointervARB != NULL) glad_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)glad_glGetVertexAttribPointervARB;
    if (glad_glGetVertexAttribPointerv == NULL && glad_glGetVertexAttribPointervNV != NULL) glad_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)glad_glGetVertexAttribPointervNV;
    if (glad_glGetVertexAttribPointervARB == NULL && glad_glGetVertexAttribPointerv != NULL) glad_glGetVertexAttribPointervARB = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC)glad_glGetVertexAttribPointerv;
    if (glad_glGetVertexAttribPointervARB == NULL && glad_glGetVertexAttribPointervNV != NULL) glad_glGetVertexAttribPointervARB = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC)glad_glGetVertexAttribPointervNV;
    if (glad_glGetVertexAttribPointervNV == NULL && glad_glGetVertexAttribPointerv != NULL) glad_glGetVertexAttribPointervNV = (PFNGLGETVERTEXATTRIBPOINTERVNVPROC)glad_glGetVertexAttribPointerv;
    if (glad_glGetVertexAttribPointervNV == NULL && glad_glGetVertexAttribPointervARB != NULL) glad_glGetVertexAttribPointervNV = (PFNGLGETVERTEXATTRIBPOINTERVNVPROC)glad_glGetVertexAttribPointervARB;
    if (glad_glIsBuffer == NULL && glad_glIsBufferARB != NULL) glad_glIsBuffer = (PFNGLISBUFFERPROC)glad_glIsBufferARB;
    if (glad_glIsBufferARB == NULL && glad_glIsBuffer != NULL) glad_glIsBufferARB = (PFNGLISBUFFERARBPROC)glad_glIsBuffer;
    if (glad_glIsProgramARB == NULL && glad_glIsProgramNV != NULL) glad_glIsProgramARB = (PFNGLISPROGRAMARBPROC)glad_glIsProgramNV;
    if (glad_glIsProgramNV == NULL && glad_glIsProgramARB != NULL) glad_glIsProgramNV = (PFNGLISPROGRAMNVPROC)glad_glIsProgramARB;
    if (glad_glIsQuery == NULL && glad_glIsQueryARB != NULL) glad_glIsQuery = (PFNGLISQUERYPROC)glad_glIsQueryARB;
    if (glad_glIsQueryARB == NULL && glad_glIsQuery != NULL) glad_glIsQueryARB = (PFNGLISQUERYARBPROC)glad_glIsQuery;
    if (glad_glLinkProgram == NULL && glad_glLinkProgramARB != NULL) glad_glLinkProgram = (PFNGLLINKPROGRAMPROC)glad_glLinkProgramARB;
    if (glad_glLinkProgramARB == NULL && glad_glLinkProgram != NULL) glad_glLinkProgramARB = (PFNGLLINKPROGRAMARBPROC)glad_glLinkProgram;
    if (glad_glLoadTransposeMatrixd == NULL && glad_glLoadTransposeMatrixdARB != NULL) glad_glLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC)glad_glLoadTransposeMatrixdARB;
    if (glad_glLoadTransposeMatrixdARB == NULL && glad_glLoadTransposeMatrixd != NULL) glad_glLoadTransposeMatrixdARB = (PFNGLLOADTRANSPOSEMATRIXDARBPROC)glad_glLoadTransposeMatrixd;
    if (glad_glLoadTransposeMatrixf == NULL && glad_glLoadTransposeMatrixfARB != NULL) glad_glLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC)glad_glLoadTransposeMatrixfARB;
    if (glad_glLoadTransposeMatrixfARB == NULL && glad_glLoadTransposeMatrixf != NULL) glad_glLoadTransposeMatrixfARB = (PFNGLLOADTRANSPOSEMATRIXFARBPROC)glad_glLoadTransposeMatrixf;
    if (glad_glMapBuffer == NULL && glad_glMapBufferARB != NULL) glad_glMapBuffer = (PFNGLMAPBUFFERPROC)glad_glMapBufferARB;
    if (glad_glMapBufferARB == NULL && glad_glMapBuffer != NULL) glad_glMapBufferARB = (PFNGLMAPBUFFERARBPROC)glad_glMapBuffer;
    if (glad_glMultiDrawArrays == NULL && glad_glMultiDrawArraysEXT != NULL) glad_glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)glad_glMultiDrawArraysEXT;
    if (glad_glMultiDrawArraysEXT == NULL && glad_glMultiDrawArrays != NULL) glad_glMultiDrawArraysEXT = (PFNGLMULTIDRAWARRAYSEXTPROC)glad_glMultiDrawArrays;
    if (glad_glMultiDrawElements == NULL && glad_glMultiDrawElementsEXT != NULL) glad_glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)glad_glMultiDrawElementsEXT;
    if (glad_glMultiDrawElementsEXT == NULL && glad_glMultiDrawElements != NULL) glad_glMultiDrawElementsEXT = (PFNGLMULTIDRAWELEMENTSEXTPROC)glad_glMultiDrawElements;
    if (glad_glMultiTexCoord1d == NULL && glad_glMultiTexCoord1dARB != NULL) glad_glMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC)glad_glMultiTexCoord1dARB;
    if (glad_glMultiTexCoord1dARB == NULL && glad_glMultiTexCoord1d != NULL) glad_glMultiTexCoord1dARB = (PFNGLMULTITEXCOORD1DARBPROC)glad_glMultiTexCoord1d;
    if (glad_glMultiTexCoord1dv == NULL && glad_glMultiTexCoord1dvARB != NULL) glad_glMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC)glad_glMultiTexCoord1dvARB;
    if (glad_glMultiTexCoord1dvARB == NULL && glad_glMultiTexCoord1dv != NULL) glad_glMultiTexCoord1dvARB = (PFNGLMULTITEXCOORD1DVARBPROC)glad_glMultiTexCoord1dv;
    if (glad_glMultiTexCoord1f == NULL && glad_glMultiTexCoord1fARB != NULL) glad_glMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC)glad_glMultiTexCoord1fARB;
    if (glad_glMultiTexCoord1fARB == NULL && glad_glMultiTexCoord1f != NULL) glad_glMultiTexCoord1fARB = (PFNGLMULTITEXCOORD1FARBPROC)glad_glMultiTexCoord1f;
    if (glad_glMultiTexCoord1fv == NULL && glad_glMultiTexCoord1fvARB != NULL) glad_glMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC)glad_glMultiTexCoord1fvARB;
    if (glad_glMultiTexCoord1fvARB == NULL && glad_glMultiTexCoord1fv != NULL) glad_glMultiTexCoord1fvARB = (PFNGLMULTITEXCOORD1FVARBPROC)glad_glMultiTexCoord1fv;
    if (glad_glMultiTexCoord1i == NULL && glad_glMultiTexCoord1iARB != NULL) glad_glMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC)glad_glMultiTexCoord1iARB;
    if (glad_glMultiTexCoord1iARB == NULL && glad_glMultiTexCoord1i != NULL) glad_glMultiTexCoord1iARB = (PFNGLMULTITEXCOORD1IARBPROC)glad_glMultiTexCoord1i;
    if (glad_glMultiTexCoord1iv == NULL && glad_glMultiTexCoord1ivARB != NULL) glad_glMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC)glad_glMultiTexCoord1ivARB;
    if (glad_glMultiTexCoord1ivARB == NULL && glad_glMultiTexCoord1iv != NULL) glad_glMultiTexCoord1ivARB = (PFNGLMULTITEXCOORD1IVARBPROC)glad_glMultiTexCoord1iv;
    if (glad_glMultiTexCoord1s == NULL && glad_glMultiTexCoord1sARB != NULL) glad_glMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC)glad_glMultiTexCoord1sARB;
    if (glad_glMultiTexCoord1sARB == NULL && glad_glMultiTexCoord1s != NULL) glad_glMultiTexCoord1sARB = (PFNGLMULTITEXCOORD1SARBPROC)glad_glMultiTexCoord1s;
    if (glad_glMultiTexCoord1sv == NULL && glad_glMultiTexCoord1svARB != NULL) glad_glMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC)glad_glMultiTexCoord1svARB;
    if (glad_glMultiTexCoord1svARB == NULL && glad_glMultiTexCoord1sv != NULL) glad_glMultiTexCoord1svARB = (PFNGLMULTITEXCOORD1SVARBPROC)glad_glMultiTexCoord1sv;
    if (glad_glMultiTexCoord2d == NULL && glad_glMultiTexCoord2dARB != NULL) glad_glMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC)glad_glMultiTexCoord2dARB;
    if (glad_glMultiTexCoord2dARB == NULL && glad_glMultiTexCoord2d != NULL) glad_glMultiTexCoord2dARB = (PFNGLMULTITEXCOORD2DARBPROC)glad_glMultiTexCoord2d;
    if (glad_glMultiTexCoord2dv == NULL && glad_glMultiTexCoord2dvARB != NULL) glad_glMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC)glad_glMultiTexCoord2dvARB;
    if (glad_glMultiTexCoord2dvARB == NULL && glad_glMultiTexCoord2dv != NULL) glad_glMultiTexCoord2dvARB = (PFNGLMULTITEXCOORD2DVARBPROC)glad_glMultiTexCoord2dv;
    if (glad_glMultiTexCoord2f == NULL && glad_glMultiTexCoord2fARB != NULL) glad_glMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC)glad_glMultiTexCoord2fARB;
    if (glad_glMultiTexCoord2fARB == NULL && glad_glMultiTexCoord2f != NULL) glad_glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC)glad_glMultiTexCoord2f;
    if (glad_glMultiTexCoord2fv == NULL && glad_glMultiTexCoord2fvARB != NULL) glad_glMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC)glad_glMultiTexCoord2fvARB;
    if (glad_glMultiTexCoord2fvARB == NULL && glad_glMultiTexCoord2fv != NULL) glad_glMultiTexCoord2fvARB = (PFNGLMULTITEXCOORD2FVARBPROC)glad_glMultiTexCoord2fv;
    if (glad_glMultiTexCoord2i == NULL && glad_glMultiTexCoord2iARB != NULL) glad_glMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC)glad_glMultiTexCoord2iARB;
    if (glad_glMultiTexCoord2iARB == NULL && glad_glMultiTexCoord2i != NULL) glad_glMultiTexCoord2iARB = (PFNGLMULTITEXCOORD2IARBPROC)glad_glMultiTexCoord2i;
    if (glad_glMultiTexCoord2iv == NULL && glad_glMultiTexCoord2ivARB != NULL) glad_glMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC)glad_glMultiTexCoord2ivARB;
    if (glad_glMultiTexCoord2ivARB == NULL && glad_glMultiTexCoord2iv != NULL) glad_glMultiTexCoord2ivARB = (PFNGLMULTITEXCOORD2IVARBPROC)glad_glMultiTexCoord2iv;
    if (glad_glMultiTexCoord2s == NULL && glad_glMultiTexCoord2sARB != NULL) glad_glMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC)glad_glMultiTexCoord2sARB;
    if (glad_glMultiTexCoord2sARB == NULL && glad_glMultiTexCoord2s != NULL) glad_glMultiTexCoord2sARB = (PFNGLMULTITEXCOORD2SARBPROC)glad_glMultiTexCoord2s;
    if (glad_glMultiTexCoord2sv == NULL && glad_glMultiTexCoord2svARB != NULL) glad_glMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC)glad_glMultiTexCoord2svARB;
    if (glad_glMultiTexCoord2svARB == NULL && glad_glMultiTexCoord2sv != NULL) glad_glMultiTexCoord2svARB = (PFNGLMULTITEXCOORD2SVARBPROC)glad_glMultiTexCoord2sv;
    if (glad_glMultiTexCoord3d == NULL && glad_glMultiTexCoord3dARB != NULL) glad_glMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC)glad_glMultiTexCoord3dARB;
    if (glad_glMultiTexCoord3dARB == NULL && glad_glMultiTexCoord3d != NULL) glad_glMultiTexCoord3dARB = (PFNGLMULTITEXCOORD3DARBPROC)glad_glMultiTexCoord3d;
    if (glad_glMultiTexCoord3dv == NULL && glad_glMultiTexCoord3dvARB != NULL) glad_glMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC)glad_glMultiTexCoord3dvARB;
    if (glad_glMultiTexCoord3dvARB == NULL && glad_glMultiTexCoord3dv != NULL) glad_glMultiTexCoord3dvARB = (PFNGLMULTITEXCOORD3DVARBPROC)glad_glMultiTexCoord3dv;
    if (glad_glMultiTexCoord3f == NULL && glad_glMultiTexCoord3fARB != NULL) glad_glMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC)glad_glMultiTexCoord3fARB;
    if (glad_glMultiTexCoord3fARB == NULL && glad_glMultiTexCoord3f != NULL) glad_glMultiTexCoord3fARB = (PFNGLMULTITEXCOORD3FARBPROC)glad_glMultiTexCoord3f;
    if (glad_glMultiTexCoord3fv == NULL && glad_glMultiTexCoord3fvARB != NULL) glad_glMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC)glad_glMultiTexCoord3fvARB;
    if (glad_glMultiTexCoord3fvARB == NULL && glad_glMultiTexCoord3fv != NULL) glad_glMultiTexCoord3fvARB = (PFNGLMULTITEXCOORD3FVARBPROC)glad_glMultiTexCoord3fv;
    if (glad_glMultiTexCoord3i == NULL && glad_glMultiTexCoord3iARB != NULL) glad_glMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC)glad_glMultiTexCoord3iARB;
    if (glad_glMultiTexCoord3iARB == NULL && glad_glMultiTexCoord3i != NULL) glad_glMultiTexCoord3iARB = (PFNGLMULTITEXCOORD3IARBPROC)glad_glMultiTexCoord3i;
    if (glad_glMultiTexCoord3iv == NULL && glad_glMultiTexCoord3ivARB != NULL) glad_glMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC)glad_glMultiTexCoord3ivARB;
    if (glad_glMultiTexCoord3ivARB == NULL && glad_glMultiTexCoord3iv != NULL) glad_glMultiTexCoord3ivARB = (PFNGLMULTITEXCOORD3IVARBPROC)glad_glMultiTexCoord3iv;
    if (glad_glMultiTexCoord3s == NULL && glad_glMultiTexCoord3sARB != NULL) glad_glMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC)glad_glMultiTexCoord3sARB;
    if (glad_glMultiTexCoord3sARB == NULL && glad_glMultiTexCoord3s != NULL) glad_glMultiTexCoord3sARB = (PFNGLMULTITEXCOORD3SARBPROC)glad_glMultiTexCoord3s;
    if (glad_glMultiTexCoord3sv == NULL && glad_glMultiTexCoord3svARB != NULL) glad_glMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC)glad_glMultiTexCoord3svARB;
    if (glad_glMultiTexCoord3svARB == NULL && glad_glMultiTexCoord3sv != NULL) glad_glMultiTexCoord3svARB = (PFNGLMULTITEXCOORD3SVARBPROC)glad_glMultiTexCoord3sv;
    if (glad_glMultiTexCoord4d == NULL && glad_glMultiTexCoord4dARB != NULL) glad_glMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC)glad_glMultiTexCoord4dARB;
    if (glad_glMultiTexCoord4dARB == NULL && glad_glMultiTexCoord4d != NULL) glad_glMultiTexCoord4dARB = (PFNGLMULTITEXCOORD4DARBPROC)glad_glMultiTexCoord4d;
    if (glad_glMultiTexCoord4dv == NULL && glad_glMultiTexCoord4dvARB != NULL) glad_glMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC)glad_glMultiTexCoord4dvARB;
    if (glad_glMultiTexCoord4dvARB == NULL && glad_glMultiTexCoord4dv != NULL) glad_glMultiTexCoord4dvARB = (PFNGLMULTITEXCOORD4DVARBPROC)glad_glMultiTexCoord4dv;
    if (glad_glMultiTexCoord4f == NULL && glad_glMultiTexCoord4fARB != NULL) glad_glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC)glad_glMultiTexCoord4fARB;
    if (glad_glMultiTexCoord4fARB == NULL && glad_glMultiTexCoord4f != NULL) glad_glMultiTexCoord4fARB = (PFNGLMULTITEXCOORD4FARBPROC)glad_glMultiTexCoord4f;
    if (glad_glMultiTexCoord4fv == NULL && glad_glMultiTexCoord4fvARB != NULL) glad_glMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC)glad_glMultiTexCoord4fvARB;
    if (glad_glMultiTexCoord4fvARB == NULL && glad_glMultiTexCoord4fv != NULL) glad_glMultiTexCoord4fvARB = (PFNGLMULTITEXCOORD4FVARBPROC)glad_glMultiTexCoord4fv;
    if (glad_glMultiTexCoord4i == NULL && glad_glMultiTexCoord4iARB != NULL) glad_glMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC)glad_glMultiTexCoord4iARB;
    if (glad_glMultiTexCoord4iARB == NULL && glad_glMultiTexCoord4i != NULL) glad_glMultiTexCoord4iARB = (PFNGLMULTITEXCOORD4IARBPROC)glad_glMultiTexCoord4i;
    if (glad_glMultiTexCoord4iv == NULL && glad_glMultiTexCoord4ivARB != NULL) glad_glMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC)glad_glMultiTexCoord4ivARB;
    if (glad_glMultiTexCoord4ivARB == NULL && glad_glMultiTexCoord4iv != NULL) glad_glMultiTexCoord4ivARB = (PFNGLMULTITEXCOORD4IVARBPROC)glad_glMultiTexCoord4iv;
    if (glad_glMultiTexCoord4s == NULL && glad_glMultiTexCoord4sARB != NULL) glad_glMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC)glad_glMultiTexCoord4sARB;
    if (glad_glMultiTexCoord4sARB == NULL && glad_glMultiTexCoord4s != NULL) glad_glMultiTexCoord4sARB = (PFNGLMULTITEXCOORD4SARBPROC)glad_glMultiTexCoord4s;
    if (glad_glMultiTexCoord4sv == NULL && glad_glMultiTexCoord4svARB != NULL) glad_glMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC)glad_glMultiTexCoord4svARB;
    if (glad_glMultiTexCoord4svARB == NULL && glad_glMultiTexCoord4sv != NULL) glad_glMultiTexCoord4svARB = (PFNGLMULTITEXCOORD4SVARBPROC)glad_glMultiTexCoord4sv;
    if (glad_glMultTransposeMatrixd == NULL && glad_glMultTransposeMatrixdARB != NULL) glad_glMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC)glad_glMultTransposeMatrixdARB;
    if (glad_glMultTransposeMatrixdARB == NULL && glad_glMultTransposeMatrixd != NULL) glad_glMultTransposeMatrixdARB = (PFNGLMULTTRANSPOSEMATRIXDARBPROC)glad_glMultTransposeMatrixd;
    if (glad_glMultTransposeMatrixf == NULL && glad_glMultTransposeMatrixfARB != NULL) glad_glMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC)glad_glMultTransposeMatrixfARB;
    if (glad_glMultTransposeMatrixfARB == NULL && glad_glMultTransposeMatrixf != NULL) glad_glMultTransposeMatrixfARB = (PFNGLMULTTRANSPOSEMATRIXFARBPROC)glad_glMultTransposeMatrixf;
    if (glad_glPointParameterf == NULL && glad_glPointParameterfARB != NULL) glad_glPointParameterf = (PFNGLPOINTPARAMETERFPROC)glad_glPointParameterfARB;
    if (glad_glPointParameterf == NULL && glad_glPointParameterfEXT != NULL) glad_glPointParameterf = (PFNGLPOINTPARAMETERFPROC)glad_glPointParameterfEXT;
    if (glad_glPointParameterf == NULL && glad_glPointParameterfSGIS != NULL) glad_glPointParameterf = (PFNGLPOINTPARAMETERFPROC)glad_glPointParameterfSGIS;
    if (glad_glPointParameterfARB == NULL && glad_glPointParameterf != NULL) glad_glPointParameterfARB = (PFNGLPOINTPARAMETERFARBPROC)glad_glPointParameterf;
    if (glad_glPointParameterfARB == NULL && glad_glPointParameterfEXT != NULL) glad_glPointParameterfARB = (PFNGLPOINTPARAMETERFARBPROC)glad_glPointParameterfEXT;
    if (glad_glPointParameterfARB == NULL && glad_glPointParameterfSGIS != NULL) glad_glPointParameterfARB = (PFNGLPOINTPARAMETERFARBPROC)glad_glPointParameterfSGIS;
    if (glad_glPointParameterfEXT == NULL && glad_glPointParameterf != NULL) glad_glPointParameterfEXT = (PFNGLPOINTPARAMETERFEXTPROC)glad_glPointParameterf;
    if (glad_glPointParameterfEXT == NULL && glad_glPointParameterfARB != NULL) glad_glPointParameterfEXT = (PFNGLPOINTPARAMETERFEXTPROC)glad_glPointParameterfARB;
    if (glad_glPointParameterfEXT == NULL && glad_glPointParameterfSGIS != NULL) glad_glPointParameterfEXT = (PFNGLPOINTPARAMETERFEXTPROC)glad_glPointParameterfSGIS;
    if (glad_glPointParameterfSGIS == NULL && glad_glPointParameterf != NULL) glad_glPointParameterfSGIS = (PFNGLPOINTPARAMETERFSGISPROC)glad_glPointParameterf;
    if (glad_glPointParameterfSGIS == NULL && glad_glPointParameterfARB != NULL) glad_glPointParameterfSGIS = (PFNGLPOINTPARAMETERFSGISPROC)glad_glPointParameterfARB;
    if (glad_glPointParameterfSGIS == NULL && glad_glPointParameterfEXT != NULL) glad_glPointParameterfSGIS = (PFNGLPOINTPARAMETERFSGISPROC)glad_glPointParameterfEXT;
    if (glad_glPointParameterfv == NULL && glad_glPointParameterfvARB != NULL) glad_glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)glad_glPointParameterfvARB;
    if (glad_glPointParameterfv == NULL && glad_glPointParameterfvEXT != NULL) glad_glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)glad_glPointParameterfvEXT;
    if (glad_glPointParameterfv == NULL && glad_glPointParameterfvSGIS != NULL) glad_glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)glad_glPointParameterfvSGIS;
    if (glad_glPointParameterfvARB == NULL && glad_glPointParameterfv != NULL) glad_glPointParameterfvARB = (PFNGLPOINTPARAMETERFVARBPROC)glad_glPointParameterfv;
    if (glad_glPointParameterfvARB == NULL && glad_glPointParameterfvEXT != NULL) glad_glPointParameterfvARB = (PFNGLPOINTPARAMETERFVARBPROC)glad_glPointParameterfvEXT;
    if (glad_glPointParameterfvARB == NULL && glad_glPointParameterfvSGIS != NULL) glad_glPointParameterfvARB = (PFNGLPOINTPARAMETERFVARBPROC)glad_glPointParameterfvSGIS;
    if (glad_glPointParameterfvEXT == NULL && glad_glPointParameterfv != NULL) glad_glPointParameterfvEXT = (PFNGLPOINTPARAMETERFVEXTPROC)glad_glPointParameterfv;
    if (glad_glPointParameterfvEXT == NULL && glad_glPointParameterfvARB != NULL) glad_glPointParameterfvEXT = (PFNGLPOINTPARAMETERFVEXTPROC)glad_glPointParameterfvARB;
    if (glad_glPointParameterfvEXT == NULL && glad_glPointParameterfvSGIS != NULL) glad_glPointParameterfvEXT = (PFNGLPOINTPARAMETERFVEXTPROC)glad_glPointParameterfvSGIS;
    if (glad_glPointParameterfvSGIS == NULL && glad_glPointParameterfv != NULL) glad_glPointParameterfvSGIS = (PFNGLPOINTPARAMETERFVSGISPROC)glad_glPointParameterfv;
    if (glad_glPointParameterfvSGIS == NULL && glad_glPointParameterfvARB != NULL) glad_glPointParameterfvSGIS = (PFNGLPOINTPARAMETERFVSGISPROC)glad_glPointParameterfvARB;
    if (glad_glPointParameterfvSGIS == NULL && glad_glPointParameterfvEXT != NULL) glad_glPointParameterfvSGIS = (PFNGLPOINTPARAMETERFVSGISPROC)glad_glPointParameterfvEXT;
    if (glad_glPointParameteri == NULL && glad_glPointParameteriNV != NULL) glad_glPointParameteri = (PFNGLPOINTPARAMETERIPROC)glad_glPointParameteriNV;
    if (glad_glPointParameteriNV == NULL && glad_glPointParameteri != NULL) glad_glPointParameteriNV = (PFNGLPOINTPARAMETERINVPROC)glad_glPointParameteri;
    if (glad_glPointParameteriv == NULL && glad_glPointParameterivNV != NULL) glad_glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)glad_glPointParameterivNV;
    if (glad_glPointParameterivNV == NULL && glad_glPointParameteriv != NULL) glad_glPointParameterivNV = (PFNGLPOINTPARAMETERIVNVPROC)glad_glPointParameteriv;
    if (glad_glPrioritizeTextures == NULL && glad_glPrioritizeTexturesEXT != NULL) glad_glPrioritizeTextures = (PFNGLPRIORITIZETEXTURESPROC)glad_glPrioritizeTexturesEXT;
    if (glad_glPrioritizeTexturesEXT == NULL && glad_glPrioritizeTextures != NULL) glad_glPrioritizeTexturesEXT = (PFNGLPRIORITIZETEXTURESEXTPROC)glad_glPrioritizeTextures;
    if (glad_glSampleCoverage == NULL && glad_glSampleCoverageARB != NULL) glad_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)glad_glSampleCoverageARB;
    if (glad_glSampleCoverageARB == NULL && glad_glSampleCoverage != NULL) glad_glSampleCoverageARB = (PFNGLSAMPLECOVERAGEARBPROC)glad_glSampleCoverage;
    if (glad_glSecondaryColor3b == NULL && glad_glSecondaryColor3bEXT != NULL) glad_glSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC)glad_glSecondaryColor3bEXT;
    if (glad_glSecondaryColor3bEXT == NULL && glad_glSecondaryColor3b != NULL) glad_glSecondaryColor3bEXT = (PFNGLSECONDARYCOLOR3BEXTPROC)glad_glSecondaryColor3b;
    if (glad_glSecondaryColor3bv == NULL && glad_glSecondaryColor3bvEXT != NULL) glad_glSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC)glad_glSecondaryColor3bvEXT;
    if (glad_glSecondaryColor3bvEXT == NULL && glad_glSecondaryColor3bv != NULL) glad_glSecondaryColor3bvEXT = (PFNGLSECONDARYCOLOR3BVEXTPROC)glad_glSecondaryColor3bv;
    if (glad_glSecondaryColor3d == NULL && glad_glSecondaryColor3dEXT != NULL) glad_glSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC)glad_glSecondaryColor3dEXT;
    if (glad_glSecondaryColor3dEXT == NULL && glad_glSecondaryColor3d != NULL) glad_glSecondaryColor3dEXT = (PFNGLSECONDARYCOLOR3DEXTPROC)glad_glSecondaryColor3d;
    if (glad_glSecondaryColor3dv == NULL && glad_glSecondaryColor3dvEXT != NULL) glad_glSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC)glad_glSecondaryColor3dvEXT;
    if (glad_glSecondaryColor3dvEXT == NULL && glad_glSecondaryColor3dv != NULL) glad_glSecondaryColor3dvEXT = (PFNGLSECONDARYCOLOR3DVEXTPROC)glad_glSecondaryColor3dv;
    if (glad_glSecondaryColor3f == NULL && glad_glSecondaryColor3fEXT != NULL) glad_glSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC)glad_glSecondaryColor3fEXT;
    if (glad_glSecondaryColor3fEXT == NULL && glad_glSecondaryColor3f != NULL) glad_glSecondaryColor3fEXT = (PFNGLSECONDARYCOLOR3FEXTPROC)glad_glSecondaryColor3f;
    if (glad_glSecondaryColor3fv == NULL && glad_glSecondaryColor3fvEXT != NULL) glad_glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC)glad_glSecondaryColor3fvEXT;
    if (glad_glSecondaryColor3fvEXT == NULL && glad_glSecondaryColor3fv != NULL) glad_glSecondaryColor3fvEXT = (PFNGLSECONDARYCOLOR3FVEXTPROC)glad_glSecondaryColor3fv;
    if (glad_glSecondaryColor3i == NULL && glad_glSecondaryColor3iEXT != NULL) glad_glSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC)glad_glSecondaryColor3iEXT;
    if (glad_glSecondaryColor3iEXT == NULL && glad_glSecondaryColor3i != NULL) glad_glSecondaryColor3iEXT = (PFNGLSECONDARYCOLOR3IEXTPROC)glad_glSecondaryColor3i;
    if (glad_glSecondaryColor3iv == NULL && glad_glSecondaryColor3ivEXT != NULL) glad_glSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC)glad_glSecondaryColor3ivEXT;
    if (glad_glSecondaryColor3ivEXT == NULL && glad_glSecondaryColor3iv != NULL) glad_glSecondaryColor3ivEXT = (PFNGLSECONDARYCOLOR3IVEXTPROC)glad_glSecondaryColor3iv;
    if (glad_glSecondaryColor3s == NULL && glad_glSecondaryColor3sEXT != NULL) glad_glSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC)glad_glSecondaryColor3sEXT;
    if (glad_glSecondaryColor3sEXT == NULL && glad_glSecondaryColor3s != NULL) glad_glSecondaryColor3sEXT = (PFNGLSECONDARYCOLOR3SEXTPROC)glad_glSecondaryColor3s;
    if (glad_glSecondaryColor3sv == NULL && glad_glSecondaryColor3svEXT != NULL) glad_glSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC)glad_glSecondaryColor3svEXT;
    if (glad_glSecondaryColor3svEXT == NULL && glad_glSecondaryColor3sv != NULL) glad_glSecondaryColor3svEXT = (PFNGLSECONDARYCOLOR3SVEXTPROC)glad_glSecondaryColor3sv;
    if (glad_glSecondaryColor3ub == NULL && glad_glSecondaryColor3ubEXT != NULL) glad_glSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC)glad_glSecondaryColor3ubEXT;
    if (glad_glSecondaryColor3ubEXT == NULL && glad_glSecondaryColor3ub != NULL) glad_glSecondaryColor3ubEXT = (PFNGLSECONDARYCOLOR3UBEXTPROC)glad_glSecondaryColor3ub;
    if (glad_glSecondaryColor3ubv == NULL && glad_glSecondaryColor3ubvEXT != NULL) glad_glSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC)glad_glSecondaryColor3ubvEXT;
    if (glad_glSecondaryColor3ubvEXT == NULL && glad_glSecondaryColor3ubv != NULL) glad_glSecondaryColor3ubvEXT = (PFNGLSECONDARYCOLOR3UBVEXTPROC)glad_glSecondaryColor3ubv;
    if (glad_glSecondaryColor3ui == NULL && glad_glSecondaryColor3uiEXT != NULL) glad_glSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC)glad_glSecondaryColor3uiEXT;
    if (glad_glSecondaryColor3uiEXT == NULL && glad_glSecondaryColor3ui != NULL) glad_glSecondaryColor3uiEXT = (PFNGLSECONDARYCOLOR3UIEXTPROC)glad_glSecondaryColor3ui;
    if (glad_glSecondaryColor3uiv == NULL && glad_glSecondaryColor3uivEXT != NULL) glad_glSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC)glad_glSecondaryColor3uivEXT;
    if (glad_glSecondaryColor3uivEXT == NULL && glad_glSecondaryColor3uiv != NULL) glad_glSecondaryColor3uivEXT = (PFNGLSECONDARYCOLOR3UIVEXTPROC)glad_glSecondaryColor3uiv;
    if (glad_glSecondaryColor3us == NULL && glad_glSecondaryColor3usEXT != NULL) glad_glSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC)glad_glSecondaryColor3usEXT;
    if (glad_glSecondaryColor3usEXT == NULL && glad_glSecondaryColor3us != NULL) glad_glSecondaryColor3usEXT = (PFNGLSECONDARYCOLOR3USEXTPROC)glad_glSecondaryColor3us;
    if (glad_glSecondaryColor3usv == NULL && glad_glSecondaryColor3usvEXT != NULL) glad_glSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC)glad_glSecondaryColor3usvEXT;
    if (glad_glSecondaryColor3usvEXT == NULL && glad_glSecondaryColor3usv != NULL) glad_glSecondaryColor3usvEXT = (PFNGLSECONDARYCOLOR3USVEXTPROC)glad_glSecondaryColor3usv;
    if (glad_glSecondaryColorPointer == NULL && glad_glSecondaryColorPointerEXT != NULL) glad_glSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC)glad_glSecondaryColorPointerEXT;
    if (glad_glSecondaryColorPointerEXT == NULL && glad_glSecondaryColorPointer != NULL) glad_glSecondaryColorPointerEXT = (PFNGLSECONDARYCOLORPOINTEREXTPROC)glad_glSecondaryColorPointer;
    if (glad_glShaderSource == NULL && glad_glShaderSourceARB != NULL) glad_glShaderSource = (PFNGLSHADERSOURCEPROC)glad_glShaderSourceARB;
    if (glad_glShaderSourceARB == NULL && glad_glShaderSource != NULL) glad_glShaderSourceARB = (PFNGLSHADERSOURCEARBPROC)glad_glShaderSource;
    if (glad_glStencilOpSeparate == NULL && glad_glStencilOpSeparateATI != NULL) glad_glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)glad_glStencilOpSeparateATI;
    if (glad_glStencilOpSeparateATI == NULL && glad_glStencilOpSeparate != NULL) glad_glStencilOpSeparateATI = (PFNGLSTENCILOPSEPARATEATIPROC)glad_glStencilOpSeparate;
    if (glad_glTexImage3D == NULL && glad_glTexImage3DEXT != NULL) glad_glTexImage3D = (PFNGLTEXIMAGE3DPROC)glad_glTexImage3DEXT;
    if (glad_glTexImage3DEXT == NULL && glad_glTexImage3D != NULL) glad_glTexImage3DEXT = (PFNGLTEXIMAGE3DEXTPROC)glad_glTexImage3D;
    if (glad_glTexSubImage1D == NULL && glad_glTexSubImage1DEXT != NULL) glad_glTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC)glad_glTexSubImage1DEXT;
    if (glad_glTexSubImage1DEXT == NULL && glad_glTexSubImage1D != NULL) glad_glTexSubImage1DEXT = (PFNGLTEXSUBIMAGE1DEXTPROC)glad_glTexSubImage1D;
    if (glad_glTexSubImage2D == NULL && glad_glTexSubImage2DEXT != NULL) glad_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)glad_glTexSubImage2DEXT;
    if (glad_glTexSubImage2DEXT == NULL && glad_glTexSubImage2D != NULL) glad_glTexSubImage2DEXT = (PFNGLTEXSUBIMAGE2DEXTPROC)glad_glTexSubImage2D;
    if (glad_glTexSubImage3D == NULL && glad_glTexSubImage3DEXT != NULL) glad_glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)glad_glTexSubImage3DEXT;
    if (glad_glTexSubImage3DEXT == NULL && glad_glTexSubImage3D != NULL) glad_glTexSubImage3DEXT = (PFNGLTEXSUBIMAGE3DEXTPROC)glad_glTexSubImage3D;
    if (glad_glUniform1f == NULL && glad_glUniform1fARB != NULL) glad_glUniform1f = (PFNGLUNIFORM1FPROC)glad_glUniform1fARB;
    if (glad_glUniform1fARB == NULL && glad_glUniform1f != NULL) glad_glUniform1fARB = (PFNGLUNIFORM1FARBPROC)glad_glUniform1f;
    if (glad_glUniform1fv == NULL && glad_glUniform1fvARB != NULL) glad_glUniform1fv = (PFNGLUNIFORM1FVPROC)glad_glUniform1fvARB;
    if (glad_glUniform1fvARB == NULL && glad_glUniform1fv != NULL) glad_glUniform1fvARB = (PFNGLUNIFORM1FVARBPROC)glad_glUniform1fv;
    if (glad_glUniform1i == NULL && glad_glUniform1iARB != NULL) glad_glUniform1i = (PFNGLUNIFORM1IPROC)glad_glUniform1iARB;
    if (glad_glUniform1iARB == NULL && glad_glUniform1i != NULL) glad_glUniform1iARB = (PFNGLUNIFORM1IARBPROC)glad_glUniform1i;
    if (glad_glUniform1iv == NULL && glad_glUniform1ivARB != NULL) glad_glUniform1iv = (PFNGLUNIFORM1IVPROC)glad_glUniform1ivARB;
    if (glad_glUniform1ivARB == NULL && glad_glUniform1iv != NULL) glad_glUniform1ivARB = (PFNGLUNIFORM1IVARBPROC)glad_glUniform1iv;
    if (glad_glUniform2f == NULL && glad_glUniform2fARB != NULL) glad_glUniform2f = (PFNGLUNIFORM2FPROC)glad_glUniform2fARB;
    if (glad_glUniform2fARB == NULL && glad_glUniform2f != NULL) glad_glUniform2fARB = (PFNGLUNIFORM2FARBPROC)glad_glUniform2f;
    if (glad_glUniform2fv == NULL && glad_glUniform2fvARB != NULL) glad_glUniform2fv = (PFNGLUNIFORM2FVPROC)glad_glUniform2fvARB;
    if (glad_glUniform2fvARB == NULL && glad_glUniform2fv != NULL) glad_glUniform2fvARB = (PFNGLUNIFORM2FVARBPROC)glad_glUniform2fv;
    if (glad_glUniform2i == NULL && glad_glUniform2iARB != NULL) glad_glUniform2i = (PFNGLUNIFORM2IPROC)glad_glUniform2iARB;
    if (glad_glUniform2iARB == NULL && glad_glUniform2i != NULL) glad_glUniform2iARB = (PFNGLUNIFORM2IARBPROC)glad_glUniform2i;
    if (glad_glUniform2iv == NULL && glad_glUniform2ivARB != NULL) glad_glUniform2iv = (PFNGLUNIFORM2IVPROC)glad_glUniform2ivARB;
    if (glad_glUniform2ivARB == NULL && glad_glUniform2iv != NULL) glad_glUniform2ivARB = (PFNGLUNIFORM2IVARBPROC)glad_glUniform2iv;
    if (glad_glUniform3f == NULL && glad_glUniform3fARB != NULL) glad_glUniform3f = (PFNGLUNIFORM3FPROC)glad_glUniform3fARB;
    if (glad_glUniform3fARB == NULL && glad_glUniform3f != NULL) glad_glUniform3fARB = (PFNGLUNIFORM3FARBPROC)glad_glUniform3f;
    if (glad_glUniform3fv == NULL && glad_glUniform3fvARB != NULL) glad_glUniform3fv = (PFNGLUNIFORM3FVPROC)glad_glUniform3fvARB;
    if (glad_glUniform3fvARB == NULL && glad_glUniform3fv != NULL) glad_glUniform3fvARB = (PFNGLUNIFORM3FVARBPROC)glad_glUniform3fv;
    if (glad_glUniform3i == NULL && glad_glUniform3iARB != NULL) glad_glUniform3i = (PFNGLUNIFORM3IPROC)glad_glUniform3iARB;
    if (glad_glUniform3iARB == NULL && glad_glUniform3i != NULL) glad_glUniform3iARB = (PFNGLUNIFORM3IARBPROC)glad_glUniform3i;
    if (glad_glUniform3iv == NULL && glad_glUniform3ivARB != NULL) glad_glUniform3iv = (PFNGLUNIFORM3IVPROC)glad_glUniform3ivARB;
    if (glad_glUniform3ivARB == NULL && glad_glUniform3iv != NULL) glad_glUniform3ivARB = (PFNGLUNIFORM3IVARBPROC)glad_glUniform3iv;
    if (glad_glUniform4f == NULL && glad_glUniform4fARB != NULL) glad_glUniform4f = (PFNGLUNIFORM4FPROC)glad_glUniform4fARB;
    if (glad_glUniform4fARB == NULL && glad_glUniform4f != NULL) glad_glUniform4fARB = (PFNGLUNIFORM4FARBPROC)glad_glUniform4f;
    if (glad_glUniform4fv == NULL && glad_glUniform4fvARB != NULL) glad_glUniform4fv = (PFNGLUNIFORM4FVPROC)glad_glUniform4fvARB;
    if (glad_glUniform4fvARB == NULL && glad_glUniform4fv != NULL) glad_glUniform4fvARB = (PFNGLUNIFORM4FVARBPROC)glad_glUniform4fv;
    if (glad_glUniform4i == NULL && glad_glUniform4iARB != NULL) glad_glUniform4i = (PFNGLUNIFORM4IPROC)glad_glUniform4iARB;
    if (glad_glUniform4iARB == NULL && glad_glUniform4i != NULL) glad_glUniform4iARB = (PFNGLUNIFORM4IARBPROC)glad_glUniform4i;
    if (glad_glUniform4iv == NULL && glad_glUniform4ivARB != NULL) glad_glUniform4iv = (PFNGLUNIFORM4IVPROC)glad_glUniform4ivARB;
    if (glad_glUniform4ivARB == NULL && glad_glUniform4iv != NULL) glad_glUniform4ivARB = (PFNGLUNIFORM4IVARBPROC)glad_glUniform4iv;
    if (glad_glUniformMatrix2fv == NULL && glad_glUniformMatrix2fvARB != NULL) glad_glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)glad_glUniformMatrix2fvARB;
    if (glad_glUniformMatrix2fvARB == NULL && glad_glUniformMatrix2fv != NULL) glad_glUniformMatrix2fvARB = (PFNGLUNIFORMMATRIX2FVARBPROC)glad_glUniformMatrix2fv;
    if (glad_glUniformMatrix3fv == NULL && glad_glUniformMatrix3fvARB != NULL) glad_glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)glad_glUniformMatrix3fvARB;
    if (glad_glUniformMatrix3fvARB == NULL && glad_glUniformMatrix3fv != NULL) glad_glUniformMatrix3fvARB = (PFNGLUNIFORMMATRIX3FVARBPROC)glad_glUniformMatrix3fv;
    if (glad_glUniformMatrix4fv == NULL && glad_glUniformMatrix4fvARB != NULL) glad_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)glad_glUniformMatrix4fvARB;
    if (glad_glUniformMatrix4fvARB == NULL && glad_glUniformMatrix4fv != NULL) glad_glUniformMatrix4fvARB = (PFNGLUNIFORMMATRIX4FVARBPROC)glad_glUniformMatrix4fv;
    if (glad_glUnmapBuffer == NULL && glad_glUnmapBufferARB != NULL) glad_glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)glad_glUnmapBufferARB;
    if (glad_glUnmapBufferARB == NULL && glad_glUnmapBuffer != NULL) glad_glUnmapBufferARB = (PFNGLUNMAPBUFFERARBPROC)glad_glUnmapBuffer;
    if (glad_glUseProgram == NULL && glad_glUseProgramObjectARB != NULL) glad_glUseProgram = (PFNGLUSEPROGRAMPROC)glad_glUseProgramObjectARB;
    if (glad_glUseProgramObjectARB == NULL && glad_glUseProgram != NULL) glad_glUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC)glad_glUseProgram;
    if (glad_glValidateProgram == NULL && glad_glValidateProgramARB != NULL) glad_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)glad_glValidateProgramARB;
    if (glad_glValidateProgramARB == NULL && glad_glValidateProgram != NULL) glad_glValidateProgramARB = (PFNGLVALIDATEPROGRAMARBPROC)glad_glValidateProgram;
    if (glad_glVertexAttrib1d == NULL && glad_glVertexAttrib1dARB != NULL) glad_glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)glad_glVertexAttrib1dARB;
    if (glad_glVertexAttrib1d == NULL && glad_glVertexAttrib1dNV != NULL) glad_glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)glad_glVertexAttrib1dNV;
    if (glad_glVertexAttrib1dARB == NULL && glad_glVertexAttrib1d != NULL) glad_glVertexAttrib1dARB = (PFNGLVERTEXATTRIB1DARBPROC)glad_glVertexAttrib1d;
    if (glad_glVertexAttrib1dARB == NULL && glad_glVertexAttrib1dNV != NULL) glad_glVertexAttrib1dARB = (PFNGLVERTEXATTRIB1DARBPROC)glad_glVertexAttrib1dNV;
    if (glad_glVertexAttrib1dNV == NULL && glad_glVertexAttrib1d != NULL) glad_glVertexAttrib1dNV = (PFNGLVERTEXATTRIB1DNVPROC)glad_glVertexAttrib1d;
    if (glad_glVertexAttrib1dNV == NULL && glad_glVertexAttrib1dARB != NULL) glad_glVertexAttrib1dNV = (PFNGLVERTEXATTRIB1DNVPROC)glad_glVertexAttrib1dARB;
    if (glad_glVertexAttrib1dv == NULL && glad_glVertexAttrib1dvARB != NULL) glad_glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)glad_glVertexAttrib1dvARB;
    if (glad_glVertexAttrib1dv == NULL && glad_glVertexAttrib1dvNV != NULL) glad_glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)glad_glVertexAttrib1dvNV;
    if (glad_glVertexAttrib1dvARB == NULL && glad_glVertexAttrib1dv != NULL) glad_glVertexAttrib1dvARB = (PFNGLVERTEXATTRIB1DVARBPROC)glad_glVertexAttrib1dv;
    if (glad_glVertexAttrib1dvARB == NULL && glad_glVertexAttrib1dvNV != NULL) glad_glVertexAttrib1dvARB = (PFNGLVERTEXATTRIB1DVARBPROC)glad_glVertexAttrib1dvNV;
    if (glad_glVertexAttrib1dvNV == NULL && glad_glVertexAttrib1dv != NULL) glad_glVertexAttrib1dvNV = (PFNGLVERTEXATTRIB1DVNVPROC)glad_glVertexAttrib1dv;
    if (glad_glVertexAttrib1dvNV == NULL && glad_glVertexAttrib1dvARB != NULL) glad_glVertexAttrib1dvNV = (PFNGLVERTEXATTRIB1DVNVPROC)glad_glVertexAttrib1dvARB;
    if (glad_glVertexAttrib1f == NULL && glad_glVertexAttrib1fARB != NULL) glad_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)glad_glVertexAttrib1fARB;
    if (glad_glVertexAttrib1f == NULL && glad_glVertexAttrib1fNV != NULL) glad_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)glad_glVertexAttrib1fNV;
    if (glad_glVertexAttrib1fARB == NULL && glad_glVertexAttrib1f != NULL) glad_glVertexAttrib1fARB = (PFNGLVERTEXATTRIB1FARBPROC)glad_glVertexAttrib1f;
    if (glad_glVertexAttrib1fARB == NULL && glad_glVertexAttrib1fNV != NULL) glad_glVertexAttrib1fARB = (PFNGLVERTEXATTRIB1FARBPROC)glad_glVertexAttrib1fNV;
    if (glad_glVertexAttrib1fNV == NULL && glad_glVertexAttrib1f != NULL) glad_glVertexAttrib1fNV = (PFNGLVERTEXATTRIB1FNVPROC)glad_glVertexAttrib1f;
    if (glad_glVertexAttrib1fNV == NULL && glad_glVertexAttrib1fARB != NULL) glad_glVertexAttrib1fNV = (PFNGLVERTEXATTRIB1FNVPROC)glad_glVertexAttrib1fARB;
    if (glad_glVertexAttrib1fv == NULL && glad_glVertexAttrib1fvARB != NULL) glad_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)glad_glVertexAttrib1fvARB;
    if (glad_glVertexAttrib1fv == NULL && glad_glVertexAttrib1fvNV != NULL) glad_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)glad_glVertexAttrib1fvNV;
    if (glad_glVertexAttrib1fvARB == NULL && glad_glVertexAttrib1fv != NULL) glad_glVertexAttrib1fvARB = (PFNGLVERTEXATTRIB1FVARBPROC)glad_glVertexAttrib1fv;
    if (glad_glVertexAttrib1fvARB == NULL && glad_glVertexAttrib1fvNV != NULL) glad_glVertexAttrib1fvARB = (PFNGLVERTEXATTRIB1FVARBPROC)glad_glVertexAttrib1fvNV;
    if (glad_glVertexAttrib1fvNV == NULL && glad_glVertexAttrib1fv != NULL) glad_glVertexAttrib1fvNV = (PFNGLVERTEXATTRIB1FVNVPROC)glad_glVertexAttrib1fv;
    if (glad_glVertexAttrib1fvNV == NULL && glad_glVertexAttrib1fvARB != NULL) glad_glVertexAttrib1fvNV = (PFNGLVERTEXATTRIB1FVNVPROC)glad_glVertexAttrib1fvARB;
    if (glad_glVertexAttrib1s == NULL && glad_glVertexAttrib1sARB != NULL) glad_glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)glad_glVertexAttrib1sARB;
    if (glad_glVertexAttrib1s == NULL && glad_glVertexAttrib1sNV != NULL) glad_glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)glad_glVertexAttrib1sNV;
    if (glad_glVertexAttrib1sARB == NULL && glad_glVertexAttrib1s != NULL) glad_glVertexAttrib1sARB = (PFNGLVERTEXATTRIB1SARBPROC)glad_glVertexAttrib1s;
    if (glad_glVertexAttrib1sARB == NULL && glad_glVertexAttrib1sNV != NULL) glad_glVertexAttrib1sARB = (PFNGLVERTEXATTRIB1SARBPROC)glad_glVertexAttrib1sNV;
    if (glad_glVertexAttrib1sNV == NULL && glad_glVertexAttrib1s != NULL) glad_glVertexAttrib1sNV = (PFNGLVERTEXATTRIB1SNVPROC)glad_glVertexAttrib1s;
    if (glad_glVertexAttrib1sNV == NULL && glad_glVertexAttrib1sARB != NULL) glad_glVertexAttrib1sNV = (PFNGLVERTEXATTRIB1SNVPROC)glad_glVertexAttrib1sARB;
    if (glad_glVertexAttrib1sv == NULL && glad_glVertexAttrib1svARB != NULL) glad_glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)glad_glVertexAttrib1svARB;
    if (glad_glVertexAttrib1sv == NULL && glad_glVertexAttrib1svNV != NULL) glad_glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)glad_glVertexAttrib1svNV;
    if (glad_glVertexAttrib1svARB == NULL && glad_glVertexAttrib1sv != NULL) glad_glVertexAttrib1svARB = (PFNGLVERTEXATTRIB1SVARBPROC)glad_glVertexAttrib1sv;
    if (glad_glVertexAttrib1svARB == NULL && glad_glVertexAttrib1svNV != NULL) glad_glVertexAttrib1svARB = (PFNGLVERTEXATTRIB1SVARBPROC)glad_glVertexAttrib1svNV;
    if (glad_glVertexAttrib1svNV == NULL && glad_glVertexAttrib1sv != NULL) glad_glVertexAttrib1svNV = (PFNGLVERTEXATTRIB1SVNVPROC)glad_glVertexAttrib1sv;
    if (glad_glVertexAttrib1svNV == NULL && glad_glVertexAttrib1svARB != NULL) glad_glVertexAttrib1svNV = (PFNGLVERTEXATTRIB1SVNVPROC)glad_glVertexAttrib1svARB;
    if (glad_glVertexAttrib2d == NULL && glad_glVertexAttrib2dARB != NULL) glad_glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)glad_glVertexAttrib2dARB;
    if (glad_glVertexAttrib2d == NULL && glad_glVertexAttrib2dNV != NULL) glad_glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)glad_glVertexAttrib2dNV;
    if (glad_glVertexAttrib2dARB == NULL && glad_glVertexAttrib2d != NULL) glad_glVertexAttrib2dARB = (PFNGLVERTEXATTRIB2DARBPROC)glad_glVertexAttrib2d;
    if (glad_glVertexAttrib2dARB == NULL && glad_glVertexAttrib2dNV != NULL) glad_glVertexAttrib2dARB = (PFNGLVERTEXATTRIB2DARBPROC)glad_glVertexAttrib2dNV;
    if (glad_glVertexAttrib2dNV == NULL && glad_glVertexAttrib2d != NULL) glad_glVertexAttrib2dNV = (PFNGLVERTEXATTRIB2DNVPROC)glad_glVertexAttrib2d;
    if (glad_glVertexAttrib2dNV == NULL && glad_glVertexAttrib2dARB != NULL) glad_glVertexAttrib2dNV = (PFNGLVERTEXATTRIB2DNVPROC)glad_glVertexAttrib2dARB;
    if (glad_glVertexAttrib2dv == NULL && glad_glVertexAttrib2dvARB != NULL) glad_glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)glad_glVertexAttrib2dvARB;
    if (glad_glVertexAttrib2dv == NULL && glad_glVertexAttrib2dvNV != NULL) glad_glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)glad_glVertexAttrib2dvNV;
    if (glad_glVertexAttrib2dvARB == NULL && glad_glVertexAttrib2dv != NULL) glad_glVertexAttrib2dvARB = (PFNGLVERTEXATTRIB2DVARBPROC)glad_glVertexAttrib2dv;
    if (glad_glVertexAttrib2dvARB == NULL && glad_glVertexAttrib2dvNV != NULL) glad_glVertexAttrib2dvARB = (PFNGLVERTEXATTRIB2DVARBPROC)glad_glVertexAttrib2dvNV;
    if (glad_glVertexAttrib2dvNV == NULL && glad_glVertexAttrib2dv != NULL) glad_glVertexAttrib2dvNV = (PFNGLVERTEXATTRIB2DVNVPROC)glad_glVertexAttrib2dv;
    if (glad_glVertexAttrib2dvNV == NULL && glad_glVertexAttrib2dvARB != NULL) glad_glVertexAttrib2dvNV = (PFNGLVERTEXATTRIB2DVNVPROC)glad_glVertexAttrib2dvARB;
    if (glad_glVertexAttrib2f == NULL && glad_glVertexAttrib2fARB != NULL) glad_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)glad_glVertexAttrib2fARB;
    if (glad_glVertexAttrib2f == NULL && glad_glVertexAttrib2fNV != NULL) glad_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)glad_glVertexAttrib2fNV;
    if (glad_glVertexAttrib2fARB == NULL && glad_glVertexAttrib2f != NULL) glad_glVertexAttrib2fARB = (PFNGLVERTEXATTRIB2FARBPROC)glad_glVertexAttrib2f;
    if (glad_glVertexAttrib2fARB == NULL && glad_glVertexAttrib2fNV != NULL) glad_glVertexAttrib2fARB = (PFNGLVERTEXATTRIB2FARBPROC)glad_glVertexAttrib2fNV;
    if (glad_glVertexAttrib2fNV == NULL && glad_glVertexAttrib2f != NULL) glad_glVertexAttrib2fNV = (PFNGLVERTEXATTRIB2FNVPROC)glad_glVertexAttrib2f;
    if (glad_glVertexAttrib2fNV == NULL && glad_glVertexAttrib2fARB != NULL) glad_glVertexAttrib2fNV = (PFNGLVERTEXATTRIB2FNVPROC)glad_glVertexAttrib2fARB;
    if (glad_glVertexAttrib2fv == NULL && glad_glVertexAttrib2fvARB != NULL) glad_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)glad_glVertexAttrib2fvARB;
    if (glad_glVertexAttrib2fv == NULL && glad_glVertexAttrib2fvNV != NULL) glad_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)glad_glVertexAttrib2fvNV;
    if (glad_glVertexAttrib2fvARB == NULL && glad_glVertexAttrib2fv != NULL) glad_glVertexAttrib2fvARB = (PFNGLVERTEXATTRIB2FVARBPROC)glad_glVertexAttrib2fv;
    if (glad_glVertexAttrib2fvARB == NULL && glad_glVertexAttrib2fvNV != NULL) glad_glVertexAttrib2fvARB = (PFNGLVERTEXATTRIB2FVARBPROC)glad_glVertexAttrib2fvNV;
    if (glad_glVertexAttrib2fvNV == NULL && glad_glVertexAttrib2fv != NULL) glad_glVertexAttrib2fvNV = (PFNGLVERTEXATTRIB2FVNVPROC)glad_glVertexAttrib2fv;
    if (glad_glVertexAttrib2fvNV == NULL && glad_glVertexAttrib2fvARB != NULL) glad_glVertexAttrib2fvNV = (PFNGLVERTEXATTRIB2FVNVPROC)glad_glVertexAttrib2fvARB;
    if (glad_glVertexAttrib2s == NULL && glad_glVertexAttrib2sARB != NULL) glad_glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)glad_glVertexAttrib2sARB;
    if (glad_glVertexAttrib2s == NULL && glad_glVertexAttrib2sNV != NULL) glad_glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)glad_glVertexAttrib2sNV;
    if (glad_glVertexAttrib2sARB == NULL && glad_glVertexAttrib2s != NULL) glad_glVertexAttrib2sARB = (PFNGLVERTEXATTRIB2SARBPROC)glad_glVertexAttrib2s;
    if (glad_glVertexAttrib2sARB == NULL && glad_glVertexAttrib2sNV != NULL) glad_glVertexAttrib2sARB = (PFNGLVERTEXATTRIB2SARBPROC)glad_glVertexAttrib2sNV;
    if (glad_glVertexAttrib2sNV == NULL && glad_glVertexAttrib2s != NULL) glad_glVertexAttrib2sNV = (PFNGLVERTEXATTRIB2SNVPROC)glad_glVertexAttrib2s;
    if (glad_glVertexAttrib2sNV == NULL && glad_glVertexAttrib2sARB != NULL) glad_glVertexAttrib2sNV = (PFNGLVERTEXATTRIB2SNVPROC)glad_glVertexAttrib2sARB;
    if (glad_glVertexAttrib2sv == NULL && glad_glVertexAttrib2svARB != NULL) glad_glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)glad_glVertexAttrib2svARB;
    if (glad_glVertexAttrib2sv == NULL && glad_glVertexAttrib2svNV != NULL) glad_glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)glad_glVertexAttrib2svNV;
    if (glad_glVertexAttrib2svARB == NULL && glad_glVertexAttrib2sv != NULL) glad_glVertexAttrib2svARB = (PFNGLVERTEXATTRIB2SVARBPROC)glad_glVertexAttrib2sv;
    if (glad_glVertexAttrib2svARB == NULL && glad_glVertexAttrib2svNV != NULL) glad_glVertexAttrib2svARB = (PFNGLVERTEXATTRIB2SVARBPROC)glad_glVertexAttrib2svNV;
    if (glad_glVertexAttrib2svNV == NULL && glad_glVertexAttrib2sv != NULL) glad_glVertexAttrib2svNV = (PFNGLVERTEXATTRIB2SVNVPROC)glad_glVertexAttrib2sv;
    if (glad_glVertexAttrib2svNV == NULL && glad_glVertexAttrib2svARB != NULL) glad_glVertexAttrib2svNV = (PFNGLVERTEXATTRIB2SVNVPROC)glad_glVertexAttrib2svARB;
    if (glad_glVertexAttrib3d == NULL && glad_glVertexAttrib3dARB != NULL) glad_glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)glad_glVertexAttrib3dARB;
    if (glad_glVertexAttrib3d == NULL && glad_glVertexAttrib3dNV != NULL) glad_glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)glad_glVertexAttrib3dNV;
    if (glad_glVertexAttrib3dARB == NULL && glad_glVertexAttrib3d != NULL) glad_glVertexAttrib3dARB = (PFNGLVERTEXATTRIB3DARBPROC)glad_glVertexAttrib3d;
    if (glad_glVertexAttrib3dARB == NULL && glad_glVertexAttrib3dNV != NULL) glad_glVertexAttrib3dARB = (PFNGLVERTEXATTRIB3DARBPROC)glad_glVertexAttrib3dNV;
    if (glad_glVertexAttrib3dNV == NULL && glad_glVertexAttrib3d != NULL) glad_glVertexAttrib3dNV = (PFNGLVERTEXATTRIB3DNVPROC)glad_glVertexAttrib3d;
    if (glad_glVertexAttrib3dNV == NULL && glad_glVertexAttrib3dARB != NULL) glad_glVertexAttrib3dNV = (PFNGLVERTEXATTRIB3DNVPROC)glad_glVertexAttrib3dARB;
    if (glad_glVertexAttrib3dv == NULL && glad_glVertexAttrib3dvARB != NULL) glad_glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)glad_glVertexAttrib3dvARB;
    if (glad_glVertexAttrib3dv == NULL && glad_glVertexAttrib3dvNV != NULL) glad_glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)glad_glVertexAttrib3dvNV;
    if (glad_glVertexAttrib3dvARB == NULL && glad_glVertexAttrib3dv != NULL) glad_glVertexAttrib3dvARB = (PFNGLVERTEXATTRIB3DVARBPROC)glad_glVertexAttrib3dv;
    if (glad_glVertexAttrib3dvARB == NULL && glad_glVertexAttrib3dvNV != NULL) glad_glVertexAttrib3dvARB = (PFNGLVERTEXATTRIB3DVARBPROC)glad_glVertexAttrib3dvNV;
    if (glad_glVertexAttrib3dvNV == NULL && glad_glVertexAttrib3dv != NULL) glad_glVertexAttrib3dvNV = (PFNGLVERTEXATTRIB3DVNVPROC)glad_glVertexAttrib3dv;
    if (glad_glVertexAttrib3dvNV == NULL && glad_glVertexAttrib3dvARB != NULL) glad_glVertexAttrib3dvNV = (PFNGLVERTEXATTRIB3DVNVPROC)glad_glVertexAttrib3dvARB;
    if (glad_glVertexAttrib3f == NULL && glad_glVertexAttrib3fARB != NULL) glad_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)glad_glVertexAttrib3fARB;
    if (glad_glVertexAttrib3f == NULL && glad_glVertexAttrib3fNV != NULL) glad_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)glad_glVertexAttrib3fNV;
    if (glad_glVertexAttrib3fARB == NULL && glad_glVertexAttrib3f != NULL) glad_glVertexAttrib3fARB = (PFNGLVERTEXATTRIB3FARBPROC)glad_glVertexAttrib3f;
    if (glad_glVertexAttrib3fARB == NULL && glad_glVertexAttrib3fNV != NULL) glad_glVertexAttrib3fARB = (PFNGLVERTEXATTRIB3FARBPROC)glad_glVertexAttrib3fNV;
    if (glad_glVertexAttrib3fNV == NULL && glad_glVertexAttrib3f != NULL) glad_glVertexAttrib3fNV = (PFNGLVERTEXATTRIB3FNVPROC)glad_glVertexAttrib3f;
    if (glad_glVertexAttrib3fNV == NULL && glad_glVertexAttrib3fARB != NULL) glad_glVertexAttrib3fNV = (PFNGLVERTEXATTRIB3FNVPROC)glad_glVertexAttrib3fARB;
    if (glad_glVertexAttrib3fv == NULL && glad_glVertexAttrib3fvARB != NULL) glad_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)glad_glVertexAttrib3fvARB;
    if (glad_glVertexAttrib3fv == NULL && glad_glVertexAttrib3fvNV != NULL) glad_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)glad_glVertexAttrib3fvNV;
    if (glad_glVertexAttrib3fvARB == NULL && glad_glVertexAttrib3fv != NULL) glad_glVertexAttrib3fvARB = (PFNGLVERTEXATTRIB3FVARBPROC)glad_glVertexAttrib3fv;
    if (glad_glVertexAttrib3fvARB == NULL && glad_glVertexAttrib3fvNV != NULL) glad_glVertexAttrib3fvARB = (PFNGLVERTEXATTRIB3FVARBPROC)glad_glVertexAttrib3fvNV;
    if (glad_glVertexAttrib3fvNV == NULL && glad_glVertexAttrib3fv != NULL) glad_glVertexAttrib3fvNV = (PFNGLVERTEXATTRIB3FVNVPROC)glad_glVertexAttrib3fv;
    if (glad_glVertexAttrib3fvNV == NULL && glad_glVertexAttrib3fvARB != NULL) glad_glVertexAttrib3fvNV = (PFNGLVERTEXATTRIB3FVNVPROC)glad_glVertexAttrib3fvARB;
    if (glad_glVertexAttrib3s == NULL && glad_glVertexAttrib3sARB != NULL) glad_glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)glad_glVertexAttrib3sARB;
    if (glad_glVertexAttrib3s == NULL && glad_glVertexAttrib3sNV != NULL) glad_glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)glad_glVertexAttrib3sNV;
    if (glad_glVertexAttrib3sARB == NULL && glad_glVertexAttrib3s != NULL) glad_glVertexAttrib3sARB = (PFNGLVERTEXATTRIB3SARBPROC)glad_glVertexAttrib3s;
    if (glad_glVertexAttrib3sARB == NULL && glad_glVertexAttrib3sNV != NULL) glad_glVertexAttrib3sARB = (PFNGLVERTEXATTRIB3SARBPROC)glad_glVertexAttrib3sNV;
    if (glad_glVertexAttrib3sNV == NULL && glad_glVertexAttrib3s != NULL) glad_glVertexAttrib3sNV = (PFNGLVERTEXATTRIB3SNVPROC)glad_glVertexAttrib3s;
    if (glad_glVertexAttrib3sNV == NULL && glad_glVertexAttrib3sARB != NULL) glad_glVertexAttrib3sNV = (PFNGLVERTEXATTRIB3SNVPROC)glad_glVertexAttrib3sARB;
    if (glad_glVertexAttrib3sv == NULL && glad_glVertexAttrib3svARB != NULL) glad_glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)glad_glVertexAttrib3svARB;
    if (glad_glVertexAttrib3sv == NULL && glad_glVertexAttrib3svNV != NULL) glad_glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)glad_glVertexAttrib3svNV;
    if (glad_glVertexAttrib3svARB == NULL && glad_glVertexAttrib3sv != NULL) glad_glVertexAttrib3svARB = (PFNGLVERTEXATTRIB3SVARBPROC)glad_glVertexAttrib3sv;
    if (glad_glVertexAttrib3svARB == NULL && glad_glVertexAttrib3svNV != NULL) glad_glVertexAttrib3svARB = (PFNGLVERTEXATTRIB3SVARBPROC)glad_glVertexAttrib3svNV;
    if (glad_glVertexAttrib3svNV == NULL && glad_glVertexAttrib3sv != NULL) glad_glVertexAttrib3svNV = (PFNGLVERTEXATTRIB3SVNVPROC)glad_glVertexAttrib3sv;
    if (glad_glVertexAttrib3svNV == NULL && glad_glVertexAttrib3svARB != NULL) glad_glVertexAttrib3svNV = (PFNGLVERTEXATTRIB3SVNVPROC)glad_glVertexAttrib3svARB;
    if (glad_glVertexAttrib4bv == NULL && glad_glVertexAttrib4bvARB != NULL) glad_glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)glad_glVertexAttrib4bvARB;
    if (glad_glVertexAttrib4bvARB == NULL && glad_glVertexAttrib4bv != NULL) glad_glVertexAttrib4bvARB = (PFNGLVERTEXATTRIB4BVARBPROC)glad_glVertexAttrib4bv;
    if (glad_glVertexAttrib4d == NULL && glad_glVertexAttrib4dARB != NULL) glad_glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)glad_glVertexAttrib4dARB;
    if (glad_glVertexAttrib4d == NULL && glad_glVertexAttrib4dNV != NULL) glad_glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)glad_glVertexAttrib4dNV;
    if (glad_glVertexAttrib4dARB == NULL && glad_glVertexAttrib4d != NULL) glad_glVertexAttrib4dARB = (PFNGLVERTEXATTRIB4DARBPROC)glad_glVertexAttrib4d;
    if (glad_glVertexAttrib4dARB == NULL && glad_glVertexAttrib4dNV != NULL) glad_glVertexAttrib4dARB = (PFNGLVERTEXATTRIB4DARBPROC)glad_glVertexAttrib4dNV;
    if (glad_glVertexAttrib4dNV == NULL && glad_glVertexAttrib4d != NULL) glad_glVertexAttrib4dNV = (PFNGLVERTEXATTRIB4DNVPROC)glad_glVertexAttrib4d;
    if (glad_glVertexAttrib4dNV == NULL && glad_glVertexAttrib4dARB != NULL) glad_glVertexAttrib4dNV = (PFNGLVERTEXATTRIB4DNVPROC)glad_glVertexAttrib4dARB;
    if (glad_glVertexAttrib4dv == NULL && glad_glVertexAttrib4dvARB != NULL) glad_glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)glad_glVertexAttrib4dvARB;
    if (glad_glVertexAttrib4dv == NULL && glad_glVertexAttrib4dvNV != NULL) glad_glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)glad_glVertexAttrib4dvNV;
    if (glad_glVertexAttrib4dvARB == NULL && glad_glVertexAttrib4dv != NULL) glad_glVertexAttrib4dvARB = (PFNGLVERTEXATTRIB4DVARBPROC)glad_glVertexAttrib4dv;
    if (glad_glVertexAttrib4dvARB == NULL && glad_glVertexAttrib4dvNV != NULL) glad_glVertexAttrib4dvARB = (PFNGLVERTEXATTRIB4DVARBPROC)glad_glVertexAttrib4dvNV;
    if (glad_glVertexAttrib4dvNV == NULL && glad_glVertexAttrib4dv != NULL) glad_glVertexAttrib4dvNV = (PFNGLVERTEXATTRIB4DVNVPROC)glad_glVertexAttrib4dv;
    if (glad_glVertexAttrib4dvNV == NULL && glad_glVertexAttrib4dvARB != NULL) glad_glVertexAttrib4dvNV = (PFNGLVERTEXATTRIB4DVNVPROC)glad_glVertexAttrib4dvARB;
    if (glad_glVertexAttrib4f == NULL && glad_glVertexAttrib4fARB != NULL) glad_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)glad_glVertexAttrib4fARB;
    if (glad_glVertexAttrib4f == NULL && glad_glVertexAttrib4fNV != NULL) glad_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)glad_glVertexAttrib4fNV;
    if (glad_glVertexAttrib4fARB == NULL && glad_glVertexAttrib4f != NULL) glad_glVertexAttrib4fARB = (PFNGLVERTEXATTRIB4FARBPROC)glad_glVertexAttrib4f;
    if (glad_glVertexAttrib4fARB == NULL && glad_glVertexAttrib4fNV != NULL) glad_glVertexAttrib4fARB = (PFNGLVERTEXATTRIB4FARBPROC)glad_glVertexAttrib4fNV;
    if (glad_glVertexAttrib4fNV == NULL && glad_glVertexAttrib4f != NULL) glad_glVertexAttrib4fNV = (PFNGLVERTEXATTRIB4FNVPROC)glad_glVertexAttrib4f;
    if (glad_glVertexAttrib4fNV == NULL && glad_glVertexAttrib4fARB != NULL) glad_glVertexAttrib4fNV = (PFNGLVERTEXATTRIB4FNVPROC)glad_glVertexAttrib4fARB;
    if (glad_glVertexAttrib4fv == NULL && glad_glVertexAttrib4fvARB != NULL) glad_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)glad_glVertexAttrib4fvARB;
    if (glad_glVertexAttrib4fv == NULL && glad_glVertexAttrib4fvNV != NULL) glad_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)glad_glVertexAttrib4fvNV;
    if (glad_glVertexAttrib4fvARB == NULL && glad_glVertexAttrib4fv != NULL) glad_glVertexAttrib4fvARB = (PFNGLVERTEXATTRIB4FVARBPROC)glad_glVertexAttrib4fv;
    if (glad_glVertexAttrib4fvARB == NULL && glad_glVertexAttrib4fvNV != NULL) glad_glVertexAttrib4fvARB = (PFNGLVERTEXATTRIB4FVARBPROC)glad_glVertexAttrib4fvNV;
    if (glad_glVertexAttrib4fvNV == NULL && glad_glVertexAttrib4fv != NULL) glad_glVertexAttrib4fvNV = (PFNGLVERTEXATTRIB4FVNVPROC)glad_glVertexAttrib4fv;
    if (glad_glVertexAttrib4fvNV == NULL && glad_glVertexAttrib4fvARB != NULL) glad_glVertexAttrib4fvNV = (PFNGLVERTEXATTRIB4FVNVPROC)glad_glVertexAttrib4fvARB;
    if (glad_glVertexAttrib4iv == NULL && glad_glVertexAttrib4ivARB != NULL) glad_glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)glad_glVertexAttrib4ivARB;
    if (glad_glVertexAttrib4ivARB == NULL && glad_glVertexAttrib4iv != NULL) glad_glVertexAttrib4ivARB = (PFNGLVERTEXATTRIB4IVARBPROC)glad_glVertexAttrib4iv;
    if (glad_glVertexAttrib4Nbv == NULL && glad_glVertexAttrib4NbvARB != NULL) glad_glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)glad_glVertexAttrib4NbvARB;
    if (glad_glVertexAttrib4NbvARB == NULL && glad_glVertexAttrib4Nbv != NULL) glad_glVertexAttrib4NbvARB = (PFNGLVERTEXATTRIB4NBVARBPROC)glad_glVertexAttrib4Nbv;
    if (glad_glVertexAttrib4Niv == NULL && glad_glVertexAttrib4NivARB != NULL) glad_glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)glad_glVertexAttrib4NivARB;
    if (glad_glVertexAttrib4NivARB == NULL && glad_glVertexAttrib4Niv != NULL) glad_glVertexAttrib4NivARB = (PFNGLVERTEXATTRIB4NIVARBPROC)glad_glVertexAttrib4Niv;
    if (glad_glVertexAttrib4Nsv == NULL && glad_glVertexAttrib4NsvARB != NULL) glad_glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)glad_glVertexAttrib4NsvARB;
    if (glad_glVertexAttrib4NsvARB == NULL && glad_glVertexAttrib4Nsv != NULL) glad_glVertexAttrib4NsvARB = (PFNGLVERTEXATTRIB4NSVARBPROC)glad_glVertexAttrib4Nsv;
    if (glad_glVertexAttrib4Nub == NULL && glad_glVertexAttrib4NubARB != NULL) glad_glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)glad_glVertexAttrib4NubARB;
    if (glad_glVertexAttrib4Nub == NULL && glad_glVertexAttrib4ubNV != NULL) glad_glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)glad_glVertexAttrib4ubNV;
    if (glad_glVertexAttrib4NubARB == NULL && glad_glVertexAttrib4Nub != NULL) glad_glVertexAttrib4NubARB = (PFNGLVERTEXATTRIB4NUBARBPROC)glad_glVertexAttrib4Nub;
    if (glad_glVertexAttrib4NubARB == NULL && glad_glVertexAttrib4ubNV != NULL) glad_glVertexAttrib4NubARB = (PFNGLVERTEXATTRIB4NUBARBPROC)glad_glVertexAttrib4ubNV;
    if (glad_glVertexAttrib4Nubv == NULL && glad_glVertexAttrib4NubvARB != NULL) glad_glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)glad_glVertexAttrib4NubvARB;
    if (glad_glVertexAttrib4Nubv == NULL && glad_glVertexAttrib4ubvNV != NULL) glad_glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)glad_glVertexAttrib4ubvNV;
    if (glad_glVertexAttrib4NubvARB == NULL && glad_glVertexAttrib4Nubv != NULL) glad_glVertexAttrib4NubvARB = (PFNGLVERTEXATTRIB4NUBVARBPROC)glad_glVertexAttrib4Nubv;
    if (glad_glVertexAttrib4NubvARB == NULL && glad_glVertexAttrib4ubvNV != NULL) glad_glVertexAttrib4NubvARB = (PFNGLVERTEXATTRIB4NUBVARBPROC)glad_glVertexAttrib4ubvNV;
    if (glad_glVertexAttrib4Nuiv == NULL && glad_glVertexAttrib4NuivARB != NULL) glad_glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)glad_glVertexAttrib4NuivARB;
    if (glad_glVertexAttrib4NuivARB == NULL && glad_glVertexAttrib4Nuiv != NULL) glad_glVertexAttrib4NuivARB = (PFNGLVERTEXATTRIB4NUIVARBPROC)glad_glVertexAttrib4Nuiv;
    if (glad_glVertexAttrib4Nusv == NULL && glad_glVertexAttrib4NusvARB != NULL) glad_glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)glad_glVertexAttrib4NusvARB;
    if (glad_glVertexAttrib4NusvARB == NULL && glad_glVertexAttrib4Nusv != NULL) glad_glVertexAttrib4NusvARB = (PFNGLVERTEXATTRIB4NUSVARBPROC)glad_glVertexAttrib4Nusv;
    if (glad_glVertexAttrib4s == NULL && glad_glVertexAttrib4sARB != NULL) glad_glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)glad_glVertexAttrib4sARB;
    if (glad_glVertexAttrib4s == NULL && glad_glVertexAttrib4sNV != NULL) glad_glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)glad_glVertexAttrib4sNV;
    if (glad_glVertexAttrib4sARB == NULL && glad_glVertexAttrib4s != NULL) glad_glVertexAttrib4sARB = (PFNGLVERTEXATTRIB4SARBPROC)glad_glVertexAttrib4s;
    if (glad_glVertexAttrib4sARB == NULL && glad_glVertexAttrib4sNV != NULL) glad_glVertexAttrib4sARB = (PFNGLVERTEXATTRIB4SARBPROC)glad_glVertexAttrib4sNV;
    if (glad_glVertexAttrib4sNV == NULL && glad_glVertexAttrib4s != NULL) glad_glVertexAttrib4sNV = (PFNGLVERTEXATTRIB4SNVPROC)glad_glVertexAttrib4s;
    if (glad_glVertexAttrib4sNV == NULL && glad_glVertexAttrib4sARB != NULL) glad_glVertexAttrib4sNV = (PFNGLVERTEXATTRIB4SNVPROC)glad_glVertexAttrib4sARB;
    if (glad_glVertexAttrib4sv == NULL && glad_glVertexAttrib4svARB != NULL) glad_glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)glad_glVertexAttrib4svARB;
    if (glad_glVertexAttrib4sv == NULL && glad_glVertexAttrib4svNV != NULL) glad_glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)glad_glVertexAttrib4svNV;
    if (glad_glVertexAttrib4svARB == NULL && glad_glVertexAttrib4sv != NULL) glad_glVertexAttrib4svARB = (PFNGLVERTEXATTRIB4SVARBPROC)glad_glVertexAttrib4sv;
    if (glad_glVertexAttrib4svARB == NULL && glad_glVertexAttrib4svNV != NULL) glad_glVertexAttrib4svARB = (PFNGLVERTEXATTRIB4SVARBPROC)glad_glVertexAttrib4svNV;
    if (glad_glVertexAttrib4svNV == NULL && glad_glVertexAttrib4sv != NULL) glad_glVertexAttrib4svNV = (PFNGLVERTEXATTRIB4SVNVPROC)glad_glVertexAttrib4sv;
    if (glad_glVertexAttrib4svNV == NULL && glad_glVertexAttrib4svARB != NULL) glad_glVertexAttrib4svNV = (PFNGLVERTEXATTRIB4SVNVPROC)glad_glVertexAttrib4svARB;
    if (glad_glVertexAttrib4ubNV == NULL && glad_glVertexAttrib4Nub != NULL) glad_glVertexAttrib4ubNV = (PFNGLVERTEXATTRIB4UBNVPROC)glad_glVertexAttrib4Nub;
    if (glad_glVertexAttrib4ubNV == NULL && glad_glVertexAttrib4NubARB != NULL) glad_glVertexAttrib4ubNV = (PFNGLVERTEXATTRIB4UBNVPROC)glad_glVertexAttrib4NubARB;
    if (glad_glVertexAttrib4ubv == NULL && glad_glVertexAttrib4ubvARB != NULL) glad_glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)glad_glVertexAttrib4ubvARB;
    if (glad_glVertexAttrib4ubvARB == NULL && glad_glVertexAttrib4ubv != NULL) glad_glVertexAttrib4ubvARB = (PFNGLVERTEXATTRIB4UBVARBPROC)glad_glVertexAttrib4ubv;
    if (glad_glVertexAttrib4ubvNV == NULL && glad_glVertexAttrib4Nubv != NULL) glad_glVertexAttrib4ubvNV = (PFNGLVERTEXATTRIB4UBVNVPROC)glad_glVertexAttrib4Nubv;
    if (glad_glVertexAttrib4ubvNV == NULL && glad_glVertexAttrib4NubvARB != NULL) glad_glVertexAttrib4ubvNV = (PFNGLVERTEXATTRIB4UBVNVPROC)glad_glVertexAttrib4NubvARB;
    if (glad_glVertexAttrib4uiv == NULL && glad_glVertexAttrib4uivARB != NULL) glad_glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)glad_glVertexAttrib4uivARB;
    if (glad_glVertexAttrib4uivARB == NULL && glad_glVertexAttrib4uiv != NULL) glad_glVertexAttrib4uivARB = (PFNGLVERTEXATTRIB4UIVARBPROC)glad_glVertexAttrib4uiv;
    if (glad_glVertexAttrib4usv == NULL && glad_glVertexAttrib4usvARB != NULL) glad_glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)glad_glVertexAttrib4usvARB;
    if (glad_glVertexAttrib4usvARB == NULL && glad_glVertexAttrib4usv != NULL) glad_glVertexAttrib4usvARB = (PFNGLVERTEXATTRIB4USVARBPROC)glad_glVertexAttrib4usv;
    if (glad_glVertexAttribPointer == NULL && glad_glVertexAttribPointerARB != NULL) glad_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)glad_glVertexAttribPointerARB;
    if (glad_glVertexAttribPointerARB == NULL && glad_glVertexAttribPointer != NULL) glad_glVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARBPROC)glad_glVertexAttribPointer;
    if (glad_glWindowPos2d == NULL && glad_glWindowPos2dARB != NULL) glad_glWindowPos2d = (PFNGLWINDOWPOS2DPROC)glad_glWindowPos2dARB;
    if (glad_glWindowPos2d == NULL && glad_glWindowPos2dMESA != NULL) glad_glWindowPos2d = (PFNGLWINDOWPOS2DPROC)glad_glWindowPos2dMESA;
    if (glad_glWindowPos2dARB == NULL && glad_glWindowPos2d != NULL) glad_glWindowPos2dARB = (PFNGLWINDOWPOS2DARBPROC)glad_glWindowPos2d;
    if (glad_glWindowPos2dARB == NULL && glad_glWindowPos2dMESA != NULL) glad_glWindowPos2dARB = (PFNGLWINDOWPOS2DARBPROC)glad_glWindowPos2dMESA;
    if (glad_glWindowPos2dMESA == NULL && glad_glWindowPos2d != NULL) glad_glWindowPos2dMESA = (PFNGLWINDOWPOS2DMESAPROC)glad_glWindowPos2d;
    if (glad_glWindowPos2dMESA == NULL && glad_glWindowPos2dARB != NULL) glad_glWindowPos2dMESA = (PFNGLWINDOWPOS2DMESAPROC)glad_glWindowPos2dARB;
    if (glad_glWindowPos2dv == NULL && glad_glWindowPos2dvARB != NULL) glad_glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC)glad_glWindowPos2dvARB;
    if (glad_glWindowPos2dv == NULL && glad_glWindowPos2dvMESA != NULL) glad_glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC)glad_glWindowPos2dvMESA;
    if (glad_glWindowPos2dvARB == NULL && glad_glWindowPos2dv != NULL) glad_glWindowPos2dvARB = (PFNGLWINDOWPOS2DVARBPROC)glad_glWindowPos2dv;
    if (glad_glWindowPos2dvARB == NULL && glad_glWindowPos2dvMESA != NULL) glad_glWindowPos2dvARB = (PFNGLWINDOWPOS2DVARBPROC)glad_glWindowPos2dvMESA;
    if (glad_glWindowPos2dvMESA == NULL && glad_glWindowPos2dv != NULL) glad_glWindowPos2dvMESA = (PFNGLWINDOWPOS2DVMESAPROC)glad_glWindowPos2dv;
    if (glad_glWindowPos2dvMESA == NULL && glad_glWindowPos2dvARB != NULL) glad_glWindowPos2dvMESA = (PFNGLWINDOWPOS2DVMESAPROC)glad_glWindowPos2dvARB;
    if (glad_glWindowPos2f == NULL && glad_glWindowPos2fARB != NULL) glad_glWindowPos2f = (PFNGLWINDOWPOS2FPROC)glad_glWindowPos2fARB;
    if (glad_glWindowPos2f == NULL && glad_glWindowPos2fMESA != NULL) glad_glWindowPos2f = (PFNGLWINDOWPOS2FPROC)glad_glWindowPos2fMESA;
    if (glad_glWindowPos2fARB == NULL && glad_glWindowPos2f != NULL) glad_glWindowPos2fARB = (PFNGLWINDOWPOS2FARBPROC)glad_glWindowPos2f;
    if (glad_glWindowPos2fARB == NULL && glad_glWindowPos2fMESA != NULL) glad_glWindowPos2fARB = (PFNGLWINDOWPOS2FARBPROC)glad_glWindowPos2fMESA;
    if (glad_glWindowPos2fMESA == NULL && glad_glWindowPos2f != NULL) glad_glWindowPos2fMESA = (PFNGLWINDOWPOS2FMESAPROC)glad_glWindowPos2f;
    if (glad_glWindowPos2fMESA == NULL && glad_glWindowPos2fARB != NULL) glad_glWindowPos2fMESA = (PFNGLWINDOWPOS2FMESAPROC)glad_glWindowPos2fARB;
    if (glad_glWindowPos2fv == NULL && glad_glWindowPos2fvARB != NULL) glad_glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC)glad_glWindowPos2fvARB;
    if (glad_glWindowPos2fv == NULL && glad_glWindowPos2fvMESA != NULL) glad_glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC)glad_glWindowPos2fvMESA;
    if (glad_glWindowPos2fvARB == NULL && glad_glWindowPos2fv != NULL) glad_glWindowPos2fvARB = (PFNGLWINDOWPOS2FVARBPROC)glad_glWindowPos2fv;
    if (glad_glWindowPos2fvARB == NULL && glad_glWindowPos2fvMESA != NULL) glad_glWindowPos2fvARB = (PFNGLWINDOWPOS2FVARBPROC)glad_glWindowPos2fvMESA;
    if (glad_glWindowPos2fvMESA == NULL && glad_glWindowPos2fv != NULL) glad_glWindowPos2fvMESA = (PFNGLWINDOWPOS2FVMESAPROC)glad_glWindowPos2fv;
    if (glad_glWindowPos2fvMESA == NULL && glad_glWindowPos2fvARB != NULL) glad_glWindowPos2fvMESA = (PFNGLWINDOWPOS2FVMESAPROC)glad_glWindowPos2fvARB;
    if (glad_glWindowPos2i == NULL && glad_glWindowPos2iARB != NULL) glad_glWindowPos2i = (PFNGLWINDOWPOS2IPROC)glad_glWindowPos2iARB;
    if (glad_glWindowPos2i == NULL && glad_glWindowPos2iMESA != NULL) glad_glWindowPos2i = (PFNGLWINDOWPOS2IPROC)glad_glWindowPos2iMESA;
    if (glad_glWindowPos2iARB == NULL && glad_glWindowPos2i != NULL) glad_glWindowPos2iARB = (PFNGLWINDOWPOS2IARBPROC)glad_glWindowPos2i;
    if (glad_glWindowPos2iARB == NULL && glad_glWindowPos2iMESA != NULL) glad_glWindowPos2iARB = (PFNGLWINDOWPOS2IARBPROC)glad_glWindowPos2iMESA;
    if (glad_glWindowPos2iMESA == NULL && glad_glWindowPos2i != NULL) glad_glWindowPos2iMESA = (PFNGLWINDOWPOS2IMESAPROC)glad_glWindowPos2i;
    if (glad_glWindowPos2iMESA == NULL && glad_glWindowPos2iARB != NULL) glad_glWindowPos2iMESA = (PFNGLWINDOWPOS2IMESAPROC)glad_glWindowPos2iARB;
    if (glad_glWindowPos2iv == NULL && glad_glWindowPos2ivARB != NULL) glad_glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC)glad_glWindowPos2ivARB;
    if (glad_glWindowPos2iv == NULL && glad_glWindowPos2ivMESA != NULL) glad_glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC)glad_glWindowPos2ivMESA;
    if (glad_glWindowPos2ivARB == NULL && glad_glWindowPos2iv != NULL) glad_glWindowPos2ivARB = (PFNGLWINDOWPOS2IVARBPROC)glad_glWindowPos2iv;
    if (glad_glWindowPos2ivARB == NULL && glad_glWindowPos2ivMESA != NULL) glad_glWindowPos2ivARB = (PFNGLWINDOWPOS2IVARBPROC)glad_glWindowPos2ivMESA;
    if (glad_glWindowPos2ivMESA == NULL && glad_glWindowPos2iv != NULL) glad_glWindowPos2ivMESA = (PFNGLWINDOWPOS2IVMESAPROC)glad_glWindowPos2iv;
    if (glad_glWindowPos2ivMESA == NULL && glad_glWindowPos2ivARB != NULL) glad_glWindowPos2ivMESA = (PFNGLWINDOWPOS2IVMESAPROC)glad_glWindowPos2ivARB;
    if (glad_glWindowPos2s == NULL && glad_glWindowPos2sARB != NULL) glad_glWindowPos2s = (PFNGLWINDOWPOS2SPROC)glad_glWindowPos2sARB;
    if (glad_glWindowPos2s == NULL && glad_glWindowPos2sMESA != NULL) glad_glWindowPos2s = (PFNGLWINDOWPOS2SPROC)glad_glWindowPos2sMESA;
    if (glad_glWindowPos2sARB == NULL && glad_glWindowPos2s != NULL) glad_glWindowPos2sARB = (PFNGLWINDOWPOS2SARBPROC)glad_glWindowPos2s;
    if (glad_glWindowPos2sARB == NULL && glad_glWindowPos2sMESA != NULL) glad_glWindowPos2sARB = (PFNGLWINDOWPOS2SARBPROC)glad_glWindowPos2sMESA;
    if (glad_glWindowPos2sMESA == NULL && glad_glWindowPos2s != NULL) glad_glWindowPos2sMESA = (PFNGLWINDOWPOS2SMESAPROC)glad_glWindowPos2s;
    if (glad_glWindowPos2sMESA == NULL && glad_glWindowPos2sARB != NULL) glad_glWindowPos2sMESA = (PFNGLWINDOWPOS2SMESAPROC)glad_glWindowPos2sARB;
    if (glad_glWindowPos2sv == NULL && glad_glWindowPos2svARB != NULL) glad_glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC)glad_glWindowPos2svARB;
    if (glad_glWindowPos2sv == NULL && glad_glWindowPos2svMESA != NULL) glad_glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC)glad_glWindowPos2svMESA;
    if (glad_glWindowPos2svARB == NULL && glad_glWindowPos2sv != NULL) glad_glWindowPos2svARB = (PFNGLWINDOWPOS2SVARBPROC)glad_glWindowPos2sv;
    if (glad_glWindowPos2svARB == NULL && glad_glWindowPos2svMESA != NULL) glad_glWindowPos2svARB = (PFNGLWINDOWPOS2SVARBPROC)glad_glWindowPos2svMESA;
    if (glad_glWindowPos2svMESA == NULL && glad_glWindowPos2sv != NULL) glad_glWindowPos2svMESA = (PFNGLWINDOWPOS2SVMESAPROC)glad_glWindowPos2sv;
    if (glad_glWindowPos2svMESA == NULL && glad_glWindowPos2svARB != NULL) glad_glWindowPos2svMESA = (PFNGLWINDOWPOS2SVMESAPROC)glad_glWindowPos2svARB;
    if (glad_glWindowPos3d == NULL && glad_glWindowPos3dARB != NULL) glad_glWindowPos3d = (PFNGLWINDOWPOS3DPROC)glad_glWindowPos3dARB;
    if (glad_glWindowPos3d == NULL && glad_glWindowPos3dMESA != NULL) glad_glWindowPos3d = (PFNGLWINDOWPOS3DPROC)glad_glWindowPos3dMESA;
    if (glad_glWindowPos3dARB == NULL && glad_glWindowPos3d != NULL) glad_glWindowPos3dARB = (PFNGLWINDOWPOS3DARBPROC)glad_glWindowPos3d;
    if (glad_glWindowPos3dARB == NULL && glad_glWindowPos3dMESA != NULL) glad_glWindowPos3dARB = (PFNGLWINDOWPOS3DARBPROC)glad_glWindowPos3dMESA;
    if (glad_glWindowPos3dMESA == NULL && glad_glWindowPos3d != NULL) glad_glWindowPos3dMESA = (PFNGLWINDOWPOS3DMESAPROC)glad_glWindowPos3d;
    if (glad_glWindowPos3dMESA == NULL && glad_glWindowPos3dARB != NULL) glad_glWindowPos3dMESA = (PFNGLWINDOWPOS3DMESAPROC)glad_glWindowPos3dARB;
    if (glad_glWindowPos3dv == NULL && glad_glWindowPos3dvARB != NULL) glad_glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC)glad_glWindowPos3dvARB;
    if (glad_glWindowPos3dv == NULL && glad_glWindowPos3dvMESA != NULL) glad_glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC)glad_glWindowPos3dvMESA;
    if (glad_glWindowPos3dvARB == NULL && glad_glWindowPos3dv != NULL) glad_glWindowPos3dvARB = (PFNGLWINDOWPOS3DVARBPROC)glad_glWindowPos3dv;
    if (glad_glWindowPos3dvARB == NULL && glad_glWindowPos3dvMESA != NULL) glad_glWindowPos3dvARB = (PFNGLWINDOWPOS3DVARBPROC)glad_glWindowPos3dvMESA;
    if (glad_glWindowPos3dvMESA == NULL && glad_glWindowPos3dv != NULL) glad_glWindowPos3dvMESA = (PFNGLWINDOWPOS3DVMESAPROC)glad_glWindowPos3dv;
    if (glad_glWindowPos3dvMESA == NULL && glad_glWindowPos3dvARB != NULL) glad_glWindowPos3dvMESA = (PFNGLWINDOWPOS3DVMESAPROC)glad_glWindowPos3dvARB;
    if (glad_glWindowPos3f == NULL && glad_glWindowPos3fARB != NULL) glad_glWindowPos3f = (PFNGLWINDOWPOS3FPROC)glad_glWindowPos3fARB;
    if (glad_glWindowPos3f == NULL && glad_glWindowPos3fMESA != NULL) glad_glWindowPos3f = (PFNGLWINDOWPOS3FPROC)glad_glWindowPos3fMESA;
    if (glad_glWindowPos3fARB == NULL && glad_glWindowPos3f != NULL) glad_glWindowPos3fARB = (PFNGLWINDOWPOS3FARBPROC)glad_glWindowPos3f;
    if (glad_glWindowPos3fARB == NULL && glad_glWindowPos3fMESA != NULL) glad_glWindowPos3fARB = (PFNGLWINDOWPOS3FARBPROC)glad_glWindowPos3fMESA;
    if (glad_glWindowPos3fMESA == NULL && glad_glWindowPos3f != NULL) glad_glWindowPos3fMESA = (PFNGLWINDOWPOS3FMESAPROC)glad_glWindowPos3f;
    if (glad_glWindowPos3fMESA == NULL && glad_glWindowPos3fARB != NULL) glad_glWindowPos3fMESA = (PFNGLWINDOWPOS3FMESAPROC)glad_glWindowPos3fARB;
    if (glad_glWindowPos3fv == NULL && glad_glWindowPos3fvARB != NULL) glad_glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC)glad_glWindowPos3fvARB;
    if (glad_glWindowPos3fv == NULL && glad_glWindowPos3fvMESA != NULL) glad_glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC)glad_glWindowPos3fvMESA;
    if (glad_glWindowPos3fvARB == NULL && glad_glWindowPos3fv != NULL) glad_glWindowPos3fvARB = (PFNGLWINDOWPOS3FVARBPROC)glad_glWindowPos3fv;
    if (glad_glWindowPos3fvARB == NULL && glad_glWindowPos3fvMESA != NULL) glad_glWindowPos3fvARB = (PFNGLWINDOWPOS3FVARBPROC)glad_glWindowPos3fvMESA;
    if (glad_glWindowPos3fvMESA == NULL && glad_glWindowPos3fv != NULL) glad_glWindowPos3fvMESA = (PFNGLWINDOWPOS3FVMESAPROC)glad_glWindowPos3fv;
    if (glad_glWindowPos3fvMESA == NULL && glad_glWindowPos3fvARB != NULL) glad_glWindowPos3fvMESA = (PFNGLWINDOWPOS3FVMESAPROC)glad_glWindowPos3fvARB;
    if (glad_glWindowPos3i == NULL && glad_glWindowPos3iARB != NULL) glad_glWindowPos3i = (PFNGLWINDOWPOS3IPROC)glad_glWindowPos3iARB;
    if (glad_glWindowPos3i == NULL && glad_glWindowPos3iMESA != NULL) glad_glWindowPos3i = (PFNGLWINDOWPOS3IPROC)glad_glWindowPos3iMESA;
    if (glad_glWindowPos3iARB == NULL && glad_glWindowPos3i != NULL) glad_glWindowPos3iARB = (PFNGLWINDOWPOS3IARBPROC)glad_glWindowPos3i;
    if (glad_glWindowPos3iARB == NULL && glad_glWindowPos3iMESA != NULL) glad_glWindowPos3iARB = (PFNGLWINDOWPOS3IARBPROC)glad_glWindowPos3iMESA;
    if (glad_glWindowPos3iMESA == NULL && glad_glWindowPos3i != NULL) glad_glWindowPos3iMESA = (PFNGLWINDOWPOS3IMESAPROC)glad_glWindowPos3i;
    if (glad_glWindowPos3iMESA == NULL && glad_glWindowPos3iARB != NULL) glad_glWindowPos3iMESA = (PFNGLWINDOWPOS3IMESAPROC)glad_glWindowPos3iARB;
    if (glad_glWindowPos3iv == NULL && glad_glWindowPos3ivARB != NULL) glad_glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC)glad_glWindowPos3ivARB;
    if (glad_glWindowPos3iv == NULL && glad_glWindowPos3ivMESA != NULL) glad_glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC)glad_glWindowPos3ivMESA;
    if (glad_glWindowPos3ivARB == NULL && glad_glWindowPos3iv != NULL) glad_glWindowPos3ivARB = (PFNGLWINDOWPOS3IVARBPROC)glad_glWindowPos3iv;
    if (glad_glWindowPos3ivARB == NULL && glad_glWindowPos3ivMESA != NULL) glad_glWindowPos3ivARB = (PFNGLWINDOWPOS3IVARBPROC)glad_glWindowPos3ivMESA;
    if (glad_glWindowPos3ivMESA == NULL && glad_glWindowPos3iv != NULL) glad_glWindowPos3ivMESA = (PFNGLWINDOWPOS3IVMESAPROC)glad_glWindowPos3iv;
    if (glad_glWindowPos3ivMESA == NULL && glad_glWindowPos3ivARB != NULL) glad_glWindowPos3ivMESA = (PFNGLWINDOWPOS3IVMESAPROC)glad_glWindowPos3ivARB;
    if (glad_glWindowPos3s == NULL && glad_glWindowPos3sARB != NULL) glad_glWindowPos3s = (PFNGLWINDOWPOS3SPROC)glad_glWindowPos3sARB;
    if (glad_glWindowPos3s == NULL && glad_glWindowPos3sMESA != NULL) glad_glWindowPos3s = (PFNGLWINDOWPOS3SPROC)glad_glWindowPos3sMESA;
    if (glad_glWindowPos3sARB == NULL && glad_glWindowPos3s != NULL) glad_glWindowPos3sARB = (PFNGLWINDOWPOS3SARBPROC)glad_glWindowPos3s;
    if (glad_glWindowPos3sARB == NULL && glad_glWindowPos3sMESA != NULL) glad_glWindowPos3sARB = (PFNGLWINDOWPOS3SARBPROC)glad_glWindowPos3sMESA;
    if (glad_glWindowPos3sMESA == NULL && glad_glWindowPos3s != NULL) glad_glWindowPos3sMESA = (PFNGLWINDOWPOS3SMESAPROC)glad_glWindowPos3s;
    if (glad_glWindowPos3sMESA == NULL && glad_glWindowPos3sARB != NULL) glad_glWindowPos3sMESA = (PFNGLWINDOWPOS3SMESAPROC)glad_glWindowPos3sARB;
    if (glad_glWindowPos3sv == NULL && glad_glWindowPos3svARB != NULL) glad_glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC)glad_glWindowPos3svARB;
    if (glad_glWindowPos3sv == NULL && glad_glWindowPos3svMESA != NULL) glad_glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC)glad_glWindowPos3svMESA;
    if (glad_glWindowPos3svARB == NULL && glad_glWindowPos3sv != NULL) glad_glWindowPos3svARB = (PFNGLWINDOWPOS3SVARBPROC)glad_glWindowPos3sv;
    if (glad_glWindowPos3svARB == NULL && glad_glWindowPos3svMESA != NULL) glad_glWindowPos3svARB = (PFNGLWINDOWPOS3SVARBPROC)glad_glWindowPos3svMESA;
    if (glad_glWindowPos3svMESA == NULL && glad_glWindowPos3sv != NULL) glad_glWindowPos3svMESA = (PFNGLWINDOWPOS3SVMESAPROC)glad_glWindowPos3sv;
    if (glad_glWindowPos3svMESA == NULL && glad_glWindowPos3svARB != NULL) glad_glWindowPos3svMESA = (PFNGLWINDOWPOS3SVMESAPROC)glad_glWindowPos3svARB;
}

static void glad_gl_free_extensions(char **exts_i) {
    if (exts_i != NULL) {
        unsigned int index;
        for(index = 0; exts_i[index]; index++) {
            free((void *) (exts_i[index]));
        }
        free((void *)exts_i);
        exts_i = NULL;
    }
}
static int glad_gl_get_extensions( const char **out_exts, char ***out_exts_i) {
#if defined(GL_ES_VERSION_3_0) || defined(GL_VERSION_3_0)
    if (glad_glGetStringi != NULL && glad_glGetIntegerv != NULL) {
        unsigned int index = 0;
        unsigned int num_exts_i = 0;
        char **exts_i = NULL;
        glad_glGetIntegerv(GL_NUM_EXTENSIONS, (int*) &num_exts_i);
        exts_i = (char **) malloc((num_exts_i + 1) * (sizeof *exts_i));
        if (exts_i == NULL) {
            return 0;
        }
        for(index = 0; index < num_exts_i; index++) {
            const char *gl_str_tmp = (const char*) glad_glGetStringi(GL_EXTENSIONS, index);
            size_t len = strlen(gl_str_tmp) + 1;

            char *local_str = (char*) malloc(len * sizeof(char));
            if(local_str == NULL) {
                exts_i[index] = NULL;
                glad_gl_free_extensions(exts_i);
                return 0;
            }

            memcpy(local_str, gl_str_tmp, len * sizeof(char));
            exts_i[index] = local_str;
        }
        exts_i[index] = NULL;

        *out_exts_i = exts_i;

        return 1;
    }
#else
    GLAD_UNUSED(out_exts_i);
#endif
    if (glad_glGetString == NULL) {
        return 0;
    }
    *out_exts = (const char *)glad_glGetString(GL_EXTENSIONS);
    return 1;
}
static int glad_gl_has_extension(const char *exts, char **exts_i, const char *ext) {
    if(exts_i) {
        unsigned int index;
        for(index = 0; exts_i[index]; index++) {
            const char *e = exts_i[index];
            if(strcmp(e, ext) == 0) {
                return 1;
            }
        }
    } else {
        const char *extensions;
        const char *loc;
        const char *terminator;
        extensions = exts;
        if(extensions == NULL || ext == NULL) {
            return 0;
        }
        while(1) {
            loc = strstr(extensions, ext);
            if(loc == NULL) {
                return 0;
            }
            terminator = loc + strlen(ext);
            if((loc == extensions || *(loc - 1) == ' ') &&
                (*terminator == ' ' || *terminator == '\0')) {
                return 1;
            }
            extensions = terminator;
        }
    }
    return 0;
}

static GLADapiproc glad_gl_get_proc_from_userptr(void *userptr, const char* name) {
    return (GLAD_GNUC_EXTENSION (GLADapiproc (*)(const char *name)) userptr)(name);
}

static int glad_gl_find_extensions_gl(void) {
    const char *exts = NULL;
    char **exts_i = NULL;
    if (!glad_gl_get_extensions(&exts, &exts_i)) return 0;

    GLAD_GL_ARB_draw_buffers = glad_gl_has_extension(exts, exts_i, "GL_ARB_draw_buffers");
    GLAD_GL_ARB_fragment_program = glad_gl_has_extension(exts, exts_i, "GL_ARB_fragment_program");
    GLAD_GL_ARB_imaging = glad_gl_has_extension(exts, exts_i, "GL_ARB_imaging");
    GLAD_GL_ARB_multisample = glad_gl_has_extension(exts, exts_i, "GL_ARB_multisample");
    GLAD_GL_ARB_multitexture = glad_gl_has_extension(exts, exts_i, "GL_ARB_multitexture");
    GLAD_GL_ARB_occlusion_query = glad_gl_has_extension(exts, exts_i, "GL_ARB_occlusion_query");
    GLAD_GL_ARB_point_parameters = glad_gl_has_extension(exts, exts_i, "GL_ARB_point_parameters");
    GLAD_GL_ARB_shader_objects = glad_gl_has_extension(exts, exts_i, "GL_ARB_shader_objects");
    GLAD_GL_ARB_texture_compression = glad_gl_has_extension(exts, exts_i, "GL_ARB_texture_compression");
    GLAD_GL_ARB_texture_cube_map = glad_gl_has_extension(exts, exts_i, "GL_ARB_texture_cube_map");
    GLAD_GL_ARB_transpose_matrix = glad_gl_has_extension(exts, exts_i, "GL_ARB_transpose_matrix");
    GLAD_GL_ARB_vertex_buffer_object = glad_gl_has_extension(exts, exts_i, "GL_ARB_vertex_buffer_object");
    GLAD_GL_ARB_vertex_program = glad_gl_has_extension(exts, exts_i, "GL_ARB_vertex_program");
    GLAD_GL_ARB_vertex_shader = glad_gl_has_extension(exts, exts_i, "GL_ARB_vertex_shader");
    GLAD_GL_ARB_window_pos = glad_gl_has_extension(exts, exts_i, "GL_ARB_window_pos");
    GLAD_GL_ATI_draw_buffers = glad_gl_has_extension(exts, exts_i, "GL_ATI_draw_buffers");
    GLAD_GL_ATI_separate_stencil = glad_gl_has_extension(exts, exts_i, "GL_ATI_separate_stencil");
    GLAD_GL_EXT_blend_color = glad_gl_has_extension(exts, exts_i, "GL_EXT_blend_color");
    GLAD_GL_EXT_blend_equation_separate = glad_gl_has_extension(exts, exts_i, "GL_EXT_blend_equation_separate");
    GLAD_GL_EXT_blend_func_separate = glad_gl_has_extension(exts, exts_i, "GL_EXT_blend_func_separate");
    GLAD_GL_EXT_blend_minmax = glad_gl_has_extension(exts, exts_i, "GL_EXT_blend_minmax");
    GLAD_GL_EXT_copy_texture = glad_gl_has_extension(exts, exts_i, "GL_EXT_copy_texture");
    GLAD_GL_EXT_draw_range_elements = glad_gl_has_extension(exts, exts_i, "GL_EXT_draw_range_elements");
    GLAD_GL_EXT_fog_coord = glad_gl_has_extension(exts, exts_i, "GL_EXT_fog_coord");
    GLAD_GL_EXT_multi_draw_arrays = glad_gl_has_extension(exts, exts_i, "GL_EXT_multi_draw_arrays");
    GLAD_GL_EXT_point_parameters = glad_gl_has_extension(exts, exts_i, "GL_EXT_point_parameters");
    GLAD_GL_EXT_secondary_color = glad_gl_has_extension(exts, exts_i, "GL_EXT_secondary_color");
    GLAD_GL_EXT_subtexture = glad_gl_has_extension(exts, exts_i, "GL_EXT_subtexture");
    GLAD_GL_EXT_texture3D = glad_gl_has_extension(exts, exts_i, "GL_EXT_texture3D");
    GLAD_GL_EXT_texture_compression_s3tc = glad_gl_has_extension(exts, exts_i, "GL_EXT_texture_compression_s3tc");
    GLAD_GL_EXT_texture_filter_anisotropic = glad_gl_has_extension(exts, exts_i, "GL_EXT_texture_filter_anisotropic");
    GLAD_GL_EXT_texture_object = glad_gl_has_extension(exts, exts_i, "GL_EXT_texture_object");
    GLAD_GL_EXT_vertex_array = glad_gl_has_extension(exts, exts_i, "GL_EXT_vertex_array");
    GLAD_GL_INGR_blend_func_separate = glad_gl_has_extension(exts, exts_i, "GL_INGR_blend_func_separate");
    GLAD_GL_KHR_debug = glad_gl_has_extension(exts, exts_i, "GL_KHR_debug");
    GLAD_GL_MESA_window_pos = glad_gl_has_extension(exts, exts_i, "GL_MESA_window_pos");
    GLAD_GL_NV_point_sprite = glad_gl_has_extension(exts, exts_i, "GL_NV_point_sprite");
    GLAD_GL_NV_vertex_program = glad_gl_has_extension(exts, exts_i, "GL_NV_vertex_program");
    GLAD_GL_SGIS_point_parameters = glad_gl_has_extension(exts, exts_i, "GL_SGIS_point_parameters");

    glad_gl_free_extensions(exts_i);

    return 1;
}

static int glad_gl_find_core_gl(void) {
    int i;
    const char* version;
    const char* prefixes[] = {
        "OpenGL ES-CM ",
        "OpenGL ES-CL ",
        "OpenGL ES ",
        "OpenGL SC ",
        NULL
    };
    int major = 0;
    int minor = 0;
    version = (const char*) glad_glGetString(GL_VERSION);
    if (!version) return 0;
    for (i = 0;  prefixes[i];  i++) {
        const size_t length = strlen(prefixes[i]);
        if (strncmp(version, prefixes[i], length) == 0) {
            version += length;
            break;
        }
    }

    GLAD_IMPL_UTIL_SSCANF(version, "%d.%d", &major, &minor);

    GLAD_GL_VERSION_1_0 = (major == 1 && minor >= 0) || major > 1;
    GLAD_GL_VERSION_1_1 = (major == 1 && minor >= 1) || major > 1;
    GLAD_GL_VERSION_1_2 = (major == 1 && minor >= 2) || major > 1;
    GLAD_GL_VERSION_1_3 = (major == 1 && minor >= 3) || major > 1;
    GLAD_GL_VERSION_1_4 = (major == 1 && minor >= 4) || major > 1;
    GLAD_GL_VERSION_1_5 = (major == 1 && minor >= 5) || major > 1;
    GLAD_GL_VERSION_2_0 = (major == 2 && minor >= 0) || major > 2;
    GLAD_GL_VERSION_2_1 = (major == 2 && minor >= 1) || major > 2;

    return GLAD_MAKE_VERSION(major, minor);
}

int gladLoadGLUserPtr( GLADuserptrloadfunc load, void *userptr) {
    int version;

    glad_glGetString = (PFNGLGETSTRINGPROC) load(userptr, "glGetString");
    if(glad_glGetString == NULL) return 0;
    version = glad_gl_find_core_gl();

    glad_gl_load_GL_VERSION_1_0(load, userptr);
    glad_gl_load_GL_VERSION_1_1(load, userptr);
    glad_gl_load_GL_VERSION_1_2(load, userptr);
    glad_gl_load_GL_VERSION_1_3(load, userptr);
    glad_gl_load_GL_VERSION_1_4(load, userptr);
    glad_gl_load_GL_VERSION_1_5(load, userptr);
    glad_gl_load_GL_VERSION_2_0(load, userptr);
    glad_gl_load_GL_VERSION_2_1(load, userptr);

    if (!glad_gl_find_extensions_gl()) return 0;
    glad_gl_load_GL_ARB_draw_buffers(load, userptr);
    glad_gl_load_GL_ARB_fragment_program(load, userptr);
    glad_gl_load_GL_ARB_imaging(load, userptr);
    glad_gl_load_GL_ARB_multisample(load, userptr);
    glad_gl_load_GL_ARB_multitexture(load, userptr);
    glad_gl_load_GL_ARB_occlusion_query(load, userptr);
    glad_gl_load_GL_ARB_point_parameters(load, userptr);
    glad_gl_load_GL_ARB_shader_objects(load, userptr);
    glad_gl_load_GL_ARB_texture_compression(load, userptr);
    glad_gl_load_GL_ARB_transpose_matrix(load, userptr);
    glad_gl_load_GL_ARB_vertex_buffer_object(load, userptr);
    glad_gl_load_GL_ARB_vertex_program(load, userptr);
    glad_gl_load_GL_ARB_vertex_shader(load, userptr);
    glad_gl_load_GL_ARB_window_pos(load, userptr);
    glad_gl_load_GL_ATI_draw_buffers(load, userptr);
    glad_gl_load_GL_ATI_separate_stencil(load, userptr);
    glad_gl_load_GL_EXT_blend_color(load, userptr);
    glad_gl_load_GL_EXT_blend_equation_separate(load, userptr);
    glad_gl_load_GL_EXT_blend_func_separate(load, userptr);
    glad_gl_load_GL_EXT_blend_minmax(load, userptr);
    glad_gl_load_GL_EXT_copy_texture(load, userptr);
    glad_gl_load_GL_EXT_draw_range_elements(load, userptr);
    glad_gl_load_GL_EXT_fog_coord(load, userptr);
    glad_gl_load_GL_EXT_multi_draw_arrays(load, userptr);
    glad_gl_load_GL_EXT_point_parameters(load, userptr);
    glad_gl_load_GL_EXT_secondary_color(load, userptr);
    glad_gl_load_GL_EXT_subtexture(load, userptr);
    glad_gl_load_GL_EXT_texture3D(load, userptr);
    glad_gl_load_GL_EXT_texture_object(load, userptr);
    glad_gl_load_GL_EXT_vertex_array(load, userptr);
    glad_gl_load_GL_INGR_blend_func_separate(load, userptr);
    glad_gl_load_GL_KHR_debug(load, userptr);
    glad_gl_load_GL_MESA_window_pos(load, userptr);
    glad_gl_load_GL_NV_point_sprite(load, userptr);
    glad_gl_load_GL_NV_vertex_program(load, userptr);
    glad_gl_load_GL_SGIS_point_parameters(load, userptr);


    glad_gl_resolve_aliases();

    return version;
}


int gladLoadGL( GLADloadfunc load) {
    return gladLoadGLUserPtr( glad_gl_get_proc_from_userptr, GLAD_GNUC_EXTENSION (void*) load);
}



 
void gladInstallGLDebug(void) {
    glad_debug_glAccum = glad_debug_impl_glAccum;
    glad_debug_glActiveTexture = glad_debug_impl_glActiveTexture;
    glad_debug_glActiveTextureARB = glad_debug_impl_glActiveTextureARB;
    glad_debug_glAlphaFunc = glad_debug_impl_glAlphaFunc;
    glad_debug_glAreProgramsResidentNV = glad_debug_impl_glAreProgramsResidentNV;
    glad_debug_glAreTexturesResident = glad_debug_impl_glAreTexturesResident;
    glad_debug_glAreTexturesResidentEXT = glad_debug_impl_glAreTexturesResidentEXT;
    glad_debug_glArrayElement = glad_debug_impl_glArrayElement;
    glad_debug_glArrayElementEXT = glad_debug_impl_glArrayElementEXT;
    glad_debug_glAttachObjectARB = glad_debug_impl_glAttachObjectARB;
    glad_debug_glAttachShader = glad_debug_impl_glAttachShader;
    glad_debug_glBegin = glad_debug_impl_glBegin;
    glad_debug_glBeginQuery = glad_debug_impl_glBeginQuery;
    glad_debug_glBeginQueryARB = glad_debug_impl_glBeginQueryARB;
    glad_debug_glBindAttribLocation = glad_debug_impl_glBindAttribLocation;
    glad_debug_glBindAttribLocationARB = glad_debug_impl_glBindAttribLocationARB;
    glad_debug_glBindBuffer = glad_debug_impl_glBindBuffer;
    glad_debug_glBindBufferARB = glad_debug_impl_glBindBufferARB;
    glad_debug_glBindProgramARB = glad_debug_impl_glBindProgramARB;
    glad_debug_glBindProgramNV = glad_debug_impl_glBindProgramNV;
    glad_debug_glBindTexture = glad_debug_impl_glBindTexture;
    glad_debug_glBindTextureEXT = glad_debug_impl_glBindTextureEXT;
    glad_debug_glBitmap = glad_debug_impl_glBitmap;
    glad_debug_glBlendColor = glad_debug_impl_glBlendColor;
    glad_debug_glBlendColorEXT = glad_debug_impl_glBlendColorEXT;
    glad_debug_glBlendEquation = glad_debug_impl_glBlendEquation;
    glad_debug_glBlendEquationEXT = glad_debug_impl_glBlendEquationEXT;
    glad_debug_glBlendEquationSeparate = glad_debug_impl_glBlendEquationSeparate;
    glad_debug_glBlendEquationSeparateEXT = glad_debug_impl_glBlendEquationSeparateEXT;
    glad_debug_glBlendFunc = glad_debug_impl_glBlendFunc;
    glad_debug_glBlendFuncSeparate = glad_debug_impl_glBlendFuncSeparate;
    glad_debug_glBlendFuncSeparateEXT = glad_debug_impl_glBlendFuncSeparateEXT;
    glad_debug_glBlendFuncSeparateINGR = glad_debug_impl_glBlendFuncSeparateINGR;
    glad_debug_glBufferData = glad_debug_impl_glBufferData;
    glad_debug_glBufferDataARB = glad_debug_impl_glBufferDataARB;
    glad_debug_glBufferSubData = glad_debug_impl_glBufferSubData;
    glad_debug_glBufferSubDataARB = glad_debug_impl_glBufferSubDataARB;
    glad_debug_glCallList = glad_debug_impl_glCallList;
    glad_debug_glCallLists = glad_debug_impl_glCallLists;
    glad_debug_glClear = glad_debug_impl_glClear;
    glad_debug_glClearAccum = glad_debug_impl_glClearAccum;
    glad_debug_glClearColor = glad_debug_impl_glClearColor;
    glad_debug_glClearDepth = glad_debug_impl_glClearDepth;
    glad_debug_glClearIndex = glad_debug_impl_glClearIndex;
    glad_debug_glClearStencil = glad_debug_impl_glClearStencil;
    glad_debug_glClientActiveTexture = glad_debug_impl_glClientActiveTexture;
    glad_debug_glClientActiveTextureARB = glad_debug_impl_glClientActiveTextureARB;
    glad_debug_glClipPlane = glad_debug_impl_glClipPlane;
    glad_debug_glColor3b = glad_debug_impl_glColor3b;
    glad_debug_glColor3bv = glad_debug_impl_glColor3bv;
    glad_debug_glColor3d = glad_debug_impl_glColor3d;
    glad_debug_glColor3dv = glad_debug_impl_glColor3dv;
    glad_debug_glColor3f = glad_debug_impl_glColor3f;
    glad_debug_glColor3fv = glad_debug_impl_glColor3fv;
    glad_debug_glColor3i = glad_debug_impl_glColor3i;
    glad_debug_glColor3iv = glad_debug_impl_glColor3iv;
    glad_debug_glColor3s = glad_debug_impl_glColor3s;
    glad_debug_glColor3sv = glad_debug_impl_glColor3sv;
    glad_debug_glColor3ub = glad_debug_impl_glColor3ub;
    glad_debug_glColor3ubv = glad_debug_impl_glColor3ubv;
    glad_debug_glColor3ui = glad_debug_impl_glColor3ui;
    glad_debug_glColor3uiv = glad_debug_impl_glColor3uiv;
    glad_debug_glColor3us = glad_debug_impl_glColor3us;
    glad_debug_glColor3usv = glad_debug_impl_glColor3usv;
    glad_debug_glColor4b = glad_debug_impl_glColor4b;
    glad_debug_glColor4bv = glad_debug_impl_glColor4bv;
    glad_debug_glColor4d = glad_debug_impl_glColor4d;
    glad_debug_glColor4dv = glad_debug_impl_glColor4dv;
    glad_debug_glColor4f = glad_debug_impl_glColor4f;
    glad_debug_glColor4fv = glad_debug_impl_glColor4fv;
    glad_debug_glColor4i = glad_debug_impl_glColor4i;
    glad_debug_glColor4iv = glad_debug_impl_glColor4iv;
    glad_debug_glColor4s = glad_debug_impl_glColor4s;
    glad_debug_glColor4sv = glad_debug_impl_glColor4sv;
    glad_debug_glColor4ub = glad_debug_impl_glColor4ub;
    glad_debug_glColor4ubv = glad_debug_impl_glColor4ubv;
    glad_debug_glColor4ui = glad_debug_impl_glColor4ui;
    glad_debug_glColor4uiv = glad_debug_impl_glColor4uiv;
    glad_debug_glColor4us = glad_debug_impl_glColor4us;
    glad_debug_glColor4usv = glad_debug_impl_glColor4usv;
    glad_debug_glColorMask = glad_debug_impl_glColorMask;
    glad_debug_glColorMaterial = glad_debug_impl_glColorMaterial;
    glad_debug_glColorPointer = glad_debug_impl_glColorPointer;
    glad_debug_glColorPointerEXT = glad_debug_impl_glColorPointerEXT;
    glad_debug_glColorSubTable = glad_debug_impl_glColorSubTable;
    glad_debug_glColorTable = glad_debug_impl_glColorTable;
    glad_debug_glColorTableParameterfv = glad_debug_impl_glColorTableParameterfv;
    glad_debug_glColorTableParameteriv = glad_debug_impl_glColorTableParameteriv;
    glad_debug_glCompileShader = glad_debug_impl_glCompileShader;
    glad_debug_glCompileShaderARB = glad_debug_impl_glCompileShaderARB;
    glad_debug_glCompressedTexImage1D = glad_debug_impl_glCompressedTexImage1D;
    glad_debug_glCompressedTexImage1DARB = glad_debug_impl_glCompressedTexImage1DARB;
    glad_debug_glCompressedTexImage2D = glad_debug_impl_glCompressedTexImage2D;
    glad_debug_glCompressedTexImage2DARB = glad_debug_impl_glCompressedTexImage2DARB;
    glad_debug_glCompressedTexImage3D = glad_debug_impl_glCompressedTexImage3D;
    glad_debug_glCompressedTexImage3DARB = glad_debug_impl_glCompressedTexImage3DARB;
    glad_debug_glCompressedTexSubImage1D = glad_debug_impl_glCompressedTexSubImage1D;
    glad_debug_glCompressedTexSubImage1DARB = glad_debug_impl_glCompressedTexSubImage1DARB;
    glad_debug_glCompressedTexSubImage2D = glad_debug_impl_glCompressedTexSubImage2D;
    glad_debug_glCompressedTexSubImage2DARB = glad_debug_impl_glCompressedTexSubImage2DARB;
    glad_debug_glCompressedTexSubImage3D = glad_debug_impl_glCompressedTexSubImage3D;
    glad_debug_glCompressedTexSubImage3DARB = glad_debug_impl_glCompressedTexSubImage3DARB;
    glad_debug_glConvolutionFilter1D = glad_debug_impl_glConvolutionFilter1D;
    glad_debug_glConvolutionFilter2D = glad_debug_impl_glConvolutionFilter2D;
    glad_debug_glConvolutionParameterf = glad_debug_impl_glConvolutionParameterf;
    glad_debug_glConvolutionParameterfv = glad_debug_impl_glConvolutionParameterfv;
    glad_debug_glConvolutionParameteri = glad_debug_impl_glConvolutionParameteri;
    glad_debug_glConvolutionParameteriv = glad_debug_impl_glConvolutionParameteriv;
    glad_debug_glCopyColorSubTable = glad_debug_impl_glCopyColorSubTable;
    glad_debug_glCopyColorTable = glad_debug_impl_glCopyColorTable;
    glad_debug_glCopyConvolutionFilter1D = glad_debug_impl_glCopyConvolutionFilter1D;
    glad_debug_glCopyConvolutionFilter2D = glad_debug_impl_glCopyConvolutionFilter2D;
    glad_debug_glCopyPixels = glad_debug_impl_glCopyPixels;
    glad_debug_glCopyTexImage1D = glad_debug_impl_glCopyTexImage1D;
    glad_debug_glCopyTexImage1DEXT = glad_debug_impl_glCopyTexImage1DEXT;
    glad_debug_glCopyTexImage2D = glad_debug_impl_glCopyTexImage2D;
    glad_debug_glCopyTexImage2DEXT = glad_debug_impl_glCopyTexImage2DEXT;
    glad_debug_glCopyTexSubImage1D = glad_debug_impl_glCopyTexSubImage1D;
    glad_debug_glCopyTexSubImage1DEXT = glad_debug_impl_glCopyTexSubImage1DEXT;
    glad_debug_glCopyTexSubImage2D = glad_debug_impl_glCopyTexSubImage2D;
    glad_debug_glCopyTexSubImage2DEXT = glad_debug_impl_glCopyTexSubImage2DEXT;
    glad_debug_glCopyTexSubImage3D = glad_debug_impl_glCopyTexSubImage3D;
    glad_debug_glCopyTexSubImage3DEXT = glad_debug_impl_glCopyTexSubImage3DEXT;
    glad_debug_glCreateProgram = glad_debug_impl_glCreateProgram;
    glad_debug_glCreateProgramObjectARB = glad_debug_impl_glCreateProgramObjectARB;
    glad_debug_glCreateShader = glad_debug_impl_glCreateShader;
    glad_debug_glCreateShaderObjectARB = glad_debug_impl_glCreateShaderObjectARB;
    glad_debug_glCullFace = glad_debug_impl_glCullFace;
    glad_debug_glDebugMessageCallback = glad_debug_impl_glDebugMessageCallback;
    glad_debug_glDebugMessageControl = glad_debug_impl_glDebugMessageControl;
    glad_debug_glDebugMessageInsert = glad_debug_impl_glDebugMessageInsert;
    glad_debug_glDeleteBuffers = glad_debug_impl_glDeleteBuffers;
    glad_debug_glDeleteBuffersARB = glad_debug_impl_glDeleteBuffersARB;
    glad_debug_glDeleteLists = glad_debug_impl_glDeleteLists;
    glad_debug_glDeleteObjectARB = glad_debug_impl_glDeleteObjectARB;
    glad_debug_glDeleteProgram = glad_debug_impl_glDeleteProgram;
    glad_debug_glDeleteProgramsARB = glad_debug_impl_glDeleteProgramsARB;
    glad_debug_glDeleteProgramsNV = glad_debug_impl_glDeleteProgramsNV;
    glad_debug_glDeleteQueries = glad_debug_impl_glDeleteQueries;
    glad_debug_glDeleteQueriesARB = glad_debug_impl_glDeleteQueriesARB;
    glad_debug_glDeleteShader = glad_debug_impl_glDeleteShader;
    glad_debug_glDeleteTextures = glad_debug_impl_glDeleteTextures;
    glad_debug_glDeleteTexturesEXT = glad_debug_impl_glDeleteTexturesEXT;
    glad_debug_glDepthFunc = glad_debug_impl_glDepthFunc;
    glad_debug_glDepthMask = glad_debug_impl_glDepthMask;
    glad_debug_glDepthRange = glad_debug_impl_glDepthRange;
    glad_debug_glDetachObjectARB = glad_debug_impl_glDetachObjectARB;
    glad_debug_glDetachShader = glad_debug_impl_glDetachShader;
    glad_debug_glDisable = glad_debug_impl_glDisable;
    glad_debug_glDisableClientState = glad_debug_impl_glDisableClientState;
    glad_debug_glDisableVertexAttribArray = glad_debug_impl_glDisableVertexAttribArray;
    glad_debug_glDisableVertexAttribArrayARB = glad_debug_impl_glDisableVertexAttribArrayARB;
    glad_debug_glDrawArrays = glad_debug_impl_glDrawArrays;
    glad_debug_glDrawArraysEXT = glad_debug_impl_glDrawArraysEXT;
    glad_debug_glDrawBuffer = glad_debug_impl_glDrawBuffer;
    glad_debug_glDrawBuffers = glad_debug_impl_glDrawBuffers;
    glad_debug_glDrawBuffersARB = glad_debug_impl_glDrawBuffersARB;
    glad_debug_glDrawBuffersATI = glad_debug_impl_glDrawBuffersATI;
    glad_debug_glDrawElements = glad_debug_impl_glDrawElements;
    glad_debug_glDrawPixels = glad_debug_impl_glDrawPixels;
    glad_debug_glDrawRangeElements = glad_debug_impl_glDrawRangeElements;
    glad_debug_glDrawRangeElementsEXT = glad_debug_impl_glDrawRangeElementsEXT;
    glad_debug_glEdgeFlag = glad_debug_impl_glEdgeFlag;
    glad_debug_glEdgeFlagPointer = glad_debug_impl_glEdgeFlagPointer;
    glad_debug_glEdgeFlagPointerEXT = glad_debug_impl_glEdgeFlagPointerEXT;
    glad_debug_glEdgeFlagv = glad_debug_impl_glEdgeFlagv;
    glad_debug_glEnable = glad_debug_impl_glEnable;
    glad_debug_glEnableClientState = glad_debug_impl_glEnableClientState;
    glad_debug_glEnableVertexAttribArray = glad_debug_impl_glEnableVertexAttribArray;
    glad_debug_glEnableVertexAttribArrayARB = glad_debug_impl_glEnableVertexAttribArrayARB;
    glad_debug_glEnd = glad_debug_impl_glEnd;
    glad_debug_glEndList = glad_debug_impl_glEndList;
    glad_debug_glEndQuery = glad_debug_impl_glEndQuery;
    glad_debug_glEndQueryARB = glad_debug_impl_glEndQueryARB;
    glad_debug_glEvalCoord1d = glad_debug_impl_glEvalCoord1d;
    glad_debug_glEvalCoord1dv = glad_debug_impl_glEvalCoord1dv;
    glad_debug_glEvalCoord1f = glad_debug_impl_glEvalCoord1f;
    glad_debug_glEvalCoord1fv = glad_debug_impl_glEvalCoord1fv;
    glad_debug_glEvalCoord2d = glad_debug_impl_glEvalCoord2d;
    glad_debug_glEvalCoord2dv = glad_debug_impl_glEvalCoord2dv;
    glad_debug_glEvalCoord2f = glad_debug_impl_glEvalCoord2f;
    glad_debug_glEvalCoord2fv = glad_debug_impl_glEvalCoord2fv;
    glad_debug_glEvalMesh1 = glad_debug_impl_glEvalMesh1;
    glad_debug_glEvalMesh2 = glad_debug_impl_glEvalMesh2;
    glad_debug_glEvalPoint1 = glad_debug_impl_glEvalPoint1;
    glad_debug_glEvalPoint2 = glad_debug_impl_glEvalPoint2;
    glad_debug_glExecuteProgramNV = glad_debug_impl_glExecuteProgramNV;
    glad_debug_glFeedbackBuffer = glad_debug_impl_glFeedbackBuffer;
    glad_debug_glFinish = glad_debug_impl_glFinish;
    glad_debug_glFlush = glad_debug_impl_glFlush;
    glad_debug_glFogCoordPointer = glad_debug_impl_glFogCoordPointer;
    glad_debug_glFogCoordPointerEXT = glad_debug_impl_glFogCoordPointerEXT;
    glad_debug_glFogCoordd = glad_debug_impl_glFogCoordd;
    glad_debug_glFogCoorddEXT = glad_debug_impl_glFogCoorddEXT;
    glad_debug_glFogCoorddv = glad_debug_impl_glFogCoorddv;
    glad_debug_glFogCoorddvEXT = glad_debug_impl_glFogCoorddvEXT;
    glad_debug_glFogCoordf = glad_debug_impl_glFogCoordf;
    glad_debug_glFogCoordfEXT = glad_debug_impl_glFogCoordfEXT;
    glad_debug_glFogCoordfv = glad_debug_impl_glFogCoordfv;
    glad_debug_glFogCoordfvEXT = glad_debug_impl_glFogCoordfvEXT;
    glad_debug_glFogf = glad_debug_impl_glFogf;
    glad_debug_glFogfv = glad_debug_impl_glFogfv;
    glad_debug_glFogi = glad_debug_impl_glFogi;
    glad_debug_glFogiv = glad_debug_impl_glFogiv;
    glad_debug_glFrontFace = glad_debug_impl_glFrontFace;
    glad_debug_glFrustum = glad_debug_impl_glFrustum;
    glad_debug_glGenBuffers = glad_debug_impl_glGenBuffers;
    glad_debug_glGenBuffersARB = glad_debug_impl_glGenBuffersARB;
    glad_debug_glGenLists = glad_debug_impl_glGenLists;
    glad_debug_glGenProgramsARB = glad_debug_impl_glGenProgramsARB;
    glad_debug_glGenProgramsNV = glad_debug_impl_glGenProgramsNV;
    glad_debug_glGenQueries = glad_debug_impl_glGenQueries;
    glad_debug_glGenQueriesARB = glad_debug_impl_glGenQueriesARB;
    glad_debug_glGenTextures = glad_debug_impl_glGenTextures;
    glad_debug_glGenTexturesEXT = glad_debug_impl_glGenTexturesEXT;
    glad_debug_glGetActiveAttrib = glad_debug_impl_glGetActiveAttrib;
    glad_debug_glGetActiveAttribARB = glad_debug_impl_glGetActiveAttribARB;
    glad_debug_glGetActiveUniform = glad_debug_impl_glGetActiveUniform;
    glad_debug_glGetActiveUniformARB = glad_debug_impl_glGetActiveUniformARB;
    glad_debug_glGetAttachedObjectsARB = glad_debug_impl_glGetAttachedObjectsARB;
    glad_debug_glGetAttachedShaders = glad_debug_impl_glGetAttachedShaders;
    glad_debug_glGetAttribLocation = glad_debug_impl_glGetAttribLocation;
    glad_debug_glGetAttribLocationARB = glad_debug_impl_glGetAttribLocationARB;
    glad_debug_glGetBooleanv = glad_debug_impl_glGetBooleanv;
    glad_debug_glGetBufferParameteriv = glad_debug_impl_glGetBufferParameteriv;
    glad_debug_glGetBufferParameterivARB = glad_debug_impl_glGetBufferParameterivARB;
    glad_debug_glGetBufferPointerv = glad_debug_impl_glGetBufferPointerv;
    glad_debug_glGetBufferPointervARB = glad_debug_impl_glGetBufferPointervARB;
    glad_debug_glGetBufferSubData = glad_debug_impl_glGetBufferSubData;
    glad_debug_glGetBufferSubDataARB = glad_debug_impl_glGetBufferSubDataARB;
    glad_debug_glGetClipPlane = glad_debug_impl_glGetClipPlane;
    glad_debug_glGetColorTable = glad_debug_impl_glGetColorTable;
    glad_debug_glGetColorTableParameterfv = glad_debug_impl_glGetColorTableParameterfv;
    glad_debug_glGetColorTableParameteriv = glad_debug_impl_glGetColorTableParameteriv;
    glad_debug_glGetCompressedTexImage = glad_debug_impl_glGetCompressedTexImage;
    glad_debug_glGetCompressedTexImageARB = glad_debug_impl_glGetCompressedTexImageARB;
    glad_debug_glGetConvolutionFilter = glad_debug_impl_glGetConvolutionFilter;
    glad_debug_glGetConvolutionParameterfv = glad_debug_impl_glGetConvolutionParameterfv;
    glad_debug_glGetConvolutionParameteriv = glad_debug_impl_glGetConvolutionParameteriv;
    glad_debug_glGetDebugMessageLog = glad_debug_impl_glGetDebugMessageLog;
    glad_debug_glGetDoublev = glad_debug_impl_glGetDoublev;
    glad_debug_glGetError = glad_debug_impl_glGetError;
    glad_debug_glGetFloatv = glad_debug_impl_glGetFloatv;
    glad_debug_glGetHandleARB = glad_debug_impl_glGetHandleARB;
    glad_debug_glGetHistogram = glad_debug_impl_glGetHistogram;
    glad_debug_glGetHistogramParameterfv = glad_debug_impl_glGetHistogramParameterfv;
    glad_debug_glGetHistogramParameteriv = glad_debug_impl_glGetHistogramParameteriv;
    glad_debug_glGetInfoLogARB = glad_debug_impl_glGetInfoLogARB;
    glad_debug_glGetIntegerv = glad_debug_impl_glGetIntegerv;
    glad_debug_glGetLightfv = glad_debug_impl_glGetLightfv;
    glad_debug_glGetLightiv = glad_debug_impl_glGetLightiv;
    glad_debug_glGetMapdv = glad_debug_impl_glGetMapdv;
    glad_debug_glGetMapfv = glad_debug_impl_glGetMapfv;
    glad_debug_glGetMapiv = glad_debug_impl_glGetMapiv;
    glad_debug_glGetMaterialfv = glad_debug_impl_glGetMaterialfv;
    glad_debug_glGetMaterialiv = glad_debug_impl_glGetMaterialiv;
    glad_debug_glGetMinmax = glad_debug_impl_glGetMinmax;
    glad_debug_glGetMinmaxParameterfv = glad_debug_impl_glGetMinmaxParameterfv;
    glad_debug_glGetMinmaxParameteriv = glad_debug_impl_glGetMinmaxParameteriv;
    glad_debug_glGetObjectLabel = glad_debug_impl_glGetObjectLabel;
    glad_debug_glGetObjectParameterfvARB = glad_debug_impl_glGetObjectParameterfvARB;
    glad_debug_glGetObjectParameterivARB = glad_debug_impl_glGetObjectParameterivARB;
    glad_debug_glGetObjectPtrLabel = glad_debug_impl_glGetObjectPtrLabel;
    glad_debug_glGetPixelMapfv = glad_debug_impl_glGetPixelMapfv;
    glad_debug_glGetPixelMapuiv = glad_debug_impl_glGetPixelMapuiv;
    glad_debug_glGetPixelMapusv = glad_debug_impl_glGetPixelMapusv;
    glad_debug_glGetPointerv = glad_debug_impl_glGetPointerv;
    glad_debug_glGetPointervEXT = glad_debug_impl_glGetPointervEXT;
    glad_debug_glGetPolygonStipple = glad_debug_impl_glGetPolygonStipple;
    glad_debug_glGetProgramEnvParameterdvARB = glad_debug_impl_glGetProgramEnvParameterdvARB;
    glad_debug_glGetProgramEnvParameterfvARB = glad_debug_impl_glGetProgramEnvParameterfvARB;
    glad_debug_glGetProgramInfoLog = glad_debug_impl_glGetProgramInfoLog;
    glad_debug_glGetProgramLocalParameterdvARB = glad_debug_impl_glGetProgramLocalParameterdvARB;
    glad_debug_glGetProgramLocalParameterfvARB = glad_debug_impl_glGetProgramLocalParameterfvARB;
    glad_debug_glGetProgramParameterdvNV = glad_debug_impl_glGetProgramParameterdvNV;
    glad_debug_glGetProgramParameterfvNV = glad_debug_impl_glGetProgramParameterfvNV;
    glad_debug_glGetProgramStringARB = glad_debug_impl_glGetProgramStringARB;
    glad_debug_glGetProgramStringNV = glad_debug_impl_glGetProgramStringNV;
    glad_debug_glGetProgramiv = glad_debug_impl_glGetProgramiv;
    glad_debug_glGetProgramivARB = glad_debug_impl_glGetProgramivARB;
    glad_debug_glGetProgramivNV = glad_debug_impl_glGetProgramivNV;
    glad_debug_glGetQueryObjectiv = glad_debug_impl_glGetQueryObjectiv;
    glad_debug_glGetQueryObjectivARB = glad_debug_impl_glGetQueryObjectivARB;
    glad_debug_glGetQueryObjectuiv = glad_debug_impl_glGetQueryObjectuiv;
    glad_debug_glGetQueryObjectuivARB = glad_debug_impl_glGetQueryObjectuivARB;
    glad_debug_glGetQueryiv = glad_debug_impl_glGetQueryiv;
    glad_debug_glGetQueryivARB = glad_debug_impl_glGetQueryivARB;
    glad_debug_glGetSeparableFilter = glad_debug_impl_glGetSeparableFilter;
    glad_debug_glGetShaderInfoLog = glad_debug_impl_glGetShaderInfoLog;
    glad_debug_glGetShaderSource = glad_debug_impl_glGetShaderSource;
    glad_debug_glGetShaderSourceARB = glad_debug_impl_glGetShaderSourceARB;
    glad_debug_glGetShaderiv = glad_debug_impl_glGetShaderiv;
    glad_debug_glGetString = glad_debug_impl_glGetString;
    glad_debug_glGetTexEnvfv = glad_debug_impl_glGetTexEnvfv;
    glad_debug_glGetTexEnviv = glad_debug_impl_glGetTexEnviv;
    glad_debug_glGetTexGendv = glad_debug_impl_glGetTexGendv;
    glad_debug_glGetTexGenfv = glad_debug_impl_glGetTexGenfv;
    glad_debug_glGetTexGeniv = glad_debug_impl_glGetTexGeniv;
    glad_debug_glGetTexImage = glad_debug_impl_glGetTexImage;
    glad_debug_glGetTexLevelParameterfv = glad_debug_impl_glGetTexLevelParameterfv;
    glad_debug_glGetTexLevelParameteriv = glad_debug_impl_glGetTexLevelParameteriv;
    glad_debug_glGetTexParameterfv = glad_debug_impl_glGetTexParameterfv;
    glad_debug_glGetTexParameteriv = glad_debug_impl_glGetTexParameteriv;
    glad_debug_glGetTrackMatrixivNV = glad_debug_impl_glGetTrackMatrixivNV;
    glad_debug_glGetUniformLocation = glad_debug_impl_glGetUniformLocation;
    glad_debug_glGetUniformLocationARB = glad_debug_impl_glGetUniformLocationARB;
    glad_debug_glGetUniformfv = glad_debug_impl_glGetUniformfv;
    glad_debug_glGetUniformfvARB = glad_debug_impl_glGetUniformfvARB;
    glad_debug_glGetUniformiv = glad_debug_impl_glGetUniformiv;
    glad_debug_glGetUniformivARB = glad_debug_impl_glGetUniformivARB;
    glad_debug_glGetVertexAttribPointerv = glad_debug_impl_glGetVertexAttribPointerv;
    glad_debug_glGetVertexAttribPointervARB = glad_debug_impl_glGetVertexAttribPointervARB;
    glad_debug_glGetVertexAttribPointervNV = glad_debug_impl_glGetVertexAttribPointervNV;
    glad_debug_glGetVertexAttribdv = glad_debug_impl_glGetVertexAttribdv;
    glad_debug_glGetVertexAttribdvARB = glad_debug_impl_glGetVertexAttribdvARB;
    glad_debug_glGetVertexAttribdvNV = glad_debug_impl_glGetVertexAttribdvNV;
    glad_debug_glGetVertexAttribfv = glad_debug_impl_glGetVertexAttribfv;
    glad_debug_glGetVertexAttribfvARB = glad_debug_impl_glGetVertexAttribfvARB;
    glad_debug_glGetVertexAttribfvNV = glad_debug_impl_glGetVertexAttribfvNV;
    glad_debug_glGetVertexAttribiv = glad_debug_impl_glGetVertexAttribiv;
    glad_debug_glGetVertexAttribivARB = glad_debug_impl_glGetVertexAttribivARB;
    glad_debug_glGetVertexAttribivNV = glad_debug_impl_glGetVertexAttribivNV;
    glad_debug_glHint = glad_debug_impl_glHint;
    glad_debug_glHistogram = glad_debug_impl_glHistogram;
    glad_debug_glIndexMask = glad_debug_impl_glIndexMask;
    glad_debug_glIndexPointer = glad_debug_impl_glIndexPointer;
    glad_debug_glIndexPointerEXT = glad_debug_impl_glIndexPointerEXT;
    glad_debug_glIndexd = glad_debug_impl_glIndexd;
    glad_debug_glIndexdv = glad_debug_impl_glIndexdv;
    glad_debug_glIndexf = glad_debug_impl_glIndexf;
    glad_debug_glIndexfv = glad_debug_impl_glIndexfv;
    glad_debug_glIndexi = glad_debug_impl_glIndexi;
    glad_debug_glIndexiv = glad_debug_impl_glIndexiv;
    glad_debug_glIndexs = glad_debug_impl_glIndexs;
    glad_debug_glIndexsv = glad_debug_impl_glIndexsv;
    glad_debug_glIndexub = glad_debug_impl_glIndexub;
    glad_debug_glIndexubv = glad_debug_impl_glIndexubv;
    glad_debug_glInitNames = glad_debug_impl_glInitNames;
    glad_debug_glInterleavedArrays = glad_debug_impl_glInterleavedArrays;
    glad_debug_glIsBuffer = glad_debug_impl_glIsBuffer;
    glad_debug_glIsBufferARB = glad_debug_impl_glIsBufferARB;
    glad_debug_glIsEnabled = glad_debug_impl_glIsEnabled;
    glad_debug_glIsList = glad_debug_impl_glIsList;
    glad_debug_glIsProgram = glad_debug_impl_glIsProgram;
    glad_debug_glIsProgramARB = glad_debug_impl_glIsProgramARB;
    glad_debug_glIsProgramNV = glad_debug_impl_glIsProgramNV;
    glad_debug_glIsQuery = glad_debug_impl_glIsQuery;
    glad_debug_glIsQueryARB = glad_debug_impl_glIsQueryARB;
    glad_debug_glIsShader = glad_debug_impl_glIsShader;
    glad_debug_glIsTexture = glad_debug_impl_glIsTexture;
    glad_debug_glIsTextureEXT = glad_debug_impl_glIsTextureEXT;
    glad_debug_glLightModelf = glad_debug_impl_glLightModelf;
    glad_debug_glLightModelfv = glad_debug_impl_glLightModelfv;
    glad_debug_glLightModeli = glad_debug_impl_glLightModeli;
    glad_debug_glLightModeliv = glad_debug_impl_glLightModeliv;
    glad_debug_glLightf = glad_debug_impl_glLightf;
    glad_debug_glLightfv = glad_debug_impl_glLightfv;
    glad_debug_glLighti = glad_debug_impl_glLighti;
    glad_debug_glLightiv = glad_debug_impl_glLightiv;
    glad_debug_glLineStipple = glad_debug_impl_glLineStipple;
    glad_debug_glLineWidth = glad_debug_impl_glLineWidth;
    glad_debug_glLinkProgram = glad_debug_impl_glLinkProgram;
    glad_debug_glLinkProgramARB = glad_debug_impl_glLinkProgramARB;
    glad_debug_glListBase = glad_debug_impl_glListBase;
    glad_debug_glLoadIdentity = glad_debug_impl_glLoadIdentity;
    glad_debug_glLoadMatrixd = glad_debug_impl_glLoadMatrixd;
    glad_debug_glLoadMatrixf = glad_debug_impl_glLoadMatrixf;
    glad_debug_glLoadName = glad_debug_impl_glLoadName;
    glad_debug_glLoadProgramNV = glad_debug_impl_glLoadProgramNV;
    glad_debug_glLoadTransposeMatrixd = glad_debug_impl_glLoadTransposeMatrixd;
    glad_debug_glLoadTransposeMatrixdARB = glad_debug_impl_glLoadTransposeMatrixdARB;
    glad_debug_glLoadTransposeMatrixf = glad_debug_impl_glLoadTransposeMatrixf;
    glad_debug_glLoadTransposeMatrixfARB = glad_debug_impl_glLoadTransposeMatrixfARB;
    glad_debug_glLogicOp = glad_debug_impl_glLogicOp;
    glad_debug_glMap1d = glad_debug_impl_glMap1d;
    glad_debug_glMap1f = glad_debug_impl_glMap1f;
    glad_debug_glMap2d = glad_debug_impl_glMap2d;
    glad_debug_glMap2f = glad_debug_impl_glMap2f;
    glad_debug_glMapBuffer = glad_debug_impl_glMapBuffer;
    glad_debug_glMapBufferARB = glad_debug_impl_glMapBufferARB;
    glad_debug_glMapGrid1d = glad_debug_impl_glMapGrid1d;
    glad_debug_glMapGrid1f = glad_debug_impl_glMapGrid1f;
    glad_debug_glMapGrid2d = glad_debug_impl_glMapGrid2d;
    glad_debug_glMapGrid2f = glad_debug_impl_glMapGrid2f;
    glad_debug_glMaterialf = glad_debug_impl_glMaterialf;
    glad_debug_glMaterialfv = glad_debug_impl_glMaterialfv;
    glad_debug_glMateriali = glad_debug_impl_glMateriali;
    glad_debug_glMaterialiv = glad_debug_impl_glMaterialiv;
    glad_debug_glMatrixMode = glad_debug_impl_glMatrixMode;
    glad_debug_glMinmax = glad_debug_impl_glMinmax;
    glad_debug_glMultMatrixd = glad_debug_impl_glMultMatrixd;
    glad_debug_glMultMatrixf = glad_debug_impl_glMultMatrixf;
    glad_debug_glMultTransposeMatrixd = glad_debug_impl_glMultTransposeMatrixd;
    glad_debug_glMultTransposeMatrixdARB = glad_debug_impl_glMultTransposeMatrixdARB;
    glad_debug_glMultTransposeMatrixf = glad_debug_impl_glMultTransposeMatrixf;
    glad_debug_glMultTransposeMatrixfARB = glad_debug_impl_glMultTransposeMatrixfARB;
    glad_debug_glMultiDrawArrays = glad_debug_impl_glMultiDrawArrays;
    glad_debug_glMultiDrawArraysEXT = glad_debug_impl_glMultiDrawArraysEXT;
    glad_debug_glMultiDrawElements = glad_debug_impl_glMultiDrawElements;
    glad_debug_glMultiDrawElementsEXT = glad_debug_impl_glMultiDrawElementsEXT;
    glad_debug_glMultiTexCoord1d = glad_debug_impl_glMultiTexCoord1d;
    glad_debug_glMultiTexCoord1dARB = glad_debug_impl_glMultiTexCoord1dARB;
    glad_debug_glMultiTexCoord1dv = glad_debug_impl_glMultiTexCoord1dv;
    glad_debug_glMultiTexCoord1dvARB = glad_debug_impl_glMultiTexCoord1dvARB;
    glad_debug_glMultiTexCoord1f = glad_debug_impl_glMultiTexCoord1f;
    glad_debug_glMultiTexCoord1fARB = glad_debug_impl_glMultiTexCoord1fARB;
    glad_debug_glMultiTexCoord1fv = glad_debug_impl_glMultiTexCoord1fv;
    glad_debug_glMultiTexCoord1fvARB = glad_debug_impl_glMultiTexCoord1fvARB;
    glad_debug_glMultiTexCoord1i = glad_debug_impl_glMultiTexCoord1i;
    glad_debug_glMultiTexCoord1iARB = glad_debug_impl_glMultiTexCoord1iARB;
    glad_debug_glMultiTexCoord1iv = glad_debug_impl_glMultiTexCoord1iv;
    glad_debug_glMultiTexCoord1ivARB = glad_debug_impl_glMultiTexCoord1ivARB;
    glad_debug_glMultiTexCoord1s = glad_debug_impl_glMultiTexCoord1s;
    glad_debug_glMultiTexCoord1sARB = glad_debug_impl_glMultiTexCoord1sARB;
    glad_debug_glMultiTexCoord1sv = glad_debug_impl_glMultiTexCoord1sv;
    glad_debug_glMultiTexCoord1svARB = glad_debug_impl_glMultiTexCoord1svARB;
    glad_debug_glMultiTexCoord2d = glad_debug_impl_glMultiTexCoord2d;
    glad_debug_glMultiTexCoord2dARB = glad_debug_impl_glMultiTexCoord2dARB;
    glad_debug_glMultiTexCoord2dv = glad_debug_impl_glMultiTexCoord2dv;
    glad_debug_glMultiTexCoord2dvARB = glad_debug_impl_glMultiTexCoord2dvARB;
    glad_debug_glMultiTexCoord2f = glad_debug_impl_glMultiTexCoord2f;
    glad_debug_glMultiTexCoord2fARB = glad_debug_impl_glMultiTexCoord2fARB;
    glad_debug_glMultiTexCoord2fv = glad_debug_impl_glMultiTexCoord2fv;
    glad_debug_glMultiTexCoord2fvARB = glad_debug_impl_glMultiTexCoord2fvARB;
    glad_debug_glMultiTexCoord2i = glad_debug_impl_glMultiTexCoord2i;
    glad_debug_glMultiTexCoord2iARB = glad_debug_impl_glMultiTexCoord2iARB;
    glad_debug_glMultiTexCoord2iv = glad_debug_impl_glMultiTexCoord2iv;
    glad_debug_glMultiTexCoord2ivARB = glad_debug_impl_glMultiTexCoord2ivARB;
    glad_debug_glMultiTexCoord2s = glad_debug_impl_glMultiTexCoord2s;
    glad_debug_glMultiTexCoord2sARB = glad_debug_impl_glMultiTexCoord2sARB;
    glad_debug_glMultiTexCoord2sv = glad_debug_impl_glMultiTexCoord2sv;
    glad_debug_glMultiTexCoord2svARB = glad_debug_impl_glMultiTexCoord2svARB;
    glad_debug_glMultiTexCoord3d = glad_debug_impl_glMultiTexCoord3d;
    glad_debug_glMultiTexCoord3dARB = glad_debug_impl_glMultiTexCoord3dARB;
    glad_debug_glMultiTexCoord3dv = glad_debug_impl_glMultiTexCoord3dv;
    glad_debug_glMultiTexCoord3dvARB = glad_debug_impl_glMultiTexCoord3dvARB;
    glad_debug_glMultiTexCoord3f = glad_debug_impl_glMultiTexCoord3f;
    glad_debug_glMultiTexCoord3fARB = glad_debug_impl_glMultiTexCoord3fARB;
    glad_debug_glMultiTexCoord3fv = glad_debug_impl_glMultiTexCoord3fv;
    glad_debug_glMultiTexCoord3fvARB = glad_debug_impl_glMultiTexCoord3fvARB;
    glad_debug_glMultiTexCoord3i = glad_debug_impl_glMultiTexCoord3i;
    glad_debug_glMultiTexCoord3iARB = glad_debug_impl_glMultiTexCoord3iARB;
    glad_debug_glMultiTexCoord3iv = glad_debug_impl_glMultiTexCoord3iv;
    glad_debug_glMultiTexCoord3ivARB = glad_debug_impl_glMultiTexCoord3ivARB;
    glad_debug_glMultiTexCoord3s = glad_debug_impl_glMultiTexCoord3s;
    glad_debug_glMultiTexCoord3sARB = glad_debug_impl_glMultiTexCoord3sARB;
    glad_debug_glMultiTexCoord3sv = glad_debug_impl_glMultiTexCoord3sv;
    glad_debug_glMultiTexCoord3svARB = glad_debug_impl_glMultiTexCoord3svARB;
    glad_debug_glMultiTexCoord4d = glad_debug_impl_glMultiTexCoord4d;
    glad_debug_glMultiTexCoord4dARB = glad_debug_impl_glMultiTexCoord4dARB;
    glad_debug_glMultiTexCoord4dv = glad_debug_impl_glMultiTexCoord4dv;
    glad_debug_glMultiTexCoord4dvARB = glad_debug_impl_glMultiTexCoord4dvARB;
    glad_debug_glMultiTexCoord4f = glad_debug_impl_glMultiTexCoord4f;
    glad_debug_glMultiTexCoord4fARB = glad_debug_impl_glMultiTexCoord4fARB;
    glad_debug_glMultiTexCoord4fv = glad_debug_impl_glMultiTexCoord4fv;
    glad_debug_glMultiTexCoord4fvARB = glad_debug_impl_glMultiTexCoord4fvARB;
    glad_debug_glMultiTexCoord4i = glad_debug_impl_glMultiTexCoord4i;
    glad_debug_glMultiTexCoord4iARB = glad_debug_impl_glMultiTexCoord4iARB;
    glad_debug_glMultiTexCoord4iv = glad_debug_impl_glMultiTexCoord4iv;
    glad_debug_glMultiTexCoord4ivARB = glad_debug_impl_glMultiTexCoord4ivARB;
    glad_debug_glMultiTexCoord4s = glad_debug_impl_glMultiTexCoord4s;
    glad_debug_glMultiTexCoord4sARB = glad_debug_impl_glMultiTexCoord4sARB;
    glad_debug_glMultiTexCoord4sv = glad_debug_impl_glMultiTexCoord4sv;
    glad_debug_glMultiTexCoord4svARB = glad_debug_impl_glMultiTexCoord4svARB;
    glad_debug_glNewList = glad_debug_impl_glNewList;
    glad_debug_glNormal3b = glad_debug_impl_glNormal3b;
    glad_debug_glNormal3bv = glad_debug_impl_glNormal3bv;
    glad_debug_glNormal3d = glad_debug_impl_glNormal3d;
    glad_debug_glNormal3dv = glad_debug_impl_glNormal3dv;
    glad_debug_glNormal3f = glad_debug_impl_glNormal3f;
    glad_debug_glNormal3fv = glad_debug_impl_glNormal3fv;
    glad_debug_glNormal3i = glad_debug_impl_glNormal3i;
    glad_debug_glNormal3iv = glad_debug_impl_glNormal3iv;
    glad_debug_glNormal3s = glad_debug_impl_glNormal3s;
    glad_debug_glNormal3sv = glad_debug_impl_glNormal3sv;
    glad_debug_glNormalPointer = glad_debug_impl_glNormalPointer;
    glad_debug_glNormalPointerEXT = glad_debug_impl_glNormalPointerEXT;
    glad_debug_glObjectLabel = glad_debug_impl_glObjectLabel;
    glad_debug_glObjectPtrLabel = glad_debug_impl_glObjectPtrLabel;
    glad_debug_glOrtho = glad_debug_impl_glOrtho;
    glad_debug_glPassThrough = glad_debug_impl_glPassThrough;
    glad_debug_glPixelMapfv = glad_debug_impl_glPixelMapfv;
    glad_debug_glPixelMapuiv = glad_debug_impl_glPixelMapuiv;
    glad_debug_glPixelMapusv = glad_debug_impl_glPixelMapusv;
    glad_debug_glPixelStoref = glad_debug_impl_glPixelStoref;
    glad_debug_glPixelStorei = glad_debug_impl_glPixelStorei;
    glad_debug_glPixelTransferf = glad_debug_impl_glPixelTransferf;
    glad_debug_glPixelTransferi = glad_debug_impl_glPixelTransferi;
    glad_debug_glPixelZoom = glad_debug_impl_glPixelZoom;
    glad_debug_glPointParameterf = glad_debug_impl_glPointParameterf;
    glad_debug_glPointParameterfARB = glad_debug_impl_glPointParameterfARB;
    glad_debug_glPointParameterfEXT = glad_debug_impl_glPointParameterfEXT;
    glad_debug_glPointParameterfSGIS = glad_debug_impl_glPointParameterfSGIS;
    glad_debug_glPointParameterfv = glad_debug_impl_glPointParameterfv;
    glad_debug_glPointParameterfvARB = glad_debug_impl_glPointParameterfvARB;
    glad_debug_glPointParameterfvEXT = glad_debug_impl_glPointParameterfvEXT;
    glad_debug_glPointParameterfvSGIS = glad_debug_impl_glPointParameterfvSGIS;
    glad_debug_glPointParameteri = glad_debug_impl_glPointParameteri;
    glad_debug_glPointParameteriNV = glad_debug_impl_glPointParameteriNV;
    glad_debug_glPointParameteriv = glad_debug_impl_glPointParameteriv;
    glad_debug_glPointParameterivNV = glad_debug_impl_glPointParameterivNV;
    glad_debug_glPointSize = glad_debug_impl_glPointSize;
    glad_debug_glPolygonMode = glad_debug_impl_glPolygonMode;
    glad_debug_glPolygonOffset = glad_debug_impl_glPolygonOffset;
    glad_debug_glPolygonStipple = glad_debug_impl_glPolygonStipple;
    glad_debug_glPopAttrib = glad_debug_impl_glPopAttrib;
    glad_debug_glPopClientAttrib = glad_debug_impl_glPopClientAttrib;
    glad_debug_glPopDebugGroup = glad_debug_impl_glPopDebugGroup;
    glad_debug_glPopMatrix = glad_debug_impl_glPopMatrix;
    glad_debug_glPopName = glad_debug_impl_glPopName;
    glad_debug_glPrioritizeTextures = glad_debug_impl_glPrioritizeTextures;
    glad_debug_glPrioritizeTexturesEXT = glad_debug_impl_glPrioritizeTexturesEXT;
    glad_debug_glProgramEnvParameter4dARB = glad_debug_impl_glProgramEnvParameter4dARB;
    glad_debug_glProgramEnvParameter4dvARB = glad_debug_impl_glProgramEnvParameter4dvARB;
    glad_debug_glProgramEnvParameter4fARB = glad_debug_impl_glProgramEnvParameter4fARB;
    glad_debug_glProgramEnvParameter4fvARB = glad_debug_impl_glProgramEnvParameter4fvARB;
    glad_debug_glProgramLocalParameter4dARB = glad_debug_impl_glProgramLocalParameter4dARB;
    glad_debug_glProgramLocalParameter4dvARB = glad_debug_impl_glProgramLocalParameter4dvARB;
    glad_debug_glProgramLocalParameter4fARB = glad_debug_impl_glProgramLocalParameter4fARB;
    glad_debug_glProgramLocalParameter4fvARB = glad_debug_impl_glProgramLocalParameter4fvARB;
    glad_debug_glProgramParameter4dNV = glad_debug_impl_glProgramParameter4dNV;
    glad_debug_glProgramParameter4dvNV = glad_debug_impl_glProgramParameter4dvNV;
    glad_debug_glProgramParameter4fNV = glad_debug_impl_glProgramParameter4fNV;
    glad_debug_glProgramParameter4fvNV = glad_debug_impl_glProgramParameter4fvNV;
    glad_debug_glProgramParameters4dvNV = glad_debug_impl_glProgramParameters4dvNV;
    glad_debug_glProgramParameters4fvNV = glad_debug_impl_glProgramParameters4fvNV;
    glad_debug_glProgramStringARB = glad_debug_impl_glProgramStringARB;
    glad_debug_glPushAttrib = glad_debug_impl_glPushAttrib;
    glad_debug_glPushClientAttrib = glad_debug_impl_glPushClientAttrib;
    glad_debug_glPushDebugGroup = glad_debug_impl_glPushDebugGroup;
    glad_debug_glPushMatrix = glad_debug_impl_glPushMatrix;
    glad_debug_glPushName = glad_debug_impl_glPushName;
    glad_debug_glRasterPos2d = glad_debug_impl_glRasterPos2d;
    glad_debug_glRasterPos2dv = glad_debug_impl_glRasterPos2dv;
    glad_debug_glRasterPos2f = glad_debug_impl_glRasterPos2f;
    glad_debug_glRasterPos2fv = glad_debug_impl_glRasterPos2fv;
    glad_debug_glRasterPos2i = glad_debug_impl_glRasterPos2i;
    glad_debug_glRasterPos2iv = glad_debug_impl_glRasterPos2iv;
    glad_debug_glRasterPos2s = glad_debug_impl_glRasterPos2s;
    glad_debug_glRasterPos2sv = glad_debug_impl_glRasterPos2sv;
    glad_debug_glRasterPos3d = glad_debug_impl_glRasterPos3d;
    glad_debug_glRasterPos3dv = glad_debug_impl_glRasterPos3dv;
    glad_debug_glRasterPos3f = glad_debug_impl_glRasterPos3f;
    glad_debug_glRasterPos3fv = glad_debug_impl_glRasterPos3fv;
    glad_debug_glRasterPos3i = glad_debug_impl_glRasterPos3i;
    glad_debug_glRasterPos3iv = glad_debug_impl_glRasterPos3iv;
    glad_debug_glRasterPos3s = glad_debug_impl_glRasterPos3s;
    glad_debug_glRasterPos3sv = glad_debug_impl_glRasterPos3sv;
    glad_debug_glRasterPos4d = glad_debug_impl_glRasterPos4d;
    glad_debug_glRasterPos4dv = glad_debug_impl_glRasterPos4dv;
    glad_debug_glRasterPos4f = glad_debug_impl_glRasterPos4f;
    glad_debug_glRasterPos4fv = glad_debug_impl_glRasterPos4fv;
    glad_debug_glRasterPos4i = glad_debug_impl_glRasterPos4i;
    glad_debug_glRasterPos4iv = glad_debug_impl_glRasterPos4iv;
    glad_debug_glRasterPos4s = glad_debug_impl_glRasterPos4s;
    glad_debug_glRasterPos4sv = glad_debug_impl_glRasterPos4sv;
    glad_debug_glReadBuffer = glad_debug_impl_glReadBuffer;
    glad_debug_glReadPixels = glad_debug_impl_glReadPixels;
    glad_debug_glRectd = glad_debug_impl_glRectd;
    glad_debug_glRectdv = glad_debug_impl_glRectdv;
    glad_debug_glRectf = glad_debug_impl_glRectf;
    glad_debug_glRectfv = glad_debug_impl_glRectfv;
    glad_debug_glRecti = glad_debug_impl_glRecti;
    glad_debug_glRectiv = glad_debug_impl_glRectiv;
    glad_debug_glRects = glad_debug_impl_glRects;
    glad_debug_glRectsv = glad_debug_impl_glRectsv;
    glad_debug_glRenderMode = glad_debug_impl_glRenderMode;
    glad_debug_glRequestResidentProgramsNV = glad_debug_impl_glRequestResidentProgramsNV;
    glad_debug_glResetHistogram = glad_debug_impl_glResetHistogram;
    glad_debug_glResetMinmax = glad_debug_impl_glResetMinmax;
    glad_debug_glRotated = glad_debug_impl_glRotated;
    glad_debug_glRotatef = glad_debug_impl_glRotatef;
    glad_debug_glSampleCoverage = glad_debug_impl_glSampleCoverage;
    glad_debug_glSampleCoverageARB = glad_debug_impl_glSampleCoverageARB;
    glad_debug_glScaled = glad_debug_impl_glScaled;
    glad_debug_glScalef = glad_debug_impl_glScalef;
    glad_debug_glScissor = glad_debug_impl_glScissor;
    glad_debug_glSecondaryColor3b = glad_debug_impl_glSecondaryColor3b;
    glad_debug_glSecondaryColor3bEXT = glad_debug_impl_glSecondaryColor3bEXT;
    glad_debug_glSecondaryColor3bv = glad_debug_impl_glSecondaryColor3bv;
    glad_debug_glSecondaryColor3bvEXT = glad_debug_impl_glSecondaryColor3bvEXT;
    glad_debug_glSecondaryColor3d = glad_debug_impl_glSecondaryColor3d;
    glad_debug_glSecondaryColor3dEXT = glad_debug_impl_glSecondaryColor3dEXT;
    glad_debug_glSecondaryColor3dv = glad_debug_impl_glSecondaryColor3dv;
    glad_debug_glSecondaryColor3dvEXT = glad_debug_impl_glSecondaryColor3dvEXT;
    glad_debug_glSecondaryColor3f = glad_debug_impl_glSecondaryColor3f;
    glad_debug_glSecondaryColor3fEXT = glad_debug_impl_glSecondaryColor3fEXT;
    glad_debug_glSecondaryColor3fv = glad_debug_impl_glSecondaryColor3fv;
    glad_debug_glSecondaryColor3fvEXT = glad_debug_impl_glSecondaryColor3fvEXT;
    glad_debug_glSecondaryColor3i = glad_debug_impl_glSecondaryColor3i;
    glad_debug_glSecondaryColor3iEXT = glad_debug_impl_glSecondaryColor3iEXT;
    glad_debug_glSecondaryColor3iv = glad_debug_impl_glSecondaryColor3iv;
    glad_debug_glSecondaryColor3ivEXT = glad_debug_impl_glSecondaryColor3ivEXT;
    glad_debug_glSecondaryColor3s = glad_debug_impl_glSecondaryColor3s;
    glad_debug_glSecondaryColor3sEXT = glad_debug_impl_glSecondaryColor3sEXT;
    glad_debug_glSecondaryColor3sv = glad_debug_impl_glSecondaryColor3sv;
    glad_debug_glSecondaryColor3svEXT = glad_debug_impl_glSecondaryColor3svEXT;
    glad_debug_glSecondaryColor3ub = glad_debug_impl_glSecondaryColor3ub;
    glad_debug_glSecondaryColor3ubEXT = glad_debug_impl_glSecondaryColor3ubEXT;
    glad_debug_glSecondaryColor3ubv = glad_debug_impl_glSecondaryColor3ubv;
    glad_debug_glSecondaryColor3ubvEXT = glad_debug_impl_glSecondaryColor3ubvEXT;
    glad_debug_glSecondaryColor3ui = glad_debug_impl_glSecondaryColor3ui;
    glad_debug_glSecondaryColor3uiEXT = glad_debug_impl_glSecondaryColor3uiEXT;
    glad_debug_glSecondaryColor3uiv = glad_debug_impl_glSecondaryColor3uiv;
    glad_debug_glSecondaryColor3uivEXT = glad_debug_impl_glSecondaryColor3uivEXT;
    glad_debug_glSecondaryColor3us = glad_debug_impl_glSecondaryColor3us;
    glad_debug_glSecondaryColor3usEXT = glad_debug_impl_glSecondaryColor3usEXT;
    glad_debug_glSecondaryColor3usv = glad_debug_impl_glSecondaryColor3usv;
    glad_debug_glSecondaryColor3usvEXT = glad_debug_impl_glSecondaryColor3usvEXT;
    glad_debug_glSecondaryColorPointer = glad_debug_impl_glSecondaryColorPointer;
    glad_debug_glSecondaryColorPointerEXT = glad_debug_impl_glSecondaryColorPointerEXT;
    glad_debug_glSelectBuffer = glad_debug_impl_glSelectBuffer;
    glad_debug_glSeparableFilter2D = glad_debug_impl_glSeparableFilter2D;
    glad_debug_glShadeModel = glad_debug_impl_glShadeModel;
    glad_debug_glShaderSource = glad_debug_impl_glShaderSource;
    glad_debug_glShaderSourceARB = glad_debug_impl_glShaderSourceARB;
    glad_debug_glStencilFunc = glad_debug_impl_glStencilFunc;
    glad_debug_glStencilFuncSeparate = glad_debug_impl_glStencilFuncSeparate;
    glad_debug_glStencilFuncSeparateATI = glad_debug_impl_glStencilFuncSeparateATI;
    glad_debug_glStencilMask = glad_debug_impl_glStencilMask;
    glad_debug_glStencilMaskSeparate = glad_debug_impl_glStencilMaskSeparate;
    glad_debug_glStencilOp = glad_debug_impl_glStencilOp;
    glad_debug_glStencilOpSeparate = glad_debug_impl_glStencilOpSeparate;
    glad_debug_glStencilOpSeparateATI = glad_debug_impl_glStencilOpSeparateATI;
    glad_debug_glTexCoord1d = glad_debug_impl_glTexCoord1d;
    glad_debug_glTexCoord1dv = glad_debug_impl_glTexCoord1dv;
    glad_debug_glTexCoord1f = glad_debug_impl_glTexCoord1f;
    glad_debug_glTexCoord1fv = glad_debug_impl_glTexCoord1fv;
    glad_debug_glTexCoord1i = glad_debug_impl_glTexCoord1i;
    glad_debug_glTexCoord1iv = glad_debug_impl_glTexCoord1iv;
    glad_debug_glTexCoord1s = glad_debug_impl_glTexCoord1s;
    glad_debug_glTexCoord1sv = glad_debug_impl_glTexCoord1sv;
    glad_debug_glTexCoord2d = glad_debug_impl_glTexCoord2d;
    glad_debug_glTexCoord2dv = glad_debug_impl_glTexCoord2dv;
    glad_debug_glTexCoord2f = glad_debug_impl_glTexCoord2f;
    glad_debug_glTexCoord2fv = glad_debug_impl_glTexCoord2fv;
    glad_debug_glTexCoord2i = glad_debug_impl_glTexCoord2i;
    glad_debug_glTexCoord2iv = glad_debug_impl_glTexCoord2iv;
    glad_debug_glTexCoord2s = glad_debug_impl_glTexCoord2s;
    glad_debug_glTexCoord2sv = glad_debug_impl_glTexCoord2sv;
    glad_debug_glTexCoord3d = glad_debug_impl_glTexCoord3d;
    glad_debug_glTexCoord3dv = glad_debug_impl_glTexCoord3dv;
    glad_debug_glTexCoord3f = glad_debug_impl_glTexCoord3f;
    glad_debug_glTexCoord3fv = glad_debug_impl_glTexCoord3fv;
    glad_debug_glTexCoord3i = glad_debug_impl_glTexCoord3i;
    glad_debug_glTexCoord3iv = glad_debug_impl_glTexCoord3iv;
    glad_debug_glTexCoord3s = glad_debug_impl_glTexCoord3s;
    glad_debug_glTexCoord3sv = glad_debug_impl_glTexCoord3sv;
    glad_debug_glTexCoord4d = glad_debug_impl_glTexCoord4d;
    glad_debug_glTexCoord4dv = glad_debug_impl_glTexCoord4dv;
    glad_debug_glTexCoord4f = glad_debug_impl_glTexCoord4f;
    glad_debug_glTexCoord4fv = glad_debug_impl_glTexCoord4fv;
    glad_debug_glTexCoord4i = glad_debug_impl_glTexCoord4i;
    glad_debug_glTexCoord4iv = glad_debug_impl_glTexCoord4iv;
    glad_debug_glTexCoord4s = glad_debug_impl_glTexCoord4s;
    glad_debug_glTexCoord4sv = glad_debug_impl_glTexCoord4sv;
    glad_debug_glTexCoordPointer = glad_debug_impl_glTexCoordPointer;
    glad_debug_glTexCoordPointerEXT = glad_debug_impl_glTexCoordPointerEXT;
    glad_debug_glTexEnvf = glad_debug_impl_glTexEnvf;
    glad_debug_glTexEnvfv = glad_debug_impl_glTexEnvfv;
    glad_debug_glTexEnvi = glad_debug_impl_glTexEnvi;
    glad_debug_glTexEnviv = glad_debug_impl_glTexEnviv;
    glad_debug_glTexGend = glad_debug_impl_glTexGend;
    glad_debug_glTexGendv = glad_debug_impl_glTexGendv;
    glad_debug_glTexGenf = glad_debug_impl_glTexGenf;
    glad_debug_glTexGenfv = glad_debug_impl_glTexGenfv;
    glad_debug_glTexGeni = glad_debug_impl_glTexGeni;
    glad_debug_glTexGeniv = glad_debug_impl_glTexGeniv;
    glad_debug_glTexImage1D = glad_debug_impl_glTexImage1D;
    glad_debug_glTexImage2D = glad_debug_impl_glTexImage2D;
    glad_debug_glTexImage3D = glad_debug_impl_glTexImage3D;
    glad_debug_glTexImage3DEXT = glad_debug_impl_glTexImage3DEXT;
    glad_debug_glTexParameterf = glad_debug_impl_glTexParameterf;
    glad_debug_glTexParameterfv = glad_debug_impl_glTexParameterfv;
    glad_debug_glTexParameteri = glad_debug_impl_glTexParameteri;
    glad_debug_glTexParameteriv = glad_debug_impl_glTexParameteriv;
    glad_debug_glTexSubImage1D = glad_debug_impl_glTexSubImage1D;
    glad_debug_glTexSubImage1DEXT = glad_debug_impl_glTexSubImage1DEXT;
    glad_debug_glTexSubImage2D = glad_debug_impl_glTexSubImage2D;
    glad_debug_glTexSubImage2DEXT = glad_debug_impl_glTexSubImage2DEXT;
    glad_debug_glTexSubImage3D = glad_debug_impl_glTexSubImage3D;
    glad_debug_glTexSubImage3DEXT = glad_debug_impl_glTexSubImage3DEXT;
    glad_debug_glTrackMatrixNV = glad_debug_impl_glTrackMatrixNV;
    glad_debug_glTranslated = glad_debug_impl_glTranslated;
    glad_debug_glTranslatef = glad_debug_impl_glTranslatef;
    glad_debug_glUniform1f = glad_debug_impl_glUniform1f;
    glad_debug_glUniform1fARB = glad_debug_impl_glUniform1fARB;
    glad_debug_glUniform1fv = glad_debug_impl_glUniform1fv;
    glad_debug_glUniform1fvARB = glad_debug_impl_glUniform1fvARB;
    glad_debug_glUniform1i = glad_debug_impl_glUniform1i;
    glad_debug_glUniform1iARB = glad_debug_impl_glUniform1iARB;
    glad_debug_glUniform1iv = glad_debug_impl_glUniform1iv;
    glad_debug_glUniform1ivARB = glad_debug_impl_glUniform1ivARB;
    glad_debug_glUniform2f = glad_debug_impl_glUniform2f;
    glad_debug_glUniform2fARB = glad_debug_impl_glUniform2fARB;
    glad_debug_glUniform2fv = glad_debug_impl_glUniform2fv;
    glad_debug_glUniform2fvARB = glad_debug_impl_glUniform2fvARB;
    glad_debug_glUniform2i = glad_debug_impl_glUniform2i;
    glad_debug_glUniform2iARB = glad_debug_impl_glUniform2iARB;
    glad_debug_glUniform2iv = glad_debug_impl_glUniform2iv;
    glad_debug_glUniform2ivARB = glad_debug_impl_glUniform2ivARB;
    glad_debug_glUniform3f = glad_debug_impl_glUniform3f;
    glad_debug_glUniform3fARB = glad_debug_impl_glUniform3fARB;
    glad_debug_glUniform3fv = glad_debug_impl_glUniform3fv;
    glad_debug_glUniform3fvARB = glad_debug_impl_glUniform3fvARB;
    glad_debug_glUniform3i = glad_debug_impl_glUniform3i;
    glad_debug_glUniform3iARB = glad_debug_impl_glUniform3iARB;
    glad_debug_glUniform3iv = glad_debug_impl_glUniform3iv;
    glad_debug_glUniform3ivARB = glad_debug_impl_glUniform3ivARB;
    glad_debug_glUniform4f = glad_debug_impl_glUniform4f;
    glad_debug_glUniform4fARB = glad_debug_impl_glUniform4fARB;
    glad_debug_glUniform4fv = glad_debug_impl_glUniform4fv;
    glad_debug_glUniform4fvARB = glad_debug_impl_glUniform4fvARB;
    glad_debug_glUniform4i = glad_debug_impl_glUniform4i;
    glad_debug_glUniform4iARB = glad_debug_impl_glUniform4iARB;
    glad_debug_glUniform4iv = glad_debug_impl_glUniform4iv;
    glad_debug_glUniform4ivARB = glad_debug_impl_glUniform4ivARB;
    glad_debug_glUniformMatrix2fv = glad_debug_impl_glUniformMatrix2fv;
    glad_debug_glUniformMatrix2fvARB = glad_debug_impl_glUniformMatrix2fvARB;
    glad_debug_glUniformMatrix2x3fv = glad_debug_impl_glUniformMatrix2x3fv;
    glad_debug_glUniformMatrix2x4fv = glad_debug_impl_glUniformMatrix2x4fv;
    glad_debug_glUniformMatrix3fv = glad_debug_impl_glUniformMatrix3fv;
    glad_debug_glUniformMatrix3fvARB = glad_debug_impl_glUniformMatrix3fvARB;
    glad_debug_glUniformMatrix3x2fv = glad_debug_impl_glUniformMatrix3x2fv;
    glad_debug_glUniformMatrix3x4fv = glad_debug_impl_glUniformMatrix3x4fv;
    glad_debug_glUniformMatrix4fv = glad_debug_impl_glUniformMatrix4fv;
    glad_debug_glUniformMatrix4fvARB = glad_debug_impl_glUniformMatrix4fvARB;
    glad_debug_glUniformMatrix4x2fv = glad_debug_impl_glUniformMatrix4x2fv;
    glad_debug_glUniformMatrix4x3fv = glad_debug_impl_glUniformMatrix4x3fv;
    glad_debug_glUnmapBuffer = glad_debug_impl_glUnmapBuffer;
    glad_debug_glUnmapBufferARB = glad_debug_impl_glUnmapBufferARB;
    glad_debug_glUseProgram = glad_debug_impl_glUseProgram;
    glad_debug_glUseProgramObjectARB = glad_debug_impl_glUseProgramObjectARB;
    glad_debug_glValidateProgram = glad_debug_impl_glValidateProgram;
    glad_debug_glValidateProgramARB = glad_debug_impl_glValidateProgramARB;
    glad_debug_glVertex2d = glad_debug_impl_glVertex2d;
    glad_debug_glVertex2dv = glad_debug_impl_glVertex2dv;
    glad_debug_glVertex2f = glad_debug_impl_glVertex2f;
    glad_debug_glVertex2fv = glad_debug_impl_glVertex2fv;
    glad_debug_glVertex2i = glad_debug_impl_glVertex2i;
    glad_debug_glVertex2iv = glad_debug_impl_glVertex2iv;
    glad_debug_glVertex2s = glad_debug_impl_glVertex2s;
    glad_debug_glVertex2sv = glad_debug_impl_glVertex2sv;
    glad_debug_glVertex3d = glad_debug_impl_glVertex3d;
    glad_debug_glVertex3dv = glad_debug_impl_glVertex3dv;
    glad_debug_glVertex3f = glad_debug_impl_glVertex3f;
    glad_debug_glVertex3fv = glad_debug_impl_glVertex3fv;
    glad_debug_glVertex3i = glad_debug_impl_glVertex3i;
    glad_debug_glVertex3iv = glad_debug_impl_glVertex3iv;
    glad_debug_glVertex3s = glad_debug_impl_glVertex3s;
    glad_debug_glVertex3sv = glad_debug_impl_glVertex3sv;
    glad_debug_glVertex4d = glad_debug_impl_glVertex4d;
    glad_debug_glVertex4dv = glad_debug_impl_glVertex4dv;
    glad_debug_glVertex4f = glad_debug_impl_glVertex4f;
    glad_debug_glVertex4fv = glad_debug_impl_glVertex4fv;
    glad_debug_glVertex4i = glad_debug_impl_glVertex4i;
    glad_debug_glVertex4iv = glad_debug_impl_glVertex4iv;
    glad_debug_glVertex4s = glad_debug_impl_glVertex4s;
    glad_debug_glVertex4sv = glad_debug_impl_glVertex4sv;
    glad_debug_glVertexAttrib1d = glad_debug_impl_glVertexAttrib1d;
    glad_debug_glVertexAttrib1dARB = glad_debug_impl_glVertexAttrib1dARB;
    glad_debug_glVertexAttrib1dNV = glad_debug_impl_glVertexAttrib1dNV;
    glad_debug_glVertexAttrib1dv = glad_debug_impl_glVertexAttrib1dv;
    glad_debug_glVertexAttrib1dvARB = glad_debug_impl_glVertexAttrib1dvARB;
    glad_debug_glVertexAttrib1dvNV = glad_debug_impl_glVertexAttrib1dvNV;
    glad_debug_glVertexAttrib1f = glad_debug_impl_glVertexAttrib1f;
    glad_debug_glVertexAttrib1fARB = glad_debug_impl_glVertexAttrib1fARB;
    glad_debug_glVertexAttrib1fNV = glad_debug_impl_glVertexAttrib1fNV;
    glad_debug_glVertexAttrib1fv = glad_debug_impl_glVertexAttrib1fv;
    glad_debug_glVertexAttrib1fvARB = glad_debug_impl_glVertexAttrib1fvARB;
    glad_debug_glVertexAttrib1fvNV = glad_debug_impl_glVertexAttrib1fvNV;
    glad_debug_glVertexAttrib1s = glad_debug_impl_glVertexAttrib1s;
    glad_debug_glVertexAttrib1sARB = glad_debug_impl_glVertexAttrib1sARB;
    glad_debug_glVertexAttrib1sNV = glad_debug_impl_glVertexAttrib1sNV;
    glad_debug_glVertexAttrib1sv = glad_debug_impl_glVertexAttrib1sv;
    glad_debug_glVertexAttrib1svARB = glad_debug_impl_glVertexAttrib1svARB;
    glad_debug_glVertexAttrib1svNV = glad_debug_impl_glVertexAttrib1svNV;
    glad_debug_glVertexAttrib2d = glad_debug_impl_glVertexAttrib2d;
    glad_debug_glVertexAttrib2dARB = glad_debug_impl_glVertexAttrib2dARB;
    glad_debug_glVertexAttrib2dNV = glad_debug_impl_glVertexAttrib2dNV;
    glad_debug_glVertexAttrib2dv = glad_debug_impl_glVertexAttrib2dv;
    glad_debug_glVertexAttrib2dvARB = glad_debug_impl_glVertexAttrib2dvARB;
    glad_debug_glVertexAttrib2dvNV = glad_debug_impl_glVertexAttrib2dvNV;
    glad_debug_glVertexAttrib2f = glad_debug_impl_glVertexAttrib2f;
    glad_debug_glVertexAttrib2fARB = glad_debug_impl_glVertexAttrib2fARB;
    glad_debug_glVertexAttrib2fNV = glad_debug_impl_glVertexAttrib2fNV;
    glad_debug_glVertexAttrib2fv = glad_debug_impl_glVertexAttrib2fv;
    glad_debug_glVertexAttrib2fvARB = glad_debug_impl_glVertexAttrib2fvARB;
    glad_debug_glVertexAttrib2fvNV = glad_debug_impl_glVertexAttrib2fvNV;
    glad_debug_glVertexAttrib2s = glad_debug_impl_glVertexAttrib2s;
    glad_debug_glVertexAttrib2sARB = glad_debug_impl_glVertexAttrib2sARB;
    glad_debug_glVertexAttrib2sNV = glad_debug_impl_glVertexAttrib2sNV;
    glad_debug_glVertexAttrib2sv = glad_debug_impl_glVertexAttrib2sv;
    glad_debug_glVertexAttrib2svARB = glad_debug_impl_glVertexAttrib2svARB;
    glad_debug_glVertexAttrib2svNV = glad_debug_impl_glVertexAttrib2svNV;
    glad_debug_glVertexAttrib3d = glad_debug_impl_glVertexAttrib3d;
    glad_debug_glVertexAttrib3dARB = glad_debug_impl_glVertexAttrib3dARB;
    glad_debug_glVertexAttrib3dNV = glad_debug_impl_glVertexAttrib3dNV;
    glad_debug_glVertexAttrib3dv = glad_debug_impl_glVertexAttrib3dv;
    glad_debug_glVertexAttrib3dvARB = glad_debug_impl_glVertexAttrib3dvARB;
    glad_debug_glVertexAttrib3dvNV = glad_debug_impl_glVertexAttrib3dvNV;
    glad_debug_glVertexAttrib3f = glad_debug_impl_glVertexAttrib3f;
    glad_debug_glVertexAttrib3fARB = glad_debug_impl_glVertexAttrib3fARB;
    glad_debug_glVertexAttrib3fNV = glad_debug_impl_glVertexAttrib3fNV;
    glad_debug_glVertexAttrib3fv = glad_debug_impl_glVertexAttrib3fv;
    glad_debug_glVertexAttrib3fvARB = glad_debug_impl_glVertexAttrib3fvARB;
    glad_debug_glVertexAttrib3fvNV = glad_debug_impl_glVertexAttrib3fvNV;
    glad_debug_glVertexAttrib3s = glad_debug_impl_glVertexAttrib3s;
    glad_debug_glVertexAttrib3sARB = glad_debug_impl_glVertexAttrib3sARB;
    glad_debug_glVertexAttrib3sNV = glad_debug_impl_glVertexAttrib3sNV;
    glad_debug_glVertexAttrib3sv = glad_debug_impl_glVertexAttrib3sv;
    glad_debug_glVertexAttrib3svARB = glad_debug_impl_glVertexAttrib3svARB;
    glad_debug_glVertexAttrib3svNV = glad_debug_impl_glVertexAttrib3svNV;
    glad_debug_glVertexAttrib4Nbv = glad_debug_impl_glVertexAttrib4Nbv;
    glad_debug_glVertexAttrib4NbvARB = glad_debug_impl_glVertexAttrib4NbvARB;
    glad_debug_glVertexAttrib4Niv = glad_debug_impl_glVertexAttrib4Niv;
    glad_debug_glVertexAttrib4NivARB = glad_debug_impl_glVertexAttrib4NivARB;
    glad_debug_glVertexAttrib4Nsv = glad_debug_impl_glVertexAttrib4Nsv;
    glad_debug_glVertexAttrib4NsvARB = glad_debug_impl_glVertexAttrib4NsvARB;
    glad_debug_glVertexAttrib4Nub = glad_debug_impl_glVertexAttrib4Nub;
    glad_debug_glVertexAttrib4NubARB = glad_debug_impl_glVertexAttrib4NubARB;
    glad_debug_glVertexAttrib4Nubv = glad_debug_impl_glVertexAttrib4Nubv;
    glad_debug_glVertexAttrib4NubvARB = glad_debug_impl_glVertexAttrib4NubvARB;
    glad_debug_glVertexAttrib4Nuiv = glad_debug_impl_glVertexAttrib4Nuiv;
    glad_debug_glVertexAttrib4NuivARB = glad_debug_impl_glVertexAttrib4NuivARB;
    glad_debug_glVertexAttrib4Nusv = glad_debug_impl_glVertexAttrib4Nusv;
    glad_debug_glVertexAttrib4NusvARB = glad_debug_impl_glVertexAttrib4NusvARB;
    glad_debug_glVertexAttrib4bv = glad_debug_impl_glVertexAttrib4bv;
    glad_debug_glVertexAttrib4bvARB = glad_debug_impl_glVertexAttrib4bvARB;
    glad_debug_glVertexAttrib4d = glad_debug_impl_glVertexAttrib4d;
    glad_debug_glVertexAttrib4dARB = glad_debug_impl_glVertexAttrib4dARB;
    glad_debug_glVertexAttrib4dNV = glad_debug_impl_glVertexAttrib4dNV;
    glad_debug_glVertexAttrib4dv = glad_debug_impl_glVertexAttrib4dv;
    glad_debug_glVertexAttrib4dvARB = glad_debug_impl_glVertexAttrib4dvARB;
    glad_debug_glVertexAttrib4dvNV = glad_debug_impl_glVertexAttrib4dvNV;
    glad_debug_glVertexAttrib4f = glad_debug_impl_glVertexAttrib4f;
    glad_debug_glVertexAttrib4fARB = glad_debug_impl_glVertexAttrib4fARB;
    glad_debug_glVertexAttrib4fNV = glad_debug_impl_glVertexAttrib4fNV;
    glad_debug_glVertexAttrib4fv = glad_debug_impl_glVertexAttrib4fv;
    glad_debug_glVertexAttrib4fvARB = glad_debug_impl_glVertexAttrib4fvARB;
    glad_debug_glVertexAttrib4fvNV = glad_debug_impl_glVertexAttrib4fvNV;
    glad_debug_glVertexAttrib4iv = glad_debug_impl_glVertexAttrib4iv;
    glad_debug_glVertexAttrib4ivARB = glad_debug_impl_glVertexAttrib4ivARB;
    glad_debug_glVertexAttrib4s = glad_debug_impl_glVertexAttrib4s;
    glad_debug_glVertexAttrib4sARB = glad_debug_impl_glVertexAttrib4sARB;
    glad_debug_glVertexAttrib4sNV = glad_debug_impl_glVertexAttrib4sNV;
    glad_debug_glVertexAttrib4sv = glad_debug_impl_glVertexAttrib4sv;
    glad_debug_glVertexAttrib4svARB = glad_debug_impl_glVertexAttrib4svARB;
    glad_debug_glVertexAttrib4svNV = glad_debug_impl_glVertexAttrib4svNV;
    glad_debug_glVertexAttrib4ubNV = glad_debug_impl_glVertexAttrib4ubNV;
    glad_debug_glVertexAttrib4ubv = glad_debug_impl_glVertexAttrib4ubv;
    glad_debug_glVertexAttrib4ubvARB = glad_debug_impl_glVertexAttrib4ubvARB;
    glad_debug_glVertexAttrib4ubvNV = glad_debug_impl_glVertexAttrib4ubvNV;
    glad_debug_glVertexAttrib4uiv = glad_debug_impl_glVertexAttrib4uiv;
    glad_debug_glVertexAttrib4uivARB = glad_debug_impl_glVertexAttrib4uivARB;
    glad_debug_glVertexAttrib4usv = glad_debug_impl_glVertexAttrib4usv;
    glad_debug_glVertexAttrib4usvARB = glad_debug_impl_glVertexAttrib4usvARB;
    glad_debug_glVertexAttribPointer = glad_debug_impl_glVertexAttribPointer;
    glad_debug_glVertexAttribPointerARB = glad_debug_impl_glVertexAttribPointerARB;
    glad_debug_glVertexAttribPointerNV = glad_debug_impl_glVertexAttribPointerNV;
    glad_debug_glVertexAttribs1dvNV = glad_debug_impl_glVertexAttribs1dvNV;
    glad_debug_glVertexAttribs1fvNV = glad_debug_impl_glVertexAttribs1fvNV;
    glad_debug_glVertexAttribs1svNV = glad_debug_impl_glVertexAttribs1svNV;
    glad_debug_glVertexAttribs2dvNV = glad_debug_impl_glVertexAttribs2dvNV;
    glad_debug_glVertexAttribs2fvNV = glad_debug_impl_glVertexAttribs2fvNV;
    glad_debug_glVertexAttribs2svNV = glad_debug_impl_glVertexAttribs2svNV;
    glad_debug_glVertexAttribs3dvNV = glad_debug_impl_glVertexAttribs3dvNV;
    glad_debug_glVertexAttribs3fvNV = glad_debug_impl_glVertexAttribs3fvNV;
    glad_debug_glVertexAttribs3svNV = glad_debug_impl_glVertexAttribs3svNV;
    glad_debug_glVertexAttribs4dvNV = glad_debug_impl_glVertexAttribs4dvNV;
    glad_debug_glVertexAttribs4fvNV = glad_debug_impl_glVertexAttribs4fvNV;
    glad_debug_glVertexAttribs4svNV = glad_debug_impl_glVertexAttribs4svNV;
    glad_debug_glVertexAttribs4ubvNV = glad_debug_impl_glVertexAttribs4ubvNV;
    glad_debug_glVertexPointer = glad_debug_impl_glVertexPointer;
    glad_debug_glVertexPointerEXT = glad_debug_impl_glVertexPointerEXT;
    glad_debug_glViewport = glad_debug_impl_glViewport;
    glad_debug_glWindowPos2d = glad_debug_impl_glWindowPos2d;
    glad_debug_glWindowPos2dARB = glad_debug_impl_glWindowPos2dARB;
    glad_debug_glWindowPos2dMESA = glad_debug_impl_glWindowPos2dMESA;
    glad_debug_glWindowPos2dv = glad_debug_impl_glWindowPos2dv;
    glad_debug_glWindowPos2dvARB = glad_debug_impl_glWindowPos2dvARB;
    glad_debug_glWindowPos2dvMESA = glad_debug_impl_glWindowPos2dvMESA;
    glad_debug_glWindowPos2f = glad_debug_impl_glWindowPos2f;
    glad_debug_glWindowPos2fARB = glad_debug_impl_glWindowPos2fARB;
    glad_debug_glWindowPos2fMESA = glad_debug_impl_glWindowPos2fMESA;
    glad_debug_glWindowPos2fv = glad_debug_impl_glWindowPos2fv;
    glad_debug_glWindowPos2fvARB = glad_debug_impl_glWindowPos2fvARB;
    glad_debug_glWindowPos2fvMESA = glad_debug_impl_glWindowPos2fvMESA;
    glad_debug_glWindowPos2i = glad_debug_impl_glWindowPos2i;
    glad_debug_glWindowPos2iARB = glad_debug_impl_glWindowPos2iARB;
    glad_debug_glWindowPos2iMESA = glad_debug_impl_glWindowPos2iMESA;
    glad_debug_glWindowPos2iv = glad_debug_impl_glWindowPos2iv;
    glad_debug_glWindowPos2ivARB = glad_debug_impl_glWindowPos2ivARB;
    glad_debug_glWindowPos2ivMESA = glad_debug_impl_glWindowPos2ivMESA;
    glad_debug_glWindowPos2s = glad_debug_impl_glWindowPos2s;
    glad_debug_glWindowPos2sARB = glad_debug_impl_glWindowPos2sARB;
    glad_debug_glWindowPos2sMESA = glad_debug_impl_glWindowPos2sMESA;
    glad_debug_glWindowPos2sv = glad_debug_impl_glWindowPos2sv;
    glad_debug_glWindowPos2svARB = glad_debug_impl_glWindowPos2svARB;
    glad_debug_glWindowPos2svMESA = glad_debug_impl_glWindowPos2svMESA;
    glad_debug_glWindowPos3d = glad_debug_impl_glWindowPos3d;
    glad_debug_glWindowPos3dARB = glad_debug_impl_glWindowPos3dARB;
    glad_debug_glWindowPos3dMESA = glad_debug_impl_glWindowPos3dMESA;
    glad_debug_glWindowPos3dv = glad_debug_impl_glWindowPos3dv;
    glad_debug_glWindowPos3dvARB = glad_debug_impl_glWindowPos3dvARB;
    glad_debug_glWindowPos3dvMESA = glad_debug_impl_glWindowPos3dvMESA;
    glad_debug_glWindowPos3f = glad_debug_impl_glWindowPos3f;
    glad_debug_glWindowPos3fARB = glad_debug_impl_glWindowPos3fARB;
    glad_debug_glWindowPos3fMESA = glad_debug_impl_glWindowPos3fMESA;
    glad_debug_glWindowPos3fv = glad_debug_impl_glWindowPos3fv;
    glad_debug_glWindowPos3fvARB = glad_debug_impl_glWindowPos3fvARB;
    glad_debug_glWindowPos3fvMESA = glad_debug_impl_glWindowPos3fvMESA;
    glad_debug_glWindowPos3i = glad_debug_impl_glWindowPos3i;
    glad_debug_glWindowPos3iARB = glad_debug_impl_glWindowPos3iARB;
    glad_debug_glWindowPos3iMESA = glad_debug_impl_glWindowPos3iMESA;
    glad_debug_glWindowPos3iv = glad_debug_impl_glWindowPos3iv;
    glad_debug_glWindowPos3ivARB = glad_debug_impl_glWindowPos3ivARB;
    glad_debug_glWindowPos3ivMESA = glad_debug_impl_glWindowPos3ivMESA;
    glad_debug_glWindowPos3s = glad_debug_impl_glWindowPos3s;
    glad_debug_glWindowPos3sARB = glad_debug_impl_glWindowPos3sARB;
    glad_debug_glWindowPos3sMESA = glad_debug_impl_glWindowPos3sMESA;
    glad_debug_glWindowPos3sv = glad_debug_impl_glWindowPos3sv;
    glad_debug_glWindowPos3svARB = glad_debug_impl_glWindowPos3svARB;
    glad_debug_glWindowPos3svMESA = glad_debug_impl_glWindowPos3svMESA;
    glad_debug_glWindowPos4dMESA = glad_debug_impl_glWindowPos4dMESA;
    glad_debug_glWindowPos4dvMESA = glad_debug_impl_glWindowPos4dvMESA;
    glad_debug_glWindowPos4fMESA = glad_debug_impl_glWindowPos4fMESA;
    glad_debug_glWindowPos4fvMESA = glad_debug_impl_glWindowPos4fvMESA;
    glad_debug_glWindowPos4iMESA = glad_debug_impl_glWindowPos4iMESA;
    glad_debug_glWindowPos4ivMESA = glad_debug_impl_glWindowPos4ivMESA;
    glad_debug_glWindowPos4sMESA = glad_debug_impl_glWindowPos4sMESA;
    glad_debug_glWindowPos4svMESA = glad_debug_impl_glWindowPos4svMESA;
}

void gladUninstallGLDebug(void) {
    glad_debug_glAccum = glad_glAccum;
    glad_debug_glActiveTexture = glad_glActiveTexture;
    glad_debug_glActiveTextureARB = glad_glActiveTextureARB;
    glad_debug_glAlphaFunc = glad_glAlphaFunc;
    glad_debug_glAreProgramsResidentNV = glad_glAreProgramsResidentNV;
    glad_debug_glAreTexturesResident = glad_glAreTexturesResident;
    glad_debug_glAreTexturesResidentEXT = glad_glAreTexturesResidentEXT;
    glad_debug_glArrayElement = glad_glArrayElement;
    glad_debug_glArrayElementEXT = glad_glArrayElementEXT;
    glad_debug_glAttachObjectARB = glad_glAttachObjectARB;
    glad_debug_glAttachShader = glad_glAttachShader;
    glad_debug_glBegin = glad_glBegin;
    glad_debug_glBeginQuery = glad_glBeginQuery;
    glad_debug_glBeginQueryARB = glad_glBeginQueryARB;
    glad_debug_glBindAttribLocation = glad_glBindAttribLocation;
    glad_debug_glBindAttribLocationARB = glad_glBindAttribLocationARB;
    glad_debug_glBindBuffer = glad_glBindBuffer;
    glad_debug_glBindBufferARB = glad_glBindBufferARB;
    glad_debug_glBindProgramARB = glad_glBindProgramARB;
    glad_debug_glBindProgramNV = glad_glBindProgramNV;
    glad_debug_glBindTexture = glad_glBindTexture;
    glad_debug_glBindTextureEXT = glad_glBindTextureEXT;
    glad_debug_glBitmap = glad_glBitmap;
    glad_debug_glBlendColor = glad_glBlendColor;
    glad_debug_glBlendColorEXT = glad_glBlendColorEXT;
    glad_debug_glBlendEquation = glad_glBlendEquation;
    glad_debug_glBlendEquationEXT = glad_glBlendEquationEXT;
    glad_debug_glBlendEquationSeparate = glad_glBlendEquationSeparate;
    glad_debug_glBlendEquationSeparateEXT = glad_glBlendEquationSeparateEXT;
    glad_debug_glBlendFunc = glad_glBlendFunc;
    glad_debug_glBlendFuncSeparate = glad_glBlendFuncSeparate;
    glad_debug_glBlendFuncSeparateEXT = glad_glBlendFuncSeparateEXT;
    glad_debug_glBlendFuncSeparateINGR = glad_glBlendFuncSeparateINGR;
    glad_debug_glBufferData = glad_glBufferData;
    glad_debug_glBufferDataARB = glad_glBufferDataARB;
    glad_debug_glBufferSubData = glad_glBufferSubData;
    glad_debug_glBufferSubDataARB = glad_glBufferSubDataARB;
    glad_debug_glCallList = glad_glCallList;
    glad_debug_glCallLists = glad_glCallLists;
    glad_debug_glClear = glad_glClear;
    glad_debug_glClearAccum = glad_glClearAccum;
    glad_debug_glClearColor = glad_glClearColor;
    glad_debug_glClearDepth = glad_glClearDepth;
    glad_debug_glClearIndex = glad_glClearIndex;
    glad_debug_glClearStencil = glad_glClearStencil;
    glad_debug_glClientActiveTexture = glad_glClientActiveTexture;
    glad_debug_glClientActiveTextureARB = glad_glClientActiveTextureARB;
    glad_debug_glClipPlane = glad_glClipPlane;
    glad_debug_glColor3b = glad_glColor3b;
    glad_debug_glColor3bv = glad_glColor3bv;
    glad_debug_glColor3d = glad_glColor3d;
    glad_debug_glColor3dv = glad_glColor3dv;
    glad_debug_glColor3f = glad_glColor3f;
    glad_debug_glColor3fv = glad_glColor3fv;
    glad_debug_glColor3i = glad_glColor3i;
    glad_debug_glColor3iv = glad_glColor3iv;
    glad_debug_glColor3s = glad_glColor3s;
    glad_debug_glColor3sv = glad_glColor3sv;
    glad_debug_glColor3ub = glad_glColor3ub;
    glad_debug_glColor3ubv = glad_glColor3ubv;
    glad_debug_glColor3ui = glad_glColor3ui;
    glad_debug_glColor3uiv = glad_glColor3uiv;
    glad_debug_glColor3us = glad_glColor3us;
    glad_debug_glColor3usv = glad_glColor3usv;
    glad_debug_glColor4b = glad_glColor4b;
    glad_debug_glColor4bv = glad_glColor4bv;
    glad_debug_glColor4d = glad_glColor4d;
    glad_debug_glColor4dv = glad_glColor4dv;
    glad_debug_glColor4f = glad_glColor4f;
    glad_debug_glColor4fv = glad_glColor4fv;
    glad_debug_glColor4i = glad_glColor4i;
    glad_debug_glColor4iv = glad_glColor4iv;
    glad_debug_glColor4s = glad_glColor4s;
    glad_debug_glColor4sv = glad_glColor4sv;
    glad_debug_glColor4ub = glad_glColor4ub;
    glad_debug_glColor4ubv = glad_glColor4ubv;
    glad_debug_glColor4ui = glad_glColor4ui;
    glad_debug_glColor4uiv = glad_glColor4uiv;
    glad_debug_glColor4us = glad_glColor4us;
    glad_debug_glColor4usv = glad_glColor4usv;
    glad_debug_glColorMask = glad_glColorMask;
    glad_debug_glColorMaterial = glad_glColorMaterial;
    glad_debug_glColorPointer = glad_glColorPointer;
    glad_debug_glColorPointerEXT = glad_glColorPointerEXT;
    glad_debug_glColorSubTable = glad_glColorSubTable;
    glad_debug_glColorTable = glad_glColorTable;
    glad_debug_glColorTableParameterfv = glad_glColorTableParameterfv;
    glad_debug_glColorTableParameteriv = glad_glColorTableParameteriv;
    glad_debug_glCompileShader = glad_glCompileShader;
    glad_debug_glCompileShaderARB = glad_glCompileShaderARB;
    glad_debug_glCompressedTexImage1D = glad_glCompressedTexImage1D;
    glad_debug_glCompressedTexImage1DARB = glad_glCompressedTexImage1DARB;
    glad_debug_glCompressedTexImage2D = glad_glCompressedTexImage2D;
    glad_debug_glCompressedTexImage2DARB = glad_glCompressedTexImage2DARB;
    glad_debug_glCompressedTexImage3D = glad_glCompressedTexImage3D;
    glad_debug_glCompressedTexImage3DARB = glad_glCompressedTexImage3DARB;
    glad_debug_glCompressedTexSubImage1D = glad_glCompressedTexSubImage1D;
    glad_debug_glCompressedTexSubImage1DARB = glad_glCompressedTexSubImage1DARB;
    glad_debug_glCompressedTexSubImage2D = glad_glCompressedTexSubImage2D;
    glad_debug_glCompressedTexSubImage2DARB = glad_glCompressedTexSubImage2DARB;
    glad_debug_glCompressedTexSubImage3D = glad_glCompressedTexSubImage3D;
    glad_debug_glCompressedTexSubImage3DARB = glad_glCompressedTexSubImage3DARB;
    glad_debug_glConvolutionFilter1D = glad_glConvolutionFilter1D;
    glad_debug_glConvolutionFilter2D = glad_glConvolutionFilter2D;
    glad_debug_glConvolutionParameterf = glad_glConvolutionParameterf;
    glad_debug_glConvolutionParameterfv = glad_glConvolutionParameterfv;
    glad_debug_glConvolutionParameteri = glad_glConvolutionParameteri;
    glad_debug_glConvolutionParameteriv = glad_glConvolutionParameteriv;
    glad_debug_glCopyColorSubTable = glad_glCopyColorSubTable;
    glad_debug_glCopyColorTable = glad_glCopyColorTable;
    glad_debug_glCopyConvolutionFilter1D = glad_glCopyConvolutionFilter1D;
    glad_debug_glCopyConvolutionFilter2D = glad_glCopyConvolutionFilter2D;
    glad_debug_glCopyPixels = glad_glCopyPixels;
    glad_debug_glCopyTexImage1D = glad_glCopyTexImage1D;
    glad_debug_glCopyTexImage1DEXT = glad_glCopyTexImage1DEXT;
    glad_debug_glCopyTexImage2D = glad_glCopyTexImage2D;
    glad_debug_glCopyTexImage2DEXT = glad_glCopyTexImage2DEXT;
    glad_debug_glCopyTexSubImage1D = glad_glCopyTexSubImage1D;
    glad_debug_glCopyTexSubImage1DEXT = glad_glCopyTexSubImage1DEXT;
    glad_debug_glCopyTexSubImage2D = glad_glCopyTexSubImage2D;
    glad_debug_glCopyTexSubImage2DEXT = glad_glCopyTexSubImage2DEXT;
    glad_debug_glCopyTexSubImage3D = glad_glCopyTexSubImage3D;
    glad_debug_glCopyTexSubImage3DEXT = glad_glCopyTexSubImage3DEXT;
    glad_debug_glCreateProgram = glad_glCreateProgram;
    glad_debug_glCreateProgramObjectARB = glad_glCreateProgramObjectARB;
    glad_debug_glCreateShader = glad_glCreateShader;
    glad_debug_glCreateShaderObjectARB = glad_glCreateShaderObjectARB;
    glad_debug_glCullFace = glad_glCullFace;
    glad_debug_glDebugMessageCallback = glad_glDebugMessageCallback;
    glad_debug_glDebugMessageControl = glad_glDebugMessageControl;
    glad_debug_glDebugMessageInsert = glad_glDebugMessageInsert;
    glad_debug_glDeleteBuffers = glad_glDeleteBuffers;
    glad_debug_glDeleteBuffersARB = glad_glDeleteBuffersARB;
    glad_debug_glDeleteLists = glad_glDeleteLists;
    glad_debug_glDeleteObjectARB = glad_glDeleteObjectARB;
    glad_debug_glDeleteProgram = glad_glDeleteProgram;
    glad_debug_glDeleteProgramsARB = glad_glDeleteProgramsARB;
    glad_debug_glDeleteProgramsNV = glad_glDeleteProgramsNV;
    glad_debug_glDeleteQueries = glad_glDeleteQueries;
    glad_debug_glDeleteQueriesARB = glad_glDeleteQueriesARB;
    glad_debug_glDeleteShader = glad_glDeleteShader;
    glad_debug_glDeleteTextures = glad_glDeleteTextures;
    glad_debug_glDeleteTexturesEXT = glad_glDeleteTexturesEXT;
    glad_debug_glDepthFunc = glad_glDepthFunc;
    glad_debug_glDepthMask = glad_glDepthMask;
    glad_debug_glDepthRange = glad_glDepthRange;
    glad_debug_glDetachObjectARB = glad_glDetachObjectARB;
    glad_debug_glDetachShader = glad_glDetachShader;
    glad_debug_glDisable = glad_glDisable;
    glad_debug_glDisableClientState = glad_glDisableClientState;
    glad_debug_glDisableVertexAttribArray = glad_glDisableVertexAttribArray;
    glad_debug_glDisableVertexAttribArrayARB = glad_glDisableVertexAttribArrayARB;
    glad_debug_glDrawArrays = glad_glDrawArrays;
    glad_debug_glDrawArraysEXT = glad_glDrawArraysEXT;
    glad_debug_glDrawBuffer = glad_glDrawBuffer;
    glad_debug_glDrawBuffers = glad_glDrawBuffers;
    glad_debug_glDrawBuffersARB = glad_glDrawBuffersARB;
    glad_debug_glDrawBuffersATI = glad_glDrawBuffersATI;
    glad_debug_glDrawElements = glad_glDrawElements;
    glad_debug_glDrawPixels = glad_glDrawPixels;
    glad_debug_glDrawRangeElements = glad_glDrawRangeElements;
    glad_debug_glDrawRangeElementsEXT = glad_glDrawRangeElementsEXT;
    glad_debug_glEdgeFlag = glad_glEdgeFlag;
    glad_debug_glEdgeFlagPointer = glad_glEdgeFlagPointer;
    glad_debug_glEdgeFlagPointerEXT = glad_glEdgeFlagPointerEXT;
    glad_debug_glEdgeFlagv = glad_glEdgeFlagv;
    glad_debug_glEnable = glad_glEnable;
    glad_debug_glEnableClientState = glad_glEnableClientState;
    glad_debug_glEnableVertexAttribArray = glad_glEnableVertexAttribArray;
    glad_debug_glEnableVertexAttribArrayARB = glad_glEnableVertexAttribArrayARB;
    glad_debug_glEnd = glad_glEnd;
    glad_debug_glEndList = glad_glEndList;
    glad_debug_glEndQuery = glad_glEndQuery;
    glad_debug_glEndQueryARB = glad_glEndQueryARB;
    glad_debug_glEvalCoord1d = glad_glEvalCoord1d;
    glad_debug_glEvalCoord1dv = glad_glEvalCoord1dv;
    glad_debug_glEvalCoord1f = glad_glEvalCoord1f;
    glad_debug_glEvalCoord1fv = glad_glEvalCoord1fv;
    glad_debug_glEvalCoord2d = glad_glEvalCoord2d;
    glad_debug_glEvalCoord2dv = glad_glEvalCoord2dv;
    glad_debug_glEvalCoord2f = glad_glEvalCoord2f;
    glad_debug_glEvalCoord2fv = glad_glEvalCoord2fv;
    glad_debug_glEvalMesh1 = glad_glEvalMesh1;
    glad_debug_glEvalMesh2 = glad_glEvalMesh2;
    glad_debug_glEvalPoint1 = glad_glEvalPoint1;
    glad_debug_glEvalPoint2 = glad_glEvalPoint2;
    glad_debug_glExecuteProgramNV = glad_glExecuteProgramNV;
    glad_debug_glFeedbackBuffer = glad_glFeedbackBuffer;
    glad_debug_glFinish = glad_glFinish;
    glad_debug_glFlush = glad_glFlush;
    glad_debug_glFogCoordPointer = glad_glFogCoordPointer;
    glad_debug_glFogCoordPointerEXT = glad_glFogCoordPointerEXT;
    glad_debug_glFogCoordd = glad_glFogCoordd;
    glad_debug_glFogCoorddEXT = glad_glFogCoorddEXT;
    glad_debug_glFogCoorddv = glad_glFogCoorddv;
    glad_debug_glFogCoorddvEXT = glad_glFogCoorddvEXT;
    glad_debug_glFogCoordf = glad_glFogCoordf;
    glad_debug_glFogCoordfEXT = glad_glFogCoordfEXT;
    glad_debug_glFogCoordfv = glad_glFogCoordfv;
    glad_debug_glFogCoordfvEXT = glad_glFogCoordfvEXT;
    glad_debug_glFogf = glad_glFogf;
    glad_debug_glFogfv = glad_glFogfv;
    glad_debug_glFogi = glad_glFogi;
    glad_debug_glFogiv = glad_glFogiv;
    glad_debug_glFrontFace = glad_glFrontFace;
    glad_debug_glFrustum = glad_glFrustum;
    glad_debug_glGenBuffers = glad_glGenBuffers;
    glad_debug_glGenBuffersARB = glad_glGenBuffersARB;
    glad_debug_glGenLists = glad_glGenLists;
    glad_debug_glGenProgramsARB = glad_glGenProgramsARB;
    glad_debug_glGenProgramsNV = glad_glGenProgramsNV;
    glad_debug_glGenQueries = glad_glGenQueries;
    glad_debug_glGenQueriesARB = glad_glGenQueriesARB;
    glad_debug_glGenTextures = glad_glGenTextures;
    glad_debug_glGenTexturesEXT = glad_glGenTexturesEXT;
    glad_debug_glGetActiveAttrib = glad_glGetActiveAttrib;
    glad_debug_glGetActiveAttribARB = glad_glGetActiveAttribARB;
    glad_debug_glGetActiveUniform = glad_glGetActiveUniform;
    glad_debug_glGetActiveUniformARB = glad_glGetActiveUniformARB;
    glad_debug_glGetAttachedObjectsARB = glad_glGetAttachedObjectsARB;
    glad_debug_glGetAttachedShaders = glad_glGetAttachedShaders;
    glad_debug_glGetAttribLocation = glad_glGetAttribLocation;
    glad_debug_glGetAttribLocationARB = glad_glGetAttribLocationARB;
    glad_debug_glGetBooleanv = glad_glGetBooleanv;
    glad_debug_glGetBufferParameteriv = glad_glGetBufferParameteriv;
    glad_debug_glGetBufferParameterivARB = glad_glGetBufferParameterivARB;
    glad_debug_glGetBufferPointerv = glad_glGetBufferPointerv;
    glad_debug_glGetBufferPointervARB = glad_glGetBufferPointervARB;
    glad_debug_glGetBufferSubData = glad_glGetBufferSubData;
    glad_debug_glGetBufferSubDataARB = glad_glGetBufferSubDataARB;
    glad_debug_glGetClipPlane = glad_glGetClipPlane;
    glad_debug_glGetColorTable = glad_glGetColorTable;
    glad_debug_glGetColorTableParameterfv = glad_glGetColorTableParameterfv;
    glad_debug_glGetColorTableParameteriv = glad_glGetColorTableParameteriv;
    glad_debug_glGetCompressedTexImage = glad_glGetCompressedTexImage;
    glad_debug_glGetCompressedTexImageARB = glad_glGetCompressedTexImageARB;
    glad_debug_glGetConvolutionFilter = glad_glGetConvolutionFilter;
    glad_debug_glGetConvolutionParameterfv = glad_glGetConvolutionParameterfv;
    glad_debug_glGetConvolutionParameteriv = glad_glGetConvolutionParameteriv;
    glad_debug_glGetDebugMessageLog = glad_glGetDebugMessageLog;
    glad_debug_glGetDoublev = glad_glGetDoublev;
    glad_debug_glGetError = glad_glGetError;
    glad_debug_glGetFloatv = glad_glGetFloatv;
    glad_debug_glGetHandleARB = glad_glGetHandleARB;
    glad_debug_glGetHistogram = glad_glGetHistogram;
    glad_debug_glGetHistogramParameterfv = glad_glGetHistogramParameterfv;
    glad_debug_glGetHistogramParameteriv = glad_glGetHistogramParameteriv;
    glad_debug_glGetInfoLogARB = glad_glGetInfoLogARB;
    glad_debug_glGetIntegerv = glad_glGetIntegerv;
    glad_debug_glGetLightfv = glad_glGetLightfv;
    glad_debug_glGetLightiv = glad_glGetLightiv;
    glad_debug_glGetMapdv = glad_glGetMapdv;
    glad_debug_glGetMapfv = glad_glGetMapfv;
    glad_debug_glGetMapiv = glad_glGetMapiv;
    glad_debug_glGetMaterialfv = glad_glGetMaterialfv;
    glad_debug_glGetMaterialiv = glad_glGetMaterialiv;
    glad_debug_glGetMinmax = glad_glGetMinmax;
    glad_debug_glGetMinmaxParameterfv = glad_glGetMinmaxParameterfv;
    glad_debug_glGetMinmaxParameteriv = glad_glGetMinmaxParameteriv;
    glad_debug_glGetObjectLabel = glad_glGetObjectLabel;
    glad_debug_glGetObjectParameterfvARB = glad_glGetObjectParameterfvARB;
    glad_debug_glGetObjectParameterivARB = glad_glGetObjectParameterivARB;
    glad_debug_glGetObjectPtrLabel = glad_glGetObjectPtrLabel;
    glad_debug_glGetPixelMapfv = glad_glGetPixelMapfv;
    glad_debug_glGetPixelMapuiv = glad_glGetPixelMapuiv;
    glad_debug_glGetPixelMapusv = glad_glGetPixelMapusv;
    glad_debug_glGetPointerv = glad_glGetPointerv;
    glad_debug_glGetPointervEXT = glad_glGetPointervEXT;
    glad_debug_glGetPolygonStipple = glad_glGetPolygonStipple;
    glad_debug_glGetProgramEnvParameterdvARB = glad_glGetProgramEnvParameterdvARB;
    glad_debug_glGetProgramEnvParameterfvARB = glad_glGetProgramEnvParameterfvARB;
    glad_debug_glGetProgramInfoLog = glad_glGetProgramInfoLog;
    glad_debug_glGetProgramLocalParameterdvARB = glad_glGetProgramLocalParameterdvARB;
    glad_debug_glGetProgramLocalParameterfvARB = glad_glGetProgramLocalParameterfvARB;
    glad_debug_glGetProgramParameterdvNV = glad_glGetProgramParameterdvNV;
    glad_debug_glGetProgramParameterfvNV = glad_glGetProgramParameterfvNV;
    glad_debug_glGetProgramStringARB = glad_glGetProgramStringARB;
    glad_debug_glGetProgramStringNV = glad_glGetProgramStringNV;
    glad_debug_glGetProgramiv = glad_glGetProgramiv;
    glad_debug_glGetProgramivARB = glad_glGetProgramivARB;
    glad_debug_glGetProgramivNV = glad_glGetProgramivNV;
    glad_debug_glGetQueryObjectiv = glad_glGetQueryObjectiv;
    glad_debug_glGetQueryObjectivARB = glad_glGetQueryObjectivARB;
    glad_debug_glGetQueryObjectuiv = glad_glGetQueryObjectuiv;
    glad_debug_glGetQueryObjectuivARB = glad_glGetQueryObjectuivARB;
    glad_debug_glGetQueryiv = glad_glGetQueryiv;
    glad_debug_glGetQueryivARB = glad_glGetQueryivARB;
    glad_debug_glGetSeparableFilter = glad_glGetSeparableFilter;
    glad_debug_glGetShaderInfoLog = glad_glGetShaderInfoLog;
    glad_debug_glGetShaderSource = glad_glGetShaderSource;
    glad_debug_glGetShaderSourceARB = glad_glGetShaderSourceARB;
    glad_debug_glGetShaderiv = glad_glGetShaderiv;
    glad_debug_glGetString = glad_glGetString;
    glad_debug_glGetTexEnvfv = glad_glGetTexEnvfv;
    glad_debug_glGetTexEnviv = glad_glGetTexEnviv;
    glad_debug_glGetTexGendv = glad_glGetTexGendv;
    glad_debug_glGetTexGenfv = glad_glGetTexGenfv;
    glad_debug_glGetTexGeniv = glad_glGetTexGeniv;
    glad_debug_glGetTexImage = glad_glGetTexImage;
    glad_debug_glGetTexLevelParameterfv = glad_glGetTexLevelParameterfv;
    glad_debug_glGetTexLevelParameteriv = glad_glGetTexLevelParameteriv;
    glad_debug_glGetTexParameterfv = glad_glGetTexParameterfv;
    glad_debug_glGetTexParameteriv = glad_glGetTexParameteriv;
    glad_debug_glGetTrackMatrixivNV = glad_glGetTrackMatrixivNV;
    glad_debug_glGetUniformLocation = glad_glGetUniformLocation;
    glad_debug_glGetUniformLocationARB = glad_glGetUniformLocationARB;
    glad_debug_glGetUniformfv = glad_glGetUniformfv;
    glad_debug_glGetUniformfvARB = glad_glGetUniformfvARB;
    glad_debug_glGetUniformiv = glad_glGetUniformiv;
    glad_debug_glGetUniformivARB = glad_glGetUniformivARB;
    glad_debug_glGetVertexAttribPointerv = glad_glGetVertexAttribPointerv;
    glad_debug_glGetVertexAttribPointervARB = glad_glGetVertexAttribPointervARB;
    glad_debug_glGetVertexAttribPointervNV = glad_glGetVertexAttribPointervNV;
    glad_debug_glGetVertexAttribdv = glad_glGetVertexAttribdv;
    glad_debug_glGetVertexAttribdvARB = glad_glGetVertexAttribdvARB;
    glad_debug_glGetVertexAttribdvNV = glad_glGetVertexAttribdvNV;
    glad_debug_glGetVertexAttribfv = glad_glGetVertexAttribfv;
    glad_debug_glGetVertexAttribfvARB = glad_glGetVertexAttribfvARB;
    glad_debug_glGetVertexAttribfvNV = glad_glGetVertexAttribfvNV;
    glad_debug_glGetVertexAttribiv = glad_glGetVertexAttribiv;
    glad_debug_glGetVertexAttribivARB = glad_glGetVertexAttribivARB;
    glad_debug_glGetVertexAttribivNV = glad_glGetVertexAttribivNV;
    glad_debug_glHint = glad_glHint;
    glad_debug_glHistogram = glad_glHistogram;
    glad_debug_glIndexMask = glad_glIndexMask;
    glad_debug_glIndexPointer = glad_glIndexPointer;
    glad_debug_glIndexPointerEXT = glad_glIndexPointerEXT;
    glad_debug_glIndexd = glad_glIndexd;
    glad_debug_glIndexdv = glad_glIndexdv;
    glad_debug_glIndexf = glad_glIndexf;
    glad_debug_glIndexfv = glad_glIndexfv;
    glad_debug_glIndexi = glad_glIndexi;
    glad_debug_glIndexiv = glad_glIndexiv;
    glad_debug_glIndexs = glad_glIndexs;
    glad_debug_glIndexsv = glad_glIndexsv;
    glad_debug_glIndexub = glad_glIndexub;
    glad_debug_glIndexubv = glad_glIndexubv;
    glad_debug_glInitNames = glad_glInitNames;
    glad_debug_glInterleavedArrays = glad_glInterleavedArrays;
    glad_debug_glIsBuffer = glad_glIsBuffer;
    glad_debug_glIsBufferARB = glad_glIsBufferARB;
    glad_debug_glIsEnabled = glad_glIsEnabled;
    glad_debug_glIsList = glad_glIsList;
    glad_debug_glIsProgram = glad_glIsProgram;
    glad_debug_glIsProgramARB = glad_glIsProgramARB;
    glad_debug_glIsProgramNV = glad_glIsProgramNV;
    glad_debug_glIsQuery = glad_glIsQuery;
    glad_debug_glIsQueryARB = glad_glIsQueryARB;
    glad_debug_glIsShader = glad_glIsShader;
    glad_debug_glIsTexture = glad_glIsTexture;
    glad_debug_glIsTextureEXT = glad_glIsTextureEXT;
    glad_debug_glLightModelf = glad_glLightModelf;
    glad_debug_glLightModelfv = glad_glLightModelfv;
    glad_debug_glLightModeli = glad_glLightModeli;
    glad_debug_glLightModeliv = glad_glLightModeliv;
    glad_debug_glLightf = glad_glLightf;
    glad_debug_glLightfv = glad_glLightfv;
    glad_debug_glLighti = glad_glLighti;
    glad_debug_glLightiv = glad_glLightiv;
    glad_debug_glLineStipple = glad_glLineStipple;
    glad_debug_glLineWidth = glad_glLineWidth;
    glad_debug_glLinkProgram = glad_glLinkProgram;
    glad_debug_glLinkProgramARB = glad_glLinkProgramARB;
    glad_debug_glListBase = glad_glListBase;
    glad_debug_glLoadIdentity = glad_glLoadIdentity;
    glad_debug_glLoadMatrixd = glad_glLoadMatrixd;
    glad_debug_glLoadMatrixf = glad_glLoadMatrixf;
    glad_debug_glLoadName = glad_glLoadName;
    glad_debug_glLoadProgramNV = glad_glLoadProgramNV;
    glad_debug_glLoadTransposeMatrixd = glad_glLoadTransposeMatrixd;
    glad_debug_glLoadTransposeMatrixdARB = glad_glLoadTransposeMatrixdARB;
    glad_debug_glLoadTransposeMatrixf = glad_glLoadTransposeMatrixf;
    glad_debug_glLoadTransposeMatrixfARB = glad_glLoadTransposeMatrixfARB;
    glad_debug_glLogicOp = glad_glLogicOp;
    glad_debug_glMap1d = glad_glMap1d;
    glad_debug_glMap1f = glad_glMap1f;
    glad_debug_glMap2d = glad_glMap2d;
    glad_debug_glMap2f = glad_glMap2f;
    glad_debug_glMapBuffer = glad_glMapBuffer;
    glad_debug_glMapBufferARB = glad_glMapBufferARB;
    glad_debug_glMapGrid1d = glad_glMapGrid1d;
    glad_debug_glMapGrid1f = glad_glMapGrid1f;
    glad_debug_glMapGrid2d = glad_glMapGrid2d;
    glad_debug_glMapGrid2f = glad_glMapGrid2f;
    glad_debug_glMaterialf = glad_glMaterialf;
    glad_debug_glMaterialfv = glad_glMaterialfv;
    glad_debug_glMateriali = glad_glMateriali;
    glad_debug_glMaterialiv = glad_glMaterialiv;
    glad_debug_glMatrixMode = glad_glMatrixMode;
    glad_debug_glMinmax = glad_glMinmax;
    glad_debug_glMultMatrixd = glad_glMultMatrixd;
    glad_debug_glMultMatrixf = glad_glMultMatrixf;
    glad_debug_glMultTransposeMatrixd = glad_glMultTransposeMatrixd;
    glad_debug_glMultTransposeMatrixdARB = glad_glMultTransposeMatrixdARB;
    glad_debug_glMultTransposeMatrixf = glad_glMultTransposeMatrixf;
    glad_debug_glMultTransposeMatrixfARB = glad_glMultTransposeMatrixfARB;
    glad_debug_glMultiDrawArrays = glad_glMultiDrawArrays;
    glad_debug_glMultiDrawArraysEXT = glad_glMultiDrawArraysEXT;
    glad_debug_glMultiDrawElements = glad_glMultiDrawElements;
    glad_debug_glMultiDrawElementsEXT = glad_glMultiDrawElementsEXT;
    glad_debug_glMultiTexCoord1d = glad_glMultiTexCoord1d;
    glad_debug_glMultiTexCoord1dARB = glad_glMultiTexCoord1dARB;
    glad_debug_glMultiTexCoord1dv = glad_glMultiTexCoord1dv;
    glad_debug_glMultiTexCoord1dvARB = glad_glMultiTexCoord1dvARB;
    glad_debug_glMultiTexCoord1f = glad_glMultiTexCoord1f;
    glad_debug_glMultiTexCoord1fARB = glad_glMultiTexCoord1fARB;
    glad_debug_glMultiTexCoord1fv = glad_glMultiTexCoord1fv;
    glad_debug_glMultiTexCoord1fvARB = glad_glMultiTexCoord1fvARB;
    glad_debug_glMultiTexCoord1i = glad_glMultiTexCoord1i;
    glad_debug_glMultiTexCoord1iARB = glad_glMultiTexCoord1iARB;
    glad_debug_glMultiTexCoord1iv = glad_glMultiTexCoord1iv;
    glad_debug_glMultiTexCoord1ivARB = glad_glMultiTexCoord1ivARB;
    glad_debug_glMultiTexCoord1s = glad_glMultiTexCoord1s;
    glad_debug_glMultiTexCoord1sARB = glad_glMultiTexCoord1sARB;
    glad_debug_glMultiTexCoord1sv = glad_glMultiTexCoord1sv;
    glad_debug_glMultiTexCoord1svARB = glad_glMultiTexCoord1svARB;
    glad_debug_glMultiTexCoord2d = glad_glMultiTexCoord2d;
    glad_debug_glMultiTexCoord2dARB = glad_glMultiTexCoord2dARB;
    glad_debug_glMultiTexCoord2dv = glad_glMultiTexCoord2dv;
    glad_debug_glMultiTexCoord2dvARB = glad_glMultiTexCoord2dvARB;
    glad_debug_glMultiTexCoord2f = glad_glMultiTexCoord2f;
    glad_debug_glMultiTexCoord2fARB = glad_glMultiTexCoord2fARB;
    glad_debug_glMultiTexCoord2fv = glad_glMultiTexCoord2fv;
    glad_debug_glMultiTexCoord2fvARB = glad_glMultiTexCoord2fvARB;
    glad_debug_glMultiTexCoord2i = glad_glMultiTexCoord2i;
    glad_debug_glMultiTexCoord2iARB = glad_glMultiTexCoord2iARB;
    glad_debug_glMultiTexCoord2iv = glad_glMultiTexCoord2iv;
    glad_debug_glMultiTexCoord2ivARB = glad_glMultiTexCoord2ivARB;
    glad_debug_glMultiTexCoord2s = glad_glMultiTexCoord2s;
    glad_debug_glMultiTexCoord2sARB = glad_glMultiTexCoord2sARB;
    glad_debug_glMultiTexCoord2sv = glad_glMultiTexCoord2sv;
    glad_debug_glMultiTexCoord2svARB = glad_glMultiTexCoord2svARB;
    glad_debug_glMultiTexCoord3d = glad_glMultiTexCoord3d;
    glad_debug_glMultiTexCoord3dARB = glad_glMultiTexCoord3dARB;
    glad_debug_glMultiTexCoord3dv = glad_glMultiTexCoord3dv;
    glad_debug_glMultiTexCoord3dvARB = glad_glMultiTexCoord3dvARB;
    glad_debug_glMultiTexCoord3f = glad_glMultiTexCoord3f;
    glad_debug_glMultiTexCoord3fARB = glad_glMultiTexCoord3fARB;
    glad_debug_glMultiTexCoord3fv = glad_glMultiTexCoord3fv;
    glad_debug_glMultiTexCoord3fvARB = glad_glMultiTexCoord3fvARB;
    glad_debug_glMultiTexCoord3i = glad_glMultiTexCoord3i;
    glad_debug_glMultiTexCoord3iARB = glad_glMultiTexCoord3iARB;
    glad_debug_glMultiTexCoord3iv = glad_glMultiTexCoord3iv;
    glad_debug_glMultiTexCoord3ivARB = glad_glMultiTexCoord3ivARB;
    glad_debug_glMultiTexCoord3s = glad_glMultiTexCoord3s;
    glad_debug_glMultiTexCoord3sARB = glad_glMultiTexCoord3sARB;
    glad_debug_glMultiTexCoord3sv = glad_glMultiTexCoord3sv;
    glad_debug_glMultiTexCoord3svARB = glad_glMultiTexCoord3svARB;
    glad_debug_glMultiTexCoord4d = glad_glMultiTexCoord4d;
    glad_debug_glMultiTexCoord4dARB = glad_glMultiTexCoord4dARB;
    glad_debug_glMultiTexCoord4dv = glad_glMultiTexCoord4dv;
    glad_debug_glMultiTexCoord4dvARB = glad_glMultiTexCoord4dvARB;
    glad_debug_glMultiTexCoord4f = glad_glMultiTexCoord4f;
    glad_debug_glMultiTexCoord4fARB = glad_glMultiTexCoord4fARB;
    glad_debug_glMultiTexCoord4fv = glad_glMultiTexCoord4fv;
    glad_debug_glMultiTexCoord4fvARB = glad_glMultiTexCoord4fvARB;
    glad_debug_glMultiTexCoord4i = glad_glMultiTexCoord4i;
    glad_debug_glMultiTexCoord4iARB = glad_glMultiTexCoord4iARB;
    glad_debug_glMultiTexCoord4iv = glad_glMultiTexCoord4iv;
    glad_debug_glMultiTexCoord4ivARB = glad_glMultiTexCoord4ivARB;
    glad_debug_glMultiTexCoord4s = glad_glMultiTexCoord4s;
    glad_debug_glMultiTexCoord4sARB = glad_glMultiTexCoord4sARB;
    glad_debug_glMultiTexCoord4sv = glad_glMultiTexCoord4sv;
    glad_debug_glMultiTexCoord4svARB = glad_glMultiTexCoord4svARB;
    glad_debug_glNewList = glad_glNewList;
    glad_debug_glNormal3b = glad_glNormal3b;
    glad_debug_glNormal3bv = glad_glNormal3bv;
    glad_debug_glNormal3d = glad_glNormal3d;
    glad_debug_glNormal3dv = glad_glNormal3dv;
    glad_debug_glNormal3f = glad_glNormal3f;
    glad_debug_glNormal3fv = glad_glNormal3fv;
    glad_debug_glNormal3i = glad_glNormal3i;
    glad_debug_glNormal3iv = glad_glNormal3iv;
    glad_debug_glNormal3s = glad_glNormal3s;
    glad_debug_glNormal3sv = glad_glNormal3sv;
    glad_debug_glNormalPointer = glad_glNormalPointer;
    glad_debug_glNormalPointerEXT = glad_glNormalPointerEXT;
    glad_debug_glObjectLabel = glad_glObjectLabel;
    glad_debug_glObjectPtrLabel = glad_glObjectPtrLabel;
    glad_debug_glOrtho = glad_glOrtho;
    glad_debug_glPassThrough = glad_glPassThrough;
    glad_debug_glPixelMapfv = glad_glPixelMapfv;
    glad_debug_glPixelMapuiv = glad_glPixelMapuiv;
    glad_debug_glPixelMapusv = glad_glPixelMapusv;
    glad_debug_glPixelStoref = glad_glPixelStoref;
    glad_debug_glPixelStorei = glad_glPixelStorei;
    glad_debug_glPixelTransferf = glad_glPixelTransferf;
    glad_debug_glPixelTransferi = glad_glPixelTransferi;
    glad_debug_glPixelZoom = glad_glPixelZoom;
    glad_debug_glPointParameterf = glad_glPointParameterf;
    glad_debug_glPointParameterfARB = glad_glPointParameterfARB;
    glad_debug_glPointParameterfEXT = glad_glPointParameterfEXT;
    glad_debug_glPointParameterfSGIS = glad_glPointParameterfSGIS;
    glad_debug_glPointParameterfv = glad_glPointParameterfv;
    glad_debug_glPointParameterfvARB = glad_glPointParameterfvARB;
    glad_debug_glPointParameterfvEXT = glad_glPointParameterfvEXT;
    glad_debug_glPointParameterfvSGIS = glad_glPointParameterfvSGIS;
    glad_debug_glPointParameteri = glad_glPointParameteri;
    glad_debug_glPointParameteriNV = glad_glPointParameteriNV;
    glad_debug_glPointParameteriv = glad_glPointParameteriv;
    glad_debug_glPointParameterivNV = glad_glPointParameterivNV;
    glad_debug_glPointSize = glad_glPointSize;
    glad_debug_glPolygonMode = glad_glPolygonMode;
    glad_debug_glPolygonOffset = glad_glPolygonOffset;
    glad_debug_glPolygonStipple = glad_glPolygonStipple;
    glad_debug_glPopAttrib = glad_glPopAttrib;
    glad_debug_glPopClientAttrib = glad_glPopClientAttrib;
    glad_debug_glPopDebugGroup = glad_glPopDebugGroup;
    glad_debug_glPopMatrix = glad_glPopMatrix;
    glad_debug_glPopName = glad_glPopName;
    glad_debug_glPrioritizeTextures = glad_glPrioritizeTextures;
    glad_debug_glPrioritizeTexturesEXT = glad_glPrioritizeTexturesEXT;
    glad_debug_glProgramEnvParameter4dARB = glad_glProgramEnvParameter4dARB;
    glad_debug_glProgramEnvParameter4dvARB = glad_glProgramEnvParameter4dvARB;
    glad_debug_glProgramEnvParameter4fARB = glad_glProgramEnvParameter4fARB;
    glad_debug_glProgramEnvParameter4fvARB = glad_glProgramEnvParameter4fvARB;
    glad_debug_glProgramLocalParameter4dARB = glad_glProgramLocalParameter4dARB;
    glad_debug_glProgramLocalParameter4dvARB = glad_glProgramLocalParameter4dvARB;
    glad_debug_glProgramLocalParameter4fARB = glad_glProgramLocalParameter4fARB;
    glad_debug_glProgramLocalParameter4fvARB = glad_glProgramLocalParameter4fvARB;
    glad_debug_glProgramParameter4dNV = glad_glProgramParameter4dNV;
    glad_debug_glProgramParameter4dvNV = glad_glProgramParameter4dvNV;
    glad_debug_glProgramParameter4fNV = glad_glProgramParameter4fNV;
    glad_debug_glProgramParameter4fvNV = glad_glProgramParameter4fvNV;
    glad_debug_glProgramParameters4dvNV = glad_glProgramParameters4dvNV;
    glad_debug_glProgramParameters4fvNV = glad_glProgramParameters4fvNV;
    glad_debug_glProgramStringARB = glad_glProgramStringARB;
    glad_debug_glPushAttrib = glad_glPushAttrib;
    glad_debug_glPushClientAttrib = glad_glPushClientAttrib;
    glad_debug_glPushDebugGroup = glad_glPushDebugGroup;
    glad_debug_glPushMatrix = glad_glPushMatrix;
    glad_debug_glPushName = glad_glPushName;
    glad_debug_glRasterPos2d = glad_glRasterPos2d;
    glad_debug_glRasterPos2dv = glad_glRasterPos2dv;
    glad_debug_glRasterPos2f = glad_glRasterPos2f;
    glad_debug_glRasterPos2fv = glad_glRasterPos2fv;
    glad_debug_glRasterPos2i = glad_glRasterPos2i;
    glad_debug_glRasterPos2iv = glad_glRasterPos2iv;
    glad_debug_glRasterPos2s = glad_glRasterPos2s;
    glad_debug_glRasterPos2sv = glad_glRasterPos2sv;
    glad_debug_glRasterPos3d = glad_glRasterPos3d;
    glad_debug_glRasterPos3dv = glad_glRasterPos3dv;
    glad_debug_glRasterPos3f = glad_glRasterPos3f;
    glad_debug_glRasterPos3fv = glad_glRasterPos3fv;
    glad_debug_glRasterPos3i = glad_glRasterPos3i;
    glad_debug_glRasterPos3iv = glad_glRasterPos3iv;
    glad_debug_glRasterPos3s = glad_glRasterPos3s;
    glad_debug_glRasterPos3sv = glad_glRasterPos3sv;
    glad_debug_glRasterPos4d = glad_glRasterPos4d;
    glad_debug_glRasterPos4dv = glad_glRasterPos4dv;
    glad_debug_glRasterPos4f = glad_glRasterPos4f;
    glad_debug_glRasterPos4fv = glad_glRasterPos4fv;
    glad_debug_glRasterPos4i = glad_glRasterPos4i;
    glad_debug_glRasterPos4iv = glad_glRasterPos4iv;
    glad_debug_glRasterPos4s = glad_glRasterPos4s;
    glad_debug_glRasterPos4sv = glad_glRasterPos4sv;
    glad_debug_glReadBuffer = glad_glReadBuffer;
    glad_debug_glReadPixels = glad_glReadPixels;
    glad_debug_glRectd = glad_glRectd;
    glad_debug_glRectdv = glad_glRectdv;
    glad_debug_glRectf = glad_glRectf;
    glad_debug_glRectfv = glad_glRectfv;
    glad_debug_glRecti = glad_glRecti;
    glad_debug_glRectiv = glad_glRectiv;
    glad_debug_glRects = glad_glRects;
    glad_debug_glRectsv = glad_glRectsv;
    glad_debug_glRenderMode = glad_glRenderMode;
    glad_debug_glRequestResidentProgramsNV = glad_glRequestResidentProgramsNV;
    glad_debug_glResetHistogram = glad_glResetHistogram;
    glad_debug_glResetMinmax = glad_glResetMinmax;
    glad_debug_glRotated = glad_glRotated;
    glad_debug_glRotatef = glad_glRotatef;
    glad_debug_glSampleCoverage = glad_glSampleCoverage;
    glad_debug_glSampleCoverageARB = glad_glSampleCoverageARB;
    glad_debug_glScaled = glad_glScaled;
    glad_debug_glScalef = glad_glScalef;
    glad_debug_glScissor = glad_glScissor;
    glad_debug_glSecondaryColor3b = glad_glSecondaryColor3b;
    glad_debug_glSecondaryColor3bEXT = glad_glSecondaryColor3bEXT;
    glad_debug_glSecondaryColor3bv = glad_glSecondaryColor3bv;
    glad_debug_glSecondaryColor3bvEXT = glad_glSecondaryColor3bvEXT;
    glad_debug_glSecondaryColor3d = glad_glSecondaryColor3d;
    glad_debug_glSecondaryColor3dEXT = glad_glSecondaryColor3dEXT;
    glad_debug_glSecondaryColor3dv = glad_glSecondaryColor3dv;
    glad_debug_glSecondaryColor3dvEXT = glad_glSecondaryColor3dvEXT;
    glad_debug_glSecondaryColor3f = glad_glSecondaryColor3f;
    glad_debug_glSecondaryColor3fEXT = glad_glSecondaryColor3fEXT;
    glad_debug_glSecondaryColor3fv = glad_glSecondaryColor3fv;
    glad_debug_glSecondaryColor3fvEXT = glad_glSecondaryColor3fvEXT;
    glad_debug_glSecondaryColor3i = glad_glSecondaryColor3i;
    glad_debug_glSecondaryColor3iEXT = glad_glSecondaryColor3iEXT;
    glad_debug_glSecondaryColor3iv = glad_glSecondaryColor3iv;
    glad_debug_glSecondaryColor3ivEXT = glad_glSecondaryColor3ivEXT;
    glad_debug_glSecondaryColor3s = glad_glSecondaryColor3s;
    glad_debug_glSecondaryColor3sEXT = glad_glSecondaryColor3sEXT;
    glad_debug_glSecondaryColor3sv = glad_glSecondaryColor3sv;
    glad_debug_glSecondaryColor3svEXT = glad_glSecondaryColor3svEXT;
    glad_debug_glSecondaryColor3ub = glad_glSecondaryColor3ub;
    glad_debug_glSecondaryColor3ubEXT = glad_glSecondaryColor3ubEXT;
    glad_debug_glSecondaryColor3ubv = glad_glSecondaryColor3ubv;
    glad_debug_glSecondaryColor3ubvEXT = glad_glSecondaryColor3ubvEXT;
    glad_debug_glSecondaryColor3ui = glad_glSecondaryColor3ui;
    glad_debug_glSecondaryColor3uiEXT = glad_glSecondaryColor3uiEXT;
    glad_debug_glSecondaryColor3uiv = glad_glSecondaryColor3uiv;
    glad_debug_glSecondaryColor3uivEXT = glad_glSecondaryColor3uivEXT;
    glad_debug_glSecondaryColor3us = glad_glSecondaryColor3us;
    glad_debug_glSecondaryColor3usEXT = glad_glSecondaryColor3usEXT;
    glad_debug_glSecondaryColor3usv = glad_glSecondaryColor3usv;
    glad_debug_glSecondaryColor3usvEXT = glad_glSecondaryColor3usvEXT;
    glad_debug_glSecondaryColorPointer = glad_glSecondaryColorPointer;
    glad_debug_glSecondaryColorPointerEXT = glad_glSecondaryColorPointerEXT;
    glad_debug_glSelectBuffer = glad_glSelectBuffer;
    glad_debug_glSeparableFilter2D = glad_glSeparableFilter2D;
    glad_debug_glShadeModel = glad_glShadeModel;
    glad_debug_glShaderSource = glad_glShaderSource;
    glad_debug_glShaderSourceARB = glad_glShaderSourceARB;
    glad_debug_glStencilFunc = glad_glStencilFunc;
    glad_debug_glStencilFuncSeparate = glad_glStencilFuncSeparate;
    glad_debug_glStencilFuncSeparateATI = glad_glStencilFuncSeparateATI;
    glad_debug_glStencilMask = glad_glStencilMask;
    glad_debug_glStencilMaskSeparate = glad_glStencilMaskSeparate;
    glad_debug_glStencilOp = glad_glStencilOp;
    glad_debug_glStencilOpSeparate = glad_glStencilOpSeparate;
    glad_debug_glStencilOpSeparateATI = glad_glStencilOpSeparateATI;
    glad_debug_glTexCoord1d = glad_glTexCoord1d;
    glad_debug_glTexCoord1dv = glad_glTexCoord1dv;
    glad_debug_glTexCoord1f = glad_glTexCoord1f;
    glad_debug_glTexCoord1fv = glad_glTexCoord1fv;
    glad_debug_glTexCoord1i = glad_glTexCoord1i;
    glad_debug_glTexCoord1iv = glad_glTexCoord1iv;
    glad_debug_glTexCoord1s = glad_glTexCoord1s;
    glad_debug_glTexCoord1sv = glad_glTexCoord1sv;
    glad_debug_glTexCoord2d = glad_glTexCoord2d;
    glad_debug_glTexCoord2dv = glad_glTexCoord2dv;
    glad_debug_glTexCoord2f = glad_glTexCoord2f;
    glad_debug_glTexCoord2fv = glad_glTexCoord2fv;
    glad_debug_glTexCoord2i = glad_glTexCoord2i;
    glad_debug_glTexCoord2iv = glad_glTexCoord2iv;
    glad_debug_glTexCoord2s = glad_glTexCoord2s;
    glad_debug_glTexCoord2sv = glad_glTexCoord2sv;
    glad_debug_glTexCoord3d = glad_glTexCoord3d;
    glad_debug_glTexCoord3dv = glad_glTexCoord3dv;
    glad_debug_glTexCoord3f = glad_glTexCoord3f;
    glad_debug_glTexCoord3fv = glad_glTexCoord3fv;
    glad_debug_glTexCoord3i = glad_glTexCoord3i;
    glad_debug_glTexCoord3iv = glad_glTexCoord3iv;
    glad_debug_glTexCoord3s = glad_glTexCoord3s;
    glad_debug_glTexCoord3sv = glad_glTexCoord3sv;
    glad_debug_glTexCoord4d = glad_glTexCoord4d;
    glad_debug_glTexCoord4dv = glad_glTexCoord4dv;
    glad_debug_glTexCoord4f = glad_glTexCoord4f;
    glad_debug_glTexCoord4fv = glad_glTexCoord4fv;
    glad_debug_glTexCoord4i = glad_glTexCoord4i;
    glad_debug_glTexCoord4iv = glad_glTexCoord4iv;
    glad_debug_glTexCoord4s = glad_glTexCoord4s;
    glad_debug_glTexCoord4sv = glad_glTexCoord4sv;
    glad_debug_glTexCoordPointer = glad_glTexCoordPointer;
    glad_debug_glTexCoordPointerEXT = glad_glTexCoordPointerEXT;
    glad_debug_glTexEnvf = glad_glTexEnvf;
    glad_debug_glTexEnvfv = glad_glTexEnvfv;
    glad_debug_glTexEnvi = glad_glTexEnvi;
    glad_debug_glTexEnviv = glad_glTexEnviv;
    glad_debug_glTexGend = glad_glTexGend;
    glad_debug_glTexGendv = glad_glTexGendv;
    glad_debug_glTexGenf = glad_glTexGenf;
    glad_debug_glTexGenfv = glad_glTexGenfv;
    glad_debug_glTexGeni = glad_glTexGeni;
    glad_debug_glTexGeniv = glad_glTexGeniv;
    glad_debug_glTexImage1D = glad_glTexImage1D;
    glad_debug_glTexImage2D = glad_glTexImage2D;
    glad_debug_glTexImage3D = glad_glTexImage3D;
    glad_debug_glTexImage3DEXT = glad_glTexImage3DEXT;
    glad_debug_glTexParameterf = glad_glTexParameterf;
    glad_debug_glTexParameterfv = glad_glTexParameterfv;
    glad_debug_glTexParameteri = glad_glTexParameteri;
    glad_debug_glTexParameteriv = glad_glTexParameteriv;
    glad_debug_glTexSubImage1D = glad_glTexSubImage1D;
    glad_debug_glTexSubImage1DEXT = glad_glTexSubImage1DEXT;
    glad_debug_glTexSubImage2D = glad_glTexSubImage2D;
    glad_debug_glTexSubImage2DEXT = glad_glTexSubImage2DEXT;
    glad_debug_glTexSubImage3D = glad_glTexSubImage3D;
    glad_debug_glTexSubImage3DEXT = glad_glTexSubImage3DEXT;
    glad_debug_glTrackMatrixNV = glad_glTrackMatrixNV;
    glad_debug_glTranslated = glad_glTranslated;
    glad_debug_glTranslatef = glad_glTranslatef;
    glad_debug_glUniform1f = glad_glUniform1f;
    glad_debug_glUniform1fARB = glad_glUniform1fARB;
    glad_debug_glUniform1fv = glad_glUniform1fv;
    glad_debug_glUniform1fvARB = glad_glUniform1fvARB;
    glad_debug_glUniform1i = glad_glUniform1i;
    glad_debug_glUniform1iARB = glad_glUniform1iARB;
    glad_debug_glUniform1iv = glad_glUniform1iv;
    glad_debug_glUniform1ivARB = glad_glUniform1ivARB;
    glad_debug_glUniform2f = glad_glUniform2f;
    glad_debug_glUniform2fARB = glad_glUniform2fARB;
    glad_debug_glUniform2fv = glad_glUniform2fv;
    glad_debug_glUniform2fvARB = glad_glUniform2fvARB;
    glad_debug_glUniform2i = glad_glUniform2i;
    glad_debug_glUniform2iARB = glad_glUniform2iARB;
    glad_debug_glUniform2iv = glad_glUniform2iv;
    glad_debug_glUniform2ivARB = glad_glUniform2ivARB;
    glad_debug_glUniform3f = glad_glUniform3f;
    glad_debug_glUniform3fARB = glad_glUniform3fARB;
    glad_debug_glUniform3fv = glad_glUniform3fv;
    glad_debug_glUniform3fvARB = glad_glUniform3fvARB;
    glad_debug_glUniform3i = glad_glUniform3i;
    glad_debug_glUniform3iARB = glad_glUniform3iARB;
    glad_debug_glUniform3iv = glad_glUniform3iv;
    glad_debug_glUniform3ivARB = glad_glUniform3ivARB;
    glad_debug_glUniform4f = glad_glUniform4f;
    glad_debug_glUniform4fARB = glad_glUniform4fARB;
    glad_debug_glUniform4fv = glad_glUniform4fv;
    glad_debug_glUniform4fvARB = glad_glUniform4fvARB;
    glad_debug_glUniform4i = glad_glUniform4i;
    glad_debug_glUniform4iARB = glad_glUniform4iARB;
    glad_debug_glUniform4iv = glad_glUniform4iv;
    glad_debug_glUniform4ivARB = glad_glUniform4ivARB;
    glad_debug_glUniformMatrix2fv = glad_glUniformMatrix2fv;
    glad_debug_glUniformMatrix2fvARB = glad_glUniformMatrix2fvARB;
    glad_debug_glUniformMatrix2x3fv = glad_glUniformMatrix2x3fv;
    glad_debug_glUniformMatrix2x4fv = glad_glUniformMatrix2x4fv;
    glad_debug_glUniformMatrix3fv = glad_glUniformMatrix3fv;
    glad_debug_glUniformMatrix3fvARB = glad_glUniformMatrix3fvARB;
    glad_debug_glUniformMatrix3x2fv = glad_glUniformMatrix3x2fv;
    glad_debug_glUniformMatrix3x4fv = glad_glUniformMatrix3x4fv;
    glad_debug_glUniformMatrix4fv = glad_glUniformMatrix4fv;
    glad_debug_glUniformMatrix4fvARB = glad_glUniformMatrix4fvARB;
    glad_debug_glUniformMatrix4x2fv = glad_glUniformMatrix4x2fv;
    glad_debug_glUniformMatrix4x3fv = glad_glUniformMatrix4x3fv;
    glad_debug_glUnmapBuffer = glad_glUnmapBuffer;
    glad_debug_glUnmapBufferARB = glad_glUnmapBufferARB;
    glad_debug_glUseProgram = glad_glUseProgram;
    glad_debug_glUseProgramObjectARB = glad_glUseProgramObjectARB;
    glad_debug_glValidateProgram = glad_glValidateProgram;
    glad_debug_glValidateProgramARB = glad_glValidateProgramARB;
    glad_debug_glVertex2d = glad_glVertex2d;
    glad_debug_glVertex2dv = glad_glVertex2dv;
    glad_debug_glVertex2f = glad_glVertex2f;
    glad_debug_glVertex2fv = glad_glVertex2fv;
    glad_debug_glVertex2i = glad_glVertex2i;
    glad_debug_glVertex2iv = glad_glVertex2iv;
    glad_debug_glVertex2s = glad_glVertex2s;
    glad_debug_glVertex2sv = glad_glVertex2sv;
    glad_debug_glVertex3d = glad_glVertex3d;
    glad_debug_glVertex3dv = glad_glVertex3dv;
    glad_debug_glVertex3f = glad_glVertex3f;
    glad_debug_glVertex3fv = glad_glVertex3fv;
    glad_debug_glVertex3i = glad_glVertex3i;
    glad_debug_glVertex3iv = glad_glVertex3iv;
    glad_debug_glVertex3s = glad_glVertex3s;
    glad_debug_glVertex3sv = glad_glVertex3sv;
    glad_debug_glVertex4d = glad_glVertex4d;
    glad_debug_glVertex4dv = glad_glVertex4dv;
    glad_debug_glVertex4f = glad_glVertex4f;
    glad_debug_glVertex4fv = glad_glVertex4fv;
    glad_debug_glVertex4i = glad_glVertex4i;
    glad_debug_glVertex4iv = glad_glVertex4iv;
    glad_debug_glVertex4s = glad_glVertex4s;
    glad_debug_glVertex4sv = glad_glVertex4sv;
    glad_debug_glVertexAttrib1d = glad_glVertexAttrib1d;
    glad_debug_glVertexAttrib1dARB = glad_glVertexAttrib1dARB;
    glad_debug_glVertexAttrib1dNV = glad_glVertexAttrib1dNV;
    glad_debug_glVertexAttrib1dv = glad_glVertexAttrib1dv;
    glad_debug_glVertexAttrib1dvARB = glad_glVertexAttrib1dvARB;
    glad_debug_glVertexAttrib1dvNV = glad_glVertexAttrib1dvNV;
    glad_debug_glVertexAttrib1f = glad_glVertexAttrib1f;
    glad_debug_glVertexAttrib1fARB = glad_glVertexAttrib1fARB;
    glad_debug_glVertexAttrib1fNV = glad_glVertexAttrib1fNV;
    glad_debug_glVertexAttrib1fv = glad_glVertexAttrib1fv;
    glad_debug_glVertexAttrib1fvARB = glad_glVertexAttrib1fvARB;
    glad_debug_glVertexAttrib1fvNV = glad_glVertexAttrib1fvNV;
    glad_debug_glVertexAttrib1s = glad_glVertexAttrib1s;
    glad_debug_glVertexAttrib1sARB = glad_glVertexAttrib1sARB;
    glad_debug_glVertexAttrib1sNV = glad_glVertexAttrib1sNV;
    glad_debug_glVertexAttrib1sv = glad_glVertexAttrib1sv;
    glad_debug_glVertexAttrib1svARB = glad_glVertexAttrib1svARB;
    glad_debug_glVertexAttrib1svNV = glad_glVertexAttrib1svNV;
    glad_debug_glVertexAttrib2d = glad_glVertexAttrib2d;
    glad_debug_glVertexAttrib2dARB = glad_glVertexAttrib2dARB;
    glad_debug_glVertexAttrib2dNV = glad_glVertexAttrib2dNV;
    glad_debug_glVertexAttrib2dv = glad_glVertexAttrib2dv;
    glad_debug_glVertexAttrib2dvARB = glad_glVertexAttrib2dvARB;
    glad_debug_glVertexAttrib2dvNV = glad_glVertexAttrib2dvNV;
    glad_debug_glVertexAttrib2f = glad_glVertexAttrib2f;
    glad_debug_glVertexAttrib2fARB = glad_glVertexAttrib2fARB;
    glad_debug_glVertexAttrib2fNV = glad_glVertexAttrib2fNV;
    glad_debug_glVertexAttrib2fv = glad_glVertexAttrib2fv;
    glad_debug_glVertexAttrib2fvARB = glad_glVertexAttrib2fvARB;
    glad_debug_glVertexAttrib2fvNV = glad_glVertexAttrib2fvNV;
    glad_debug_glVertexAttrib2s = glad_glVertexAttrib2s;
    glad_debug_glVertexAttrib2sARB = glad_glVertexAttrib2sARB;
    glad_debug_glVertexAttrib2sNV = glad_glVertexAttrib2sNV;
    glad_debug_glVertexAttrib2sv = glad_glVertexAttrib2sv;
    glad_debug_glVertexAttrib2svARB = glad_glVertexAttrib2svARB;
    glad_debug_glVertexAttrib2svNV = glad_glVertexAttrib2svNV;
    glad_debug_glVertexAttrib3d = glad_glVertexAttrib3d;
    glad_debug_glVertexAttrib3dARB = glad_glVertexAttrib3dARB;
    glad_debug_glVertexAttrib3dNV = glad_glVertexAttrib3dNV;
    glad_debug_glVertexAttrib3dv = glad_glVertexAttrib3dv;
    glad_debug_glVertexAttrib3dvARB = glad_glVertexAttrib3dvARB;
    glad_debug_glVertexAttrib3dvNV = glad_glVertexAttrib3dvNV;
    glad_debug_glVertexAttrib3f = glad_glVertexAttrib3f;
    glad_debug_glVertexAttrib3fARB = glad_glVertexAttrib3fARB;
    glad_debug_glVertexAttrib3fNV = glad_glVertexAttrib3fNV;
    glad_debug_glVertexAttrib3fv = glad_glVertexAttrib3fv;
    glad_debug_glVertexAttrib3fvARB = glad_glVertexAttrib3fvARB;
    glad_debug_glVertexAttrib3fvNV = glad_glVertexAttrib3fvNV;
    glad_debug_glVertexAttrib3s = glad_glVertexAttrib3s;
    glad_debug_glVertexAttrib3sARB = glad_glVertexAttrib3sARB;
    glad_debug_glVertexAttrib3sNV = glad_glVertexAttrib3sNV;
    glad_debug_glVertexAttrib3sv = glad_glVertexAttrib3sv;
    glad_debug_glVertexAttrib3svARB = glad_glVertexAttrib3svARB;
    glad_debug_glVertexAttrib3svNV = glad_glVertexAttrib3svNV;
    glad_debug_glVertexAttrib4Nbv = glad_glVertexAttrib4Nbv;
    glad_debug_glVertexAttrib4NbvARB = glad_glVertexAttrib4NbvARB;
    glad_debug_glVertexAttrib4Niv = glad_glVertexAttrib4Niv;
    glad_debug_glVertexAttrib4NivARB = glad_glVertexAttrib4NivARB;
    glad_debug_glVertexAttrib4Nsv = glad_glVertexAttrib4Nsv;
    glad_debug_glVertexAttrib4NsvARB = glad_glVertexAttrib4NsvARB;
    glad_debug_glVertexAttrib4Nub = glad_glVertexAttrib4Nub;
    glad_debug_glVertexAttrib4NubARB = glad_glVertexAttrib4NubARB;
    glad_debug_glVertexAttrib4Nubv = glad_glVertexAttrib4Nubv;
    glad_debug_glVertexAttrib4NubvARB = glad_glVertexAttrib4NubvARB;
    glad_debug_glVertexAttrib4Nuiv = glad_glVertexAttrib4Nuiv;
    glad_debug_glVertexAttrib4NuivARB = glad_glVertexAttrib4NuivARB;
    glad_debug_glVertexAttrib4Nusv = glad_glVertexAttrib4Nusv;
    glad_debug_glVertexAttrib4NusvARB = glad_glVertexAttrib4NusvARB;
    glad_debug_glVertexAttrib4bv = glad_glVertexAttrib4bv;
    glad_debug_glVertexAttrib4bvARB = glad_glVertexAttrib4bvARB;
    glad_debug_glVertexAttrib4d = glad_glVertexAttrib4d;
    glad_debug_glVertexAttrib4dARB = glad_glVertexAttrib4dARB;
    glad_debug_glVertexAttrib4dNV = glad_glVertexAttrib4dNV;
    glad_debug_glVertexAttrib4dv = glad_glVertexAttrib4dv;
    glad_debug_glVertexAttrib4dvARB = glad_glVertexAttrib4dvARB;
    glad_debug_glVertexAttrib4dvNV = glad_glVertexAttrib4dvNV;
    glad_debug_glVertexAttrib4f = glad_glVertexAttrib4f;
    glad_debug_glVertexAttrib4fARB = glad_glVertexAttrib4fARB;
    glad_debug_glVertexAttrib4fNV = glad_glVertexAttrib4fNV;
    glad_debug_glVertexAttrib4fv = glad_glVertexAttrib4fv;
    glad_debug_glVertexAttrib4fvARB = glad_glVertexAttrib4fvARB;
    glad_debug_glVertexAttrib4fvNV = glad_glVertexAttrib4fvNV;
    glad_debug_glVertexAttrib4iv = glad_glVertexAttrib4iv;
    glad_debug_glVertexAttrib4ivARB = glad_glVertexAttrib4ivARB;
    glad_debug_glVertexAttrib4s = glad_glVertexAttrib4s;
    glad_debug_glVertexAttrib4sARB = glad_glVertexAttrib4sARB;
    glad_debug_glVertexAttrib4sNV = glad_glVertexAttrib4sNV;
    glad_debug_glVertexAttrib4sv = glad_glVertexAttrib4sv;
    glad_debug_glVertexAttrib4svARB = glad_glVertexAttrib4svARB;
    glad_debug_glVertexAttrib4svNV = glad_glVertexAttrib4svNV;
    glad_debug_glVertexAttrib4ubNV = glad_glVertexAttrib4ubNV;
    glad_debug_glVertexAttrib4ubv = glad_glVertexAttrib4ubv;
    glad_debug_glVertexAttrib4ubvARB = glad_glVertexAttrib4ubvARB;
    glad_debug_glVertexAttrib4ubvNV = glad_glVertexAttrib4ubvNV;
    glad_debug_glVertexAttrib4uiv = glad_glVertexAttrib4uiv;
    glad_debug_glVertexAttrib4uivARB = glad_glVertexAttrib4uivARB;
    glad_debug_glVertexAttrib4usv = glad_glVertexAttrib4usv;
    glad_debug_glVertexAttrib4usvARB = glad_glVertexAttrib4usvARB;
    glad_debug_glVertexAttribPointer = glad_glVertexAttribPointer;
    glad_debug_glVertexAttribPointerARB = glad_glVertexAttribPointerARB;
    glad_debug_glVertexAttribPointerNV = glad_glVertexAttribPointerNV;
    glad_debug_glVertexAttribs1dvNV = glad_glVertexAttribs1dvNV;
    glad_debug_glVertexAttribs1fvNV = glad_glVertexAttribs1fvNV;
    glad_debug_glVertexAttribs1svNV = glad_glVertexAttribs1svNV;
    glad_debug_glVertexAttribs2dvNV = glad_glVertexAttribs2dvNV;
    glad_debug_glVertexAttribs2fvNV = glad_glVertexAttribs2fvNV;
    glad_debug_glVertexAttribs2svNV = glad_glVertexAttribs2svNV;
    glad_debug_glVertexAttribs3dvNV = glad_glVertexAttribs3dvNV;
    glad_debug_glVertexAttribs3fvNV = glad_glVertexAttribs3fvNV;
    glad_debug_glVertexAttribs3svNV = glad_glVertexAttribs3svNV;
    glad_debug_glVertexAttribs4dvNV = glad_glVertexAttribs4dvNV;
    glad_debug_glVertexAttribs4fvNV = glad_glVertexAttribs4fvNV;
    glad_debug_glVertexAttribs4svNV = glad_glVertexAttribs4svNV;
    glad_debug_glVertexAttribs4ubvNV = glad_glVertexAttribs4ubvNV;
    glad_debug_glVertexPointer = glad_glVertexPointer;
    glad_debug_glVertexPointerEXT = glad_glVertexPointerEXT;
    glad_debug_glViewport = glad_glViewport;
    glad_debug_glWindowPos2d = glad_glWindowPos2d;
    glad_debug_glWindowPos2dARB = glad_glWindowPos2dARB;
    glad_debug_glWindowPos2dMESA = glad_glWindowPos2dMESA;
    glad_debug_glWindowPos2dv = glad_glWindowPos2dv;
    glad_debug_glWindowPos2dvARB = glad_glWindowPos2dvARB;
    glad_debug_glWindowPos2dvMESA = glad_glWindowPos2dvMESA;
    glad_debug_glWindowPos2f = glad_glWindowPos2f;
    glad_debug_glWindowPos2fARB = glad_glWindowPos2fARB;
    glad_debug_glWindowPos2fMESA = glad_glWindowPos2fMESA;
    glad_debug_glWindowPos2fv = glad_glWindowPos2fv;
    glad_debug_glWindowPos2fvARB = glad_glWindowPos2fvARB;
    glad_debug_glWindowPos2fvMESA = glad_glWindowPos2fvMESA;
    glad_debug_glWindowPos2i = glad_glWindowPos2i;
    glad_debug_glWindowPos2iARB = glad_glWindowPos2iARB;
    glad_debug_glWindowPos2iMESA = glad_glWindowPos2iMESA;
    glad_debug_glWindowPos2iv = glad_glWindowPos2iv;
    glad_debug_glWindowPos2ivARB = glad_glWindowPos2ivARB;
    glad_debug_glWindowPos2ivMESA = glad_glWindowPos2ivMESA;
    glad_debug_glWindowPos2s = glad_glWindowPos2s;
    glad_debug_glWindowPos2sARB = glad_glWindowPos2sARB;
    glad_debug_glWindowPos2sMESA = glad_glWindowPos2sMESA;
    glad_debug_glWindowPos2sv = glad_glWindowPos2sv;
    glad_debug_glWindowPos2svARB = glad_glWindowPos2svARB;
    glad_debug_glWindowPos2svMESA = glad_glWindowPos2svMESA;
    glad_debug_glWindowPos3d = glad_glWindowPos3d;
    glad_debug_glWindowPos3dARB = glad_glWindowPos3dARB;
    glad_debug_glWindowPos3dMESA = glad_glWindowPos3dMESA;
    glad_debug_glWindowPos3dv = glad_glWindowPos3dv;
    glad_debug_glWindowPos3dvARB = glad_glWindowPos3dvARB;
    glad_debug_glWindowPos3dvMESA = glad_glWindowPos3dvMESA;
    glad_debug_glWindowPos3f = glad_glWindowPos3f;
    glad_debug_glWindowPos3fARB = glad_glWindowPos3fARB;
    glad_debug_glWindowPos3fMESA = glad_glWindowPos3fMESA;
    glad_debug_glWindowPos3fv = glad_glWindowPos3fv;
    glad_debug_glWindowPos3fvARB = glad_glWindowPos3fvARB;
    glad_debug_glWindowPos3fvMESA = glad_glWindowPos3fvMESA;
    glad_debug_glWindowPos3i = glad_glWindowPos3i;
    glad_debug_glWindowPos3iARB = glad_glWindowPos3iARB;
    glad_debug_glWindowPos3iMESA = glad_glWindowPos3iMESA;
    glad_debug_glWindowPos3iv = glad_glWindowPos3iv;
    glad_debug_glWindowPos3ivARB = glad_glWindowPos3ivARB;
    glad_debug_glWindowPos3ivMESA = glad_glWindowPos3ivMESA;
    glad_debug_glWindowPos3s = glad_glWindowPos3s;
    glad_debug_glWindowPos3sARB = glad_glWindowPos3sARB;
    glad_debug_glWindowPos3sMESA = glad_glWindowPos3sMESA;
    glad_debug_glWindowPos3sv = glad_glWindowPos3sv;
    glad_debug_glWindowPos3svARB = glad_glWindowPos3svARB;
    glad_debug_glWindowPos3svMESA = glad_glWindowPos3svMESA;
    glad_debug_glWindowPos4dMESA = glad_glWindowPos4dMESA;
    glad_debug_glWindowPos4dvMESA = glad_glWindowPos4dvMESA;
    glad_debug_glWindowPos4fMESA = glad_glWindowPos4fMESA;
    glad_debug_glWindowPos4fvMESA = glad_glWindowPos4fvMESA;
    glad_debug_glWindowPos4iMESA = glad_glWindowPos4iMESA;
    glad_debug_glWindowPos4ivMESA = glad_glWindowPos4ivMESA;
    glad_debug_glWindowPos4sMESA = glad_glWindowPos4sMESA;
    glad_debug_glWindowPos4svMESA = glad_glWindowPos4svMESA;
}


#ifdef __cplusplus
}
#endif
