#ifndef ROM_COMMAND_HPP_fork_9_blob
#define ROM_COMMAND_HPP_fork_9_blob

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <gmpxx.h>

using namespace std;
using json = nlohmann::json;

namespace fork_9_blob
{

// ROM functions
typedef enum : int {
    f_empty = 0,
    f_beforeLast,
    f_getGlobalExitRoot,
    f_getSequencerAddr,
    f_getTimestamp,
    f_getTxs,
    f_getTxsLen,
    f_eventLog,
    f_cond,
    f_inverseFpEc,
    f_inverseFnEc,
    f_sqrtFpEc,
    f_sqrtFpEcParity,
    f_xAddPointEc,
    f_yAddPointEc,
    f_xDblPointEc,
    f_yDblPointEc,
    f_bitwise_and,
    f_bitwise_or,
    f_bitwise_xor,
    f_bitwise_not,
    f_comp_lt,
    f_comp_gt,
    f_comp_eq,
    f_loadScalar,
    f_log,
    f_exp,
    f_storeLog,
    f_memAlignWR_W0,
    f_memAlignWR_W1,
    f_memAlignWR8_W0,
    f_onOpcode,
    f_onUpdateStorage,
    f_getL1InfoRoot,
    f_getL1InfoGER,
    f_getL1InfoBlockHash,
    f_getL1InfoTimestamp,
    f_getTimestampLimit,
    f_getForcedBlockHashL1,
    f_getSmtProof,
    f_MPdiv,
    f_MPdiv_short,
    f_receiveLenQuotient_short,
    f_receiveQuotientChunk_short,
    f_receiveRemainderChunk_short,
    f_receiveLenRemainder,
    f_receiveRemainderChunk,
    f_receiveLenQuotient,
    f_receiveQuotientChunk,
    f_receiveLen,
    f_ARITH_BN254_ADDFP2,
    f_ARITH_BN254_SUBFP2,
    f_ARITH_BN254_MULFP2_X,
    f_ARITH_BN254_MULFP2_Y,
    f_fp2InvBN254_x,
    f_fp2InvBN254_y,
    f_fpBN254inv,
    f_getBatchHashData,
    f_getType,
    f_getForcedGER,
    f_getForcedTimestamp,
    f_getL1HistoricRoot,
    f_getPendingRID,
    f_getZkGasLimit,
    f_getZ,
    f_getY,
    f_getBlobL2HashData,
    f_getForcedHashData,
    f_getBlobLen,
    f_frBLS12_381inv,
    f_dump,
    f_check4096Root,
    f_get4096RootIndex,
} tFunction;

// ROM command (op)
typedef enum : int {
    op_empty = 0,
    op_number,
    op_declareVar,
    op_setVar,
    op_getVar,
    op_getReg,
    op_functionCall,
    op_add,
    op_sub,
    op_neg,
    op_mul,
    op_div,
    op_mod,
    op_or,
    op_and,
    op_gt,
    op_ge,
    op_lt,
    op_le,
    op_eq,
    op_ne,
    op_not,
    op_bitand,
    op_bitor,
    op_bitxor,
    op_bitnot,
    op_shl,
    op_shr,
    op_if,
    op_getMemValue
} tOp;

// Register (reg)
typedef enum : int {
    reg_empty = 0,
    reg_A,
    reg_B,
    reg_C,
    reg_D,
    reg_E,
    reg_SR,
    reg_CTX,
    reg_SP,
    reg_PC,
    reg_GAS,
    reg_zkPC,
    reg_RR,
    reg_CNT_ARITH,
    reg_CNT_BINARY,
    reg_CNT_KECCAK_F,
    reg_CNT_MEM_ALIGN,
    reg_CNT_PADDING_PG,
    reg_CNT_POSEIDON_G,
    reg_STEP,
    reg_HASHPOS,
    reg_RCX,
    reg_RID
} tReg;

// Contains a ROM command data, and arrays possibly containing other ROM commands data
class RomCommand {
public:
    bool isPresent; // presence flag
    tOp op; // command
    string varName; // variable name
    tReg reg; // register
    tFunction function; // function 
    mpz_class num; //number
    vector<RomCommand *> values;
    vector<RomCommand *> params;
    uint64_t offset;
    string opAndFunction;
    uint64_t useCTX;
    RomCommand() : isPresent(false), op(op_empty), reg(reg_empty), function(f_empty), num(0), offset(0), useCTX(0) {};
    string toString(void) const;
};

// Functions for conversion from ROM function/op to string and viceversa
tFunction string2Function(string s);
tOp string2Op(string s);
string function2String(tFunction f);
string op2String(tOp op);
tReg string2reg(string s);
string reg2string(tReg reg);

// Functions to parse/free a ROM command, or an array of them
void parseRomCommandArray (vector<RomCommand *> &values, json tag);
void parseRomCommand      (RomCommand &cmd, json tag);
void freeRomCommandArray  (vector<RomCommand *> &array);
void freeRomCommand       (RomCommand &cmd);

} // namespace

#endif