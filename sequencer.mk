##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=sequencer
ConfigurationName      :=Debug
WorkspacePath          := "/home/benoit/Dev/arduino"
ProjectPath            := "/home/benoit/Dev/arduino/sequencer"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Benoit
Date                   :=02/14/15
CodeLitePath           :="/home/benoit/.codelite"
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
ObjectsFileList        :="sequencer.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)includes 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)ncurses 
ArLibs                 :=  "ncurses" 
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
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/ConsoleAdapter.cpp$(ObjectSuffix) $(IntermediateDirectory)/arduino.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/benoit/Dev/arduino/sequencer/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/ConsoleAdapter.cpp$(ObjectSuffix): ConsoleAdapter.cpp $(IntermediateDirectory)/ConsoleAdapter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/benoit/Dev/arduino/sequencer/ConsoleAdapter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConsoleAdapter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConsoleAdapter.cpp$(DependSuffix): ConsoleAdapter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConsoleAdapter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConsoleAdapter.cpp$(DependSuffix) -MM "ConsoleAdapter.cpp"

$(IntermediateDirectory)/ConsoleAdapter.cpp$(PreprocessSuffix): ConsoleAdapter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConsoleAdapter.cpp$(PreprocessSuffix) "ConsoleAdapter.cpp"

$(IntermediateDirectory)/arduino.cpp$(ObjectSuffix): arduino.cpp $(IntermediateDirectory)/arduino.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/benoit/Dev/arduino/sequencer/arduino.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/arduino.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/arduino.cpp$(DependSuffix): arduino.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/arduino.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/arduino.cpp$(DependSuffix) -MM "arduino.cpp"

$(IntermediateDirectory)/arduino.cpp$(PreprocessSuffix): arduino.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/arduino.cpp$(PreprocessSuffix) "arduino.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


