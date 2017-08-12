/* Elastos Coin */

/* This file was written in 2017 by Yuan Xun. */

/* The license for this file has not yet been determined.
   Yuan Xun is hoping that some of these component files
   may be dual-licensed under the GPL and the Unlicense.
   Whereas the GPL is a strong libre license, the
   Unlicense is a weak libre license. This does not have
   to be a permanent arrangement. Mr Yuan would be
   contented if this happened only for the first one or
   two prereleases of Elastos Coin. That way, any useful
   subroutines of a customary nature contained within the
   codebase may be utilized by those who have possible
   disagreements with the GPL. */

/* The text of the Unlicense (without the second
   paragraph, which may not be necessary) is as follows: */

/* This is free and unencumbered software released into
   the public domain. Anyone is free to copy, modify,
   publish, use, compile, sell, or distribute this
   software, either in source code form or as a compiled
   binary, for any purpose, commercial or non-commercial,
   and by any means. In jurisdictions that recognize
   copyright laws, the author or authors of this software
   dedicate any and all copyright interest in the
   software to the public domain. We make this dedication
   for the benefit of the public at large and to the
   detriment of our heirs and successors. We intend this
   dedication to be an overt act of relinquishment in
   perpetuity of all present and future rights to this
   software under copyright law. */

/* The text of the GPL (the second version) is as
   follows: */

/* The text of the GPL (the third version) is as follows: */

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

struct _8684 *analyze_8774(unsigned char *buffer, int length) {

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

struct _6179 *analyze_3746(unsigned char *buffer, int length) {

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

unsigned char *build_2763(unsigned char *address, int address_size, int amount) {

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
