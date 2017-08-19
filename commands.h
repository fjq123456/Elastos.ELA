struct command_getinfo {
   unsigned int tag;
};

struct command_getwork {
   unsigned int tag;
};

struct command_submitblock {
   unsigned int tag;
   unsigned char *block;
};
