//
// Created by cedriccf on 20/01/17.
//

#ifndef CPP_SEED_PROPERTIES_H
#define CPP_SEED_PROPERTIES_H
#include <string>
#include <vector>

namespace Properties {
    using namespace std;
    namespace Engine {
        static float FPS(60);
    }
    namespace Resources {
        static const string IMAGES_FOLDER_PATH("./resources/pictures/");
        static const string MUSIC_FOLDER_PATH("./resources/music/");
    }
    namespace Level {
        struct Element_Type{
        };
        static const vector<Element_Type> LEVEL_1 = {
        };
    }
    namespace Window {
        static const string TITLE("Civet-Heroes");
        static const int WIDTH(800);
        static const int HEIGHT(600);
    }
    namespace Game {
        static const float SPEED = 3;
        namespace Pose {
            static const int WIDTH = 100;
            static const int HEIGHT = WIDTH;
            static const int X_START = 0;
            static const int Y_START = Window::HEIGHT / 2 - HEIGHT / 2;
            static const std::pair<int, int> POSX_ACTIVE = {Window::WIDTH / 2 - WIDTH / 2  + 1, Window::WIDTH / 2 + WIDTH / 2  - 1};
        }
    }
}
#endif //CPP_SEED_PROPERTIES_H
