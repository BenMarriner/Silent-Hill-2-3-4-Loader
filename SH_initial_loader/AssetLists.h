#ifndef ASSETLISTS
#define ASSETLISTS

#include <filesystem>
#include <vector>

static filesystem::path baseSH2dir;
static filesystem::path baseSH3dir;
static filesystem::path baseSH4dir;

static vector<std::filesystem::path> SH2SceneFiles;
static int numSH2SceneFiles = 0;
static int curSH2SceneDir = 0;
static int curSH2SceneFile = 0;

static vector<std::filesystem::path> SH2ModelFiles;
static int numSH2ModelFiles = 0;
static int curSH2ModelDir = 0;
static int curSH2ModelFile = 0;

static vector<std::filesystem::path> SH2AnimFiles;
static int numSH2AnimFiles = 0;
static int curSH2AnimFile = 0;

static vector<std::filesystem::path> SH3SceneFiles;
static int numSH3SceneFiles = 0;
static int curSceneFile = 0;

static vector<std::filesystem::path> SH3ModelFiles;
static int numSH3ModelFiles = 0;
static int curModelFile = 0;

static vector<std::filesystem::path> SH4Files;
static int numSH4Files = 0;
static int curSH4File = 0;

#endif