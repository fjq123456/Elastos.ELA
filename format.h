/*

   BLOCK := HEAD, TRANSACTION(?)
   HEAD := current(32), nonce, previous(32), target(32), time
   TRANSACTION := size, A, B, INPUT(A), OUTPUT(B)
   INPUT := size, index, A, public(A), B, signature(B), transaction(32)
   OUTPUT := size, A, address(A), amount(8)

*/

unsigned char *jump_4363(unsigned char *cursor, unsigned char *limit) {

   unsigned int *_9458;

   _9458 = (unsigned int *) cursor;
   cursor += *_9458;

   return (cursor < limit ? cursor : 0);
}

/****************************/
/* [1] Essential Structures */
/****************************/

struct _8192 {

   uint8_t *current;
   uint32_t nonce;
   uint8_t *previous;
   uint8_t *target;
   uint32_t time;
};

struct _4226 {

   uint32_t index;
   uint8_t *public;
   uint8_t *signature;
   uint8_t *transaction;
};

struct _6106 {

   uint8_t *address;
   uint64_t amount;
};

/* The data structures below are going to be retired. */

struct _2458 {

   void *current;
   void *nonce;
   void *previous;
   void *target;
   void *time;
};

struct _5124 {

   void *inputs;
   void *outputs;
};

struct _6179 {

   void *index;
   void *public;
   void *public_size;
   void *signature;
   void *signature_size;
   void *transaction;
};

struct _8684 {

   void *address;
   void *address_size;
   void *amount;
};

/***********************************************/
/* [2] Conversion from Arguments to Structures */
/***********************************************/

struct _2458 *convert_4338(unsigned char *current, unsigned int nonce, unsigned char *previous, unsigned char *target, unsigned int time) {

   struct _2458 *_1506;

   _1506 = malloc(sizeof (struct _2458));

   _1506->current = malloc(32);
   _1506->previous = malloc(32);
   _1506->target = malloc(32);

   memcpy(_1506->current, current, 32);
   memcpy(_1506->previous, previous, 32);
   memcpy(_1506->target, target, 32);

   _1506->nonce = (void *) nonce;
   _1506->time = (void *) time;

   return _1506;
}

struct _6179 *convert_0849(unsigned int index, unsigned int public_size, unsigned char *public, unsigned int signature_size, unsigned char *signature, unsigned char *transaction) {

   
}

struct _8684 *convert_4724(unsigned char *address, unsigned int address_size, unsigned int amount) {

   
}

/*********************************************/
/* [3] Conversion from Structures to Buffers */
/*********************************************/

unsigned char *convert_8843(struct _2458 *subject, int *length) {

}

unsigned char *convert_8920(struct _6179 *subject, int *length) {

}

unsigned char *convert_8008(struct _8684 *subject, int *length) {

}

/********************************************/
/* [4] Conversion from Arguments to Buffers */
/********************************************/

unsigned char *convert_1325(unsigned char *current, unsigned int nonce, unsigned char *previous, unsigned char *target, unsigned int time) {

   unsigned char *buffer;
   unsigned int _8664, *_5477;

   buffer = malloc(_8664 = 32 + 4 + 32 + 32 + 4);
   memcpy(buffer, current, 32);
   memcpy(buffer + 36, previous, 32);
   memcpy(buffer + 68, target, 32);

   _5477 = (unsigned int *) buffer + 32;
   *_5477 = nonce;
   _5477 = (unsigned int *) buffer + 100;
   *_5477 = time;

   return buffer;
}

unsigned char *convert_7486(unsigned int index, unsigned int _1922, unsigned char *public, unsigned int _0108, unsigned char *signature, unsigned char *transaction) {

   unsigned char *buffer;
   unsigned int _8029, *_4945;

   buffer = malloc(_8029 = 4 + 4 + 4 + _1922 + 4 + _0108 + 32);
   memcpy(buffer + 12, public, _1922);
   memcpy(buffer + 16 + _1922, signature, _0108);
   memcpy(buffer + 16 + _1922 + _0108, transaction, 32);

   _4945 = (unsigned int *) buffer;
   *_4945 = _8029;
   _4945 = (unsigned int *) buffer + 4;
   *_4945 = index;
   _4945 = (unsigned int *) buffer + 8;
   *_4945 = _1922;
   _4945 = (unsigned int *) buffer + 12 + _1922;
   *_4945 = _0108;

   return buffer;
}

