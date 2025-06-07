// SH_initial_loader.cpp : Defines the entry point for the application.
//

#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")

#include <glad/gl.h>
#include <glad/wgl.h>
//#include <gl/glu.h>
#ifndef __INTRIN_H_
#include <windows.h>
//#include <intrin.h>
#endif /*__INTRIN_H_*/
//#include <glad/glext.h>
//#include <glad\glprocs.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string>
#include <vector>

#include "mathOpts.h"
#include "vertex.h"
//#include "quat.h"
#include "matrix.h"
#include "typedefs.h"
#include "mathlib.h"
#include "Camera.h"
//#include "tgaload.h"
#include "Renderer.h"
//#include "AuxToolFuncs.h"
#include "SH3_Loader.h"
#include "SH2_Loader.h"
#include "SH_Model_Anim.h"
#include "debugDrawing.h"
#include "SH3_ArcFilenames.h"
#include "SH2_Model.h"
#include "SH_Msg.h"
#include "SH_Collision.h"
#include "AssetLists.h"

#include "OBJ_Exporter.h"
#include <filesystem>
#include <regex>
#include <fstream>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
//#pragma comment(lib, "glaux.lib")

extern int errno;

#define NUM_SCREEN_DIMS 7

//PLACE IN IT"S OWN STATIC CLASS
void createFont();
void printText(float x,float y,float z,const char *text,rgbf *color);
void startText();
void endText();
bool m_bTextStarted;
//END TEXT FUNCTIONS


//-----------------------------------------------------------------------------
// GLOBALS
//-----------------------------------------------------------------------------
HWND    hwnd = NULL;               //Rendering and Display Globals
HDC	    hdc  = NULL;
HGLRC   hglrc  = NULL;
HINSTANCE g_hInstance=NULL;
DEVMODE oldMode;

int loadOrder=0;
int loadOrder2=0;
int transpose=0;
	

bool onlyStatic = true;
bool onlyVar = true;

bool g_bHasAnim = false;
float g_fPrevTime = 0.0;
float g_fCurTime = 0.0;


int testModeInt = 1;

//=====[ Testing Variables ]=====/
bool test_anim_transpose_seq0 = false;
bool test_anim_transpose_seq8 = false;
bool test_anim_swapXY_seq0 = false;
bool test_anim_swapXY_seq8 = false;
bool test_anim_seq0_use1st = false;
bool test_anim_seq8_use1st = false;

void ProcessTestInput( );

bool sh2_mode = false;
bool sh3_mode = false;
bool sh4_mode = false;
bool model_mode = false;
bool scene_mode = false;

bool sh2_sceneMode = false;
bool sh3_modelMode = false; //true;
bool sh3_sceneMode = false;
bool debugMode = false;
bool animDebugMode = false;
bool testMode = true;
bool showBox = false;
bool clearAllTex = true;
bool dumpScene = false;

bool displayMatrix = false;
bool useOpenGL = true;

bool sh2_run;
bool sh2_anim = false;	//Load the sh2 animations (they don't work right...)
matrix origin;

Camera viewCam;                   //State and Interaction Globals
LARGE_INTEGER freq,FPSTime,lastTime;
int frameCount=0, lightRot = 0;
GLuint nFontList;
char curFileInfo[128];

sh2_tex_index sh2TexList;
TexMgr textureMgr;
//ShaderMgr shaderMgr;
//ShaderObj vShader,fShader;
//ShaderObj vRShader, fRShader;
//ShaderObj vWall, fWall;

//ShadowMap testShadow;
lightAttrib pointLight;
AABB box;

SH3_Collision testCollision;
SceneMap testScene;
SceneMap **testScene2 = NULL;
SH2_MapLoader **testSceneSH2 = NULL;

int modelNum;
int sceneModelNum = 0;
int numScenes = 1;
int sceneLimit = 30;
int minSceneNum, maxSceneNum;
int minModelNum, maxModelNum;

int doDebug = 0;

BYTE colorBits=32;                //Stuff for the Config File
BYTE depthBits=24;
BYTE stencilBits=8;
BYTE screenDimMode=_1024x768; //start off w/  1280x960
BYTE fullScreen=1;
BYTE refreshRate=r60;
bool dumpModel = false;
bool debugRender = false;
float fMoveRate = 100.0f;
float fMouseRate = 1.0f;
float fClearColorRed = 0.2f;
float fClearColorGreen = 0.4f;
float fClearColorBlue = 0.2f;
float d_frameRate = 24.0f;
float fThrottleRatio = 4.0f;
float zDist = 1000.0f;

int g_iMoveDir = 1;
int gTestInt = 0;
int reflectMap;
char gTestStr[128];
char fpsString[32];

rgbf white={1.0,1.0,1.0};
vertex zeroVec(0.0f, 20.0f, 0.0f);
vertex lightPos;

const char* className="GL_TEST";
bool testShit = true;
bool g_bPostQuit = false;

int dirLooped;

OBJ_Exporter OBJ_Dump;

sh3_arcfile arcList;
SH3_Actor testAct;
sh2_model sh2Act;
sh4_model sh4Act;
SH_Anim_Loader testActAnim;



int modelPart = -1;
bool throttleKey = false;
int throttleCount;
int throttleRate = 20;

void throttleKeys();
void throttleOn();
void throttleSetRate( int rate );

long curFrame = 0;

int numTexLoaded=0;
//-----------------------------------------------------------------------------
// PROTOTYPES
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int init(void);
void createEmptyConfig( );
void shutDown(void);
void render( bool shadowMapRender );
float computeFPS(LARGE_INTEGER *curTime);
int pixelFormatSetup(DWORD *flags, BYTE *cbits, BYTE *depthBits, BYTE *stencil,BOOL check=FALSE);
void readIndexData( char *filename, int numLongs, int place, int placeLongs, long placeShift, bool showSign = false);
void readFileDataAtLocation( char *filename, int numLongs, long offset );

//-----------------------------------------------------------------------------
// GL Loader Functions
//-----------------------------------------------------------------------------
GLADapiproc glad_win32_loader(const char* name);

void Load_SH2_SceneFile(filesystem::path& fileToLoad );
void Process_SH2_SceneKeyInput( );
void Load_SH3_SceneFile( filesystem::path& fileToLoad );
void Process_SH3_SceneKeyInput( );
bool Load_SH3_ModelFile( filesystem::path& fileToLoad );
void Process_SH3_ModelKeyInput( );
void Load_SH2_ModelFile( filesystem::path& fileToLoad );
void Process_SH2_ModelKeyInput( );
void Load_SH4_File( filesystem::path& fileToLoad );
void Process_SH4_KeyInput( );
void CleanDirectoryFilelist(vector<filesystem::path>& filePaths);
//int GetDirectoryFilelist(char *fileDirExt,char *fileExt, char ***foundFileName);
//int GetSH2DirectoryFilelist(char *fileDirExt,char *fileExt, char ***foundFileName, bool getFiles = false);
//void GetSH2DirectoryListAux(char *pDirName,char *fileExt, vector< string > & tempList );
//void GetSH2DirectoryFilelistAux(char *pDirName,char *fileExt, vector< string > & tempList );
int GetDirectoryFileList(const filesystem::path& rootDataDir, const string& fileExtRegexPattern, vector<filesystem::path>& foundFileNames);


//---------------[ CLEANUP FUNCTIONS ]----------------/
void DeleteSH3Scene( );
void DeleteSH2Scene( );
void DeleteSH2Models( );
void DeleteSH3Models( );
void DeleteSH4Models( );
void DeleteAllData( );
void DeleteFilesysData( );


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	WNDCLASSEX winClass; 
	MSG        uMsg;
//	char messageBoxString[512];
	int testInt=0;

    memset(&uMsg,0,sizeof(uMsg));
    
	winClass.lpszClassName = className;
	winClass.cbSize        = sizeof(WNDCLASSEX);
	winClass.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	winClass.lpfnWndProc   = WindowProc;
	winClass.hInstance     = hInstance;
    winClass.hIcon	       = LoadIcon(NULL,IDI_APPLICATION);
    winClass.hIconSm	   = LoadIcon(NULL,IDI_APPLICATION);
	winClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winClass.lpszMenuName  = NULL;
	winClass.cbClsExtra    = 0;
	winClass.cbWndExtra    = 0;

	g_hInstance=hInstance;

	int k;

	if( !RegisterClassEx(&winClass) )
		return E_FAIL;

	if(!init())
	{
		MessageBox(NULL,"Unable to Initialize the window!!!","ERROR",MB_OK);
		shutDown();
		UnregisterClass( className , winClass.hInstance );
		return 1;
	}

	
	origin.identity( );


	numSH2SceneFiles	= GetDirectoryFileList( baseSH2dir, SH2_MAP, SH2SceneFiles);
	numSH2ModelFiles	= GetDirectoryFileList( baseSH2dir, SH2_MDL, SH2ModelFiles);
	numSH2AnimFiles		= GetDirectoryFileList( baseSH2dir, SH2_ANM, SH2AnimFiles);
	numSH3SceneFiles	= GetDirectoryFileList( baseSH3dir, SH3_MAP, SH3SceneFiles);
	numSH3ModelFiles	= GetDirectoryFileList( baseSH3dir, SH3_MDL, SH3ModelFiles);
	numSH4Files			= GetDirectoryFileList( baseSH4dir, SH4_BIN, SH4Files);

	if (testMode)
	{
		LogFile(DATA_LOG, "No. SH2 Scene Files: %i\n", numSH2SceneFiles);
		LogFile(DATA_LOG, "No. SH2 Model Files: %i\n", numSH2ModelFiles);
		LogFile(DATA_LOG, "No. SH2 Anm Files: %i\n", numSH2AnimFiles);
		LogFile(DATA_LOG, "No. SH3 Scene Files: %i\n", numSH3SceneFiles);
		LogFile(DATA_LOG, "No. SH3 Model Files: %i\n", numSH3ModelFiles);
		LogFile(DATA_LOG, "No. SH4 Files: %i\n", numSH4Files);
	}



	if( !numSH3SceneFiles && !numSH2SceneFiles && !numSH2ModelFiles && !numSH3ModelFiles && !numSH4Files && !testMode )
	{
		MessageBox(NULL,"No SH2 or SH3 or SH4 Data Files Found - Cannot Continue","ERROR",MB_OK);
		shutDown();
		exit(1);
	}

	if( numSH3ModelFiles == 0 && !testMode )
	{
		MessageBox(NULL,"No SH3 Model Files Found - Model Mode Not Available","ERROR",MB_OK);
	}
	else if( !testMode )
	{
		for( k = 0; k < numSH3ModelFiles; k ++ )
		{
			if( debugMode )LogFile(ERROR_LOG,"Found Data File [%s]",SH3ModelFiles[k]);
		}
	}

	if( numSH3SceneFiles == 0 && !testMode )
	{
		MessageBox(NULL,"No SH3 Level Files Found - Scene Mode Not Available","ERROR",MB_OK);
	}
	else if( !testMode )
	{
		for( k = 0; k < numSH3SceneFiles; k ++ )
		{
			if( debugMode )LogFile(ERROR_LOG,"Found Data File [%s]",SH3SceneFiles[k]);
		}
	}


	if( numSH2SceneFiles == 0 && !testMode )
	{
		MessageBox(NULL,"No SH2 Level Files Found - SH2 Scene Mode Not Available","ERROR",MB_OK);
	}
	else if( !testMode )
	{
		for( k = 0; k < numSH2SceneFiles; k ++ )
		{
			if( debugMode )LogFile(ERROR_LOG,"Found Data File [%s]",SH2SceneFiles[k]);
		}
	}

	if( numSH2ModelFiles == 0 && !testMode )
	{
		MessageBox(NULL,"No SH2 Model Files Found - SH2 Model Mode Not Available","ERROR",MB_OK);
	}
	else if( !testMode )
	{
		for( k = 0; k < numSH2ModelFiles; k ++ )
		{
			if( debugMode )LogFile(ERROR_LOG,"Found Data File [%s]",SH2ModelFiles[k]);
		}
	}

	if( numSH2AnimFiles == 0 && !testMode )
	{
		MessageBox(NULL,"No SH2 Anim Files Found - SH2 Model Animation Mode Not Available","ERROR",MB_OK);
	}
	else if( !testMode )
	{
		for( k = 0; k < numSH2AnimFiles; k ++ )
		{
			if( debugMode )LogFile(ERROR_LOG,"Found Data File [%s]",SH2AnimFiles[k]);
		}
	}

	if( numSH4Files == 0 && !testMode )
	{
		MessageBox(NULL,"No SH4 Files Found - SH4 Mode Not Available","ERROR",MB_OK);
	}
	else if( !testMode )
	{
		for( k = 0; k < numSH4Files; k ++ )
		{
			if( debugMode )LogFile(ERROR_LOG,"Found Data File [%s]",SH4Files[k]);
		}
	}

	//-------------Loading Scene Files-------------//

	if( numSH2SceneFiles && !testMode )
	{
		sh2_mode = true;
		sh3_mode = false;
		sh4_mode = false;
		scene_mode = true;
		model_mode = false;

		sh2_sceneMode = true;
		sh3_sceneMode = false;
		sh3_modelMode = false;
		//numSH2SceneFiles = GetDirectoryFilelist( sceneSH2Dirs[ curSH2SceneDir ], "*.map",&SH2SceneFiles);
		dirLooped = 0;
		Load_SH2_SceneFile( SH2SceneFiles[ curSH2SceneDir ] );
	}
	else if( numSH2ModelFiles && !testMode )
	{
		sh2_mode = true;
		sh3_mode = false;
		sh4_mode = false;
		scene_mode = false;
		model_mode = true;

		sh2_sceneMode = true;
		sh3_sceneMode = false;
		sh3_modelMode = false;
		//numSH2SceneFiles = GetDirectoryFilelist( sceneSH2Dirs[ curSH2SceneDir ], "*.map",&SH2SceneFiles);
		dirLooped = 0;
		Load_SH2_ModelFile( SH2ModelFiles[ curSH2ModelDir ] );
	}
	else if( numSH3SceneFiles && !testMode )
	{
		sh2_mode = false;
		sh3_mode = true;
		sh4_mode = false;
		scene_mode = true;
		model_mode = false;

		sh2_sceneMode = false;
		sh3_sceneMode = true;
		sh3_modelMode = false;
		Load_SH3_SceneFile( SH3SceneFiles[curSceneFile]);
	}
	else if( numSH3ModelFiles && !testMode )
	{
		sh2_mode = false;
		sh3_mode = true;
		sh4_mode = false;
		scene_mode = false;
		model_mode = true;

		sh2_sceneMode = false;
		sh3_sceneMode = false;
		sh3_modelMode = true;
		Load_SH3_ModelFile( SH3ModelFiles[curModelFile]);
	}
	else if( numSH4Files && !testMode )
	{
		sh2_mode = false;
		sh3_mode = false;
		sh4_mode = true;
		scene_mode = false;
		model_mode = false;

		sh2_sceneMode = false;
		sh3_sceneMode = false;
		sh3_modelMode = true;
		Load_SH4_File( SH4Files[curSH4File]);
	}


	createFont();

	ShowWindow( hwnd, nCmdShow );
    UpdateWindow( hwnd );

	while( uMsg.message != WM_QUIT && !g_bPostQuit )
	{
		if( PeekMessage( &uMsg, NULL, 0, 0, PM_REMOVE ) )
		{
			TranslateMessage( &uMsg );
			DispatchMessage( &uMsg );
		}
        //else render();
	}


    UnregisterClass( className , winClass.hInstance );

	return uMsg.wParam;
}

