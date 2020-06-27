#pragma once

#include <SDL2/SDL_mixer.h>
#include <string>
#include <map>

namespace GLEngine {

	class SoundEffect {
		public:
			friend class AudioEngine;

			/// Plays the effect file
			/// @param loops: If loops == -1, loop forever,
			/// otherwise play it loops+1 times
			void play(int loops = 0);
			void setVolume(unsigned int volume) {
				m_chunk->volume = volume;
			}
		private:
			Mix_Chunk* m_chunk = nullptr;
	};

	class Music {
		public:
			friend class AudioEngine;

			/// Plays the music file
			/// @param loops: If loops == -1, loop forever,
			/// otherwise play it loops times
			void play(int loops = 1);
			void fadeIn(int timeMs, int loops = 1);
			bool isPlaying() {
				return Mix_PlayingMusic();
			}

			void setVolume(unsigned int volume) {
				Mix_VolumeMusic(volume);
			}

			/// Pauses whatever song is currently playing
			static void pause();
			/// Stops whatever song is currently playing
			static void stop();
			static void fadeOut(int timeMs);
			/// Resumes whatever song is currently playing
			static void resume();
		private:
			Mix_Music* m_music = nullptr;
	};

	class AudioEngine {
		public:
			AudioEngine();
			~AudioEngine();

			void init();
			void destroy();

			bool hasBeenInited() {
				return m_isInitialized;
			}

			SoundEffect loadSoundEffect(const std::string& filePath); // .wav
			Music loadMusic(const std::string& filePath);             // .mus
		private:

			std::map<std::string, Mix_Chunk*> m_effectMap; ///< Effects cache
			std::map<std::string, Mix_Music*> m_musicMap; ///< Music cache

			bool m_isInitialized = false;
	};

}
