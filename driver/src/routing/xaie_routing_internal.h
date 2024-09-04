/******************************************************************************
* Copyright (C) 2024 AMD, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/


/*****************************************************************************/
/**
* @file xaie_routing.h
* @{
*
* This file contains the internal high level APIs for AI-Engines.
*
******************************************************************************/
#ifndef XAIE_ROUTING_INTERNAL_H
#define XAIE_ROUTING_INTERNAL_H

/***************************** Include Files *********************************/
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <xaiegbl.h>

//internal functions
static void _XAie_printBitfield(int value, int bits);
static const char* _XAie_StrmSwPortTypeToString(StrmSwPortType type);
static void _XAie_drawRoute(XAie_RoutingInstance *routingInstance, XAie_LocType *path, int pathLength,
         XAie_LocType source, XAie_LocType destination);
static void _XAie_enqueue(Queue* queue, XAie_LocType item);
static XAie_LocType _XAie_dequeue(Queue* queue);
static bool _XAie_isShimTile(XAie_RoutingInstance* RoutingInstance, XAie_LocType tile);
static AieRC _XAie_updatePortAvailabilityForShimDmaToAie(XAie_RoutingInstance *routingInstance, XAie_LocType tile, int stream, bool SetOrUnset /*True for set*/);
static AieRC _XAie_updatePortAvailabilityForAieToShimDma(XAie_RoutingInstance *routingInstance, XAie_LocType tile, int stream, bool SetOrUnset /*True for set*/);
static void _XAie_updatePortAvailabilityForStrmConn(XAie_RoutingInstance *routingInstance, XAie_LocType tile, StrmSwPortType portSource, int sourceStream, StrmSwPortType portDest, int destStream);
static int _XAie_findFirstMatchingStream(XAie_RoutingInstance* RoutingInstance, XAie_LocType tile,
        StrmSwPortType direction, bool isEndTile);
static void _XAie_resetBDAvailability(XAie_RoutingInstance *routingInstance, XAie_LocType tile, u8 bdID);
static int _XAie_findAvailableBufferID(XAie_RoutingInstance *routingInstance, XAie_LocType tile);
static bool _XAie_isAdjTileValidForCurrTile(XAie_RoutingInstance* RoutingInstance, XAie_RouteConstraints* RouteConstraints,
                    XAie_LocType currentTile, XAie_LocType adjTile, StrmSwPortType direction, bool** visited);
static AieRC _XAie_performRoutingOnPath(XAie_RoutingInstance *routingInstance, XAie_LocType source, XAie_LocType destination, XAie_LocType *path, int pathLength);
static AieRC _XAie_programBufferDescriptors(XAie_RoutingInstance *routingInstance, XAie_LocType source, void* SourceObject, u32 data_size, void* DestinationObject,
                              XAie_LocType destination, XAie_BDs* BDs);
static bool _XAie_findShortestPath(XAie_RoutingInstance *routingInstance, XAie_RouteConstraints* RouteConstraints, XAie_LocType source, XAie_LocType destination, XAie_LocType *path, int *pathLength);
static bool _XAie_isTileBlackListed(XAie_LocType CurrTile, XAie_RouteConstraints* RouteConstraints);
static bool _XAie_isTileWhitelisted(XAie_LocType CurrTile, XAie_LocType *whitelist, u16 whitelistCount);
static bool _XAie_isMemTile(XAie_RoutingInstance* RoutingInstance, XAie_LocType tile);
static void _XAie_updatePortAvailabilityForStrmConnInverse(XAie_RoutingInstance *routingInstance, XAie_LocType tile,
        StrmSwPortType portSource, int sourceStream, StrmSwPortType portDest, int destStream);
static void _XAie_freeXAieProgrammedRoutes(XAie_ProgrammedRoutes* headRoute);
static void _XAie_FreeRouteFromRoutesDB(XAie_ProgrammedRoutes** head, XAie_LocType source, XAie_LocType destination);
static void _XAie_FreeRoutingSteps(XAie_RoutingStep* step);
static XAie_RoutingPath* _XAie_findRouteInRouteDB(XAie_ProgrammedRoutes* routesDB, XAie_LocType source, XAie_LocType destination);
static void _XAie_addRouteInRoutesDB(XAie_ProgrammedRoutes** head, XAie_RoutingPath* routePath);

#endif	/* End of protection macro */

/** @} */