//-----------------------------------------------------------------------------
// Name: WindowProc()
// Desc: The window's message handler
//-----------------------------------------------------------------------------
LRESULT CALLBACK WindowProc( HWND   hWnd, 
							 UINT   msg, 
							 WPARAM wParam, 
							 LPARAM lParam )
{

	vertex corners[4]={ vertex(-10.0f,10.0f, 15.0f),
						vertex(10.0f, 10.0f, 15.0f),
						vertex(10.0f,-10.0f, 15.0f),
						vertex(-10.0f,-10.0f,15.0f)};
    switch( msg )
	{
	case WM_CREATE:
		{
			QueryPerformanceFrequency(&freq);
			QueryPerformanceCounter(&lastTime);
			FPSTime=lastTime;
		}
		break;
	case WM_CHAR:
		{
			switch( wParam )
			{
				case '1': if( testMode ){ testModeInt = 1;testActAnim.ApplyAnimFrame( 0 ); }break;
				case '2': if( testMode ){ testModeInt = 2;testActAnim.ApplyAnimFrame( 0 ); }break;
				case '3': if( testMode ){ testModeInt = 3;testActAnim.ApplyAnimFrame( 0 ); }break;
				case '4': /*if( testMode )*/{ testModeInt = 4;testActAnim.ApplyAnimFrame( 0 ); }break;
				case '5': /*if( testMode )*/{ testModeInt = 5;testActAnim.ApplyAnimFrame( 0 ); }break;
				case '6': if( testMode ){ testModeInt = 6;testActAnim.ApplyAnimFrame( 0 ); }break;
				case '7': if( testMode ){ testModeInt = 7;testActAnim.ApplyAnimFrame( 0 ); }break;
				case '8': if( testMode ){ testModeInt = 8;testActAnim.ApplyAnimFrame( 0 ); }break;
				case '9': if( testMode ){ testModeInt = 9;testActAnim.ApplyAnimFrame( 0 ); }break;
				case '0': if( testMode ){ testModeInt = 0;testActAnim.ApplyAnimFrame( 0 ); }break;
			}
			//LogFile(ERROR_LOG,"Check bad exit - WM_CHAR: %ld '%c'",wParam,wParam);
			if( wParam == VK_ESCAPE){
					//LogFile(ERROR_LOG,"Check bad exit - ESC: %ld '%c'",wParam,wParam);
				//	shutDown();
					PostQuitMessage(0);
				//	return 0;
			}
			else if( wParam == 'q' || wParam == 'Q'){

					//LogFile(ERROR_LOG,"Check bad exit - q: %ld '%c'",wParam,wParam);
					shutDown();
					exit(0);}
			//else if( wParam == ' '){ LogFile(ERROR_LOG,"Check bad exit - SPACE: %ld '%c'",wParam,wParam);}
			//else
			//	LogFile(ERROR_LOG,"Check bad exit - default: %ld or '%c'",wParam,wParam);
		}
        break;
	case WM_PAINT:
		{

			static bool ls_bFirstTime = true;
			LARGE_INTEGER curTime;
			float fps=0,timeStep, timeInc;
			POINT screenLoc;
			int halfWidth=dScreenRes[screenDimMode].w>>1,halfHeight=dScreenRes[screenDimMode].h>>1;
			static int xrot=0,yrot=0;
			static float xRotStep = 0.0f, yRotStep = 0.0f;
			int k;
			char statStr[100];
			float frameTime = 1.0f/d_frameRate;

			dumpScene = false;

			if( dirLooped > 1 )
			{
				shutDown( );
				MessageBox( NULL, "--- ERROR ---\nSH2 Data Directory Is Invalid","Terminal ERROR",MB_OK);
				PostQuitMessage( 0 );
			}
			//--[ COMPUTE FPS AND TIME STEP FOR MOVEMENT ]--/
			//Sleep(1);
			QueryPerformanceCounter(&curTime);   //Set time based motion
			timeInc=((float)(curTime.QuadPart-lastTime.QuadPart)/(float)freq.QuadPart);
			g_fCurTime += timeInc;

			//timeStep*=.1f;
			//timeInc=((float)(curTime.QuadPart-lastTime.QuadPart)/10000000.0);
			lastTime=curTime;

			frameCount++;          //Calculate FPS
			fps=computeFPS(&curTime);

			//sprintf(fpsString,"FPS %6.2f   Time Inc %6.6f",fps,timeInc);
			sprintf(fpsString,"FPS %6.2f",fps);

			//----[ SET UP RATE OF KEYBOARD RESPONSE ]----/
			throttleSetRate( (int)(fps/fThrottleRatio) );
			throttleKeys( );
			

		//	if( fps > refreshRate )
		//		timeStep = 1.0f/((float)refreshRate);
		//	else
		//		timeStep = 1.0f/fps;
			timeStep = timeInc;

		//-- Compute the Light Position --/

			if( model_mode && g_fCurTime > frameTime )
			{
				g_fCurTime = 0.0f;
				if( sh3_mode )
				{
					if (g_bHasAnim && GetAsyncKeyState(VK_F3) & 0x8000){ testActAnim.LoadNextAnim( ); curFrame = 0; }
					if (g_bHasAnim && GetAsyncKeyState(VK_F5) & 0x8000){ if( curFrame == 0 )curFrame = testActAnim.m_lNumSets; --curFrame; testActAnim.ApplyAnimFrame( curFrame ); }
					if (g_bHasAnim && GetAsyncKeyState(VK_F6) & 0x8000){ curFrame = (curFrame+1)%testActAnim.m_lNumSets; testActAnim.ApplyAnimFrame( curFrame );}
				}
				else if( sh2_mode )
				{
					if (GetAsyncKeyState(VK_F5) & 0x8000){ sh2Act.prevFrame( ); }
					if (GetAsyncKeyState(VK_F6) & 0x8000){ sh2Act.nextFrame( ); }
				}
			}


			if( !throttleKey )
			{
				if (GetAsyncKeyState(VK_F7) & 0x8000)
				{
					onlyStatic = !onlyStatic;
					throttleOn();
				}

				if (GetAsyncKeyState(VK_F8) & 0x8000)
				{
					onlyVar = !onlyVar;
					throttleOn();
				}

				if (GetAsyncKeyState(VK_F12) & 0x8000)
				{
					displayMatrix = !displayMatrix;
					throttleOn();
				}

				if( sh2_mode && !testMode )
				{
					if( model_mode )
						Process_SH2_ModelKeyInput( );
					else
						Process_SH2_SceneKeyInput( );
					throttleOn();
				}
				else if( sh3_mode && !testMode )
				{
					if( model_mode )
					{
						if (GetAsyncKeyState(VK_END) & 0x8000){ modelPart=-1; throttleOn();}
						if (GetAsyncKeyState(VK_DELETE) & 0x8000){ modelPart++; modelPart %= testAct.numPrimitives; throttleOn();}
						if (GetAsyncKeyState(VK_INSERT) & 0x8000){  if(modelPart < 1) modelPart = testAct.numPrimitives; modelPart--; throttleOn();}
						Process_SH3_ModelKeyInput( );
					}
					else
						Process_SH3_SceneKeyInput( );
					throttleOn();
				}
				else if( sh4_mode && !testMode )
				{
					Process_SH4_KeyInput( );
					throttleOn();
				}
				else if( testMode )
				{
					ProcessTestInput( );
					if (GetAsyncKeyState(VK_END) & 0x8000){ modelPart=-1; throttleOn();}
					if (GetAsyncKeyState(VK_DELETE) & 0x8000){ modelPart++; modelPart %= testAct.numPrimitives; throttleOn();}
					if (GetAsyncKeyState(VK_INSERT) & 0x8000){  if(modelPart < 1) modelPart = testAct.numPrimitives; modelPart--; throttleOn();}
				}

				if( ( numSH2SceneFiles || numSH2ModelFiles ) && GetAsyncKeyState(VK_F9) & 0x8000 && !sh2_mode && !testMode )
				{
					sh2_mode = true;
					sh3_mode = false;
					sh4_mode = false;
					DeleteAllData( );
					if( debugMode )LogFile(ERROR_LOG,"WM_PAINT - Switching Mode to SH2 - About to delete SH3 Tex");
										dirLooped = 0;
					if( model_mode )
						Load_SH2_ModelFile( SH2ModelFiles[ curSH2ModelDir ] );
					else
						Load_SH2_SceneFile( SH2SceneFiles[curSH2SceneDir] );
					throttleOn();
				}
				else if( ( numSH3SceneFiles || numSH3ModelFiles ) && GetAsyncKeyState(VK_F10) & 0x8000 && !sh3_mode && !testMode )
				{
					if( debugMode )LogFile(ERROR_LOG,"WM_PAINT - Switching Mode to SH3 - About to delete SH2/4 Tex");
					DeleteAllData( );
					//LogFile(ERROR_LOG,"WM_PAINT - SH3 - Completed tex delete");
					sh2_mode = false;
					sh3_mode = true;
					sh4_mode = false;
					if( model_mode )
						Load_SH3_ModelFile( SH3ModelFiles[ curModelFile ]);
					else
						Load_SH3_SceneFile( SH3SceneFiles[curSceneFile]);
					throttleOn();
				}
				else if( numSH3ModelFiles && GetAsyncKeyState(VK_F11) & 0x8000 && !sh3_modelMode && !testMode )
				{
					if( debugMode )LogFile(ERROR_LOG,"WM_PAINT - Switching Mode to SH4 - About to delete SH2/3 Tex");
					DeleteAllData( );
					//LogFile(ERROR_LOG,"WM_PAINT - SH4 - Completed tex delete");
					sh2_mode = false;
					sh3_mode = false;
					sh4_mode = true;
				
					Load_SH4_File( SH4Files[ curSH4File]);
					throttleOn();
				}

				if( model_mode && GetAsyncKeyState(VK_F4) & 0x8000)
				{
					if( debugMode )LogFile(ERROR_LOG,"WM_PAINT - Switching to SCENE MODE");
					scene_mode = true;
					model_mode = false;
					DeleteAllData( );
					if( sh2_mode )
					{
						if( debugMode )LogFile(ERROR_LOG,"WM_PAINT - Switching to SCENE MODE - Loading SH2 Scene");
					//	CleanDirectoryFilelist( numSH2ModelFiles, &SH2ModelFiles );
					//	CleanDirectoryFilelist( numSH2AnimFiles, &animSH2Files );
					//	CleanDirectoryFilelist( numSH2SceneFiles, &SH2SceneFiles );
						Load_SH2_SceneFile( SH2SceneFiles[curSH2SceneDir] );
					}
					else if( sh3_mode )
					{
						if( debugMode )LogFile(ERROR_LOG,"WM_PAINT - Switching to SCENE MODE - Loading SH3 Scene");
						Load_SH3_SceneFile( SH3SceneFiles[curSceneFile] );
					}
					throttleOn();
				}
				else if( scene_mode && GetAsyncKeyState(VK_F4) & 0x8000)
				{
					if( debugMode )LogFile(ERROR_LOG,"WM_PAINT - Switching to MODEL MODE");
					scene_mode = false;
					model_mode = true;
					DeleteAllData( );
					if( sh2_mode )
					{
						if( debugMode )LogFile(ERROR_LOG,"WM_PAINT - Switching to MODEL MODE - Loding SH2 Model");
						Load_SH2_ModelFile( SH2ModelFiles[curSH2ModelDir] );
					}
					else if( sh3_mode )
					{
						if( debugMode )LogFile(ERROR_LOG,"WM_PAINT - Switching to MODEL MODE - Loding SH3 Model");
						Load_SH3_ModelFile( SH3ModelFiles[curModelFile]);
					}
					throttleOn();
				}
			}

			//if (GetAsyncKeyState(VK_F9) & 0x8000)
			//if (GetAsyncKeyState(VK_F10) & 0x8000)
			//if (GetAsyncKeyState(VK_F11) & 0x8000)
			//if (GetAsyncKeyState(VK_F12) & 0x8000)
			//if (GetAsyncKeyState(VK_NUMPAD3) & 0x8000)
			//if (GetAsyncKeyState(VK_NUMPAD4) & 0x8000)
			//if (GetAsyncKeyState(VK_NUMPAD5) & 0x8000)
			//if (GetAsyncKeyState(VK_NUMPAD6) & 0x8000)
			//if (GetAsyncKeyState(VK_NUMPAD7) & 0x8000)
			//if (GetAsyncKeyState(VK_NUMPAD8) & 0x8000)
			//if (GetAsyncKeyState(VK_NUMPAD9) & 0x8000)


			
			
			//if (GetAsyncKeyState(VK_END) & 0x8000 )
			
			//-- Viewer Camera Update --/
			GetCursorPos(&screenLoc);              //Calculate the movement of the mouse for free viewing

			//--[ Set Timestep Based On Mouse Movement ]--/

			xrot+=halfWidth - screenLoc.x;
			yrot+=screenLoc.y - halfHeight;
			SetCursorPos(halfWidth,halfHeight);

		//	xRotStep += 400.0f * timeStep * fMouseRate * (float)(halfWidth - screenLoc.x);
		//	yRotStep += 400.0f * timeStep * fMouseRate * (float)(screenLoc.y - halfHeight);
		//	
		//	xrot = (int)xRotStep;
		//	yrot = (int)yRotStep;

			//--[ Reset y rotation into proper range ]--/
			if( yrot > 89 )
			{
				yrot = 89;
				yRotStep = 89.0f;
			}
			else if( yrot < -89 )
			{
				yrot = -89;
				yRotStep = -89.0f;
			}

			//--[ Reset x rotation into proper range ]--/
			xrot %= 360;                           

			viewCam.rotateView(xrot,yrot);         //figure out some way to use the screenDims and time to slow rotation
			//-- END Viewer Camera Update --/

			if( numScenes == 1 || model_mode || testMode )
			{
				if (GetAsyncKeyState(VK_UP) & 0x8000)viewCam.moveFB(10.0f * timeStep * fMoveRate);
				if (GetAsyncKeyState(VK_DOWN) & 0x8000)viewCam.moveFB(10.0f * -timeStep * fMoveRate);
				if (GetAsyncKeyState(VK_LEFT) & 0x8000)viewCam.moveLR(10.0f * timeStep * fMoveRate);
				if (GetAsyncKeyState(VK_RIGHT) & 0x8000)viewCam.moveLR(10.0f * -timeStep * fMoveRate);
		
			//if (!(GetAsyncKeyState(VK_RSHIFT) & 0x8000) && !(GetAsyncKeyState(VK_LSHIFT) & 0x8000))
			}
			else
			{
				if (GetAsyncKeyState(VK_UP) & 0x8000)	viewCam.moveFB(100.0f * timeStep * fMoveRate);
				if (GetAsyncKeyState(VK_DOWN) & 0x8000)	viewCam.moveFB(-100.0f * timeStep * fMoveRate);
				if (GetAsyncKeyState(VK_LEFT) & 0x8000)	viewCam.moveLR(100.0f * timeStep * fMoveRate);
				if (GetAsyncKeyState(VK_RIGHT) & 0x8000)viewCam.moveLR(-100.0f * timeStep * fMoveRate);
			}
			

			
			if(GetAsyncKeyState(VK_F1) & 0x8000)
			{
				shutDown();
				exit(0);
			}

	
			viewCam.camView();

			glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

			if( sh2_mode && !testMode )
			{
				glScalef( 1.0f, -1.0f, -1.0f );
				if( model_mode )
				{
					if (GetAsyncKeyState('T') & 0x8000)
						transpose = (transpose+1)%4;
					if (GetAsyncKeyState('R') & 0x8000)
						loadOrder = (loadOrder+1)%6;
					if (GetAsyncKeyState('E') & 0x8000)
						loadOrder2 = (loadOrder2+1)%6;
				//	if( g_fCurTime > 0.04166 )
				//	{
				//		g_fCurTime = 0.0f;
				//		if (GetAsyncKeyState(VK_F5) & 0x8000){ sh2Act.prevFrame( ); }
				//		if (GetAsyncKeyState(VK_F6) & 0x8000){ sh2Act.nextFrame( ); }
				//	}

					//if( sh2Act.m_bHasAnim && sh2_anim )
					//{
					
					sh2Act.Render( );
					sprintf(statStr,"Transpose: %ld   Load Order: %s  Load Order2: %s",transpose, (loadOrder ==0)?"XYZ":(loadOrder ==1)?"XZY":(loadOrder ==2)?"YXZ":(loadOrder ==3)?"YZX":
						(loadOrder ==4)?"ZXY":"ZYX",
						(loadOrder2 ==0)?"XYZ":(loadOrder2 ==1)?"XZY":(loadOrder2 ==2)?"YXZ":(loadOrder2 ==3)?"YZX":(loadOrder2 ==4)?"ZXY":"ZYX");
					printText(0,400,0,statStr,&white);

					if( modelPart > -1 )
						sprintf(statStr,"Cur Frame: %ld of %ld   ModelPart: %ld of %ld",curFrame+1,testActAnim.m_lNumSets,modelPart,testAct.numPrimitives-1);
					else
						sprintf(statStr,"Cur Frame: %ld of %ld",sh2Act.m_lCurFrame+1,sh2Act.m_lFrameCount );
					printText(0, 668, 0, statStr, &white );
					//}
					//else
					//{
					//	sh2Act.Render2( );
					//}
				}
				else
				{
					for( k = 0; k < numScenes; k ++ )
					{
						//LogFile(TEST_LOG,"****************\n\nDid I get here %d of %d\n\n*********************",k, numScenes);
						if(testSceneSH2[k])
							testSceneSH2[k]->RenderMap( );	
					}
				}
				glFlush();

			}
			else if( sh3_mode && !testMode )
			{
				if( model_mode )
				{
					glScalef(1.0f,-1.0f,1.0f);
					if( g_bHasAnim && testActAnim.m_pcDispMat )
					{
						testActAnim.RenderModel( modelPart );
						if( modelPart > -1 )
							sprintf(statStr,"Cur Frame: %ld of %ld   ModelPart: %ld of %ld",curFrame+1,testActAnim.m_lNumSets,modelPart,testAct.numPrimitives-1);
						else
							sprintf(statStr,"Cur Frame: %ld of %ld",curFrame+1,testActAnim.m_lNumSets);
						printText(0, 668, 0, statStr, &white );
					}
					else
					{
						testAct.draw( modelPart );
						if( modelPart > -1 )
							sprintf(statStr,"No Animation For Model   ModelPart: %ld of %ld",curFrame+1,testActAnim.m_lNumSets,modelPart,testAct.numPrimitives-1);
						else
							printText(0, 668, 0, (char*)"No Animation For Model", &white );
					}

				}
				else
				{
					//	glScalef(1.0f,-1.0f,-1.0f);
					glScalef(.10f,-.10f,-.10f);
					//testScene.renderScene();
					for( k = 0; k < numScenes; k ++ )
					{
						//LogFile(ERROR_LOG,"Did I get here %d",k);
						if(testScene2[k])
							testScene2[k]->renderScene();
					}
				}
				glFlush();

				if( !onlyVar || !onlyStatic )
				{
					sprintf( statStr,"DRAW: Odd Trans: %3s   Even Trans: %s",(onlyStatic)?"Yes":"No",(onlyVar)?"Yes":"No");
					printText(0,688,0,statStr,&white);
				}

			}
			else if( sh4_mode )
			{
				glScalef(1.0f,-1.0f,-1.0f);
				sh4Act.Render( );
				glFlush( );
			}
			else if( testMode )
			{
				if( ls_bFirstTime )LogFile( ERROR_LOG, "WM_PAINT - In testMode render block");
				drawBasisMatrix( &origin, 20.0f );
//				glScalef(1.0f,-1.0f,1.0f);
				
				if( model_mode )
				{
					if( g_fCurTime > 0.04166 )
					{
						g_fCurTime = 0.0f;

						if(sh2_run)
						{	if (GetAsyncKeyState(VK_F5) & 0x8000){ sh2Act.prevFrame( ); }
							if (GetAsyncKeyState(VK_F6) & 0x8000){ sh2Act.nextFrame( ); }
						}
						else
						{	if (GetAsyncKeyState(VK_F3) & 0x8000){ testActAnim.LoadNextAnim( ); curFrame = 0; }
							if (GetAsyncKeyState(VK_F5) & 0x8000){ if( curFrame == 0 )curFrame = testActAnim.m_lNumSets; --curFrame; testActAnim.ApplyAnimFrame( curFrame ); }
							if (GetAsyncKeyState(VK_F6) & 0x8000){ curFrame = (curFrame+1)%testActAnim.m_lNumSets; testActAnim.ApplyAnimFrame( curFrame );}
						}				
					}


					if( (sh2_run && sh2Act.m_bHasAnim) || testActAnim.IsAnimLoaded() )
		//			if(testActAnim.m_pcDispMat )
					{
						if( ls_bFirstTime )LogFile( ERROR_LOG, "WM_PAINT - Model Has animation...about to call render");
						if(sh2_run)
							sh2Act.Render( );
						else				
							testActAnim.RenderModel( modelPart );

						if( modelPart > -1 )
							sprintf(statStr,"Cur Frame: %ld of %ld   ModelPart: %ld of %ld",curFrame+1,testActAnim.m_lNumSets,modelPart,testAct.numPrimitives-1);
						else
							sprintf(statStr,"Cur Frame: %ld of %ld",curFrame+1,testActAnim.m_lNumSets);
					}
					else
					{
						if( ls_bFirstTime )LogFile( ERROR_LOG, "WM_PAINT - Model does NOT have animations... calling Render2");
						if(sh2_run)
							sh2Act.Render( );
						else				
							testAct.draw( modelPart );
						if( modelPart > -1 )
							sprintf(statStr,"No Animation For Model   ModelPart: %ld of %ld",modelPart,testAct.numPrimitives-1);
						else
							sprintf(statStr,"No Animation For Model");
					}

				
					printText(0, 668, 0, statStr, &white );

					sprintf( statStr, "Tests: Trnsps 0: %c  8: %c   Swap 0: %c  8: %c   Use1st 0: %c  8: %c",
						(test_anim_transpose_seq0)?'Y':'N',
						(test_anim_transpose_seq8)?'Y':'N',
						(test_anim_swapXY_seq0)?'Y':'N',
						(test_anim_swapXY_seq8)?'Y':'N',
						(test_anim_seq0_use1st)?'Y':'N',
						(test_anim_seq8_use1st)?'Y':'N');
					printText( 0, 28, 0, statStr, &white );
				}
				else
				{
					if( sh2_run )
					{

					}
					else
					{
						//testScene.renderScene();
						for( k = 0; k < 5; k++ )
						{
							if( testCollision.m_caCldData[ k ].m_vPrimData.size( ) )
							{
								if( ls_bFirstTime )LogFile( ERROR_LOG, "WM_PAINT - Section %ld of 5 has %ld primitives",k+1, testCollision.m_caCldData[ k ].m_vPrimData.size( ) );
								
								long j;
								for( j = 0; j < testCollision.m_caCldData[ k ].m_vPrimData.size( ); j++ )
								{
									if( ls_bFirstTime )LogFile( ERROR_LOG, "WM_PAINT - Section Drawing %ld of %ld primitive",j+1,testCollision.m_caCldData[ k ].m_vPrimData.size( ));
glDisable( GL_TEXTURE_2D );
									glEnable(GL_BLEND);
									glBlendFunc(GL_SRC_ALPHA,GL_DST_COLOR);
									//if( k == 2 )
									//if( testCollision.m_caCldData[ k ].m_vPrimData[ j ].m_sVertHeader.q1_sh3_cvh == 4096
									//	|| (testCollision.m_caCldData[ k ].m_vPrimData[ j ].m_sVertHeader.q1_sh3_cvh == 1 && k == 0 ))
									{
										glBegin( GL_TRIANGLES );
											glColor4f( 1.0f / j, 0.0f, 1.0f / j, 0.5f );
											glVertex3fv( &( testCollision.m_caCldData[ k ].m_vPrimData[ j ].m_pcVerts[ 0 ].x ) );
											glColor4f( 1.0f / j, 1.0f / j, 1.0f / j, 0.5f );
											glVertex3fv( &( testCollision.m_caCldData[ k ].m_vPrimData[ j ].m_pcVerts[ 1 ].x ) );
											glColor4f( 1.0f / j, 1.0f / j, 0.0f, 0.5f );
											glVertex3fv( &( testCollision.m_caCldData[ k ].m_vPrimData[ j ].m_pcVerts[ 2 ].x ) );

											glColor4f( 1.0f / j, 0.0f, 1.0f / j, 0.5f );
											glVertex3fv( &( testCollision.m_caCldData[ k ].m_vPrimData[ j ].m_pcVerts[ 0 ].x ) );
											glColor4f( 1.0f / j, 1.0f / j, 0.0f, 0.5f );
											glVertex3fv( &( testCollision.m_caCldData[ k ].m_vPrimData[ j ].m_pcVerts[ 2 ].x ) );
											glColor4f( 1.0f / j, 1.0f / j, 1.0f / j, 0.5f );
											glVertex3fv( &( testCollision.m_caCldData[ k ].m_vPrimData[ j ].m_pcVerts[ 3 ].x ) );
										glEnd( );
									}
									glDisable( GL_BLEND );
								}
							}
						}
					}
				}
			}

			sprintf( statStr,"Pos: X: %.2f   Y: %.2f   Z: %.2f",viewCam.from.x, viewCam.from.y, viewCam.from.z );
			printText(0, 48, 0, statStr, &white);
			
			sprintf( statStr,"Dir: X: %.2f   Y: %.2f   Z: %.2f",viewCam.at.x - viewCam.from.x, viewCam.at.y- viewCam.from.y, viewCam.at.z - viewCam.from.z );
			printText(0, 68, 0, statStr, &white);

			printText(0,748,0,curFileInfo,&white);
			printText(0,708,0,fpsString,&white);

			//if (GetAsyncKeyState(VK_F4) & 0x8000)dumpScene = dumpModel = !dumpScene;
			if (GetAsyncKeyState(VK_F3) & 0x8000)debugMode = !debugMode;

			//sprintf(statStr,"Dump Scene: %s   Dump Model: %s   Debug Mode: %s",(dumpScene)?"Yes":"No",(dumpModel)?"Yes":"No",(debugMode)?"Yes":"No");
			//printText(0,728,0,statStr,&white);
			if( displayMatrix && !model_mode )
				printText( 0, 688, 0, (char*)"Displaying Matricies", &white );
			
			if( sh2_mode )
				sprintf(statStr,"Tex In Mem: %3.3ld",sh2TexList.CountTexInMem( ));
			else
				sprintf(statStr,"Tex In Mem: %3.3ld",textureMgr.textures.size());
			printText(0,728,0,statStr,&white);

			printText(0,10,0, (char*)"Hold 'HOME' For Help",&white);

			if( sh2_mode && scene_mode && !testMode )
			{
				for( k = 0; k < numScenes; k++ )
				{
					if( testSceneSH2[ k ] )
					{
						if( testSceneSH2[ k ]->m_bHasMultiView )
						{
							sprintf( statStr,"DRAW: Static Prim: %3s   Var Prim: %s",(onlyStatic)?"Yes":"No",(onlyVar)?"Yes":"No");
							printText(0,688,0,statStr,&white);
							k = numScenes;
						}
					}
				}
			}

			if (GetAsyncKeyState(VK_HOME) & 0x8000)
			{
				sprintf( statStr,"     - - - H E L P - - -    ");
				printText(300,600,0,statStr,&white);
				sprintf( statStr,"ESC - Exit   ");
				printText(300,580,0,statStr,&white);
				sprintf( statStr,"F2  - Dump Model (if available)");
				printText(300,560,0,statStr,&white);
				if( g_bHasAnim )
					sprintf( statStr,"F3  - Load Next Anim File");
				else
					sprintf( statStr,"F3  - Toggle Debug Log");
				printText(300,540,0,statStr,&white);
				sprintf( statStr,"F4  - Toggle Model/Scene Mode");
				printText(300,520,0,statStr,&white);
				if( g_bHasAnim )
				{
					printText(300,500,0, (char*)"F5  - Decrease Frame Num",&white);
					printText(300,480,0, (char*)"F6  - Increase Frame Num",&white);
				}
				else
				{
					sprintf( statStr,"F7  - Toggle Static Prim Draw");
					printText(300,500,0,statStr,&white);
					sprintf( statStr,"F8  - Toggle Var Prim Draw");
					printText(300,480,0,statStr,&white);
				}
				sprintf( statStr,"F9  - Switch to SH2 Mode");
				printText(300,460,0,statStr,&white);
				sprintf( statStr,"F10 - Switch to SH3 Mode");
				printText(300,440,0,statStr,&white);
				sprintf( statStr,"F11 - Switch to SH4 Mode");
				printText(300,420,0,statStr,&white);
				sprintf( statStr,"F12 - Display Matricies for Models (if possible)");
				printText(300,400,0,statStr,&white);
				sprintf( statStr,"L/R CTRL - Cycle Through Files/Dirs");
				printText(300,380,0,statStr,&white);
				sprintf( statStr,"L/R SHFT - Cycle Through Models/Levels");
				printText(300,360,0,statStr,&white);
			}
ls_bFirstTime = false;
dumpModel = false;
			SwapBuffers( hdc );
		}
		break;
		case WM_CLOSE:
		{
		//	LogFile(ERROR_LOG,"Check bad exit - WM_CLOSE: %ld",wParam);
		//		glDeleteLists(nFontList,128);
			shutDown();
			PostQuitMessage(0);	
			break;
		}
		case WM_DESTROY:
		{
		//	glDeleteLists(nFontList, 128);
		//	LogFile(ERROR_LOG,"Check bad exit - WM_DESTROY: %ld",wParam);
			shutDown();
			PostQuitMessage(0);
			return(0);
		}break;
/*		case WM_MOUSEWHEEL:
			{
				WORD zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
				//remember, the zDelta moves in +/-120 increments
			}break;*/
		case WM_MOUSEMOVE:
		{
		//	hdc=GetDC(hwnd);
			int mouseX=(int)LOWORD(lParam);
			int mouseY=(int)HIWORD(lParam);
			int buttons=(int)wParam;
		
			if(buttons&MK_LBUTTON)
			{
			//	if(sh3_modelMode)
			//	{
			//		if(modelnum < 45 )
			//			modelnum ++;
					//testModel.LoadModel("D:\\Program Files\\KONAMI\\SILENT HILL 3\\data\\chrwp.arc",modelnum);
			//		testModel.LoadModel("chrwp.arc",modelnum);
			//		printModelHeader(&testModel.mHeader,modelnum);
			//	}
			//	else
			//	{
			//		if(sceneModelNum > 0 ) sceneModelNum --;
			//	}
			}
			else if(buttons&MK_RBUTTON)
			{
			//	if(sh3_modelMode)
			//	{
			//		if(modelnum > 16 )
			//			modelnum --;
					//testModel.LoadModel("D:\\Program Files\\KONAMI\\SILENT HILL 3\\data\\chrwp.arc",modelnum);
			//		testModel.LoadModel("chrwp.arc",modelnum);
			//		printModelHeader(&testModel.mHeader,modelnum);
			//	}
			//	else
			//	{
			//		if(sceneModelNum < 178) sceneModelNum++;
			//	}
			}
		//	ReleaseDC(hwnd,hdc);
			//LogFile(ERROR_LOG,"Check bad exit - MOUSE: %ld",wParam);
			return(0);
		}break;		
		default:
		{
			return DefWindowProc( hWnd, msg, wParam, lParam );
		}
		break;
	}

	return 0;
}

