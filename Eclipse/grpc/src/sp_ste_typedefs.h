
#ifndef SP_STE_TYPEDEFS_H_
#define SP_STE_TYPEDEFS_H_

#include <iostream>
#include <memory>
#include <fstream>

#include <vector>
#include <algorithm>
#include <map>

struct InFileData
{
    public:
        std::string current_type;
        std::string current_name;
        std::string current_value;
        void add_to_list();
        void next_in_list(std::string &, std::string &, std::string &);
        void reset_count();
        int get_count();
        int get_element_and_increment();
        int get_element_count();
    private:
        int count = 0;
        int accumulator = 0;
        int number_of_elements = 0;
        std::vector<std::string> types;
        std::vector<std::string> names;
        std::vector<std::string> values;
};


enum IdlePatterns
{
   TX_IDLE_PATTERN_ZERO = 0,
   TX_IDLE_PATTERN_RAMP = 1,
   TX_IDLE_PATTERN_CW = 2
};

struct SPSingleMeasurementParams
{
   public:
      std::string IdlePatternStrings[3]{"TX_IDLE_PATTERN_ZERO",
                                      "TX_IDLE_PATTERN_RAMP",
                                      "TX_IDLE_PATTERN_CW"};

      // Per-test RX inputs begin
      uint32_t fft_length_a = 0;
      uint32_t fft_length_b = 0;
      uint32_t fft_batches_a = 0;
      uint32_t fft_batches_b = 0;

      uint32_t decimation = 0;
      uint32_t num_rx_samples = 0;
      // Per-test RX inputs end

      // Per-test TX inputs begin
      uint32_t num_tx_samples_total = 0;
      uint32_t num_tx_samples_per_batch = 0;
      // Per-test TX inputs end

      // Per-test RX inputs begin
      float rx_rot_freq_Hz = 0.0;
      // Per-test RX inputs end

      // Per-test TX inputs begin
      float tx_freq1_Hz = 0.0;
      float tx_phase1_rot = 0.0;
      float tx_freq2_Hz = 0.0;
      float tx_phase2_rot = 0.0;
      float gain1 = 0.0;
      float gain2 = 0.0;
      float gain3 = 0.0;
      // Per-test TX inputs end

      // Per-test RX inputs begin
      bool save_iq = false;
      bool fft_a_enable = false;
      bool fft_b_enable = false;
      bool parameter_estimate_enable = false;
      // Per-test RX inputs end

      // Per-test TX inputs begin
      bool awgn_enable = false;
      bool notch_enable = false;
      // Per-test TX inputs end

      // Per-test RX inputs begin
      std::string filename_fft_a = "empty"; //These are derived from the base name provided
      std::string filename_fft_b = "empty"; //These are derived from the base name provided
      std::string filename_rx_samples = "empty"; //These are derived from the base name provided
      // Per-test RX inputs end

      // Per-test TX inputs begin
      std::string filename_tx_samples = "empty";
      // Per-test TX inputs end

      // Per-test RX inputs begin
      uint64_t nextRxStartTime = 0.0; //This is not provided
      // Per-test RX inputs end

      // Per-test TX inputs begin
      uint64_t nextTxStartTime = 0.0;
      // Per-test TX inputs end

      // Per-test TX inputs begin
      IdlePatterns tx_idle_pattern = TX_IDLE_PATTERN_ZERO; // 0: Zeros, 1: Ramp, 2: Tone at tx_freq1_Hz
      // Per-test TX inputs end

      bool load_config_file(const std::string filename);

      bool load_in_file_data(InFileData &in_file_data);

      template <typename Type>
      Type get_element(const int);

      template <typename Type>
      void set_element(const int, Type);

      int get_element_count();

   private:
      int element_count = 0;
      int number_of_elements = 29;
      bool fully_initialized = false;
};


#endif /* SP_STE_TYPEDEFS_H_ */
