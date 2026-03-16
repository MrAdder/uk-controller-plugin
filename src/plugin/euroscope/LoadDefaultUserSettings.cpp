#include "euroscope/LoadDefaultUserSettings.h"
#include "euroscope/UserSetting.h"
#include "euroscope/GeneralSettingsEntries.h"

using UKControllerPlugin::Euroscope::GeneralSettingsEntries;
using UKControllerPlugin::Euroscope::UserSetting;

namespace UKControllerPlugin {
    namespace Euroscope {
        void LoadDefaultUserSettings(UserSetting& userSetting)
        {
            // Prenotes
            if (!userSetting.HasEntry(GeneralSettingsEntries::usePrenoteSettingsKey)) {
                LogInfo("Loading default value for setting " + GeneralSettingsEntries::usePrenoteSettingsKey);
                userSetting.Save(
                    GeneralSettingsEntries::usePrenoteSettingsKey,
                    GeneralSettingsEntries::usePrenoteSettingsDescription,
                    false);
            }

            // Automatic squawk assignment
            if (!userSetting.HasEntry(GeneralSettingsEntries::squawkToggleSettingsKey)) {
                LogInfo("Loading default value for setting " + GeneralSettingsEntries::squawkToggleSettingsKey);
                userSetting.Save(
                    GeneralSettingsEntries::squawkToggleSettingsKey,
                    GeneralSettingsEntries::squawkToggleSettingsDescription,
                    true);
            }

            // Automatic initial altitude assignment
            if (!userSetting.HasEntry(GeneralSettingsEntries::initialAltitudeToggleSettingsKey)) {
                LogInfo(
                    "Loading default value for setting " + GeneralSettingsEntries::initialAltitudeToggleSettingsKey);
                userSetting.Save(
                    GeneralSettingsEntries::initialAltitudeToggleSettingsKey,
                    GeneralSettingsEntries::initialAltitudeToggleSettingsDescription,
                    true);
            }

            // Pressure change notifications
            if (!userSetting.HasEntry(GeneralSettingsEntries::pressureMonitorSendMessageKey)) {
                LogInfo("Loading default value for setting " + GeneralSettingsEntries::pressureMonitorSendMessageKey);
                userSetting.Save(
                    GeneralSettingsEntries::pressureMonitorSendMessageKey,
                    GeneralSettingsEntries::pressureMonitorSendMessageDescription,
                    true);
            }

            // Time format
            if (!userSetting.HasEntry(GeneralSettingsEntries::unknownTimeFormatBlankKey)) {
                LogInfo("Loading default value for setting " + GeneralSettingsEntries::unknownTimeFormatBlankKey);
                userSetting.Save(
                    GeneralSettingsEntries::unknownTimeFormatBlankKey,
                    GeneralSettingsEntries::unknownTimeFormatBlankDescription,
                    false);
            }

            // Stand assignment colours
            if (!userSetting.HasEntry(GeneralSettingsEntries::standPilotRequestedColourKey)) {
                LogInfo("Loading default value for setting " + GeneralSettingsEntries::standPilotRequestedColourKey);
                userSetting.Save(
                    GeneralSettingsEntries::standPilotRequestedColourKey,
                    GeneralSettingsEntries::standPilotRequestedColourDescription,
                    RGB(255, 153, 255));
            }

            if (!userSetting.HasEntry(GeneralSettingsEntries::standPilotRequestedUnavailableColourKey)) {
                LogInfo(
                    "Loading default value for setting " +
                    GeneralSettingsEntries::standPilotRequestedUnavailableColourKey);
                userSetting.Save(
                    GeneralSettingsEntries::standPilotRequestedUnavailableColourKey,
                    GeneralSettingsEntries::standPilotRequestedUnavailableColourDescription,
                    RGB(255, 87, 51));
            }

            if (!userSetting.HasEntry(GeneralSettingsEntries::standVaaAssignmentColourKey)) {
                LogInfo("Loading default value for setting " + GeneralSettingsEntries::standVaaAssignmentColourKey);
                userSetting.Save(
                    GeneralSettingsEntries::standVaaAssignmentColourKey,
                    GeneralSettingsEntries::standVaaAssignmentColourDescription,
                    RGB(102, 255, 255));
            }

            if (!userSetting.HasEntry(GeneralSettingsEntries::standSystemAutoColourKey)) {
                LogInfo("Loading default value for setting " + GeneralSettingsEntries::standSystemAutoColourKey);
                userSetting.Save(
                    GeneralSettingsEntries::standSystemAutoColourKey,
                    GeneralSettingsEntries::standSystemAutoColourDescription,
                    RGB(255, 215, 0));
            }
        }
    } // namespace Euroscope
} // namespace UKControllerPlugin