void Trim(string& inputString)
{
	auto itl = std::find_if_not(
		inputString.begin(),
		inputString.end(),
		[](unsigned char ch)
		{
			return std::isspace(ch);
		}
	);
	inputString.erase(inputString.begin(), itl);

	auto itr = std::find_if_not(
		inputString.rbegin(),
		inputString.rend(),
		[](unsigned char ch)
		{
			return std::isspace(ch);
		}
	);
	inputString.erase(itr.base(), inputString.end());
}

//-----------------------------------------------------------------------------
// Name: InitConfig()
// Desc: Initialises settings from the config file
//-----------------------------------------------------------------------------
int InitConfig(Config& outConfig)
{
	namespace fs = std::filesystem;

	fs::path exeDir = fs::current_path();
	fs::path cfgPath = exeDir / "default.cfg";

	if (!fs::exists(cfgPath))
	{
		LogFile(ERROR_LOG, "Couldn't find the configuration file at %s\n", cfgPath.string());
		return 0;
	}

	ifstream file(cfgPath);
	if (!file.is_open())
	{
		LogFile(ERROR_LOG, "Couldn't open the configuration file at %s\n", cfgPath.string());
		return 0;
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		Trim(line);

		if (line[0] == '#')
			continue;

		auto eqPos = line.find(' ');
		if (eqPos == string::npos)
		{
			if (line.find("data_dir")) // Just skip this line and move onto the next if a data directory doesn't exist. No need to throw an error
				continue;

			LogFile(ERROR_LOG, "Invalid key-value pair while reading line: %s", line);
			return 0;
		}

		string key = line.substr(0, eqPos);
		string value = line.substr(eqPos + 1);
		Trim(key);
		Trim(value);

		outConfig.values[key] = value;
	}

	file.close();
	return 1;
}

template<typename T>
bool ParseString(const string& text, T& out)
{
	std::istringstream iss(text);
	if (!(iss >> out))
		return false;
	if (!iss.eof())
		return false;
	return true;
}

template<>
bool ParseString<bool>(const string& text, bool& out)
{
	string s = text;
	for (auto& c : s) c = static_cast<char>(std::tolower(c));
	if (s == "true" || s == "1") { out = true; return true; }
	if (s == "false" || s == "0") { out = false; return false; }
	return false;
}

template<typename T>
T GetConfigVariable(
	const std::unordered_map<string, string>& values,
	const string& key,
	const T& defaultValue)
{
	auto it = values.find(key);
	if (it == values.end())
	{
		LogFile(ERROR_LOG, "Couldn't read config variable %s. Reverting to default value", key);
		return defaultValue;
	}

	T result{};
	if (!ParseString<T>(it->second, result))
	{
		LogFile(ERROR_LOG, "Couldn't read config variable %s's value. Reverting to default value", key);
		return defaultValue;
	}

	return result;
}

template<>
filesystem::path GetConfigVariable<filesystem::path>(
	const std::unordered_map<string, string>& values,
	const string& key,
	const filesystem::path& defaultValue)
{
	auto it = values.find(key);
	if (it == values.end())
	{
		LogFile(ERROR_LOG, "Couldn't read path for %s", key);
		return defaultValue;
	}

	filesystem::path path = it->second;
	return path;
}

void AssignConfigVars(const Config& config)
{
	colorBits = GetConfigVariable(config.values, "d_colordepth", COLOR_DEPTH_DEFAULT);
	depthBits = GetConfigVariable(config.values, "d_depthbuff", DEPTH_BUFFER_DEFAULT);
	stencilBits = GetConfigVariable(config.values, "d_stencil", STENCIL_DEFAULT);
	screenDimMode = GetConfigVariable(config.values, "d_dispmode", DISPLAY_MODE_DEFAULT) % NUM_SCREEN_DIMS;
	refreshRate = GetConfigVariable(config.values, "d_refresh", REFRESH_DEFAULT);
	fullScreen = GetConfigVariable(config.values, "d_fullscreen", FULLSCREEN_DEFAULT);
	sceneLimit = GetConfigVariable(config.values, "o_num_scenes", NUM_SCENES_DEFAULT);
	baseSH2dir = GetConfigVariable(config.values, "o_sh2_data_dir", SH2_DATA_DIR_DEFAULT);
	baseSH3dir = GetConfigVariable(config.values, "o_sh3_data_dir", SH3_DATA_DIR_DEFAULT);
	baseSH4dir = GetConfigVariable(config.values, "o_sh4_data_dir", SH4_DATA_DIR_DEFAULT);
	sh2_anim = GetConfigVariable(config.values, "o_sh2_anim", SH2_ANIM_DEFAULT);
	zDist = GetConfigVariable(config.values, "d_zdist", Z_DISTANCE_DEFAULT);
	debugRender = GetConfigVariable(config.values, "o_debug_render", DEBUG_RENDER_DEFAULT);
	debugMode = GetConfigVariable(config.values, "o_debug", DEBUG_DEFAULT);
	animDebugMode = GetConfigVariable(config.values, "o_anim_debug", ANIM_DEBUG_DEFAULT);
	dumpModel = GetConfigVariable(config.values, "o_dumpmeshdata", DUMP_MESH_DATA_DEFAULT);
	testMode = GetConfigVariable(config.values, "o_test_mode", TEST_MODE_DEFAULT);
	fMoveRate = GetConfigVariable(config.values, "o_movement_rate", MOVEMENT_RATE_DEFAULT);
	fMouseRate = GetConfigVariable(config.values, "o_mouse_rate", MOUSE_RATE_DEFAULT);
	fThrottleRatio = GetConfigVariable(config.values, "o_throttle_ratio", THROTTLE_KEYS_DEFAULT);
	d_frameRate = GetConfigVariable(config.values, "o_anim_frame_rate", ANIM_FRAMERATE_DEFAULT);
	fClearColorRed = GetConfigVariable(config.values, "d_screen_color", SCREEN_COLOR_R_DEFAULT);
	fClearColorGreen = GetConfigVariable(config.values, "d_screen_color", SCREEN_COLOR_G_DEFAULT);
	fClearColorBlue = GetConfigVariable(config.values, "d_screen_color", SCREEN_COLOR_B_DEFAULT);
}

//-----------------------------------------------------------------------------
// Name: init()
// Desc: 
//-----------------------------------------------------------------------------
int init( void )
{
	char configFile[128]="default.cfg";
	Config config;
	int nMode = 0;
	DEVMODE devMode;
	bool bDesiredDevModeFound = false;
	FILE *fp;
	

	// Variables for setting pixel format and display settings
	DWORD flagPtr=PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	DWORD dwStyle = WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	DWORD retVal;

	char errorString[128];

	if (!InitConfig(config))
	{
		sprintf( errorString, "init( ) - ERROR: Couldn't load default.cfg - REASON: %s",strerror( errno ) );
		LogFile( ERROR_LOG, errorString );
		MessageBox( NULL, errorString, "FATAL ERROR: Config", MB_OK );
		/*if( MessageBox( NULL, "Do you want to create a generic 'default.cfg'?","NOTICE",MB_YESNO ) )
			createEmptyConfig( );*/
		return 0;
	}
	AssignConfigVars(config);


	//---[ Validate debug settings, to avoid invalid values ]---/
	if( zDist < F_EPS )
		zDist = 100.0f;
	if( fMoveRate < F_EPS )
		fMoveRate = 0.01f;
	if( fMouseRate < F_EPS )
		fMouseRate = 0.01f;
	

	// Cache the current display mode so we can switch back when done.
	EnumDisplaySettings( NULL, ENUM_CURRENT_SETTINGS, &oldMode );


	


	//
	// Enumerate Device modes...
	//
	if(fullScreen)
	{

		while( EnumDisplaySettings( NULL, nMode++, &devMode ) )
		{
			// Does this device mode support a 640 x 480 setting?
			if( devMode.dmPelsWidth  != dScreenRes[screenDimMode].w || 
				devMode.dmPelsHeight !=dScreenRes[screenDimMode].h )
				continue;

			// Does this device mode support 32-bit color?
			if( devMode.dmBitsPerPel != colorBits )
				continue;

			// Does this device mode support a refresh rate of 75 MHz?
			if( devMode.dmDisplayFrequency != refreshRate )
				continue;

			// We found a match, but can it be set without rebooting?
			if( ChangeDisplaySettings( &devMode, CDS_TEST ) == DISP_CHANGE_SUCCESSFUL )
			{
				bDesiredDevModeFound = true;
				break;
			}
		}

		if( bDesiredDevModeFound == false )
		{
			fullScreen=0;
			LogFile(ERROR_LOG,"init( %d ) - ERROR: Couldn't find correct display mode\n\t...Exiting",__LINE__);
			return 0;
		}
	}



	//if( ChangeDisplaySettings( &devMode, CDS_FULLSCREEN ) != DISP_CHANGE_SUCCESSFUL )
	//{
	//	// TO DO: Respond to failure of ChangeDisplaySettings
	//	LogFile(ERROR_LOG,"init( %d ) - ERROR: Couldn't change the display\n\t...Exiting",__LINE__);
	//	return 0;
	//}

	RECT winRect;
	winRect.left	= 0;			
	winRect.right	= dScreenRes[screenDimMode].w;	
	winRect.top	    = 0;
	winRect.bottom	= dScreenRes[screenDimMode].h;	

	AdjustWindowRect( &winRect, dwStyle, false);

	hwnd = CreateWindowEx( NULL, className, "Silent Hill 3 - Level Viewer",
						     dwStyle,
					         0, 0, winRect.right-winRect.left, winRect.bottom-winRect.top, NULL, NULL, g_hInstance, NULL );
	if( hwnd == NULL )
	{
		LogFile(ERROR_LOG,"init( %d ) - ERROR: Couldn't create the Windo\n\t...Exiting",__LINE__);
		return 0;
  	}


	sprintf(errorString,"Requested: %dx%d:%d bpp @ %d, with %d and %d bits depth and stencil\n",
		dScreenRes[screenDimMode].w,dScreenRes[screenDimMode].h,colorBits,refreshRate,depthBits,stencilBits);

	if((retVal=pixelFormatSetup(&flagPtr,&colorBits,&depthBits,&stencilBits,FALSE))!=0)
	{
		char messageString[128];
		sprintf(messageString,"%s Initialized: %d bpp with %d and %d bits depth and stencil",errorString,colorBits,
			depthBits,stencilBits);
		//MessageBox(NULL,messageString,"ERROR: Display Init",MB_OK);
	}

	if(hdc==NULL)
		hdc=GetDC(hwnd);

	hglrc = wglCreateContext( hdc );
	wglMakeCurrent(hdc, hglrc);

	// Using compatibility profile for OpenGL for now. Uncomment this when moving to modern OpenGL and consequently, the core profile.
	if (!gladLoadGL(glad_win32_loader))
	{
		MessageBox(NULL, "gladLoadGL failed", "Error", MB_OK);
		//return 0;
	}
	
	if (!gladLoadWGL(hdc, glad_win32_loader))
	{
		MessageBox(NULL, "gladLoadWGL failed", "Error", MB_OK);
		//return 0;
	}

	using GetExtsFn = const char* (WINAPI*)(HDC);
	auto wglGetExts = (PFNWGLGETEXTENSIONSSTRINGARBPROC)wglGetProcAddress("wglGetExtensionsStringARB");
	const char* wglExts = wglGetExts ? wglGetExts(hdc) : "";
	static const  char* wglRequired[] = {
		"WGL_ARB_pixel_format",
		"WGL_ARB_create_context",
		"WGL_EXT_swap_control",
		"WGL_ARB_extensions_string",
		"WGL_ARB_pbuffer",
		"WGL_ARB_pixel_format",
		"WGL_ARB_pixel_format_float",
		"WGL_ARB_render_texture"
	};

	for (auto& name : wglRequired)
	{
		if (std::strstr(wglExts, name) == nullptr)
		{
			LogFile(ERROR_LOG, "Missing WGL extension %s", name);
		}
	}

	const char* glExts = reinterpret_cast<const char*>(glGetString(GL_EXTENSIONS));
	static const char* glRequired[] = {
		"GL_ARB_fragment_program",
		"GL_ARB_multitexture",
		"GL_ARB_texture_compression",
		"GL_ARB_texture_cube_map",
		"GL_ARB_vertex_program",
		"GL_EXT_texture_compression_s3tc",
		"GL_EXT_texture_filter_anisotropic"
	};

	for (auto& name : glRequired)
	{
		if (std::strstr(glExts, name))
		{
			LogFile(ERROR_LOG, "Missing GL extension %s", name);
		}
	}

	glEnable(GL_DEPTH_TEST);

	viewCam.createCamView(75.0f, 4.0f/3.0f, 1.0f, zDist);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glShadeModel(GL_SMOOTH);
	glClearColor(fClearColorRed, fClearColorGreen, fClearColorBlue, 0.0f);
	glColor4f(.50f, .50f, .50f, .50f);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	//glPolygonOffset( 4.0f, 0.8f );
	//Depth states
	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	//glDisable(GL_CULL_FACE);
	return 1;
}

