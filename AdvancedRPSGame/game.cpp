//
//  game.cpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/9/21.
//

#include "game.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Game::Game(){currentPlayer=Player("tester",1000000,1000000);}

void Game::begin()
{
    cout<<"Advanced Rock Paper Scissors\nby Nathan Dilla\n"
    <<"\n ENTER A NUMBER TO NAVIGATE:\n\n"
    <<"1. NEW GAME\n"
    <<"2. CONTINUE FROM SAVE\n"
    <<"3. QUIT\n";
    int input=validateInput(1, 3);
    switch(input)
    {
        case 1:
            newGame();
            break;
        case 2:
            loadGame();
            break;
        case 3:
            break;
    }
}

void Game::newGame()
{
    cout<<"ENTER THE NEW PLAYER'S NAME:"<<endl;
    string input;
    cin>>input;
    ofstream newFile(input+".txt");
    ofstream list;
    list.open("player_list.txt",fstream::app);
    list<<input<<endl;
    list.close();
    newFile.close();
    currentPlayer=Player (input,50,0);
    saveGame();
    hub();
}

void Game::loadGame()
{
    cout<<"ENTER THE SAVE NUMBER:"<<endl;
    string myText;
    ifstream MyReadFile("player_list.txt");
    int i=1;
    vector<string> saves;
    while (getline (MyReadFile, myText)) {
      cout << i<<". "<<myText<<endl;
        saves.push_back(myText);
        i++;
    }

    MyReadFile.close();
    int input=validateInput(1,saves.size());
    
    cout<<"LOADING: "<<saves.at(input-1);
    currentPlayer=Player(saves.at(input-1),0,0);
    currentPlayer.setName(saves.at(input-1));
    ifstream loadFile(saves.at(input-1)+".txt");
    int load_index=0;
    int items=0;
    int item_data_index=0;
    vector<item>loadInventory;
    while (getline (loadFile, myText)) {
        load_index++;
        if(load_index==1){currentPlayer.setMoney(stoi(myText));cout<<"loaded money\n";}
        if(load_index==2){currentPlayer.setExp(stoi(myText));cout<<"loaded exp\n";}
        if(load_index==3){currentPlayer.setZone1Progress(stoi(myText));}
        if(load_index==4){currentPlayer.setZone2Progress(stoi(myText));}
        if(load_index==5){currentPlayer.setZone3Progress(stoi(myText));}
        if(load_index==6){currentPlayer.setZone4Progress(stoi(myText));}
        loadInventory.push_back(item());
        if(load_index>6)
        {
            if(item_data_index==0)
            {
                loadInventory.push_back(item());
                loadInventory.at(items).setName(myText);
                break;
            }
            else if (item_data_index==1)
            {
                loadInventory.at(items).setQuantity(stoi(myText));break;
            }
            else if (item_data_index==2)
            {
                loadInventory.at(items).setCategory(myText);break;
            }
            else if (item_data_index==3)
            {
                loadInventory.at(items).setDesc(myText);break;
            }
            else if (item_data_index==4)
            {
                item_data_index=0;
                bool onbody=false;
                if(myText=="1"){onbody=true;}
                loadInventory.at(items).setOnBody(onbody);
                currentPlayer.addToBackpack(&loadInventory.at(items));
                items++;
                break;
            }
            item_data_index++;
        }
    }
//    Player obj;
//    loadFile.read((char*)&obj, sizeof(obj));
//    currentPlayer=obj;
    hub();
}

Player Game::getPlayer()
{
    return currentPlayer;
}

int Game::validateInput(int low, int high)
{
    int input = 0;
    while(true)
    {
        cin>>input;
        if(low<=input&&input<=high)
        {
            return input;
        }
    }
}

void Game::hub()
{
    cout<<"\n\nWelcome to Advanced Rock Paper Scissors,"<<currentPlayer.getName()<<" \n"
    <<"\n THIS IS YOUR WORLD HUB. PLEASE ENTER A NUMBER TO BEGIN YOUR JOURNEY!\n\n"
    <<"1. EMBARK\n"
    <<"2. STORE\n"
    <<"3. INVENTORY\n"
    <<"4. SAVE AND QUIT\n";
    int input=validateInput(1, 4);
    switch(input)
    {
        case 1:
            embark();
            break;
        case 2:
            store();
            break;
        case 3:
            inventory();
            break;
        case 4:
            saveGame();
            begin();
            break;
    }
}

