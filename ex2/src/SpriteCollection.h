//
// Created by ori on 28/11/16.
//

#ifndef ASS2_SPRITECOLLECTION_H
#define ASS2_SPRITECOLLECTION_H

#include "Sprite.h"
#include <vector>
#include "../test/SpriteCollectionTest.h"

using namespace std;

class SpriteCollection {
    friend class SpriteCollectionTest;
private:
    vector <Sprite> collection;
public:
    SpriteCollection();
    void addSprite(Sprite* sprite);
    void removeSprite(Sprite* sprite);
    void notifyAllTimePassed();
};

#endif //ASS2_SPRITECOLLECTION_H
