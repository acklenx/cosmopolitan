/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2020 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/bits/safemacros.h"
#include "libc/dce.h"
#include "libc/errno.h"
#include "libc/fmt/fmt.h"
#include "libc/macros.h"
#include "libc/nt/enum/formatmessageflags.h"
#include "libc/nt/process.h"
#include "libc/nt/runtime.h"
#include "libc/str/str.h"

STATIC_YOINK("ntoa");
STATIC_YOINK("stoa");

STATIC_YOINK("E2BIG");
STATIC_YOINK("EACCES");
STATIC_YOINK("EADDRINUSE");
STATIC_YOINK("EADDRNOTAVAIL");
STATIC_YOINK("EADV");
STATIC_YOINK("EAFNOSUPPORT");
STATIC_YOINK("EAGAIN");
STATIC_YOINK("EALREADY");
STATIC_YOINK("EBADE");
STATIC_YOINK("EBADF");
STATIC_YOINK("EBADFD");
STATIC_YOINK("EBADMSG");
STATIC_YOINK("EBADR");
STATIC_YOINK("EBADRQC");
STATIC_YOINK("EBADSLT");
STATIC_YOINK("EBFONT");
STATIC_YOINK("EBUSY");
STATIC_YOINK("ECANCELED");
STATIC_YOINK("ECHILD");
STATIC_YOINK("ECHRNG");
STATIC_YOINK("ECOMM");
STATIC_YOINK("ECONNABORTED");
STATIC_YOINK("ECONNREFUSED");
STATIC_YOINK("ECONNRESET");
STATIC_YOINK("EDEADLK");
STATIC_YOINK("EDESTADDRREQ");
STATIC_YOINK("EDOM");
STATIC_YOINK("EDOTDOT");
STATIC_YOINK("EDQUOT");
STATIC_YOINK("EEXIST");
STATIC_YOINK("EFAULT");
STATIC_YOINK("EFBIG");
STATIC_YOINK("EHOSTDOWN");
STATIC_YOINK("EHOSTUNREACH");
STATIC_YOINK("EHWPOISON");
STATIC_YOINK("EIDRM");
STATIC_YOINK("EILSEQ");
STATIC_YOINK("EINPROGRESS");
STATIC_YOINK("EINTR");
STATIC_YOINK("EINVAL");
STATIC_YOINK("EIO");
STATIC_YOINK("EISCONN");
STATIC_YOINK("EISDIR");
STATIC_YOINK("EISNAM");
STATIC_YOINK("EKEYEXPIRED");
STATIC_YOINK("EKEYREJECTED");
STATIC_YOINK("EKEYREVOKED");
STATIC_YOINK("EL2HLT");
STATIC_YOINK("EL2NSYNC");
STATIC_YOINK("EL3HLT");
STATIC_YOINK("EL3RST");
STATIC_YOINK("ELIBACC");
STATIC_YOINK("ELIBBAD");
STATIC_YOINK("ELIBEXEC");
STATIC_YOINK("ELIBMAX");
STATIC_YOINK("ELIBSCN");
STATIC_YOINK("ELNRNG");
STATIC_YOINK("ELOOP");
STATIC_YOINK("EMEDIUMTYPE");
STATIC_YOINK("EMFILE");
STATIC_YOINK("EMLINK");
STATIC_YOINK("EMSGSIZE");
STATIC_YOINK("EMULTIHOP");
STATIC_YOINK("ENAMETOOLONG");
STATIC_YOINK("ENAVAIL");
STATIC_YOINK("ENETDOWN");
STATIC_YOINK("ENETRESET");
STATIC_YOINK("ENETUNREACH");
STATIC_YOINK("ENFILE");
STATIC_YOINK("ENOANO");
STATIC_YOINK("ENOBUFS");
STATIC_YOINK("ENOCSI");
STATIC_YOINK("ENODATA");
STATIC_YOINK("ENODEV");
STATIC_YOINK("ENOENT");
STATIC_YOINK("ENOEXEC");
STATIC_YOINK("ENOKEY");
STATIC_YOINK("ENOLCK");
STATIC_YOINK("ENOLINK");
STATIC_YOINK("ENOMEDIUM");
STATIC_YOINK("ENOMEM");
STATIC_YOINK("ENOMSG");
STATIC_YOINK("ENONET");
STATIC_YOINK("ENOPKG");
STATIC_YOINK("ENOPROTOOPT");
STATIC_YOINK("ENOSPC");
STATIC_YOINK("ENOSR");
STATIC_YOINK("ENOSTR");
STATIC_YOINK("ENOSYS");
STATIC_YOINK("ENOTBLK");
STATIC_YOINK("ENOTCONN");
STATIC_YOINK("ENOTDIR");
STATIC_YOINK("ENOTEMPTY");
STATIC_YOINK("ENOTNAM");
STATIC_YOINK("ENOTRECOVERABLE");
STATIC_YOINK("ENOTSOCK");
STATIC_YOINK("ENOTSUP");
STATIC_YOINK("ENOTTY");
STATIC_YOINK("ENOTUNIQ");
STATIC_YOINK("ENXIO");
STATIC_YOINK("EOPNOTSUPP");
STATIC_YOINK("EOVERFLOW");
STATIC_YOINK("EOWNERDEAD");
STATIC_YOINK("EPERM");
STATIC_YOINK("EPFNOSUPPORT");
STATIC_YOINK("EPIPE");
STATIC_YOINK("EPROTO");
STATIC_YOINK("EPROTONOSUPPORT");
STATIC_YOINK("EPROTOTYPE");
STATIC_YOINK("ERANGE");
STATIC_YOINK("EREMCHG");
STATIC_YOINK("EREMOTE");
STATIC_YOINK("EREMOTEIO");
STATIC_YOINK("ERESTART");
STATIC_YOINK("ERFKILL");
STATIC_YOINK("EROFS");
STATIC_YOINK("ESHUTDOWN");
STATIC_YOINK("ESOCKTNOSUPPORT");
STATIC_YOINK("ESPIPE");
STATIC_YOINK("ESRCH");
STATIC_YOINK("ESRMNT");
STATIC_YOINK("ESTALE");
STATIC_YOINK("ESTRPIPE");
STATIC_YOINK("ETIME");
STATIC_YOINK("ETIMEDOUT");
STATIC_YOINK("ETOOMANYREFS");
STATIC_YOINK("ETXTBSY");
STATIC_YOINK("EUCLEAN");
STATIC_YOINK("EUNATCH");
STATIC_YOINK("EUSERS");
STATIC_YOINK("EXDEV");
STATIC_YOINK("EXFULL");

