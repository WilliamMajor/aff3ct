#ifndef CODEC_TURBO_PRODUCT_HPP_
#define CODEC_TURBO_PRODUCT_HPP_

#include <vector>
#include <fstream>

#include "Module/Encoder/BCH/Encoder_BCH.hpp"
#include "Module/Decoder/BCH/Decoder_BCH.hpp"
#include "Module/Decoder/Decoder_SISO_SIHO.hpp"
#include "Module/Decoder/Turbo_product/Chase_pyndiah/Decoder_chase_pyndiah.hpp"
#include "Module/Decoder/Turbo_product/Chase_pyndiah/Decoder_chase_pyndiah_fast.hpp"

#include "Factory/Module/Encoder/Turbo_product/Encoder_turbo_product.hpp"
#include "Factory/Module/Decoder/Turbo_product/Decoder_turbo_product.hpp"

#include "../Codec_SISO_SIHO.hpp"

namespace aff3ct
{
namespace module
{
template <typename B = int, typename Q = float>
class Codec_turbo_product : public Codec_SISO_SIHO<B,Q>
{
protected:
	const tools::BCH_polynomial_generator<B> GF_poly;
	Encoder_BCH<B  >* enc_bch_rows;
	Encoder_BCH<B  >* enc_bch_cols;
	Decoder_BCH<B,Q>* dec_bch_rows;
	Decoder_BCH<B,Q>* dec_bch_cols;
	Decoder_chase_pyndiah<B,Q>* cp_rows;
	Decoder_chase_pyndiah<B,Q>* cp_cols;

public:
	Codec_turbo_product(const factory::Encoder_turbo_product::parameters &enc_params,
	                    const factory::Decoder_turbo_product::parameters &dec_params);
	virtual ~Codec_turbo_product();
};
}
}

#endif /* CODEC_TURBO_PRODUCT_HPP_ */