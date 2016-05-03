/* Auto-generated config file hpl_dmac_v100_config.h */
#ifndef HPL_DMAC_V100_CONFIG_H
#define HPL_DMAC_V100_CONFIG_H

	// <<< Use Configuration Wizard in Context Menu >>>

	// <h> M2M DMA Channel Control
	// <q> Channel Enable
	// <i> Indicates whether Channel Enable is enabled or not
	// <id> m2m_dma_ch_enable
#ifndef CONF_M2M_DMAC_0_CH_ENABLE
#    define CONF_M2M_DMAC_0_CH_ENABLE 1
#endif

	// <o>Trigger Action
	// <0x0=>BLOCK
	// <0x2=>BEAT
	// <0x3=>TRANSACTION
	// <i> Define the trigger action used for a transfer
	// <id> m2m_dma_trigact
#ifndef CONF_M2M_DMAC_0_TRIGACT
#    define CONF_M2M_DMAC_0_TRIGACT 0x3
#endif

	// <o>Channel Arbitration Level
	// <0x0=>Priority Level 0
	// <0x1=>Priority Level 1
	// <0x2=>Priority Level 2
	// <0x3=>Priority Level 3
	// <i> Define arbitration level used for a DMA channel
	// <id> m2m_dma_lvl
#ifndef CONF_M2M_DMAC_0_LVL
#    define CONF_M2M_DMAC_0_LVL 0x0
#endif

	// <o> Beat Size
	// <0x0=>BYTE
	// <0x1=>HWORD
	// <0x2=>WORD
	// <i> Define the size of one beat
	// <id> m2m_dma_beatsize
#ifndef CONF_M2M_DMAC_0_BEATSIZE
#    define CONF_M2M_DMAC_0_BEATSIZE 0x0
#endif

	// <o> Address Increment Step Size
	// <0x0=>BEATSIZE * 1
	// <0x1=>BEATSIZE * 2
	// <0x2=>BEATSIZE * 4
	// <0x3=>BEATSIZE * 8
	// <0x4=>BEATSIZE * 16
	// <0x5=>BEATSIZE * 32
	// <0x6=>BEATSIZE * 64
	// <0x7=>BEATSIZE * 128
	// <i> Define address increment step size
	// <id> m2m_dma_stepsize
#ifndef CONF_M2M_DMAC_0_STEPSIZE
#    define CONF_M2M_DMAC_0_STEPSIZE 0x0
#endif

	// <o> Step Selection
	// <0x0=>DST
	// <0x1=>SRC
	// <i> Define source or destination are using the step size settings
	// <id> m2m_dma_stepsel
#ifndef CONF_M2M_DMAC_0_STEPSEL
#    define CONF_M2M_DMAC_0_STEPSEL 0x0
#endif

	// <q> Destination Address Increment Enable
	// <i> Indicates whether Destination Address Increment Enable is enabled or not
	// <id> m2m_dma_dstinc
#ifndef CONF_M2M_DMAC_0_DSTINC
#    define CONF_M2M_DMAC_0_DSTINC 1
#endif

	// <q> Source Address Increment Enable
	// <i> Indicates whether Source Address Increment Enable is enabled or not
	// <id> m2m_dma_srcinc
#ifndef CONF_M2M_DMAC_0_SRCINC
#    define CONF_M2M_DMAC_0_SRCINC 1
#endif

	// <o>Block Action
	// <0x0=>NOACT
	// <0x1=>INT
	// <0x2=>SUSPEND
	// <0x3=>BOTH
	// <i> Define what action the DMAC take after a block transfer has completed
	// <id> m2m_dma_blockact
#ifndef CONF_M2M_DMAC_0_BLOCKACT
#    define CONF_M2M_DMAC_0_BLOCKACT 0x0
#endif
	// </h>

#define DMAC_transaction 1
#define DMAC_channel 1

	// <<< end of configuration section >>>

#endif         // HPL_DMAC_V100_CONFIG_H
