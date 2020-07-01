/*****************************************************************************
 *
 * MODULE:             Develco Volatile Organic Compounds (VOC) Measurement Cluster
 *
 * COMPONENT:          DevelcoVOCMeasurement.c
 *
 * AUTHOR:             schrodingersket
 *
 * DESCRIPTION:        Develco Volatile Organic Compounds (VOC) cluster definition
 *
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "zcl.h"
#include "DevelcoVOCMeasurement.h"
#include "zcl_customcommand.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
const tsZCL_AttributeDefinition asCLD_DevelcoVOCMeasurementClusterAttributeDefinitions[] = {
#ifdef DEVELCO_VOC_MEASUREMENT_SERVER
        {E_CLD_DEVELCO_VOC_MEAS_ATTR_ID_MEASURED_VALUE,               (E_ZCL_AF_RD|E_ZCL_AF_RP),      E_ZCL_UINT16,  (uint32)(&((tsCLD_DevelcoVOCMeasurement*)(0))->u16MeasuredValue),    0},  /* Mandatory */

        {E_CLD_DEVELCO_VOC_MEAS_ATTR_ID_MIN_MEASURED_VALUE,           E_ZCL_AF_RD,                    E_ZCL_UINT16,  (uint32)(&((tsCLD_DevelcoVOCMeasurement*)(0))->u16MinMeasuredValue), 0},  /* Mandatory */

        {E_CLD_DEVELCO_VOC_MEAS_ATTR_ID_MAX_MEASURED_VALUE,           E_ZCL_AF_RD,                    E_ZCL_UINT16,  (uint32)(&((tsCLD_DevelcoVOCMeasurement*)(0))->u16MaxMeasuredValue), 0},  /* Mandatory */

        {E_CLD_DEVELCO_VOC_MEAS_ATTR_ID_RESOLUTION,                    E_ZCL_AF_RD,                    E_ZCL_UINT16,  (uint32)(&((tsCLD_DevelcoVOCMeasurement*)(0))->u16Resolution), 0},  /* Mandatory */


#endif    
        {E_CLD_GLOBAL_ATTR_ID_CLUSTER_REVISION,             (E_ZCL_AF_RD|E_ZCL_AF_GA),      E_ZCL_UINT16,   (uint32)(&((tsCLD_DevelcoVOCMeasurement*)(0))->u16ClusterRevision),  0},   /* Mandatory  */
};

tsZCL_ClusterDefinition sCLD_DevelcoVOCMeasurement = {
		MEASUREMENT_AND_SENSING_CLUSTER_ID_DEVELCO_VOC_MEASUREMENT,
        FALSE,
        E_ZCL_SECURITY_NETWORK,
        (sizeof(asCLD_DevelcoVOCMeasurementClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition)),
        (tsZCL_AttributeDefinition*)asCLD_DevelcoVOCMeasurementClusterAttributeDefinitions,
        NULL
};

uint8 au8DevelcoVOCMeasurementAttributeControlBits[(sizeof(asCLD_DevelcoVOCMeasurementClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition))];

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 **
 ** NAME:       eCLD_DevelcoVOCMeasurementCreateDevelcoVOCMeasurement
 **
 ** DESCRIPTION:
 ** Creates a Develco VOC measurement cluster
 **
 ** PARAMETERS:                 Name                        Usage
 ** tsZCL_ClusterInstance       *psClusterInstance             Cluster structure
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_DevelcoVOCMeasurementCreateDevelcoVOCMeasurement(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8                              *pu8AttributeControlBits)
{
    #ifdef STRICT_PARAM_CHECK 
        /* Parameter check */
        if((psClusterInstance == NULL) ||
           (psClusterDefinition == NULL))
        {
            return E_ZCL_ERR_PARAMETER_NULL;
        }
    #endif


    /* Create an instance of a VOC measurement cluster */
    vZCL_InitializeClusterInstance(
                                   psClusterInstance, 
                                   bIsServer,
                                   psClusterDefinition,
                                   pvEndPointSharedStructPtr,
                                   pu8AttributeControlBits,
                                   NULL,
                                   NULL);
                                   

        if(pvEndPointSharedStructPtr != NULL)
        {
        #ifdef DEVELCO_VOC_MEASUREMENT_SERVER
            ((tsCLD_DevelcoVOCMeasurement*)pvEndPointSharedStructPtr)->u16MinMeasuredValue = 0x0000;
            ((tsCLD_DevelcoVOCMeasurement*)pvEndPointSharedStructPtr)->u16MaxMeasuredValue = 0xEA60; // 60000
        #endif
            ((tsCLD_DevelcoVOCMeasurement*)pvEndPointSharedStructPtr)->u16ClusterRevision = CLD_DEVELCO_VOC_MEAS_CLUSTER_REVISION;
        }

    /* As this cluster has reportable attributes enable default reporting */
    vZCL_SetDefaultReporting(psClusterInstance);
    
    return E_ZCL_SUCCESS;

}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

