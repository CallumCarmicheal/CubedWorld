#include "../stdafx.h"


#ifndef __DEF_CW_ENGINE_HUD_H 
#define __DEF_CW_ENGINE_HUD_H 1

	namespace CubeWorld { namespace Engine { 

		class HUD {

		private: 
			void Init();
			
			HUD() {
				// Call the init code
				Init();
			};
			
		public:
			int AddMenuItem(
				int ecx, 			// 
				int a2, 			// 1
				int a3, 			// 0
				void* ButtonClick,  // Pointer to button event
				int edi,			// ?? 
				int eax_var28, 		// ?? = EAX + var_28
				int a7);			// byte ptr [ebp+var_4]
			
		}
		
	}

#endif