void Game::store()
{
    cout<<"\n\nThis is the store! Purchase new defensive or offensive items here. \nYou may also buy perks to give you advantages in battle!\n"
    <<"\n ENTER A NUMBER TO NAVIGATE:\n\n"
    <<"1. WEAPONS\n"
    <<"2. CLOTHES\n"
    <<"\n ENTER 0 TO RETURN TO THE HUB\n\n";
    int input=validateInput(0, 2);
    switch(input)
    {
        case 0:
            hub();
            break;
        case 1:
            store_weapons();
            break;
        case 2:
            store_clothes();
            break;
    }
}

void Game::store_weapons()
{
    cout<<"\n\nWeaponry\n"
    <<"\n ENTER A NUMBER TO INSPECT:\n\n"
    <<"1. ADVANCED ROCK\n"
    <<"2. ADVANCED PAPER\n"
    <<"3. ADVANCED SCISSORS\n"
    <<"ENTER 0 TO GO BACK\n";
    int input=validateInput(0, 3);
    if(input==0){store();}else{store_inspect(input,1);}
}

void Game::store_clothes()
{
    cout<<"\n\nCLOTHES\n"
    <<"\n ENTER A NUMBER TO INSPECT:\n\n"
    <<"1. BEANIE\n"
    <<"2. WIG\n"
    <<"3. HELMET\n"
    <<"4. SHIRT\n"
    <<"5. DRESS SHIRT\n"
    <<"6. KHAKIS\n"
    <<"7. SKIRT\n"
    <<"8. CROCS\n"
    <<"9. SNEAKERS\n"
    <<"10. SLIPPERS\n"
    <<"11. WATCH\n"
    <<"12. SUNGLASSES\n"
    <<"ENTER 0 TO GO BACK\n";
    int input=validateInput(0, 12);
    if(input==0){store();}else{store_inspect(input,-2);}
}