//-----------------------------------------------------------------------------
// Name: glad_win32_loader()
// Desc: Loads Win32 GLAD
//-----------------------------------------------------------------------------
GLADapiproc glad_win32_loader(const char* name)
{
	/*GLADapiproc proc = (GLADapiproc)wglGetProcAddress(name);
	if (proc == nullptr ||
		proc == (GLADapiproc)0x1 || (GLADapiproc)0x2 ||
		proc == (GLADapiproc)0x3 || (GLADapiproc)-1)
	{
		static HMODULE ogl32 = LoadLibraryA("opengl32.dll");
		proc = (GLADapiproc)GetProcAddress(ogl32, name);
	}

	return proc;*/

	void* ptr = (void*)wglGetProcAddress(name);
	if (ptr) return (GLADapiproc)ptr;

	static HMODULE module = LoadLibraryA("opengl32.dll");
	return (GLADapiproc)GetProcAddress(module, name);
}

int pixelFormatSetup(DWORD *flags, BYTE *cbits, BYTE *depthBits, BYTE *stencil,BOOL check)
{
	int closestPF;
	if(hdc==NULL)
		hdc = GetDC( hwnd );

	PIXELFORMATDESCRIPTOR pfd = {sizeof(PIXELFORMATDESCRIPTOR), 
								1,
								(*flags),//,
								PFD_TYPE_RGBA,
								(*cbits),
								0,0,0,0,0,0,0,     //Bit breakdown
								0,0,0,0,0,         //Bits per Accum Buffer Color Channel
								(*depthBits),
								(*stencil),
								0,0,0,0,0,0};

	if(!check)
	{
		closestPF=ChoosePixelFormat(hdc,&pfd);

		if( SetPixelFormat( hdc, closestPF, &pfd) == FALSE )
		{	
			//MessageBox(NULL,"Why did it get here,\nMaybe cuz there is no HWND?","ERROR",MB_OK);
			DWORD dwErrorCode = GetLastError();
			// TO DO: Respond to failure of SetPixelFormat
			return dwErrorCode;
		}
	}
	DescribePixelFormat(hdc,GetPixelFormat(hdc),pfd.nSize,&pfd);
	cbits[0]=pfd.cColorBits;
	depthBits[0]=pfd.cDepthBits;
	flags[0]=pfd.dwFlags;

	return 0;
}
	


void createEmptyConfig( )
{
	FILE *outFile;

	if( (outFile = fopen( "default.cfg","w" )) != NULL )
	{
		fprintf( outFile, "#  Mode 0 - 640x480    1 - 800x600    2 - 1024x768    3 - 1280x960    4 - 1280x1024    5 - 1600x1200\n");
		fprintf( outFile, "d_dispmode 2\n\n");
		fprintf( outFile, "#NOTE: I wouldn't mess w/ these display settings, unless you know what you're doing...\n\n");
		fprintf( outFile, "d_refresh 60\nd_colordepth 32\nd_depthbuff 24\nd_stencil 8\n\n");
		fprintf( outFile, "# I Never implemented the windowed version, and I didn't test what would happen if I tried it windowed... Have fun\n");
		fprintf( outFile, "d_fullscreen 1\n\n#For large models, you may want to change this (Note: This can't be 0)\nd_zdist 25000.0\n\n#Background Color\n");
		fprintf( outFile, "d_screen_color 0.2 0.4 0.2\n\n# This is the directory where the data files reside. Don't forget the '\\' at the end...\n");
		fprintf( outFile, "o_sh2_data_dir h:\\Silent Hill 2\\data\\\no_sh3_data_dir C:\\Program Files\\KONAMI\\SILENT HILL 3\\data\\\n");
		fprintf( outFile, "o_sh4_data_dir C:\\Program Files\\KONAMI\\SILENT HILL 4\\data\\\n\n# Number of different sections of the town");
		fprintf( outFile, "and outside levels to load at a time\n# NOTE: Since the mouse and keypad movement is based on the frame rate, too high a\n");
		fprintf( outFile, "#       number may result in viewing difficulty (you'll see what I mean)\no_num_scenes 15\n\n");
		fprintf( outFile, "# Setting this to 1 will cause the program to debug the section loading, texture data, and a whole lot of other stuff...\n");
		fprintf( outFile, "# It increases how long it takes to load, but If you want to know anything about the format, turn it on...\no_debug 1\n\n");
		fprintf( outFile, "# This will print out the data for the animations as they load...  It's a *LOT* of data... I don't\n");
		fprintf( outFile, "#recommend turning it on.  Loading 6 or so models will write out like 10 Megs of logging - Have Fun!\n");
		fprintf( outFile, "o_anim_debug 1\n\n#NOTE: Because my USB drive was stolen, this only dumps texture data for SH2... I'm not really sure about");
		fprintf( outFile, "SH3 stuff tho...\no_dumpmeshdata 0\n\n#Constant movement rate per second (Note: This can't be 0)\no_movement_rate 100.0\n");
		fprintf( outFile, "\n#Mouse sensitivity - The lower it is, the slower the mouse moves when looking around (Note: This can't be 0)o_mouse_rate 1.0\n");
		fprintf( outFile, "\n#Frame Rate For Animated Models - It seems like they are run at 24 frames per second.  Play around w/ this\n");
		fprintf( outFile, "o_anim_frame_rate 24.0\n\n#Load SH2 Animations - NOTE: These animations aren't quite right, so it won't look all that good....\n");
		fprintf( outFile, "o_sh2_anim 1\no_debug_render 1\n");
		fclose( outFile );
	}
	else
		MessageBox( NULL, "Cannot create 'default.cfg' file...","FATAL ERROR",MB_OK);
}

//-----------------------------------------------------------------------------
// Name: shutDown()
// Desc: 
//-----------------------------------------------------------------------------
void shutDown( void )	
{
//	int k;
	glDeleteLists(nFontList,128);
//LogFile(ERROR_LOG,"SD-Here A");
DeleteAllData( );
// Restore original device mode...
	ChangeDisplaySettings( &oldMode, 0 );

	if( hglrc != NULL )
	{
		wglMakeCurrent( NULL, NULL );
		wglDeleteContext( hglrc );
		hglrc = NULL;
	}
//LogFile(ERROR_LOG,"SD-Here C");
	if( hdc != NULL )
	{
		ReleaseDC( hwnd, hdc );
		hdc = NULL;
	}

	if(fullScreen)
	{
		ChangeDisplaySettings(NULL,0);
		ShowCursor(TRUE);
	}
//LogFile(ERROR_LOG,"SD-Here D");
DeleteFilesysData( );	
//LogFile(ERROR_LOG,"SD-Here E");
	g_bPostQuit = true;
}

void DeleteSH3Scene( )
{
	long k;
//	LogFile( ERROR_LOG, "DeleteSH3Scene - Start");
	for( k = textureMgr.textures.size( ); k > 0; k-- )
	{
//		LogFile( ERROR_LOG, "Does this work?");
//		LogFile(ERROR_LOG,"    Delete Tex %d - [%s]", k,textureMgr.textures[k-1].texName.c_str());
		textureMgr.DeleteTex( (int)(k - 1) );
	}
//LogFile( ERROR_LOG, "DeleteSH3Scene - Deleted Tex, starting scene data");
	if( testScene2 )
	{
//		LogFile( ERROR_LOG, "DeleteSH3Scene - Stuff 2 delete");
		for( k = 0; k < numScenes; k ++)
		{
//			LogFile( ERROR_LOG, "DeleteSH3Scene - %ld of %ld",k+1, numScenes);
			if( testScene2[k] )
				delete testScene2[k];
			testScene2[k] = NULL;
		}
//		LogFile( ERROR_LOG, "DeleteSH3Scene - About to delete main array");
		SAFEDELETE(testScene2);
	}
//	LogFile( ERROR_LOG, "DeleteSH3Scene - done");
}

void DeleteSH2Scene( )
{
	long k;
//LogFile(ERROR_LOG,"SD-Here B");
	if( testSceneSH2 )
	{
		for( k = 0; k < numScenes; k ++)
		{
			if( testSceneSH2[k] )
				delete testSceneSH2[k];
		
			testSceneSH2[k] = NULL;
		}
		
		SAFEDELETE(testSceneSH2);
		
		//--[ Clean Up Scene Textures ]--/
		sh2TexList.ReleaseAllTex( );
	}
}


void DeleteSH2Models( )
{
	sh2Act.deleteData( );
	testActAnim.ReleaseData( );
}

void DeleteSH3Models( )
{
	testAct.releaseModelData( );
	testActAnim.ReleaseData( );
}

void DeleteSH4Models( )
{
	sh4Act.deleteData( );
}

void DeleteAllData( )
{
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - Start");
	DeleteSH2Scene( );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH2 Scene done");
	DeleteSH3Scene( );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH3 Scene done");
	DeleteSH2Models( );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH2 Models done");
	DeleteSH3Models( );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH3 Models done");
	DeleteSH4Models( );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH4 Models done");
}

void DeleteFilesysData( )
{
	CleanDirectoryFilelist( SH2SceneFiles );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH2 scene files");
	CleanDirectoryFilelist( SH2SceneFiles );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH2 scene dirs");
	CleanDirectoryFilelist( SH3SceneFiles );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH3 Scene files");
	CleanDirectoryFilelist( SH3ModelFiles );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH3 Model files");
	CleanDirectoryFilelist( SH2ModelFiles );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH2 Model files");
	CleanDirectoryFilelist( SH2ModelFiles );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH2 Model dirs ");
	CleanDirectoryFilelist( SH4Files );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH4 files");
	CleanDirectoryFilelist( SH2AnimFiles );
	if( debugMode )LogFile( ERROR_LOG, "DeleteAllData( ) - SH2 Anim files");

}

float computeFPS(LARGE_INTEGER *curTime)
{
	float fps;                   //FPSTime,freq,and frameCount are all global
	fps=((float)(curTime->QuadPart-FPSTime.QuadPart)/(float)freq.QuadPart);
//	fps/=10.0;
	fps=1.0f/fps;
//	if(frameCount==360)
//		frameCount=0;
	QueryPerformanceCounter(&FPSTime);
	return fps;
}


//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void createFont()
{
	// Setup the Font characteristics
	HFONT hFont;
	LOGFONT logfont;

	logfont.lfHeight = -20;
	logfont.lfWidth = 0;
	logfont.lfEscapement = 0;
	logfont.lfOrientation = 0;
	logfont.lfWeight = FW_BOLD;
	logfont.lfItalic = FALSE;
	logfont.lfUnderline = FALSE;
	logfont.lfStrikeOut = FALSE;
	logfont.lfCharSet = ANSI_CHARSET;
	logfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	logfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	logfont.lfQuality = DEFAULT_QUALITY;
	logfont.lfPitchAndFamily = DEFAULT_PITCH;
	strcpy(logfont.lfFaceName,"Arial");

	// Create the font and display list
	hFont = CreateFontIndirect(&logfont);
	SelectObject (hdc, hFont); 

	
	//Create display lists for glyphs 0 through 128
	nFontList = glGenLists(128);
	wglUseFontBitmaps(hdc, 0, 128, nFontList);

	DeleteObject(hFont);		// Don't need original font anymore

}


//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void startText()
{
	if(!m_bTextStarted)
	{
		m_bTextStarted = true;
		glMatrixMode( GL_PROJECTION );
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0,1024.0,0.0,768.0);
		glMatrixMode( GL_MODELVIEW );
		glPushMatrix();
		glLoadIdentity();
		glDisable(GL_DEPTH_TEST);
	}
}

//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void endText()
{
	if(m_bTextStarted)
	{
		m_bTextStarted = false;
		glMatrixMode( GL_MODELVIEW );
		glPopMatrix();
		glMatrixMode( GL_PROJECTION );
		glPopMatrix();
		glEnable(GL_DEPTH_TEST);
	}
}

//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void printText(float x,float y,float z,const char *text,rgbf *color)
{
	startText();
	glColor4f(color->r,color->g,color->b,1.0);
//	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(x,y);
	glListBase(nFontList);
	glCallLists (strlen(text), GL_UNSIGNED_BYTE, text);
	endText();
}


//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void throttleKeys()
{
	if( throttleKey )
		throttleCount--;
	if( throttleCount < 1 )
		throttleKey = false;
}

//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void throttleOn()
{
	throttleKey = true;
	throttleCount = throttleRate;
}


void throttleSetRate( int rate )
{
	if( rate )
		throttleRate = rate;
	else
		throttleRate = 1;
}
/***********************************************************************************************/


//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
//int GetDirectoryFilelist(filesystem::path& fileDirExt, string_view fileExt, vector<filesystem::path>& foundFileNames)
//{
//	//vector< filesystem::path > fileList;
//	WIN32_FIND_DATA fileData;	
//	HANDLE fileHandle;
//	//int numFiles;
//	std::string searchStr[512];
//
//	if (!fileDirExt.empty() && fileDirExt.string()[fileDirExt.string().length() - 1] != '\\')
//		//sprintf( searchStr, "%s\\%s",fileDirExt->string().c_str(), fileExt);
//		searchStr->append(std::format("%s\\%s", fileDirExt.string().c_str(), fileExt));
//	else
//		//sprintf( searchStr,  "%s%s",fileDirExt->string().c_str(), fileExt );
//		searchStr->append(std::format("%s%s", fileDirExt.string().c_str(), fileExt));
//
//	if((fileHandle = FindFirstFile(searchStr->c_str(), &fileData)) != INVALID_HANDLE_VALUE)
//	{
//		do
//		{
//			//fileList.push_back( string( fileDirExt ) + string(fileData.cFileName) );
//			foundFileNames.push_back(fileDirExt/fileData.cFileName);
//		}
//		while(FindNextFile(fileHandle, &fileData));
//		FindClose(fileHandle);
//	}
//	else
//	{
//		LogFile(ERROR_LOG,"GetDirectoryFilelist( ) - ERROR: Unable to find any files that match the search path [%s]", searchStr);
//		return 0;
//	}
//
//	/*if( foundFileName.size() = 0)
//		return foundFileName.size( );
//	if( !foundFileName.size( ) )
//		return 0;*/
////LogFile(TEST_LOG,"Array     : Addr: 0x%08x\t PRE",(*foundFileName));
////LogFile(TEST_LOG,"----------------GetDirectoryFilelist-------------------");
////LogFile(TEST_LOG,"CREATING: Dest-  foundFileName = 0x%08x", foundFileName);
////LogFile(TEST_LOG,"CREATING: Pre - *foundFileName = 0x%08x",*foundFileName);
////LogFile(TEST_LOG,"CHECK: Address of SH2SceneFiles= 0x%08x",&SH2SceneFiles);
////LogFile(TEST_LOG,"CHECK: CurVal  of SH2SceneFiles= 0x%08x",SH2SceneFiles);
//	//*foundFileName = new char *[ fileList.size( ) + 1 ];
////LogFile(TEST_LOG,"Array     : Addr: 0x%08x\t POST",(*foundFileName));
////LogFile(TEST_LOG,"CREATING: Post- *foundFileName = 0x%08x",*foundFileName);
////LogFile(TEST_LOG,"CHECK: CurVal  of SH2SceneFiles= 0x%08x",SH2SceneFiles);	
//	/*for( numFiles = 0; numFiles < fileList.size( ); numFiles ++ )
//	{
//		(*foundFileName)[ numFiles ] = new char[ fileList[ numFiles ].length( ) + 1 ];
//		strcpy( (*foundFileName)[ numFiles ], fileList[ numFiles ].c_str() );*/
////LogFile(TEST_LOG,"CREATING: %ld  - *foundFileName[%2.2ld] = 0x%08x\tval[%s]\tlen: %ld\tstrlen: %ld",numFiles,numFiles,(*foundFileName)[numFiles],(*foundFileName)[numFiles],fileList[ numFiles ].length(),strlen(fileList[ numFiles ].c_str()));
//		/*{
//			int k1;
//			LogFile(ERROR_LOG,"CHECK: Array length: %ld",sizeof((*foundFileName)[ numFiles ])/sizeof((*foundFileName)[ numFiles ][0]));
//			LogFile(TEST_LOG,"Array[%3d]: Base Addr: 0x%08x\tChar Addr: 0x%08x",numFiles,&((*foundFileName)[ numFiles ]),(*foundFileName)[ numFiles ]);
//			LogFile(ERROR_LOG,"CHECK: length: %d   strlen: %d",fileList[ numFiles ].length(),strlen((*foundFileName)[numFiles]));
//			for( k1 = 0; k1 < fileList[ numFiles ].length( ); k1++ )
//				LogFile(ERROR_LOG,"%d\t[%c]\t Addr: 0x%08x",k1,(*foundFileName)[ numFiles ][k1],&((*foundFileName)[ numFiles ][k1]));
//		}*/
//
//	//}
//
//	return foundFileNames.size();
//}


//----------------------------------------------------------------------------/
//- CleanDirectoryFilelist                                                   -/
//-     Cleans a single directory list of files                              -/
//----------------------------------------------------------------------------/
void CleanDirectoryFilelist(vector<filesystem::path>& filePaths)
{
	filePaths.clear();

//	int k;
//	char ** ppFiles, *pFile;
//	if( *pppFileName == NULL || numNames == 0 )
//		return;
//	
//	ppFiles = *pppFileName;
////	LogFile(ERROR_LOG,"TEST: The address of the char** array is: 0x%08x",pppFileName);
////	LogFile(ERROR_LOG,"TEST: The address of the char* array is: 0x%08x or 0x%08x",*pppFileName,ppFiles);
//	for( k = numNames - 1; k >= 0; k-- )
//	{
//		pFile = ppFiles[k];
////		LogFile(ERROR_LOG,"Point 5.1.%d of %d - Addr: 0x%08x\tString [%s]",k,numNames,pFile,pFile);
//		delete [] ppFiles[k];
////		LogFile(ERROR_LOG,"Point 5.1.%d.2",k);
//		pFile = NULL;
//		//SAFEDELETE( pFile );
//	}
////	LogFile(ERROR_LOG,"Point 5.2");
//
//	SAFEDELETE( ppFiles );
////	LogFile(ERROR_LOG,"Point 5.3");
}


