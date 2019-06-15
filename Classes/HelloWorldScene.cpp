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

	//�e�N�X�`���t�@�C�������w�肵�āA�X�v���C�g���쐬
	sprite = Sprite::create("sample08.png");
	sprite2 = Sprite::create("a.png");
	//�V�[���O���t�ɂȂ�
	this->addChild(sprite);
	this->addChild(sprite2);

	//cocos�͉�ʂ̍�����(0,0)�ɂȂ�

	//�\�����W���w��
	sprite->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	sprite2->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	//��]�p���w��i�p�x�j
	//sprite->setRotation(45.0f);
	//�g�k���w��(���{�A�c�{)
	sprite->setScale(3.0f);
	sprite->getTexture()->setAliasTexParameters();
	sprite2->setScale(0.3f);
	//���E���]
	//sprite->setFlippedX(true);
	//�㉺���]
	//sprite->setFlippedY(true);
	//��\���ɂ���
	//sprite->setVisible(false);
	//�F������ݒ� 16�i���ȊO��10�i���ł����͉\
	sprite->setColor(Color3B(255, 255, 255));
	sprite2->setColor(Color3B(0, 0, 255));
	//�s�����x��ݒ� �F�����̐��l�Ɠ��l
	sprite->setOpacity(255);
	sprite2->setOpacity(0);

	//sprite->setAnchorPoint(Vec2(0, 1));

	//update���Ăяo�����悤�ɂ���
	this->scheduleUpdate();

	counter = 0;

	//���ړ�����
	state = 0;

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
	//Vec2 pos;
	//switch (state)
	//{
	////��
	//case 0:
	//	pos = sprite->getPosition();
	//	pos.x += -5.0f;
	//	pos.y += 0.0f;
	//	sprite->setPosition(pos);
	//	//���[�ɒB������
	//	if (pos.x <=200) {
	//		state = 1;//state��1�ɂȂ�
	//	}
	//	break;
	////��
	//case 1:
	//	pos = sprite->getPosition();
	//	pos.x += 0.0f;
	//	pos.y += -5.0f;
	//	sprite->setPosition(pos);
	//	if (pos.y <= 100) {
	//		state = 2;
	//	}
	//	break;
	////�E
	//case 2: 
	//	pos = sprite->getPosition();
	//	pos.x += 5.0f;
	//	pos.y += 0.0f;
	//	sprite->setPosition(pos);
	//	if (pos.x >= 940) {
	//		state = 3;
	//	}
	//	break;
	////��
	//case 3:
	//default:
	//	pos = sprite->getPosition();
	//	pos.x += 0.0f;
	//	pos.y += 5.0f;
	//	sprite->setPosition(pos);
	//	if (pos.y>=600) {
	//		state = 0;
	//	}
	//	break;
	//}
	//�����ɍX�V����������
	//�X�v���C�g�̌��ݍ��W���擾
	//Vec2 pos = sprite->getPosition();
	//���W���ړ�������
	//pos += Vec2(1.0f, 1.0f);
	//pos.x += -1.0f;
	//pos.y += 0.0f;
	//�ړ���̍��W�𔽉f
	//sprite->setPosition(pos);

	/*counter++;
	if (counter > 300)
	{
		counter = 300;
	}
	float opacity = counter / 300.0f * 255.0f;
	opacity = 255.0f - opacity;
	sprite->setOpacity(opacity);*/

	////����𒆐S�ɉ�]
	//float angl = sprite->getRotation();
	//angl += 30;
	//sprite->setRotation(angl);

	//�Ԃ���ɂR�b�����ĕω�
	/*counter++;
	if (counter > 180)
	{
		counter = 180;
	}
	float opacity = counter / 180.0f * 255.0f;
	float opacity2 = counter / 180.0f * 255.0f;
	opacity = 255.0f - opacity;
	opacity2 = 0.0f + opacity2;
	sprite->setColor(Color3B(opacity,0,opacity2));*/

	//�O�L�������������t�F�[�h�A�E�g
	//���L�������t�F�[�h�C��
	/*counter++;
	if (counter > 600)
	{
		counter = 600;
	}
	float opacity = counter / 600.0f * 255.0f;
	float opacity2 = counter / 600.0f*255.0f;
	opacity = 255.0f - opacity;
	opacity2 = 0.0f + opacity2;
	sprite->setOpacity(opacity);
	sprite2->setOpacity(opacity2);*/

	//���E�������Ȃ��獶�ɐi��ł�Ƃ����A�E�Ȃ�E�ɂ���;

	//Vec2 pos;
	//switch (state)
	//{
	////��
	//case 0:
	//	pos = sprite->getPosition();
	//	pos.x += -5.0f;
	//	pos.y += 0.0f;
	//	sprite->setPosition(pos);
	//	sprite->setFlippedX(true);
	//	//���[�ɒB������
	//	if (pos.x <=200) {
	//		state = 1;//state��1�ɂȂ�
	//	}
	//	break;
	////�E
	//case 1: 
 //   default:
	//	pos = sprite->getPosition();
	//	pos.x += 5.0f;
	//	pos.y += 0.0f;
	//	sprite->setPosition(pos);
	//	sprite->setFlippedX(false);
	//	if (pos.x >= 1080) {
	//		state = 0;
	//	}
	//	break;
	//}
	////�����ɍX�V����������
	////�X�v���C�g�̌��ݍ��W���擾
	//pos = sprite->getPosition();
	////���W���ړ�������
	//pos += Vec2(1.0f, 0.0f);
	//pos.x += -1.0f;
	////�ړ���̍��W�𔽉f
	//sprite->setPosition(pos);

    //setTextureRect �Ńp�^�[���A�j���[�V����
	Vec2 pos;
	int x;

	switch (state)
	{
	//��
	case 0:
		pos = sprite->getPosition();
		x = sprite->getTextureRect(Rect(x));
		pos.x += -5.0f;
		pos.y += 0.0f;
		sprite->setPosition(pos);
		sprite->setTextureRect(Rect(0, 32, 32, 32));
		//���[�ɒB������
		if(pos.x <=200) {
			state = 1;//state��1�ɂȂ�
		}
		break;
	//�E
	case 1: 
    default:
		pos = sprite->getPosition();
		pos.x += 5.0f;
		pos.y += 0.0f;
		sprite->setPosition(pos);
		sprite->setTextureRect(cocos2d::Rect(0, 64, 32, 32));
		if(pos.x >= 1080) {
			state = 0;
		}
		break;
	}
}
