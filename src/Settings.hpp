#pragma once

#include <map>
#include <string>
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using json = nlohmann::json;

namespace Simulator
{
    static class Settings
    {
    private:
        inline static map<string,float> _data = {{"position_mult",5}};

    public:
        static void Init()
        {
            GetSettings();
        }

        static void WriteSettings()
        {
            _data["position_mult"] = 5;
            
            json j = _data;
            
            ofstream out("data.json");
            out << j.dump(4);
            out.close();
        }

        static void GetSettings()
        {
            if(filesystem::exists("data.json"))
            {
                fstream out("data.json");
            
                _data = json::parse(out);
            }
            else
            {
                WriteSettings();
            }
        }

        static float ReadSettings(string key)
        {
            return _data[key];
        }
    };
}