//----------------------------------------------------------------------------/
//- Name: GetDirectoryFileList                                               -/
//- Desc: The new and more unified version of GetDirectoryFileList.			 -/
//	It uses a regex string to search for a specific kind of asset			 -/
//----------------------------------------------------------------------------/
int GetDirectoryFileList(const filesystem::path& rootDataDir, const string& fileExtRegexPattern, vector<filesystem::path>& foundFileNames)
{
	regex::flag_type flags = regex::icase;
	regex rx(fileExtRegexPattern, flags);
	filesystem::directory_options opts = filesystem::directory_options::skip_permission_denied;

	for (const filesystem::directory_entry& e : filesystem::recursive_directory_iterator(rootDataDir, opts))
	{
		if (!e.is_regular_file()) continue;

		const string name = e.path().filename().string();
		if (regex_match(name, rx))
			foundFileNames.emplace_back(e.path());
	}

	return (int)foundFileNames.size();
}
	

////----------------------------------------------------------------------------/
////-                                                                          -/
////-                                                                          -/
////----------------------------------------------------------------------------/
//int GetSH2DirectoryFilelist(filesystem::path& fileDirExt, string& fileExt, vector<filesystem::path>& foundFileNames, bool getFiles )
//{
//	int numFiles;
////	WIN32_FIND_DATA fileData;	
////	HANDLE fileHandle;
//	string searchStr;
//
//	//if( fileDirExt != NULL && fileDirExt[ strlen( fileDirExt ) - 1 ] != '\\' )
//	if (!fileDirExt.empty() && fileDirExt.native().back() != '\\')
//		//sprintf( searchStr, "%s\\",fileDirExt );
//		searchStr = format("%s\\", fileDirExt.string());
//	else
//		//sprintf( searchStr, "%s",fileDirExt );
//		searchStr = format("%s", fileDirExt.string());
//
//	if( getFiles )
//		GetSH2DirectoryFilelistAux( searchStr, fileExt, foundFileNames );
//	else
//		GetSH2DirectoryListAux( searchStr, fileExt, foundFileNames );
//
//	if( foundFileName == NULL )
//		return foundFileNames.size( );
//
////LogFile(TEST_LOG,"+-+-+-+-+-+-+-+-GetSH2DirectoryFilelist-+-+-+-+-+-+-+-+-+");
////LogFile(TEST_LOG,"CREATING: Dest-  foundFileName = 0x%08x", foundFileName);
////LogFile(TEST_LOG,"CREATING: Pre - *foundFileName = 0x%08x",*foundFileName);
//	*foundFileName = new char *[ foundFileNames.size( ) ];
////LogFile(TEST_LOG,"CREATING: Post- *foundFileName = 0x%08x",*foundFileName);
//
//	for( numFiles = 0; numFiles < foundFileNames.size( ); numFiles ++ )
//	{
//		(*foundFileName)[ numFiles ] = new char[ foundFileNames[ numFiles ].length( ) + 1 ];
//		strcpy( (*foundFileName)[ numFiles ], foundFileNames[ numFiles ].c_str() );
////LogFile(TEST_LOG,"CREATING: %ld  - *foundFileName[%2.2ld] = 0x%08x\tval[%s]",numFiles,numFiles,(*foundFileName)[numFiles],(*foundFileName)[numFiles]);
//	}
//
//	return numFiles;
//
//}

////----------------------------------------------------------------------------/
////-                                                                          -/
////-                                                                          -/
////----------------------------------------------------------------------------/
//void GetSH2DirectoryListAux(char *pDirName,char *fileExt, vector< string > & tempList )
//{
//	WIN32_FIND_DATA fileData;	
//	HANDLE fileHandle;
//	char dirName[512];
//	char fileName[512];
//	bool addSlash = false;
//
//	if( pDirName[ strlen( pDirName ) - 1 ] == '\\' )
//	{
//		addSlash = false;
//		sprintf( dirName,"%s*",pDirName );
//	}
//	else
//	{
//		addSlash = true;
//		sprintf( dirName, "%s\\*",pDirName );
//	}
//
//	if((fileHandle = FindFirstFile( dirName, &fileData)) != INVALID_HANDLE_VALUE )
//	{
//		do
//		{
//			if( fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && fileData.cFileName[0] != '.' )
//			{
//				if( addSlash )
//					sprintf( dirName, "%s\\%s",pDirName, fileData.cFileName );
//				else
//					sprintf( dirName, "%s%s",pDirName, fileData.cFileName );
//
//				if( debugMode )LogFile( ERROR_LOG, "GetSH2DirectoryListAux( %s ) - Switching to directory '%s'",pDirName, dirName );
//
//				GetSH2DirectoryListAux( dirName, fileExt, tempList );
//
//				if( addSlash )
//					sprintf( dirName, "%s\\*",pDirName );
//				else
//					sprintf( dirName, "%s*",pDirName );
//			}
//			else
//			{
//				if( strncmp( &( fileData.cFileName[ strlen( fileData.cFileName ) - strlen( fileExt ) ] ), fileExt, strlen( fileExt ) ) == 0 )
//				{
//					if( addSlash )
//						sprintf( fileName, "%s\\",pDirName );
//					else
//						sprintf( fileName, "%s",pDirName );
//
//					tempList.push_back( string( fileName ) );
//					FindClose(fileHandle);
//					return;
//				}
//			}
//			
//		}
//		while(FindNextFile(fileHandle, &fileData));
//		FindClose(fileHandle);
//	}
//	else
//	{
//		LogFile(ERROR_LOG,"GetSH2DirectoryFilelistAux( ) - ERROR: Unable to find any files that match the search path [%s]", dirName);
//	}
//
//}
	
////----------------------------------------------------------------------------/
////-                                                                          -/
////-                                                                          -/
////----------------------------------------------------------------------------/
//void GetSH2DirectoryFilelistAux(string& pDirName, string& fileExt, vector<filesystem::path>& tempList )
//{
//	WIN32_FIND_DATA fileData;	
//	HANDLE fileHandle;
//	char dirName[512];
//	char fileName[512];
//	bool addSlash = false;
//
//	if( pDirName[ strlen( pDirName ) - 1 ] == '\\' )
//	{
//		addSlash = false;
//		sprintf( dirName,"%s*",pDirName );
//	}
//	else
//	{
//		addSlash = true;
//		sprintf( dirName, "%s\\*",pDirName );
//	}
//
//	if((fileHandle = FindFirstFile( dirName, &fileData)) != INVALID_HANDLE_VALUE )
//	{
//		do
//		{
//			if( fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && fileData.cFileName[0] != '.' )
//			{
//				if( strncmp( fileData.cFileName, "demo", 4 ) == 0 )
//				{
//					if( debugMode )LogFile( ERROR_LOG, "GetSH2DirectoryFilelistAux( ) - NOTE: Ignoring demo dirs '%s'",dirName );
//					continue;
//				}
//
//				if( addSlash )
//					sprintf( dirName, "%s\\%s",pDirName, fileData.cFileName );
//				else
//					sprintf( dirName, "%s%s",pDirName, fileData.cFileName );
//
//				if( debugMode )LogFile( ERROR_LOG, "GetSH2DirectoryFilelistAux( %s ) - Switching to directory '%s'",pDirName, dirName );
//
//				GetSH2DirectoryFilelistAux( dirName, fileExt, tempList );
//
//				if( addSlash )
//					sprintf( dirName, "%s\\*",pDirName );
//				else
//					sprintf( dirName, "%s*",pDirName );
//			}
//			else
//			{
//				if( strncmp( &( fileData.cFileName[ strlen( fileData.cFileName ) - strlen( fileExt ) ] ), fileExt, strlen( fileExt ) ) == 0 )
//				{
//					if( addSlash )
//						sprintf( fileName, "%s\\%s",pDirName, fileData.cFileName );
//					else
//						sprintf( fileName, "%s%s",pDirName, fileData.cFileName );
//
//					tempList.push_back( string( fileName ) );
//					//FindClose(fileHandle);
//				}
//			}
//			
//		}
//		while(FindNextFile(fileHandle, &fileData));
//		FindClose(fileHandle);
//	}
//	else
//	{
//		LogFile(ERROR_LOG,"GetSH2DirectoryFilelistAux( ) - ERROR: Unable to find any files that match the search path [%s]", dirName);
//	}
//
//}
	



//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void Load_SH2_SceneFile(filesystem::path& fileToLoad )
{
	int k;
	int numLoaded;
	bool doTrans, looped = false;
	bool origDebugMode = debugMode;
	//char nameLen = strlen( fileToLoad );
//	long startIndex;
	int badLoopCounter = 0;


	if( dirLooped > 1 )
		return;

	/*if( nameLen != 0 && nameLen > 2 )
	{
		if( fileToLoad[ nameLen - 1 ] == '\\' )
			nameLen -= 3;
		else
			nameLen -= 2;

		if( fileToLoad[ nameLen ] == 'c' )
			doTrans = true;
		else
			doTrans = false;
	}
	else
		doTrans = false;*/

	doTrans = true;

	if( debugMode )
		LogFile( ERROR_LOG,"Load_SH2_SceneFile( %s ) - NOTE: %s",fileToLoad,(doTrans)?"Multiple maps will be loaded":"Single map loading mode");

	clearAllTex = !doTrans;

	//CleanDirectoryFilelist( SH2SceneFiles );

	//---[ CLEAN UP OLD SCENE, IF IT EXISTS ]---//
	if( testSceneSH2 )
	{
		for( k = 0; k < numScenes; k ++)
		{
			if( testSceneSH2[k] )
				delete testSceneSH2[k];
		
			testSceneSH2[k] = NULL;
		}
		
		SAFEDELETE(testSceneSH2);
		
		//--[ Clean Up Scene Textures ]--/
		sh2TexList.ReleaseAllTex( );
	}

	curSH2SceneFile = 0;
	//numSH2SceneFiles = GetDirectoryFileList(fileToLoad, SH2_MAP, SH2SceneFiles);

	if( ! numSH2SceneFiles )
	{
		MessageBox( NULL, "Load_SH2_SceneFile( ) - Found files, but internal error occurred","I is stupeed",MB_OK);
		return;
	}
//debugMode = true;
	sh2TexList.BuildTexList();
//debugMode = origDebugMode;
	
	if( debugMode )LogFile(ERROR_LOG,"Load_SH2_SceneFile() - FILE [%s]  Map Files [ first: \"%s\"  last: \"%s\" ]",fileToLoad,SH2SceneFiles[0],SH2SceneFiles[numSH2SceneFiles-1]);

	if( doTrans )
		numScenes = sceneLimit;
	else
		numScenes = 1;

	testSceneSH2 = new SH2_MapLoader*[numScenes];

	for( k = 0; k < numScenes; k ++ )
		testSceneSH2[k] = NULL;

	for( numLoaded = 0; curSH2SceneFile < numSH2SceneFiles && numLoaded < numScenes; numLoaded++,curSH2SceneFile++ )
	{
		testSceneSH2[numLoaded] = new SH2_MapLoader;

		if( debugMode )
			LogFile(ERROR_LOG,"Load_SH2_SceneFile() - CHECK: numLoaded=%ld\tcurSH2SceneFile is [%ld]= %s",numLoaded,curSH2SceneFile,SH2SceneFiles[curSH2SceneFile]);

		while( !testSceneSH2[numLoaded]->LoadMap( SH2SceneFiles[curSH2SceneFile].string().c_str() )
			&& curSceneFile < numSH2SceneFiles 
			&& numLoaded < numScenes )
		{
			badLoopCounter++;
			curSH2SceneFile++;

			if( (curSH2SceneFile >= numSH2SceneFiles && numLoaded == 0 )
				|| (!numSH2SceneFiles || numSH2SceneFiles == 1)
				|| badLoopCounter > 50 + numScenes )
			{
				//if( looped || !numSH2SceneFiles || numSH2SceneFiles == 1 || badLoopCounter > 50 + numScenes )
				//{
					if( g_iMoveDir < 0 )
					{
						curSH2SceneDir = (curSH2SceneDir - 1);
						if( curSH2SceneDir < 0 )
						{
							dirLooped ++;
							curSH2SceneDir +=numSH2SceneFiles;
						}
					}
					else
					{
						if( curSH2SceneDir + 1 == numSH2SceneFiles )
							dirLooped ++;
						curSH2SceneDir = (curSH2SceneDir + 1)%numSH2SceneFiles;
					}

					if( badLoopCounter > 50 + numScenes )
						LogFile( ERROR_LOG,"Load_SH2_SceneFile( %s ) - ERROR: Bad Loop Counter Reached threshold %d In Directory",fileToLoad,badLoopCounter);
					if( !numSH2SceneFiles || numSH2SceneFiles == 1)
						LogFile( ERROR_LOG, "Load_SH2_SceneFile( %s ) - ERROR: No Map Files Found In Directory",fileToLoad);
	
					Load_SH2_SceneFile( SH2SceneFiles[curSH2SceneDir] );
					return;
				//}
				curSH2SceneFile = 0;
				looped = true;
			}

			if( debugMode )
				LogFile(ERROR_LOG,"Load_SH2_SceneFile() - POST CHECK: numLoaded=%ld\tcurSH2SceneFile is [%ld]= %s",numLoaded,curSH2SceneFile,SH2SceneFiles[curSH2SceneFile]);
			
		}

		if( curSH2SceneFile < numSH2SceneFiles && numLoaded < numScenes && testSceneSH2[numLoaded]->m_pcVarPrim )
		{
			viewCam.setCam(testSceneSH2[numLoaded]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.x,
							-testSceneSH2[numLoaded]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.y,
							-testSceneSH2[numLoaded]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.z,
							testSceneSH2[numLoaded]->m_pcVarPrim[ 0 ].m_sBaseHeader.maxExtent.x,
							-testSceneSH2[numLoaded]->m_pcVarPrim[ 0 ].m_sBaseHeader.maxExtent.y,
							-testSceneSH2[numLoaded]->m_pcVarPrim[ 0 ].m_sBaseHeader.maxExtent.z,
							0,1,0);

			//viewCam.from.x = testSceneSH2[numLoaded]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.x;
			//viewCam.from.y = testSceneSH2[numLoaded]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.y;
			//viewCam.from.z = -testSceneSH2[numLoaded]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.z;
			//LogFile(ERROR_LOG,"viewCam [%f %f %f]",viewCam.from.x,viewCam.from.y,viewCam.from.z);
		}
		else if( curSH2SceneFile >= numSH2SceneFiles && numLoaded < numScenes )
		{
		
			delete testSceneSH2[numLoaded];
			testSceneSH2[numLoaded] = NULL;

		}
	}

	if( curSH2SceneFile )
		curSH2SceneFile --;

	sprintf(curFileInfo,"FILE: %s",SH2SceneFiles[curSH2SceneFile]);

	if( debugMode )
		LogFile(ERROR_LOG,"Load_SH2_SceneFile() - EXIT CHECK: numLoaded=%ld\tcurSH2SceneFile is [%ld]= %s",numLoaded,curSH2SceneFile,SH2SceneFiles[curSH2SceneFile]);
}


