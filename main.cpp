
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<bits/stdc++.h>
#include<ctime>
using namespace std;
using namespace sf;
int b = 1;
int cx = 0;
int cy = 0;
const unsigned int gs = 150;
const unsigned int cs = 130;
Text fun1(int r,int c,const Font& fc)
{
    Text t;
    t.setFont(fc);
    t.setString("X");
    t.setFillColor(Color::White);
    t.setCharacterSize(cs);
    t.setPosition(Vector2f(gs*r+(gs-cs)/2+200,gs*c+(gs-cs)/2-10+100));
    return t;
}
Text fun2(int r,int c,const Font& fc)
{
    Text t;
    t.setFont(fc);
    t.setString("O");
    t.setFillColor(Color::White);
    t.setCharacterSize(cs);
    t.setPosition(Vector2f(gs*r+(gs-cs)/2+200,gs*c+(gs-cs)/2-10+100));
    return t;
}
unsigned int fun3(Event& e1)
{
    unsigned int a = 0;
    if(e1.type == Event::MouseButtonPressed)
    {
        if(e1.mouseButton.button==Mouse::Left)
        {
            unsigned int x = e1.mouseButton.x;
            unsigned int y = e1.mouseButton.y;
            if(x>=200 && x<200 + gs)
            {
                a += 10;
            }
            else if(x>=200 + gs && x<200+gs*2)
            {
                a += 20;
            }
            else if(x>=200 + gs*2 && x<200+gs*3)
            {
                a += 30;
            }
            if(y>=100 && y<100+gs)
            {
                a += 1;
            }
            else if(y>=100+gs && y<100+gs*2)
            {
                a += 2;
            }
            else if(y>=100+gs*2 && y<100+gs*3)
            {
                a += 3;
            }
        }
    }
    return a;
}
bool fun4(char* k,bool pc,Text& rt,Sound& asp1,Sound& asp2)
{
    int wc[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(auto& c : wc)
    {
        if(k[c[0]]!=' ' && k[c[0]]==k[c[1]] && k[c[1]]==k[c[2]])
        {
            if(pc)
            {
                rt.setString("Try Again Buddy");
                asp2.play();
            }
            else
            {
                rt.setString("You Win Buddy");
                asp1.play();
            }
            return true;
        }
    }
    return false;
}
bool fun5(char* k,Text& rt,Sound& asp3)
{
    for(int i=0;i<9;i++)
    {
        if(k[i]==' ')
        {
            return false;
        }
    }
    rt.setString("Game was Tie");
    asp3.play();
    return true;
}
int main()
{
    RenderWindow s(VideoMode(883,621),"New Game");
    srand(time(NULL));
    s.setVerticalSyncEnabled(true);
    RectangleShape g(Vector2f(gs,gs));
    g.setFillColor(Color::Transparent);
    g.setOutlineThickness(3.0f);
    g.setOutlineColor(Color::White);
    SoundBuffer as1;
    as1.loadFromFile("audio/one.mp3");
    Sound asp1;
    asp1.setBuffer(as1);
    SoundBuffer as2;
    as2.loadFromFile("audio/two.mp3");
    Sound asp2;
    asp2.setBuffer(as2);
    SoundBuffer as3;
    as3.loadFromFile("audio/three.mp3");
    Sound asp3;
    asp3.setBuffer(as3);
    SoundBuffer as4;
    as4.loadFromFile("audio/four.mp3");
    Sound asp4;
    asp4.setBuffer(as4);
    Font f;
    if(!f.loadFromFile("font/fb.otf"))
    {
        cout<<"Unable to load font now"<<endl;
    }
    Font fc;
    if(!fc.loadFromFile("font/ft.TTF"))
    {
        cout<<"Unable to load font now"<<endl;
    }
    vector<Text>f1;
    vector<Text>f2;
    unsigned int f3 = 0;
    vector<unsigned int>pxy;
    char k[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int r = (rand() % 3 + 1) * 10 + (rand() % 3 + 1);
    Event e;
    Texture s1;
    s1.loadFromFile("images/1.png");
    Texture s2;
    s2.loadFromFile("images/2.png");
    Texture s3;
    s3.loadFromFile("images/3.png");
    Texture s4;
    s4.loadFromFile("images/4.png");
    Texture s5;
    s5.loadFromFile("images/5.png");
    Texture s6;
    s6.loadFromFile("images/6.png");
    Texture s7;
    s7.loadFromFile("images/7.png");
    Texture s8;
    s8.loadFromFile("images/8.png");
    Sprite a1(s1),a2(s2),a3(s3),a4(s4),a5(s5),a6(s6),a7(s7),a8(s8);
    Text rt;
    rt.setFont(f);
    rt.setCharacterSize(70);
    rt.setFillColor(Color::White);
    rt.setPosition(150,250);
    while(s.isOpen())
    {
        while(s.pollEvent(e))
        {
            if(e.type==Event::Closed)
            {
                s.close();
            }
            if(e.type==Event::MouseMoved)
            {
                cx = e.mouseMove.x;
                cy = e.mouseMove.y;
            }
            if(e.type==Event::MouseButtonReleased)
            {
                if(b==1)
                {
                    if(cx<657 && cx>215 && cy>446 && cy<563)
                    {
                        asp4.play();
                        b = 2;
                    }
                }
            }
        }
        s.clear(Color::Black);
        if(b==1)
        {

            if(a1.getPosition().y<150)
            {
                a1.move(4,3);
            }
            if(a5.getPosition().y<250)
            {
                a5.move(3.5,3);
            }
            if(a6.getPosition().y<250)
            {
                a6.move(5,3);
            }
            if(a8.getPosition().y<250)
            {
                a8.move(6.5,3);
            }
            s.draw(a1);
            s.draw(a4);
            a4.setPosition(240,415);
            s.draw(a5);
            s.draw(a6);
            s.draw(a8);
        }
        else if(b==2)
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    g.setPosition(Vector2f(gs*i+200,gs*j+100));
                    s.draw(g);
                }
            }
            for(unsigned int i=0;i<f1.size();i++)
            {
                s.draw(f1.at(i));
            }
            for(unsigned int i=0;i<f2.size();i++)
            {
                s.draw(f2.at(i));
            }
            if(a1.getPosition().y<550)
            {
                a1.move(0,2);
            }
            if(a1.getPosition().x>20)
            {
                a1.move(-3,0);
                a1.scale(Vector2f(0.97,0.97));
            }
            s.draw(a1);
            if(pxy.size()!=9)
            {
                    if(e.type==Event::MouseButtonPressed && e.mouseButton.button==Mouse::Left)
                    {
                        int c1 = (cx-200)/gs;
                        int r1 = (cy-100)/gs;
                        int k1 = r1*3 + c1;
                        if(k1>=0 && k1<9 && k[k1]==' ')
                        {
                            if(f3 % 2 == 0)
                            {
                                f1.push_back(fun1(c1,r1,fc));
                                k[k1] = 'X';
                                f3++;
                            }

                            else
                            {
                                f2.push_back(fun2(c1,r1,fc));
                                k[k1] = 'O';
                                f3++;
                            }
                            pxy.push_back(k1);
                        }
                    }
                    if(fun4(k,f3%2==0,rt,asp1,asp2) || fun5(k,rt,asp3))
                    {
                        b = 3;
                    }
            }
        }
        if(b==3)
        {
            s.draw(rt);
        }
        s.display();
    }
    return 0;
}
