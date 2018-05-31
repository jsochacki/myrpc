#include "sp_ste_typedefs.h"

void InFileData::add_to_list()
{
    this->types.push_back(this->current_type);
    this->names.push_back(this->current_name);
    this->values.push_back(this->current_value);
    number_of_elements++;
}

void InFileData::next_in_list(std::string &type,
                              std::string &name,
                              std::string &value)
{
    type = this->types[count];
    name = this->names[count];
    value = this->values[count];
    count++;
}

void InFileData::reset_count()
{
    this->count = 0;
    this->accumulator = 0;
}

int InFileData::get_count()
{
    return this->count;
}

int InFileData::get_element_and_increment()
{
    this->accumulator += 1;
    return (this->accumulator - 1);
}

int InFileData::get_element_count()
{
    return this->number_of_elements;
}



int SPSingleMeasurementParams::get_element_count()
{
   return element_count;
}

/*
template <>
uint32_t SPSingleMeasurementParams::get_element <uint32_t> (const int element_number)
{
    switch(element_number)
    {
        case 0: return fft_length_a;
        case 1: return fft_length_b;
        case 2: return fft_batches_a;
        case 3: return fft_batches_b;
        case 4: return decimation;
        case 5: return num_rx_samples;
        case 6: return num_tx_samples_total;
        case 7: return num_tx_samples_per_batch;
        default:
            {
                std::cerr << "attempted to access a non existing element"
                          << std::endl;
                exit(1);
            }
    }
}
*/

template <>
void SPSingleMeasurementParams::set_element <uint32_t> (const int element_number,
                                                        uint32_t element_value)
{
    switch(element_number)
    {
        case 0: fft_length_a = element_value; break;
        case 1: fft_length_b = element_value; break;
        case 2: fft_batches_a = element_value; break;
        case 3: fft_batches_b = element_value; break;
        case 4: decimation = element_value; break;
        case 5: num_rx_samples = element_value; break;
        case 6: num_tx_samples_total = element_value; break;
        case 7: num_tx_samples_per_batch = element_value; break;
        default:
            {
                std::cerr << "attempted to access a non existing element"
                          << std::endl;
                exit(1);
            }
    }
}

/*
template <>
float SPSingleMeasurementParams::get_element <float> (const int element_number)
{
    switch(element_number)
    {
        case 8: return rx_rot_freq_hz;
        case 9: return tx_freq1_hz;
        case 10: return tx_phase1_rot;
        case 11: return tx_freq2_hz;
        case 12: return tx_phase2_rot;
        case 13: return gain1;
        case 14: return gain2;
        case 15: return gain3;
        default:
            {
                std::cerr << "attempted to access a non existing element"
                          << std::endl;
                exit(1);
            }
    }
}
*/

template <>
void SPSingleMeasurementParams::set_element <float> (const int element_number,
                                                     float element_value)
{
    switch(element_number)
    {
        case 8: rx_rot_freq_hz = element_value; break;
        case 9: tx_freq1_hz = element_value; break;
        case 10: tx_phase1_rot = element_value; break;
        case 11: tx_freq2_hz = element_value; break;
        case 12: tx_phase2_rot = element_value; break;
        case 13: gain1 = element_value; break;
        case 14: gain2 = element_value; break;
        case 15: gain3 = element_value; break;
        default:
            {
                std::cerr << "attempted to access a non existing element"
                          << std::endl;
                exit(1);
            }
    }
}

/*
template <>
bool SPSingleMeasurementParams::get_element <bool> (const int element_number)
{
    switch(element_number)
    {
        case 16: return save_iq;
        case 17: return fft_a_enable;
        case 18: return fft_b_enable;
        case 19: return parameter_estimate_enable;
        case 20: return awgn_enable;
        case 21: return notch_enable;
        default:
            {
                std::cerr << "attempted to access a non existing element"
                          << std::endl;
                exit(1);
            }
    }
}
*/

template <>
void SPSingleMeasurementParams::set_element <bool> (const int element_number,
                                                    bool element_value)
{
    switch(element_number)
    {
        case 16: save_iq = element_value; break;
        case 17: fft_a_enable = element_value; break;
        case 18: fft_b_enable = element_value; break;
        case 19: parameter_estimate_enable = element_value; break;
        case 20: awgn_enable = element_value; break;
        case 21: notch_enable = element_value; break;
        default:
            {
                std::cerr << "attempted to access a non existing element"
                          << std::endl;
                exit(1);
            }
    }
}

/*
template <>
std::string SPSingleMeasurementParams::get_element <std::string> (const int element_number)
{
    switch(element_number)
    {
        case 22: return rx_file_base_name;
        case 23: return filename_fft_a;
        case 24: return filename_fft_b;
        case 25: return filename_rx_samples;
        case 26: return tx_file_base_name;
        case 27: return filename_tx_samples;
        default:
            {
                std::cerr << "attempted to access a non existing element"
                          << std::endl;
                exit(1);
            }
    }
}
*/

template <>
void SPSingleMeasurementParams::set_element <std::string> (const int element_number,
                                                           std::string element_value)
{
    switch(element_number)
    {
        case 22: rx_file_base_name = element_value; break;
        case 23: filename_fft_a = element_value; break;
        case 24: filename_fft_b = element_value; break;
        case 25: filename_rx_samples = element_value; break;
        case 26: tx_file_base_name = element_value; break;
        case 27: filename_tx_samples = element_value; break;
        default:
            {
                std::cerr << "attempted to access a non existing element"
                          << std::endl;
                exit(1);
            }
    }
}

