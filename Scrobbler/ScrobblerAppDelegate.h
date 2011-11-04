//
//  ScrobblerAppDelegate.h
//  Scrobbler
//
//  Created by Nanoha Takamachi on 10/28/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Scribbler/Scribbler.h>
// Forward declarations
@class SYUIController;
@interface ScrobblerAppDelegate : NSObject <NSApplicationDelegate> {
	IBOutlet SYUIController *ui;
	IBOutlet NSWindow *mainWindow;
    IBOutlet NSMenu *statusMenu;
    NSStatusItem                *statusItem;
    NSImage                        *statusImage;
    NSImage                        *statusHighlightImage;
	NSMutableArray *recentTracks;
	IBOutlet NSTableView *trackTableView;
	
	LFTrack *currentTrack;
	NSUInteger currentTrackID;
	BOOL wasPlaying;
	
	BOOL authorizationPending;
    BOOL ScrrobleState;
    IBOutlet NSMenuItem *ToggleScrobbling;
    IBOutlet NSTextField *Scrobblerstatus;
}

// Application delegate methods
- (void)applicationDidFinishLaunching:(NSNotification *)aNotification;
- (BOOL)applicationOpenUntitledFile:(NSApplication *)theApplication;

// Connection methods
- (IBAction)connectWithLastFM:(id)sender;
- (IBAction)disconnectFromLastFM:(id)sender;
- (void)connectWithStoredCredentials;
- (void)completeAuthorization:(NSNotification *)theNotification;

// Web service delegate methods
- (void)sessionNeedsAuthorizationViaURL:(NSURL *)theURL;
- (void)sessionAuthorizationStillPending;
- (void)sessionAuthorizationFailed;
- (void)sessionCreatedWithKey:(NSString *)theKey user:(NSString *)theUser;

- (void)sessionValidatedForUser:(NSString *)theUser;
- (void)sessionInvalidForUser:(NSString *)theUser;
- (void)sessionKeyRevoked:(NSString *)theKey forUser:(NSString *)theUser;

- (void)scrobblerClient:(NSString *)theClientID bannedForVersion:(NSString *)theClientVersion;

- (void)scrobbleSucceededForTrack:(LFTrack *)theTrack;
- (void)scrobbleFailedForTrack:(LFTrack *)theTrack error:(NSError *)theError willRetry:(BOOL)willRetry;

// Tracking methods
- (void)playerInfoChanged:(NSNotification *)theNotification;
- (IBAction)loveTrack:(id)sender;
- (IBAction)banTrack:(id)sender;

// Table data source methods
- (NSInteger)numberOfRowsInTableView:(NSTableView *)aTableView;
- (id)tableView:(NSTableView *)aTableView objectValueForTableColumn:(NSTableColumn *)aTableColumn row:(NSInteger)rowIndex;

//Menu Commands
- (IBAction)togglescrobbling:(id)sender;
@end
