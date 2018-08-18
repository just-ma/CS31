//
//  Player.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"



namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mRound( 0 ) //default score is 0, default round is 0
    {
        
    }

    int Player::roll( int amount )
    {
        int amountrolled;
        if (amount == 0) //if amount entered is 0, random number is generated
        {
            mDie.roll();
            if (mDie.getValue() == mRound) //if number matches round number, score increases
                mScore++;
            amountrolled = mDie.getValue();
        }
        else
        {
            if (amount == mRound) //for entering manual amounts
                mScore++;
            amountrolled = amount;
        }
        return amountrolled;
    }
    
    void Player::setRound( int round )
    {
        mRound = round; //sets round to the number provided
        mScore = 0; //resets score to 0
    }
    
    int  Player::getScore( ) const
    {
        return mScore; //returns the current score
    }
    
    
}
