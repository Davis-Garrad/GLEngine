##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=GLEngine
ConfigurationName      :=Release
WorkspacePath          :=/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine
ProjectPath            :=/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine
IntermediateDirectory  :=./obj/Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=UndistinguishedProgrammer
Date                   :=22/06/20
CodeLitePath           :=/home/davis-dev/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=bin/Release/libGLEngine.a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="GLEngine.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -s -static -lboost_filesystem -lboost_thread -lboost_system -Wl,-Bdynamic -lSDL2 -lSDL2_ttf -lSDL2_mixer -lGL -lGLEW 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O2 -Wall -std=c++14 -std=c++14  $(Preprocessors)
CFLAGS   :=  -O2 -Wall -std=c++14 -std=c++14  $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/AudioEngine.cpp$(ObjectSuffix) $(IntermediateDirectory)/Camera2D.cpp$(ObjectSuffix) $(IntermediateDirectory)/DebugRenderer.cpp$(ObjectSuffix) $(IntermediateDirectory)/GLEngineRandom.cpp$(ObjectSuffix) $(IntermediateDirectory)/GLEngine.cpp$(ObjectSuffix) $(IntermediateDirectory)/SpriteFont.cpp$(ObjectSuffix) $(IntermediateDirectory)/ParticleBatch2D.cpp$(ObjectSuffix) $(IntermediateDirectory)/ResourceManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/GUI.cpp$(ObjectSuffix) $(IntermediateDirectory)/IMainGame.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/GLEngineErrors.cpp$(ObjectSuffix) $(IntermediateDirectory)/Timing.cpp$(ObjectSuffix) $(IntermediateDirectory)/ScreenList.cpp$(ObjectSuffix) $(IntermediateDirectory)/picoPNG.cpp$(ObjectSuffix) $(IntermediateDirectory)/TextureCache.cpp$(ObjectSuffix) $(IntermediateDirectory)/Window.cpp$(ObjectSuffix) $(IntermediateDirectory)/ImageLoader.cpp$(ObjectSuffix) $(IntermediateDirectory)/IOManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/SpriteBatch.cpp$(ObjectSuffix) $(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Physics.cpp$(ObjectSuffix) $(IntermediateDirectory)/ParticleEngine2D.cpp$(ObjectSuffix) $(IntermediateDirectory)/InputManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/GLSLProgram.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/.build-release"
	@echo rebuilt > "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/.build-release/GLEngine"

MakeIntermediateDirs:
	@test -d ./obj/Release || $(MakeDirCommand) ./obj/Release


./obj/Release:
	@test -d ./obj/Release || $(MakeDirCommand) ./obj/Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/AudioEngine.cpp$(ObjectSuffix): AudioEngine.cpp $(IntermediateDirectory)/AudioEngine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/AudioEngine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AudioEngine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AudioEngine.cpp$(DependSuffix): AudioEngine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AudioEngine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AudioEngine.cpp$(DependSuffix) -MM AudioEngine.cpp

$(IntermediateDirectory)/AudioEngine.cpp$(PreprocessSuffix): AudioEngine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AudioEngine.cpp$(PreprocessSuffix) AudioEngine.cpp

$(IntermediateDirectory)/Camera2D.cpp$(ObjectSuffix): Camera2D.cpp $(IntermediateDirectory)/Camera2D.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/Camera2D.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Camera2D.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Camera2D.cpp$(DependSuffix): Camera2D.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Camera2D.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Camera2D.cpp$(DependSuffix) -MM Camera2D.cpp

$(IntermediateDirectory)/Camera2D.cpp$(PreprocessSuffix): Camera2D.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Camera2D.cpp$(PreprocessSuffix) Camera2D.cpp

$(IntermediateDirectory)/DebugRenderer.cpp$(ObjectSuffix): DebugRenderer.cpp $(IntermediateDirectory)/DebugRenderer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/DebugRenderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DebugRenderer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DebugRenderer.cpp$(DependSuffix): DebugRenderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DebugRenderer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DebugRenderer.cpp$(DependSuffix) -MM DebugRenderer.cpp

$(IntermediateDirectory)/DebugRenderer.cpp$(PreprocessSuffix): DebugRenderer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DebugRenderer.cpp$(PreprocessSuffix) DebugRenderer.cpp

$(IntermediateDirectory)/GLEngineRandom.cpp$(ObjectSuffix): GLEngineRandom.cpp $(IntermediateDirectory)/GLEngineRandom.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/GLEngineRandom.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GLEngineRandom.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GLEngineRandom.cpp$(DependSuffix): GLEngineRandom.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GLEngineRandom.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GLEngineRandom.cpp$(DependSuffix) -MM GLEngineRandom.cpp

$(IntermediateDirectory)/GLEngineRandom.cpp$(PreprocessSuffix): GLEngineRandom.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GLEngineRandom.cpp$(PreprocessSuffix) GLEngineRandom.cpp

$(IntermediateDirectory)/GLEngine.cpp$(ObjectSuffix): GLEngine.cpp $(IntermediateDirectory)/GLEngine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/GLEngine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GLEngine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GLEngine.cpp$(DependSuffix): GLEngine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GLEngine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GLEngine.cpp$(DependSuffix) -MM GLEngine.cpp

$(IntermediateDirectory)/GLEngine.cpp$(PreprocessSuffix): GLEngine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GLEngine.cpp$(PreprocessSuffix) GLEngine.cpp

$(IntermediateDirectory)/SpriteFont.cpp$(ObjectSuffix): SpriteFont.cpp $(IntermediateDirectory)/SpriteFont.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/SpriteFont.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SpriteFont.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SpriteFont.cpp$(DependSuffix): SpriteFont.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SpriteFont.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SpriteFont.cpp$(DependSuffix) -MM SpriteFont.cpp

$(IntermediateDirectory)/SpriteFont.cpp$(PreprocessSuffix): SpriteFont.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SpriteFont.cpp$(PreprocessSuffix) SpriteFont.cpp

$(IntermediateDirectory)/ParticleBatch2D.cpp$(ObjectSuffix): ParticleBatch2D.cpp $(IntermediateDirectory)/ParticleBatch2D.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/ParticleBatch2D.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ParticleBatch2D.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ParticleBatch2D.cpp$(DependSuffix): ParticleBatch2D.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ParticleBatch2D.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ParticleBatch2D.cpp$(DependSuffix) -MM ParticleBatch2D.cpp

$(IntermediateDirectory)/ParticleBatch2D.cpp$(PreprocessSuffix): ParticleBatch2D.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ParticleBatch2D.cpp$(PreprocessSuffix) ParticleBatch2D.cpp

$(IntermediateDirectory)/ResourceManager.cpp$(ObjectSuffix): ResourceManager.cpp $(IntermediateDirectory)/ResourceManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/ResourceManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ResourceManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ResourceManager.cpp$(DependSuffix): ResourceManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ResourceManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ResourceManager.cpp$(DependSuffix) -MM ResourceManager.cpp

$(IntermediateDirectory)/ResourceManager.cpp$(PreprocessSuffix): ResourceManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ResourceManager.cpp$(PreprocessSuffix) ResourceManager.cpp

$(IntermediateDirectory)/GUI.cpp$(ObjectSuffix): GUI.cpp $(IntermediateDirectory)/GUI.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/GUI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GUI.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GUI.cpp$(DependSuffix): GUI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GUI.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GUI.cpp$(DependSuffix) -MM GUI.cpp

$(IntermediateDirectory)/GUI.cpp$(PreprocessSuffix): GUI.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GUI.cpp$(PreprocessSuffix) GUI.cpp

$(IntermediateDirectory)/IMainGame.cpp$(ObjectSuffix): IMainGame.cpp $(IntermediateDirectory)/IMainGame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/IMainGame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IMainGame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IMainGame.cpp$(DependSuffix): IMainGame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IMainGame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IMainGame.cpp$(DependSuffix) -MM IMainGame.cpp

$(IntermediateDirectory)/IMainGame.cpp$(PreprocessSuffix): IMainGame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IMainGame.cpp$(PreprocessSuffix) IMainGame.cpp

$(IntermediateDirectory)/GLEngineErrors.cpp$(ObjectSuffix): GLEngineErrors.cpp $(IntermediateDirectory)/GLEngineErrors.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/GLEngineErrors.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GLEngineErrors.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GLEngineErrors.cpp$(DependSuffix): GLEngineErrors.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GLEngineErrors.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GLEngineErrors.cpp$(DependSuffix) -MM GLEngineErrors.cpp

$(IntermediateDirectory)/GLEngineErrors.cpp$(PreprocessSuffix): GLEngineErrors.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GLEngineErrors.cpp$(PreprocessSuffix) GLEngineErrors.cpp

$(IntermediateDirectory)/Timing.cpp$(ObjectSuffix): Timing.cpp $(IntermediateDirectory)/Timing.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/Timing.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Timing.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Timing.cpp$(DependSuffix): Timing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Timing.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Timing.cpp$(DependSuffix) -MM Timing.cpp

$(IntermediateDirectory)/Timing.cpp$(PreprocessSuffix): Timing.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Timing.cpp$(PreprocessSuffix) Timing.cpp

$(IntermediateDirectory)/ScreenList.cpp$(ObjectSuffix): ScreenList.cpp $(IntermediateDirectory)/ScreenList.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/ScreenList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ScreenList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ScreenList.cpp$(DependSuffix): ScreenList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ScreenList.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ScreenList.cpp$(DependSuffix) -MM ScreenList.cpp

$(IntermediateDirectory)/ScreenList.cpp$(PreprocessSuffix): ScreenList.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ScreenList.cpp$(PreprocessSuffix) ScreenList.cpp

$(IntermediateDirectory)/picoPNG.cpp$(ObjectSuffix): picoPNG.cpp $(IntermediateDirectory)/picoPNG.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/picoPNG.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/picoPNG.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/picoPNG.cpp$(DependSuffix): picoPNG.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/picoPNG.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/picoPNG.cpp$(DependSuffix) -MM picoPNG.cpp

$(IntermediateDirectory)/picoPNG.cpp$(PreprocessSuffix): picoPNG.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/picoPNG.cpp$(PreprocessSuffix) picoPNG.cpp

$(IntermediateDirectory)/TextureCache.cpp$(ObjectSuffix): TextureCache.cpp $(IntermediateDirectory)/TextureCache.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/TextureCache.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TextureCache.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TextureCache.cpp$(DependSuffix): TextureCache.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TextureCache.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TextureCache.cpp$(DependSuffix) -MM TextureCache.cpp

$(IntermediateDirectory)/TextureCache.cpp$(PreprocessSuffix): TextureCache.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TextureCache.cpp$(PreprocessSuffix) TextureCache.cpp

$(IntermediateDirectory)/Window.cpp$(ObjectSuffix): Window.cpp $(IntermediateDirectory)/Window.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/Window.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Window.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Window.cpp$(DependSuffix): Window.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Window.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Window.cpp$(DependSuffix) -MM Window.cpp

$(IntermediateDirectory)/Window.cpp$(PreprocessSuffix): Window.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Window.cpp$(PreprocessSuffix) Window.cpp

$(IntermediateDirectory)/ImageLoader.cpp$(ObjectSuffix): ImageLoader.cpp $(IntermediateDirectory)/ImageLoader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/ImageLoader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImageLoader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImageLoader.cpp$(DependSuffix): ImageLoader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ImageLoader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ImageLoader.cpp$(DependSuffix) -MM ImageLoader.cpp

$(IntermediateDirectory)/ImageLoader.cpp$(PreprocessSuffix): ImageLoader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImageLoader.cpp$(PreprocessSuffix) ImageLoader.cpp

$(IntermediateDirectory)/IOManager.cpp$(ObjectSuffix): IOManager.cpp $(IntermediateDirectory)/IOManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/IOManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IOManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IOManager.cpp$(DependSuffix): IOManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IOManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IOManager.cpp$(DependSuffix) -MM IOManager.cpp

$(IntermediateDirectory)/IOManager.cpp$(PreprocessSuffix): IOManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IOManager.cpp$(PreprocessSuffix) IOManager.cpp

$(IntermediateDirectory)/SpriteBatch.cpp$(ObjectSuffix): SpriteBatch.cpp $(IntermediateDirectory)/SpriteBatch.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/SpriteBatch.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SpriteBatch.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SpriteBatch.cpp$(DependSuffix): SpriteBatch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SpriteBatch.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SpriteBatch.cpp$(DependSuffix) -MM SpriteBatch.cpp

$(IntermediateDirectory)/SpriteBatch.cpp$(PreprocessSuffix): SpriteBatch.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SpriteBatch.cpp$(PreprocessSuffix) SpriteBatch.cpp

$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix): Sprite.cpp $(IntermediateDirectory)/Sprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/Sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sprite.cpp$(DependSuffix): Sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Sprite.cpp$(DependSuffix) -MM Sprite.cpp

