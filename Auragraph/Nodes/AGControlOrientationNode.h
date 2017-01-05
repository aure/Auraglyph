//
//  AGControlOrientationNode.h
//  Auragraph
//
//  Created by Spencer Salazar on 11/12/16.
//  Copyright © 2016 Spencer Salazar. All rights reserved.
//

#ifndef AGControlOrientationNode_hpp
#define AGControlOrientationNode_hpp

#include "AGControlNode.h"
#include "AGTimer.h"

#ifdef __OBJC__
@class CMMotionManager;
#else
typedef void CMMotionManager;
#endif


//------------------------------------------------------------------------------
// ### AGControlOrientationNode ###
//------------------------------------------------------------------------------
#pragma mark - AGControlOrientationNode

class AGControlOrientationNode : public AGControlNode
{
public:
    
    enum Param
    {
        PARAM_READ,
        PARAM_RATE,
    };
    
    class Manifest : public AGStandardNodeManifest<AGControlOrientationNode>
    {
    public:
        string _type() const override { return "Orientation"; };
        string _name() const override { return "Orientation"; };
        
        vector<AGPortInfo> _inputPortInfo() const override
        {
            return {
                { PARAM_READ, "read", true, true }
            };
        };
        
        vector<AGPortInfo> _editPortInfo() const override
        {
            return {
                { PARAM_RATE, "rate", true, true, 60, 0, 100, AGPortInfo::LIN },
            };
        };
        
        vector<GLvertex3f> _iconGeo() const override;
        
        GLuint _iconGeoType() const override { return GL_LINES; };
    };
    
    using AGControlNode::AGControlNode;
    
    void initFinal() override;
    
    ~AGControlOrientationNode();
    
    void editPortValueChanged(int paramId) override;
    
    void receiveControl(int port, const AGControl &control) override;
    
    virtual int numOutputPorts() const override { return 3; }
    
private:
    CMMotionManager *m_manager;
    AGTimer m_timer;
    
    void _pushData();
};



#endif /* AGControlOrientationNode_hpp */
