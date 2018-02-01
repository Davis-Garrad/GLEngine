################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GLEngine/AudioEngine.cpp \
../GLEngine/Camera2D.cpp \
../GLEngine/GLEngine.cpp \
../GLEngine/GLEngineErrors.cpp \
../GLEngine/GLEngineRandom.cpp \
../GLEngine/GLSLProgram.cpp \
../GLEngine/IOManager.cpp \
../GLEngine/ImageLoader.cpp \
../GLEngine/InputManager.cpp \
../GLEngine/ParticleBatch2D.cpp \
../GLEngine/ParticleEngine2D.cpp \
../GLEngine/Physics.cpp \
../GLEngine/ResourceManager.cpp \
../GLEngine/Sprite.cpp \
../GLEngine/SpriteBatch.cpp \
../GLEngine/SpriteFont.cpp \
../GLEngine/TextureCache.cpp \
../GLEngine/Time.cpp \
../GLEngine/Timing.cpp \
../GLEngine/Window.cpp \
../GLEngine/picoPNG.cpp 

OBJS += \
./GLEngine/AudioEngine.o \
./GLEngine/Camera2D.o \
./GLEngine/GLEngine.o \
./GLEngine/GLEngineErrors.o \
./GLEngine/GLEngineRandom.o \
./GLEngine/GLSLProgram.o \
./GLEngine/IOManager.o \
./GLEngine/ImageLoader.o \
./GLEngine/InputManager.o \
./GLEngine/ParticleBatch2D.o \
./GLEngine/ParticleEngine2D.o \
./GLEngine/Physics.o \
./GLEngine/ResourceManager.o \
./GLEngine/Sprite.o \
./GLEngine/SpriteBatch.o \
./GLEngine/SpriteFont.o \
./GLEngine/TextureCache.o \
./GLEngine/Time.o \
./GLEngine/Timing.o \
./GLEngine/Window.o \
./GLEngine/picoPNG.o 

CPP_DEPS += \
./GLEngine/AudioEngine.d \
./GLEngine/Camera2D.d \
./GLEngine/GLEngine.d \
./GLEngine/GLEngineErrors.d \
./GLEngine/GLEngineRandom.d \
./GLEngine/GLSLProgram.d \
./GLEngine/IOManager.d \
./GLEngine/ImageLoader.d \
./GLEngine/InputManager.d \
./GLEngine/ParticleBatch2D.d \
./GLEngine/ParticleEngine2D.d \
./GLEngine/Physics.d \
./GLEngine/ResourceManager.d \
./GLEngine/Sprite.d \
./GLEngine/SpriteBatch.d \
./GLEngine/SpriteFont.d \
./GLEngine/TextureCache.d \
./GLEngine/Time.d \
./GLEngine/Timing.d \
./GLEngine/Window.d \
./GLEngine/picoPNG.d 


# Each subdirectory must supply rules for building sources it contributes
GLEngine/%.o: ../GLEngine/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