$(IntermediateDirectory)/Sprite.cpp$(PreprocessSuffix): Sprite.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sprite.cpp$(PreprocessSuffix) Sprite.cpp

$(IntermediateDirectory)/Physics.cpp$(ObjectSuffix): Physics.cpp $(IntermediateDirectory)/Physics.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/Physics.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Physics.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Physics.cpp$(DependSuffix): Physics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Physics.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Physics.cpp$(DependSuffix) -MM Physics.cpp

$(IntermediateDirectory)/Physics.cpp$(PreprocessSuffix): Physics.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Physics.cpp$(PreprocessSuffix) Physics.cpp

$(IntermediateDirectory)/ParticleEngine2D.cpp$(ObjectSuffix): ParticleEngine2D.cpp $(IntermediateDirectory)/ParticleEngine2D.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/ParticleEngine2D.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ParticleEngine2D.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ParticleEngine2D.cpp$(DependSuffix): ParticleEngine2D.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ParticleEngine2D.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ParticleEngine2D.cpp$(DependSuffix) -MM ParticleEngine2D.cpp

$(IntermediateDirectory)/ParticleEngine2D.cpp$(PreprocessSuffix): ParticleEngine2D.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ParticleEngine2D.cpp$(PreprocessSuffix) ParticleEngine2D.cpp

$(IntermediateDirectory)/InputManager.cpp$(ObjectSuffix): InputManager.cpp $(IntermediateDirectory)/InputManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/InputManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/InputManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/InputManager.cpp$(DependSuffix): InputManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/InputManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/InputManager.cpp$(DependSuffix) -MM InputManager.cpp

$(IntermediateDirectory)/InputManager.cpp$(PreprocessSuffix): InputManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/InputManager.cpp$(PreprocessSuffix) InputManager.cpp

$(IntermediateDirectory)/GLSLProgram.cpp$(ObjectSuffix): GLSLProgram.cpp $(IntermediateDirectory)/GLSLProgram.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/davis-dev/Documents/Programming/C++/CodingGithub/GLEngine/GLSLProgram.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GLSLProgram.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GLSLProgram.cpp$(DependSuffix): GLSLProgram.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GLSLProgram.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GLSLProgram.cpp$(DependSuffix) -MM GLSLProgram.cpp

$(IntermediateDirectory)/GLSLProgram.cpp$(PreprocessSuffix): GLSLProgram.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GLSLProgram.cpp$(PreprocessSuffix) GLSLProgram.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Release/


