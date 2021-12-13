//
//  round.cpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/8/21.
//

#include "round.hpp"

Round::Round(int z)
{
    zone=z;
    enemy = generateEnemy(z);
}

void Round::setEnemyLife(int l)
{
    enemyLife=l;
}

Enemy Round::generateEnemy(int zone)
{
    srand(time(0));
    string zone1[5] = {"Professor Tadayon","Tracy","David","Ben","Thunder"};
    string zone2[5] = {"Santa","Frosty","Rudolph","Jack Frost","Elf"};
    string zone3[5] = {"Snoop Dogg","Obama","Xenomorph","Shrek","Mario"};
    int rockp=rand()%100;
    int paperp=rand()%(100-rockp);
    Enemy e(zone1[rand()%4],0.1,rockp,paperp,500);
    string enname;
    switch (zone)
    {
        case 1:
            enname=zone1[rand()%4];
            e.setName(enname);
            cout<<"\n\nYou walk down Lopes Way trying to find some food to end your starvation..Until suddenly, "<<enname<<" appears to challenge you in a game of ROCK, PAPER SCISSORS!"<<endl;
            break;
        case 2:
            enname=zone2[rand()%4];
            e.setName(enname);
            cout<<"\n\nIts Christmas morning and you wake up to find no presents under your tree.. You embark on a journey to the North Pole to punish those who haved wronged you.., "<<enname<<" appears to challenge you in a game of ROCK, PAPER SCISSORS!"<<endl;
            break;
        case 3:
            enname=zone3[rand()%4];
            e.setName(enname);
            cout<<"\n\nYou fall into a hole of infinite dispair and all seems lost.. Creatures of every kind appear around you.., "<<enname<<" appears to challenge you in a game of ROCK, PAPER SCISSORS!"<<endl;
            break;
        case 4:
            e.setName("Thanos");
            break;
    }
    return e;
}

void Round::play(Player &player)
{
    while (true)
    {
        Hand playersHand(player.shoot());
        Hand enemysHand(enemy.shoot());
        
        if(playersHand.getValue()==0)
        {
            cout<<"YOU FORFEIT.. \n"<<endl
            <<"You have no weaponry to battle with..\n"<<endl
            <<"PRESS ENTER ANYTHING TO CONTINUE."<<endl;
            string q; cin>>q;
            break;
        }
        else if(enemysHand.getValue()==0)
        {
            cout<<enemy.getName()<< " FORFEITS.. \n"<<endl
            <<"They had no weaponry to battle with..\n"<<endl
            <<"PRESS ENTER ANYTHING TO CONTINUE."<<endl;
            string q; cin>>q;
            break;
        }
        else
        {
            cout<<enemy.getName()<<" used " << enemysHand.getType()<<". You chose "<<
            playersHand.getType()<<"."<<endl;
            
            Character * charptr;
            
            if (playersHand.getType()==enemysHand.getType()) {
                cout<<"ITS A TIE!"<<endl;
            }
            else if (playersHand.getBeatenBy()==enemysHand.getType())
            {
                cout<<"YOU LOSE A LIFE!"<<endl;
                charptr=&enemy;
                charptr->taunt();
                playerLife--;
            }
            else if (enemysHand.getBeatenBy()==playersHand.getType())
            {
                cout<<enemy.getName()<< " LOSES A LIFE!"<<endl;
                charptr=&player;
                charptr->taunt();
                enemyLife--;
            }
            
            if (enemyLife==0) {
                player.setMoney(enemy.getLoot()+player.getMoney());
                player.setExp(player.getExp()+100);
                if(zone==1){player.setZone1Progress(player.getZone1Progress()+1);}
                else if(zone==2){player.setZone2Progress(player.getZone2Progress()+1);}
                else if(zone==3){player.setZone3Progress(player.getZone3Progress()+1);}
                else if(zone==4){player.setZone4Progress(player.getZone4Progress()+1);}
                cout<<"YOU WIN! \n"<<endl
                <<"You gained "<<enemy.getLoot()<<" money!\n"<<endl
                <<"PRESS ENTER ANYTHING TO CONTINUE."<<endl;
                string q; cin>>q;
                break;
            }
            else if(playerLife==0)
            {
                player.setMoney(player.getMoney()-(player.getMoney()*enemy.getStealPntge()));
                player.setExp(player.getExp()+2);
                cout<<"YOU ARE A FAILURE! \n"<<endl
                <<enemy.getName()<<" stole some of your money and left you for dead..\n"<<endl
                <<"TRY AGAIN? PRESS ENTER ANYTHING TO CONTINUE."<<endl;
                string q; cin>>q;
                break;
            }
            else
            {
                continue;
            }
        }
    }
}
