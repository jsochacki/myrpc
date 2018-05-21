
#ifndef RPC_STRUCTURES_H_
#define RPC_STRUCTURES_H_

enum state
{
    DISABLED = 0,
    OFF = 0,
    NOTRUNNING = 0,
    COMPLETE = 0,
    ENABLED = 1,
    ON = 1,
    RUNNING = 1,
    INCOMPLETE = 1,
};

//Sub sructure definitions
struct NumParams
{
   unsigned int state_count;
   unsigned int tx_count;
   unsigned int fft_count;
   unsigned int other_count;
};


struct StateParameters
{
   state save_iq;
   state parameter_estimate_enable;
   state awgn_enable;
   state notch_enable;
   state fft_a_enable;
   state fft_b_enable;
};

struct TxParameters
{
   double num_tx_samples_total;
   double tx_freq1_Hz;
   double tx_freq2_Hz;
   double tx_phase1_rot;
   double tx_phase2_rot;
};

struct FFTParameters
{
   unsigned int fft_length_a;
   unsigned int fft_batches_a;
   unsigned int fft_length_b;
   unsigned int fft_batches_b;
};

struct OtherParameters
{
   double num_rx_samples;
   double rx_rot_freq_Hz;
   unsigned int decimation;
   unsigned int gain1;
   unsigned int gain2;
   double nextTxStartTime;
   double nextRxStartTime;
};


struct NullMessage
{

};

//Top level definitions

//COMPOSITE TOP LEVEL MESSAGES
struct set_parameters
{
   NumParams num_params;
   StateParameters state_parameters;
   TxParameters tx_parameters;
   FFTParameters fft_parameters;
   OtherParameters other_parameters;
};

struct parameter_values
{
   NumParams num_params;
   StateParameters state_parameters;
   TxParameters tx_parameters;
   FFTParameters fft_parameters;
   OtherParameters other_parameters;
};

#endif /* RPC_STRUCTURES_H_ */
