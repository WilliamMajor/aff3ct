#ifndef FACTORY_ENCODER_RA_HPP
#define FACTORY_ENCODER_RA_HPP

#include <string>

#include "Module/Encoder/Encoder.hpp"
#include "Module/Interleaver/Interleaver.hpp"

#include "Factory/Module/Interleaver/Interleaver.hpp"

#include "../Encoder.hpp"

namespace aff3ct
{
namespace factory
{
struct Encoder_RA : public Encoder
{
	static const std::string name;
	static const std::string prefix;

	struct parameters : Encoder::parameters
	{
		virtual ~parameters() {}

		template <typename B = int>
		module::Encoder<B>* build(const module::Interleaver<B> &itl) const;

		Interleaver::parameters itl;
	};

	template <typename B = int>
	static module::Encoder<B>* build(const parameters& params, const module::Interleaver<B> &itl);

	static void build_args(arg_map &req_args, arg_map &opt_args, const std::string p = prefix);
	static void store_args(const arg_val_map &vals, parameters &params, const std::string p = prefix);
	static void make_header(params_list& head_enc, params_list& head_itl, const parameters& params, const bool full = true);
};
}
}

#endif /* FACTORY_ENCODER_RA_HPP */