_Alignas(char) static const char kErrnoNames[] = "\
2BIG\000\
ACCES\000\
ADDRINUSE\000\
ADDRNOTAVAIL\000\
ADV\000\
AFNOSUPPORT\000\
AGAIN\000\
ALREADY\000\
BADE\000\
BADF\000\
BADFD\000\
BADMSG\000\
BADR\000\
BADRQC\000\
BADSLT\000\
BFONT\000\
BUSY\000\
CANCELED\000\
CHILD\000\
CHRNG\000\
COMM\000\
CONNABORTED\000\
CONNREFUSED\000\
CONNRESET\000\
DEADLK\000\
DESTADDRREQ\000\
DOM\000\
DOTDOT\000\
DQUOT\000\
EXIST\000\
FAULT\000\
FBIG\000\
HOSTDOWN\000\
HOSTUNREACH\000\
HWPOISON\000\
IDRM\000\
ILSEQ\000\
INPROGRESS\000\
INTR\000\
INVAL\000\
IO\000\
ISCONN\000\
ISDIR\000\
ISNAM\000\
KEYEXPIRED\000\
KEYREJECTED\000\
KEYREVOKED\000\
L2HLT\000\
L2NSYNC\000\
L3HLT\000\
L3RST\000\
LIBACC\000\
LIBBAD\000\
LIBEXEC\000\
LIBMAX\000\
LIBSCN\000\
LNRNG\000\
LOOP\000\
MEDIUMTYPE\000\
MFILE\000\
MLINK\000\
MSGSIZE\000\
MULTIHOP\000\
NAMETOOLONG\000\
NAVAIL\000\
NETDOWN\000\
NETRESET\000\
NETUNREACH\000\
NFILE\000\
NOANO\000\
NOBUFS\000\
NOCSI\000\
NODATA\000\
NODEV\000\
NOENT\000\
NOEXEC\000\
NOKEY\000\
NOLCK\000\
NOLINK\000\
NOMEDIUM\000\
NOMEM\000\
NOMSG\000\
NONET\000\
NOPKG\000\
NOPROTOOPT\000\
NOSPC\000\
NOSR\000\
NOSTR\000\
NOSYS\000\
NOTBLK\000\
NOTCONN\000\
NOTDIR\000\
NOTEMPTY\000\
NOTNAM\000\
NOTRECOVERABLE\000\
NOTSOCK\000\
NOTSUP\000\
NOTTY\000\
NOTUNIQ\000\
NXIO\000\
OPNOTSUPP\000\
OVERFLOW\000\
OWNERDEAD\000\
PERM\000\
PFNOSUPPORT\000\
PIPE\000\
PROTO\000\
PROTONOSUPPORT\000\
PROTOTYPE\000\
RANGE\000\
REMCHG\000\
REMOTE\000\
REMOTEIO\000\
RESTART\000\
RFKILL\000\
ROFS\000\
SHUTDOWN\000\
SOCKTNOSUPPORT\000\
SPIPE\000\
SRCH\000\
SRMNT\000\
STALE\000\
STRPIPE\000\
TIME\000\
TIMEDOUT\000\
TOOMANYREFS\000\
TXTBSY\000\
UCLEAN\000\
UNATCH\000\
USERS\000\
XDEV\000\
XFULL\000\
\000";

static const char *geterrname(long code) {
  const long *e;
  size_t i, n;
  e = &E2BIG;
  n = &EXFULL + 1 - e;
  for (i = 0; i < n; ++i) {
    if (code == e[i]) {
      return IndexDoubleNulString(kErrnoNames, i);
    }
  }
  return NULL;
}

/**
 * Converts errno value to string.
 * @return 0 on success, or error code
 */
int strerror_r(int err, char *buf, size_t size) {
  const char *s;
  char16_t buf16[100];
  int winstate, sysvstate;
  if (err == -1 || IsTiny()) {
    s = "?";
  } else {
    s = firstnonnull(geterrname(err), "?");
  }
  if (!SupportsWindows()) {
    (snprintf)(buf, size, "E%s[%d]", s, err);
  } else {
    winstate = GetLastError();
    sysvstate = errno;
    if (FormatMessage(
            kNtFormatMessageFromSystem | kNtFormatMessageIgnoreInserts, NULL,
            err, 0, buf16, ARRAYLEN(buf16) - 1, 0) > 0) {
      chomp16(buf16);
    } else {
      buf16[0] = u'\0';
    }
    (snprintf)(buf, size, "E%s/err=%d/errno:%d/GetLastError:%d%s%hs", s, err,
               sysvstate, winstate, buf16[0] ? " " : "", buf16);
  }
  return 0;
}