//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void Process_SH2_SceneKeyInput( )
{
	bool looped = false;

	if (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
	{
		curSH2SceneDir --;
		if( curSH2SceneDir < 0 )
			curSH2SceneDir = numSH2SceneFiles - 1;
		curSH2SceneDir %= numSH2SceneFiles;

		g_iMoveDir = -1;
		dirLooped = 0;
		curSH2SceneFile = 0;
		
		Load_SH2_SceneFile( SH2SceneFiles[ curSH2SceneDir ] );
		sprintf(curFileInfo,"FILE: %s",SH2SceneFiles[curSH2SceneFile]);
	}

	if (GetAsyncKeyState(VK_RCONTROL) & 0x8000)
	{
		curSH2SceneDir ++;
		curSH2SceneDir %= numSH2SceneFiles;

		g_iMoveDir = 1;
		dirLooped = 0;
		curSH2SceneFile = 0;

		Load_SH2_SceneFile( SH2SceneFiles[ curSH2SceneDir ] );
		sprintf(curFileInfo,"FILE: %s",SH2SceneFiles[curSH2SceneFile]);
	}

	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000)
	{
		if( curSH2SceneFile > 0 )
		{
			int k;
			string offsetStr;
//			SH2_MapLoader *tScenePtr;
			if(testSceneSH2[numScenes-1])
			{
				if( clearAllTex )
					sh2TexList.DeleteAllTex( );
				else
				{
					for( k = 0; k < testSceneSH2[numScenes-1]->m_sOffsetUnknown.numUnknowDataSets; k++ )
					{
						//sprintf(offsetStr,"%15ld",testSceneSH2[numScenes-1]->m_psUnknownData[ k ].id );
						offsetStr = format("%15ld", testSceneSH2[numScenes - 1]->m_psUnknownData[k].id);
						//LogFile(TEST_LOG,"CHECK: About to clean texture [%s]",offsetStr);
						sh2TexList.DeleteTex( offsetStr );
					}
				}

				delete testSceneSH2[numScenes-1];
				testSceneSH2[numScenes-1] = NULL;	
			}

			for( k = numScenes-1; k > 0; k--)
				testSceneSH2[k] = testSceneSH2[k-1];
			testSceneSH2[0] = NULL;
			
			curSH2SceneFile--;
			if( curSH2SceneFile < 0 )
				curSH2SceneFile = numSH2SceneFiles - 1;


			testSceneSH2[0] = new SH2_MapLoader;
			if( numScenes != 1 )
			{
				if(!testSceneSH2[0]->LoadMap( SH2SceneFiles[ curSH2SceneFile ].string().c_str() ) )
				{
					LogFile(ERROR_LOG,"Process_SH2_SceneKeyInput() - ERROR: Could not load map file [%s]",SH2SceneFiles[ curSH2SceneFile ]);
					delete testSceneSH2[0];
					testSceneSH2[0] = NULL;
				}
			}
			else
			{
				while( !testSceneSH2[0]->LoadMap( SH2SceneFiles[ curSH2SceneFile ].string().c_str() )&& curSH2SceneFile >= 0 )
				{
					curSH2SceneFile--;
					if( curSH2SceneFile < 0 )
					{
						if( looped )
						{
							curSH2SceneDir = (curSH2SceneDir - 1);
							if( curSH2SceneDir < 0 )
								curSH2SceneDir +=numSH2SceneFiles;
							dirLooped = 0;
							Load_SH2_SceneFile( SH2SceneFiles[curSH2SceneDir] );
							return;
						}
						curSH2SceneFile += numSH2SceneFiles;
						looped = true;
					}
				}

				if(!testSceneSH2[0]->isSceneValid())
				{
					LogFile(ERROR_LOG,"Process_SH2_SceneKeyInput() - ERROR: Could not load map file [%s]",SH2SceneFiles[ curSH2SceneFile ]);
					delete testSceneSH2[0];
					testSceneSH2[0] = NULL;
				}
				else
				{
					if( testSceneSH2[0]->m_lNumVarPrim )
					{
						viewCam.setCam(testSceneSH2[0]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.x,
										-testSceneSH2[0]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.y,
										-testSceneSH2[0]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.z,
										testSceneSH2[0]->m_pcVarPrim[ 0 ].m_sBaseHeader.maxExtent.x,
										-testSceneSH2[0]->m_pcVarPrim[ 0 ].m_sBaseHeader.maxExtent.y,
										-testSceneSH2[0]->m_pcVarPrim[ 0 ].m_sBaseHeader.maxExtent.z,
										0,1,0);
					}
					else if( testSceneSH2[0]->m_lNumStaticPrim )
					{
						viewCam.from.x = testSceneSH2[0]->m_pcStaticPrim[ 0 ].m_sBaseHeader.minExtent.x;
						viewCam.from.y = -testSceneSH2[0]->m_pcStaticPrim[ 0 ].m_sBaseHeader.minExtent.y;
						viewCam.from.z = -testSceneSH2[0]->m_pcStaticPrim[0].m_sBaseHeader.minExtent.z;
					}
				}

			}

		}

		sprintf(curFileInfo,"FILE: %s",SH2SceneFiles[curSH2SceneFile]);
	}

	if (GetAsyncKeyState(VK_RSHIFT) & 0x8000)
	{
		if( curSH2SceneFile < numSH2SceneFiles )
		{
			int k;
			string offsetStr;
//			SH2_MapLoader *tScenePtr;
			if(testSceneSH2[0])
			{
				if( clearAllTex )
				{
					sh2TexList.DeleteAllTex( );
				}
				else
				{
	
					for( k = 0; k < testSceneSH2[0]->m_sOffsetUnknown.numUnknowDataSets; k++ )
					{
						//sprintf(offsetStr,"%15ld",testSceneSH2[0]->m_psUnknownData[ k ].id );
						offsetStr = format("%15ld", testSceneSH2[0]->m_psUnknownData[k].id);
						//LogFile(TEST_LOG,"CHECK: About to clean texture [%s]",offsetStr);
						sh2TexList.DeleteTex(offsetStr);
					}
				}

				delete testSceneSH2[0];
				testSceneSH2[0] = NULL;
			}

			for( k = 0; k < numScenes-1; k++)
				testSceneSH2[k] = testSceneSH2[k+1];
			testSceneSH2[numScenes-1] = NULL;
			
			curSH2SceneFile = (curSH2SceneFile + 1) % numSH2SceneFiles;

			testSceneSH2[numScenes-1] = new SH2_MapLoader;
			if( numScenes != 1 )
			{
				if(!testSceneSH2[numScenes-1]->LoadMap( SH2SceneFiles[ curSH2SceneFile ].string().c_str() ) )
				{
					LogFile(ERROR_LOG,"Process_SH2_SceneKeyInput() - ERROR: Could not load map file [%s]",SH2SceneFiles[ curSH2SceneFile ]);
					delete testSceneSH2[numScenes-1];
					testSceneSH2[numScenes-1] = NULL;
				}
			}
			else
			{
				while( !testSceneSH2[numScenes-1]->LoadMap( SH2SceneFiles[ curSH2SceneFile ].string().c_str() )
					&& curSH2SceneFile < numSH2SceneFiles )
				{
					curSH2SceneFile++;
					if( curSH2SceneFile == numSH2SceneFiles )
					{
						if( looped )
						{
							curSH2SceneDir = (curSH2SceneDir + 1)%numSH2SceneFiles;
							dirLooped = 0;
							Load_SH2_SceneFile( SH2SceneFiles[curSH2SceneDir] );
							return;
						}
						curSH2SceneFile = 0;
						looped = true;
					}
				}
					

				if(!testSceneSH2[numScenes-1]->isSceneValid())
				{
					LogFile(ERROR_LOG,"Process_SH2_SceneKeyInput() - ERROR: Could not load map file [%s]",SH2SceneFiles[ curSH2SceneFile ]);
					delete testSceneSH2[numScenes-1];
					testSceneSH2[numScenes-1] = NULL;
				}
				else
				{
					if( testSceneSH2[numScenes-1]->m_lNumVarPrim )
					{
						//viewCam.from.x = testSceneSH2[numScenes-1]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.x;
						//viewCam.from.y = -testSceneSH2[numScenes-1]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.y;
						//viewCam.from.z = -testSceneSH2[numScenes-1]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.z;
						viewCam.setCam(testSceneSH2[numScenes-1]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.x,
										-testSceneSH2[numScenes-1]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.y,
										-testSceneSH2[numScenes-1]->m_pcVarPrim[ 0 ].m_sBaseHeader.minExtent.z,
										testSceneSH2[numScenes-1]->m_pcVarPrim[ 0 ].m_sBaseHeader.maxExtent.x,
										-testSceneSH2[numScenes-1]->m_pcVarPrim[ 0 ].m_sBaseHeader.maxExtent.y,
										-testSceneSH2[numScenes-1]->m_pcVarPrim[ 0 ].m_sBaseHeader.maxExtent.z,
										0,1,0);
					}
					else if( testSceneSH2[numScenes-1]->m_lNumStaticPrim )
					{
						viewCam.from.x = testSceneSH2[numScenes-1]->m_pcStaticPrim[ 0 ].m_sBaseHeader.minExtent.x;
						viewCam.from.y = -testSceneSH2[numScenes-1]->m_pcStaticPrim[ 0 ].m_sBaseHeader.minExtent.y;
						viewCam.from.z = -testSceneSH2[numScenes-1]->m_pcStaticPrim[0].m_sBaseHeader.minExtent.z;
					}
				}
			}

		}

		sprintf(curFileInfo,"FILE: %s",SH2SceneFiles[curSH2SceneFile]);
	}
	

			//if (GetAsyncKeyState(VK_F5) & 0x8000)
			//if (GetAsyncKeyState(VK_F6) & 0x8000)
			//if (GetAsyncKeyState(VK_F3) & 0x8000)
			//if (GetAsyncKeyState(VK_F4) & 0x8000) 
	if(GetAsyncKeyState(VK_F2) & 0x8000)
	{
		dumpModel = true;
		int k;
		char tempName[ 256 ];
		for( k = 0; k < numScenes; k++ )
		{
			if( testSceneSH2[ k ] != NULL )
			{
				strcpy( tempName, testSceneSH2[ k ]->m_sFilename.c_str( ) );
				delete testSceneSH2[ k ];
				testSceneSH2[ k ] = new SH2_MapLoader;
				testSceneSH2[ k ]->LoadMap( tempName );
			}
		}

		/*
		int k,j;
		char offsetStr[20];
		SH2_MapLoader *tScenePtr;

		for( j = 0; j < numScenes; j ++ )
			if( testSceneSH2[j] != NULL )
				break;

		if(testSceneSH2[j])
		{
			sprintf(offsetStr,"%ld",testSceneSH2[j]->baseOffset);

			delete testSceneSH2[j];
			testSceneSH2[j] = NULL;

			for( k = textureMgr.textures.size(); k > 0; k-- )
			{
				if( clearAllTex )
				{
					if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
						LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
				}
				else if(strncmp(textureMgr.textures[k-1].texName.c_str(),offsetStr,strlen(offsetStr))==0)
				{
					if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
						LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
				}
			}
		}

		testSceneSH2[j] = new SH2_MapLoader;

		if(!testSceneSH2[j]->loadArcScene( sceneFiles[curSceneFile], sceneModelNum ))
		{
			LogFile(ERROR_LOG,"MessagePump::Paint - Could not load scene # %d",sceneModelNum);
			delete testSceneSH2[j];
			testSceneSH2[j] = NULL;
		}
		textureMgr.checkResident();
		*/
		//dumpModel = false;
	}


}



//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void Load_SH3_SceneFile( filesystem::path& fileToLoad )
{
	int k;
	int numLoaded;
	bool doTrans = true;

	/*k = strlen(fileToLoad) - strlen("bgcc.arc");

	if( strcmp(&(fileToLoad[k]),"bgcc.arc") == 0 )
		doTrans = true;
	else
		doTrans = false;*/

	clearAllTex = !doTrans;

	//---[ CLEAN UP OLD SCENE, IF IT EXISTS ]---//

	minSceneNum = sceneModelNum = testScene.getMinScene( fileToLoad.string().c_str() );
	maxSceneNum   = testScene.getMaxScene( fileToLoad.string().c_str() );

	if( testScene2 )
	{
		for( k = 0; k < numScenes; k ++)
		{
			if( testScene2[k] )
				delete testScene2[k];
			testScene2[k] = NULL;
		}
		SAFEDELETE(testScene2);

		//--[ Clean Up Scene Textures ]--/
		for( k = textureMgr.textures.size(); k > 0; k-- )
		{
			if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
				LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
		}
	}

//	minSceneNum = sceneModelNum = testScene2[0].getMinScene( fileToLoad );
//	maxSceneNum   = testScene2[0].getNumScene( fileToLoad );
	if( debugMode )LogFile(ERROR_LOG,"FILE [%s]  Scene Numbers [ min: %d  max: %d ]",fileToLoad,minSceneNum,maxSceneNum);

	if( doTrans )
		numScenes = sceneLimit;
	else
		numScenes = 1;
//LogFile( ERROR_LOG, "CHECK - NumScenes = %ld",numScenes);

	testScene2 = new SceneMap*[numScenes];

	for( k = 0; k < numScenes; k ++ )
		testScene2[k] = NULL;

	for( numLoaded = 0, k = sceneModelNum; k < maxSceneNum && numLoaded < numScenes; k ++, numLoaded++ )
	{
		testScene2[numLoaded] = new SceneMap;
		printText(dScreenRes[screenDimMode].w - 64,dScreenRes[screenDimMode].h - numLoaded*20,0,"Loading...",&white);

		while(!testScene2[numLoaded]->loadArcScene( fileToLoad.string().c_str(), k) && k < maxSceneNum && numLoaded < numScenes )
			k++;

		if( k < maxSceneNum && numLoaded < numScenes)
		{
			if( doTrans )
			{
				/*viewCam.setCam( .1f*testScene2[0]->mainHeader.skybox[0].x,
					.1f*testScene2[numLoaded]->mainHeader.skybox[0].y,
					.1f*testScene2[numLoaded]->mainHeader.skybox[0].z,
					.1f*testScene2[numLoaded]->mainHeader.skybox[7].x,
					.1f*testScene2[numLoaded]->mainHeader.skybox[7].y,
					.1f*testScene2[numLoaded]->mainHeader.skybox[7].z,
					0,1,0);
				*/viewCam.setCam(0.1f * (testScene2[numLoaded]->sceneData[1].min.x + testScene2[numLoaded]->mainHeader.transMat.mat[12]),
							-0.1f * (testScene2[numLoaded]->sceneData[1].min.y + testScene2[numLoaded]->mainHeader.transMat.mat[13]),
							-0.1f * (testScene2[numLoaded]->sceneData[1].min.z + testScene2[numLoaded]->mainHeader.transMat.mat[14]),
							-0.1f * (testScene2[numLoaded]->sceneData[1].max.x + testScene2[numLoaded]->mainHeader.transMat.mat[12]),
							-0.1f * (testScene2[numLoaded]->sceneData[1].max.y + testScene2[numLoaded]->mainHeader.transMat.mat[13]),
							-0.1f * (testScene2[numLoaded]->sceneData[1].max.z + testScene2[numLoaded]->mainHeader.transMat.mat[14]),
							0,1,0);
							//*/
			}
			else
			{
				/*viewCam.setCam( .1f*testScene2[0]->mainHeader.skybox[0].x,
					.1f*testScene2[numLoaded]->mainHeader.skybox[0].y,
					.1f*testScene2[numLoaded]->mainHeader.skybox[0].z,
					.1f*testScene2[numLoaded]->mainHeader.skybox[7].x,
					.1f*testScene2[numLoaded]->mainHeader.skybox[7].y,
					-.1f*testScene2[numLoaded]->mainHeader.skybox[7].z,
					0,1,0);
				*/viewCam.setCam(0.1f * (testScene2[numLoaded]->sceneData[1].min.x + testScene2[numLoaded]->mainHeader.transMat.mat[12]),
							-0.1f * (testScene2[numLoaded]->sceneData[1].min.y + testScene2[numLoaded]->mainHeader.transMat.mat[13]),
							-0.1f * (testScene2[numLoaded]->sceneData[1].min.z + testScene2[numLoaded]->mainHeader.transMat.mat[14]),
							-0.1f * (testScene2[numLoaded]->sceneData[1].max.x + testScene2[numLoaded]->mainHeader.transMat.mat[12]),
							-0.1f * (testScene2[numLoaded]->sceneData[1].max.y + testScene2[numLoaded]->mainHeader.transMat.mat[13]),
							-0.1f * (testScene2[numLoaded]->sceneData[1].max.z + testScene2[numLoaded]->mainHeader.transMat.mat[14]),
							0,1,0);
							//*/
				//viewCam.from.x = .1f * testScene2[numLoaded]->sceneData[0].verts[0].vert.x;
				//viewCam.from.y = -.1f * testScene2[numLoaded]->sceneData[0].verts[0].vert.y;
				//viewCam.from.z = -.1f * testScene2[numLoaded]->sceneData[0].verts[0].vert.z;
			}

			LogFile(ERROR_LOG,"viewCam [%f %f %f]",viewCam.from.x,viewCam.from.y,viewCam.from.z);
		}
		else if( k >= maxSceneNum && numLoaded < numScenes )
		{
		
			delete testScene2[numLoaded];
			testScene2[numLoaded] = NULL;

		}
	}
}


//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void Process_SH3_SceneKeyInput( )
{
	if (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
	{
		curSceneFile --;
		if( curSceneFile < 0 )
			curSceneFile = numSH3SceneFiles - 1;
		curSceneFile %= numSH3SceneFiles;
		Load_SH3_SceneFile( SH3SceneFiles[curSceneFile] );
	}

	if (GetAsyncKeyState(VK_RCONTROL) & 0x8000)
	{
		curSceneFile ++;
		curSceneFile %= numSH3SceneFiles;
		Load_SH3_SceneFile( SH3SceneFiles[curSceneFile] );
	}

	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000)
	{
		if( sceneModelNum > minSceneNum )
		{
			int k;
			char offsetStr[20];
//			SceneMap *tScenePtr;
			if(testScene2[numScenes-1])
			{
				sprintf(offsetStr,"%ld",testScene2[numScenes-1]->baseOffset);

				delete testScene2[numScenes-1];
				testScene2[numScenes-1] = NULL;

				for( k = textureMgr.textures.size(); k > 0; k-- )
				{
					if( clearAllTex )
					{
						if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
							LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
					}
					else if(strncmp(textureMgr.textures[k-1].texName.c_str(),offsetStr,strlen(offsetStr))==0)
					{
						if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
							LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
					}
				}
			}

			for( k = numScenes-1; k > 0; k--)
				testScene2[k] = testScene2[k-1];
			testScene2[0] = NULL;
			sceneModelNum--;

			testScene2[0] = new SceneMap;
			if( numScenes != 1 )
			{
				if(!testScene2[0]->loadArcScene( SH3SceneFiles[curSceneFile].string().c_str(), sceneModelNum ))
				{
					LogFile(ERROR_LOG,"MessagePump::Paint - Could not load scene # %d",sceneModelNum);
					delete testScene2[0];
					testScene2[0] = NULL;
				}
			}
			else
			{
				while( !testScene2[0]->loadArcScene( SH3SceneFiles[curSceneFile].string().c_str(), sceneModelNum ) && sceneModelNum > minSceneNum)
					sceneModelNum--;
				if(!testScene2[0]->isSceneValid())
				{
					LogFile(ERROR_LOG,"MessagePump::Paint - Could not load scene # %d",sceneModelNum);
					delete testScene2[0];
					testScene2[0] = NULL;
				}
			}

			textureMgr.checkResident();

			if( testScene2[0] && numScenes == 1 && testScene2[0]->numScenePrimitives > 1)
			{
				/*viewCam.setCam( .1f*testScene2[0]->mainHeader.skybox[0].x,
					.1f*testScene2[0]->mainHeader.skybox[0].y,
					.1f*testScene2[0]->mainHeader.skybox[0].z,
					.1f*testScene2[0]->mainHeader.skybox[7].x,
					.1f*testScene2[0]->mainHeader.skybox[7].y,
					-.1f*testScene2[0]->mainHeader.skybox[7].z,
					0,1,0);
				/*/viewCam.setCam(0.1f * (testScene2[0]->sceneData[1].min.x + testScene2[0]->mainHeader.transMat.mat[12]),
							-0.1f * (testScene2[0]->sceneData[1].min.y + testScene2[0]->mainHeader.transMat.mat[13]),
							-0.1f * (testScene2[0]->sceneData[1].min.z + testScene2[0]->mainHeader.transMat.mat[14]),
							-0.1f * (testScene2[0]->sceneData[1].max.x + testScene2[0]->mainHeader.transMat.mat[12]),
							-0.1f * (testScene2[0]->sceneData[1].max.y + testScene2[0]->mainHeader.transMat.mat[13]),
							-0.1f * (testScene2[0]->sceneData[1].max.z + testScene2[0]->mainHeader.transMat.mat[14]),
							0,1,0);
							//*/
				//viewCam.from.x = .1f * testScene2[0]->sceneData[testScene2[0]->numScenePrimitives-1].verts[0].vert.x;
				//viewCam.from.y = -.1f * testScene2[0]->sceneData[testScene2[0]->numScenePrimitives-1].verts[0].vert.y;
				//viewCam.from.z = -.1f * testScene2[0]->sceneData[testScene2[0]->numScenePrimitives-1].verts[0].vert.z;
			}
			else
				LogFile(TEST_LOG,"CHECK: This message should not appear");
			//else
			//	viewCam.reset();

		}
	}

	if (GetAsyncKeyState(VK_RSHIFT) & 0x8000)
	{
		if( sceneModelNum < maxSceneNum )
		{
			int k;
			char offsetStr[20];
//			SceneMap *tScenePtr;

			if(testScene2[0])
			{
				sprintf(offsetStr,"%ld",testScene2[0]->baseOffset);

				delete testScene2[0];
				testScene2[0] = NULL;

				for( k = textureMgr.textures.size(); k > 0; k-- )
				{
					if( clearAllTex )
					{
						if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
							LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
					}
					else if(strncmp(textureMgr.textures[k-1].texName.c_str(),offsetStr,strlen(offsetStr))==0)
					{
						if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
							LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
					}
				}
			}

			for( k = 0; k < numScenes-1; k++)
				testScene2[k] = testScene2[k+1];

			testScene2[numScenes-1] = NULL;
			sceneModelNum++;

			testScene2[numScenes-1] = new SceneMap;

			if( numScenes != 1 )
			{
				if(!testScene2[numScenes-1]->loadArcScene( SH3SceneFiles[curSceneFile].string().c_str(), sceneModelNum+numScenes-1))
				{
					LogFile(ERROR_LOG,"MessagePump::Paint - Could not load scene # %d",sceneModelNum+numScenes-1);
					delete testScene2[numScenes-1];
					testScene2[numScenes-1] = NULL;
				}
			}
			else
			{
				while( !testScene2[numScenes-1]->loadArcScene( SH3SceneFiles[curSceneFile].string().c_str(), sceneModelNum ) && sceneModelNum < maxSceneNum)
					sceneModelNum++;
				if(!testScene2[numScenes-1]->isSceneValid())
				{
					LogFile(ERROR_LOG,"MessagePump::Paint - Could not load scene # %d",sceneModelNum);
					delete testScene2[numScenes-1];
					testScene2[numScenes-1] = NULL;
				}
			}

			textureMgr.checkResident();

			if( testScene2[k] && numScenes == 1 && testScene2[0]->numScenePrimitives > 1)
			{
				/*viewCam.setCam( .1f*testScene2[0]->mainHeader.skybox[0].x,
					.1f*testScene2[0]->mainHeader.skybox[0].y,
					.1f*testScene2[0]->mainHeader.skybox[0].z,
					.1f*testScene2[0]->mainHeader.skybox[7].x,
					.1f*testScene2[0]->mainHeader.skybox[7].y,
					-.1f*testScene2[0]->mainHeader.skybox[7].z,
					0,1,0);
				/*/viewCam.setCam(0.1f * (testScene2[0]->sceneData[1].min.x + testScene2[0]->mainHeader.transMat.mat[12]),
							-0.1f * (testScene2[0]->sceneData[1].min.y + testScene2[0]->mainHeader.transMat.mat[13]),
							-0.1f * (testScene2[0]->sceneData[1].min.z + testScene2[0]->mainHeader.transMat.mat[14]),
							-0.1f * (testScene2[0]->sceneData[1].max.x + testScene2[0]->mainHeader.transMat.mat[12]),
							-0.1f * (testScene2[0]->sceneData[1].max.y + testScene2[0]->mainHeader.transMat.mat[13]),
							-0.1f * (testScene2[0]->sceneData[1].max.z + testScene2[0]->mainHeader.transMat.mat[14]),
							0,1,0);
							//*/
				//viewCam.from.x = .1f * testScene2[0]->sceneData[testScene2[0]->numScenePrimitives-1].verts[0].vert.x;
				//viewCam.from.y = -.1f * testScene2[0]->sceneData[testScene2[0]->numScenePrimitives-1].verts[0].vert.y;
				//viewCam.from.z = -.1f * testScene2[0]->sceneData[testScene2[0]->numScenePrimitives-1].verts[0].vert.z;
			}
			else
				LogFile(TEST_LOG,"CHECK: This message should not appear");
			//else
			//	viewCam.reset();

		}
			
	}
	
			//if (GetAsyncKeyState(VK_F3) & 0x8000)
			//if (GetAsyncKeyState(VK_F4) & 0x8000) 
	if(GetAsyncKeyState(VK_F2) & 0x8000)
	{
		dumpScene = true;
		int k,j;
		char offsetStr[20];
//		SceneMap *tScenePtr;

		for( j = 0; j < numScenes; j ++ )
			if( testScene2[j] != NULL )
				break;

		if(testScene2[j])
		{
			sprintf(offsetStr,"%ld",testScene2[j]->baseOffset);

			delete testScene2[j];
			testScene2[j] = NULL;

			for( k = textureMgr.textures.size(); k > 0; k-- )
			{
				if( clearAllTex )
				{
					if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
						LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
				}
				else if(strncmp(textureMgr.textures[k-1].texName.c_str(),offsetStr,strlen(offsetStr))==0)
				{
					if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
						LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
				}
			}
		}

		testScene2[j] = new SceneMap;

		if(!testScene2[j]->loadArcScene( SH3SceneFiles[curSceneFile].string().c_str(), sceneModelNum ))
		{
			LogFile(ERROR_LOG,"MessagePump::Paint - Could not load scene # %d",sceneModelNum);
			delete testScene2[j];
			testScene2[j] = NULL;
		}
		textureMgr.checkResident();
	}

	sprintf(curFileInfo,"FILE: %s  SCENE: %d of [%d - %d]",SH3SceneFiles[curSceneFile], sceneModelNum,minSceneNum,maxSceneNum-1);
}