void Game::store_inspect(int itemno, int translate)
{
    string itemdesc[15]={"ADVANCED ROCK\n\nA rock is a solid mass of geological materials. Geological materials include individual mineral crystals, inorganic non-mineral solids like glass, pieces broken from other rocks, and even fossils. The geological materials in rocks may be inorganic, but they can also include organic materials such as the partially decomposed plant matter preserved in coal. A rock can be composed of only one type of geological material or mineral, but many are composed of several types.\n\nGAMEPLAY: DESTROYS SCISSORS, DESTROYED BY PAPER","ADVANCED PAPER\n\nPaper is a thin sheet material produced by mechanically or chemically processing cellulose fibres derived from wood, rags, grasses or other vegetable sources in water, draining the water through fine mesh leaving the fibre evenly distributed on the surface, followed by pressing and drying. It is a versatile material with many uses, including printing, packaging, decorating, writing, cleaning, filter paper, wallpaper, book endpaper, conservation paper, laminated worktops, toilet tissue, currency and security paper and a number of industrial and construction processes.\n\nGAMEPLAY: DESTROYS ROCK, DESTROYED BY SCISSORS","ADVANCED SCISSORS\n\nScissors are hand-operated shearing tools. A pair of scissors consists of a pair of metal blades pivoted so that the sharpened edges slide against each other when the handles (bows) opposite to the pivot are closed. Scissors are used for cutting various thin materials, such as paper, cardboard, metal foil, cloth, rope, and wire. A large variety of scissors and shears all exist for specialized purposes.\n\nGAMEPLAY: DESTROYS PAPER, DESTROYED BY ROCK","BEANIE\n\na beanie is a head-hugging brimless cap, made from triangular panels of material joined by a button at the crown and seamed together around the sides. Commonly made of cloth or felt material, beanies may also be made from leather or silk. In some US regions and parts of Canada the term beanie refers to a knitted cap (often woollen), alternately called a stocking cap or toque\n\nNO GAMEPLAY","WIG\n\nA wig is a head or hair accessory made from human hair, animal hair, or synthetic fiber.[1] The word wig is short for periwig,[2] which makes its earliest known appearance in the English language in William Shakespeare's The Two Gentlemen of Verona. Some people wear wigs to disguise baldness; a wig may be used as a less intrusive and less expensive alternative to medical therapies for restoring hair or for a religious reason.\n\nNO GAMEPLAY","HELMET\n\nA helmet is a form of protective gear worn to protect the head. More specifically, a helmet complements the skull in protecting the human brain. Ceremonial or symbolic helmets (e.g., a policeman's helmet in the United Kingdom) without protective function are sometimes worn. Soldiers wear combat helmets, often made from Kevlar or other lightweight synthetic fibers.\n\nNO GAMEPLAY","SHIRT\n\nA shirt is a cloth garment for the upper body (from the neck to the waist).\n\nNO GAMEPLAY","DRESS SHIRT\n\nA dress shirt, button shirt, button-front, button-front shirt, or button-up shirt is a garment with a collar and a full-length opening at the front, which is fastened using buttons or shirt studs. A button-down or button-down shirt is a dress shirt which has a button-down collar – a collar having the ends fastened to the shirt with buttons.\n\nNO GAMEPLAY","KHAKIS\n\nKhaki has been used by many armies around the world for uniforms, including camouflage. It has been used as a color name in English since 1848 when it was first introduced as a military uniform.[1] In Western fashion, it is a standard color for smart casual dress trousers for civilians, which are also often called khakis.\n\nNO GAMEPLAY","SKIRT\n\nA skirt is the lower part of a dress or a separate outer garment that covers a person from the waist downwards.\n\nNO GAMEPLAY","CROCS\n\nThe shoe was originally developed as a boating shoe. The first model produced by Crocs, the Beach, was unveiled in 2001 at the Fort Lauderdale Boat Show in Florida, and the 200 pairs that they had produced were all sold.[10] Crocs has since sold 300 million pairs of shoes.[11] In June 2020, Crocs moved the headquarters from Niwot, Colorado to Broomfield.\n\nNO GAMEPLAY","SNEAKERS\n\nSneakers (also called trainers, athletic shoes, tennis shoes, gym shoes, kicks, sport shoes, flats, running shoes, skate shoes, or runners) are shoes primarily designed for sports or other forms of physical exercise, but which are now also widely used for everyday casual wear.\n\nNO GAMEPLAY","SLIPPERS\n\nSlippers are light footwear that are easy to put on and off and are intended to be worn indoors, particularly at home.[1] They provide comfort and protection for the feet when walking indoors.\n\nNO GAMEPLAY","WRIST WATCH\n\nA watch is a portable timepiece intended to be carried or worn by a person. It is designed to keep a consistent movement despite the motions caused by the person's activities. A wristwatch is designed to be worn around the wrist, attached by a watch strap or other type of bracelet, including metal bands, leather straps or any other kind of bracelet.\n\nNO GAMEPLAY","SUNGLASSES\n\nSunglasses or sun glasses (informally called shades or sunnies; more names below) are a form of protective eyewear designed primarily to prevent bright sunlight and high-energy visible light from damaging or discomforting the eyes. They can sometimes also function as a visual aid, as variously termed spectacles or glasses exist, featuring lenses that are colored, polarized or darkened. In the early 20th century, they were also known as sun cheaters (cheaters then being an American slang term for glasses)\n\nNO GAMEPLAY"};
    int itemcosts[15]={10,10,10,1000,1000,5000,2500,5000,3500,3500,5000,1000,2000,2500,10000};
    item catalog[15]={
        item("rock",15,"Weapon","Upon the right hand- is a rock. Pointed edges and rough faces appear all over.."),
        item("paper",15,"Weapon","In the left hand, there appears to be a sheet of paper. The paper appears thin and razor sharp."),
        item("scissors",15,"Weapon","On their back are scissors, capable of cutting through any sheet. They sparkle in the presence of the sunlight.."),
        item("beanie",1,"Wearable","The warrior wears a cozy beanie on top of their head, covering both ears."),
        item("wig",1,"Wearable","The warrior dawns a fashionable wig that drapes over their shoulders."),
        item("helmet",1,"Wearable","A mighty helmet glimmers in the light and strikes fear in many."),
        item("shirt",1,"Wearable","They wear a shirt, 100% cotton, and very clean."),
        item("dressshirt",1,"Wearable","They wear a nice button shirt, accompanied with a neck tie. Very formal."),
        item("khakis",1,"Wearable","Nice, brown khakis are worn."),
        item("skirt",1,"Wearable","A beautiful skirt drapes over the legs."),
        item("crocs",1,"Wearable","Trendy crocs fit snuggly onto the feet."),
        item("sneakers",1,"Wearable","Smelly sneakers emit horrible stench."),
        item("slippers",1,"Wearable","The slippers expose the beautiful toes of the warrior."),
        item("watch",1,"Wearable","On the wrist is a watch that tells the time. It is muffin time."),
        item("sunglasses",1,"Wearable","Sunglasses rest on the warriors face, as explosions erupt behind them."),
    };
    cout<<itemdesc[itemno-translate]<<endl
    <<"\n Would you like to purchase this? ("<<itemcosts[itemno-translate]<<" moneys)\n"
    <<"ENTER YES (Y) OR NO (N):\n";
    string input;
    cin>>input;
    item * itemptr;
    if(input=="Y")
    {
        if(currentPlayer.getMoney()>=itemcosts[itemno-translate])
        {
            currentPlayer.setMoney(currentPlayer.getMoney()-itemcosts[itemno-translate]);
            
            if(currentPlayer.getItem(catalog[itemno-translate].getName())!=NULL)
            {
                itemptr=currentPlayer.getItem(catalog[itemno-translate].getName());
                itemptr->setQuantity(itemptr->getQuantity()+1);
            }
            else
            {
                item i =catalog[itemno-translate];
                itemptr=&i;
                currentPlayer.addToBackpack(itemptr);
            }
            cout<<"PURCHASE SUCCESSFFUL!\n";
        }
        else
        {
            cout<<"INSUFFICENT FUNDS! :(\n";
        }
        store_weapons();
    }
    else
    {
        cout<<"PURCHASE CANCELLED!\n";
        store_weapons();
    }
}

