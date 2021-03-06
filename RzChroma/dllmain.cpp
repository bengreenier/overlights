#include <mutex>

#include "targetver.h"
#include "RzChromaSDKDefines.h"
#include "RzChromaSDKTypes.h"
#include "RzErrors.h"

#include "application.h"

// dllmain is soley responsible for the lifecycle of the application
// plugin logic is managed by the Application
static Application* app = nullptr;
static std::mutex appMutex;

BOOL WINAPI DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	return TRUE;
}

#ifdef __cplusplus
extern "C" {
#endif

	__declspec(dllexport) RZRESULT Init()
	{
		if (app == nullptr)
		{
			std::lock_guard<std::mutex> appGuard(appMutex);

			try
			{
				app = new Application();
			}
			catch (const std::exception&)
			{
				app = nullptr;
				return RZRESULT_FAILED;
			}

			return RZRESULT_SUCCESS;
		}
		else
		{
			return RZRESULT_ALREADY_INITIALIZED;
		}
	}

	__declspec(dllexport) RZRESULT UnInit()
	{
		delete app;
		app = nullptr;

		return RZRESULT_SUCCESS;
	}

	__declspec(dllexport) RZRESULT CreateEffect(RZDEVICEID DeviceId, ChromaSDK::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId)
	{
		if (app != nullptr)
		{
			return app->CreateEffect(DeviceId, Effect, pParam, pEffectId);
		}
		else
		{
			return RZRESULT_INVALID;
		}
	}

	__declspec(dllexport) RZRESULT CreateKeyboardEffect(ChromaSDK::Keyboard::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId)
	{
		if (app != nullptr)
		{
			return app->CreateKeyboardEffect(Effect, pParam, pEffectId);
		}
		else
		{
			return RZRESULT_INVALID;
		}
	}

	__declspec(dllexport) RZRESULT CreateHeadsetEffect(ChromaSDK::Headset::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId)
	{
		if (app != nullptr)
		{
			return app->CreateHeadsetEffect(Effect, pParam, pEffectId);
		}
		else
		{
			return RZRESULT_INVALID;
		}
	}

	__declspec(dllexport) RZRESULT CreateMousepadEffect(ChromaSDK::Mousepad::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId)
	{
		if (app != nullptr)
		{
			return app->CreateMousepadEffect(Effect, pParam, pEffectId);
		}
		else
		{
			return RZRESULT_INVALID;
		}
	}

	__declspec(dllexport) RZRESULT CreateMouseEffect(ChromaSDK::Mouse::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId)
	{
		if (app != nullptr)
		{
			return app->CreateMouseEffect(Effect, pParam, pEffectId);
		}
		else
		{
			return RZRESULT_INVALID;
		}
	}

	__declspec(dllexport) RZRESULT CreateKeypadEffect(ChromaSDK::Keypad::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId)
	{
		if (app != nullptr)
		{
			return app->CreateKeypadEffect(Effect, pParam, pEffectId);
		}
		else
		{
			return RZRESULT_INVALID;
		}
	}

	__declspec(dllexport) RZRESULT SetEffect(RZEFFECTID EffectId)
	{
		if (app != nullptr)
		{
			return app->SetEffect(EffectId);
		}
		else
		{
			return RZRESULT_INVALID;
		}
	}

	__declspec(dllexport) RZRESULT DeleteEffect(RZEFFECTID EffectId)
	{
		if (app != nullptr)
		{
			return app->DeleteEffect(EffectId);
		}
		else
		{
			return RZRESULT_INVALID;
		}
	}

	__declspec(dllexport) RZRESULT QueryDevice(RZDEVICEID DeviceId, ChromaSDK::DEVICE_INFO_TYPE &DeviceInfo)
	{
		if (app != nullptr)
		{
			return app->QueryDevice(DeviceId, DeviceInfo);
		}
		else
		{
			return RZRESULT_INVALID;
		}
	}

	__declspec(dllexport) RZRESULT RegisterEventNotification(HWND hWnd)
	{
		if (app != nullptr)
		{
			// Not Implemented

			return RZRESULT_SUCCESS;
		}
		else
		{
			return RZRESULT_INVALID;
		}
	}

	__declspec(dllexport) RZRESULT UnregisterEventNotification(HWND hWnd)
	{
		if (app != nullptr)
		{
			// Not Implemented

			return RZRESULT_SUCCESS;
		}
		else
		{
			return RZRESULT_INVALID;
		}
	}

#ifdef __cplusplus
}
#endif