//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
bool Load_SH3_ModelFile( filesystem::path& fileToLoad )
{
	int k;

	//---[ CLEAN UP OLD MODEL, IF IT EXISTS ]---//

	if( debugMode )LogFile( ERROR_LOG, "Load_SH3_ModelFile( ) - Loading SH3 Models from [%s]",fileToLoad);
	//testAct.releaseModelData();
	testActAnim.ReleaseData( );
	curFrame = 0;
	g_bHasAnim = false;

	//--[ Clean Up Scene Textures ]--/
	for( k = textureMgr.textures.size(); k > 0; k-- )
	{
		//LogFile( ERROR_LOG, "About to delete tex # %d of %d",k,textureMgr.textures.size());
		if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
			LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
	}
	
	if( debugMode )
		LogFile( ERROR_LOG, "                      - Checking for minimum and maximum model numbers");
	minModelNum = modelNum = testAct.getMinModel( fileToLoad.string().c_str() );
	maxModelNum   = testAct.getMaxModel( fileToLoad.string().c_str() );

	if( debugMode )
		LogFile( ERROR_LOG, "                      - Model Numbers [ min: %d  max: %d ]",minModelNum,maxModelNum);


	k = modelNum;
	while( k <= maxModelNum )
	{
		if(testAct.loadModel(fileToLoad.string().c_str(),k))
			break;
		++k;
	}
	
	if( modelNum > maxModelNum )
		return false;

	testActAnim.AttachModel( & testAct );
	if( testActAnim.LoadAnim( ) )
		g_bHasAnim = true;
	else
		g_bHasAnim = false;


	viewCam.reset();
	return true;
}



//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void Process_SH3_ModelKeyInput( )
{
//	int k;
	bool sh3ModelLooped = false;
	
//	LogFile( ERROR_LOG, "BASE: Process_SH3_ModelKeyInput - Count Model Files: %ld   Cur File Num: %ld   Model: %ld",numModelFiles,curModelFile, modelNum);
	if (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
	{
		throttleOn();
		testActAnim.ReleaseData( );
		curFrame = 0;
		do
		{
			curModelFile --;
			if( curModelFile < 0 )
			{
				if( sh3ModelLooped )
				{
					MessageBox( NULL, "ERROR","No SH3 Model Files Exist In The Data Directory - Check default.cfg",MB_OK);
					if( numSH2SceneFiles )
					{
						sh2_sceneMode = true;
						sh3_sceneMode = false;
						sh3_modelMode = false;
						dirLooped = 0;
						Load_SH2_SceneFile( SH2SceneFiles[ curSH2SceneDir ] );
					}
					else if( numSH3SceneFiles )
					{
						sh2_sceneMode = false;
						sh3_sceneMode = true;
						sh3_modelMode = false;
						Load_SH3_SceneFile( SH3SceneFiles[curSceneFile] );
					}
					return;
				}
				sh3ModelLooped = true;
				curModelFile = numSH3ModelFiles - 1;
			}
			curModelFile %= numSH3ModelFiles;
//LogFile( ERROR_LOG, "Process_SH3_ModelKeyInput - Count Model Files: %ld   Cur File Num: %ld   Model: %ld",numModelFiles,curModelFile, modelNum);
		}while(!Load_SH3_ModelFile( SH3ModelFiles[curModelFile]));
	}

	if (GetAsyncKeyState(VK_RCONTROL) & 0x8000)
	{
		throttleOn();
		testActAnim.ReleaseData( );
		curFrame = 0;
		g_bHasAnim = false;
//LogFile( ERROR_LOG, "Process_SH3_ModelKeyInput - Count Model Files: %ld   Cur File Num: %ld   Model: %ld",numModelFiles,curModelFile, modelNum);
		do
		{
			curModelFile ++;
	
			if( curModelFile == numSH3ModelFiles )
			{
				if( sh3ModelLooped )
				{
					MessageBox( NULL, "ERROR","No SH3 Model Files Exist In The Data Directory - Check default.cfg",MB_OK);
					return;
				}
				sh3ModelLooped = true;
			}
			curModelFile %= numSH3ModelFiles;
//LogFile( ERROR_LOG, "Process_SH3_ModelKeyInput - Count Model Files: %ld   Cur File Num: %ld   Model: %ld",numModelFiles,curModelFile, modelNum);
		}while(!Load_SH3_ModelFile( SH3ModelFiles[curModelFile]));
	}


	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000)
	{
		if( modelNum > minModelNum )
		{
			int k;
			
			throttleOn();
			for( k = textureMgr.textures.size(); k > 0; k-- )
			{
				if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
					LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
			}
			k = curModelFile;
			testActAnim.ReleaseData( );
			curFrame = 0;
			g_bHasAnim = false;
			do
			{
				modelNum --;
				if( modelNum < minModelNum )
				{
					if( sh3ModelLooped )
					{
						curModelFile = (curModelFile + 1 ) % numSH3ModelFiles;
						if( curModelFile == k )
						{
							MessageBox( NULL, "TERMINAL ERROR","Check your default config, or contact perdedork@yahoo.com",MB_OK);
							PostQuitMessage(1);
							return;
						}
						minModelNum = testAct.getMinModel( SH3ModelFiles[curModelFile].string().c_str() );
						maxModelNum = modelNum = testAct.getMaxModel( SH3ModelFiles[curModelFile].string().c_str() );
						sh3ModelLooped = false;
						--modelNum;
					}
					else
					{
						modelNum = maxModelNum;
						sh3ModelLooped = true;
					}
				}
//	LogFile( ERROR_LOG, "Process_SH3_ModelKeyInput - Count Model Files: %ld   Cur File Num: %ld   Model: %ld",numModelFiles,curModelFile, modelNum);
			}while(!testAct.loadModel(SH3ModelFiles[curModelFile].string().c_str(), modelNum ));

			testActAnim.AttachModel( & testAct );
			if( testActAnim.LoadAnim( ) )
				g_bHasAnim = true;
			else
				g_bHasAnim = false;


		}
	}


	if (GetAsyncKeyState(VK_RSHIFT) & 0x8000)
	{
		if( modelNum < maxModelNum )
		{
			int k;
			
			throttleOn();
			for( k = textureMgr.textures.size(); k > 0; k-- )
			{
				if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
					LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
			}
			k = curModelFile;
			testActAnim.ReleaseData( );
			curFrame = 0;
			g_bHasAnim = false;
			do
			{
				modelNum ++;
				if( modelNum == maxModelNum )
				{
					if( sh3ModelLooped )
					{
						curModelFile = (curModelFile + 1 ) % numSH3ModelFiles;
						if( curModelFile == k )
						{
							MessageBox( NULL, "TERMINAL ERROR","Check your default config, or contact perdedork@yahoo.com",MB_OK);
							PostQuitMessage(1);
							return;
						}
						minModelNum = modelNum = testAct.getMinModel( SH3ModelFiles[curModelFile].string().c_str());
						maxModelNum = testAct.getMaxModel( SH3ModelFiles[curModelFile].string().c_str());
						sh3ModelLooped = false;
					}
					else
					{
						modelNum = minModelNum;
						sh3ModelLooped = true;
					}
				}
//	LogFile( ERROR_LOG, "Process_SH3_ModelKeyInput - Count Model Files: %ld   Cur File Num: %ld   Model: %ld",numModelFiles,curModelFile, modelNum);
			}while(!testAct.loadModel(SH3ModelFiles[curModelFile].string().c_str(), modelNum ));

			testActAnim.AttachModel( & testAct );
			if( testActAnim.LoadAnim( ) )
				g_bHasAnim = true;
			else
				g_bHasAnim = false;
		
		}
	}

	if(GetAsyncKeyState(VK_F2) & 0x8000)
	{
		dumpModel = true;
		for( long k = textureMgr.textures.size(); k > 0; k-- )
		{
			if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
				LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
		}
		testAct.loadModel(SH3ModelFiles[curModelFile].string().c_str(), modelNum );
		

		testActAnim.ReleaseData( );
		curFrame = 0;
		g_bHasAnim = false;
		testActAnim.AttachModel( & testAct );
		if( testActAnim.LoadAnim( ) )
		{
			g_bHasAnim = true;
			testActAnim.ExportSMD();
			testActAnim.ExportSMDAnimation();
		}
		else
		{
			testAct.ExportSMD();
			g_bHasAnim = false;
		}
		

		dumpModel = false;
	}
	sprintf(curFileInfo,"FILE: %s  SCENE: %d of %d",SH3ModelFiles[curModelFile], modelNum, maxModelNum - 1 );
}




//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void Load_SH2_ModelFile( filesystem::path& fileToLoad )
{
//	int k;
//	int numLoaded;
	bool looped = false;
	bool origDebugMode = debugMode;
	bool foundAnim = false;
	//char nameLen = strlen( fileToLoad );
//	long startIndex;
	int badLoopCounter = 0;

	/*if( !fileToLoad || dirLooped > 1 )
		return;*/

	clearAllTex = true;

	/*if( debugMode )
		LogFile( ERROR_LOG, "Load_SH2_ModelFile( %s ) - About to clean model file listing", fileToLoad );
	CleanDirectoryFilelist( SH2ModelFiles );*/
	
	if( debugMode )
		LogFile( ERROR_LOG, "Load_SH2_ModelFile( %s ) - About to clean anim file listing - num: %ld", fileToLoad, numSH2AnimFiles );
	//CleanDirectoryFilelist( numSH2AnimFiles, &animSH2Files );

	//---[ CLEAN UP OLD SCENE, IF IT EXISTS ]---//
	
	if( debugMode )
		LogFile( ERROR_LOG, "Load_SH2_ModelFile( %s ) - About to delete model data", fileToLoad );
	sh2Act.deleteData( );
	if( debugMode )
		LogFile( ERROR_LOG, "Load_SH2_ModelFile( %s ) - About to delete old texture data", fileToLoad );
	sh2TexList.ReleaseAllTex( );
	if( debugMode )
		LogFile( ERROR_LOG, "Load_SH2_ModelFile( %s ) - Done with cleanup - now loading data for current dir", fileToLoad );


	curSH2ModelFile = 0;
	//numSH2ModelFiles = GetDirectoryFileList( fileToLoad, "*.mdl", SH2ModelFiles);

//	curSH2AnimFile = 0;
//	numSH2AnimFiles = GetDirectoryFilelist( fileToLoad, "*.anm",&animSH2Files);

//debugMode = true;
	sh2TexList.BuildTexList( );
//debugMode = origDebugMode;
	
	if( debugMode )LogFile(ERROR_LOG,"Load_SH2_ModelFile() - FILE [%s]  Model Files [ first: \"%s\"  last: \"%s\" ]",fileToLoad,SH2ModelFiles[0],SH2ModelFiles[numSH2ModelFiles-1]);

	while( !sh2Act.loadData( SH2ModelFiles[ curSH2ModelFile ].string().c_str())
			&& curSH2ModelFile < numSH2ModelFiles )
	{
		badLoopCounter++;
		curSH2ModelFile++;

		if( (curSH2ModelFile >= numSH2ModelFiles )
			|| (!numSH2ModelFiles || numSH2ModelFiles == 1)
			|| badLoopCounter > 50 )
		{
			//if( looped || !numSH2SceneFiles || numSH2SceneFiles == 1 || badLoopCounter > 50 + numScenes )
			//{
				if( g_iMoveDir < 0 )
				{
					curSH2ModelDir = (curSH2ModelDir - 1);
					if( curSH2ModelDir < 0 )
					{
						dirLooped ++;
						curSH2ModelDir +=numSH2ModelFiles;
					}
				}
				else
				{
					if( curSH2ModelDir + 1 == numSH2ModelFiles )
						dirLooped ++;
					curSH2ModelDir = (curSH2ModelDir + 1)%numSH2ModelFiles;
				}

				if( badLoopCounter > 50 )
					LogFile( ERROR_LOG,"Load_SH2_ModelFile( %s ) - ERROR: Bad Loop Counter Reached threshold %d In Directory",fileToLoad,badLoopCounter);
				if( !numSH2ModelFiles || numSH2ModelFiles == 1)
					LogFile( ERROR_LOG, "Load_SH2_ModelFile( %s ) - ERROR: No MDL Files Found In Directory",fileToLoad);
	
				Load_SH2_ModelFile( SH2ModelFiles[curSH2ModelDir]);
				return;
			//}
			curSH2ModelFile = 0;
			looped = true;
		}

		if( debugMode )
			LogFile(ERROR_LOG,"Load_SH2_ModelFile() - POST CHECK: curSH2SceneFile is [%ld]= %s",curSH2ModelFile,SH2ModelFiles[curSH2ModelFile]);
			
	}

	if( curSH2ModelFile < numSH2ModelFiles && sh2Act.m_pcTexSetMapping )
	{
		viewCam.reset( );
		if( sh2_anim )
		{
			char l_cModelName[ 256 ];

			if( baseName( (char*)SH2ModelFiles[ curSH2ModelFile ].string().c_str(), l_cModelName))
			{
				LogFile( ERROR_LOG, "CHECKKKKKKKKKKK: The model '%s' basename is '%s'",SH2ModelFiles[ curSH2ModelFile ], l_cModelName );
				for( curSH2AnimFile = 0; curSH2AnimFile < numSH2AnimFiles && ! foundAnim; curSH2AnimFile ++ )
				{
					if( strstr( SH2AnimFiles[ curSH2AnimFile ].string().c_str(), l_cModelName))
					{
						if( sh2Act.loadAnim( testActAnim, SH2AnimFiles[ curSH2AnimFile ].string().c_str()) )
							foundAnim = true;
					}
				//	LogFile( ERROR_LOG, "CHEXXXXXXXXX: Just compared '%s' to '%s'",animSH2Files[ curSH2AnimFile ], l_cModelName );
				//	LogFile( ERROR_LOG, "\tstrstr = %ld",strstr( animSH2Files[ curSH2AnimFile ], l_cModelName ) );
				}
			}
		}

		if( foundAnim )
		{
			sh2Act.m_bHasAnim = true;
			g_bHasAnim = true;
		}
		else
		{
			sh2Act.m_bHasAnim = false;
			g_bHasAnim = false;
		}
	}
	
//	if( curSH2ModelFile )
//		curSH2ModelFile --;

	sprintf(curFileInfo,"FILE: %s",SH2ModelFiles[curSH2ModelFile]);

	if( debugMode )
		LogFile(ERROR_LOG,"Load_SH2_ModelFile() - EXIT CHECK: curSH2ModelFile is [%ld]= %s",curSH2ModelFile,SH2ModelFiles[curSH2ModelFile]);
}