void Game::embark()
{
    cout<<"\n\nThis is your world map! There are 5 acts per zone. \nOnce you complete all zones you may take on the final boss!\n"
    <<"\n ENTER THE ZONE NUMBER:\n\n"
    <<"1. ZONE 1: ("<<currentPlayer.getZone1Progress()<<"/3)\n"
    <<"2. ZONE 2: ("<<currentPlayer.getZone2Progress()<<"/3)\n"
    <<"3. ZONE 3: ("<<currentPlayer.getZone3Progress()<<"/3)\n\n\n"
    <<"4. FINAL ZONE: ("<<currentPlayer.getZone4Progress()<<"/1)\n\n"
    <<"ENTER 0 TO RETURN TO HUB\n";
    int input=validateInput(0, 4);
    if(input==0)
    {
        hub();
    }
    else if(input==4)
    {
        if(currentPlayer.getZone1Progress()>=3&&currentPlayer.getZone2Progress()>=3&&
           currentPlayer.getZone3Progress()>=3)
        {
            Round r(input);
            r.play(currentPlayer);
            r.setEnemyLife(10);
            embark();
        }
        else
        {
            cout<<"INSUFFICIENT PROGRESS!\n";
            embark();
        }
    }
    else
    {
        Round r(input);
        r.play(currentPlayer);
        embark();
    }
}

void Game::inventory()
{
    cout<<"\n\nPLAYER INVENTORY\n"
    <<"Your Balance:"<<currentPlayer.getMoney()<<endl
    <<"Your Experience:"<<currentPlayer.getExp()<<endl;
    
    cout<<setw(10)<<"- INDEX -"<<setw(10)<<"- ITEM NAME -"<<setw(10)<<"- CATEGORY -"<<
    setw(10)<<"- QUANTITY -"<<setw(10)<<"- WEARING -"<<endl;
    
    item * itmptr;
    int backpacksize=currentPlayer.getBackpack().size();
    for(int i=0;i<backpacksize;i++)
    {
        itmptr=currentPlayer.getItem(i);
        if(itmptr->isOnBody()){cout<<itmptr->getDesc();}
    }
    cout<<endl;
    for(int i=0;i<backpacksize;i++)
    {
        itmptr=currentPlayer.getItem(i);
        cout<<setw(10)<<i+1<<setw(10)<<itmptr->getName()<<setw(10)<<itmptr->getCategory()<<
        setw(10)<<itmptr->getQuantity()<<setw(10)<<itmptr->isOnBody()<<endl;
    }
    
    cout<<"ENTER A NUMBER TO WEAR/TAKE OFF THE ITEM. ENTER 0 TO RETURN TO THE HUB\n";
    int input=validateInput(0,backpacksize);
    if(input==0){hub();}
    else
    {
        itmptr=currentPlayer.getItem(input-1);
        itmptr->dawn();
    }
    inventory();
}

void Game::saveGame()
{
    fstream file;
    file.open(currentPlayer.getName()+".txt");
    item*itemptr;
    file<<currentPlayer.getMoney()<<endl;
    file<<currentPlayer.getExp()<<endl;
    file<<currentPlayer.getZone1Progress()<<endl;
    file<<currentPlayer.getZone2Progress()<<endl;
    file<<currentPlayer.getZone3Progress()<<endl;
    file<<currentPlayer.getZone4Progress()<<endl;
    
    for(int i=0;i<currentPlayer.getBackpack().size();i++)
    {
        itemptr=currentPlayer.getItem(i);
        file<<itemptr->getName()<<endl;
        file<<itemptr->getQuantity()<<endl;
        file<<itemptr->getCategory()<<endl;
        file<<itemptr->getDesc()<<endl;
        file<<itemptr->isOnBody()<<endl;
    }
    file.close();
}

//void Game::saveGame()
//{
//    fstream file;
//    file.open(currentPlayer.getName()+".txt");
//    file.write( (char*)&currentPlayer, sizeof(currentPlayer) );
//    file.close();
//}
