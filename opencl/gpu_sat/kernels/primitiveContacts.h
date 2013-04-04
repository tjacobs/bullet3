//this file is autogenerated using stringify.bat (premake --stringify) in the build folder of this project
static const char* primitiveContactsKernelsCL= \
"#define TRIANGLE_NUM_CONVEX_FACES 5\n"
"\n"
"#define SHAPE_CONVEX_HULL 3\n"
"#define SHAPE_PLANE 4\n"
"#define SHAPE_CONCAVE_TRIMESH 5\n"
"#define SHAPE_COMPOUND_OF_CONVEX_HULLS 6\n"
"#define SHAPE_SPHERE 7\n"
"\n"
"\n"
"#pragma OPENCL EXTENSION cl_amd_printf : enable\n"
"#pragma OPENCL EXTENSION cl_khr_local_int32_base_atomics : enable\n"
"#pragma OPENCL EXTENSION cl_khr_global_int32_base_atomics : enable\n"
"#pragma OPENCL EXTENSION cl_khr_local_int32_extended_atomics : enable\n"
"#pragma OPENCL EXTENSION cl_khr_global_int32_extended_atomics : enable\n"
"\n"
"#ifdef cl_ext_atomic_counters_32\n"
"#pragma OPENCL EXTENSION cl_ext_atomic_counters_32 : enable\n"
"#else\n"
"#define counter32_t volatile __global int*\n"
"#endif\n"
"\n"
"#define GET_GROUP_IDX get_group_id(0)\n"
"#define GET_LOCAL_IDX get_local_id(0)\n"
"#define GET_GLOBAL_IDX get_global_id(0)\n"
"#define GET_GROUP_SIZE get_local_size(0)\n"
"#define GET_NUM_GROUPS get_num_groups(0)\n"
"#define GROUP_LDS_BARRIER barrier(CLK_LOCAL_MEM_FENCE)\n"
"#define GROUP_MEM_FENCE mem_fence(CLK_LOCAL_MEM_FENCE)\n"
"#define AtomInc(x) atom_inc(&(x))\n"
"#define AtomInc1(x, out) out = atom_inc(&(x))\n"
"#define AppendInc(x, out) out = atomic_inc(x)\n"
"#define AtomAdd(x, value) atom_add(&(x), value)\n"
"#define AtomCmpxhg(x, cmp, value) atom_cmpxchg( &(x), cmp, value )\n"
"#define AtomXhg(x, value) atom_xchg ( &(x), value )\n"
"\n"
"#define max2 max\n"
"#define min2 min\n"
"\n"
"typedef unsigned int u32;\n"
"\n"
"\n"
"\n"
"typedef struct\n"
"{\n"
"	float4 m_worldPos[4];\n"
"	float4 m_worldNormal;	//	w: m_nPoints\n"
"	u32 m_coeffs;\n"
"	u32 m_batchIdx;\n"
"\n"
"	int m_bodyAPtrAndSignBit;//x:m_bodyAPtr, y:m_bodyBPtr\n"
"	int m_bodyBPtrAndSignBit;\n"
"} Contact4;\n"
"\n"
"\n"
"///keep this in sync with btCollidable.h\n"
"typedef struct\n"
"{\n"
"	int m_numChildShapes;\n"
"	float m_radius;\n"
"	int m_shapeType;\n"
"	int m_shapeIndex;\n"
"	\n"
"} btCollidableGpu;\n"
"\n"
"typedef struct\n"
"{\n"
"	float4	m_childPosition;\n"
"	float4	m_childOrientation;\n"
"	int m_shapeIndex;\n"
"	int m_unused0;\n"
"	int m_unused1;\n"
"	int m_unused2;\n"
"} btGpuChildShape;\n"
"\n"
"#define GET_NPOINTS(x) (x).m_worldNormal.w\n"
"\n"
"typedef struct\n"
"{\n"
"	float4 m_pos;\n"
"	float4 m_quat;\n"
"	float4 m_linVel;\n"
"	float4 m_angVel;\n"
"\n"
"	u32 m_collidableIdx;	\n"
"	float m_invMass;\n"
"	float m_restituitionCoeff;\n"
"	float m_frictionCoeff;\n"
"} BodyData;\n"
"\n"
"\n"
"typedef struct  \n"
"{\n"
"	float4		m_localCenter;\n"
"	float4		m_extents;\n"
"	float4		mC;\n"
"	float4		mE;\n"
"	\n"
"	float			m_radius;\n"
"	int	m_faceOffset;\n"
"	int m_numFaces;\n"
"	int	m_numVertices;\n"
"	\n"
"	int m_vertexOffset;\n"
"	int	m_uniqueEdgesOffset;\n"
"	int	m_numUniqueEdges;\n"
"	int m_unused;\n"
"\n"
"} ConvexPolyhedronCL;\n"
"\n"
"typedef struct\n"
"{\n"
"	float4 m_plane;\n"
"	int m_indexOffset;\n"
"	int m_numIndices;\n"
"} btGpuFace;\n"
"\n"
"#define SELECT_UINT4( b, a, condition ) select( b,a,condition )\n"
"\n"
"#define make_float4 (float4)\n"
"#define make_float2 (float2)\n"
"#define make_uint4 (uint4)\n"
"#define make_int4 (int4)\n"
"#define make_uint2 (uint2)\n"
"#define make_int2 (int2)\n"
"\n"
"\n"
"__inline\n"
"float fastDiv(float numerator, float denominator)\n"
"{\n"
"	return native_divide(numerator, denominator);	\n"
"//	return numerator/denominator;	\n"
"}\n"
"\n"
"__inline\n"
"float4 fastDiv4(float4 numerator, float4 denominator)\n"
"{\n"
"	return native_divide(numerator, denominator);	\n"
"}\n"
"\n"
"\n"
"__inline\n"
"float4 cross3(float4 a, float4 b)\n"
"{\n"
"	return cross(a,b);\n"
"}\n"
"\n"
"//#define dot3F4 dot\n"
"\n"
"__inline\n"
"float dot3F4(float4 a, float4 b)\n"
"{\n"
"	float4 a1 = make_float4(a.xyz,0.f);\n"
"	float4 b1 = make_float4(b.xyz,0.f);\n"
"	return dot(a1, b1);\n"
"}\n"
"\n"
"__inline\n"
"float4 fastNormalize4(float4 v)\n"
"{\n"
"	return fast_normalize(v);\n"
"}\n"
"\n"
"\n"
"///////////////////////////////////////\n"
"//	Quaternion\n"
"///////////////////////////////////////\n"
"\n"
"typedef float4 Quaternion;\n"
"\n"
"__inline\n"
"Quaternion qtMul(Quaternion a, Quaternion b);\n"
"\n"
"__inline\n"
"Quaternion qtNormalize(Quaternion in);\n"
"\n"
"__inline\n"
"float4 qtRotate(Quaternion q, float4 vec);\n"
"\n"
"__inline\n"
"Quaternion qtInvert(Quaternion q);\n"
"\n"
"\n"
"\n"
"\n"
"__inline\n"
"Quaternion qtMul(Quaternion a, Quaternion b)\n"
"{\n"
"	Quaternion ans;\n"
"	ans = cross3( a, b );\n"
"	ans += a.w*b+b.w*a;\n"
"//	ans.w = a.w*b.w - (a.x*b.x+a.y*b.y+a.z*b.z);\n"
"	ans.w = a.w*b.w - dot3F4(a, b);\n"
"	return ans;\n"
"}\n"
"\n"
"__inline\n"
"Quaternion qtNormalize(Quaternion in)\n"
"{\n"
"	return fastNormalize4(in);\n"
"//	in /= length( in );\n"
"//	return in;\n"
"}\n"
"__inline\n"
"float4 qtRotate(Quaternion q, float4 vec)\n"
"{\n"
"	Quaternion qInv = qtInvert( q );\n"
"	float4 vcpy = vec;\n"
"	vcpy.w = 0.f;\n"
"	float4 out = qtMul(qtMul(q,vcpy),qInv);\n"
"	return out;\n"
"}\n"
"\n"
"__inline\n"
"Quaternion qtInvert(Quaternion q)\n"
"{\n"
"	return (Quaternion)(-q.xyz, q.w);\n"
"}\n"
"\n"
"__inline\n"
"float4 qtInvRotate(const Quaternion q, float4 vec)\n"
"{\n"
"	return qtRotate( qtInvert( q ), vec );\n"
"}\n"
"\n"
"__inline\n"
"float4 transform(const float4* p, const float4* translation, const Quaternion* orientation)\n"
"{\n"
"	return qtRotate( *orientation, *p ) + (*translation);\n"
"}\n"
"\n"
"void	trInverse(float4 translationIn, Quaternion orientationIn,\n"
"		float4* translationOut, Quaternion* orientationOut)\n"
"{\n"
"	*orientationOut = qtInvert(orientationIn);\n"
"	*translationOut = qtRotate(*orientationOut, -translationIn);\n"
"}\n"
"\n"
"void	trMul(float4 translationA, Quaternion orientationA,\n"
"						float4 translationB, Quaternion orientationB,\n"
"		float4* translationOut, Quaternion* orientationOut)\n"
"{\n"
"	*orientationOut = qtMul(orientationA,orientationB);\n"
"	*translationOut = transform(&translationB,&translationA,&orientationA);\n"
"}\n"
"\n"
"\n"
"\n"
"__inline\n"
"float4 normalize3(const float4 a)\n"
"{\n"
"	float4 n = make_float4(a.x, a.y, a.z, 0.f);\n"
"	return fastNormalize4( n );\n"
"}\n"
"\n"
"\n"
"__inline float4 lerp3(const float4 a,const float4 b, float  t)\n"
"{\n"
"	return make_float4(	a.x + (b.x - a.x) * t,\n"
"						a.y + (b.y - a.y) * t,\n"
"						a.z + (b.z - a.z) * t,\n"
"						0.f);\n"
"}\n"
"\n"
"\n"
"float signedDistanceFromPointToPlane(float4 point, float4 planeEqn, float4* closestPointOnFace)\n"
"{\n"
"	float4 n = (float4)(planeEqn.x, planeEqn.y, planeEqn.z, 0);\n"
"	float dist = dot3F4(n, point) + planeEqn.w;\n"
"	*closestPointOnFace = point - dist * n;\n"
"	return dist;\n"
"}\n"
"\n"
"\n"
"\n"
"inline bool IsPointInPolygon(float4 p, \n"
"							float4	posConvex,\n"
"							float4	ornConvex,\n"
"							const btGpuFace* face,\n"
"							__global const float4* baseVertex,\n"
"							__global const  int* convexIndices,\n"
"							float4* out)\n"
"{\n"
"    float4 a;\n"
"    float4 b;\n"
"    float4 ab;\n"
"    float4 ap;\n"
"    float4 v;\n"
"\n"
"	float4 plane = make_float4(face->m_plane.x,face->m_plane.y,face->m_plane.z,0.f);\n"
"	\n"
"	if (face->m_numIndices<2)\n"
"		return false;\n"
"\n"
"	\n"
"	float4 v0 = baseVertex[convexIndices[face->m_indexOffset + face->m_numIndices-1]];\n"
"	float4 worldV0 = transform(&v0, &posConvex, &ornConvex);\n"
"	\n"
"	b = worldV0;\n"
"\n"
"    for(unsigned i=0; i != face->m_numIndices; ++i)\n"
"    {\n"
"		a = b;\n"
"		float4 vi = baseVertex[convexIndices[face->m_indexOffset + i]];\n"
"		float4 worldVi = transform(&vi, &posConvex, &ornConvex);\n"
"		b = worldVi;\n"
"        ab = b-a;\n"
"        ap = p-a;\n"
"        v = cross3(ab,plane);\n"
"\n"
"        if (dot(ap, v) > 0.f)\n"
"        {\n"
"            float ab_m2 = dot(ab, ab);\n"
"            float rt = ab_m2 != 0.f ? dot(ab, ap) / ab_m2 : 0.f;\n"
"            if (rt <= 0.f)\n"
"            {\n"
"                *out = a;\n"
"            }\n"
"            else if (rt >= 1.f) \n"
"            {\n"
"                *out = b;\n"
"            }\n"
"            else\n"
"            {\n"
"            	float s = 1.f - rt;\n"
"							out[0].x = s * a.x + rt * b.x;\n"
"							out[0].y = s * a.y + rt * b.y;\n"
"							out[0].z = s * a.z + rt * b.z;\n"
"            }\n"
"            return false;\n"
"        }\n"
"    }\n"
"    return true;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"void	computeContactSphereConvex(int pairIndex,\n"
"																int bodyIndexA, int bodyIndexB, \n"
"																int collidableIndexA, int collidableIndexB, \n"
"																__global const BodyData* rigidBodies, \n"
"																__global const btCollidableGpu* collidables,\n"
"																__global const ConvexPolyhedronCL* convexShapes,\n"
"																__global const float4* convexVertices,\n"
"																__global const int* convexIndices,\n"
"																__global const btGpuFace* faces,\n"
"																__global Contact4* restrict globalContactsOut,\n"
"																counter32_t nGlobalContactsOut,\n"
"																int numPairs)\n"
"{\n"
"\n"
"	float radius = collidables[collidableIndexA].m_radius;\n"
"	float4 spherePos1 = rigidBodies[bodyIndexA].m_pos;\n"
"	float4 sphereOrn = rigidBodies[bodyIndexA].m_quat;\n"
"\n"
"\n"
"\n"
"	float4 pos = rigidBodies[bodyIndexB].m_pos;\n"
"	float4 quat = rigidBodies[bodyIndexB].m_quat;\n"
"\n"
"	float4 spherePos = spherePos1 - pos;\n"
"\n"
"	int collidableIndex = rigidBodies[bodyIndexB].m_collidableIdx;\n"
"	int shapeIndex = collidables[collidableIndex].m_shapeIndex;\n"
"	int numFaces = convexShapes[shapeIndex].m_numFaces;\n"
"	float4 closestPnt = (float4)(0, 0, 0, 0);\n"
"	float4 hitNormalWorld = (float4)(0, 0, 0, 0);\n"
"	float minDist = -1000000.f;\n"
"	bool bCollide = true;\n"
"\n"
"	for ( int f = 0; f < numFaces; f++ )\n"
"	{\n"
"		btGpuFace face = faces[convexShapes[shapeIndex].m_faceOffset+f];\n"
"\n"
"		// set up a plane equation \n"
"		float4 planeEqn;\n"
"		float4 n1 = qtRotate(quat, (float4)(face.m_plane.xyz, 0));\n"
"		planeEqn = n1;\n"
"		planeEqn.w = face.m_plane.w;\n"
"		\n"
"	\n"
"		// compute a signed distance from the vertex in cloth to the face of rigidbody.\n"
"		float4 pntReturn;\n"
"		float dist = signedDistanceFromPointToPlane(spherePos, planeEqn, &pntReturn);\n"
"\n"
"		// If the distance is positive, the plane is a separating plane. \n"
"		if ( dist > radius )\n"
"		{\n"
"			bCollide = false;\n"
"			break;\n"
"		}\n"
"\n"
"\n"
"		if (dist>0)\n"
"		{\n"
"			//might hit an edge or vertex\n"
"			float4 out;\n"
"			bool isInPoly = IsPointInPolygon(spherePos,\n"
"					pos,\n"
"					quat,\n"
"					&face,\n"
"					&convexVertices[convexShapes[shapeIndex].m_vertexOffset],\n"
"					convexIndices,\n"
"           &out);\n"
"			if (isInPoly)\n"
"			{\n"
"				if (dist>minDist)\n"
"				{\n"
"					minDist = dist;\n"
"					closestPnt = pntReturn;\n"
"					hitNormalWorld = planeEqn;\n"
"					\n"
"				}\n"
"			} else\n"
"			{\n"
"				float4 tmp = spherePos-out;\n"
"				float l2 = dot(tmp,tmp);\n"
"				if (l2<radius*radius)\n"
"				{\n"
"					dist  = sqrt(l2);\n"
"					if (dist>minDist)\n"
"					{\n"
"						minDist = dist;\n"
"						closestPnt = out;\n"
"						hitNormalWorld = tmp/dist;\n"
"						\n"
"					}\n"
"					\n"
"				} else\n"
"				{\n"
"					bCollide = false;\n"
"					break;\n"
"				}\n"
"			}\n"
"		} else\n"
"		{\n"
"			if ( dist > minDist )\n"
"			{\n"
"				minDist = dist;\n"
"				closestPnt = pntReturn;\n"
"				hitNormalWorld.xyz = planeEqn.xyz;\n"
"			}\n"
"		}\n"
"		\n"
"	}\n"
"\n"
"	\n"
"\n"
"	if (bCollide)\n"
"	{\n"
"		float4 normalOnSurfaceB1 = -hitNormalWorld;\n"
"		float4 pOnB1 = closestPnt+pos;\n"
"		float actualDepth = minDist-radius;\n"
"		pOnB1.w = actualDepth;\n"
"\n"
"		int dstIdx;\n"
"    AppendInc( nGlobalContactsOut, dstIdx );\n"
"		\n"
"		if (dstIdx < numPairs)\n"
"		{\n"
"			__global Contact4* c = &globalContactsOut[dstIdx];\n"
"			c->m_worldNormal = normalOnSurfaceB1;\n"
"			c->m_coeffs = (u32)(0.f*0xffff) | ((u32)(0.7f*0xffff)<<16);\n"
"			c->m_batchIdx = pairIndex;\n"
"			c->m_bodyAPtrAndSignBit = rigidBodies[bodyIndexA].m_invMass==0?-bodyIndexA:bodyIndexA;\n"
"			c->m_bodyBPtrAndSignBit = rigidBodies[bodyIndexB].m_invMass==0?-bodyIndexB:bodyIndexB;\n"
"			c->m_worldPos[0] = pOnB1;\n"
"			GET_NPOINTS(*c) = 1;\n"
"		}//if (dstIdx < numPairs)\n"
"	}//if (hasCollision)\n"
"\n"
"}\n"
"							\n"
"\n"
"									\n"
"void	computeContactPlaneConvex(int pairIndex,\n"
"																int bodyIndexA, int bodyIndexB, \n"
"																int collidableIndexA, int collidableIndexB, \n"
"																__global const BodyData* rigidBodies, \n"
"																__global const btCollidableGpu* collidables,\n"
"																__global const btGpuFace* faces,\n"
"																__global Contact4* restrict globalContactsOut,\n"
"																counter32_t nGlobalContactsOut,\n"
"																int numPairs)\n"
"{\n"
"	float4 planeEq = faces[collidables[collidableIndexA].m_shapeIndex].m_plane;\n"
"	float radius = collidables[collidableIndexB].m_radius;\n"
"	float4 posA1 = rigidBodies[bodyIndexA].m_pos;\n"
"	float4 ornA1 = rigidBodies[bodyIndexA].m_quat;\n"
"	float4 posB1 = rigidBodies[bodyIndexB].m_pos;\n"
"	float4 ornB1 = rigidBodies[bodyIndexB].m_quat;\n"
"	\n"
"	bool hasCollision = false;\n"
"	float4 planeNormal1 = make_float4(planeEq.x,planeEq.y,planeEq.z,0.f);\n"
"	float planeConstant = planeEq.w;\n"
"	float4 convexInPlaneTransPos1; Quaternion convexInPlaneTransOrn1;\n"
"	{\n"
"		float4 invPosA;Quaternion invOrnA;\n"
"		trInverse(posA1,ornA1,&invPosA,&invOrnA);\n"
"		trMul(invPosA,invOrnA,posB1,ornB1,&convexInPlaneTransPos1,&convexInPlaneTransOrn1);\n"
"	}\n"
"	float4 planeInConvexPos1;	Quaternion planeInConvexOrn1;\n"
"	{\n"
"		float4 invPosB;Quaternion invOrnB;\n"
"		trInverse(posB1,ornB1,&invPosB,&invOrnB);\n"
"		trMul(invPosB,invOrnB,posA1,ornA1,&planeInConvexPos1,&planeInConvexOrn1);	\n"
"	}\n"
"	float4 vtx1 = qtRotate(planeInConvexOrn1,-planeNormal1)*radius;\n"
"	float4 vtxInPlane1 = transform(&vtx1,&convexInPlaneTransPos1,&convexInPlaneTransOrn1);\n"
"	float distance = dot3F4(planeNormal1,vtxInPlane1) - planeConstant;\n"
"	hasCollision = distance < 0.f;//m_manifoldPtr->getContactBreakingThreshold();\n"
"	if (hasCollision)\n"
"	{\n"
"		float4 vtxInPlaneProjected1 = vtxInPlane1 -   distance*planeNormal1;\n"
"		float4 vtxInPlaneWorld1 = transform(&vtxInPlaneProjected1,&posA1,&ornA1);\n"
"		float4 normalOnSurfaceB1 = qtRotate(ornA1,planeNormal1);\n"
"		float4 pOnB1 = vtxInPlaneWorld1+normalOnSurfaceB1*distance;\n"
"		pOnB1.w = distance;\n"
"\n"
"		int dstIdx;\n"
"    AppendInc( nGlobalContactsOut, dstIdx );\n"
"		\n"
"		if (dstIdx < numPairs)\n"
"		{\n"
"			__global Contact4* c = &globalContactsOut[dstIdx];\n"
"			c->m_worldNormal = normalOnSurfaceB1;\n"
"			c->m_coeffs = (u32)(0.f*0xffff) | ((u32)(0.7f*0xffff)<<16);\n"
"			c->m_batchIdx = pairIndex;\n"
"			c->m_bodyAPtrAndSignBit = rigidBodies[bodyIndexA].m_invMass==0?-bodyIndexA:bodyIndexA;\n"
"			c->m_bodyBPtrAndSignBit = rigidBodies[bodyIndexB].m_invMass==0?-bodyIndexB:bodyIndexB;\n"
"			c->m_worldPos[0] = pOnB1;\n"
"			GET_NPOINTS(*c) = 1;\n"
"		}//if (dstIdx < numPairs)\n"
"	}//if (hasCollision)\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"__kernel void   primitiveContactsKernel( __global const int2* pairs, \n"
"																					__global const BodyData* rigidBodies, \n"
"																					__global const btCollidableGpu* collidables,\n"
"																					__global const ConvexPolyhedronCL* convexShapes, \n"
"																					__global const float4* vertices,\n"
"																					__global const float4* uniqueEdges,\n"
"																					__global const btGpuFace* faces,\n"
"																					__global const int* indices,\n"
"																					__global Contact4* restrict globalContactsOut,\n"
"																					counter32_t nGlobalContactsOut,\n"
"																					int numPairs)\n"
"{\n"
"\n"
"	int i = get_global_id(0);\n"
"	int pairIndex = i;\n"
"	\n"
"	float4 worldVertsB1[64];\n"
"	float4 worldVertsB2[64];\n"
"	int capacityWorldVerts = 64;	\n"
"\n"
"	float4 localContactsOut[64];\n"
"	int localContactCapacity=64;\n"
"	\n"
"	float minDist = -1e30f;\n"
"	float maxDist = 0.02f;\n"
"\n"
"	if (i<numPairs)\n"
"	{\n"
"\n"
"		int bodyIndexA = pairs[i].x;\n"
"		int bodyIndexB = pairs[i].y;\n"
"			\n"
"		int collidableIndexA = rigidBodies[bodyIndexA].m_collidableIdx;\n"
"		int collidableIndexB = rigidBodies[bodyIndexB].m_collidableIdx;\n"
"	\n"
"\n"
"		if (collidables[collidableIndexA].m_shapeType == SHAPE_SPHERE &&\n"
"			collidables[collidableIndexB].m_shapeType == SHAPE_PLANE)\n"
"		{\n"
"\n"
"\n"
"			computeContactPlaneConvex( pairIndex, bodyIndexB,bodyIndexA,  collidableIndexB,collidableIndexA, \n"
"																rigidBodies,collidables,faces,	globalContactsOut, nGlobalContactsOut,numPairs);\n"
"			return;\n"
"		}\n"
"\n"
"		if (collidables[collidableIndexA].m_shapeType == SHAPE_PLANE &&\n"
"			collidables[collidableIndexB].m_shapeType == SHAPE_SPHERE)\n"
"		{\n"
"\n"
"\n"
"			computeContactPlaneConvex(pairIndex, bodyIndexA, bodyIndexB, collidableIndexA, collidableIndexB, \n"
"																rigidBodies,collidables,faces, globalContactsOut, nGlobalContactsOut,numPairs);\n"
"			return;\n"
"			\n"
"		}\n"
"	\n"
"		if (collidables[collidableIndexA].m_shapeType == SHAPE_SPHERE &&\n"
"			collidables[collidableIndexB].m_shapeType == SHAPE_CONVEX_HULL)\n"
"		{\n"
"		\n"
"			computeContactSphereConvex(pairIndex, bodyIndexA, bodyIndexB, collidableIndexA, collidableIndexB, \n"
"																rigidBodies,collidables,convexShapes,vertices,indices,faces, globalContactsOut, nGlobalContactsOut,numPairs);\n"
"			return;\n"
"		}\n"
"\n"
"		if (collidables[collidableIndexA].m_shapeType == SHAPE_CONVEX_HULL &&\n"
"			collidables[collidableIndexB].m_shapeType == SHAPE_SPHERE)\n"
"		{\n"
"		\n"
"			computeContactSphereConvex(pairIndex, bodyIndexB, bodyIndexA, collidableIndexB, collidableIndexA, \n"
"																rigidBodies,collidables,convexShapes,vertices,indices,faces, globalContactsOut, nGlobalContactsOut,numPairs);\n"
"			return;\n"
"		}\n"
"	\n"
"	\n"
"	\n"
"	\n"
"	\n"
"		if (collidables[collidableIndexA].m_shapeType == SHAPE_SPHERE &&\n"
"			collidables[collidableIndexB].m_shapeType == SHAPE_SPHERE)\n"
"		{\n"
"			//sphere-sphere\n"
"			float radiusA = collidables[collidableIndexA].m_radius;\n"
"			float radiusB = collidables[collidableIndexB].m_radius;\n"
"			float4 posA = rigidBodies[bodyIndexA].m_pos;\n"
"			float4 posB = rigidBodies[bodyIndexB].m_pos;\n"
"\n"
"			float4 diff = posA-posB;\n"
"			float len = length(diff);\n"
"			\n"
"			///iff distance positive, don't generate a new contact\n"
"			if ( len <= (radiusA+radiusB))\n"
"			{\n"
"				///distance (negative means penetration)\n"
"				float dist = len - (radiusA+radiusB);\n"
"				float4 normalOnSurfaceB = make_float4(1.f,0.f,0.f,0.f);\n"
"				if (len > 0.00001)\n"
"				{\n"
"					normalOnSurfaceB = diff / len;\n"
"				}\n"
"				float4 contactPosB = posB + normalOnSurfaceB*radiusB;\n"
"				contactPosB.w = dist;\n"
"								\n"
"				int dstIdx;\n"
"        AppendInc( nGlobalContactsOut, dstIdx );\n"
"				\n"
"				if (dstIdx < numPairs)\n"
"				{\n"
"					__global Contact4* c = &globalContactsOut[dstIdx];\n"
"					c->m_worldNormal = -normalOnSurfaceB;\n"
"					c->m_coeffs = (u32)(0.f*0xffff) | ((u32)(0.7f*0xffff)<<16);\n"
"					c->m_batchIdx = pairIndex;\n"
"					int bodyA = pairs[pairIndex].x;\n"
"					int bodyB = pairs[pairIndex].y;\n"
"					c->m_bodyAPtrAndSignBit = rigidBodies[bodyA].m_invMass==0?-bodyA:bodyA;\n"
"					c->m_bodyBPtrAndSignBit = rigidBodies[bodyB].m_invMass==0?-bodyB:bodyB;\n"
"					c->m_worldPos[0] = contactPosB;\n"
"					GET_NPOINTS(*c) = 1;\n"
"				}//if (dstIdx < numPairs)\n"
"			}//if ( len <= (radiusA+radiusB))\n"
"\n"
"			return;\n"
"		}//SHAPE_SPHERE SHAPE_SPHERE\n"
"\n"
"	}//	if (i<numPairs)\n"
"\n"
"}\n"
"\n"
;