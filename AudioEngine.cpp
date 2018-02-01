#include "AudioEngine.h"

#include "GLEngineErrors.h"

namespace GLEngine {
	
	void SoundEffect::play(int loops) {
		if (Mix_PlayChannel(-1, m_chunk, loops) == -1) { // -1 is first channel open, m_chunk is the sound, 0 is how many times it should loop AGAIN (-1 is infinite)
			if (Mix_PlayChannel(0, m_chunk, loops) == -1) {
				if (Mix_PlayChannel(1, m_chunk, loops) == -1) {
					fatalError("Mix_PlayChannel failed: " + std::string(Mix_GetError()) + ".\n");
				}
			}
		}
	}

	void Music::play(int loops) {
		if (Mix_PlayMusic(m_music, loops) == -1) { // -1 is first channel open, m_chunk is the sound, 1 is how many times it should play (-1 is infinite)
			fatalError("Mix_PlayMusic failed: " + std::string(Mix_GetError()) + ".\n");
		}
	}

	void Music::pause() {
		Mix_PauseMusic(); // Pauses ANY MUSIC PLAYING
	}

	void Music::stop() {
		Mix_HaltMusic(); // Stops ANY MUSIC PLAYING
	}

	void Music::resume() {
		Mix_ResumeMusic(); // Resumes ANY MUSIC PAUSED
	}

	AudioEngine::AudioEngine() {
		
	}

	AudioEngine::~AudioEngine() {
		destroy();
	}

	void AudioEngine::destroy() {

		if (m_initialized == true) {
			m_initialized = false;

			for (auto &it : m_effectMap) {
				Mix_FreeChunk(it.second);
			}
			for (auto &it : m_musicMap) {
				Mix_FreeMusic(it.second);
			}

			m_effectMap.clear();
			m_musicMap.clear();

			Mix_CloseAudio();
			Mix_Quit();
		}

	}

	void AudioEngine::init() {

		if (m_initialized) {
			fatalError("Tried to initialize sound engine after initializing sound engine.:|");
		}

		// Parameter can be a bitwise combination of MIX_INIT_FAC, MIX_INIT_MOD, MIX_INIT_MP3, and MIX_INIT_OGG
		if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == -1) {
			fatalError("Mix_Init failed: " + std::string(Mix_GetError()) + ".\n");
		}

		if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
			fatalError("Mix_OpenAudio failed: " + std::string(Mix_GetError()) + ".\n");
		}

		m_initialized = true;

	}

	SoundEffect AudioEngine::loadSoundEffect(const std::string &filepath) {

		auto it = m_effectMap.find(filepath); // Try to find audio in cache

		SoundEffect effect;

		if (it == m_effectMap.end()) {
			Mix_Chunk* chunk = Mix_LoadWAV(filepath.c_str());
			if (chunk == nullptr) {
				fatalError("Mix_LoadWAV failed: " + std::string(Mix_GetError()) + ".\n");
			}
			effect.m_chunk = chunk;
			m_effectMap[filepath] = chunk;
		} else {
			effect.m_chunk = it->second;
		}

		return effect;
	}

	Music AudioEngine::loadMusic(const std::string &filepath) {
		auto it = m_musicMap.find(filepath); // Try to find audio in cache

		Music music;

		if (it == m_musicMap.end()) {
			Mix_Music* mixMusic = Mix_LoadMUS(filepath.c_str());
			if (mixMusic == nullptr) {
				fatalError("Mix_LoadMUS failed: " + std::string(Mix_GetError()) + ".\n");
			}
			music.m_music = mixMusic;
			m_musicMap[filepath] = mixMusic;
		} else {
			music.m_music = it->second;
		}

		return music;
	}

}
