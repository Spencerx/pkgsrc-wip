# $NetBSD$

BUILDLINK_TREE+=	cpptrace

.if !defined(CPPTRACE_BUILDLINK3_MK)
CPPTRACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cpptrace+=	cpptrace>=1.0.4
BUILDLINK_PKGSRCDIR.cpptrace?=		../../wip/cpptrace

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/libdwarf/buildlink3.mk"

.endif	# CPPTRACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cpptrace
