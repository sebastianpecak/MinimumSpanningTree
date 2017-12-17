##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=MSP_SebastianPecak
ConfigurationName      :=Debug
WorkspacePath          :=/home/sebastian/Dokumenty/MSP_MyAlg
ProjectPath            :=/home/sebastian/Dokumenty/MSP_MyAlg
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Sebastian Pecak
Date                   :=17/12/17
CodeLitePath           :=/home/sebastian/.codelite
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="MSP_SebastianPecak.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/Array.c$(ObjectSuffix) $(IntermediateDirectory)/MSP.c$(ObjectSuffix) $(IntermediateDirectory)/Tools.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/sebastian/Dokumenty/MSP_MyAlg/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/Array.c$(ObjectSuffix): Array.c $(IntermediateDirectory)/Array.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/sebastian/Dokumenty/MSP_MyAlg/Array.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Array.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Array.c$(DependSuffix): Array.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Array.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Array.c$(DependSuffix) -MM Array.c

$(IntermediateDirectory)/Array.c$(PreprocessSuffix): Array.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Array.c$(PreprocessSuffix) Array.c

$(IntermediateDirectory)/MSP.c$(ObjectSuffix): MSP.c $(IntermediateDirectory)/MSP.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/sebastian/Dokumenty/MSP_MyAlg/MSP.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MSP.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MSP.c$(DependSuffix): MSP.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MSP.c$(ObjectSuffix) -MF$(IntermediateDirectory)/MSP.c$(DependSuffix) -MM MSP.c

$(IntermediateDirectory)/MSP.c$(PreprocessSuffix): MSP.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MSP.c$(PreprocessSuffix) MSP.c

$(IntermediateDirectory)/Tools.c$(ObjectSuffix): Tools.c $(IntermediateDirectory)/Tools.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/sebastian/Dokumenty/MSP_MyAlg/Tools.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tools.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tools.c$(DependSuffix): Tools.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tools.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Tools.c$(DependSuffix) -MM Tools.c

$(IntermediateDirectory)/Tools.c$(PreprocessSuffix): Tools.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tools.c$(PreprocessSuffix) Tools.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


