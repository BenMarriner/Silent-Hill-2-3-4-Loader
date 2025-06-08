#include "AssetLists.h"


filesystem::path baseSH2dir;
filesystem::path baseSH3dir;
filesystem::path baseSH4dir;

vector<filesystem::path> SH2SceneFiles;
int numSH2SceneFiles = 0;
int curSH2SceneDir = 0;
int curSH2SceneFile = 0;

vector<filesystem::path> SH2ModelFiles;
int numSH2ModelFiles = 0;
int curSH2ModelDir = 0;
int curSH2ModelFile = 0;

vector<filesystem::path> SH2AnimFiles;
int numSH2AnimFiles = 0;
int curSH2AnimFile = 0;

vector<filesystem::path> SH3SceneFiles;
int numSH3SceneFiles = 0;
int curSceneFile = 0;

vector<filesystem::path> SH3ModelFiles;
int numSH3ModelFiles = 0;
int curModelFile = 0;

vector<filesystem::path> SH4Files;
int numSH4Files = 0;
int curSH4File = 0;