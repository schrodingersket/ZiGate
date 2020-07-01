

/*****************************************************************************
 *
 * MODULE:             Develco Volatile Organic Compounds (VOC) Measurement Cluster
 *
 * COMPONENT:          DevelcoVOCMeasurement.h
 *
 * AUTHOR:             schrodingersket
 *
 * DESCRIPTION:        Header for Develco Volatile Organic Compounds (VOC) Measurement Cluster
 *
 ****************************************************************************/

#ifndef DEVELCO_VOC_MEASUREMENT_H
#define DEVELCO_VOC_MEASUREMENT_H

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef CLD_DEVELCO_VOC_MEAS_CLUSTER_REVISION
    #define CLD_DEVELCO_VOC_MEAS_CLUSTER_REVISION        1
#endif

/* Cluster IDs */
#define MEASUREMENT_AND_SENSING_CLUSTER_ID_DEVELCO_VOC_MEASUREMENT  0xfc03


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef enum 
{
    /* Develco VOC Measurement Information attribute set attribute IDs (https://www.develcoproducts.com/media/1674/aqszb-110-technical-manual-air-quality-sensor.pdf) */
    E_CLD_DEVELCO_VOC_MEAS_ATTR_ID_MEASURED_VALUE          = 0x0000,  /* Mandatory */
    E_CLD_DEVELCO_VOC_MEAS_ATTR_ID_MIN_MEASURED_VALUE,                /* Mandatory */
    E_CLD_DEVELCO_VOC_MEAS_ATTR_ID_MAX_MEASURED_VALUE,                /* Mandatory */
    E_CLD_DEVELCO_VOC_MEAS_ATTR_ID_RESOLUTION,						  /* Mandatory */
} teCLD_DevelcoVOCMeasurement_AttributeID;

/* Develco VOC Measurement Cluster */
typedef struct
{
#ifdef DEVELCO_VOC_MEASUREMENT_SERVER
    zuint16                u16MeasuredValue;

    zuint16                u16MinMeasuredValue;

    zuint16                u16MaxMeasuredValue;

    zuint16                u16Resolution;
#endif

    zuint16                u16ClusterRevision;
} tsCLD_DevelcoVOCMeasurement;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_DevelcoVOCMeasurementCreateDevelcoVOCMeasurement(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8                              *pu8AttributeControlBits);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
extern tsZCL_ClusterDefinition sCLD_DevelcoVOCMeasurement;
extern uint8 au8DevelcoVOCMeasurementAttributeControlBits[];
extern const tsZCL_AttributeDefinition asCLD_DevelcoVOCMeasurementClusterAttributeDefinitions[];
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* DEVELCO_VOC_MEASUREMENT_H */
