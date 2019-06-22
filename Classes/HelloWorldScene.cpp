/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }
	
	//乱数の初期化
	//Random r = new Random();
	srand(time(nullptr));

	for (int i = 0; i < 1; i++)
	{
		int state = 0;
		float mx, my;
		//-250～250までの乱数
		mx = (float)rand() / RAND_MAX * 500 - 250;
		my = (float)rand() / RAND_MAX * 500 - 250;

		sprite[i] = Sprite::create("a.png");
		this->addChild(sprite[i]);
		sprite[i]->setPosition(Vec2(1100, 600));
		sprite[i]->setColor(Color3B(255, 0, 0));
		sprite[i]->setScale(0.3f);

		MoveBy* action1 = MoveBy::create(5.0f, Vec2(-900, 0));
		FadeOut* action2 = FadeOut::create(6.0f);
        sprite[i]->runAction(action1);
		sprite[i]->runAction(action2);

	}

	//テクスチャファイル名を指定して、スプライトを作成
	//sprite = Sprite::create("a.png");
	//sprite2 = Sprite::create("a.png");
	////シーングラフにつなぐ
	//this->addChild(sprite);
	//this->addChild(sprite2);

	////cocosは画面の左下が(0,0)になる

	////表示座標を指定
	//sprite->setPosition(Vec2(300, visibleSize.height / 2.0f));
	//sprite2->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	////回転角を指定（角度）
	////sprite->setRotation(45.0f);
	////拡縮を指定(横倍、縦倍)
	////sprite->setScale(3.0f);
	////sprite->getTexture()->setAliasTexParameters();
	//sprite->setScale(0.3f);
	//sprite2->setScale(0.3f);
	////左右反転
	////sprite->setFlippedX(true);
	////上下反転
	////sprite->setFlippedY(true);
	////非表示にする
	////sprite->setVisible(false);
	////色あいを設定 16進数以外に10進数でも入力可能
	//sprite->setColor(Color3B(0, 0, 255));
	//sprite2->setColor(Color3B(255, 0, 0));
	////不透明度を設定 色合いの数値と同様
	////sprite->setOpacity(255);
	////sprite2->setOpacity(0);

	////sprite->setAnchorPoint(Vec2(0, 1));

	////updateが呼び出されるようにする
	this->scheduleUpdate();

	////アクションの作成（１秒かけて　右に２００　上に１００動く）
	//MoveBy* action1 = MoveBy::create(1.0f, Vec2(300, 100));
	//MoveBy* action2 = MoveBy::create(1.0f, Vec2(300, 100));
	////MoveTo* action1 = MoveTo::create(1.0f, Vec2(200, 100));
	////ScaleTo* action1 = ScaleTo::create(1.0f, 5.0f);
	////JumpTo* action1 = JumpTo::create(1.0f, Vec2(200, 100), 300.0f, 1);
	///*ccBezierConfig conf;
	//conf.controlPoint_1 = Vec2(200, 200);
	//conf.controlPoint_2 = Vec2(500, 500);
	//conf.endPosition = Vec2(800, 200);*/
	////BezierTo* action1 = BezierTo::create(2.0f, conf);
	////EaseInOut* action2 = EaseInOut::create(action1, 2.0f);
	//sprite->runAction(action1->clone());
	//sprite2->runAction(action1);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta) 
{
	
}
