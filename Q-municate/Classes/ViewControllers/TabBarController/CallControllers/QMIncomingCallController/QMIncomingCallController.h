//
//  QMIncomingCallController.h
//  Q-municate
//
//  Created by Igor Alefirenko on 08/04/2014.
//  Copyright (c) 2014 Quickblox. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface QMIncomingCallController : UIViewController

@property (assign, nonatomic) NSUInteger opponentID;
@property (assign, nonatomic) BOOL isVideoCall;
@property (strong, nonatomic) QBUUser *opponent;

@end