/*
template <>
uint64_t SPSingleMeasurementParams::get_element <uint64_t> (const int element_number)
{
    switch(element_number)
    {
        case 28: return next_rx_start_time;
        case 29: return next_tx_start_time;
        default:
            {
                std::cerr << "attempted to access a non existing element"
                          << std::endl;
                exit(1);
            }
    }
}
*/

template <>
void SPSingleMeasurementParams::set_element <uint64_t> (const int element_number,
                                                        uint64_t element_value)
{
    switch(element_number)
    {
        case 28: next_rx_start_time = element_value; break;
        case 29: next_tx_start_time = element_value; break;
        default:
            {
                std::cerr << "attempted to access a non existing element"
                          << std::endl;
                exit(1);
            }
    }
}


/*
template <>
IdlePatterns SPSingleMeasurementParams::get_element <IdlePatterns> (const int element_number)
{
    switch(element_number)
    {
        case 30: return tx_idle_pattern;
        default:
            {
                std::cerr << "attempted to access a non existing element"
                          << std::endl;
                exit(1);
            }
    }
}
*/


template <>
void SPSingleMeasurementParams::set_element <IdlePatterns> (const int element_number,
                                                            IdlePatterns element_value)
{
    switch(element_number)
    {
        case 30: tx_idle_pattern = static_cast<IdlePatterns>(element_value); break;
        default:
            {
                std::cerr << "attempted to access a non existing element"
                          << std::endl;
                exit(1);
            }
    }
}

bool SPSingleMeasurementParams::load_config_file(const std::string filename)
{
   const std::string comment_symbol("#");

   std::string type; std::string name; std::string value;

   InFileData in_file_data;

   if( filename.empty() )
   {
       std::cout << "error , no file name given" << std::endl;
   }

   //declare, initialize, and open all in one
   std::fstream config_file(filename);

   if( config_file.is_open() )
   {

       while(config_file >> type)
       {
           if(!(type.at(0) == comment_symbol.at(0)))
           {
           config_file >> name >> value;
           in_file_data.current_type = type;
           in_file_data.current_name = name;
           in_file_data.current_value = value;
           in_file_data.add_to_list();
           }
           else
           {
               config_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           }
       }
       config_file.close();
   }
   else
   {
       std::cerr << "could not open the config file " << filename << std::endl;
       exit(1);
   }

   //I pass back whether the data is all initialized as I am assuming that you
   //want to initialize it all, i am not telling you if there is a failure
   return this->load_in_file_data(in_file_data);
}

bool SPSingleMeasurementParams::load_in_file_data(InFileData &in_file_data)
{

    std::map<std::string, int> IdlePatternDict;
    for(int i = 0; i < std::extent<decltype(this->IdlePatternStrings)>::value; i++)
    {
        IdlePatternDict.insert(
                        std::pair<std::string, int>
                        (this->IdlePatternStrings[i], i));
    }

    std::string type; std::string name; std::string value;

    while(in_file_data.get_count() < in_file_data.get_element_count())
    {

        in_file_data.next_in_list(type, name, value);
        if(!type.compare("uint32_t"))
        {
            uint32_t temp = std::stoul(value, nullptr, 10);
            this->set_element(in_file_data.get_element_and_increment(),
                                     temp);
            element_count += 1;
        }
        else if(!type.compare("float"))
        {
            float temp = std::atof(value.c_str());
            this->set_element(in_file_data.get_element_and_increment(),
                                     temp);
            element_count += 1;
        }
        else if(!type.compare("bool"))
        {
            int itemp;
            bool btemp;
            itemp = (value == "true") ? true :
                       (value == "false") ? false : -1;
            if(itemp == -1)
            {
                std::cerr << "You have an invalid assignment to the bool type "
                          << "which is " << value << std::endl;
                std::cerr << "Your options are: true or false" << std::endl;
                exit(1);
            }
            else
            {
                btemp = bool(itemp);
            }
            this->set_element(in_file_data.get_element_and_increment(),
                                     btemp);
            element_count += 1;
        }
        else if(!type.compare("std::string"))
        {
            std::string temp = value;
            this->set_element(in_file_data.get_element_and_increment(),
                                     temp);
            element_count += 1;
        }
        else if(!type.compare("uint64_t"))
        {
            uint64_t temp = std::stoull(value, nullptr, 0);
            this->set_element(in_file_data.get_element_and_increment(),
                                     temp);
            element_count += 1;
        }
        else if(!type.compare("IdlePatterns"))
        {
            int enum_val;

            std::map<std::string, int>::iterator
                itter = IdlePatternDict.find(value);

            if( itter != IdlePatternDict.end() ) enum_val = itter->second;

            IdlePatterns iptemp = static_cast<IdlePatterns>(enum_val);
            this->set_element(in_file_data.get_element_and_increment(), iptemp);
            element_count += 1;
        }
        else
            std::cerr << "you have an invalid type in your setting file" << std::endl;
    }

    //For Debug
//    in_file_data.reset_count();
//    for(int i = 0; i < in_file_data.get_element_count(); i++)
//    {
//       in_file_data.next_in_list(type, name, value);
//       std::cout << type << name << value << std::endl;
//    }

    if(element_count == number_of_elements) fully_initialized = true;

    return fully_initialized;
}
