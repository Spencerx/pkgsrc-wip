# $NetBSD$

BUILDLINK_TREE+=	libassert

.if !defined(LIBASSERT_BUILDLINK3_MK)
LIBASSERT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libassert+=	libassert>=2.2.1
BUILDLINK_PKGSRCDIR.libassert?=		../../wip/libassert

.include "../../wip/cpptrace/buildlink3.mk"

.endif	# LIBASSERT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libassert