unsigned char *convert_7210(unsigned int _2124, unsigned char *address, uint64_t amount) {

   unsigned char *buffer;
   unsigned int _7930, *_6650;

   buffer = malloc(_7930 = 4 + 4 + _2124 + 8);
   memcpy(buffer + 8, address, _2124);
   memcpy(buffer + 8 + _2124, &amount, 8);

   _6650 = (unsigned int *) buffer;
   *_6650 = _7930;
   _6650 = (unsigned int *) buffer + 4;
   *_6650 = _2124;

   return buffer;
}

/*********************************************/
/* [5] Conversion from Buffers to Structures */
/*********************************************/

struct _8192 *convert_0902(unsigned char *buffer, unsigned int limit) {

   struct _8192 *object;
   unsigned int *_4215;

   object = malloc(sizeof (struct _8192));

   _4215 = (unsigned int *) buffer + 4;
   object->nonce = *_4215;
   _4215 = (unsigned int *) buffer + 100;
   object->time = *_4215;

   object->current = malloc(32);
   object->previous = malloc(32);
   object->target = malloc(32);

   memcpy(object->current, buffer, 32);
   memcpy(object->previous, buffer + 36, 32);
   memcpy(object->target, buffer + 68, 32);

   return object;
}

struct _4226 *convert_2245(unsigned char *buffer, unsigned int limit) {

   struct _4226 *object;
   unsigned int _0308, _8439, *_8998;

   object = malloc(sizeof (struct _4226));

   _8998 = (unsigned int *) buffer + 4;
   object->index = *_8998;
   _8998 = (unsigned int *) buffer + 8;   
   _0308 = *_8998;
   _8998 = (unsigned int *) buffer + 12 + _0308;
   _8439 = *_8998;

   object->public = malloc(_0308 + 4) + 4;
   object->signature = malloc(_8439 + 4) + 4;
   object->transaction = malloc(32);

   memcpy(object->public, buffer + 12, _0308);
   memcpy(object->signature, buffer + 16 + _0308, _8439);
   memcpy(object->transaction, buffer + 16 + _0308 + _8439, 32);

   _8998 = (unsigned int *) object->public - 4;
   *_8998 = _0308;
   _8998 = (unsigned int *) object->signature - 4;
   *_8998 = _8439;

   return object;
}

struct _6106 *convert_1386(unsigned char *buffer, unsigned int limit) {

   struct _6106 *object;
   unsigned int _1622, *_5667;

   object = malloc(sizeof (struct _6106));

   _5667 = (unsigned int *) buffer + 4;
   _1622 = *_5667;

   object->address = malloc(_1622 + 4) + 4;

   memcpy(object->address, buffer + 8, _1622);
   memcpy(&object->amount, buffer + 8 + _1622, 8);

   _5667 = (unsigned int *) object->address - 4;
   *_5667 = _1622;

   return object;
}

/*********************/
/* [6] Miscellaneous */
/*********************/

/* This function likely has errors. It is not being maintained. */

struct _5124 *analyze_9388(unsigned char *buffer, int length) {

   int *_9874, count;
   struct _5124 *goal;
   unsigned char *_7168, *_7583;

   goal = malloc(sizeof (struct _5124));
   goal->inputs = 0;
   goal->outputs = 0;

   _9874 = (int *) buffer + 4;
   count = *_9874;
   _7168 = buffer + 8;

   while (_7168 < buffer + length && count--) {

      _9874 = (int *) _7168;
      _7583 = malloc(*_9874);
      memcpy(_7583, _7168, *_9874);
      _7168 += *_9874;
   }

