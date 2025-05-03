#pragma once

#include <map>
#include <string>
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include "raylib.h"

using namespace std;
using json = nlohmann::json;

namespace Simulator
{
    static class Settings
    {
    private:
        inline static map<string, float> _data = { {"position_mult", 5}, {"font_size", 32} };

    public:
        static void Init()
        {
            GetSettings();
        }

        static void WriteSettings(map<string, float> newData)
        {
            _data = newData;

            json j = _data;

            ofstream out("data.json");
            out << j.dump(4);
            out.close();
        }

        static void GetSettings()
        {
            if (filesystem::exists("data.json"))
            {
                fstream out("data.json");

                _data = json::parse(out);
            }
            else
            {
                FirstWrite();
            }
        }

        static void FirstWrite()
        {
            _data["position_mult"] = 5;
            _data["font_size"] = 32;

            json j = _data;

            ofstream out("data.json");
            out << j.dump(4);
            out.close();
        }

        static auto ReadSettings(string key)
        {
            return _data[key];
        }
    };
}