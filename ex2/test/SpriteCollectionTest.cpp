#include "SpriteCollectionTest.h"

TEST_F(SpriteCollectionTest, addSpriteClass){
    Sprite sprite;
    SpriteCollection sp;
    sp.addSprite(sprite);
    collection.addSprite(sprite);
    EXPECT_EQ(sprite, sp.at(0));
}