   while (_7168 < buffer + length) {

      _9874 = (int *) _7168;
      _7583 = malloc(*_9874);
      memcpy(_7583, _7168, *_9874);
      _7168 += *_9874;
   }

   return goal;
}

unsigned char *build_4059(unsigned char *current, unsigned int nonce, unsigned char *previous, unsigned char *target, unsigned int time) {

   unsigned char *_9471;
   unsigned int *_0368;

   _9471 = malloc(104);

   memcpy(_9471, current, 32);
   memcpy(_9471, previous + 36, 32);
   memcpy(_9471, target + 68, 32);

   _0368 = (unsigned int *) _9471 + 32;
   *_0368 = nonce;
   _0368 = (unsigned int *) _9471 + 100;
   *_0368 = time;

   return _9471;
}

unsigned char *build_6931(int index, unsigned char *public, int public_size, unsigned char *signature, int signature_size, int transaction) {

   int *_2098;
   unsigned char *goal;

   goal = malloc(public_size + signature_size + 20);
   memcpy(goal + 12, public, public_size);
   memcpy(goal + 16 + public_size, signature, signature_size);

   _2098 = (int *) goal;
   *_2098 = public_size + signature_size + 20;

   _2098 = (int *) goal + 4;
   *_2098 = index;

   _2098 = (int *) goal + 8;
   *_2098 = public_size;

   _2098 = (int *) goal + 12 + public_size;
   *_2098 = signature_size;

   _2098 = (int *) goal + 16 + public_size + signature_size;
   *_2098 = transaction;

   return goal;
}

unsigned char *build_2763(unsigned char *address, unsigned int address_size, unsigned int amount) {

   int *_6589;
   unsigned char *goal;

   goal = malloc(address_size + 8);
   memcpy(goal + 4, address, address_size);

   _6589 = (int *) goal;
   *_6589 = address_size + 8;

   _6589 = (int *) goal + address_size + 4;
   *_6589 = amount;

   return goal;
}

struct _2458 *convert_3153(unsigned char *buffer, int length) {

   int *_7636;
   struct _2458 *_1485;

   if (length < 104)
      return 0;

   _1485 = malloc(sizeof (struct _2458));
   _1485->current = malloc(32);
   _1485->previous = malloc(32);
   _1485->target = malloc(32);

   memcpy(_1485->current, buffer, 32);
   memcpy(_1485->previous, buffer + 36, 32);
   memcpy(_1485->target, buffer + 68, 32);

   _7636 = (int *) buffer + 32;
   _1485->nonce = (void *) *_7636;
   _7636 = (int *) buffer + 100;
   _1485->time = (void *) *_7636;

   return _1485;
}

struct _6179 *convert_3746(unsigned char *buffer, int length) {

   int *_6044;
   struct _6179 *goal;

   if (length < 76)
      return 0;

   goal = malloc(sizeof (struct _6179));
   _6044 = (int *) buffer + 4;
   goal->index = (void *) *_6044;
   _6044 = (int *) buffer + 8;
   goal->public_size = (void *) *_6044;
   _6044 = (int *) buffer + 12 + ((int) goal->public_size);
   goal->signature_size = (void *) *_6044;
   _6044 = (int *) buffer + length - 4;
   goal->transaction = (void *) *_6044;

   goal->public = malloc((int) goal->public_size);
   goal->signature = malloc((int) goal->signature_size);

   memcpy(goal->public, buffer + 12, (int) goal->public_size);
   memcpy(goal->signature, buffer + 12 + (int) goal->public_size, (int) goal->signature_size);

   return goal;
}


struct _8684 *convert_8774(unsigned char *buffer, int length) {

   int *_6858;
   struct _8684 *goal;

   if (length < 68)
      return 0;

   goal = malloc(sizeof (struct _8684));
   _6858 = (int *) buffer;
   goal->address_size = (void *) *_6858;
   _6858 = (int *) buffer + length - 4;
   goal->amount = (void *) *_6858;

   goal->address = malloc((int) goal->address_size);
   memcpy(goal->address, buffer + 4, (int) goal->address_size);

   return goal;
}