//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void Process_SH2_ModelKeyInput( )
{
	bool looped = false;
	bool foundAnim = false;

	//if( debugMode ) LogFile( ERROR_LOG, "Process_SH2_ModelKeyInput( ) - Start");

	if (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
	{
	//	if( debugMode ) LogFile( ERROR_LOG, "Process_SH2_ModelKeyInput( ) - Left Control");
		curSH2ModelDir --;
		if( curSH2ModelDir < 0 )
			curSH2ModelDir = numSH2ModelFiles - 1;
		curSH2ModelDir %= numSH2ModelFiles;

		g_iMoveDir = -1;
		dirLooped = 0;
		curSH2ModelFile = 0;
		
		Load_SH2_ModelFile( SH2ModelFiles[ curSH2ModelDir ] );
		sprintf(curFileInfo,"FILE: %s",SH2ModelFiles[curSH2ModelFile]);
	}

	if (GetAsyncKeyState(VK_RCONTROL) & 0x8000)
	{
	//	if( debugMode ) LogFile( ERROR_LOG, "Process_SH2_ModelKeyInput( ) - Right Control");
		curSH2ModelDir ++;
		curSH2ModelDir %= numSH2ModelFiles;

		g_iMoveDir = 1;
		dirLooped = 0;
		curSH2ModelFile = 0;

		Load_SH2_ModelFile( SH2ModelFiles[ curSH2ModelDir ] );
		sprintf(curFileInfo,"FILE: %s",SH2ModelFiles[curSH2ModelFile]);
	}

	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000)
	{
	//	if( debugMode ) LogFile( ERROR_LOG, "Process_SH2_ModelKeyInput( ) - Left Shift");
		if( curSH2ModelFile > 0 )
		{
//			int k;
//			char offsetStr[20];
//			SH2_MapLoader *tScenePtr;
			sh2TexList.DeleteAllTex( );

			curSH2ModelFile--;
			if( curSH2ModelFile < 0 )
				curSH2ModelFile = numSH2ModelFiles - 1;

			sh2Act.deleteData( );
			
			while( !sh2Act.loadData( SH2ModelFiles[ curSH2ModelFile ].string().c_str()) && curSH2ModelFile >= 0 )
			{
				curSH2ModelFile--;
				if( curSH2ModelFile < 0 )
				{
					if( looped )
					{
						curSH2ModelDir = (curSH2ModelDir - 1);
						if( curSH2ModelDir < 0 )
							curSH2ModelDir +=numSH2ModelFiles;
						dirLooped = 0;
						Load_SH2_ModelFile( SH2ModelFiles[curSH2ModelDir] );
						return;
					}
					curSH2ModelFile += numSH2ModelFiles;
					looped = true;
				}
			}

			viewCam.reset( );
			if( sh2_anim )
			{
				char l_cModelName[ 256 ];

				if( baseName( (char*)SH2ModelFiles[ curSH2ModelFile ].string().c_str(), l_cModelName ) )
				{
					LogFile( ERROR_LOG, "CHECKKKKKKKKKKK: The model '%s' basename is '%s'",SH2ModelFiles[ curSH2ModelFile ], l_cModelName );
					for( curSH2AnimFile = 0; curSH2AnimFile < numSH2AnimFiles && ! foundAnim; curSH2AnimFile ++ )
					{
						if( strstr( SH2AnimFiles[ curSH2AnimFile ].string().c_str(), l_cModelName ) )
						{
							if( sh2Act.loadAnim( testActAnim, SH2AnimFiles[ curSH2AnimFile ].string().c_str()) )
								foundAnim = true;
						}
					//	LogFile( ERROR_LOG, "CHEXXXXXXXXX: Just compared '%s' to '%s'",animSH2Files[ curSH2AnimFile ], l_cModelName );
					//	LogFile( ERROR_LOG, "\tstrstr = %ld",strstr( animSH2Files[ curSH2AnimFile ], l_cModelName ) );
					}
				}
			}

			if( foundAnim )
			{
				sh2Act.m_bHasAnim = true;
				g_bHasAnim = true;
			}
			else
			{
				sh2Act.m_bHasAnim = false;
				g_bHasAnim = false;
			}
		}

		sprintf(curFileInfo,"FILE: %s",SH2ModelFiles[curSH2ModelFile]);
	}

	if (GetAsyncKeyState(VK_RSHIFT) & 0x8000)
	{
	//	if( debugMode ) LogFile( ERROR_LOG, "Process_SH2_ModelKeyInput( ) - Right Shift");
		if( curSH2SceneFile < numSH2SceneFiles )
		{
//			int k;
//			char offsetStr[20];
//			SH2_MapLoader *tScenePtr;
			sh2TexList.DeleteAllTex( );

			curSH2ModelFile++;
			if( curSH2ModelFile == numSH2ModelFiles )
				curSH2ModelFile = 0;

			sh2Act.deleteData( );
			
			while( !sh2Act.loadData( SH2ModelFiles[ curSH2ModelFile ].string().c_str()) && curSH2ModelFile < numSH2ModelFiles )
			{
				if( debugMode )LogFile( ERROR_LOG, "Process_SH2_ModelKeyInput( ) - NOTE: Couldn't load model file %ld of %ld, '%s' in dir '%s'\n\tAttempting next load...",
					curSH2ModelFile+1, numSH2ModelFiles, SH2ModelFiles[ curSH2ModelFile ],SH2ModelFiles[ curSH2ModelDir ] );
				curSH2ModelFile++;
				if( curSH2ModelFile == numSH2ModelFiles )
				{
					if( looped )
					{
						curSH2ModelDir = (curSH2ModelDir + 1) % numSH2ModelFiles;
						dirLooped = 0;
						Load_SH2_ModelFile( SH2ModelFiles[curSH2ModelDir] );
						return;
					}
					curSH2ModelFile = 0;
					looped = true;
				}
			}

			viewCam.reset( );
			if( sh2_anim )
			{
				char l_cModelName[ 256 ];

				if( baseName( (char*)SH2ModelFiles[ curSH2ModelFile ].string().c_str(), l_cModelName ) )
				{
					LogFile( ERROR_LOG, "CHECKKKKKKKKKKK: The model '%s' basename is '%s'",SH2ModelFiles[ curSH2ModelFile ], l_cModelName );
					for( curSH2AnimFile = 0; curSH2AnimFile < numSH2AnimFiles && ! foundAnim; curSH2AnimFile ++ )
					{
						if( strstr( SH2AnimFiles[ curSH2AnimFile ].string().c_str(), l_cModelName ) )
						{
							if( sh2Act.loadAnim( testActAnim, SH2AnimFiles[ curSH2AnimFile ].string().c_str()) )
								foundAnim = true;
						}
					//	LogFile( ERROR_LOG, "CHEXXXXXXXXX: Just compared '%s' to '%s'",animSH2Files[ curSH2AnimFile ], l_cModelName );
					//	LogFile( ERROR_LOG, "\tstrstr = %ld",strstr( animSH2Files[ curSH2AnimFile ], l_cModelName ) );
					}
				}
			}

			if( foundAnim )
			{
				sh2Act.m_bHasAnim = true;
				g_bHasAnim = true;
			}
			else
			{
				sh2Act.m_bHasAnim = false;
				g_bHasAnim = false;
			}
		
		}

		sprintf(curFileInfo,"FILE: %s",SH2ModelFiles[curSH2ModelFile]);
	}

	
	if(GetAsyncKeyState(VK_F2) & 0x8000)
	{
		dumpModel = true;
		/*
		int k,j;
		char offsetStr[20];
		SH2_MapLoader *tScenePtr;

		for( j = 0; j < numScenes; j ++ )
			if( testSceneSH2[j] != NULL )
				break;

		if(testSceneSH2[j])
		{
			sprintf(offsetStr,"%ld",testSceneSH2[j]->baseOffset);

			delete testSceneSH2[j];
			testSceneSH2[j] = NULL;

			for( k = textureMgr.textures.size(); k > 0; k-- )
			{
				if( clearAllTex )
				{
					if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
						LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
				}
				else if(strncmp(textureMgr.textures[k-1].texName.c_str(),offsetStr,strlen(offsetStr))==0)
				{
					if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
						LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
				}
			}
		}

		testSceneSH2[j] = new SH2_MapLoader;

		if(!testSceneSH2[j]->loadArcScene( sceneFiles[curSceneFile], sceneModelNum ))
		{
			LogFile(ERROR_LOG,"MessagePump::Paint - Could not load scene # %d",sceneModelNum);
			delete testSceneSH2[j];
			testSceneSH2[j] = NULL;
		}
		textureMgr.checkResident();
		*/
		dumpModel = false;
	}


}


//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void Load_SH4_File( filesystem::path& fileToLoad )
{
	int k;
//	int numLoaded;
	bool looped = false;
	bool origDebugMode = debugMode;
	//char nameLen = strlen( fileToLoad );
//	long startIndex;
	int badLoopCounter = 0;


	if( dirLooped > 1 )
		return;

	clearAllTex = true;

	//---[ CLEAN UP OLD SCENE, IF IT EXISTS ]---//
	for( k = textureMgr.textures.size(); k > 0; k-- )
	{
		if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
			LogFile(TEST_LOG,"Load_SH4_File() - ERROR: DID NOT Successfully delete tex");
	}

	sh4Act.deleteData( );

	while( !sh4Act.loadData( SH4Files[ curSH4File ].string().c_str() )
			&& curSH4File < numSH4Files )
	{
		badLoopCounter++;
		curSH4File++;

		if( (curSH4File >= numSH4Files )
			|| (!numSH4Files || numSH4Files == 1)
			|| badLoopCounter > 500 )
		{
			if( dirLooped )
				return;
			dirLooped ++;
			curSH4File = 0;
		}
		
		if( badLoopCounter > 500 )
			LogFile( ERROR_LOG,"Load_SH4_File( %s ) - ERROR: Bad Loop Counter Reached threshold %d In Directory",fileToLoad.string().c_str(),badLoopCounter);
		if( !numSH4Files || numSH4Files == 1)
			LogFile( ERROR_LOG, "Load_SH4_File( %s ) - ERROR: No Files Found In Directory",fileToLoad.string().c_str());
	
		if( debugMode )
			LogFile(ERROR_LOG,"Load_SH4_File() - POST CHECK: curSH4File is [%ld]= %s",curSH4File,SH4Files[curSH4File]);
			
	}

	if( curSH4File < numSH4Files && sh4Act.m_cVertPrim )
	{
		viewCam.reset( );
		if( false ) //sh2_anim )
		{
			while( !sh2Act.loadAnim( testActAnim, SH2AnimFiles[ curSH2AnimFile ].string().c_str() ) && curSH2AnimFile < numSH2AnimFiles )
				curSH2AnimFile++;
			if( curSH2AnimFile == numSH2AnimFiles )
			{
				sh2Act.m_bHasAnim = false;
				curSH2AnimFile = 0;
			}
			else
				g_bHasAnim = true;
		}
	}
	
//	if( curSH2ModelFile )
//		curSH2ModelFile --;

	sprintf(curFileInfo,"FILE: %s",SH4Files[curSH4File]);

	if( debugMode )
		LogFile(ERROR_LOG,"Load_SH4_File() - EXIT CHECK: curSH2ModelFile is [%ld]= %s",curSH4File,SH4Files[curSH4File]);
}

//----------------------------------------------------------------------------/
//-                                                                          -/
//-                                                                          -/
//----------------------------------------------------------------------------/
void Process_SH4_KeyInput( )
{
	int k;
//	int numLoaded;
	bool looped = false;
	bool origDebugMode = debugMode;
//	long startIndex;
	int badLoopCounter = 0;


	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000 || GetAsyncKeyState(VK_LCONTROL) & 0x8000)
	{
		if( curSH4File > 0 )
		{
			for( k = textureMgr.textures.size(); k > 0; k-- )
			{
				if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
					LogFile(TEST_LOG,"Process_SH4_KeyInput() - ERROR: DID NOT Successfully delete tex");
			}

			sh4Act.deleteData( );

			curSH4File--;

			while( !sh4Act.loadData( SH4Files[ curSH4File ].string().c_str() ) && curSH4File >=0)
			{
				badLoopCounter++;
				curSH4File--;

				if( (curSH4File < 0 )
					|| (!numSH4Files || numSH4Files == 1)
					|| badLoopCounter > 500 )
				{
					if( dirLooped )
						return;
					dirLooped ++;
					curSH4File = numSH4Files;
					looped = true;
				}
		
				if( badLoopCounter > 500 )
				{
					LogFile( ERROR_LOG,"Process_SH4_KeyInput( ) - ERROR: Bad Loop Counter Reached threshold %d In Directory",badLoopCounter);
					return;
				}
				

				if( debugMode )
					LogFile(ERROR_LOG,"Process_SH4_KeyInput() - POST CHECK: curSH4File is [%ld]= %s",curSH4File,SH4Files[curSH4File]);
			
			}

			if( curSH4File < numSH4Files && sh4Act.m_cVertPrim )
			{
				viewCam.reset( );
				if( false ) //sh2_anim )
				{
					while( !sh2Act.loadAnim( testActAnim, SH2AnimFiles[ curSH2AnimFile ].string().c_str() ) && curSH2AnimFile < numSH2AnimFiles )
						curSH2AnimFile++;
					if( curSH2AnimFile == numSH2AnimFiles )
					{
						sh2Act.m_bHasAnim = false;
						curSH2AnimFile = 0;
					}
					else
						g_bHasAnim = true;
				}
			}
		}

		sprintf(curFileInfo,"FILE: %s",SH4Files[curSH4File]);
	}

	if (GetAsyncKeyState(VK_RSHIFT) & 0x8000 || GetAsyncKeyState(VK_RCONTROL) & 0x8000)
	{
		if( curSH4File < numSH4Files )
		{
			for( k = textureMgr.textures.size(); k > 0; k-- )
			{
				if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
					LogFile(TEST_LOG,"Process_SH4_KeyInput() - ERROR: DID NOT Successfully delete tex");
			}

			sh4Act.deleteData( );

			curSH4File = ( curSH4File + 1 ) % numSH4Files;

			while( !sh4Act.loadData( SH4Files[ curSH4File ].string().c_str()) )
			{
				badLoopCounter++;
				curSH4File++;

				if( (curSH4File == numSH4Files )
					|| (!numSH4Files || numSH4Files == 1)
					|| badLoopCounter > 500 )
				{
					if( dirLooped )
						return;
					dirLooped ++;
					curSH4File = 0;
				}
		
				if( badLoopCounter > 500 )
				{
					LogFile( ERROR_LOG,"Process_SH4_KeyInput( ) - ERROR: Bad Loop Counter Reached threshold %d In Directory",badLoopCounter);
					return;
				}

				if( debugMode )
					LogFile(ERROR_LOG,"Process_SH4_KeyInput() - POST CHECK: curSH4File is [%ld]= %s",curSH4File,SH4Files[curSH4File]);
			
			}

			if( curSH4File < numSH4Files && sh4Act.m_cVertPrim )
			{
				viewCam.reset( );
				if( false )//sh2_anim )
				{
					
					char l_cModelName[ 256 ];
					curSH2AnimFile = 0;
					if( baseName( (char*)SH4Files[ curSH4File ].string().c_str(), l_cModelName ) )
					{
						while( !sh2Act.loadAnim( testActAnim, SH2AnimFiles[ curSH2AnimFile ].string().c_str() ) && curSH2AnimFile < numSH2AnimFiles )
							curSH2AnimFile++;
						if( curSH2AnimFile == numSH2AnimFiles )
						{
							sh2Act.m_bHasAnim = false;
							curSH2AnimFile = 0;
						}
						else
							g_bHasAnim = true;
					}
					else
						sh2Act.m_bHasAnim = true;
				}
			}
		}

		sprintf(curFileInfo,"FILE: %s",SH4Files[curSH4File]);
	}

	
	if(GetAsyncKeyState(VK_F2) & 0x8000)
	{
		dumpModel = true;
		/*
		int k,j;
		char offsetStr[20];
		SH2_MapLoader *tScenePtr;

		for( j = 0; j < numScenes; j ++ )
			if( testSceneSH2[j] != NULL )
				break;

		if(testSceneSH2[j])
		{
			sprintf(offsetStr,"%ld",testSceneSH2[j]->baseOffset);

			delete testSceneSH2[j];
			testSceneSH2[j] = NULL;

			for( k = textureMgr.textures.size(); k > 0; k-- )
			{
				if( clearAllTex )
				{
					if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
						LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
				}
				else if(strncmp(textureMgr.textures[k-1].texName.c_str(),offsetStr,strlen(offsetStr))==0)
				{
					if(!textureMgr.DeleteTex(textureMgr.textures[k-1].texName.c_str()))
						LogFile(TEST_LOG,"ERROR: DID NOT Successfully delete tex");
				}
			}
		}

		testSceneSH2[j] = new SH2_MapLoader;

		if(!testSceneSH2[j]->loadArcScene( sceneFiles[curSceneFile], sceneModelNum ))
		{
			LogFile(ERROR_LOG,"MessagePump::Paint - Could not load scene # %d",sceneModelNum);
			delete testSceneSH2[j];
			testSceneSH2[j] = NULL;
		}
		textureMgr.checkResident();
		*/
		dumpModel = false;
	}


}




void ProcessTestInput( )
{
	bool reloadData = false;
	bool origDebug = debugMode;
	bool origAnimDebug = animDebugMode;

	debugMode = false;
	animDebugMode = false;

	if (GetAsyncKeyState(VK_F7) & 0x8000)
	{
		test_anim_transpose_seq0 = !test_anim_transpose_seq0;
		reloadData = true;
	}

	if (GetAsyncKeyState(VK_F8) & 0x8000)
	{
		test_anim_transpose_seq8 = !test_anim_transpose_seq8;
		reloadData = true;
	}

	if (GetAsyncKeyState(VK_F9) & 0x8000)
	{
		test_anim_swapXY_seq0 = !test_anim_swapXY_seq0;
		reloadData = true;
	}

	if (GetAsyncKeyState(VK_F10) & 0x8000)
	{
		test_anim_swapXY_seq8 = !test_anim_swapXY_seq8;
		reloadData = true;
	}

	if (GetAsyncKeyState(VK_F11) & 0x8000)
	{
		test_anim_seq0_use1st = !test_anim_seq0_use1st;
		reloadData = true;
	}

	if (GetAsyncKeyState(VK_F12) & 0x8000)
	{
		test_anim_seq8_use1st = !test_anim_seq8_use1st;
		reloadData = true;
	}

		



	if( reloadData )
	{
		long l_lTestRes;

		if( ! ( l_lTestRes = sh2Act.loadAnim( testActAnim, "H:\\Silent Hill 2\\data\\chr\\red\\red.anm" ) ) )
		{
			MessageBox( NULL, "Did not load SH2 Model's Animation","E R R O R !!!!", MB_OK );
			PostQuitMessage( 0 );
		}
		else
			LogFile( ERROR_LOG, "NOTE: Loaded %ld animations for SH2 Model", l_lTestRes );
	}
	debugMode = origDebug;
	animDebugMode = origAnimDebug;
}




void readFileDataAtLocation( char *filename, int numLongs, long offset )
{
	FILE *theFile = NULL;
	long k;
	BYTE *buffer;
	unsigned long *lDat;
	float *fDat;
	long size;
	unsigned short *sDat;
	
	if((theFile = fopen(filename,"rb"))==NULL)
	{
		LogFile(ERROR_LOG,"ERROR: Unable to open file for reading in 'readIndexData'");
		return;
	}

	fseek(theFile, offset, SEEK_SET );
	
	size = numLongs * 4;
	buffer = new BYTE[size];

	k =fread(buffer,sizeof(BYTE),size,theFile);
	fclose(theFile);

	LogFile(ERROR_LOG,"NOTE: Read %d of %d bytes from %s at offset %d",k,size,filename, offset);

	if(k < size)size = k;

	LogFile(ERROR_LOG,">------===[ D A T A   F R O M   O F F S E T   %d   O F   F I L E ]===------<", offset);
	fDat = (float *)buffer;
	lDat = (unsigned long *)buffer;
	sDat = (unsigned short *)buffer;
	for(k = 0; k < size/sizeof(float);k++)
		LogFile(ERROR_LOG,"%6d - [ %08x ][ %f ] [ %u ] [ %d %d ] [ %d %d %d %d ] [%c%c%c%c]",k + offset/4,lDat[k],fDat[k],lDat[k],(unsigned short)sDat[k*2],(unsigned short)sDat[k*2+1],
				buffer[k*4],buffer[k*4+1],buffer[k*4+2],buffer[k*4+3],(isgraph(buffer[k*4]))?buffer[k*4]:'.',(isgraph(buffer[k*4+1]))?buffer[k*4+1]:'.',
				(isgraph(buffer[k*4+2]))?buffer[k*4+2]:'.',(isgraph(buffer[k*4+3]))?buffer[k*4+3]:'.');
	//LogFile(ERROR_LOG,"%5d - [ %8f ] [ %ld ] [ %d %d ] [ %d %d %d %d ] [%c%c%c%c]",k,fDat[k],lDat[k],sDat[k*2],sDat[k*2+1],
	//		buffer[k*4],buffer[k*4+1],buffer[k*4+2],buffer[k*4+3],
	//		(isgraph(buffer[k*4]))?buffer[k*4]:'.',(isgraph(buffer[k*4+1]))?buffer[k*4+1]:'.',
	//		(isgraph(buffer[k*4+2]))?buffer[k*4+2]:'.',(isgraph(buffer[k*4+3]))?buffer[k*4+3]:'.');

	delete [] buffer;
	LogFile(ERROR_LOG,"");
}



