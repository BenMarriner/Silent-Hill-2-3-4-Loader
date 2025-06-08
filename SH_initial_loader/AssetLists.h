#ifndef ASSETLISTS
#define ASSETLISTS

#include <filesystem>
#include <vector>

using namespace std;

extern filesystem::path baseSH2dir;
extern filesystem::path baseSH3dir;
extern filesystem::path baseSH4dir;

extern vector<filesystem::path> SH2SceneFiles;
extern int numSH2SceneFiles;
extern int curSH2SceneDir;
extern int curSH2SceneFile;

extern vector<filesystem::path> SH2ModelFiles;
extern int numSH2ModelFiles;
extern int curSH2ModelDir;
extern int curSH2ModelFile;

extern vector<filesystem::path> SH2AnimFiles;
extern int numSH2AnimFiles;
extern int curSH2AnimFile;

extern vector<filesystem::path> SH3SceneFiles;
extern int numSH3SceneFiles;
extern int curSceneFile;

extern vector<filesystem::path> SH3ModelFiles;
extern int numSH3ModelFiles;
extern int curModelFile;

extern vector<filesystem::path> SH4Files;
extern int numSH4Files;
extern int curSH4File;

#endif