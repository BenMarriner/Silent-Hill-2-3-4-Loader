#include <glad/gl.h>
#ifndef TGA_LOAD_H
#define TGA_LOAD_H
/*  Definitions for bitflags  */
typedef unsigned int tgaFLAG;

#define TGA_DEFAULT            0x00000000   /* In case we don't want any parameters */
#define TGA_FREE               0x00000001   /* Bit flag 0 */
#define TGA_NO_PASS            0x00000010   /* Bit flag 1 */
#define TGA_ALPHA              0x00000100   /* Bit flag 2 */
#define TGA_LUMINANCE          0x00001000   /* Bit flag 3 */
#define TGA_NO_MIPMAPS         0x00010000   /* Bit flag 4 */
#define TGA_LOW_QUALITY        0x00100000   /* Bit flag 5 */
#define TGA_COMPRESS           0x01000000   /* Bit flag 6 */
#define TGA_FILL			   0x10000000	/* This flag causes the 'tgaLoadSeperateChannels' function to fill in missing channels with the last good  color channel's  comporable */
											/* color component. i.e. Passing in R, A, the rgba would be R.r, R.g, R.b, A.a;  


/*
** GL_ARB_texture_compression
**
** Support:
**  GeForce
**  Radeon
**  ????   <- Any suggestions?
*/
#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression 1

#define GL_COMPRESSED_ALPHA_ARB					 0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB				 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB		 0x84EB
#define GL_COMPRESSED_INTENSITY_ARB				 0x84EC
#define GL_COMPRESSED_RGB_ARB				   	 0x84ED
#define GL_COMPRESSED_RGBA_ARB					 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB	    0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB	 0x86A0
#define GL_TEXTURE_COMPRESSED_ARB				 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB		 0x86A3

#ifdef WINDOWS
typedef void (APIENTRY * PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)(GLenum target, GLint level, 
													   GLenum internalFormat, GLsizei width,
													   GLsizei height, GLsizei depth,
													   GLint border, GLsizei imageSize,
													   const GLvoid *data);
typedef void (APIENTRY * PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)(GLenum target, GLint level,
													   GLenum internalFormat, GLsizei width,
													   GLsizei height, GLint border,
													   GLsizei imageSize, const GLvoid *data);
typedef void (APIENTRY * PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)(GLenum target, GLint level,
													   GLenum internalFormat, GLsizei width,
													   GLint border, GLsizei imageSize,
													   const GLvoid *data);
typedef void (APIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)(GLenum target, GLint level,
														  GLint xoffset, GLint yoffset,
														  GLint zoffset, GLsizei width,
														  GLsizei height, GLsizei depth,
														  GLenum format, GLsizei imageSize,
														  const GLvoid *data);
typedef void (APIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)(GLenum target, GLint level,
														  GLint xoffset, GLint yoffset,
														  GLsizei width, GLsizei height,
														  GLenum format, GLsizei imageSize,
														  const GLvoid *data);
typedef void (APIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)(GLenum target, GLint level,
														  GLint xoffset, GLsizei width,
														  GLenum format, GLsizei imageSize,
														  const GLvoid *data);
typedef void (APIENTRY * PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)(GLenum target, GLint lod, 
#endif WINDOWS														GLvoid *img);
														

#endif /* GL_ARB_texture_compression */



typedef struct {
   unsigned char id_length;
   unsigned char colour_map_type;
   unsigned char image_type;

   // colourmap spec.  5 bytes
   short int     colour_map_first_entry;  // Ignore
   short int     colour_map_length;       // Usually 256
   unsigned char colour_map_entry_size;   // Usually 24-bit

   // image spec.  10 bytes
   short int     x_origin;  // Ignore
   short int     y_origin;  // Ignore
   short int     width;
   short int     height;
   unsigned char pixel_depth;       // Usually 24 or 32
   unsigned char image_descriptor;  // Ignore

   // Added for 'compeletness' :)
   int   components;
   int   bytes;

   GLenum tgaColourType;

} tgaHeader_t;


typedef struct {
   unsigned char        *data;      /* Image data */
   tgaHeader_t           info;
} image_t;


/* 'Public' functions */
void tgaDebugHeader(tgaHeader_t *info);
void   tgaLoad        ( const char *file_name, image_t *p, tgaFLAG mode );
GLuint tgaLoadAndBind ( const char *file_name, tgaFLAG mode, int *flags=NULL );
int tgaLoadAndBind2( const char *file_name, tgaFLAG mode,GLuint texture_id );
int tgaLoadAndBind3( const char *file_name, tgaFLAG mode,GLuint texture_id );
void tgaSetTexParams  ( unsigned int min_filter, unsigned int mag_filter, float anisotropy, unsigned int application );
int tgaLoadSeperateChannels(const char *redTex, const char *greenTex, const char *blueTex, const char *alphaTex, tgaFLAG mode, GLuint texture_id );
void tgaFree ( image_t *p );

int tgaSave( const char *filename, image_t *p, bool swapRB = false, bool debugVals = false);
#endif
